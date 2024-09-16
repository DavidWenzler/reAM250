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

#include <cmath>

#include "Framework/Application.hpp"


#include "CustomConstants.hpp"

//include required hardware modules
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20AI4622.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"



namespace BuRCPP {
	class CStateVacuumSystem_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_1(pEnvironment, "114KF28"); // enable pump
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_2(pEnvironment, "114KF25"); // set valves
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pressure measurement error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
			
			pDigitalOutputModule_1->setOutput(2, false); // disable pump
		
			pDigitalOutputModule_2->setOutput(4, false); // close vacuum valves
			pDigitalOutputModule_2->setOutput(5, false);
			
			// Signal from PC
			auto pSignalInitVacuumSystem = pEnvironment->checkSignal ("initvacuumsystem");
			
			if (pSignalInitVacuumSystem)
			{
				int pressure_threshold_vacuum_off_in_mbar = pSignalInitVacuumSystem->getInt32Parameter("pressurethresholdvacuumoffinmbar");
				pEnvironment->setIntegerValue(JOURNALVARIABLE_PRESSURE_THRESHOLD_VACUUM_OFF_IN_MBAR, pressure_threshold_vacuum_off_in_mbar);
				pEnvironment->setNextState("idle");
				pSignalInitVacuumSystem->finishProcessing ();
			}
			else 
			{
				pEnvironment->setNextState("init");
			}
			
			if (pDigitalInputModule_1->getInput(2)==0 || pDigitalInputModule_2->getInput(5)==1)
			{
				pEnvironment->setNextState("error");
			}
		}
	};
	
	class CStateVacuumSystem_idle : public CState {
		public:

		std::string getName () 
		{
			return "idle";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pressure measurement error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_3(pEnvironment, "113KF17");// get circulation valves status
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_4(pEnvironment, "113KF21");// get vacuum valves status
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF25"); // set valves
			
			// Signal from PC
			auto pSignalStartVacuumPump = pEnvironment->checkSignal ("startvacuumpump");
			auto pSignalToggleValves = pEnvironment->checkSignal ("togglevalves");
			
			if (pSignalToggleValves) // toggle gas flow valves
			{
				bool toggle_zAxis_vacuum_valve = pSignalToggleValves->getBoolParameter("toggle_zAxis_vacuum_valve");
				bool toggle_chamber_vacuum_valve = pSignalToggleValves->getBoolParameter("toggle_chamber_vacuum_valve");
				
				pDigitalOutputModule->setOutput(5, toggle_zAxis_vacuum_valve);
				pDigitalOutputModule->setOutput(4, toggle_chamber_vacuum_valve);
				pSignalToggleValves->finishProcessing ();
			}
			
			if (pSignalStartVacuumPump && pDigitalInputModule_3->getInput(2)==1 && pDigitalInputModule_3->getInput(4)==1 && pDigitalInputModule_4->getInput(1)==1 && pDigitalInputModule_4->getInput(3)==1)
			{
				pEnvironment->setNextState("vacuum_pump_on");
				pSignalStartVacuumPump->finishProcessing ();
			}
			else
			{
				pEnvironment->setNextState("idle");
			}
			
			if (pDigitalInputModule_1->getInput(2)==0 || pDigitalInputModule_2->getInput(5)==1)
			{
				pEnvironment->setNextState("error");
			}
		}
	
	};
	
	class CStateVacuumSystem_vacuum_pump_on : public CState {
		public:

		std::string getName () 
		{
			return "vacuum_pump_on";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pressure measurement error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
			ioModuleAccess<CIOModule_X20AI4622> pAnalogInputModule(pEnvironment, "112KF15");// pressure in volt
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF28");// enable vacuum pump
			
			// Signal from PC
			auto pSignalTurnOffVacuumPump = pEnvironment->checkSignal ("turnoffvacuumpump");
			
			double pressure_in_volt = pAnalogInputModule->getInputVoltageInVolt(1);
			int pressure_in_mbar = (int) (std::pow(10 , 0.778*(pressure_in_volt - 6.143))); //characteristic curve of the pressure sensor, type-casting to integer
			pEnvironment->setIntegerValue(JOURNALVARIABLE_PRESSURE_IN_MBAR, pressure_in_mbar);
			auto pressure_threshold_vacuum_off_in_mbar = pEnvironment->getInt32Value(JOURNALVARIABLE_PRESSURE_THRESHOLD_VACUUM_OFF_IN_MBAR);
			
			pDigitalOutputModule->setOutput(2, true); // enable vacuum pump
			
			if (pSignalTurnOffVacuumPump || (pressure_in_mbar < pressure_threshold_vacuum_off_in_mbar))
			{
				pDigitalOutputModule->setOutput(2, false); // disable vacuum pump
				pEnvironment->setNextState("idle");
				pSignalTurnOffVacuumPump->finishProcessing ();
			}
			else
			{
				pEnvironment->setNextState("vacuum_pump_on");
			}
			
			if (pDigitalInputModule_1->getInput(2)==0 || pDigitalInputModule_2->getInput(5)==1)
			{
				pDigitalOutputModule->setOutput(2, false); // disable vacuum pump
				pEnvironment->setNextState("error");
			}
		}
	
	};
	
	class CStateVacuumSystem_error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pressure measurement error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
				
			if (pDigitalInputModule_1->getInput(2)==0 || pDigitalInputModule_2->getInput(5)==1)
			{
				pEnvironment->setNextState("error");
			}
			else
			{
				pEnvironment->setNextState("init");
			}
		}
	
	};
	
		
	
	class CStateHandlerVacuumSystem : public CStateHandler {
		public:

		CStateHandlerVacuumSystem (CApplication* pApplication)
			// retrieve the journal group variable for this vacuum system state machine
			: CStateHandler (pApplication->getJournal (), "vacuumsystem", pApplication->getModuleHandler (), JOURNALGROUP_VACUUMSYSTEM)
		{
			// register all states of this state machine here
			addState (std::make_shared<CStateVacuumSystem_Init> ());
			addState (std::make_shared<CStateVacuumSystem_idle> ());
			addState (std::make_shared<CStateVacuumSystem_vacuum_pump_on> ());
			addState (std::make_shared<CStateVacuumSystem_error> ());
			
			//register signal
			auto pSignalInitVacuumSystem = registerSignal ("initvacuumsystem", 4, 1000);
			pSignalInitVacuumSystem->addInt32Parameter ("pressurethresholdvacuumoffinmbar", 0);
			pSignalInitVacuumSystem->addBoolResult ("success", false);
			
			auto pSignalToggleValves = registerSignal ("togglevalves", 4, 1000);
			pSignalToggleValves->addBoolParameter ("toggle_lower_gas_flow_circuit_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_upper_gas_flow_circuit_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_shielding_gas_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_chamber_vacuum_valve", false);
			pSignalToggleValves->addBoolParameter ("toggle_zAxis_vacuum_valve", false);
			pSignalToggleValves->addBoolResult ("success", false);
			
			auto pSignalStartVacuumPump = registerSignal ("startvacuumpump", 4, 1000);
			pSignalStartVacuumPump->addBoolResult ("success", false);
			
			auto pSignalTurnOffVacuumPump = registerSignal ("turnoffvacuumpump", 4, 1000);
			pSignalTurnOffVacuumPump->addBoolResult ("success", false);
			
			// register journal variables
			registerIntegerValue("pressurethresholdvacuumoffinmbar", JOURNALVARIABLE_PRESSURE_THRESHOLD_VACUUM_OFF_IN_MBAR, 0, 1000);
			registerIntegerValue("pressureinmbar", JOURNALVARIABLE_PRESSURE_IN_MBAR, 0, 1000);
		
		}
	
		virtual ~CStateHandlerVacuumSystem ()		
		{
		}
			

	
	};

	void registerVacuumSystemStateHandler (CApplication * pApplication)
	{
		auto pVacuumSystemStateHandler = std::make_shared<CStateHandlerVacuumSystem> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pVacuumSystemStateHandler->setDebugVariables (CURRENT_STATE_VACUUMSYSTEM, 80);
		pApplication->registerStateHandler (pVacuumSystemStateHandler);
	}


}