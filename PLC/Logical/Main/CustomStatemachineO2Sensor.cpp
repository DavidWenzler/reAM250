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

//include required hardware modules
#include "Modules/IOModule_X20AI4622.hpp"
#include "Modules/IOModule_X20DO6322.hpp"



namespace BuRCPP {
	
	class CStateO2Sensor_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			
			// access io modules
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF24"); // measuring range switch

			pDigitalOutputModule->setOutput(6, false); // set measuring range 0 to 25 %
			
			if (pAnalogInputModule->getIOStatus(1) == 0 && pAnalogInputModule->getIOStatus(2) == 0) { // transitioning to measuring_range_0_to_25_percent
				pEnvironment->setNextState ("measuring_range_0_to_25_percent");
			}
			else {		
				pEnvironment->setNextState ("error");
			}			
		}
	};

	class CStateO2Sensor_measuring_range_0_to_25_percent : public CState {
		public:

		std::string getName()
		{
			return "measuring_range_0_to_25_percent";
		}

		void Execute(CEnvironment* pEnvironment)
		{
			// access io modules
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF24"); // measuring range switch
			
			// Signal from PC
			auto pSignalSensorTest = pEnvironment->checkSignal ("sensortest");
			
			double o2inpercent_chamber = (pAnalogInputModule->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_COARSE_UPPER_INPERCENT-O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT)/0.016)+O2SENSORCHAMBER_RANGE_COARSE_LOWER_INPERCENT;
			double o2inpercent_filter = (pAnalogInputModule->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT;
			
			pEnvironment->setIntegerValue(JOURNALVARIABLE_O2INPPM_CHAMBER, o2inpercent_chamber*10000.0);
			pEnvironment->setIntegerValue(JOURNALVARIABLE_O2INPPM_FILTER, o2inpercent_filter*10000.0);
		
			if (o2inpercent_chamber*10000 >= O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM) {		// oxygen content value >=  1000 ppm
				pDigitalOutputModule->setOutput(6, false);
				pEnvironment->setNextState("measuring_range_0_to_25_percent");
			}
			else {      // oxygen content value < 1000 ppm
				pDigitalOutputModule->setOutput(6, true);
				pEnvironment->setNextState("measuring_range_0_to_1000ppm");
			}
			if (pSignalSensorTest) { // Signal from PC
				pEnvironment->setNextState("sensor_test");
				pSignalSensorTest->finishProcessing ();
			}
			if (pAnalogInputModule->getIOStatus(1) != 0 && pAnalogInputModule->getIOStatus(2) != 0) { // transitioning to error
				pEnvironment->setNextState ("error");
			}

		}

	};
	
	class CStateO2Sensor_measuring_range_0_to_1000ppm : public CState {
		public:

		std::string getName()
		{
			return "measuring_range_0_to_1000ppm";
		}

		void Execute(CEnvironment* pEnvironment)
		{
			// access io modules
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF24"); // measuring range switch
			
			// Signal from PC
			
			auto pSignalSensorTest = pEnvironment->checkSignal ("sensortest");
			
			double o2inppm_chamber = (pAnalogInputModule->getInputCurrentInAmpere(2)-0.004)*((O2SENSORCHAMBER_RANGE_FINE_UPPER_INPPM-O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM)/0.016)+O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM;
			double o2inpercent_filter = (pAnalogInputModule->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT;
			
			pEnvironment->setIntegerValue(JOURNALVARIABLE_O2INPPM_CHAMBER, o2inppm_chamber);
			pEnvironment->setIntegerValue(JOURNALVARIABLE_O2INPPM_FILTER, o2inpercent_filter*10000.0);
			
			if (o2inppm_chamber >= O2SENSORCHAMBER_RANGE_FINE_LOWER_INPPM) {// oxygen content value >= 1000 ppm
				pDigitalOutputModule->setOutput(6, false);
				pEnvironment->setNextState("measuring_range_0_to_25_percent");
			}
			else {      // oxygen content value < 1000 ppm
				pDigitalOutputModule->setOutput(6, true);
				pEnvironment->setNextState("measuring_range_0_to_1000ppm");
			}
			if (pSignalSensorTest) { // Signal from PC
				pEnvironment->setNextState("sensor_test");
				pSignalSensorTest->finishProcessing ();
			}
			if (pAnalogInputModule->getIOStatus(1) != 0 && pAnalogInputModule->getIOStatus(2) != 0) { // transitioning to error
				pEnvironment->setNextState ("error");
			}

		}

	};

	class CStateO2Sensor_sensor_test : public CState {
		public:

		std::string getName()
		{
			return "sensor_test";
		}

		void Execute(CEnvironment* pEnvironment)
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF24"); // measuring range switch
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			
			
			if (false) { 
				pEnvironment->setNextState("sensor_test");
			}
			else {		// transitioning to init
				pEnvironment->setNextState("init");
			}
			if (pAnalogInputModule->getIOStatus(1) != 0 && pAnalogInputModule->getIOStatus(2) != 0) { // transitioning to error
				pEnvironment->setNextState ("error");
			}
		}

	};
	
	class CStateO2Sensor_error : public CState {
		public:

		std::string getName()
		{
			return "error";
		}

		void Execute(CEnvironment* pEnvironment)
		{
			// access io modules
			ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			
			if (pAnalogInputModule->getIOStatus(1) == 0 && pAnalogInputModule->getIOStatus(2) == 0) { // transitioning to init
				pEnvironment->setNextState ("init");
			}
			else {		
				pEnvironment->setNextState ("error");
			}
		}

	};

	class CO2SensorStateHandler : public CStateHandler {
		public:

		CO2SensorStateHandler (CApplication* pApplication)
			// retrieve the journal group variable for this O2Sensor state machine
			: CStateHandler (pApplication->getJournal (), "O2Sensor", pApplication->getModuleHandler (), JOURNALGROUP_O2SENSOR)
		{
			// register all states of this state machine here
			addState (std::make_shared<CStateO2Sensor_Init> ());
			addState (std::make_shared<CStateO2Sensor_measuring_range_0_to_25_percent> ());
			addState(std::make_shared<CStateO2Sensor_measuring_range_0_to_1000ppm>());
			addState(std::make_shared<CStateO2Sensor_sensor_test>());
			addState(std::make_shared<CStateO2Sensor_error>());
			
			//register signal
			auto pSignalSensorTest = registerSignal ("sensortest", 4, 1000);
			pSignalSensorTest->addBoolResult ("success", false);
			
			// register journal variables
			registerIntegerValue("o2chamberinppm", JOURNALVARIABLE_O2INPPM_CHAMBER, 0, 250000);
			registerIntegerValue("o2filterinppm", JOURNALVARIABLE_O2INPPM_FILTER, 0, 250000);
		
		}
	
		virtual ~CO2SensorStateHandler ()
		{
		}
			

	
	};

	void registerO2SensorStateHandler (CApplication * pApplication)
	{
		auto pO2SensorStateHandler = std::make_shared<CO2SensorStateHandler> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pO2SensorStateHandler->setDebugVariables (CURRENT_STATE_O2SENSOR, 80);
		pApplication->registerStateHandler (pO2SensorStateHandler);
	}


}

