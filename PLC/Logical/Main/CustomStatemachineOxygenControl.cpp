/*++

Copyright (C) 2024 Institute for Machine Tools and Industrial Management
TUM School of Engineering and Design
Technical University of Munich

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Technical University of Munich nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL TECHNICAL UNIVERSITY OF MUNICH BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "Framework/Application.hpp"

#include "CustomConstants.hpp"
#include <cmath>

//include required hardware modules
#include "Modules/IOModule_X20AI4622.hpp"
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20SI8110.hpp"
#include "Modules/IOModule_X20DI6371.hpp"

namespace BuRCPP {
	
	class CStateOxygenControl_Wait_For_Init : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
						
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
						
			// check for PC signals
			auto pSignalUpdateControllerPidParameters = pEnvironment->checkSignal ("updatecontrollerparameters");
			auto pSignalUpdateControllerTunerParameters = pEnvironment->checkSignal ("updatecontrollertunerparameters");
			auto pSignalUpdateControllerPwmParameters = pEnvironment->checkSignal ("updatecontrollerpwmparameters");
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint");
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				// ensure the shielding gas valve is closed
				pDigitalOutputModule114KF25->setOutput(3, false);
					
				if(pSignalUpdateControllerPidParameters)
				{ // check if the signal is an update signal
					bool bIsInitPID = pSignalUpdateControllerPidParameters->getBoolParameter("isinit");
					pEnvironment->setNextState ("wait_for_init");
					if(bIsInitPID)
					{
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PID_ISINIT, true);
					
						//retrieve the PID update parameters 
						double dDerivativeTime = pSignalUpdateControllerPidParameters->getInt32Parameter("derivativetime")* 0.001;
						double dIntegrationTime = pSignalUpdateControllerPidParameters->getInt32Parameter("integrationtime")* 0.001;
						double dGain = pSignalUpdateControllerPidParameters->getInt32Parameter("gain")*0.001;
						double dFilterTime = pSignalUpdateControllerPidParameters->getInt32Parameter("filtertime")* 0.001;
						int nMaxOut = pSignalUpdateControllerPidParameters->getInt32Parameter("maxout");
						int nMinOut = pSignalUpdateControllerPidParameters->getInt32Parameter("minout");
				
			
						// store the PID parameters in journal variables
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_DERIVATIVETIMEINSECONDS,  dDerivativeTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_INTEGRATIONTIMEINSECONDS,  dIntegrationTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_GAIN,  dGain);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_FILTERTIMEINSECONDS,  dFilterTime);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_MAXOUTINPERCENT,  nMaxOut);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_MINOUTINPERCENT,  nMinOut);
					}
					// finish processing of the signals
					pSignalUpdateControllerPidParameters->finishProcessing ();
				}
				else if(pSignalUpdateControllerTunerParameters)
				{ // check if the signal is an update signal
					bool bIsInitTuner = pSignalUpdateControllerTunerParameters->getBoolParameter("isinit");
					pEnvironment->setNextState ("wait_for_init");
					if(bIsInitTuner)
					{	
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_ISINIT, true);

						//retrieve the PID tuner update parameters 
						int nStepHeight = pSignalUpdateControllerTunerParameters->getInt32Parameter("stepheight");
						int nMaxActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxactvalue");
						int nMinActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("minactvalue");
						double dSystemSettlingTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("systemsettlingtime")/1000.0;
						double dMaxTuningTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxtuningtime")/1000.0;
								
						// store the PID tuner parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT,  nStepHeight);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
	
					}
					// finish processing of the signals
					pSignalUpdateControllerTunerParameters->finishProcessing ();			
				}
				else if(pSignalUpdateControllerPwmParameters)
				{ // check if the signal is an update signal
					bool bIsInitPWM = pSignalUpdateControllerPwmParameters->getBoolParameter("isinit");
					pEnvironment->setNextState ("wait_for_init");
					if(bIsInitPWM)
					{
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_ISINIT, true);
			
						// retrieve the parameters to update the OxygenControl PWM function block
						int nDutyCycle = pSignalUpdateControllerPwmParameters->getInt32Parameter("dutycycle");
						double dPeriod = pSignalUpdateControllerPwmParameters->getInt32Parameter("period")/1000;
						int nMaxFrequency = pSignalUpdateControllerPwmParameters->getInt32Parameter("maxFrequency");
						bool bMode = pSignalUpdateControllerPwmParameters->getInt32Parameter("mode");
								
						// store the OxygenControl PWM function block parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_DUTYCYCLE,  nDutyCycle);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_PERIOD,  dPeriod);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MAXFREQUENCY,  nMaxFrequency);
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MODE,  bMode);
					}
					// finish processing of the signals
					pSignalUpdateControllerPwmParameters->finishProcessing ();
				}
				else if(pSignalUpdateControllerSetpoint)
				{ // check if the signal is an update signal
					bool bIsInitSetpoint = pSignalUpdateControllerSetpoint->getBoolParameter("isinit");
					pEnvironment->setNextState ("wait_for_init");
					if(bIsInitSetpoint)
					{	
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINT_ISINIT, true);
			
						// retrieve the parameter to update the oxygen content setpoint
						int nSetvalue = pSignalUpdateControllerSetpoint->getInt32Parameter("setvalue");
								
						// store the oxygen content setpoint in journal variable
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINTINPPM, nSetvalue);
					}
					// finish processing of the signals
					pSignalUpdateControllerSetpoint->finishProcessing ();
				}
				
				else 
				{ // check if all parameters were inizialized
					bool bIsInitPID = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PID_ISINIT);
					bool bIsInitTuner = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_ISINIT);
					bool bIsInitPWM = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_ISINIT);
					bool bIsInitSetpoint = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINT_ISINIT);
					
					if (bIsInitPWM && bIsInitTuner && bIsInitPID && bIsInitSetpoint){
						pEnvironment->setNextState ("init");
						// reset the init flags
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PID_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINT_ISINIT, false);
					}else
					{ // wait for the init parameter signal from the PC
						pEnvironment->setNextState ("wait_for_init");
					}
					
				}
			}
			else
			{ // if there is an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block 
		}
	
	};
	
	class CStateOxygenControl_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
						
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				// ensure the shielding gas valve is closed
				pDigitalOutputModule114KF25->setOutput(3, false);
				
				//enable the oxygen controller function blocks to be able to update the parameters
				fbOxygenControlPID.Enable = 1;
				fbOxygenControlPWM.Enable = 1;
				fbOxygenControlTuner.Enable = 1;
				
				//retrieve the PID init parameters 
				double dDerivativeTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_DERIVATIVETIMEINSECONDS);
				double dIntegrationTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_INTEGRATIONTIMEINSECONDS);
				double dGain = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_GAIN);
				double dFilterTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_FILTERTIMEINSECONDS);
				int nMaxOut = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_MAXOUTINPERCENT);
				int nMinOut = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_MINOUTINPERCENT);
				//retrieve the setpoint init parameter
				int nSetValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_SETPOINTINPPM);
										
				// initialize the OxygenControl PID function block
				// controller output scaled between 0% and 100%, controller input is in (25000ppm - currentOxygenppm) -> 250000 = 0
				// the contorller setpoint is initialized with 
				fbOxygenControlPID.PIDParameters.DerivativeTime = dDerivativeTime;
				fbOxygenControlPID.PIDParameters.IntegrationTime = dIntegrationTime;
				fbOxygenControlPID.PIDParameters.Gain = dGain;
				fbOxygenControlPID.PIDParameters.FilterTime = dFilterTime;
				fbOxygenControlPID.MaxOut = nMaxOut;
				fbOxygenControlPID.MinOut = nMinOut;
				fbOxygenControlPID.SetValue = (O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT*FACTOR_PERCENT_TO_PPM) - nSetValue;
				fbOxygenControlPID.Update = true;
					
				//retrieve the PID tuner init parameters 
				int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT);
				int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT);
				int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT);
				double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS);
				double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS);
				
				// initialize the OxygenControl PID tuner function block
				// height of the step to be applied during training,Out = startValue+StepHeight 
				fbOxygenControlTuner.StepHeight = nStepHeight;
				// range of the measured process variable during training, scaled to be in %
				fbOxygenControlTuner.MaxActValue = nMaxActValue;
				fbOxygenControlTuner.MinActValue = nMinActValue;
				// time for the system to settle at the start setpoint before the step for tuning is applied in s
				fbOxygenControlTuner.SystemSettlingTime = dSystemSettlingTime;
				// maximum time for the tuning including the settling time in s
				fbOxygenControlTuner.MaxTuningTime = dMaxTuningTime;
				fbOxygenControlTuner.Update = true;
				
				// initialize the oxygen controller enabled flag
				pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED,  false);
											
				// retrieve the parameters to initialize the OxygenControl PWM function block
				int nDutyCycle = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_PWM_DUTYCYCLE);
				double dPeriod = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_PERIOD);
				int nMaxFrequency = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_PWM_MAXFREQUENCY);
				bool bMode = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MODE);
			
					
				// PWM DutyCycle
				fbOxygenControlPWM.DutyCycle = nDutyCycle;
				// min time of a single pulse, on or off, 1/maxFrequency = 1/5 Hz
				fbOxygenControlPWM.MinPulseWidth = 1/nMaxFrequency;
				// mode = pulse in the middle (1) of the period time of in the beginning (0)
				if(bMode)
				{
					fbOxygenControlPWM.Mode = mtBASICS_PULSE_BEGINNING;
				}
				else
				{
					fbOxygenControlPWM.Mode = mtBASICS_PULSE_MIDDLE;
				}
				// period time of the PWM
				fbOxygenControlPWM.Period = dPeriod; 
				//currently, default values are used
				fbOxygenControlPWM.Update = true;		
				
				pEnvironment->setNextState ("wait_for_parameter_update");
		
			}
			else
			{ // if there is an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}	
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	};
	
	
	class CStateOxygenControl_IdleDisabled : public CState {
		public:

		std::string getName () 
		{
			return "idle_disabled";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Door safety switch, Modul: 115KF51; SDI Channel 3, door switch first channel;, SDI Channel 4, door switch second channel
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			// circulation valves status, Modul: 113KF17; Channel 1: chamber valve open; Channel 2: chamber valve closed; Channel 3: heat exchanger valve open; Channel 4: heat exchanger valve closed
			// vacuum valves status, Modul: 113KF21; Channel 1: chamber valve open; Channel 2: chamber valve closed; Channel 3: z-axis valve open; Channel 4: z-axis valve closed
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20SI8110> pSafetyDigitalInputModule115KF51 (pEnvironment, "115KF51");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule113KF17(pEnvironment, "113KF17");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule113KF21(pEnvironment, "113KF21");
			
			// check for signals
			auto pSignalEnableController = pEnvironment->checkSignal ("enablecontroller"); //signal to enable the controller
			auto pSignalUpdateControllerPidParameters = pEnvironment->checkSignal ("updatecontrollerparameters"); //signal to update the PID parameters
			auto pSignalUpdateControllerTunerParameters = pEnvironment->checkSignal ("updatecontrollertunerparameters"); //signal to update the parameters of the tuner
			auto pSignalUpdateControllerPwmParameters = pEnvironment->checkSignal ("updatecontrollerpwmparameters"); //signal to update the PWM parameters
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint"); //signal to update the setpoint
			auto pSignalAutoTuneController = pEnvironment->checkSignal ("autotunecontroller"); //signal to update the setpoint
			auto pSignalToggleValves = pEnvironment->checkSignal ("togglevalves");
			
			fbOxygenControlPID.Enable = 0;
			fbOxygenControlPWM.Enable = 0;
			fbOxygenControlTuner.Enable = 0;
			
			
			if (pSignalToggleValves) // toggle gas flow valves
			{
				bool toggle_shielding_gas = pSignalToggleValves->getBoolParameter("toggle_shielding_gas_valve");
				
				pDigitalOutputModule114KF25->setOutput(3, toggle_shielding_gas);
				pSignalToggleValves->finishProcessing ();
			}
			
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{	
				if(pSignalUpdateControllerPidParameters)
				{ // check if the signal is an update signal
					bool bIsInitPID = pSignalUpdateControllerPidParameters->getBoolParameter("isinit");
					
					pEnvironment->setNextState ("idle_disabled");
					
					if(!bIsInitPID)
					{
						//retrieve the PID update parameters 
						double dDerivativeTime = pSignalUpdateControllerPidParameters->getInt32Parameter("derivativetime")* 0.001;
						double dIntegrationTime = pSignalUpdateControllerPidParameters->getInt32Parameter("integrationtime")* 0.001;
						double dGain = pSignalUpdateControllerPidParameters->getInt32Parameter("gain")*0.001;
						double dFilterTime = pSignalUpdateControllerPidParameters->getInt32Parameter("filtertime")* 0.001;
						int nMaxOut = pSignalUpdateControllerPidParameters->getInt32Parameter("maxout");
						int nMinOut = pSignalUpdateControllerPidParameters->getInt32Parameter("minout");
					
					
						// store the PID parameters in journal variables
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_DERIVATIVETIMEINSECONDS,  dDerivativeTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_INTEGRATIONTIMEINSECONDS,  dIntegrationTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_GAIN,  dGain);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_FILTERTIMEINSECONDS,  dFilterTime);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_MAXOUTINPERCENT,  nMaxOut);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_MINOUTINPERCENT,  nMinOut);
			
						
						// finish processing of the signals
						pSignalUpdateControllerPidParameters->finishProcessing ();
						
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
				}
				else if(pSignalUpdateControllerTunerParameters)
				{ // check if the signal is an update signal
					bool bIsInitTuner = pSignalUpdateControllerTunerParameters->getBoolParameter("isinit");
					
					pEnvironment->setNextState ("idle_disabled");
					
					if(!bIsInitTuner)
					{				
						//retrieve the PID tuner update parameters 
						int nStepHeight = pSignalUpdateControllerTunerParameters->getInt32Parameter("stepheight");
						int nMaxActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxactvalue");
						int nMinActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("minactvalue");
						double dSystemSettlingTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("systemsettlingtime")/1000;
						double dMaxTuningTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxtuningtime")/1000;
										
						// store the PID tuner parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT,  nStepHeight);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
						
						// finish processing of the signals
						pSignalUpdateControllerTunerParameters->finishProcessing ();
						
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
					
				}
				else if(pSignalUpdateControllerPwmParameters)
				{ // check if the signal is an update signal
					bool bIsInitPWM = pSignalUpdateControllerPwmParameters->getBoolParameter("isinit");
					
					pEnvironment->setNextState ("idle_disabled");
					
					if(!bIsInitPWM)
					{
						// retrieve the parameters to update the OxygenControl PWM function block
						int nDutyCycle = pSignalUpdateControllerPwmParameters->getInt32Parameter("dutycycle");
						double dPeriod = pSignalUpdateControllerPwmParameters->getInt32Parameter("period")/1000;
						int nMaxFrequency = pSignalUpdateControllerPwmParameters->getInt32Parameter("maxFrequency");
						bool bMode = pSignalUpdateControllerPwmParameters->getInt32Parameter("mode");
										
						// store the OxygenControl PWM function block parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_DUTYCYCLE,  nDutyCycle);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_PERIOD,  dPeriod);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MAXFREQUENCY,  nMaxFrequency);
						pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MODE,  bMode);
					
						// finish processing of the signals
						pSignalUpdateControllerPwmParameters->finishProcessing ();
					
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
												
				}
				else if(pSignalUpdateControllerSetpoint)
				{ // check if the signal is an update signal
					bool bIsInitSetpoint = pSignalUpdateControllerSetpoint->getBoolParameter("isinit");
					
					pEnvironment->setNextState ("idle_disabled");
					
					if(!bIsInitSetpoint)
					{
						//signal from PC to update the setpoint 
						//retrieve new setpoint from signal
						double nSetValue = pSignalUpdateControllerSetpoint->getInt32Parameter("setvalue");
						//store setpoint in the journal variable
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINTINPPM,  nSetValue);
						//set new setpoint
						fbOxygenControlPID.SetValue = (O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT*FACTOR_PERCENT_TO_PPM) - nSetValue;
						// finish processing of the signal
						pSignalUpdateControllerSetpoint->finishProcessing ();
					}
				}
				else if(pSignalAutoTuneController)
				{ // signal from PC to perform a parameter tuning
					
					//retrieve the PID tuner update parameters 
					int nStepHeight = pSignalAutoTuneController->getInt32Parameter("stepheight");
					int nMaxActValue = pSignalAutoTuneController->getInt32Parameter("maxactvalue");
					int nMinActValue = pSignalAutoTuneController->getInt32Parameter("minactvalue");
					double dSystemSettlingTime = pSignalAutoTuneController->getInt32Parameter("systemsettlingtime")/1000;
					double dMaxTuningTime = pSignalAutoTuneController->getInt32Parameter("maxtuningtime")/1000;
										
					// store the PID tuner parameters in journal variables
					pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT,  nStepHeight);
					pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
					pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
					
					//check if the chamber door is closed and if the status of the valves are correct, circulation valves must be open, vaccuum valves must be closed
					if(pSafetyDigitalInputModule115KF51->getInput(3) && pSafetyDigitalInputModule115KF51->getInput(4) && pDigitalInputModule113KF17->getInput(1)==1 && pDigitalInputModule113KF17->getInput(3)==1 && pDigitalInputModule113KF21->getInput(2)==1 && pDigitalInputModule113KF21->getInput(4)==1)
					{
						// go to tune_control_parameters state
						pEnvironment->setNextState ("tune_control_parameters");
						// finish processing of the signals
						pSignalAutoTuneController->setBoolResult("success", true);
						pSignalAutoTuneController->finishProcessing ();
					}
					else
					{
						// stay in idle_disabled state
						pEnvironment->setNextState ("idle_disabled");
						// finish processing of the signals
						pSignalAutoTuneController->setBoolResult("success", false);
						pSignalAutoTuneController->finishProcessing ();
					}
				}
				else if(pSignalEnableController)
				{ 					
					//check if the chamber door is closed and if the status of the valves are correct, circulation valves must be open, vaccuum valves must be closed
					if(pSafetyDigitalInputModule115KF51->getInput(3) && pSafetyDigitalInputModule115KF51->getInput(4) && pDigitalInputModule113KF17->getInput(1)==1 && pDigitalInputModule113KF17->getInput(3)==1 && pDigitalInputModule113KF21->getInput(2)==1 && pDigitalInputModule113KF21->getInput(4)==1)
					{
						// enable the controller
						fbOxygenControlPID.Enable = 1;
						fbOxygenControlPWM.Enable = 1;
						fbOxygenControlTuner.Enable = 0;
						// go to oxygen_control_enabled state
						pEnvironment->setNextState ("oxygen_control_enabled");
						// finish processing of the signals
						pSignalEnableController->setBoolResult("success", true);
						pSignalEnableController->finishProcessing ();
					}
					else
					{
						// disable the controller
						fbOxygenControlPID.Enable = 0;
						fbOxygenControlPWM.Enable = 0;
						fbOxygenControlTuner.Enable = 0;
						// stay in idle_disabled state
						pEnvironment->setNextState ("idle_disabled");
						// finish processing of the signals
						pSignalEnableController->setBoolResult("success", false);
						pSignalEnableController->finishProcessing ();
					}
					
				}
				else
				{
					pEnvironment->setNextState ("idle_disabled");
				}
				
			}
			else
			{ // if there is an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};
	
	class CStateOxygenControl_Update_Parameters : public CState {
		public:

		std::string getName () 
		{
			return "update_parameters";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			
			fbOxygenControlTuner.Enable = 1;
			fbOxygenControlPWM.Enable = 1;
			fbOxygenControlTuner.Enable = 1;
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				//retrieve the PID init parameters 
				double dDerivativeTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_DERIVATIVETIMEINSECONDS);
				double dIntegrationTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_INTEGRATIONTIMEINSECONDS);
				double dGain = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_GAIN);
				double dFilterTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_FILTERTIMEINSECONDS);
				int nMaxOut = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_MAXOUTINPERCENT);
				int nMinOut = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_MINOUTINPERCENT);
				
										
				// initialize the OxygenControl PID function block
				// controller output scaled between 0% and 100%, controller input will be scaled to %, too
				fbOxygenControlPID.PIDParameters.DerivativeTime = dDerivativeTime;
				fbOxygenControlPID.PIDParameters.IntegrationTime = dIntegrationTime;
				fbOxygenControlPID.PIDParameters.Gain = dGain;
				fbOxygenControlPID.PIDParameters.FilterTime = dFilterTime;
				fbOxygenControlPID.MaxOut = nMaxOut;
				fbOxygenControlPID.MinOut = nMinOut;
				fbOxygenControlPID.Update = true;
					
				//retrieve the PID tuner init parameters 
				int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT);
				int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT);
				int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT);
				double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS);
				double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS);
				
				// initialize the OxygenControl PID tuner function block
				// height of the step to be applied during training,Out = startValue+StepHeight 
				fbOxygenControlTuner.StepHeight = nStepHeight;
				// range of the measured process variable during training, scaled to be in %
				fbOxygenControlTuner.MaxActValue = nMaxActValue;
				fbOxygenControlTuner.MinActValue = nMinActValue;
				// time for the system to settle at the start setpoint before the step for tuning is applied in s
				fbOxygenControlTuner.SystemSettlingTime = dSystemSettlingTime;
				// maximum time for the tuning including the settling time in s
				fbOxygenControlTuner.MaxTuningTime = dMaxTuningTime;
				fbOxygenControlTuner.Update = true;
											
				// retrieve the parameters to initialize the OxygenControl PWM function block
				int nDutyCycle = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_PWM_DUTYCYCLE);
				double dPeriod = pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_PERIOD);
				int nMaxFrequency = pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_PWM_MAXFREQUENCY);
				bool bMode = pEnvironment->getBoolValue(JOURNALVARIABLE_OXYGENCONTROL_PWM_MODE);
			
					
				// PWM DutyCycle
				fbOxygenControlPWM.DutyCycle = nDutyCycle;
				// min time of a single pulse, on or off, 1/maxFrequency = 1/5 Hz
				fbOxygenControlPWM.MinPulseWidth = 1/nMaxFrequency;
				// mode = pulse in the middle (1) of the period time of in the beginning (0)
				if(bMode)
				{
					fbOxygenControlPWM.Mode = mtBASICS_PULSE_BEGINNING;
				}
				else
				{
					fbOxygenControlPWM.Mode = mtBASICS_PULSE_MIDDLE;
				}
				// period time of the PWM
				fbOxygenControlPWM.Period = dPeriod; 
				//currently, default values are used
				fbOxygenControlPWM.Update = true;		
				
				pEnvironment->setNextState ("wait_for_parameter_update");
			}
			else
			{ // if there is an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};
	
	class CStateOxygenControl_Wait_For_Parameter_Update : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_parameter_update";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
		
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				//check if the parameter update of all three control function blocks is done
				if(fbOxygenControlPID.UpdateDone == 1 && fbOxygenControlPWM.UpdateDone == 1 && fbOxygenControlTuner.UpdateDone == 1)
				{	//reset the update flag and change to idle state
					fbOxygenControlPID.Update = 0;
					fbOxygenControlPWM.Update = 0;
					fbOxygenControlTuner.Update = 0;
					fbOxygenControlPID.Enable = false;
					fbOxygenControlTuner.Enable = false;
					fbOxygenControlPWM.Enable = false;
					pEnvironment->setNextState ("idle_disabled");
				}
				else
				{	//if the update is not yet done, remain in the wait_for_parameter_update state
					pEnvironment->setNextState ("wait_for_parameter_update");
				}
			}
			else
			{ // if there is an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};


	class CStateOxygenControl_oxygen_control_enabled : public CState {
		public:

		std::string getName () 
		{
			return "oxygen_control_enabled";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
			
			//check for signals
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint"); //signal to update the setpoint
			auto pSignalDisableBuildPlateTempControl = pEnvironment->checkSignal ("disablecontroller"); //signal to disable the controller
			
				
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{					
				if(pSignalDisableBuildPlateTempControl) 
				{// disable control signal from the PC
					fbOxygenControlPID.Enable = 0;
					pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED,  false); // set the oxygen controller enabled flag
					pEnvironment->setNextState ("idle_disabled");
				}
				else if(pSignalUpdateControllerSetpoint)
				{ // check if the signal is an update signal
					bool bIsInitSetpoint = pSignalUpdateControllerSetpoint->getBoolParameter("isinit");
					
					if(!bIsInitSetpoint)
					{
						//signal from PC to update the setpoint 
						//retrieve new setpoint from signal
						double nSetValue = pSignalUpdateControllerSetpoint->getInt32Parameter("setvalue");
						//store setpoint in the journal variable
						pEnvironment->setIntegerValue(JOURNALVARIABLE_OXYGENCONTROL_SETPOINTINPPM, nSetValue);
						//set new setpoint
						fbOxygenControlPID.SetValue = (O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT*FACTOR_PERCENT_TO_PPM) - nSetValue;
					}
					// finish processing of the signal
					pSignalUpdateControllerSetpoint->finishProcessing ();
					pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED,  true); // set the oxygen controller enabled flag
					pEnvironment->setNextState ("oxygen_control_enabled");
				}
				else
				{	
					//get and convert oxygen sensor values
					double o2inppm_chamber = 0;
					if (pDigitalOutputModule114KF24->getOutput(6))
					{
						o2inppm_chamber = (pAnalogInputModule112KF14->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_FINE_UPPER_INPPM-O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM)/0.016)+O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM;
					}else{
						o2inppm_chamber = ((pAnalogInputModule112KF14->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT-O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT)/0.016)+O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT)*FACTOR_PERCENT_TO_PPM;
					}
					double o2inppm_filter = ((pAnalogInputModule112KF14->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT)*FACTOR_PERCENT_TO_PPM;
			
					fbOxygenControlPID.ActValue = (O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT*FACTOR_PERCENT_TO_PPM) - o2inppm_chamber; // (250000 ppm - o2chamber)
					fbOxygenControlPWM.DutyCycle = fbOxygenControlPID.Out; // transform PID control output to a PID signal
					pDigitalOutputModule114KF25->setOutput(3, fbOxygenControlPWM.Out); // set the OxygenControl output according to the PID signal
					pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED,  true); // set the oxygen controller enabled flag
					pEnvironment->setNextState ("oxygen_control_enabled");
				}
					
			}
			else
			{ // if an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setBoolValue(JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED,  false); // set the oxygen controller enabled flag
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block		
		}
	
	};
	
	class CStateOxygenControl_Tune_Control_Parameters : public CState {
		public:

		std::string getName () 
		{
			return "tune_control_parameters";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				fbOxygenControlPID.Enable = true;
				fbOxygenControlPWM.Enable = true;
				fbOxygenControlTuner.Enable = true;
				if(fbOxygenControlTuner.Update == false)
				{	
					//retrieve the PID tuner init parameters 
					int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT);
					int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT);
					int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT);
					double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS);
					double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS);
				
					// initialize the OxygenControl PID tuner function block
					// height of the step to be applied during training,Out = startValue+StepHeight 
					fbOxygenControlTuner.StepHeight = nStepHeight;
					// range of the measured process variable during training, scaled to be in %
					fbOxygenControlTuner.MaxActValue = nMaxActValue;
					fbOxygenControlTuner.MinActValue = nMinActValue;
					// time for the system to settle at the start setpoint before the step for tuning is applied in s
					fbOxygenControlTuner.SystemSettlingTime = dSystemSettlingTime;
					// maximum time for the tuning including the settling time in s
					fbOxygenControlTuner.MaxTuningTime = dMaxTuningTime;
					
					fbOxygenControlTuner.Update = true;
					fbOxygenControlTuner.Start = false;
					pEnvironment->setNextState ("tune_control_parameters");
				} 
				else if(fbOxygenControlTuner.UpdateDone)
				{	
					fbOxygenControlTuner.Update = false;
					fbOxygenControlTuner.Start = true;
					pEnvironment->setNextState ("wait_for_tuning");
				}	
			}
			else
			{ // if an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};
	
	class CStateOxygenControl_Wait_For_Tuning : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_tuning";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
			
			//check for signals
			auto pSignalAbortAutoTuningController = pEnvironment->checkSignal ("abortautotuningcontroller"); //signal to abort the auto tuning
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				if(fbOxygenControlTuner.TuningDone)
				{
					fbOxygenControlTuner.Start = 0;
					fbOxygenControlPID.PIDParameters = fbOxygenControlTuner.PIDParameters;
					fbOxygenControlPID.Enable = 1;
					fbOxygenControlPWM.Enable = 1;
					fbOxygenControlTuner.Enable = 1;
					fbOxygenControlPID.Update = true;
					fbOxygenControlPWM.Update = true;
					fbOxygenControlTuner.Update = true;
					pEnvironment->setNextState("wait_for_parameter_update");
				}
				else if (pSignalAbortAutoTuningController)
				{
					fbOxygenControlTuner.Start = 0;
					fbOxygenControlPID.Enable = 0;
					fbOxygenControlPWM.Enable = 0;
					fbOxygenControlTuner.Enable = 0;
					pEnvironment->setNextState("idle_disabled");
				}
				else
				{
					pEnvironment->setNextState("wait_for_tuning");
					
					//get and convert oxygen sensor values
					double o2inppm_chamber = 0;
					if (pDigitalOutputModule114KF24->getOutput(6))
					{
						o2inppm_chamber = (pAnalogInputModule112KF14->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_FINE_UPPER_INPPM-O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM)/0.016)+O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM;
					}else{
						o2inppm_chamber = ((pAnalogInputModule112KF14->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT-O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT)/0.016)+O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT)*FACTOR_PERCENT_TO_PPM;
					}
					double o2inppm_filter = ((pAnalogInputModule112KF14->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT)*FACTOR_PERCENT_TO_PPM;
			
					fbOxygenControlTuner.ActValue = (int) (round(((O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT*FACTOR_PERCENT_TO_PPM) - o2inppm_chamber)/1000)*1000); // (250000 ppm - o2chamber)
					fbOxygenControlPWM.DutyCycle = fbOxygenControlTuner.Out; // transform PID control output to a PID signal
					pDigitalOutputModule114KF25->setOutput(3, fbOxygenControlPWM.Out); // set the OxygenControl output according to the PID signal
				}
				
			}
			else
			{ // if an error occured, diable the OxygenControl control function bocks and switch to the error state
				fbOxygenControlPID.Enable = 0;
				fbOxygenControlPWM.Enable = 0;
				fbOxygenControlTuner.Enable = 0;
				fbOxygenControlTuner.Start = false;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};

	class CStateOxygenControl_Error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Oxygen sensor chamber, Modul: 112KF14; AI Channel: 2; Value range: (0-25% or 0-1000ppm / 4 … 20mA)
			// Oxygen sensor filter, Modul: 112KF14; AI Channel: 1; Value range: (0-25% / 4 … 20mA)
			// measuring range chamber o2 sensor switch, Modul: 114KF24; DO Channel: 6; 0 = 0-25%, 1 = 0-1000ppm
			// Shielding gas valve, Modul: 114KF25; DO Channel 3: shielding gas valve open/close
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule112KF14(pEnvironment, "112KF14");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF24(pEnvironment, "114KF24");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25(pEnvironment, "114KF25");
			
			// ensure the shielding gas valve is closed
			pDigitalOutputModule114KF25->setOutput(3, false);
			// disable the oxygen control function blocks 
			fbOxygenControlPID.Enable = 0;
			fbOxygenControlPWM.Enable = 0;
			fbOxygenControlTuner.Enable = 0;
			
			
			// check if the control function blocks and the analog input modul channels of the oxygen sensors are ok
			if(fbOxygenControlPID.Error == 0 && fbOxygenControlPWM.Error == 0 && fbOxygenControlTuner.Error == 0 &&  pAnalogInputModule112KF14->getIOStatus(1) == 0  &&  pAnalogInputModule112KF14->getIOStatus(2) == 0)
			{
				pEnvironment->setNextState("init");
			}
			else
			{
				pEnvironment->setNextState("error");
			}
			MTBasicsStepTuning(&fbOxygenControlTuner); // call tuning function block 
			MTBasicsPID(&fbOxygenControlPID); // call PID function block 
			MTBasicsPWM(&fbOxygenControlPWM); // call PWM function block
		}
	
	};
	
		
	
	class CStateHandlerOxygenControl : public CStateHandler {
		public:

		CStateHandlerOxygenControl (CApplication* pApplication)
			: CStateHandler (pApplication->getJournal (), "oxygen", pApplication->getModuleHandler (), JOURNALGROUP_OxygenControl)
		{
			// register all states of this state machine here
			addState (std::make_shared<CStateOxygenControl_Wait_For_Init> ());
			addState (std::make_shared<CStateOxygenControl_Init> ());
			addState (std::make_shared<CStateOxygenControl_IdleDisabled> ());
			addState (std::make_shared<CStateOxygenControl_Update_Parameters> ());
			addState (std::make_shared<CStateOxygenControl_Wait_For_Parameter_Update> ());
			addState (std::make_shared<CStateOxygenControl_oxygen_control_enabled> ());
			addState (std::make_shared<CStateOxygenControl_Tune_Control_Parameters> ());
			addState (std::make_shared<CStateOxygenControl_Wait_For_Tuning> ());
			addState (std::make_shared<CStateOxygenControl_Error> ());
			
			// register journal variables
			registerDoubleValue("oxygencontrol_PID_derivativetime", JOURNALVARIABLE_OXYGENCONTROL_DERIVATIVETIMEINSECONDS, 0.0, 1000.0, 40000000);
			registerDoubleValue("oxygencontrol_PID_integrationtime", JOURNALVARIABLE_OXYGENCONTROL_INTEGRATIONTIMEINSECONDS, 0.0, 1000.0, 40000000);
			registerDoubleValue("oxygencontrol_PID_gain", JOURNALVARIABLE_OXYGENCONTROL_GAIN, -1000.0, 1000.0, 20000000);
			registerDoubleValue("oxygencontrol_PID_filtertime", JOURNALVARIABLE_OXYGENCONTROL_FILTERTIMEINSECONDS, 0.0, 1000.0, 20000000);
			registerIntegerValue("oxygencontrol_PID_maxout", JOURNALVARIABLE_OXYGENCONTROL_MINOUTINPERCENT, 0, 100);
			registerIntegerValue("oxygencontrol_PID_minout", JOURNALVARIABLE_OXYGENCONTROL_MAXOUTINPERCENT, 0, 100);
			registerIntegerValue("oxygencontrol_PID_setvalue", JOURNALVARIABLE_OXYGENCONTROL_SETPOINTINPPM, 0, 250000);
			registerBoolValue("oxygencontrol_PID_isenabled", JOURNALVARIABLE_OXYGENCONTROL_CONTROLLER_ENABLED);
			registerIntegerValue("oxygencontrol_tuner_stepheight", JOURNALVARIABLE_OXYGENCONTROL_TUNE_STEPHEIGHTINPERCENT, 0, 100);
			registerIntegerValue("oxygencontrol_tuner_maxactvalue", JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXACTVALUEINPERCENT, 0, 100);
			registerIntegerValue("oxygencontrol_tuner_minactvalue", JOURNALVARIABLE_OXYGENCONTROL_TUNE_MINACTVALUEINPERCENT, 0, 100);
			registerDoubleValue("oxygencontrol_tuner_systemsettlingtime", JOURNALVARIABLE_OXYGENCONTROL_TUNE_SETTLINGTIMEINSECONDS, 0.0, 3600.0, 3600000);
			registerDoubleValue("oxygencontrol_tuner_maxtuningtime", JOURNALVARIABLE_OXYGENCONTROL_TUNE_MAXTUNINGTIMEINSECONDS, 0.0, 3600.0, 3600000);
			registerIntegerValue("oxygencontrol_PWM_dutycycle", JOURNALVARIABLE_OXYGENCONTROL_PWM_DUTYCYCLE, 0, 100);
			registerDoubleValue("oxygencontrol_PWM_period", JOURNALVARIABLE_OXYGENCONTROL_PWM_PERIOD, 0.0, 1000, 1000000);
			registerIntegerValue("oxygencontrol_PWM_maxFrequency", JOURNALVARIABLE_OXYGENCONTROL_PWM_MAXFREQUENCY, 0, 1000);
			registerBoolValue("oxygencontrol_PWM_mode", JOURNALVARIABLE_OXYGENCONTROL_PWM_MODE);
			registerBoolValue("oxygencontrol_PID_isinit", JOURNALVARIABLE_OXYGENCONTROL_PID_ISINIT);
			registerBoolValue("oxygencontrol_PWM_isinit", JOURNALVARIABLE_OXYGENCONTROL_PWM_ISINIT);
			registerBoolValue("oxygencontrol_tuner_isinit", JOURNALVARIABLE_OXYGENCONTROL_TUNE_ISINIT);
			registerBoolValue("oxygencontrol_setpoint_isinit", JOURNALVARIABLE_OXYGENCONTROL_SETPOINT_ISINIT);

			// register all signals here
			auto pSignalEnableController = registerSignal ("enablecontroller", 4, 1000);
			pSignalEnableController->addBoolResult ("success", false);
			
			auto pSignalUpdateControllerPidParameters = registerSignal ("updatecontrollerparameters", 4,3000);
			pSignalUpdateControllerPidParameters->addBoolParameter ("isinit", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("derivativetime", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("integrationtime", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("gain", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("filtertime", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("maxout", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("minout", 0);
			pSignalUpdateControllerPidParameters->addInt32Parameter ("setvalue", 0);
			pSignalUpdateControllerPidParameters->addBoolResult ("success", false);
			
			auto pSignalUpdateControllerTunerParameters = registerSignal ("updatecontrollertunerparameters", 4, 3000);
			pSignalUpdateControllerTunerParameters->addBoolParameter ("isinit", 0);
			pSignalUpdateControllerTunerParameters->addInt32Parameter ("stepheight", 0);
			pSignalUpdateControllerTunerParameters->addInt32Parameter ("maxactvalue", 0);
			pSignalUpdateControllerTunerParameters->addInt32Parameter ("minactvalue", 0);
			pSignalUpdateControllerTunerParameters->addInt32Parameter ("systemsettlingtime", 0);
			pSignalUpdateControllerTunerParameters->addInt32Parameter ("maxtuningtime", 0);
			pSignalUpdateControllerTunerParameters->addBoolResult ("success", false);
			

			auto pSignalUpdateControllerPwmParameters = registerSignal ("updatecontrollerpwmparameters", 4, 3000);
			pSignalUpdateControllerPwmParameters->addBoolParameter ("isinit", 0);
			pSignalUpdateControllerPwmParameters->addInt32Parameter ("dutycycle", 0);
			pSignalUpdateControllerPwmParameters->addInt32Parameter ("period", 0);
			pSignalUpdateControllerPwmParameters->addInt32Parameter ("maxFrequency", 0);
			pSignalUpdateControllerPwmParameters->addBoolParameter ("mode", 0);
			pSignalUpdateControllerPwmParameters->addBoolResult ("success", false);
				
			auto pSignalUpdateControllerSetpoint = registerSignal ("updatecontrollersetpoint", 4, 1000);
			pSignalUpdateControllerSetpoint->addBoolParameter ("isinit", 0);
			pSignalUpdateControllerSetpoint->addInt32Parameter ("setvalue", 0);
			pSignalUpdateControllerSetpoint->addBoolResult ("success", false);
			
				
			auto pSignalAutoTuneController = registerSignal ("autotunecontroller", 4, 1000);
			pSignalAutoTuneController->addInt32Parameter ("stepheight", 0);
			pSignalAutoTuneController->addInt32Parameter ("maxactvalue", 0);
			pSignalAutoTuneController->addInt32Parameter ("minactvalue", 0);
			pSignalAutoTuneController->addInt32Parameter ("systemsettlingtime", 0);
			pSignalAutoTuneController->addInt32Parameter ("maxtuningtime", 0);
			pSignalAutoTuneController->addBoolResult ("success", false);
			
			auto pSignalAbortAutoTuningController = registerSignal ("abortautotuningcontroller", 4, 1000);
			pSignalAbortAutoTuningController->addBoolResult ("success", false);
			
			auto pSignalDisableBuildPlateTempControl = registerSignal ("disablecontroller", 4, 1000);
			pSignalDisableBuildPlateTempControl->addBoolResult ("success", false);
			
			auto pSignalToggleValves = registerSignal ("togglevalves", 4, 1000);
			pSignalToggleValves->addBoolParameter ("toggle_lower_gas_flow_circuit_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_upper_gas_flow_circuit_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_shielding_gas_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_chamber_vacuum_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_zAxis_vacuum_valve", false);
			pSignalToggleValves->addBoolResult ("success", false);
	
		}
		
	
		virtual ~CStateHandlerOxygenControl ()		
		{
		}
			
	};

	void registerOxygenControlStateHandler (CApplication * pApplication)
	{
		auto pOxygenControlStateHandler = std::make_shared<CStateHandlerOxygenControl> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pOxygenControlStateHandler->setDebugVariables (CURRENT_STATE_OXYGENCONTROL, 80);
		pApplication->registerStateHandler (pOxygenControlStateHandler);
	}


}

