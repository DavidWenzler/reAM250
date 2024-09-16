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
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20DO6322.hpp"


namespace BuRCPP {
	
	class CStateHeater_Wait_For_Init : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
						
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			// check for PC signals
			auto pSignalUpdateControllerPidParameters = pEnvironment->checkSignal ("updatecontrollerparameters");
			auto pSignalUpdateControllerTunerParameters = pEnvironment->checkSignal ("updatecontrollertunerparameters");
			auto pSignalUpdateControllerPwmParameters = pEnvironment->checkSignal ("updatecontrollerpwmparameters");
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint");
			
			// check if the control function block, the temperature sensor, and the heater protection switch are OK 
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
					
				if(pSignalUpdateControllerPidParameters)
				{ // check if the signal is an update signal
					bool bIsInitPID = pSignalUpdateControllerPidParameters->getBoolParameter("isinit");
					pEnvironment->setNextState ("wait_for_init");
					if(bIsInitPID)
					{
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PID_ISINIT, true);
					
						//retrieve the PID update parameters 
						double dDerivativeTime = pSignalUpdateControllerPidParameters->getInt32Parameter("derivativetime")* 0.001;
						double dIntegrationTime = pSignalUpdateControllerPidParameters->getInt32Parameter("integrationtime")* 0.001;
						double dGain = pSignalUpdateControllerPidParameters->getInt32Parameter("gain")*0.001;
						double dFilterTime = pSignalUpdateControllerPidParameters->getInt32Parameter("filtertime")* 0.001;
						int nMaxOut = pSignalUpdateControllerPidParameters->getInt32Parameter("maxout");
						int nMinOut = pSignalUpdateControllerPidParameters->getInt32Parameter("minout");
				
			
						// store the PID parameters in journal variables
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_DERIVATIVETIMEINSECONDS,  dDerivativeTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_INTEGRATIONTIMEINSECONDS,  dIntegrationTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_GAIN,  dGain);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_FILTERTIMEINSECONDS,  dFilterTime);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_MAXOUTINPERCENT,  nMaxOut);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_MINOUTINPERCENT,  nMinOut);
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
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_TUNE_ISINIT, true);

						//retrieve the PID tuner update parameters 
						int nStepHeight = pSignalUpdateControllerTunerParameters->getInt32Parameter("stepheight");
						int nMaxActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxactvalue");
						int nMinActValue = pSignalUpdateControllerTunerParameters->getInt32Parameter("minactvalue");
						double dSystemSettlingTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("systemsettlingtime")/1000.0;
						double dMaxTuningTime = pSignalUpdateControllerTunerParameters->getInt32Parameter("maxtuningtime")/1000.0;
								
						// store the PID tuner parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS,  nStepHeight);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
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
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PWM_ISINIT, true);
			
						// retrieve the parameters to update the heater PWM function block
						int nDutyCycle = pSignalUpdateControllerPwmParameters->getInt32Parameter("dutycycle");
						double dPeriod = pSignalUpdateControllerPwmParameters->getInt32Parameter("period")/1000;
						int nMaxFrequency = pSignalUpdateControllerPwmParameters->getInt32Parameter("maxFrequency");
						bool bMode = pSignalUpdateControllerPwmParameters->getInt32Parameter("mode");
								
						// store the heater PWM function block parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_PWM_DUTYCYCLE,  nDutyCycle);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_PWM_PERIOD,  dPeriod);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_PWM_MAXFREQUENCY,  nMaxFrequency);
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PWM_MODE,  bMode);
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
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_SETPOINT_ISINIT, true);
		
						// retrieve the parameter to update the heater temperature setpoint
						int nSetvalue = pSignalUpdateControllerSetpoint->getInt32Parameter("setvalue");
							
						// store the heater temperature setpoint in journal variable
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_SETPOINTINDEGREECELCIUS,  nSetvalue);
					}
					// finish processing of the signals
					pSignalUpdateControllerSetpoint->finishProcessing ();
				}
				
				else 
				{ // check if all parameters were inizialized
					bool bIsInitPID = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_PID_ISINIT);
					bool bIsInitTuner = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_TUNE_ISINIT);
					bool bIsInitPWM = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_PWM_ISINIT);
					bool bIsInitSetpoint = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_SETPOINT_ISINIT);
					
					if (bIsInitPWM && bIsInitTuner && bIsInitPID && bIsInitSetpoint){
						pEnvironment->setNextState ("init");
						// reset the init flags
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PID_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_TUNE_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PWM_ISINIT, false);
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_SETPOINT_ISINIT, false);
					}else
					{ // wait for the init parameter signal from the PC
						pEnvironment->setNextState ("wait_for_init");
					}
					
				}
			}
			else
			{ // if there is an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block 
		}
	
	};
	
	class CStateHeater_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
						
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			// check if the control function block, the temperature sensor, and the heater protection switch are OK 
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
				fbBuildPlatformTempController.Enable = 1;
				fbBuildPlatformTempPWM.Enable = 1;
				fbBuildPlatfromTempTuner.Enable = 1;
				//retrieve the PID init parameters 
				double dDerivativeTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_DERIVATIVETIMEINSECONDS);
				double dIntegrationTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_INTEGRATIONTIMEINSECONDS);
				double dGain = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_GAIN);
				double dFilterTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_FILTERTIMEINSECONDS);
				int nMaxOut = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_MAXOUTINPERCENT);
				int nMinOut = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_MINOUTINPERCENT);
				//retrieve the setpoint init parameter
				int nSetValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_SETPOINTINDEGREECELCIUS);
										
				// initialize the heater PID function block
				// controller output scaled between 0% and 100%, controller input will be scaled to %, too
				fbBuildPlatformTempController.PIDParameters.DerivativeTime = dDerivativeTime;
				fbBuildPlatformTempController.PIDParameters.IntegrationTime = dIntegrationTime;
				fbBuildPlatformTempController.PIDParameters.Gain = dGain;
				fbBuildPlatformTempController.PIDParameters.FilterTime = dFilterTime;
				fbBuildPlatformTempController.MaxOut = nMaxOut;
				fbBuildPlatformTempController.MinOut = nMinOut;
				fbBuildPlatformTempController.SetValue = nSetValue;
				fbBuildPlatformTempController.Update = true;
					
				//retrieve the PID tuner init parameters 
				int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS);
				int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT);
				int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT);
				double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS);
				double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS);
				
				// initialize the heater PID tuner function block
				// height of the step to be applied during training,Out = startValue+StepHeight 
				fbBuildPlatfromTempTuner.StepHeight = nStepHeight;
				// range of the measured process variable during training, scaled to be in %
				fbBuildPlatfromTempTuner.MaxActValue = nMaxActValue;
				fbBuildPlatfromTempTuner.MinActValue = nMinActValue;
				// time for the system to settle at the start setpoint before the step for tuning is applied in s
				fbBuildPlatfromTempTuner.SystemSettlingTime = dSystemSettlingTime;
				// maximum time for the tuning including the settling time in s
				fbBuildPlatfromTempTuner.MaxTuningTime = dMaxTuningTime;
				fbBuildPlatfromTempTuner.Update = true;
				
				// initialize the heater controller enabled flag
				pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED,  false);
											
				// retrieve the parameters to initialize the heater PWM function block
				int nDutyCycle = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_PWM_DUTYCYCLE);
				double dPeriod = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_PWM_PERIOD);
				int nMaxFrequency = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_PWM_MAXFREQUENCY);
				bool bMode = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_PWM_MODE);
			
					
				// PWM DutyCycle
				fbBuildPlatformTempPWM.DutyCycle = nDutyCycle;
				// min time of a single pulse, on or off, 1/maxFrequency = 1/5 Hz
				fbBuildPlatformTempPWM.MinPulseWidth = 1/nMaxFrequency;
				// mode = pulse in the middle (1) of the period time of in the beginning (0)
				if(bMode)
				{
					fbBuildPlatformTempPWM.Mode = mtBASICS_PULSE_BEGINNING;
				}
				else
				{
					fbBuildPlatformTempPWM.Mode = mtBASICS_PULSE_MIDDLE;
				}
				// period time of the PWM
				fbBuildPlatformTempPWM.Period = dPeriod; 
				//currently, default values are used
				fbBuildPlatformTempPWM.Update = true;		
				
				pEnvironment->setNextState ("wait_for_parameter_update");
		
			}
			else
			{ // if there is an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}	
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	};
	
	
	class CStateHeater_IdleDisabled : public CState {
		public:

		std::string getName () 
		{
			return "idle_disabled";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			// check for signals
			auto pSignalEnableBuildPlateTempControl = pEnvironment->checkSignal ("enablecontroller"); //signal to enable the controller
			auto pSignalUpdateControllerPidParameters = pEnvironment->checkSignal ("updatecontrollerparameters"); //signal to update the PID parameters
			auto pSignalUpdateControllerTunerParameters = pEnvironment->checkSignal ("updatecontrollertunerparameters"); //signal to update the parameters of the tuner
			auto pSignalUpdateControllerPwmParameters = pEnvironment->checkSignal ("updatecontrollerpwmparameters"); //signal to update the PWM parameters
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint"); //signal to update the setpoint
			auto pSignalAutoTuneController = pEnvironment->checkSignal ("autotunecontroller"); //signal to update the setpoint
			
			fbBuildPlatformTempController.Enable = 0;
			fbBuildPlatformTempPWM.Enable = 0;
			fbBuildPlatfromTempTuner.Enable = 0;
			
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
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
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_DERIVATIVETIMEINSECONDS,  dDerivativeTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_INTEGRATIONTIMEINSECONDS,  dIntegrationTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_GAIN,  dGain);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_FILTERTIMEINSECONDS,  dFilterTime);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_MAXOUTINPERCENT,  nMaxOut);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_MINOUTINPERCENT,  nMinOut);
						
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
					// finish processing of the signals
					pSignalUpdateControllerPidParameters->finishProcessing ();
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
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS,  nStepHeight);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
						
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
					// finish processing of the signals
					pSignalUpdateControllerTunerParameters->finishProcessing ();
				}
				else if(pSignalUpdateControllerPwmParameters)
				{ // check if the signal is an update signal
					bool bIsInitPWM = pSignalUpdateControllerPwmParameters->getBoolParameter("isinit");
					
					pEnvironment->setNextState ("idle_disabled");
					
					if(!bIsInitPWM)
					{
						// retrieve the parameters to update the heater PWM function block
						int nDutyCycle = pSignalUpdateControllerPwmParameters->getInt32Parameter("dutycycle");
						double dPeriod = pSignalUpdateControllerPwmParameters->getInt32Parameter("period")/1000;
						int nMaxFrequency = pSignalUpdateControllerPwmParameters->getInt32Parameter("maxFrequency");
						bool bMode = pSignalUpdateControllerPwmParameters->getInt32Parameter("mode");
										
						// store the heater PWM function block parameters in journal variables
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_PWM_DUTYCYCLE,  nDutyCycle);
						pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_PWM_PERIOD,  dPeriod);
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_PWM_MAXFREQUENCY,  nMaxFrequency);
						pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_PWM_MODE,  bMode);
					
						// go to init state
						pEnvironment->setNextState ("update_parameters");
					}
					// finish processing of the signals
					pSignalUpdateControllerPwmParameters->finishProcessing ();
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
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_SETPOINTINDEGREECELCIUS,  nSetValue);
						//set new setpoint
						fbBuildPlatformTempController.SetValue = nSetValue;
					}
					// finish processing of the signal
					pSignalUpdateControllerSetpoint->finishProcessing ();
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
					pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS,  nStepHeight);
					pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT,  nMaxActValue);
					pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT,  nMinActValue);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS,  dSystemSettlingTime);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS,  dMaxTuningTime);
						
					// finish processing of the signals
					pSignalAutoTuneController->finishProcessing ();
						
					// go to init state
					pEnvironment->setNextState ("tune_control_parameters");
				}
				else if(pSignalEnableBuildPlateTempControl)
				{ // enable the controller
					fbBuildPlatformTempController.Enable = 1;
					fbBuildPlatformTempPWM.Enable = 1;
					fbBuildPlatfromTempTuner.Enable = 1;
					pEnvironment->setNextState ("heating_control_enabled");
				}
				else
				{
					pEnvironment->setNextState ("idle_disabled");
				}
				
			}
			else
			{ // if there is an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};
	
	class CStateHeater_Update_Parameters : public CState {
		public:

		std::string getName () 
		{
			return "update_parameters";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			fbBuildPlatfromTempTuner.Enable = 1;
			fbBuildPlatformTempPWM.Enable = 1;
			fbBuildPlatfromTempTuner.Enable = 1;
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
					//retrieve the PID init parameters 
					double dDerivativeTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_DERIVATIVETIMEINSECONDS);
					double dIntegrationTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_INTEGRATIONTIMEINSECONDS);
					double dGain = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_GAIN);
					double dFilterTime = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_FILTERTIMEINSECONDS);
					int nMaxOut = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_MAXOUTINPERCENT);
					int nMinOut = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_MINOUTINPERCENT);
				
										
					// initialize the heater PID function block
					// controller output scaled between 0% and 100%, controller input will be scaled to %, too
					fbBuildPlatformTempController.PIDParameters.DerivativeTime = dDerivativeTime;
					fbBuildPlatformTempController.PIDParameters.IntegrationTime = dIntegrationTime;
					fbBuildPlatformTempController.PIDParameters.Gain = dGain;
					fbBuildPlatformTempController.PIDParameters.FilterTime = dFilterTime;
					fbBuildPlatformTempController.MaxOut = nMaxOut;
					fbBuildPlatformTempController.MinOut = nMinOut;
					fbBuildPlatformTempController.Update = true;
					
					//retrieve the PID tuner init parameters 
					int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS);
					int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT);
					int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT);
					double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS);
					double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS);
				
					// initialize the heater PID tuner function block
					// height of the step to be applied during training,Out = startValue+StepHeight 
					fbBuildPlatfromTempTuner.StepHeight = nStepHeight;
					// range of the measured process variable during training, scaled to be in %
					fbBuildPlatfromTempTuner.MaxActValue = nMaxActValue;
					fbBuildPlatfromTempTuner.MinActValue = nMinActValue;
					// time for the system to settle at the start setpoint before the step for tuning is applied in s
					fbBuildPlatfromTempTuner.SystemSettlingTime = dSystemSettlingTime;
					// maximum time for the tuning including the settling time in s
					fbBuildPlatfromTempTuner.MaxTuningTime = dMaxTuningTime;
					fbBuildPlatfromTempTuner.Update = true;
											
					// retrieve the parameters to initialize the heater PWM function block
					int nDutyCycle = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_PWM_DUTYCYCLE);
					double dPeriod = pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_PWM_PERIOD);
					int nMaxFrequency = pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_PWM_MAXFREQUENCY);
					bool bMode = pEnvironment->getBoolValue(JOURNALVARIABLE_HEATER_PWM_MODE);
			
					
					// PWM DutyCycle
					fbBuildPlatformTempPWM.DutyCycle = nDutyCycle;
					// min time of a single pulse, on or off, 1/maxFrequency = 1/5 Hz
					fbBuildPlatformTempPWM.MinPulseWidth = 1/nMaxFrequency;
					// mode = pulse in the middle (1) of the period time of in the beginning (0)
					if(bMode)
					{
						fbBuildPlatformTempPWM.Mode = mtBASICS_PULSE_BEGINNING;
					}
					else
					{
						fbBuildPlatformTempPWM.Mode = mtBASICS_PULSE_MIDDLE;
					}
					// period time of the PWM
					fbBuildPlatformTempPWM.Period = dPeriod; 
					//currently, default values are used
					fbBuildPlatformTempPWM.Update = true;		
				
					pEnvironment->setNextState ("wait_for_parameter_update");
			}
			else
			{ // if there is an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};
	
	class CStateHeater_Wait_For_Parameter_Update : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_parameter_update";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{	//check if the parameter update of all three control function blocks is done
				if(fbBuildPlatformTempController.UpdateDone == 1 && fbBuildPlatformTempPWM.UpdateDone == 1 && fbBuildPlatfromTempTuner.UpdateDone == 1)
				{	//reset the update flag and change to idle state
					fbBuildPlatformTempController.Update = 0;
					fbBuildPlatformTempPWM.Update = 0;
					fbBuildPlatfromTempTuner.Update = 0;
					fbBuildPlatformTempController.Enable = false;
					fbBuildPlatfromTempTuner.Enable = false;
					fbBuildPlatformTempPWM.Enable = false;
					pEnvironment->setNextState ("idle_disabled");
				}
				else
				{	//if the update is not yet done, remain in the wait_for_parameter_update state
					pEnvironment->setNextState ("wait_for_parameter_update");
				}
			}
			else
			{ // if there is an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};


	class CStateHeater_Heating_Control_Enabled : public CState {
		public:

		std::string getName () 
		{
			return "heating_control_enabled";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			// Build plate heating relais, Modul: 114KF28; DO Channel: 3
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF28");
			
			//check for signals
			auto pSignalUpdateControllerSetpoint = pEnvironment->checkSignal ("updatecontrollersetpoint"); //signal to update the setpoint
			auto pSignalDisableBuildPlateTempControl = pEnvironment->checkSignal ("disablecontroller"); //signal to disable the controller
			
				
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
								
				if(pSignalDisableBuildPlateTempControl) 
				{// disable control signal from the PC
					fbBuildPlatformTempController.Enable = 0;
					pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED,  false); // set the heater controller enabled flag
					pEnvironment->setNextState ("idle_disabled");
				}
				else if(pSignalUpdateControllerSetpoint)
				{ //signal from PC to update the setpoint
					
					// check if the signal is an update signal
					bool bIsInitSetpoint = pSignalUpdateControllerSetpoint->getBoolParameter("isinit");
					
					if(!bIsInitSetpoint)
					{
						//retrieve new setpoint from signal
						double nSetValue = pSignalUpdateControllerSetpoint->getInt32Parameter("setvalue");
						//store setpoint in the journal variable
						pEnvironment->setIntegerValue(JOURNALVARIABLE_HEATER_SETPOINTINDEGREECELCIUS,  nSetValue);
						//set new setpoint
						fbBuildPlatformTempController.SetValue = nSetValue;
					}
					// finish processing of the signal
					pSignalUpdateControllerSetpoint->finishProcessing ();
					pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED,  true); // set the heater controller enabled flag
					pEnvironment->setNextState ("heating_control_enabled");
				}
				else
				{	
					fbBuildPlatformTempController.ActValue = 20*pAnalogInputModule->getInputVoltageInVolt(2); // (0-200°C / 0 … 10V)
					fbBuildPlatformTempPWM.DutyCycle = fbBuildPlatformTempController.Out; // transform PID control output to a PID signal
					pDigitalOutputModule->setOutput(3, fbBuildPlatformTempPWM.Out); // set the heater output according to the PID signal
					pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED,  true); // set the heater controller enabled flag
					pEnvironment->setNextState ("heating_control_enabled");
				}
					
			}
			else
			{ // if an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setBoolValue(JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED,  false); // set the heater controller enabled flag
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block		
		}
	
	};
	
	class CStateHeater_Tune_Control_Parameters : public CState {
		public:

		std::string getName () 
		{
			return "tune_control_parameters";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			// Build plate heating relais, Modul: 114KF28; DO Channel: 3
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
				fbBuildPlatformTempController.Enable = true;
				fbBuildPlatformTempPWM.Enable = true;
				fbBuildPlatfromTempTuner.Enable = true;
				if(fbBuildPlatfromTempTuner.Update == false)
				{	
					//retrieve the PID tuner init parameters 
					int nStepHeight =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS);
					int nMaxActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT);
					int nMinActValue =  pEnvironment->getInt32Value(JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT);
					double dSystemSettlingTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS);
					double dMaxTuningTime =  pEnvironment->getDoubleValue(JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS);
				
					// initialize the heater PID tuner function block
					// height of the step to be applied during training,Out = startValue+StepHeight 
					fbBuildPlatfromTempTuner.StepHeight = nStepHeight;
					// range of the measured process variable during training, scaled to be in %
					fbBuildPlatfromTempTuner.MaxActValue = nMaxActValue;
					fbBuildPlatfromTempTuner.MinActValue = nMinActValue;
					// time for the system to settle at the start setpoint before the step for tuning is applied in s
					fbBuildPlatfromTempTuner.SystemSettlingTime = dSystemSettlingTime;
					// maximum time for the tuning including the settling time in s
					fbBuildPlatfromTempTuner.MaxTuningTime = dMaxTuningTime;
					
					fbBuildPlatfromTempTuner.Update = true;
					fbBuildPlatfromTempTuner.Start = false;
					pEnvironment->setNextState ("tune_control_parameters");
				} 
				else if(fbBuildPlatfromTempTuner.UpdateDone)
				{	
					fbBuildPlatfromTempTuner.Update = false;
					fbBuildPlatfromTempTuner.Start = true;
					pEnvironment->setNextState ("wait_for_tuning");
				}	
			}
			else
			{ // if an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};
	
	class CStateHeater_Wait_For_Tuning : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_tuning";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			// Build plate heating relais, Modul: 114KF28; DO Channel: 3
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF28");
			
			//check for signals
			auto pSignalAbortAutoTuningController = pEnvironment->checkSignal ("abortautotuningcontroller"); //signal to abort the auto tuning
			
			// check if there is an error --> error state
			if(fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
				if(fbBuildPlatfromTempTuner.TuningDone)
				{
					fbBuildPlatfromTempTuner.Start = 0;
					fbBuildPlatformTempController.PIDParameters = fbBuildPlatfromTempTuner.PIDParameters;
					fbBuildPlatformTempController.Enable = 1;
					fbBuildPlatformTempPWM.Enable = 1;
					fbBuildPlatfromTempTuner.Enable = 1;
					fbBuildPlatformTempController.Update = true;
					fbBuildPlatformTempPWM.Update = true;
					fbBuildPlatfromTempTuner.Update = true;
					pEnvironment->setNextState("wait_for_parameter_update");
				}
				else if (pSignalAbortAutoTuningController)
				{
					fbBuildPlatfromTempTuner.Start = 0;
					fbBuildPlatformTempController.Enable = 0;
					fbBuildPlatformTempPWM.Enable = 0;
					fbBuildPlatfromTempTuner.Enable = 0;
					pEnvironment->setNextState("idle_disabled");
				}
				else
				{
					pEnvironment->setNextState("wait_for_tuning");
					fbBuildPlatfromTempTuner.ActValue = (int)round(20*pAnalogInputModule->getInputVoltageInVolt(2)); // (0-200°C / 0 … 10V)
					fbBuildPlatformTempPWM.DutyCycle = fbBuildPlatfromTempTuner.Out; // transform PID control output to a PID signal
					pDigitalOutputModule->setOutput(3, fbBuildPlatformTempPWM.Out); // set the heater output according to the PID signal
				}
				
			}
			else
			{ // if an error occured, diable the heater control function bocks and switch to the error state
				fbBuildPlatformTempController.Enable = 0;
				fbBuildPlatformTempPWM.Enable = 0;
				fbBuildPlatfromTempTuner.Enable = 0;
				fbBuildPlatfromTempTuner.Start = false;
				pEnvironment->setNextState ("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};

	class CStateHeater_Error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{	
			// access an IO modules
			// Temperature build plate heating, Modul: 112KF15; AI Channel: 2; Value range: (0-200°C / 0 … 10V)
			// Build plate heating protection switch, Modul: 113KF18; DI Channel: 6; 0 = error, 1 = OK
			// Build plate heating relais, Modul: 114KF28; DO Channel: 3
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule (pEnvironment, "112KF15");
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF18");
			
			if (fbBuildPlatformTempController.Error == 0 && fbBuildPlatformTempPWM.Error == 0 && fbBuildPlatfromTempTuner.Error == 0 &&  pAnalogInputModule->getIOStatus(2) == 0 && pDigitalInputModule->getInput(6) == 0)
			{
				pEnvironment->setNextState("init");
			}
			else
			{
				pEnvironment->setNextState("error");
			}
			MTBasicsStepTuning(&fbBuildPlatfromTempTuner); // call tuning function block 
			MTBasicsPID(&fbBuildPlatformTempController); // call PID function block 
			MTBasicsPWM(&fbBuildPlatformTempPWM); // call PWM function block
		}
	
	};
	
		
	
	class CStateHandlerHeater : public CStateHandler {
		public:

		CStateHandlerHeater (CApplication* pApplication)
			: CStateHandler (pApplication->getJournal (), "heater", pApplication->getModuleHandler (), JOURNALGROUP_HEATER)
		{
			// register all states of this state machine here
			addState (std::make_shared<CStateHeater_Wait_For_Init> ());
			addState (std::make_shared<CStateHeater_Init> ());
			addState (std::make_shared<CStateHeater_IdleDisabled> ());
			addState (std::make_shared<CStateHeater_Update_Parameters> ());
			addState (std::make_shared<CStateHeater_Wait_For_Parameter_Update> ());
			addState (std::make_shared<CStateHeater_Heating_Control_Enabled> ());
			addState (std::make_shared<CStateHeater_Tune_Control_Parameters> ());
			addState (std::make_shared<CStateHeater_Wait_For_Tuning> ());
			addState (std::make_shared<CStateHeater_Error> ());
			
			// register journal variables
			registerDoubleValue("heater_PID_derivativetime", JOURNALVARIABLE_HEATER_DERIVATIVETIMEINSECONDS, 0.0, 1000.0, 40000000);
			registerDoubleValue("heater_PID_integrationtime", JOURNALVARIABLE_HEATER_INTEGRATIONTIMEINSECONDS, 0.0, 1000.0, 40000000);
			registerDoubleValue("heater_PID_gain", JOURNALVARIABLE_HEATER_GAIN, -1000.0, 1000.0, 20000000);
			registerDoubleValue("heater_PID_filtertime", JOURNALVARIABLE_HEATER_FILTERTIMEINSECONDS, 0.0, 1000.0, 20000000);
			registerIntegerValue("heater_PID_maxout", JOURNALVARIABLE_HEATER_MINOUTINPERCENT, 0, 100);
			registerIntegerValue("heater_PID_minout", JOURNALVARIABLE_HEATER_MAXOUTINPERCENT, 0, 100);
			registerIntegerValue("heater_PID_setvalue", JOURNALVARIABLE_HEATER_SETPOINTINDEGREECELCIUS, 0, 250000);
			registerBoolValue("heater_PID_isenabled", JOURNALVARIABLE_HEATER_CONTROLLER_ENABLED);
			registerIntegerValue("heater_tuner_stepheight", JOURNALVARIABLE_HEATER_TUNE_STEPHEIGHTINDEGREECELCIUS, 0, 1000);
			registerIntegerValue("heater_tuner_maxactvalue", JOURNALVARIABLE_HEATER_TUNE_MAXACTVALUEINPERCENT, 0, 100);
			registerIntegerValue("heater_tuner_minactvalue", JOURNALVARIABLE_HEATER_TUNE_MINACTVALUEINPERCENT, 0, 100);
			registerDoubleValue("heater_tuner_systemsettlingtime", JOURNALVARIABLE_HEATER_TUNE_SETTLINGTIMEINSECONDS, 0.0, 3600.0, 3600000);
			registerDoubleValue("heater_tuner_maxtuningtime", JOURNALVARIABLE_HEATER_TUNE_MAXTUNINGTIMEINSECONDS, 0.0, 3600.0, 3600000);
			registerIntegerValue("heater_PWM_dutycycle", JOURNALVARIABLE_HEATER_PWM_DUTYCYCLE, 0, 100);
			registerDoubleValue("heater_PWM_period", JOURNALVARIABLE_HEATER_PWM_PERIOD, 0.0, 1000, 1000000);
			registerIntegerValue("heater_PWM_maxFrequency", JOURNALVARIABLE_HEATER_PWM_MAXFREQUENCY, 0, 1000);
			registerBoolValue("heater_PWM_mode", JOURNALVARIABLE_HEATER_PWM_MODE);
			registerBoolValue("heater_PID_isinit", JOURNALVARIABLE_HEATER_PID_ISINIT);
			registerBoolValue("heater_PWM_isinit", JOURNALVARIABLE_HEATER_PWM_ISINIT);
			registerBoolValue("heater_tuner_isinit", JOURNALVARIABLE_HEATER_TUNE_ISINIT);
			registerBoolValue("heater_setpoint_isinit", JOURNALVARIABLE_HEATER_SETPOINT_ISINIT);

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
		}
	
		virtual ~CStateHandlerHeater ()		
		{
		}
			
	};

	void registerHeaterStateHandler (CApplication * pApplication)
	{
		auto pHeaterStateHandler = std::make_shared<CStateHandlerHeater> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pHeaterStateHandler->setDebugVariables (CURRENT_STATE_HEATING, 80);
		pApplication->registerStateHandler (pHeaterStateHandler);
	}


}

