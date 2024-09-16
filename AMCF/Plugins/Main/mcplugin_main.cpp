/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Autodesk Inc. nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "libmcplugin_impl.hpp"

#include <sstream>
#include <iomanip>

#define MIN_LAYERHEIGHTINMM 0.001


#define MIN_PLATFORMAREAINMMSQUARED 1.0
#define MAX_PLATFORMAREAINMMSQUARED 1.0e12

#define MIN_POWDERRESERVOIRVOLUMEINMMCUBE 1.0
#define MAX_POWDERRESERVOIRVOLUMEINMMCUBE 1.0e12

#define MIN_POWDERRESERVOIROVERDOSEFACTOR 1.0
#define MAX_POWDERRESERVOIROVERDOSEFACTOR 100.0

#define MIN_AXIS_ID 1
#define MAX_AXIS_ID 4
#define ABSOLUTE_FLAG 1
#define RELATIVE_FLAG 2
#define MIN_TARGET -1000000
#define MAX_TARGET 1000000
#define MIN_SPEED -1000000
#define MAX_SPEED 1000000
#define MIN_ACCELERATION -1000000
#define MAX_ACCELERATION 1000000

#define CONTROLLER_INIT 1
#define CONTROLLER_UPDATE 0
#define CONTROLLER_ID_HEATER 1
#define CONTROLLER_ID_SHIELDINGGAS 2

#define AXISID_BUILDPLATFORM 1
#define AXISID_POWDERRESERVOIR 2
#define AXISID_RECOATERPOWDERBELT 3
#define AXISID_RECOATELINEAR 4

/*************************************************************************************************************************
  Driver import definition
**************************************************************************************************************************/
__NODRIVERIMPORT


/*************************************************************************************************************************
  State definitions
**************************************************************************************************************************/
__BEGINSTATEDEFINITIONS

__DECLARESTATE(init)
{
	pStateEnvironment->LogMessage("Initializing...");

	pStateEnvironment->SetIntegerParameter("jobinfo", "layercount", 0);
	pStateEnvironment->SetIntegerParameter("jobinfo", "currentlayer", 0);
	pStateEnvironment->SetDoubleParameter("jobinfo", "totalheight", 0.0);
	pStateEnvironment->SetDoubleParameter("jobinfo", "currentheight", 0.0);
	pStateEnvironment->SetBoolParameter("jobinfo", "printinprogress", false);

	pStateEnvironment->SetStringParameter("ui", "currentlayerdisplay", "---");
	pStateEnvironment->SetStringParameter("ui", "currentheightdisplay", "---");

	// initialize state machines of the PLC
	
	// Get Timeouts
	uint32_t nHeaterInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "heaterinittimeout");
	uint32_t nOxygenInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "oxygeninittimeout");
	uint32_t nVacuumInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "vacuuminittimeout");
	uint32_t nAtmosphereInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "atmosphereinittimeout");
	uint32_t nAxesInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "axesinittimeout");
	uint32_t nInitialPlatformMovementTimeOut = pStateEnvironment->GetIntegerParameter("timeouts", "initialplatformmovementtimeout");
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");
	

	// initialize heater controller
	pStateEnvironment->LogMessage("Initializing build plate heater controller..");
	//retrieve PID parameters, tuner parameters, PWM parameters and the temperature setpoint from the parameter group
	//retrieve PID parameters from the parameter group
	auto dDerivativetimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "derivativetime");
	auto dIntegrationtimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "integrationtime");
	auto dGainHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "gain");
	auto dFiltertimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "filtertime");
	auto nMaxoutHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxout");
	auto nMinoutHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "minout");
	//retrieve PWM parameters from the parameter group
	auto nDutycycleHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "dutycycle");
	auto dPeriodTimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "periodTime");
	auto nMaxFrequencyHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxFrequency");
	auto bModeHeater = pStateEnvironment->GetBoolParameter("heatercontroller", "mode");
	//retrieve tuning parameters from the parameter group
	auto nStepheightHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "stepheight");
	auto nMaxactvalueHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxactvalue");
	auto nMinactvalueHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "minactvalue");
	auto dSystemsettlingtimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "systemsettlingtime");
	auto dMaxtuningtimeHeater = pStateEnvironment->GetDoubleParameter("heatercontroller", "maxtuningtime");
	//retrieve the temperature setpoint from the parameter group
	auto nSetpointHeater = pStateEnvironment->GetIntegerParameter("heatercontroller", "setpoint");

	// send signal to plc state machine to update the heater control tuner parameters
	auto pSignalInitTunerHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollertuner");
	pSignalInitTunerHeater->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitTunerHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignalInitTunerHeater->SetInteger("stepheight", nStepheightHeater);
	pSignalInitTunerHeater->SetInteger("maxactvalue", nMaxactvalueHeater);
	pSignalInitTunerHeater->SetInteger("minactvalue", nMinactvalueHeater);
	pSignalInitTunerHeater->SetDouble("systemsettlingtime", dSystemsettlingtimeHeater);
	pSignalInitTunerHeater->SetDouble("maxtuningtime", dMaxtuningtimeHeater);
	pSignalInitTunerHeater->Trigger();

	// send signal to plc state machine to update the heater control PWM parameters
	auto pSignalInitPWMHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
	pSignalInitPWMHeater->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitPWMHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignalInitPWMHeater->SetInteger("dutycycle", nDutycycleHeater);
	pSignalInitPWMHeater->SetDouble("periodTime", dPeriodTimeHeater);
	pSignalInitPWMHeater->SetInteger("maxFrequency", nMaxFrequencyHeater);
	pSignalInitPWMHeater->SetBool("mode", bModeHeater);
	pSignalInitPWMHeater->Trigger();

	// send signal to plc state machine to update the heater control PID parameters
	auto pSignalInitPIDHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
	pSignalInitPIDHeater->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitPIDHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignalInitPIDHeater->SetDouble("derivativetime", dDerivativetimeHeater);
	pSignalInitPIDHeater->SetDouble("integrationtime", dIntegrationtimeHeater);
	pSignalInitPIDHeater->SetDouble("gain", dGainHeater);
	pSignalInitPIDHeater->SetDouble("filtertime", dFiltertimeHeater);
	pSignalInitPIDHeater->SetInteger("maxout", nMaxoutHeater);
	pSignalInitPIDHeater->SetInteger("minout", nMinoutHeater);
	pSignalInitPIDHeater->Trigger();

	// send signal to plc state machine to update the heater control temperature setpoint
	auto pSignalInitSetpointHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
	pSignalInitSetpointHeater->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitSetpointHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignalInitSetpointHeater->SetInteger("setpoint", nSetpointHeater);
	pSignalInitSetpointHeater->Trigger();

	if (pSignalInitTunerHeater->WaitForHandling(nHeaterInitTimeout) && pSignalInitPWMHeater->WaitForHandling(nHeaterInitTimeout) && pSignalInitPIDHeater->WaitForHandling(nHeaterInitTimeout) && pSignalInitSetpointHeater->WaitForHandling(nHeaterInitTimeout)) {
		bool bTunerReadyHeater = pSignalInitTunerHeater->GetBoolResult("success");
		bool bPWMReadyHeater = pSignalInitPWMHeater->GetBoolResult("success");
		bool bPIDReadyHeater = pSignalInitPIDHeater->GetBoolResult("success");
		bool bSetpointReadyHeater = pSignalInitSetpointHeater->GetBoolResult("success");

		bool bHeaterControllerIsReady = bTunerReadyHeater && bPWMReadyHeater && bPIDReadyHeater && bSetpointReadyHeater;

		pStateEnvironment->SetBoolParameter("processinitialization", "heatercontroller_ready", bHeaterControllerIsReady);
		
		std::vector<std::string> readyControllersHeater;
		std::vector<std::string> notReadyControllersHeater;
		if (bTunerReadyHeater)
			readyControllersHeater.push_back("HeaterControllerTuner");
		else
			notReadyControllersHeater.push_back("HeaterControllerTuner");
		if (bPWMReadyHeater)
			readyControllersHeater.push_back("HeaterControllerPWM");
		else
			notReadyControllersHeater.push_back("HeaterControllerPWM");
		if (bPIDReadyHeater)
			readyControllersHeater.push_back("HeaterControllerPID");
		else
			notReadyControllersHeater.push_back("HeaterControllerPID");
		if (bSetpointReadyHeater)
			readyControllersHeater.push_back("HeaterControllerSetpoint");
		else
			notReadyControllersHeater.push_back("HeaterControllerSetpoint");

		if (readyControllersHeater.size() > 0) {
			std::string sReadyControllersHeaterString;
			for (auto controllerString : readyControllersHeater) {
				if (!sReadyControllersHeaterString.empty())
					sReadyControllersHeaterString += ", ";
				sReadyControllersHeaterString += controllerString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sReadyControllersHeaterString + " successfull");
		}
		if(notReadyControllersHeater.size() > 0) {
			std::string sNotReadyControllersHeaterString;
			for (auto controllerString : notReadyControllersHeater) {
				if (!sNotReadyControllersHeaterString.empty())
					sNotReadyControllersHeaterString += ", ";
				sNotReadyControllersHeaterString += controllerString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sNotReadyControllersHeaterString + " failed");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->LogMessage("No response from PLC");
		pStateEnvironment->SetBoolParameter("processinitialization", "heatercontroller_ready", false);
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEHEATERCONTROLLER");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	// inizialize oxygen controller
	pStateEnvironment->LogMessage("Initializing oxygen controller..");
	//retrieve PID parameters, tuner parameters, PWM parameters and the oxygen setpoint from the parameter group
	//retrieve PID parameters from the parameter group
	auto dDerivativetimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "derivativetime");
	auto dIntegrationtimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "integrationtime");
	auto dGainOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "gain");
	auto dFiltertimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "filtertime");
	auto nMaxoutOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxout");
	auto nMinoutOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minout");
	//retrieve PWM parameters from the parameter group
	auto nDutycycleOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "dutycycle");
	auto dPeriodTimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "periodTime");
	auto nMaxFrequencyOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxFrequency");
	auto bModeOxygen = pStateEnvironment->GetBoolParameter("oxygencontroller", "mode");
	//retrieve tuning parameters from the parameter group
	auto nStepheightOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "stepheight");
	auto nMaxactvalueOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxactvalue");
	auto nMinactvalueOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minactvalue");
	auto dSystemsettlingtimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "systemsettlingtime");
	auto dMaxtuningtimeOxygen = pStateEnvironment->GetDoubleParameter("oxygencontroller", "maxtuningtime");
	//retrieve the oxygen setpoint from the parameter group
	auto nSetpointOxygen = pStateEnvironment->GetIntegerParameter("oxygencontroller", "setpoint");

	// send signal to plc state machine to update the oxygen control tuner parameters
	auto pSignalInitTunerOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollertuner");
	pSignalInitTunerOxygen->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitTunerOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pSignalInitTunerOxygen->SetInteger("stepheight", nStepheightOxygen);
	pSignalInitTunerOxygen->SetInteger("maxactvalue", nMaxactvalueOxygen);
	pSignalInitTunerOxygen->SetInteger("minactvalue", nMinactvalueOxygen);
	pSignalInitTunerOxygen->SetDouble("systemsettlingtime", dSystemsettlingtimeOxygen);
	pSignalInitTunerOxygen->SetDouble("maxtuningtime", dMaxtuningtimeOxygen);
	pSignalInitTunerOxygen->Trigger();

	// send signal to plc state machine to update the oxygen control PWM parameters
	auto pSignalInitPWMOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
	pSignalInitPWMOxygen->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitPWMOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pSignalInitPWMOxygen->SetInteger("dutycycle", nDutycycleOxygen);
	pSignalInitPWMOxygen->SetDouble("periodTime", dPeriodTimeOxygen);
	pSignalInitPWMOxygen->SetInteger("maxFrequency", nMaxFrequencyOxygen);
	pSignalInitPWMOxygen->SetBool("mode", bModeOxygen);
	pSignalInitPWMOxygen->Trigger();

	// send signal to plc state machine to update the oxygen control PID parameters
	auto pSignalInitPIDOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
	pSignalInitPIDOxygen->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitPIDOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pSignalInitPIDOxygen->SetDouble("derivativetime", dDerivativetimeOxygen);
	pSignalInitPIDOxygen->SetDouble("integrationtime", dIntegrationtimeOxygen);
	pSignalInitPIDOxygen->SetDouble("gain", dGainOxygen);
	pSignalInitPIDOxygen->SetDouble("filtertime", dFiltertimeOxygen);
	pSignalInitPIDOxygen->SetInteger("maxout", nMaxoutOxygen);
	pSignalInitPIDOxygen->SetInteger("minout", nMinoutOxygen);
	pSignalInitPIDOxygen->Trigger();

	// send signal to plc state machine to update the shielding gas control oxygen content setpoint
	auto pSignalInitSetpointOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
	pSignalInitSetpointOxygen->SetBool("isinit", CONTROLLER_INIT);
	pSignalInitSetpointOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pSignalInitSetpointOxygen->SetInteger("setpoint", nSetpointOxygen);
	pSignalInitSetpointOxygen->Trigger();

	if (pSignalInitTunerOxygen->WaitForHandling(nOxygenInitTimeout) && pSignalInitPWMOxygen->WaitForHandling(nOxygenInitTimeout) && pSignalInitPIDOxygen->WaitForHandling(nOxygenInitTimeout) && pSignalInitSetpointOxygen->WaitForHandling(nOxygenInitTimeout)) {
		bool bTunerReadyOxygen = pSignalInitTunerOxygen->GetBoolResult("success");
		bool bPWMReadyOxygen = pSignalInitPWMOxygen->GetBoolResult("success");
		bool bPIDReadyOxygen = pSignalInitPIDOxygen->GetBoolResult("success");
		bool bSetpointReadyOxygen = pSignalInitSetpointOxygen->GetBoolResult("success");

		bool bOxygenControllerIsReady = bTunerReadyOxygen && bPWMReadyOxygen && bPIDReadyOxygen && bSetpointReadyOxygen;

		pStateEnvironment->SetBoolParameter("processinitialization", "oxygencontroller_ready", bOxygenControllerIsReady);

		std::vector<std::string> readyControllersOxygen;
		std::vector<std::string> notReadyControllersOxygen;
		if (bTunerReadyOxygen)
			readyControllersOxygen.push_back("OxygenControllerTuner");
		else
			notReadyControllersOxygen.push_back("OxygenControllerTuner");
		if (bPWMReadyOxygen)
			readyControllersOxygen.push_back("OxygenControllerPWM");
		else
			notReadyControllersOxygen.push_back("OxygenControllerPWM");
		if (bPIDReadyOxygen)
			readyControllersOxygen.push_back("OxygenControllerPID");
		else
			notReadyControllersOxygen.push_back("OxygenControllerPID");
		if (bSetpointReadyOxygen)
			readyControllersOxygen.push_back("OxygenControllerSetpoint");
		else
			notReadyControllersOxygen.push_back("OxygenControllerSetpoint");

		if (readyControllersOxygen.size() > 0) {
			std::string sReadyControllersOxygenString;
			for (auto controllerString : readyControllersOxygen) {
				if (!sReadyControllersOxygenString.empty())
					sReadyControllersOxygenString += ", ";
				sReadyControllersOxygenString += controllerString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sReadyControllersOxygenString + " successfull");
		}
		if (notReadyControllersOxygen.size() > 0) {
			std::string sNotReadyControllersOxygenString;
			for (auto controllerString : notReadyControllersOxygen) {
				if (!sNotReadyControllersOxygenString.empty())
					sNotReadyControllersOxygenString += ", ";
				sNotReadyControllersOxygenString += controllerString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sNotReadyControllersOxygenString + " failed");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->LogMessage("No response from PLC");
		pStateEnvironment->SetBoolParameter("processinitialization", "oxygencontroller_ready", false);
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEOXYGENCONTROLLER");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	// initialize vacuum controller
	pStateEnvironment->LogMessage("Initializing vacuum controller..");
	// retrieve pressure threshold from the parameter group
	auto npressure_threshold_vacuum_off_in_mbar = pStateEnvironment->GetIntegerParameter("jobinfo", "pressure_threshold_vacuum_off_in_mbar");

	auto pSignalInitVacuumControl = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_init");
	pSignalInitVacuumControl->SetInteger("pressure_threshold_vacuum_off_in_mbar", npressure_threshold_vacuum_off_in_mbar);
	pSignalInitVacuumControl->Trigger();

	if (pSignalInitVacuumControl->WaitForHandling(nVacuumInitTimeout)) {
		bool bVacuumControllerIsReady = pSignalInitVacuumControl->GetBoolResult("success");

		pStateEnvironment->SetBoolParameter("processinitialization", "vacuumcontroller_ready", bVacuumControllerIsReady);
		if (bVacuumControllerIsReady)
			pStateEnvironment->LogMessage("Vacuum controller initialized");
		else
			pStateEnvironment->LogMessage("Could not initialize vacuum controller");
	}
	else {
		// No response from PLC!
		pStateEnvironment->LogMessage("No response from PLC");
		pStateEnvironment->SetBoolParameter("processinitialization", "vacuumcontroller_ready", false);
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEVACUUMCONTROLLER");
		pStateEnvironment->SetNextState("initerror");
		return;
	}
		
	// initialize atmosphere controller
	// retrieve pressure threshold from the parameter group
	auto no2_threshold_circulation_on_in_ppm = pStateEnvironment->GetIntegerParameter("hardwareinformation", "o2_threshold_circulation_on_in_ppm");
	auto no2_threshold_circulation_off_in_ppm = pStateEnvironment->GetIntegerParameter("hardwareinformation", "o2_threshold_circulation_off_in_ppm");

	auto pSignalInitAtmosphereControl = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_init");
	pSignalInitAtmosphereControl->SetInteger("o2_threshold_circulation_on_in_ppm", no2_threshold_circulation_on_in_ppm);
	pSignalInitAtmosphereControl->SetInteger("o2_threshold_circulation_off_in_ppm", no2_threshold_circulation_off_in_ppm);
	pSignalInitAtmosphereControl->Trigger();

	if (pSignalInitAtmosphereControl->WaitForHandling(nAtmosphereInitTimeout)) {
		bool bAtmosphereControllerIsReady = pSignalInitAtmosphereControl->GetBoolResult("success");

		pStateEnvironment->SetBoolParameter("processinitialization", "atmospherecontroller_ready", bAtmosphereControllerIsReady);
		if (bAtmosphereControllerIsReady)
			pStateEnvironment->LogMessage("Atmosphere controller initialized");
		else
			pStateEnvironment->LogMessage("Could not initialize atmosphere controller");
	}
	else {
		// No response from PLC!
		pStateEnvironment->LogMessage("No response from PLC");
		pStateEnvironment->SetBoolParameter("processinitialization", "atmospherecontroller_ready", false);
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEATMOSPHERECONTROLLER");
		pStateEnvironment->SetNextState("initerror");
		return;
	}
	// initialize stepper motors
	auto pSignalInitAxes= pStateEnvironment->PrepareSignal("plc", "signal_initaxes");
	pSignalInitAxes->Trigger();

	if (pSignalInitAxes->WaitForHandling(nAxesInitTimeout)) 
	{
		pStateEnvironment->LogMessage("Initializing of all axes successfull");

		//Get the target position, the velocity and the acceleration of the build platform
		double dTargetPlatformInMM = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_initial_absolute_position");
		double dSpeedPlatformInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_speed");
		double dAccelerationPlatformInMMPerSecondSquared = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_acceleration");
		//Prepare the signal to move the build platform into the working plane
		auto pMovementPlatformSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
		pMovementPlatformSignal->SetInteger("axis_ID", AXISID_BUILDPLATFORM); //axis_ID build platform
		pMovementPlatformSignal->SetInteger("absoluterelative", ABSOLUTE_FLAG); //absolute movement
		pMovementPlatformSignal->SetDouble("target", dTargetPlatformInMM);
		pMovementPlatformSignal->SetDouble("speed", dSpeedPlatformInMMPerSecond);
		pMovementPlatformSignal->SetDouble("acceleration", dAccelerationPlatformInMMPerSecondSquared);
		//Send the build platform movement signal to the plc state machine
		pMovementPlatformSignal->Trigger();
		pStateEnvironment->LogMessage("Wait for initial platform movement ...");
		if (pMovementPlatformSignal->WaitForHandling(nInitialPlatformMovementTimeOut))
		{
			if (pMovementPlatformSignal->GetBoolResult("success"))
			{
				pStateEnvironment->LogMessage("Initial platform movement finished");
			}
			else
			{
				pStateEnvironment->LogMessage("Initial platform movement was not successful");
				pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYMOVEBUILDPLATFORM");
				pStateEnvironment->SetNextState("initerror");
				return;
			}
		}
		else
		{
			// no response from PLC!
			pStateEnvironment->LogMessage("Initial platform movement timeout");
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYMOVEBUILDPLATFORMDUETOTIMEOUT");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else {

		bool bIsInitPlatformAxis = pSignalInitAxes->GetBoolResult("platformaxis_initialized");
		bool bIsInitReservoirAxis = pSignalInitAxes->GetBoolResult("powderreservoiraxis_initialized");
		bool bIsInitRecoaterAxisPowder = pSignalInitAxes->GetBoolResult("recoateraxis_powder_initialized");
		bool bIsInitRecoaterAxisLinear = pSignalInitAxes->GetBoolResult("recoateraxis_linear_initialized");

		pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_linear_ready", bIsInitRecoaterAxisLinear);
		pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_powder_ready", bIsInitRecoaterAxisPowder);
		pStateEnvironment->SetBoolParameter("processinitialization", "powderreservoiraxis_ready", bIsInitReservoirAxis);
		pStateEnvironment->SetBoolParameter("processinitialization", "platformaxis_ready", bIsInitPlatformAxis);


		std::vector<std::string> readyAxes;
		std::vector<std::string> notReadyAxes;
		if (bIsInitPlatformAxis)
			readyAxes.push_back("Platform");
		else
			notReadyAxes.push_back("Platform");
		if (bIsInitReservoirAxis)
			readyAxes.push_back("PowderReservoir");
		else
			notReadyAxes.push_back("PowderReservoir");
		if (bIsInitRecoaterAxisPowder)
			readyAxes.push_back("PowderRecoaterAxis");
		else
			notReadyAxes.push_back("PowderRecoaterAxis");
		if (bIsInitRecoaterAxisLinear)
			readyAxes.push_back("LinearRecoaterAxis");
		else
			notReadyAxes.push_back("LinearRecoaterAxis");

		if (readyAxes.size() > 0) {
			std::string sReadyAxesString;
			for (auto axisString : readyAxes) {
				if (!sReadyAxesString.empty())
					sReadyAxesString += ", ";
				sReadyAxesString += axisString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sReadyAxesString + " successfull");
		}
		if (notReadyAxes.size() > 0) {
			std::string sNotReadyAxesString;
			for (auto axisString : notReadyAxes) {
				if (!sNotReadyAxesString.empty())
					sNotReadyAxesString += ", ";
				sNotReadyAxesString += axisString;
			}
			pStateEnvironment->LogMessage("Initializing of " + sNotReadyAxesString + " failed");
		}

		// Send signal to the plc state machine to leave the waitforreferencing state
		auto pLeaveWaitforreferencingSignal = pStateEnvironment->PrepareSignal("plc", "signal_leavewaitforreferencing");
		pLeaveWaitforreferencingSignal->Trigger();
		if (pLeaveWaitforreferencingSignal->WaitForHandling(nGeneralCommandTimeout))
		{
			pStateEnvironment->LogMessage("The state waitforreferencing in the plc state machine was left for the state idle");
		}
		else
		{
			// no response from PLC!
			pStateEnvironment->LogMessage("Leave waitforreferencing in the plc state machine timeout");
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTLEAVEWAITFORREFERENCINGDUETOTIMEOUT");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}

	pStateEnvironment->SetNextState("idle");
}


__DECLARESTATE(idle) 
{

	PSignalHandler pSignalHandler;
	if (pStateEnvironment->WaitForSignal("signal_startbuild", 0, pSignalHandler)) {

		std::string sJobUUID = pSignalHandler->GetString("jobuuid");
		pStateEnvironment->LogMessage("Starting job " + sJobUUID);
		pSignalHandler->SignalHandled();

		pStateEnvironment->SetUUIDParameter("jobinfo", "jobuuid", sJobUUID);

		pStateEnvironment->SetBoolParameter("ui", "build_canbecanceled", true);

		pStateEnvironment->SetNextState("startprocess");

	}
	else if (pStateEnvironment->WaitForSignal("signal_manualmovementcontrol_enter", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("manualmovementcontrol");

	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_enter", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}

	else if (pStateEnvironment->WaitForSignal("signal_manualheatercontrol_enter", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("manualheatercontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_changelayer", 0, pSignalHandler)) {
		auto nLayer = pSignalHandler->GetInteger("layer");
		pStateEnvironment->SetIntegerParameter("jobinfo", "startlayer", nLayer);
		pStateEnvironment->LogMessage("Changed build job start layer " + std::to_string(nLayer));
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");

	}
	else {

		pStateEnvironment->SetNextState("idle");

	}

}

__DECLARESTATE(startprocess)
{
	// check if CancelBuild button was clicked
	PSignalHandler pSignalHandler;
	if (pStateEnvironment->WaitForSignal("signal_cancelbuild", 0, pSignalHandler)) {
		pStateEnvironment->SetBoolParameter("ui", "build_canbecanceled", false);
		pStateEnvironment->SetNextState("cancelprocess");
		pSignalHandler->SignalHandled();
		return;
	}

	// Reset error state
	pStateEnvironment->SetStringParameter("processinitialization", "initerror", "NOERROR");

	// Reset all process variables to default values
	pStateEnvironment->SetBoolParameter("processinitialization", "emergencycircuitclosed", false);
	pStateEnvironment->SetBoolParameter("processinitialization", "sufficientpowderisavailable", false);
	pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_linear_ready", false);
	pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_powder_ready", false);
	pStateEnvironment->SetBoolParameter("processinitialization", "powderreservoiraxis_ready", false);
	pStateEnvironment->SetBoolParameter("processinitialization", "platformaxis_ready", false);

	// Reset current job information
	pStateEnvironment->SetIntegerParameter("jobinfo", "layercount", 0);
	pStateEnvironment->SetIntegerParameter("jobinfo", "currentlayer", 0);

	// Get UUID Information
	std::string sJobUUID = pStateEnvironment->GetUUIDParameter("jobinfo", "jobuuid");
	pStateEnvironment->LogMessage("Loading job " + sJobUUID);

	auto pBuildJob = pStateEnvironment->GetBuildJob(sJobUUID);	

	auto layerCount = pBuildJob->GetLayerCount();
	pStateEnvironment->LogMessage("Job has " + std::to_string(layerCount) + " layers...");


	// TODO: Check if all metadata parameters are present!

	// Get Timeouts
	uint32_t nEmergencyCircuitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "emergencycircuittimeout");
	uint32_t nPowderAvailabilityTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "powderavailabilitytimeout");
	uint32_t nMotorEnabledCheckTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "motorenabledchecktimeout");
	uint32_t nLockDoorTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "lockdoortimeout");
	uint32_t nControllerSetpointUpdateTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "controllersetpointupdatetimeout");

	// Check if Emergency Circuit is closed
	pStateEnvironment->LogMessage("Checking if emergency circuit is closed..");
	auto pEmergencyCircuitSignal = pStateEnvironment->PrepareSignal("plc", "signal_checkemergencycircuit");
	pEmergencyCircuitSignal->Trigger();

	if (pEmergencyCircuitSignal->WaitForHandling (nEmergencyCircuitTimeout)) {
		bool bEmergencyCircuitIsClosed = pEmergencyCircuitSignal->GetBoolResult("circuitisclosed");		
		pStateEnvironment->SetBoolParameter("processinitialization", "emergencycircuitclosed", bEmergencyCircuitIsClosed);
		if (!bEmergencyCircuitIsClosed) {
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "ERGENCYCIRCUITNOTCLOSED");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTREADEMERGENCYCIRCUITSTATE");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	// Send signal to PLC to lock the process chamber door
	pStateEnvironment->LogMessage("Locking process chamber door..");
	auto pLockDoorSignal = pStateEnvironment->PrepareSignal("plc", "signal_lockdoor");
	pLockDoorSignal->SetBool("lockdoor", true);
	pLockDoorSignal->Trigger();

	if (pLockDoorSignal->WaitForHandling(nLockDoorTimeout)) {
		bool bDoorIsLocked = pLockDoorSignal->GetBoolResult("doorlockstate");
		pStateEnvironment->SetBoolParameter("processinitialization", "chamberdoorislocked", bDoorIsLocked);
		if (!bDoorIsLocked) {
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "DOORNOTLOCKED");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTLOCKDOOR");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	
	// Check if enough powder is available
	pStateEnvironment->LogMessage("Checking if enough powder is available..");
	auto pPowderAvailabilitySignal = pStateEnvironment->PrepareSignal("plc", "signal_checkpowderavailability");
	pPowderAvailabilitySignal->Trigger();

	if (pPowderAvailabilitySignal->WaitForHandling(nPowderAvailabilityTimeout)) {
		double dPowderAvailability = pPowderAvailabilitySignal->GetDoubleResult("filllevel");
		if ((dPowderAvailability < 0.0) || (dPowderAvailability > 1.0)) {
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "POWDERAVAILABILITYSENSORFAILED");
			pStateEnvironment->SetNextState("initerror");
			return;
		}

		// Calculate needed powder reservoir
		double dPlatformAreaInMMSquared = pStateEnvironment->GetDoubleParameter ("hardwareinformation", "platformarea");
		double dMaxPowderReservoirAreaInMMSquared = pStateEnvironment->GetDoubleParameter("hardwareinformation", "powderreservoirarea");
		double dMaxPowderReservoirHeightInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "powderreservoirheight");
		double dMaxPowderReservoirVolumeInMMCubed = dMaxPowderReservoirAreaInMMSquared * dMaxPowderReservoirHeightInMM;
		pStateEnvironment->SetDoubleParameter("jobinfo", "currentreservoirpowdercapacity", dMaxPowderReservoirVolumeInMMCubed);

		// Overdosing factor is a job parameter. MUST be larger than 1.0
		double dOverdosingFactor = pStateEnvironment->GetDoubleParameter ("jobinfo", "overdosefactor");

		if ((dPlatformAreaInMMSquared < MIN_PLATFORMAREAINMMSQUARED) || (dPlatformAreaInMMSquared > MAX_PLATFORMAREAINMMSQUARED))
			throw std::runtime_error("invalid platform area!");

		if ((dMaxPowderReservoirVolumeInMMCubed < MIN_POWDERRESERVOIRVOLUMEINMMCUBE) || (dMaxPowderReservoirVolumeInMMCubed > MAX_POWDERRESERVOIRVOLUMEINMMCUBE))
			throw std::runtime_error("invalid reservoir volume!");

		if ((dOverdosingFactor < MIN_POWDERRESERVOIROVERDOSEFACTOR) || (dOverdosingFactor > MAX_POWDERRESERVOIROVERDOSEFACTOR))
			throw std::runtime_error("invalid overdose factor!");

		pStateEnvironment->SetIntegerParameter("jobinfo", "layercount", layerCount);
		pStateEnvironment->SetIntegerParameter("jobinfo", "currentlayer", 0);

		double dBuildHeightInMM = pBuildJob->GetBuildHeightInMM();
		double dNeededPowderVolumeInMMCubed = dBuildHeightInMM * dPlatformAreaInMMSquared;
		double dPowderMinimumPowderAvailability = dNeededPowderVolumeInMMCubed * dOverdosingFactor / dMaxPowderReservoirVolumeInMMCubed;

		bool bSufficientPowderIsAvailable = (dPowderAvailability > dPowderMinimumPowderAvailability);
		pStateEnvironment->SetBoolParameter("processinitialization", "sufficientpowderisavailable", bSufficientPowderIsAvailable);


	}
	else {
		// No response from PLC!
		pStateEnvironment->SetBoolParameter("processinitialization", "sufficientpowderisavailable", false);
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTREADPOWDERAVAILABILITYSTATE");
		pStateEnvironment->SetNextState("initerror");
		return;
	}
	

	// Check if axes are enabled and homed
	pStateEnvironment->LogMessage("Check if axes are enabled and homed...");
	auto pAxisStateCheckSignal = pStateEnvironment->PrepareSignal("plc", "signal_checkaxisstate");
	pAxisStateCheckSignal->Trigger();

	if (pAxisStateCheckSignal->WaitForHandling(nMotorEnabledCheckTimeout)) {
		bool bRecoaterAxisLinearReady = pAxisStateCheckSignal->GetBoolResult ("recoateraxis_linear_ready");
		bool bRecoaterAxisPowderReady = pAxisStateCheckSignal->GetBoolResult ("recoateraxis_powder_ready");
		bool bPowderReservoirAxisReady = pAxisStateCheckSignal->GetBoolResult ("powderreservoiraxis_ready");
		bool bPlatformAxisReady = pAxisStateCheckSignal->GetBoolResult ("platformaxis_ready");

		pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_linear_ready", bRecoaterAxisLinearReady);
		pStateEnvironment->SetBoolParameter("processinitialization", "recoateraxis_powder_ready", bRecoaterAxisPowderReady);
		pStateEnvironment->SetBoolParameter("processinitialization", "powderreservoiraxis_ready", bPowderReservoirAxisReady);
		pStateEnvironment->SetBoolParameter("processinitialization", "platformaxis_ready", bPlatformAxisReady);

		if (!bRecoaterAxisLinearReady || !bRecoaterAxisPowderReady || !bPowderReservoirAxisReady || !bPlatformAxisReady) {
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "AXISNOTREADY");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTCHECKAXESSTATUS");
		pStateEnvironment->SetNextState("initerror");
		return;
	}


	// Update the controller setpoints of the oxygen and the heater control

	pStateEnvironment->LogMessage("Update the heater control temperature setpoint ...");
	// Get the heater control temperature setpoint from the jobinfo parameter group
	int nSetpointHeater = pStateEnvironment->GetIntegerParameter("jobinfo" ,"heatercontroller_temperature_setpoint_in_degree_celsius");
	// Set the heater control temperature setpoint in the heatercontoller parameter group 
	pStateEnvironment->SetIntegerParameter("heatercontroller", "setpoint", nSetpointHeater);
	// send signal to plc state machine to update the heater control temperature setpoint
	auto pSignalUpdateSetpointHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
	pSignalUpdateSetpointHeater->SetBool("isinit", CONTROLLER_UPDATE);
	pSignalUpdateSetpointHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignalUpdateSetpointHeater->SetInteger("setpoint", nSetpointHeater);
	pSignalUpdateSetpointHeater->Trigger();
	if (pSignalUpdateSetpointHeater->WaitForHandling(nControllerSetpointUpdateTimeout))
	{
		if (pSignalUpdateSetpointHeater->GetBoolResult("success"))
		{
			pStateEnvironment->LogMessage("Update of the heater control temperature setpoint successful");
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTUPDATEHEATERCONTROLSETPOINT");
			pStateEnvironment->LogMessage("Update of the heater control temperature setpoint was not successful");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else
	{
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTUPDATEHEATERCONTROLSETPOINTDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Update of the heater control temperature setpoint timeout");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	pStateEnvironment->LogMessage("Update the shielding gas control oxygen content setpoint ...");
	// Get the shielding gas control oxygen content setpoint from the jobinfo
	int nSetpointOxygen = pStateEnvironment->GetIntegerParameter("jobinfo", "oxygencontroller_oxygen_setpoint_in_ppm");
	// Set the shielding gas control oxygen content setpoint in the oxygencontoller parameter group 
	pStateEnvironment->SetIntegerParameter("oxygencontroller", "setpoint", nSetpointOxygen);
	// send signal to plc state machine to update the shielding gas control oxygen content setpoint
	auto pSignalUpdateSetpointOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
	pSignalUpdateSetpointOxygen->SetBool("isinit", CONTROLLER_UPDATE);
	pSignalUpdateSetpointOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pSignalUpdateSetpointOxygen->SetInteger("setpoint", nSetpointOxygen);
	pSignalUpdateSetpointOxygen->Trigger();
	if (pSignalUpdateSetpointOxygen->WaitForHandling(nControllerSetpointUpdateTimeout))
	{
		if (pSignalUpdateSetpointOxygen->GetBoolResult("success"))
		{
			pStateEnvironment->LogMessage("Update of the shielding gas control oxygen content setpoint successful");
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTUPDATEOXYGENCONTROLSETPOINT");
			pStateEnvironment->LogMessage("Update of the shielding gas control oxygen content setpoint was not successful");
			pStateEnvironment->SetNextState("initerror");
			return;
		}
	}
	else
	{
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTUPDATEOXYGENCONTROLSETPOINTDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Update of the shielding gas control oxygen content setpoint timeout");
		pStateEnvironment->SetNextState("initerror");
		return;
	}


	pStateEnvironment->SetNextState("processpreparation");
}

__DECLARESTATE(processpreparation)
{
	// check if CancelBuild button was clicked
	PSignalHandler pSignalHandler;
	if (pStateEnvironment->WaitForSignal("signal_cancelbuild", 0, pSignalHandler)) {
		pStateEnvironment->SetBoolParameter("ui", "build_canbecanceled", false);
		pStateEnvironment->SetNextState("cancelprocess");
		pSignalHandler->SignalHandled();
		return;
	}

	// Get Timeouts
	uint32_t nPowderDosingTimeOut = pStateEnvironment->GetIntegerParameter("timeouts", "powderdosingtimeout");
	uint32_t nInitialRecoaterMovementTimeOut = pStateEnvironment->GetIntegerParameter("timeouts", "initialrecoatermovementtimeout");

	pStateEnvironment->SetStringParameter("ui", "currentlayerdisplay", "initializing");
	pStateEnvironment->SetStringParameter("ui", "currentheightdisplay", "initializing");

	// initialize job information variables
	auto sJobUUID = pStateEnvironment->GetUUIDParameter("jobinfo", "jobuuid");
	auto pBuildJob = pStateEnvironment->GetBuildJob(sJobUUID);

	auto sJobName = pBuildJob->GetName();
	double dTotalHeight = pBuildJob->GetBuildHeightInMM();
	auto nLayerCount = pBuildJob->GetLayerCount();
	auto nStartLayer = pStateEnvironment->GetIntegerParameter("jobinfo", "startlayer");

	if (nStartLayer > nLayerCount) {
		pStateEnvironment->LogMessage("Invalid start layer! Start layer " + std::to_string(nStartLayer) + " > Max layer index = " + std::to_string(nLayerCount));
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "INVALIDSTARTLAYER");
		pStateEnvironment->SetNextState("initerror");
		return;
	}

	pStateEnvironment->LogMessage("Job Name: " + sJobName);
	pStateEnvironment->LogMessage("Layer Count: " + std::to_string(nLayerCount));

	pStateEnvironment->SetStringParameter("jobinfo", "jobname", sJobName);
	pStateEnvironment->SetIntegerParameter("jobinfo", "currentlayer", nStartLayer);
	pStateEnvironment->SetIntegerParameter("jobinfo", "layercount", nLayerCount);
	pStateEnvironment->SetDoubleParameter("jobinfo", "currentheight", 0.0);
	pStateEnvironment->SetDoubleParameter("jobinfo", "totalheight", dTotalHeight);
	pStateEnvironment->SetDoubleParameter("jobinfo", "currentthickness", 0.0);

	//Get the target position, the velocity and the acceleration of the recoater linear axis
	double dTargetRecoaterInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_refill_position");
	double dSpeedRecoaterInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_linear_speed_travel");
	double dAccelerationRecoaterInMMPerSecondSquared = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_axes_linear_acceleration_travel");
	
	//Initial powder dosing 
	auto nInitialPowderDosingUnits = pStateEnvironment->GetIntegerParameter("jobinfo", "initpowderdosingunits");
	
	int nPowderreservoirNotchCount = pStateEnvironment->GetIntegerParameter("hardwareinformation", "powderreservoir_dosing_notch_count");
	double dSpeedInDegreesPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_speed");
	double dAccelerationInDegreesPerSecondSquared = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_acceleration");
	double dTargetInDegrees = nInitialPowderDosingUnits * 360.0/(double)nPowderreservoirNotchCount;
	
	//Prepare the signal to move the recoater into the refilling position
	auto pMovementRecoaterSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
	pMovementRecoaterSignal->SetInteger("axis_ID", AXISID_RECOATELINEAR); //axis_ID linear recoater axis
	pMovementRecoaterSignal->SetInteger("absoluterelative", ABSOLUTE_FLAG); //absolute movement
	pMovementRecoaterSignal->SetDouble("target", dTargetRecoaterInMM);
	pMovementRecoaterSignal->SetDouble("speed", dSpeedRecoaterInMMPerSecond);
	pMovementRecoaterSignal->SetDouble("acceleration", dAccelerationRecoaterInMMPerSecondSquared);
	//Send the recoater movement to the plc state machine
	pMovementRecoaterSignal->Trigger();
	pStateEnvironment->LogMessage("Wait for recoater movement to the refilling position ...");
	if (pMovementRecoaterSignal->WaitForHandling(nInitialRecoaterMovementTimeOut))
	{
		if (pMovementRecoaterSignal->GetBoolResult("success"))
		{
			//Prepare the powder dosing signal
			auto pMovementReservoirSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
			pMovementReservoirSignal->SetInteger("axis_ID", AXISID_POWDERRESERVOIR); //axis_ID powder reservoir
			pMovementReservoirSignal->SetInteger("absoluterelative", RELATIVE_FLAG); //relative movement
			pMovementReservoirSignal->SetDouble("target", dTargetInDegrees);
			pMovementReservoirSignal->SetDouble("speed", dSpeedInDegreesPerSecond);
			pMovementReservoirSignal->SetDouble("acceleration", dAccelerationInDegreesPerSecondSquared);
			//Send the powder dosing signal to the plc state machine
			pMovementReservoirSignal->Trigger();
			pStateEnvironment->LogMessage("Filling recoater with " + std::to_string(nInitialPowderDosingUnits) + " dosing units powder");
			pStateEnvironment->LogMessage("Wait for powder dosing ...");
			if (pMovementReservoirSignal->WaitForHandling(nInitialRecoaterMovementTimeOut))
			{
				if (pMovementReservoirSignal->GetBoolResult("success"))
				{
					double dPowderVolumePerNotchInCubicMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "powderreservoir_notch_volume_in_cubic_mm");
					double dOldReservoirPowderVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentreservoirpowdercapacity");
					double dRecoaterFillingVolumeInMMCubed = dPowderVolumePerNotchInCubicMM * nInitialPowderDosingUnits;
					pStateEnvironment->SetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity", dRecoaterFillingVolumeInMMCubed);
					pStateEnvironment->SetDoubleParameter("jobinfo", "currentreservoirpowdercapacity", (dOldReservoirPowderVolumeInMMCubed - dRecoaterFillingVolumeInMMCubed));

					pStateEnvironment->LogMessage("Powder dosing finished");
					pStateEnvironment->LogMessage("Current recoater powder capacity: " + std::to_string(dRecoaterFillingVolumeInMMCubed) + " cubic mm");
					pStateEnvironment->LogMessage("Current reservoir powder capacity: " + std::to_string((dOldReservoirPowderVolumeInMMCubed - dRecoaterFillingVolumeInMMCubed)) + " cubic mm");

					// Set next state if the linear recoater axis and the reservoir axis were moved successfully
					pStateEnvironment->SetNextState("waitforheater");
				}
				else
				{
					pStateEnvironment->LogMessage("Powder dosing was not successful");
					pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYDOSEPOWDER");
					pStateEnvironment->SetNextState("initerror");
				}
			}
			else 
			{
				// no response from PLC!
				pStateEnvironment->LogMessage("Powder dosing timeout");
				pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYDOSEPOWDERDUETOTIMEOUT");
				pStateEnvironment->SetNextState("initerror");
			}
		}
		else
		{
			pStateEnvironment->LogMessage("Initial recoater movement was not successful");
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYMOVERECOATER");
			pStateEnvironment->SetNextState("initerror");
		}
	}
	else
	{
		// no response from PLC!
		pStateEnvironment->LogMessage("Initial recoater movement timeout");
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALLYMOVERECOATERDUETOTIMEOUT");
		pStateEnvironment->SetNextState("initerror");
	}
}

__DECLARESTATE(waitforheater)
{
	// Get Timeouts
	uint32_t nHeaterTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "heatercontroltimeout");
	uint32_t nToggleValvesTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "togglevalvestimeout");

	//Check if the vacuum system should be used 
	bool bVacuumIsEnabled = pStateEnvironment->GetIntegerParameter("jobinfo", "vacuum_enabled_flag");

	auto pEnableControllerSignal = pStateEnvironment->PrepareSignal("plc", "signal_enablecontroller");
	pEnableControllerSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pEnableControllerSignal->Trigger();

	if (pEnableControllerSignal->WaitForHandling(nHeaterTimeout)) 
	{
		if (pEnableControllerSignal->GetBoolResult("success"))
		{
			auto pSignalSwitchValves = pStateEnvironment->PrepareSignal("plc", "signal_switchvalves");
			if (bVacuumIsEnabled)
			{
				// Open vacuum valves
				pSignalSwitchValves->SetBool("toggle_upper_gas_flow_circuit_valve", false);
				pSignalSwitchValves->SetBool("toggle_lower_gas_flow_circuit_valve", false);
				pSignalSwitchValves->SetBool("toggle_shielding_gas_valve", false);
				pSignalSwitchValves->SetBool("toggle_chamber_vacuum_valve", true);
				pSignalSwitchValves->SetBool("toggle_zAxis_vacuum_valve", true);
				pSignalSwitchValves->Trigger();
				if (pSignalSwitchValves->WaitForHandling(nToggleValvesTimeout))
				{
					if (pSignalSwitchValves->GetBoolResult("success"))
					{
						pStateEnvironment->SetNextState("waitforvacuum");
					}
					else
					{
						pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVES");
						pStateEnvironment->LogMessage("Switch valves was not successful");
						pStateEnvironment->SetNextState("initerror");
					}
				}
				else
				{
					pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVESDUETOTIMEOUT");
					pStateEnvironment->LogMessage("Switch valves timeout");
					pStateEnvironment->SetNextState("initerror");
				}
			}
			else
			{
				// Open circulation valves
				auto pSignalSwitchValves = pStateEnvironment->PrepareSignal("plc", "signal_switchvalves");
				pSignalSwitchValves->SetBool("toggle_upper_gas_flow_circuit_valve", true);
				pSignalSwitchValves->SetBool("toggle_lower_gas_flow_circuit_valve", true);
				pSignalSwitchValves->SetBool("toggle_shielding_gas_valve", false);
				pSignalSwitchValves->SetBool("toggle_chamber_vacuum_valve", false);
				pSignalSwitchValves->SetBool("toggle_zAxis_vacuum_valve", false);
				pSignalSwitchValves->Trigger();
				if (pSignalSwitchValves->WaitForHandling(nToggleValvesTimeout))
				{
					if (pSignalSwitchValves->GetBoolResult("success"))
					{
						pStateEnvironment->SetNextState("waitforatmospherewithoutpump");
					}
					else
					{
						pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVES");
						pStateEnvironment->LogMessage("Switch valves was not successful");
						pStateEnvironment->SetNextState("initerror");
					}
				}
				else
				{
					pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVESDUETOTIMEOUT");
					pStateEnvironment->LogMessage("Switch valves timeout");
					pStateEnvironment->SetNextState("initerror");
				}
			}
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTREACHBUILDPLATETEMPERATURE");
			pStateEnvironment->LogMessage("Reaching the build plate temperature was not successful");
			pStateEnvironment->SetNextState("initerror");
		}
	}
	else
	{
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTREACHBUILDPLATETEMPERATUREDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Build plate temperature timeout");
		pStateEnvironment->SetNextState("initerror");
	}
}

__DECLARESTATE(waitforvacuum)
{
	// Get Timeouts
	uint32_t nToggleValvesTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "togglevalvestimeout");
	uint32_t nVacuumTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "vacuumtimeout");
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");
	
	// get vacuum pressure parameter
	int nPressureThresholdVacuumOffInMbar = pStateEnvironment->GetIntegerParameter("jobinfo", "pressure_threshold_vacuum_off_in_mbar");
	 
	// turn on the vaccuum pump and wait until the pressure is reached --> plc signal returns true
	pStateEnvironment->LogMessage("Starting the vacuum pump ...");
	auto pStartVacuumPumpSignal = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_start_vacuum_pump");
	pStartVacuumPumpSignal->SetInteger("pressure_threshold_vacuum_off_in_mbar", nPressureThresholdVacuumOffInMbar);
	pStartVacuumPumpSignal->Trigger();

	if (pStartVacuumPumpSignal->WaitForHandling(nVacuumTimeout)) 
	{	
		if (pStartVacuumPumpSignal->GetBoolResult("success"))
		{
			auto pTurnOffVacuumPumpSignal = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_turn_off_vacuum_pump");
			pTurnOffVacuumPumpSignal->Trigger();
			if (pTurnOffVacuumPumpSignal->WaitForHandling(nGeneralCommandTimeout))
			{
				if (pTurnOffVacuumPumpSignal->GetBoolResult("success"))
				{
					// Close vacuum valves and open circulation valves
					auto pSignalSwitchValves = pStateEnvironment->PrepareSignal("plc", "signal_switchvalves");
					pSignalSwitchValves->SetBool("toggle_upper_gas_flow_circuit_valve", true);
					pSignalSwitchValves->SetBool("toggle_lower_gas_flow_circuit_valve", true);
					pSignalSwitchValves->SetBool("toggle_shielding_gas_valve", false);
					pSignalSwitchValves->SetBool("toggle_chamber_vacuum_valve", false);
					pSignalSwitchValves->SetBool("toggle_zAxis_vacuum_valve", false);
					pSignalSwitchValves->Trigger();
					if (pSignalSwitchValves->WaitForHandling(nToggleValvesTimeout)) 
					{
						if (pSignalSwitchValves->GetBoolResult("success"))
						{
							pStateEnvironment->SetNextState("waitforatmospherewithoutpump");
						}
						else
						{
							pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVES");
							pStateEnvironment->LogMessage("Switch valves was not successful");
							pStateEnvironment->SetNextState("initerror");
						}
					}
					else
					{
						pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTOGGLEVALVESDUETOTIMEOUT");
						pStateEnvironment->LogMessage("Switch valves timeout");
						pStateEnvironment->SetNextState("initerror");
					}
				}
				else
				{
					pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTURNOFFVACUUMPUMP");
					pStateEnvironment->LogMessage("Turning off the vacuum pump was not successful");
					pStateEnvironment->SetNextState("initerror");
				}
			}
			else
			{
				pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTTURNOFFVACUUMPUMPDUETOTIMEOUT");
				pStateEnvironment->LogMessage("Turn off vacuum pump timeout");
				pStateEnvironment->SetNextState("initerror");
			}
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHVACUUM");
			pStateEnvironment->LogMessage("Establishing vacuum was not successful");
			pStateEnvironment->SetNextState("initerror");
		}
	}
	else
	{
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHVACUUMDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Establishing vacuum timeout");
		pStateEnvironment->SetNextState("initerror");
	}
}

__DECLARESTATE(waitforatmospherewithoutpump)
{
	// Get Timeouts
	uint32_t nAtmosphereWithoutPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "atmospherewithoutpumptimeout");
	
	auto pEnableControllerSignal = pStateEnvironment->PrepareSignal("plc", "signal_enablecontroller");
	pEnableControllerSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pEnableControllerSignal->Trigger();
	
	if (pEnableControllerSignal->WaitForHandling(nAtmosphereWithoutPumpTimeout)) {
		if (pEnableControllerSignal->GetBoolResult("success"))
		{
			pStateEnvironment->SetNextState("waitforatmospherewithpump");
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHATMOSPHERE");
			pStateEnvironment->LogMessage("Establishing process atmosphere was not successful");
			pStateEnvironment->SetNextState("initerror");
		}
	}
	else
	{
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHATMOSPHEREDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Establishing process atmosphere timeout");
		pStateEnvironment->SetNextState("initerror");
	}
}

__DECLARESTATE(waitforatmospherewithpump)
{
	// Get Timeouts
	uint32_t nAtmosphereWithPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "atmospherewithpumptimeout");
	
	// Get gasflow setpoint
	int nSetpointInPercent = pStateEnvironment->GetIntegerParameter("jobinfo", "circulation_pump_setpoint_in_percent");

	auto pStartGasFlowSignal = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_start_gas_flow");
	pStartGasFlowSignal->SetInteger("setpoint_in_percent", nSetpointInPercent);
	pStartGasFlowSignal->Trigger();

	if (pStartGasFlowSignal->WaitForHandling(nAtmosphereWithPumpTimeout)) {
		if (pStartGasFlowSignal->GetBoolResult("success"))
		{
			// Set the circulation pump started flag
			pStateEnvironment->SetBoolParameter("jobinfo", "circulation_pump_started_flag", true);

			pStateEnvironment->SetNextState("beginlayer");
		}
		else
		{
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHATMOSPHERE");
			pStateEnvironment->LogMessage("Establishing process atmosphere was not successful");
			pStateEnvironment->SetNextState("initerror");
		}
	}
	else
	{
		pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTESTABLISHATMOSPHEREDUETOTIMEOUT");
		pStateEnvironment->LogMessage("Establishing process atmosphere timeout");
		pStateEnvironment->SetNextState("initerror");
	}
}

__DECLARESTATE(beginlayer)
{
	auto layerIndex = pStateEnvironment->GetIntegerParameter("jobinfo", "currentlayer");
	pStateEnvironment->LogMessage("Starting layer " + std::to_string(layerIndex));

	auto sJobUUID = pStateEnvironment->GetStringParameter("jobinfo", "jobuuid");
	auto nLayerCount = pStateEnvironment->GetIntegerParameter("jobinfo", "layercount");
	auto dTotalHeight = pStateEnvironment->GetDoubleParameter("jobinfo", "totalheight");
	
	auto pBuildJob = pStateEnvironment->GetBuildJob(sJobUUID);	
	auto dCurrentHeight = pBuildJob->GetZValueInMM(layerIndex);
	

	std::stringstream sLayerDisplay, sHeightDisplay;
	sLayerDisplay << layerIndex << " / " << (nLayerCount-1);
	sHeightDisplay << std::setprecision(4) << dCurrentHeight << " mm" << " / " << std::setprecision(4) << dTotalHeight << " mm";

	pStateEnvironment->SetDoubleParameter("jobinfo", "currentheight", dCurrentHeight);
	pStateEnvironment->SetStringParameter("ui", "currentlayerdisplay", sLayerDisplay.str());
	pStateEnvironment->SetStringParameter("ui", "currentheightdisplay", sHeightDisplay.str());


	pStateEnvironment->SetNextState("exposelayer");
}

__DECLARESTATE(exposelayer)
{

	//Get timeouts
	uint32_t nExposureTimeOut = pStateEnvironment->GetIntegerParameter("timeouts", "exposuretimeout");
	uint32_t nPowderDosingTimeOut = pStateEnvironment->GetIntegerParameter("timeouts", "powderdosingtimeout");
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	// Get the tolerances from the parameter groups
	int nHeaterTolerance = pStateEnvironment->GetIntegerParameter("jobinfo", "heatercontroller_tolerance_degree_celsius");
	int nAtmosphereGasFlowTolerance = pStateEnvironment->GetIntegerParameter("jobinfo", "oxygencontroller_tolerance_ppm");

	// Check if an atmosphere error, gasflow error or heater error has occured
	auto pCheckHeaterSignal = pStateEnvironment->PrepareSignal("plc", "signal_check_heater");
	pCheckHeaterSignal->SetInteger("heater_controller_tolerance_degree_celsius", nHeaterTolerance);
	pCheckHeaterSignal->Trigger();
	if (pCheckHeaterSignal->WaitForHandling(nGeneralCommandTimeout)) {
		if (pCheckHeaterSignal->GetBoolResult("heater_controller_enabled_setpoint_reached"))
		{
			auto pCheckAtmosphereSignal = pStateEnvironment->PrepareSignal("plc", "signal_check_atmosphere");
			pCheckAtmosphereSignal->SetInteger("atmosphere_controller_tolerance_ppm", nAtmosphereGasFlowTolerance);
			pCheckAtmosphereSignal->Trigger();
			if (pCheckAtmosphereSignal->WaitForHandling(nGeneralCommandTimeout)) {
				if (pCheckAtmosphereSignal->GetBoolResult("atmosphere_controller_enabled_setpoint_reached"))
				{
					auto pCheckGasFlowSignal = pStateEnvironment->PrepareSignal("plc", "signal_check_gas_flow");
					pCheckGasFlowSignal->SetInteger("atmosphere_controller_tolerance_ppm", nAtmosphereGasFlowTolerance);
					pCheckGasFlowSignal->Trigger();
					if (pCheckGasFlowSignal->WaitForHandling(nGeneralCommandTimeout)) {
						if (pCheckGasFlowSignal->GetBoolResult("circulation_pump_started_setpoint_reached"))
						{
							pStateEnvironment->LogMessage("No heater error, atmosphere error or gas flow error");
						}
						else
						{
							pStateEnvironment->LogMessage("The gas flow is not working properly");
							pStateEnvironment->SetNextState("gasflowerror");
							return;
						}
					}
					else
					{
						pStateEnvironment->LogMessage("Check atmosphere timeout");
						pStateEnvironment->SetNextState("waitforshutdown");
						return;
					}
				}
				else
				{
					pStateEnvironment->LogMessage("The shielding gas controller is not working properly");
					pStateEnvironment->SetNextState("atmosphereerror");
					return;
				}
			}
			else
			{
				pStateEnvironment->LogMessage("Check atmosphere timeout");
				pStateEnvironment->SetNextState("waitforshutdown");
				return;
			}
		}
		else
		{
			pStateEnvironment->LogMessage("The build platform heater controller is not working properly");
			pStateEnvironment->SetNextState("heatererror");
			return;
		}
	}
	else
	{
		pStateEnvironment->LogMessage("Check heater timeout");
		pStateEnvironment->SetNextState("waitforshutdown");
		return;
	}

	// In this state, the layer is exposed and simulatneosly the recoater is filled with powder if necessary

	// get parameters for the exposure command
	auto sJobUUID = pStateEnvironment->GetStringParameter("jobinfo", "jobuuid");
	auto nCurrentLayer = pStateEnvironment->GetIntegerParameter("jobinfo", "currentlayer");
	auto nLayerCount = pStateEnvironment->GetIntegerParameter("jobinfo", "layercount");
	

	// get parameters for the powder refill command
	auto pBuildJob = pStateEnvironment->GetBuildJob(sJobUUID);
	auto dCurrentLayerZ = pBuildJob->GetZValueInMM(nCurrentLayer);
	auto dTotalHeight = pStateEnvironment->GetDoubleParameter("jobinfo", "totalheight");
	auto dOldRecoaterFillingVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity");
	auto dRecoaterRefillPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_refill_position");
	auto dRecoatingStartPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoating_start_position");
	auto dPowderVolumePerNotchInCubicMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "powderreservoir_notch_volume_in_cubic_mm");
	auto dOldReservoirPowderVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentreservoirpowdercapacity");
	auto dOverDoseFactor = pStateEnvironment->GetDoubleParameter("jobinfo", "overdosefactor");
	auto nPowderreservoirNotchCount = pStateEnvironment->GetIntegerParameter("hardwareinformation", "powderreservoir_dosing_notch_count");
	auto dReservoirSpeedInDegreesPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_speed");
	auto dReservoirAccelerationInDegreesPerSecondSquared = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_acceleration");
	double dRecoaterPowderBeltWidthInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_powderbelt_width");
	double dRecoaterLevelingBladeHeightInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_powderbelt_levelingblade_height");

	//TODO: Debugging of layer indexing, currently only building until (nLayerCount-1)
	double dLayerHeightInMM = 0;

	//Initialize the powder dosing signal
	auto pMovementReservoirSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
	bool bPowderDosingTriggered = false;

	// check if this is the final layer
	if (nCurrentLayer < (nLayerCount - 1)) {

		// check the layerheight of the next layer
		auto dNextLayerZ = pBuildJob->GetZValueInMM(nCurrentLayer + 1);
		dLayerHeightInMM = dNextLayerZ - dCurrentLayerZ;

		if (dLayerHeightInMM < MIN_LAYERHEIGHTINMM)
			throw std::runtime_error("invalid layer height in layer " + std::to_string(nCurrentLayer) + ": " + std::to_string(dLayerHeightInMM) + "mm");
		// calculate powder needed for the next recoating
		double dNeededPowderVolumeInMMCubed = (dRecoatingStartPositionInMM - dRecoaterRefillPositionInMM) * dOverDoseFactor * dRecoaterPowderBeltWidthInMM * dRecoaterLevelingBladeHeightInMM;

		// check the current powder availability in the reservoir of the recoater
		if (dOldRecoaterFillingVolumeInMMCubed <= dNeededPowderVolumeInMMCubed)
		{
			// refill the recoater by the needed ammount
			auto nDosingUnits = (int32_t)round(((dNeededPowderVolumeInMMCubed - dOldRecoaterFillingVolumeInMMCubed) / dPowderVolumePerNotchInCubicMM) + 0.5);
			auto dRecoaterFillingVolumeInMMCubed = nDosingUnits * dPowderVolumePerNotchInCubicMM;

			pStateEnvironment->LogMessage("Refilling recoater with powder ...");
			double dTargetInDegrees = nDosingUnits * 360.0 / nPowderreservoirNotchCount;

			//Prepare the powder dosing signal
			pMovementReservoirSignal->SetInteger("axis_ID", AXISID_POWDERRESERVOIR); //axis_ID powder reservoir
			pMovementReservoirSignal->SetInteger("absoluterelative", RELATIVE_FLAG); //relative movement
			pMovementReservoirSignal->SetDouble("target", dTargetInDegrees);
			pMovementReservoirSignal->SetDouble("speed", dReservoirSpeedInDegreesPerSecond);
			pMovementReservoirSignal->SetDouble("acceleration", dReservoirAccelerationInDegreesPerSecondSquared);
			pMovementReservoirSignal->Trigger();
			bPowderDosingTriggered = true;

			// update powder reservoir volume 
			pStateEnvironment->SetDoubleParameter("jobinfo", "currentreservoirpowdercapacity", (dOldReservoirPowderVolumeInMMCubed - dRecoaterFillingVolumeInMMCubed));
			pStateEnvironment->SetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity", (dOldRecoaterFillingVolumeInMMCubed + dRecoaterFillingVolumeInMMCubed));

		}
	}
	
	pStateEnvironment->LogMessage("Exposing layer " + std::to_string(nLayerCount));

	// prepare exopse layer command
	auto pExposureSignal = pStateEnvironment->PrepareSignal("scanner", "signal_exposure");
	pExposureSignal->SetString("jobuuid", sJobUUID);
	pExposureSignal->SetInteger("layerindex", nCurrentLayer);
	pExposureSignal->Trigger();

	if (pExposureSignal->WaitForHandling((uint32_t)nExposureTimeOut)) {
		pStateEnvironment->LogMessage("Layer successfully exposed...");

	}
	else {
		pStateEnvironment->LogMessage("Layer exposure failed...");
		pStateEnvironment->SetNextState("fatalerror");
		return;
	}
	//check if a powder dosing was triggered
	if (bPowderDosingTriggered)
	{
		//check if powderdosing was done
		if (pMovementReservoirSignal->WaitForHandling((uint32_t)nPowderDosingTimeOut)) {
				
			if (pMovementReservoirSignal->GetBoolResult("success"))
			{
				pStateEnvironment->LogMessage("Powder dosing finished");
			}
			else {
				pStateEnvironment->LogMessage("Powder dosing failed");
				pStateEnvironment->SetNextState("fatalerror");
			}
				
		}
		else {
			pStateEnvironment->LogMessage("Refilling recoater failed, powder dosing timeout");
			pStateEnvironment->SetNextState("fatalerror");
			return;
		}

		

	}

	pStateEnvironment->SetNextState("recoatlayer");
}

__DECLARESTATE(recoatlayer)
{
	auto nRecoatLayerTimeOut = pStateEnvironment->GetDoubleParameter("timeouts", "recoatingtimeout");
	
	// move recoater linear to the recoat start position
	// drive build plate to desired layer height
	// recoat the layer


	std::string sJobUUID = pStateEnvironment->GetStringParameter("jobinfo", "jobuuid");
	auto layerIndex = pStateEnvironment->GetIntegerParameter("jobinfo", "currentlayer");
	auto layerCount = pStateEnvironment->GetIntegerParameter("jobinfo", "layercount");

	bool bFinished = (layerIndex >= layerCount-1);

	if (bFinished) {
		pStateEnvironment->SetNextState("finishlayer");
		return;
	}
	else {
		pStateEnvironment->LogMessage("Start recoating ...");
		auto pBuildJob = pStateEnvironment->GetBuildJob(sJobUUID);
		auto dCurrentLayerZ = pBuildJob->GetZValueInMM(layerIndex);
		auto dNextLayerZ = pBuildJob->GetZValueInMM(layerIndex + 1);

		double dLayerHeightInMM = dNextLayerZ - dCurrentLayerZ;
		if (dLayerHeightInMM < MIN_LAYERHEIGHTINMM)
			throw std::runtime_error("invalid layer height in layer " + std::to_string(layerIndex) + ": " + std::to_string(dLayerHeightInMM) + "mm");

		//Retrieve parameters of signal from jobinfo and hardware info
		double dPlatformAxisClearanceInMM = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_clearance");
		double dPlatformAxisSpeedInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_speed");
		double dPlatformAxisAccelerationInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_acceleration");
		double dRecoaterLinearAxisSpeedTravelInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_linear_speed_travel");
		double dRecoaterLinearAxesAccelerationTravelInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_axes_linear_acceleration_travel");
		double dRecoaterLinearAxisSpeedRecoatingInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_linear_speed_recoating");
		double dRecoaterLinearAxesAccelerationRecoatingInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_axes_linear_acceleration_recoating");
		double dRecoaterDosingFactor = pStateEnvironment->GetDoubleParameter("jobinfo", "overdosefactor");
		double dRecoaterRefillPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_refill_position");
		double dRecoatingStartPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoating_start_position");
		double dOldRecoaterPowderVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity");
		double dRecoaterPowderBeltWidthInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_powderbelt_width");
		double dRecoaterLevelingBladeHeightInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_powderbelt_levelingblade_height");

		pStateEnvironment->LogMessage("Trigger recoating signal ...");
		//Prepare the recoat layer signal
		auto pRecoatLayer = pStateEnvironment->PrepareSignal("plc", "signal_recoatlayer");
		pRecoatLayer->SetDouble("platformaxis_clearance", dPlatformAxisClearanceInMM);
		pRecoatLayer->SetDouble("platformaxis_speed", dPlatformAxisSpeedInMMPerSecond);
		pRecoatLayer->SetDouble("platformaxis_acceleration", dPlatformAxisAccelerationInMMPerSecondSqaured);
		pRecoatLayer->SetDouble("layer_height", dLayerHeightInMM);
		pRecoatLayer->SetDouble("recoater_linear_speed_travel", dRecoaterLinearAxisSpeedTravelInMMPerSecond);
		pRecoatLayer->SetDouble("recoater_axes_linear_acceleration_travel", dRecoaterLinearAxesAccelerationTravelInMMPerSecondSqaured);
		pRecoatLayer->SetDouble("recoater_linear_speed_recoating", dRecoaterLinearAxisSpeedRecoatingInMMPerSecond);
		pRecoatLayer->SetDouble("recoater_axes_linear_acceleration_recoating", dRecoaterLinearAxesAccelerationRecoatingInMMPerSecondSqaured);
		pRecoatLayer->SetDouble("recoater_axes_dosing_factor", dRecoaterDosingFactor);
		pRecoatLayer->SetDouble("recoater_refill_position", dRecoaterRefillPositionInMM);
		pRecoatLayer->SetDouble("recoating_start_position", dRecoatingStartPositionInMM);
		//Send the recoat layer signal to the plc state machine
		pRecoatLayer->Trigger();
		pStateEnvironment->LogMessage("Wait for recoating ...");
		if (pRecoatLayer->WaitForHandling(nRecoatLayerTimeOut)) {
			pStateEnvironment->LogMessage("Recoating finished");
			pStateEnvironment->SetNextState("finishlayer");

			double dLayerPowderVolumeInMMCubed = (dRecoatingStartPositionInMM - dRecoaterRefillPositionInMM) * dRecoaterDosingFactor * dRecoaterPowderBeltWidthInMM * dRecoaterLevelingBladeHeightInMM;
			double dRecoaterFillingVolumeInMMCubed = dOldRecoaterPowderVolumeInMMCubed - dLayerPowderVolumeInMMCubed;
			pStateEnvironment->SetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity", dRecoaterFillingVolumeInMMCubed);

			pStateEnvironment->LogMessage("Current recoater powder capacity: " + std::to_string(dRecoaterFillingVolumeInMMCubed) + " cubic mm");
		}
		else {
			// no response from PLC!
			pStateEnvironment->SetNextState("recoatingerror");
		}
	}
}


__DECLARESTATE(finishlayer)
{
	PSignalHandler pSignalHandler;
	auto layerIndex = pStateEnvironment->GetIntegerParameter("jobinfo", "currentlayer");
	auto layerCount = pStateEnvironment->GetIntegerParameter("jobinfo", "layercount");

	pStateEnvironment->LogMessage("Finished layer " + std::to_string(layerIndex));
	layerIndex = layerIndex + 1;
	pStateEnvironment->SetIntegerParameter ("jobinfo", "currentlayer", layerIndex);

	pStateEnvironment->LogMessage("Moving to layer " + std::to_string(layerIndex));

	bool bFinished = (layerIndex >= layerCount);
	
	if (bFinished) {
		pStateEnvironment->SetNextState("finishprocess");
	}
	else if (pStateEnvironment->WaitForSignal("signal_cancelbuild", 0 , pSignalHandler)) {
		pStateEnvironment->SetBoolParameter("ui", "build_canbecanceled", false);
		pStateEnvironment->SetNextState("cancelprocess");
		pSignalHandler->SignalHandled();
	}
	else {
		pStateEnvironment->SetNextState("beginlayer");
	}
}

__DECLARESTATE(finishprocess)
{
	pStateEnvironment->SetNextState("waitforshutdown");
}

__DECLARESTATE(pauseprocess)
{
	pStateEnvironment->SetNextState("beginlayer");
}

__DECLARESTATE(cancelprocess)
{
	pStateEnvironment->SetNextState("waitforshutdown");
}

__DECLARESTATE(waitforshutdown)
{	
	// reset shutdown parameters
	pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "NOERROR");

	// get timeouts
	uint32_t nLockDoorTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "lockdoortimeout");
	uint32_t nGeneralShutDownTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalshutdowntimeout");
	uint32_t nToggleValvesTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "togglevalvestimeout");

	// disable cancel build button 
	pStateEnvironment->SetBoolParameter("ui", "build_canbecanceled", false);
	
	// unlock door
	pStateEnvironment->LogMessage("Unlocking chamber door..");
	auto pLockDoorSignal = pStateEnvironment->PrepareSignal("plc", "signal_lockdoor");
	pLockDoorSignal->SetBool("lockdoor", false);
	pLockDoorSignal->Trigger();
	if (pLockDoorSignal->WaitForHandling(nLockDoorTimeout)) {
		bool bDoorIsLocked = pLockDoorSignal->GetBoolResult("doorlockstate");
		if (bDoorIsLocked) {
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTUNLOCKDOOR");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
		else
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "doorunlocked", true);
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTUNLOCKDOOR");
		pStateEnvironment->SetNextState("waitforshutdown");
	}
	
	// turn off vacuum pump
	pStateEnvironment->LogMessage("Turning off vacuum pump..");
	auto pTurnOffVacuumPumpSignal = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_turn_off_vacuum_pump");
	pTurnOffVacuumPumpSignal->Trigger();
	if (pTurnOffVacuumPumpSignal->WaitForHandling(nGeneralShutDownTimeout)) {
		if (pTurnOffVacuumPumpSignal->GetBoolResult("success")) 
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "vacuumpumpturnedoff", true);
		}
		else
		{
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFVACUUMPUMP");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFVACUUMPUMP");
		pStateEnvironment->SetNextState("waitforshutdown");
	}

	// disable heater controller
	pStateEnvironment->LogMessage("Disabling heater controller..");
	auto pDisableHeaterControllerSignal = pStateEnvironment->PrepareSignal("plc", "signal_disablecontroller");
	pDisableHeaterControllerSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pDisableHeaterControllerSignal->Trigger();
	if (pDisableHeaterControllerSignal->WaitForHandling(nGeneralShutDownTimeout)) {
		if (pDisableHeaterControllerSignal->GetBoolResult("success"))
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "heaterturnedoff", true);
		}
		else
		{
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFHEATER");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFHEATER");
		pStateEnvironment->SetNextState("waitforshutdown");
	}

	// disable shielding gas controller
	pStateEnvironment->LogMessage("Disabling oxygen controller..");
	auto pDisableOxygenControllerSignal = pStateEnvironment->PrepareSignal("plc", "signal_disablecontroller");
	pDisableOxygenControllerSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pDisableOxygenControllerSignal->Trigger();
	if (pDisableOxygenControllerSignal->WaitForHandling(nGeneralShutDownTimeout)) {
		if (pDisableOxygenControllerSignal->GetBoolResult("success"))
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "shieldinggasturnedoff", true);
		}
		else
		{
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFSHIELDINGGAS");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFSHIELDINGGAS");
		pStateEnvironment->SetNextState("waitforshutdown");
	}

	// turn off circulation pump
	pStateEnvironment->LogMessage("Turning off vacuum pump..");
	auto pTurnOffCirculationPumpSignal = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_turn_off_gas_flow");
	pTurnOffCirculationPumpSignal->Trigger();
	if (pTurnOffCirculationPumpSignal->WaitForHandling(nGeneralShutDownTimeout)) {
		if (pTurnOffCirculationPumpSignal->GetBoolResult("success"))
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "circulationpumpturnedoff", true);

			// Reset the circulation pump started flag
			pStateEnvironment->SetBoolParameter("jobinfo", "circulation_pump_started_flag", false);
		}
		else
		{
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFCIRCULATIONPUMP");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFCIRCULATIONPUMP");
		pStateEnvironment->SetNextState("waitforshutdown");
	}

	// shut valves
	pStateEnvironment->LogMessage("Shuting valves..");
	auto pSignalSwitchValves = pStateEnvironment->PrepareSignal("plc", "signal_switchvalves");
	pSignalSwitchValves->SetBool("toggle_upper_gas_flow_circuit_valve", false);
	pSignalSwitchValves->SetBool("toggle_lower_gas_flow_circuit_valve", false);
	pSignalSwitchValves->SetBool("toggle_shielding_gas_valve", false);
	pSignalSwitchValves->SetBool("toggle_chamber_vacuum_valve", false);
	pSignalSwitchValves->SetBool("toggle_zAxis_vacuum_valve", false);
	pSignalSwitchValves->Trigger();
	if (pSignalSwitchValves->WaitForHandling(nToggleValvesTimeout)) {
		if (pSignalSwitchValves->GetBoolResult("success"))
		{
			pStateEnvironment->SetBoolParameter("processshutdown", "valvesshut", true);
		}
		else
		{
			// Invalid response from PLC!
			pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFCIRCULATIONPUMP");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else {
		// No response from PLC!
		pStateEnvironment->SetStringParameter("processshutdown", "shutdownerror", "COULDNOTTURNOFFCIRCULATIONPUMP");
		pStateEnvironment->SetNextState("waitforshutdown");
	}

	// shutdown flags
	bool bDoorUnlocked = pStateEnvironment->GetBoolParameter("processshutdown", "doorunlocked");
	bool bVacuumPumpTurnedOff = pStateEnvironment->GetBoolParameter("processshutdown", "vacuumpumpturnedoff");
	bool bHeaterTurnedOff = pStateEnvironment->GetBoolParameter("processshutdown", "heaterturnedoff");
	bool bShieldingGasTurnedOff = pStateEnvironment->GetBoolParameter("processshutdown", "shieldinggasturnedoff");
	bool bCirculationPumpTurnedOff = pStateEnvironment->GetBoolParameter("processshutdown", "circulationpumpturnedoff");
	bool bValvesShut = pStateEnvironment->GetBoolParameter("processshutdown", "valvesshut");

	if (bDoorUnlocked && bVacuumPumpTurnedOff && bHeaterTurnedOff && bShieldingGasTurnedOff && bCirculationPumpTurnedOff && bValvesShut)
	{
		pStateEnvironment->SetNextState("idle");
	}
	pStateEnvironment->SetNextState("idle");
}

__DECLARESTATE(initerror)
{
	pStateEnvironment->LogMessage("Error during initialization!");
	pStateEnvironment->SetNextState("waitforshutdown");

}

__DECLARESTATE(powdererror)
{

}

__DECLARESTATE(heatererror)
{
	// Get Timeouts
	uint32_t nHeaterTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "heatercontroltimeout");

	auto pEnableControllerSignal = pStateEnvironment->PrepareSignal("plc", "signal_enablecontroller");
	pEnableControllerSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pEnableControllerSignal->Trigger();

	if (pEnableControllerSignal->WaitForHandling(nHeaterTimeout))
	{
		if (pEnableControllerSignal->GetBoolResult("success"))
		{
			pStateEnvironment->SetNextState("pauseprocess");
		}
		else
		{
			pStateEnvironment->LogMessage("Reaching the build plate temperature was not successful");
			pStateEnvironment->SetNextState("waitforshutdown");
		}
	}
	else
	{
		pStateEnvironment->LogMessage("Build plate temperature timeout");
		pStateEnvironment->SetNextState("waitforshutdown");
	}
}

__DECLARESTATE(atmosphereerror)
{

}

__DECLARESTATE(vacuumerror)
{

}


__DECLARESTATE(gasflowerror)
{

}

__DECLARESTATE(recoatingerror)
{
	pStateEnvironment->SetNextState("pauseprocess");
}

__DECLARESTATE(manualmovementcontrol)
{

	LibMCEnv::PSignalHandler pSignalHandler;

	if (pStateEnvironment->WaitForSignal("signal_manualmovementcontrol_enter", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("manualmovementcontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_manualmovementcontrol_leave", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("idle");
		pSignalHandler->SignalHandled();
	}
	
	else if (pStateEnvironment->WaitForSignal("signal_referenceaxis", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("manualreferencing");

		pStateEnvironment->StoreSignal("manualreference_signal", pSignalHandler);
	}

	else if (pStateEnvironment->WaitForSignal("signal_singleaxismovement", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("manualmovement");

		pStateEnvironment->StoreSignal("manualmovement_signal", pSignalHandler);
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualmovementcontrol_recoat_layer", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("manualrecoating");

		pStateEnvironment->StoreSignal("signal_manualmovementcontrol_recoat_layer", pSignalHandler);
	}

	else if (pStateEnvironment->WaitForSignal("signal_manual_powder_dosing", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("manualpowderdosing");

		pStateEnvironment->StoreSignal("signal_manual_powder_dosing", pSignalHandler);
	}
	else {
		pStateEnvironment->SetNextState("manualmovementcontrol");
	}
	
}

__DECLARESTATE(manualreferencing)
{
	auto pManualReferenceSignalHandler = pStateEnvironment->RetrieveSignal("manualreference_signal");

	bool bDoReferenceRecoaterAxisLinear = pManualReferenceSignalHandler->GetBool("reference_recoateraxis_linear");
	bool bDoReferenceRecoaterAxisPowder = pManualReferenceSignalHandler->GetBool("reference_recoateraxis_powder");
	bool bDoReferencePlatform = pManualReferenceSignalHandler->GetBool("reference_platform");
	bool bDoReferencePlatformAbsoluteSwitch = pManualReferenceSignalHandler->GetBool("reference_platform_absolute_switch");
	bool bDoReferencePowderReservoir = pManualReferenceSignalHandler->GetBool("reference_powderreservoir");

	std::vector<std::string> axesToMove; 
	if (bDoReferenceRecoaterAxisLinear)
		axesToMove.push_back("LinearRecoaterAxis");
	if (bDoReferenceRecoaterAxisPowder)
		axesToMove.push_back("PowderRecoaterAxis");
	if (bDoReferencePlatform || bDoReferencePlatformAbsoluteSwitch)
		axesToMove.push_back("Platform");
	if (bDoReferencePowderReservoir)
		axesToMove.push_back("PowderReservoir");

	if (axesToMove.size() > 0) {
		std::string sAxesString;
		for (auto axisString : axesToMove) {
			if (!sAxesString.empty())
				sAxesString += ", ";
			sAxesString += axisString;
		}
 
		auto nReferenceTimeout = 30000;

		pStateEnvironment->LogMessage("Manually Referencing " + sAxesString + "...");

		auto pReferenceSignal = pStateEnvironment->PrepareSignal("plc", "signal_reference");
		pReferenceSignal->SetBool("reference_recoateraxis_linear", bDoReferenceRecoaterAxisLinear);
		pReferenceSignal->SetBool("reference_recoateraxis_powder", bDoReferenceRecoaterAxisPowder);
		pReferenceSignal->SetBool("reference_platform", bDoReferencePlatform);
		pReferenceSignal->SetBool("reference_platform_absolute_switch", bDoReferencePlatformAbsoluteSwitch);
		pReferenceSignal->SetBool("reference_powderreservoir", bDoReferencePowderReservoir);
		pReferenceSignal->Trigger();

		if (pReferenceSignal->WaitForHandling(nReferenceTimeout)) {

			if (pReferenceSignal->GetBoolResult("success")) {
				pManualReferenceSignalHandler->SetBoolResult("success", true);
				pManualReferenceSignalHandler->SetIntegerResult("errorcode", 0);
				
				pStateEnvironment->LogMessage("Referencing finished!");

			}
			else {
				pManualReferenceSignalHandler->SetBoolResult("success", false);
				pManualReferenceSignalHandler->SetIntegerResult("errorcode", 1);
				pStateEnvironment->LogMessage("Referencing error.");

			}
			
		}
		else {
			pManualReferenceSignalHandler->SetBoolResult("success", false);
			pManualReferenceSignalHandler->SetIntegerResult("errorcode", 2);
			pStateEnvironment->LogMessage("Referencing timeout!");
		}
		
		

	}
	else {
		pStateEnvironment->LogMessage("No axis to reference!");

	}

	pManualReferenceSignalHandler->SignalHandled();

	pStateEnvironment->SetNextState("manualmovementcontrol");
}

__DECLARESTATE(manualmovement)
{

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("manualmovement_signal");

	try {
			auto nAxisID = pSignalHandler->GetInteger("axis_ID");
			auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");
			auto dTarget = pSignalHandler->GetDouble("target");
			auto dSpeed = pSignalHandler->GetDouble("speed");
			auto dAcceleration = pSignalHandler->GetDouble("acceleration");

			if ((nAxisID < MIN_AXIS_ID) || (nAxisID > MAX_AXIS_ID))
				throw std::runtime_error("invalid axis ID: " + std::to_string(nAxisID));
			if ((nAbsoluteRelative < ABSOLUTE_FLAG) || (nAbsoluteRelative > RELATIVE_FLAG))
				throw std::runtime_error("invalid movement type flag: " + std::to_string(nAbsoluteRelative));
			if ((dTarget < MIN_TARGET) || (dTarget > MAX_TARGET))
				throw std::runtime_error("invalid movement target: " + std::to_string(dTarget));
			if ((dSpeed < MIN_SPEED) || (dSpeed > MAX_SPEED))
				throw std::runtime_error("invalid movement speed: " + std::to_string(dSpeed));
			if ((dAcceleration < MIN_ACCELERATION) || (dAcceleration > MAX_ACCELERATION))
				throw std::runtime_error("invalid movement acceleration: " + std::to_string(dAcceleration));

			auto nReferenceTimeout = 30000;

			pStateEnvironment->LogMessage("Single axis movement");

			auto pMovementSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
			pMovementSignal->SetInteger("axis_ID", nAxisID);
			pMovementSignal->SetInteger("absoluterelative", nAbsoluteRelative);
			pMovementSignal->SetDouble("target",dTarget);
			pMovementSignal->SetDouble("speed", dSpeed);
			pMovementSignal->SetDouble("acceleration", dAcceleration);
			pMovementSignal->Trigger();

			if (pMovementSignal->WaitForHandling(nReferenceTimeout)) {

				if (pMovementSignal->GetBoolResult("success")) {

					pSignalHandler->SetBoolResult("success", true);
					pSignalHandler->SetIntegerResult("errorcode", 0);

					pStateEnvironment->LogMessage("Movement finished!");

				}
				else {

					pSignalHandler->SetBoolResult("success", false);
					pSignalHandler->SetIntegerResult("errorcode", 1);

					pStateEnvironment->LogMessage("Movement error.");

				}

			}
			else {

				pSignalHandler->SetBoolResult("success", false);
				pSignalHandler->SetIntegerResult("errorcode", 2);

				pStateEnvironment->LogMessage("Movement timeout!");
				pStateEnvironment->SetNextState("manualmovementcontrol");
			}
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("manualmovementcontrol");
		}
	catch (std::exception & E) {
		// TODO: Error Codes!
		pStateEnvironment->LogMessage("Error: " + std::string (E.what ()));
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SetIntegerResult("errorcode", 0);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualmovementcontrol");
	}
}

__DECLARESTATE(manualrecoating)
{
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_manualmovementcontrol_recoat_layer");

	auto nRecoatLayerTimeOut = pStateEnvironment->GetDoubleParameter("timeouts", "recoatingtimeout");
	pStateEnvironment->LogMessage("Start manual recoating ...");

	// retrieve dosing factor of the manual recoating command
	double dRecoaterDosingFactor = pSignalHandler->GetDouble("dosing_factor_manual");

	//Retrieve parameters of signal from jobinfo and hardware info
	double dPlatformAxisClearanceInMM = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_clearance");
	double dPlatformAxisSpeedInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_speed");
	double dPlatformAxisAccelerationInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "platformaxis_acceleration");
	double dLayerHeightInMM = pStateEnvironment->GetDoubleParameter("jobinfo", "layer_height");
	double dRecoaterLinearAxisSpeedTravelInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_linear_speed_travel");
	double dRecoaterLinearAxesAccelerationTravelInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_axes_linear_acceleration_travel");
	double dRecoaterLinearAxisSpeedRecoatingInMMPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_linear_speed_recoating");
	double dRecoaterLinearAxesAccelerationRecoatingInMMPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "recoater_axes_linear_acceleration_recoating");
	
	double dRecoaterRefillPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoater_refill_position");
	double dRecoatingStartPositionInMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "recoating_start_position");

	pStateEnvironment->LogMessage("Trigger recoating signal ...");
	//Prepare the recoat layer signal
	auto pRecoatLayer = pStateEnvironment->PrepareSignal("plc", "signal_recoatlayer");
	pRecoatLayer->SetDouble("platformaxis_clearance", dPlatformAxisClearanceInMM);
	pRecoatLayer->SetDouble("platformaxis_speed", dPlatformAxisSpeedInMMPerSecond);
	pRecoatLayer->SetDouble("platformaxis_acceleration", dPlatformAxisAccelerationInMMPerSecondSqaured);
	pRecoatLayer->SetDouble("layer_height", dLayerHeightInMM);
	pRecoatLayer->SetDouble("recoater_linear_speed_travel", dRecoaterLinearAxisSpeedTravelInMMPerSecond);
	pRecoatLayer->SetDouble("recoater_axes_linear_acceleration_travel", dRecoaterLinearAxesAccelerationTravelInMMPerSecondSqaured);
	pRecoatLayer->SetDouble("recoater_linear_speed_recoating", dRecoaterLinearAxisSpeedRecoatingInMMPerSecond);
	pRecoatLayer->SetDouble("recoater_axes_linear_acceleration_recoating", dRecoaterLinearAxesAccelerationRecoatingInMMPerSecondSqaured);
	pRecoatLayer->SetDouble("recoater_axes_dosing_factor", dRecoaterDosingFactor);
	pRecoatLayer->SetDouble("recoater_refill_position", dRecoaterRefillPositionInMM);
	pRecoatLayer->SetDouble("recoating_start_position", dRecoatingStartPositionInMM);
	//Send the recoat layer signal to the plc state machine
	pRecoatLayer->Trigger();
	pStateEnvironment->LogMessage("Wait for recoating ...");
	if (pRecoatLayer->WaitForHandling(nRecoatLayerTimeOut)) {
		pSignalHandler->SetBoolResult("success", true);
		pStateEnvironment->LogMessage("Recoating finished");
		pStateEnvironment->SetNextState("manualmovementcontrol");
	}
	else {
		// no response from PLC!
		pSignalHandler->SetBoolResult("success", false);
		pStateEnvironment->LogMessage("Recoating timeout");
		pStateEnvironment->SetNextState("manualmovementcontrol");
	}
	
	pSignalHandler->SignalHandled();

}

__DECLARESTATE(manualpowderdosing)
{
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_manual_powder_dosing");
	pStateEnvironment->LogMessage("Start powder dosing from the reservoir ...");

	// retrieve dosing units of the manual powder dosing command
	int nDosingNotches = pSignalHandler->GetInteger("dosing_notches");

	//Retrieve parameters of signal from jobinfo and hardware info
	int nPowderDosingTimeOut = pStateEnvironment->GetDoubleParameter("timeouts", "powderdosingtimeout");
	int nPowderreservoirNotchCount = pStateEnvironment->GetIntegerParameter("hardwareinformation", "powderreservoir_dosing_notch_count");
	double dSpeedInDegreesPerSecond = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_speed");
	double dAccelerationInDegreesPerSecondSqaured = pStateEnvironment->GetDoubleParameter("jobinfo", "powderreservoir_acceleration");
	double dPowderVolumePerNotchInCubicMM = pStateEnvironment->GetDoubleParameter("hardwareinformation", "powderreservoir_notch_volume_in_cubic_mm");
	double dOldReservoirPowderVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentreservoirpowdercapacity");
	double dOldRecoaterPowderVolumeInMMCubed = pStateEnvironment->GetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity");
	
	double dTargetInDegrees = nDosingNotches * 360.0 / nPowderreservoirNotchCount;

	//Prepare the powder dosing signal
	auto pMovementSignal = pStateEnvironment->PrepareSignal("plc", "signal_singleaxismovement");
	pMovementSignal->SetInteger("axis_ID", 2); //axis_ID powder reservoir
	pMovementSignal->SetInteger("absoluterelative", 2); //relative movement
	pMovementSignal->SetDouble("target", dTargetInDegrees);
	pMovementSignal->SetDouble("speed", dSpeedInDegreesPerSecond);
	pMovementSignal->SetDouble("acceleration", dAccelerationInDegreesPerSecondSqaured);

	//Send the powder dosing signal to the plc state machine
	pMovementSignal->Trigger();
	pStateEnvironment->LogMessage("Wait for powder dosing ...");
	if (pMovementSignal->WaitForHandling(nPowderDosingTimeOut)) {
		pSignalHandler->SetBoolResult("success", true);
		pStateEnvironment->LogMessage("Powder dosing finished");
		pStateEnvironment->SetNextState("manualmovementcontrol");

		double dRecoaterFillingVolumeInMMCubed = dPowderVolumePerNotchInCubicMM * nDosingNotches;
		pStateEnvironment->SetDoubleParameter("jobinfo", "currentrecoaterpowdercapacity", (dOldRecoaterPowderVolumeInMMCubed + dRecoaterFillingVolumeInMMCubed));
		pStateEnvironment->SetDoubleParameter("jobinfo", "currentreservoirpowdercapacity", (dOldReservoirPowderVolumeInMMCubed - dRecoaterFillingVolumeInMMCubed));

		pStateEnvironment->LogMessage("Powder dosing finished");
		pStateEnvironment->LogMessage("Current recoater powder capacity: " + std::to_string(dOldRecoaterPowderVolumeInMMCubed + dRecoaterFillingVolumeInMMCubed) + " cubic mm");
		pStateEnvironment->LogMessage("Current reservoir powder capacity: " + std::to_string((dOldReservoirPowderVolumeInMMCubed - dRecoaterFillingVolumeInMMCubed)) + " cubic mm");

	}
	else {
		// no response from PLC!
		pSignalHandler->SetBoolResult("success", false);
		pStateEnvironment->LogMessage("Powder dosing timeout");
		pStateEnvironment->SetNextState("manualmovementcontrol");
	}
	pSignalHandler->SignalHandled();
}

__DECLARESTATE(manualatmospherecontrol)
{
	// Get Timeouts
	uint32_t nOxygenInitTimeout = pStateEnvironment->GetDoubleParameter("timeouts", "oxygeninittimeout");
	uint32_t nVacuumInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "vacuuminittimeout");
	uint32_t nAtmosphereInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "atmosphereinittimeout");
	
	//TODO: button to trigger manualexposure_signal
	pStateEnvironment->SetNextState("manualatmospherecontrol");

	LibMCEnv::PSignalHandler pSignalHandler;
	if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_enter", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_leave", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		pStateEnvironment->SetNextState("idle");
	}
	else if (pStateEnvironment->WaitForSignal("signal_manualtogglevalves", 0, pSignalHandler)) {

		auto nValve_ID = pSignalHandler->GetInteger("valve_ID");
		pSignalHandler->SignalHandled();
		
		auto pSignal_togglevalves = pStateEnvironment->PrepareSignal("plc", "signal_togglevalve");
		pSignal_togglevalves ->SetInteger("valve_ID", nValve_ID);
		pSignal_togglevalves->Trigger();

	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_init", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto no2_threshold_circulation_on_in_ppm = pStateEnvironment->GetIntegerParameter("hardwareinformation", "o2_threshold_circulation_on_in_ppm");
		auto no2_threshold_circulation_off_in_ppm = pStateEnvironment->GetIntegerParameter("hardwareinformation", "o2_threshold_circulation_off_in_ppm");

		auto pSignalInitAtmosphereControl = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_init");
		pSignalInitAtmosphereControl->SetInteger("o2_threshold_circulation_on_in_ppm", no2_threshold_circulation_on_in_ppm);
		pSignalInitAtmosphereControl->SetInteger("o2_threshold_circulation_off_in_ppm", no2_threshold_circulation_off_in_ppm);
		pSignalInitAtmosphereControl->Trigger();

		if (pSignalInitAtmosphereControl->WaitForHandling(nAtmosphereInitTimeout)) {
			bool bAtmosphereControllerIsReady = pSignalInitAtmosphereControl->GetBoolResult("success");

			pStateEnvironment->SetBoolParameter("processinitialization", "atmospherecontroller_ready", bAtmosphereControllerIsReady);
			if (bAtmosphereControllerIsReady)
				pStateEnvironment->LogMessage("Atmosphere controller initialized");
			else
				pStateEnvironment->LogMessage("Could not initialize atmosphere controller");
		}
		else {
			// No response from PLC!
			pStateEnvironment->LogMessage("No response from PLC");
			pStateEnvironment->SetBoolParameter("processinitialization", "atmospherecontroller_ready", false);
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEATMOSPHERECONTROLLER");
			pStateEnvironment->SetNextState("manualatmospherecontrol");
		}
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_update_gas_flow_setpoint", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto nsetpoint_in_percent = pStateEnvironment->GetIntegerParameter("jobinfo", "circulation_pump_setpoint_in_percent");

		auto pSignal_atmospherecontrol_update_gas_flow_setpoint = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_update_gas_flow_setpoint");
		pSignal_atmospherecontrol_update_gas_flow_setpoint->SetInteger("setpoint_in_percent", nsetpoint_in_percent);
		pSignal_atmospherecontrol_update_gas_flow_setpoint->Trigger();
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_start_gas_flow", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto nsetpoint_in_percent = pStateEnvironment->GetIntegerParameter("jobinfo", "circulation_pump_setpoint_in_percent");

		auto pSignal_atmospherecontrol_update_gas_flow_setpoint = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_start_gas_flow");
		pSignal_atmospherecontrol_update_gas_flow_setpoint->SetInteger("setpoint_in_percent", nsetpoint_in_percent);
		pSignal_atmospherecontrol_update_gas_flow_setpoint->Trigger();

		// Set the circulation pump started flag
		pStateEnvironment->SetBoolParameter("jobinfo", "circulation_pump_started_flag", true);
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_turn_off_gas_flow", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto pSignal_atmospherecontrol_update_gas_flow_setpoint = pStateEnvironment->PrepareSignal("plc", "signal_atmospherecontrol_turn_off_gas_flow");
		pSignal_atmospherecontrol_update_gas_flow_setpoint->Trigger();

		// Reset the circulation pump started flag
		pStateEnvironment->SetBoolParameter("jobinfo", "circulation_pump_started_flag", false);
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_save", 0, pSignalHandler)) {

		auto nsetpointinpercent = pSignalHandler->GetInteger("setpointinpercent");
		pSignalHandler->SignalHandled();

		pStateEnvironment->SetIntegerParameter("jobinfo", "circulation_pump_setpoint_in_percent", nsetpointinpercent);
	}

	else if (pStateEnvironment->WaitForSignal("signal_manualvacuumcontrol_init", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto npressure_threshold_vacuum_off_in_mbar = pStateEnvironment->GetIntegerParameter("jobinfo", "pressure_threshold_vacuum_off_in_mbar");

		auto pSignalInitVacuumControl = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_init");
		pSignalInitVacuumControl->SetInteger("pressure_threshold_vacuum_off_in_mbar", npressure_threshold_vacuum_off_in_mbar);
		pSignalInitVacuumControl->Trigger();

		if (pSignalInitVacuumControl->WaitForHandling(nVacuumInitTimeout)) {
			bool bVacuumControllerIsReady = pSignalInitVacuumControl->GetBoolResult("success");

			pStateEnvironment->SetBoolParameter("processinitialization", "vacuumcontroller_ready", bVacuumControllerIsReady);
			if (bVacuumControllerIsReady)
				pStateEnvironment->LogMessage("Vacuum controller initialized");
			else
				pStateEnvironment->LogMessage("Could not initialize vacuum controller");
		}
		else {
			// No response from PLC!
			pStateEnvironment->LogMessage("No response from PLC");
			pStateEnvironment->SetBoolParameter("processinitialization", "vacuumcontroller_ready", false);
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEVACUUMCONTROLLER");
			pStateEnvironment->SetNextState("manualatmospherecontrol");
		}

	}

	else if (pStateEnvironment->WaitForSignal("signal_manualvacuumcontrol_start_vacuum_pump", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto pSignal_vacuumcontrol_start_vacuum_pump = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_start_vacuum_pump");
		pSignal_vacuumcontrol_start_vacuum_pump->Trigger();

	}

	else if (pStateEnvironment->WaitForSignal("signal_manualvacuumcontrol_turn_off_vacuum_pump", 0, pSignalHandler)) {

		pSignalHandler->SignalHandled();

		auto pSignal_vacuumcontrol_turn_off_vacuum_pump = pStateEnvironment->PrepareSignal("plc", "signal_vacuumcontrol_turn_off_vacuum_pump");
		pSignal_vacuumcontrol_turn_off_vacuum_pump->Trigger();

	}

	else if (pStateEnvironment->WaitForSignal("signal_initoxygen", 0, pSignalHandler)) {
		pSignalHandler->SignalHandled();

		//retrieve PID, tuner, and PWM parameters from the parameter group
		//retrieve PID parameters from the parameter group
		auto dDerivativetime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "derivativetime");
		auto dIntegrationtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "integrationtime");
		auto dGain = pStateEnvironment->GetDoubleParameter("oxygencontroller", "gain");
		auto dFiltertime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "filtertime");
		auto nMaxout = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxout");
		auto nMinout = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minout");
		//retrieve PWM parameters from the parameter group
		auto nDutycycle = pStateEnvironment->GetIntegerParameter("oxygencontroller", "dutycycle");
		auto dPeriodTime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "periodTime");
		auto nMaxFrequency = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxFrequency");
		auto bMode = pStateEnvironment->GetBoolParameter("oxygencontroller", "mode");
		//retrieve tuning parameters from the parameter group
		auto nStepheight = pStateEnvironment->GetIntegerParameter("oxygencontroller", "stepheight");
		auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxactvalue");
		auto nMinactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minactvalue");
		auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "systemsettlingtime");
		auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "maxtuningtime");


		// send signal to plc state machine to update the oxygen control tuner parameters
		auto pSignalInitTunerOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollertuner");
		pSignalInitTunerOxygen->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitTunerOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignalInitTunerOxygen->SetInteger("stepheight", nStepheight);
		pSignalInitTunerOxygen->SetInteger("maxactvalue", nMaxactvalue);
		pSignalInitTunerOxygen->SetInteger("minactvalue", nMinactvalue);
		pSignalInitTunerOxygen->SetDouble("systemsettlingtime", dSystemsettlingtime);
		pSignalInitTunerOxygen->SetDouble("maxtuningtime", dMaxtuningtime);
		pSignalInitTunerOxygen->Trigger();

		// send signal to plc state machine to update the oxygen control PWM parameters
		auto pSignalInitPWMOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
		pSignalInitPWMOxygen->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitPWMOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignalInitPWMOxygen->SetInteger("dutycycle", nDutycycle);
		pSignalInitPWMOxygen->SetDouble("periodTime", dPeriodTime);
		pSignalInitPWMOxygen->SetInteger("maxFrequency", nMaxFrequency);
		pSignalInitPWMOxygen->SetBool("mode", bMode);
		pSignalInitPWMOxygen->Trigger();

		// send signal to plc state machine to update the oxygen control PID parameters
		auto pSignalInitPIDOxygen = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
		pSignalInitPIDOxygen->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitPIDOxygen->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignalInitPIDOxygen->SetDouble("derivativetime", dDerivativetime);
		pSignalInitPIDOxygen->SetDouble("integrationtime", dIntegrationtime);
		pSignalInitPIDOxygen->SetDouble("gain", dGain);
		pSignalInitPIDOxygen->SetDouble("filtertime", dFiltertime);
		pSignalInitPIDOxygen->SetInteger("maxout", nMaxout);
		pSignalInitPIDOxygen->SetInteger("minout", nMinout);
		pSignalInitPIDOxygen->Trigger();

		if (pSignalInitTunerOxygen->WaitForHandling(nOxygenInitTimeout) && pSignalInitPWMOxygen->WaitForHandling(nOxygenInitTimeout) && pSignalInitPIDOxygen->WaitForHandling(nOxygenInitTimeout)) {
			bool bTunerReadyOxygen = pSignalInitTunerOxygen->GetBoolResult("success");
			bool bPWMReadyOxygen = pSignalInitPWMOxygen->GetBoolResult("success");
			bool bPIDReadyOxygen = pSignalInitPIDOxygen->GetBoolResult("success");

			bool bOxygenControllerIsReady = bTunerReadyOxygen && bPWMReadyOxygen && bPIDReadyOxygen;

			pStateEnvironment->SetBoolParameter("processinitialization", "oxygencontroller_ready", bOxygenControllerIsReady);

			std::vector<std::string> readyControllersOxygen;
			std::vector<std::string> notReadyControllersOxygen;
			if (bTunerReadyOxygen)
				readyControllersOxygen.push_back("HeaterControllerTuner");
			else
				notReadyControllersOxygen.push_back("HeaterControllerTuner");
			if (bPWMReadyOxygen)
				readyControllersOxygen.push_back("HeaterControllerPWM");
			else
				notReadyControllersOxygen.push_back("HeaterControllerPWM");
			if (bPIDReadyOxygen)
				readyControllersOxygen.push_back("HeaterControllerPID");
			else
				notReadyControllersOxygen.push_back("HeaterControllerPID");

			if (readyControllersOxygen.size() > 0) {
				std::string sReadyControllersOxygenString;
				for (auto controllerString : readyControllersOxygen) {
					if (!sReadyControllersOxygenString.empty())
						sReadyControllersOxygenString += ", ";
					sReadyControllersOxygenString += controllerString;
				}
				pStateEnvironment->LogMessage("Initializing of " + sReadyControllersOxygenString + " successfull");
			}
			if (notReadyControllersOxygen.size() > 0) {
				std::string sNotReadyControllersOxygenString;
				for (auto controllerString : notReadyControllersOxygen) {
					if (!sNotReadyControllersOxygenString.empty())
						sNotReadyControllersOxygenString += ", ";
					sNotReadyControllersOxygenString += controllerString;
				}
				pStateEnvironment->LogMessage("Initializing of " + sNotReadyControllersOxygenString + " failed");
			}
			pStateEnvironment->SetNextState("manualatmospherecontrol");
		}
		else {
			// No response from PLC!
			pStateEnvironment->LogMessage("No response from PLC");
			pStateEnvironment->SetBoolParameter("processinitialization", "oxygencontroller_ready", false);
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEOXYGENCONTROLLER");
			pStateEnvironment->SetNextState("manualatmospherecontrol");
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_controllerparameters_save", 0, pSignalHandler))
	{
		auto nController_ID = pSignalHandler->GetInteger("controller_ID");
		if (nController_ID == CONTROLLER_ID_SHIELDINGGAS)
		{
			// retrieve values to save from signal
			auto dDerivativetime = pSignalHandler->GetDouble("derivativetime");
			auto dIntegrationtime = pSignalHandler->GetDouble("integrationtime");
			auto dGain = pSignalHandler->GetDouble("gain");
			auto dFiltertime = pSignalHandler->GetDouble("filtertime");
			auto nMaxout = pSignalHandler->GetInteger("maxout");
			auto nMinout = pSignalHandler->GetInteger("minout");
			auto nDutycycle = pSignalHandler->GetInteger("dutycycle");
			auto dPeriodTime = pSignalHandler->GetDouble("periodTime");
			auto nMaxFrequency = pSignalHandler->GetInteger("maxFrequency");
			auto bMode = pSignalHandler->GetBool("mode");
			auto nStepheight = pSignalHandler->GetInteger("stepheight");
			auto nMaxactvalue = pSignalHandler->GetInteger("maxactvalue");
			auto nMinactvalue = pSignalHandler->GetInteger("minactvalue");
			auto dSystemsettlingtime = pSignalHandler->GetDouble("systemsettlingtime");
			auto dMaxtuningtime = pSignalHandler->GetDouble("maxtuningtime");
			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();

				
			// store values in the parameter group
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "derivativetime", dDerivativetime);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "integrationtime", dIntegrationtime);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "gain", dGain);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "filtertime", dFiltertime);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "maxout", nMaxout);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "minout", nMinout);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "dutycycle", nDutycycle);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "periodTime", dPeriodTime);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "maxFrequency", nMaxFrequency);
			pStateEnvironment->SetBoolParameter("oxygencontroller", "mode", bMode);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "stepheight", nStepheight);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "maxactvalue", nMaxactvalue);
			pStateEnvironment->SetIntegerParameter("oxygencontroller", "minactvalue", nMinactvalue);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "systemsettlingtime", dSystemsettlingtime);
			pStateEnvironment->SetDoubleParameter("oxygencontroller", "maxtuningtime", dMaxtuningtime);

		}
		pStateEnvironment->SetNextState("manualatmospherecontrol");
	}
	else if (pStateEnvironment->WaitForSignal("signal_enableoxygencontroller", 0, pSignalHandler))
	{

		pStateEnvironment->SetNextState("manualatmospherecontrol");
		// send signal to plc state machine to enable the oxygen controller
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_enablecontroller");
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->Trigger();
		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_disableoxygencontroller", 0, pSignalHandler))
	{

		pStateEnvironment->SetNextState("manualatmospherecontrol");
		// send signal to plc state machine to disable the oxygen controller
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_disablecontroller");
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->Trigger();
		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_updatePIDoxygencontroller", 0, pSignalHandler))
	{

		//retrieve PID parameters from the parameter group
		auto dDerivativetime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "derivativetime");
		auto dIntegrationtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "integrationtime");
		auto dGain = pStateEnvironment->GetDoubleParameter("oxygencontroller", "gain");
		auto dFiltertime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "filtertime");
		auto nMaxout = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxout");
		auto nMinout = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minout");

		// send signal to plc state machine to update the heater control PID parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->SetDouble("derivativetime", dDerivativetime);
		pSignal->SetDouble("integrationtime", dIntegrationtime);
		pSignal->SetDouble("gain", dGain);
		pSignal->SetDouble("filtertime", dFiltertime);
		pSignal->SetInteger("maxout", nMaxout);
		pSignal->SetInteger("minout", nMinout);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_updatePWMoxygencontroller", 0, pSignalHandler))
	{

		//retrieve PWM parameters from the parameter group
		auto nDutycycle = pStateEnvironment->GetIntegerParameter("oxygencontroller", "dutycycle");
		auto dPeriodTime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "periodTime");
		auto nMaxFrequency = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxFrequency");
		auto bMode = pStateEnvironment->GetBoolParameter("oxygencontroller", "mode");


		// send signal to plc state machine to update the heater control PWM parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->SetInteger("dutycycle", nDutycycle);
		pSignal->SetDouble("periodTime", dPeriodTime);
		pSignal->SetInteger("maxFrequency", nMaxFrequency);
		pSignal->SetBool("mode", bMode);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

		}
	else if (pStateEnvironment->WaitForSignal("signal_updatetuneroxygencontroller", 0, pSignalHandler))
	{

		//retrieve tuner parameters from the parameter group
		auto nStepheight = pStateEnvironment->GetIntegerParameter("oxygencontroller", "stepheight");
		auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxactvalue");
		auto nMinactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minactvalue");
		auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "systemsettlingtime");
		auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "maxtuningtime");


		// send signal to plc state machine to update the heater control tuner parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollertuner");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->SetInteger("stepheight", nStepheight);
		pSignal->SetInteger("maxactvalue", nMaxactvalue);
		pSignal->SetInteger("minactvalue", nMinactvalue);
		pSignal->SetDouble("systemsettlingtime", dSystemsettlingtime);
		pSignal->SetDouble("maxtuningtime", dMaxtuningtime);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_updateoxygensetpoint", 0, pSignalHandler))
	{

		pStateEnvironment->SetNextState("manualatmospherecontrol");

		//retrieve PID parameters from the parameter group
		auto nSetpoint = pStateEnvironment->GetIntegerParameter("oxygencontroller", "setpoint");

		// send signal to plc state machine to update the heater setpoint
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pSignal->SetInteger("setpoint", nSetpoint);
		pSignal->Trigger();
		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualatmospherecontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_manual_controllertuning", 0, pSignalHandler)) {

		auto nController_ID = pSignalHandler->GetInteger("controller_ID");
		if (nController_ID == CONTROLLER_ID_SHIELDINGGAS)
		{

			//retrieve tuner parameters from the parameter group
			auto nStepheight = pStateEnvironment->GetIntegerParameter("oxygencontroller", "stepheight");
			auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "maxactvalue");
			auto nMinactvalue = pStateEnvironment->GetIntegerParameter("oxygencontroller", "minactvalue");
			auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "systemsettlingtime");
			auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("oxygencontroller", "maxtuningtime");


			// send signal to plc state machine to perform a auto tuning of the heater controller
			auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
			pSignal->SetInteger("stepheight", nStepheight);
			pSignal->SetInteger("maxactvalue", nMaxactvalue);
			pSignal->SetInteger("minactvalue", nMinactvalue);
			pSignal->SetDouble("systemsettlingtime", dSystemsettlingtime);
			pSignal->SetDouble("maxtuningtime", dMaxtuningtime);
			pSignal->Trigger();


			if (pSignal->WaitForHandling(1000))
			{
				pSignalHandler->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
			}

			pSignalHandler->SignalHandled();
			return;
		}
		pStateEnvironment->SetNextState("waitforcontrollertuning");
	}
	else 
	{
		pStateEnvironment->SetNextState("manualatmospherecontrol");
	}
}

__DECLARESTATE(manuallasercontrol)
{
	LibMCEnv::PSignalHandler pSignalHandler;
	//TODO: cancel manual laser control signal adn go back to idle
	//pStateEnvironment->SetNextState("idle");
	//TODO: button to trigger manualexposure_signal
	
	if (pStateEnvironment->WaitForSignal("signal_manualcontrol_exposure", 0, pSignalHandler)) {
		pStateEnvironment->SetNextState("manualexposure");

		pStateEnvironment->StoreSignal("manualexposure_signal", pSignalHandler);
	}
	else {
		pStateEnvironment->SetNextState("manuallasercontrol");
	}
}

__DECLARESTATE(manualexposure)
{
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("manualexposure_signal");

	std::string sJobUUID = pSignalHandler->GetString("jobuuid");
	int64_t nLayerIndex = pSignalHandler->GetInteger("layerindex");

	pStateEnvironment->LogMessage("Manually Exposure of Job " + sJobUUID + " layer " + std::to_string(nLayerIndex) + "...");

	pStateEnvironment->Sleep(5000);

	pSignalHandler->SetBoolResult("success", true);
	pSignalHandler->SetIntegerResult("errorcode", 0);

	pSignalHandler->SignalHandled();

	pStateEnvironment->SetNextState("manuallasercontrol");


}

__DECLARESTATE(manualheatercontrol)
{
	pStateEnvironment->SetNextState("manualheatercontrol");

	LibMCEnv::PSignalHandler pSignalHandler;
	
	// Get Timeouts
	uint32_t nHeaterInitTimeout = pStateEnvironment->GetDoubleParameter("timeouts", "heaterinittimeout");

	if (pStateEnvironment->WaitForSignal("signal_initheater", 0, pSignalHandler)) {
		pSignalHandler->SignalHandled();

		//retrieve PID, tuner, and PWM parameters from the parameter group
		//retrieve PID parameters from the parameter group
		auto dDerivativetime = pStateEnvironment->GetDoubleParameter("heatercontroller", "derivativetime");
		auto dIntegrationtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "integrationtime");
		auto dGain = pStateEnvironment->GetDoubleParameter("heatercontroller", "gain");
		auto dFiltertime = pStateEnvironment->GetDoubleParameter("heatercontroller", "filtertime");
		auto nMaxout = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxout");
		auto nMinout = pStateEnvironment->GetIntegerParameter("heatercontroller", "minout");
		//retrieve PWM parameters from the parameter group
		auto nDutycycle = pStateEnvironment->GetIntegerParameter("heatercontroller", "dutycycle");
		auto dPeriodTime = pStateEnvironment->GetDoubleParameter("heatercontroller", "periodTime");
		auto nMaxFrequency = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxFrequency");
		auto bMode = pStateEnvironment->GetBoolParameter("heatercontroller", "mode");
		//retrieve tuning parameters from the parameter group
		auto nStepheight = pStateEnvironment->GetIntegerParameter("heatercontroller", "stepheight");
		auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxactvalue");
		auto nMinactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "minactvalue");
		auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "systemsettlingtime");
		auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "maxtuningtime");


		// send signal to plc state machine to update the heater control tuner parameters
		auto pSignalInitTunerHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollertuner");
		pSignalInitTunerHeater->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitTunerHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignalInitTunerHeater->SetInteger("stepheight", nStepheight);
		pSignalInitTunerHeater->SetInteger("maxactvalue", nMaxactvalue);
		pSignalInitTunerHeater->SetInteger("minactvalue", nMinactvalue);
		pSignalInitTunerHeater->SetDouble("systemsettlingtime", dSystemsettlingtime);
		pSignalInitTunerHeater->SetDouble("maxtuningtime", dMaxtuningtime);
		pSignalInitTunerHeater->Trigger();

		// send signal to plc state machine to update the heater control PWM parameters
		auto pSignalInitPWMHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
		pSignalInitPWMHeater->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitPWMHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignalInitPWMHeater->SetInteger("dutycycle", nDutycycle);
		pSignalInitPWMHeater->SetDouble("periodTime", dPeriodTime);
		pSignalInitPWMHeater->SetInteger("maxFrequency", nMaxFrequency);
		pSignalInitPWMHeater->SetBool("mode", bMode);
		pSignalInitPWMHeater->Trigger();

		// send signal to plc state machine to update the heater control PID parameters
		auto pSignalInitPIDHeater = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
		pSignalInitPIDHeater->SetBool("isinit", CONTROLLER_INIT);
		pSignalInitPIDHeater->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignalInitPIDHeater->SetDouble("derivativetime", dDerivativetime);
		pSignalInitPIDHeater->SetDouble("integrationtime", dIntegrationtime);
		pSignalInitPIDHeater->SetDouble("gain", dGain);
		pSignalInitPIDHeater->SetDouble("filtertime", dFiltertime);
		pSignalInitPIDHeater->SetInteger("maxout", nMaxout);
		pSignalInitPIDHeater->SetInteger("minout", nMinout);
		pSignalInitPIDHeater->Trigger();

		if (pSignalInitTunerHeater->WaitForHandling(nHeaterInitTimeout) && pSignalInitPWMHeater->WaitForHandling(nHeaterInitTimeout) && pSignalInitPIDHeater->WaitForHandling(nHeaterInitTimeout)) {
			bool bTunerReadyHeater = pSignalInitTunerHeater->GetBoolResult("success");
			bool bPWMReadyHeater = pSignalInitPWMHeater->GetBoolResult("success");
			bool bPIDReadyHeater = pSignalInitPIDHeater->GetBoolResult("success");

			bool bHeaterControllerIsReady = bTunerReadyHeater && bPWMReadyHeater && bPIDReadyHeater;

			pStateEnvironment->SetBoolParameter("processinitialization", "heatercontroller_ready", bHeaterControllerIsReady);

			std::vector<std::string> readyControllersHeater;
			std::vector<std::string> notReadyControllersHeater;
			if (bTunerReadyHeater)
				readyControllersHeater.push_back("HeaterControllerTuner");
			else
				notReadyControllersHeater.push_back("HeaterControllerTuner");
			if (bPWMReadyHeater)
				readyControllersHeater.push_back("HeaterControllerPWM");
			else
				notReadyControllersHeater.push_back("HeaterControllerPWM");
			if (bPIDReadyHeater)
				readyControllersHeater.push_back("HeaterControllerPID");
			else
				notReadyControllersHeater.push_back("HeaterControllerPID");

			if (readyControllersHeater.size() > 0) {
				std::string sReadyControllersHeaterString;
				for (auto controllerString : readyControllersHeater) {
					if (!sReadyControllersHeaterString.empty())
						sReadyControllersHeaterString += ", ";
					sReadyControllersHeaterString += controllerString;
				}
				pStateEnvironment->LogMessage("Initializing of " + sReadyControllersHeaterString + " successfull");
			}
			if (notReadyControllersHeater.size() > 0) {
				std::string sNotReadyControllersHeaterString;
				for (auto controllerString : notReadyControllersHeater) {
					if (!sNotReadyControllersHeaterString.empty())
						sNotReadyControllersHeaterString += ", ";
					sNotReadyControllersHeaterString += controllerString;
				}
				pStateEnvironment->LogMessage("Initializing of " + sNotReadyControllersHeaterString + " failed");
			}
		}
		else {
			// No response from PLC!
			pStateEnvironment->LogMessage("No response from PLC");
			pStateEnvironment->SetBoolParameter("processinitialization", "heatercontroller_ready", false);
			pStateEnvironment->SetStringParameter("processinitialization", "initerror", "COULDNOTINITIALIZEHEATERCONTROLLER");
			pStateEnvironment->SetNextState("manualheatercontrol");
			return;
		}

		pStateEnvironment->SetNextState("manualheatercontrol");
		return;
	}
	else if (pStateEnvironment->WaitForSignal("signal_manual_controllertuning", 0, pSignalHandler)) {
			
		auto nController_ID = pSignalHandler->GetInteger("controller_ID");
		if (nController_ID == CONTROLLER_ID_HEATER)
		{

			//retrieve tuner parameters from the parameter group
			auto nStepheight = pStateEnvironment->GetIntegerParameter("heatercontroller", "stepheight");
			auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxactvalue");
			auto nMinactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "minactvalue");
			auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "systemsettlingtime");
			auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "maxtuningtime");


			// send signal to plc state machine to perform a auto tuning of the heater controller
			auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
			pSignal->SetInteger("stepheight", nStepheight);
			pSignal->SetInteger("maxactvalue", nMaxactvalue);
			pSignal->SetInteger("minactvalue", nMinactvalue);
			pSignal->SetDouble("systemsettlingtime", dSystemsettlingtime);
			pSignal->SetDouble("maxtuningtime", dMaxtuningtime);
			pSignal->Trigger();


			if (pSignal->WaitForHandling(1000))
			{
				pSignalHandler->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
			}

			pSignalHandler->SignalHandled();
			return;
		}
		pStateEnvironment->SetNextState("waitforcontrollertuning");
	}
	else if (pStateEnvironment->WaitForSignal("signal_manualheatercontrol_enter", 0, pSignalHandler))
	{
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualheatercontrol");
	}
	else if (pStateEnvironment->WaitForSignal("signal_manualheatercontrol_leave", 0, pSignalHandler))
	{	
		pSignalHandler->SetBoolResult("istuning", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
	else if (pStateEnvironment->WaitForSignal("signal_enableheater", 0, pSignalHandler))
	{
		
		pStateEnvironment->SetNextState("manualheatercontrol");
		// send signal to plc state machine to enable the heater control
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_enablecontroller");
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignal->Trigger();
		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();

	}
	else if (pStateEnvironment->WaitForSignal("signal_disableheater", 0, pSignalHandler))
	{

	pStateEnvironment->SetNextState("manualheatercontrol");
	// send signal to plc state machine to disable the heater control
	auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_disablecontroller");
	pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignal->Trigger();
	if (pSignal->WaitForHandling(1000))
	{
		pSignalHandler->SetBoolResult("success", true);
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
	}

	pSignalHandler->SignalHandled();

	}
	else if (pStateEnvironment->WaitForSignal("signal_updateheatersetpoint", 0, pSignalHandler))
	{

	pStateEnvironment->SetNextState("manualheatercontrol");

	//retrieve PID parameters from the parameter group
	auto nSetpoint = pStateEnvironment->GetIntegerParameter("heatercontroller", "setpoint");

	// send signal to plc state machine to update the heater setpoint
	auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollersetpoint");
	pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
	pSignal->SetInteger("setpoint", nSetpoint);
	pSignal->Trigger();
	if (pSignal->WaitForHandling(1000))
	{
		pSignalHandler->SetBoolResult("success", true);
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
	}

	pSignalHandler->SignalHandled();

	}
	else if (pStateEnvironment->WaitForSignal("signal_controllerparameters_save", 0, pSignalHandler))
	{
		auto nController_ID = pSignalHandler->GetInteger("controller_ID");
		if (nController_ID == CONTROLLER_ID_HEATER)
		{
			// retrieve values to save from signal
			auto dDerivativetime = pSignalHandler->GetDouble("derivativetime");
			auto dIntegrationtime = pSignalHandler->GetDouble("integrationtime");
			auto dGain = pSignalHandler->GetDouble("gain");
			auto dFiltertime = pSignalHandler->GetDouble("filtertime");
			auto nMaxout = pSignalHandler->GetInteger("maxout");
			auto nMinout = pSignalHandler->GetInteger("minout");
			auto nDutycycle = pSignalHandler->GetInteger("dutycycle");
			auto dPeriodTime = pSignalHandler->GetDouble("periodTime");
			auto nMaxFrequency = pSignalHandler->GetInteger("maxFrequency");
			auto bMode = pSignalHandler->GetBool("mode");
			auto nStepheight = pSignalHandler->GetInteger("stepheight");
			auto nMaxactvalue = pSignalHandler->GetInteger("maxactvalue");
			auto nMinactvalue = pSignalHandler->GetInteger("minactvalue");
			auto dSystemsettlingtime = pSignalHandler->GetDouble("systemsettlingtime");
			auto dMaxtuningtime = pSignalHandler->GetDouble("maxtuningtime");
			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();

			// store values in the parameter group
			pStateEnvironment->SetDoubleParameter("heatercontroller", "derivativetime", dDerivativetime);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "integrationtime", dIntegrationtime);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "gain", dGain);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "filtertime", dFiltertime);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "maxout", nMaxout);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "minout", nMinout);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "dutycycle", nDutycycle);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "periodTime", dPeriodTime);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "maxFrequency", nMaxFrequency);
			pStateEnvironment->SetBoolParameter("heatercontroller", "mode", bMode);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "stepheight", nStepheight);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "maxactvalue", nMaxactvalue);
			pStateEnvironment->SetIntegerParameter("heatercontroller", "minactvalue", nMinactvalue);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "systemsettlingtime", dSystemsettlingtime);
			pStateEnvironment->SetDoubleParameter("heatercontroller", "maxtuningtime", dMaxtuningtime);
			
		}
		pStateEnvironment->SetNextState("manualheatercontrol");
	}
	else if (pStateEnvironment->WaitForSignal("signal_heatercontrolsetpoint_save", 0, pSignalHandler))
	{
		// retrieve values to save from signal
		auto nSetpoint = pSignalHandler->GetInteger("setpoint");
		pSignalHandler->SetBoolResult("success", true);
		pSignalHandler->SignalHandled();

		// store values in the parameter group
		pStateEnvironment->SetIntegerParameter("heatercontroller", "setpoint", nSetpoint);

		pStateEnvironment->SetNextState("manualheatercontrol");
	}
	else if (pStateEnvironment->WaitForSignal("signal_updatePIDheater", 0, pSignalHandler))
	{

		//retrieve PID parameters from the parameter group
		auto dDerivativetime = pStateEnvironment->GetDoubleParameter("heatercontroller", "derivativetime");
		auto dIntegrationtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "integrationtime");
		auto dGain = pStateEnvironment->GetDoubleParameter("heatercontroller", "gain");
		auto dFiltertime = pStateEnvironment->GetDoubleParameter("heatercontroller", "filtertime");
		auto nMaxout = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxout");
		auto nMinout = pStateEnvironment->GetIntegerParameter("heatercontroller", "minout");
		
		// send signal to plc state machine to update the heater control PID parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPID");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignal->SetDouble("derivativetime", dDerivativetime);
		pSignal->SetDouble("integrationtime", dIntegrationtime);
		pSignal->SetDouble("gain", dGain);
		pSignal->SetDouble("filtertime", dFiltertime);
		pSignal->SetInteger("maxout", nMaxout);
		pSignal->SetInteger("minout", nMinout);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualheatercontrol");

	}
	else if (pStateEnvironment->WaitForSignal("signal_updatePWMheater", 0, pSignalHandler))
	{

		//retrieve PWM parameters from the parameter group
		auto nDutycycle = pStateEnvironment->GetIntegerParameter("heatercontroller", "dutycycle");
		auto dPeriodTime = pStateEnvironment->GetDoubleParameter("heatercontroller", "periodTime");
		auto nMaxFrequency = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxFrequency");
		auto bMode = pStateEnvironment->GetBoolParameter("heatercontroller", "mode");


		// send signal to plc state machine to update the heater control PWM parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_updatecontrollerPWM");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignal->SetInteger("dutycycle", nDutycycle);
		pSignal->SetDouble("periodTime", dPeriodTime);
		pSignal->SetInteger("maxFrequency", nMaxFrequency);
		pSignal->SetBool("mode", bMode);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualheatercontrol");

		}
	else if (pStateEnvironment->WaitForSignal("signal_updatetunerheater", 0, pSignalHandler))
	{

		//retrieve tuner parameters from the parameter group
		auto nStepheight = pStateEnvironment->GetIntegerParameter("heatercontroller", "stepheight");
		auto nMaxactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "maxactvalue");
		auto nMinactvalue = pStateEnvironment->GetIntegerParameter("heatercontroller", "minactvalue");
		auto dSystemsettlingtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "systemsettlingtime");
		auto dMaxtuningtime = pStateEnvironment->GetDoubleParameter("heatercontroller", "maxtuningtime");


		// send signal to plc state machine to update the heater control tuner parameters
		auto pSignal = pStateEnvironment->PrepareSignal("plc", "signal_controllertuning");
		pSignal->SetBool("isinit", CONTROLLER_UPDATE);
		pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
		pSignal->SetInteger("stepheight", nStepheight);
		pSignal->SetInteger("maxactvalue", nMaxactvalue);
		pSignal->SetInteger("minactvalue", nMinactvalue);
		pSignal->SetDouble("systemsettlingtime", dSystemsettlingtime);
		pSignal->SetDouble("maxtuningtime", dMaxtuningtime);
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000))
		{
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
		}

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("manualheatercontrol");

		}

	else
	{
		pStateEnvironment->SetNextState("manualheatercontrol"); 
	}
	
}

__DECLARESTATE(waitforcontrollertuning)
{
	LibMCEnv::PSignalHandler pSignalHandler;

	if (false) {
		//TODO: wait for tuning to be done or to reach the lifetime
		pStateEnvironment->SetNextState("manualheatercontrol");
		return;
	}
	else if (pStateEnvironment->WaitForSignal("signal_manualheatercontrol_leave", 0, pSignalHandler))
	{
		pSignalHandler->SetBoolResult("istuning", true);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("waitforcontrollertuning");
	}
	else if (pStateEnvironment->WaitForSignal("signal_manualatmospherecontrol_leave", 0, pSignalHandler))
	{
		pSignalHandler->SetBoolResult("istuning", true);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("waitforcontrollertuning");
	}
	else if (pStateEnvironment->WaitForSignal("signal_abort_controllertuning", 0, pSignalHandler))
	{
		auto nController_ID = pSignalHandler->GetInteger("controller_ID");
		if (nController_ID == CONTROLLER_ID_HEATER)
		{
			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			auto pSAbortTuningSignal = pStateEnvironment->PrepareSignal("plc", "signal_abortcontrollertuning");
			pSAbortTuningSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
			pSAbortTuningSignal->Trigger();
			pStateEnvironment->SetNextState("manualheatercontrol");
		}
		else if (nController_ID == CONTROLLER_ID_SHIELDINGGAS)
		{
			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			auto pSAbortTuningSignal = pStateEnvironment->PrepareSignal("plc", "signal_abortcontrollertuning");
			pSAbortTuningSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
			pSAbortTuningSignal->Trigger();
			pStateEnvironment->SetNextState("manualatmospherecontrol");
		}
	}
	pStateEnvironment->SetNextState("waitforcontrollertuning");
}


__DECLARESTATE(fatalerror) 
{
	pStateEnvironment->SetNextState("fatalerror");
}



__ENDSTATEDEFINITIONS