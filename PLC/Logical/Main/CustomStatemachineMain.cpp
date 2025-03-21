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

#include "Modules/IOModule_X20AI4622.hpp"
#include "Modules/IOModule_X20DI9371.hpp"
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20AT6402.hpp"
#include "Modules/IOModule_PLC.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"



namespace BuRCPP {


	class CState_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access IO moduls
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25 (pEnvironment, "114KF25"); //valves
			
			if (true)
			{
				pEnvironment->setNextState ("idle");
				// close all valves during init
				pDigitalOutputModule114KF25->setOutput(1, false);
				pDigitalOutputModule114KF25->setOutput(2, false);
				pDigitalOutputModule114KF25->setOutput(3, false);
				pDigitalOutputModule114KF25->setOutput(4, false);
				pDigitalOutputModule114KF25->setOutput(5, false);
			} 
			else
			{
				pEnvironment->setNextState ("init");
			}
			
		}
	};

	
	
	class CState_Idle : public CState {
		public:

		std::string getName () 
		{
			return "idle";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState ("idle");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule114KF25 (pEnvironment, "114KF25");
			
			auto pSignalToggleValves = pEnvironment->checkSignal ("togglevalves");
			
			if (pSignalToggleValves) 
			{
				bool toggle_lower_gas_flow_circuit_valve = pSignalToggleValves->getBoolParameter("toggle_lower_gas_flow_circuit_valve");
				bool toggle_upper_gas_flow_circuit_valve = pSignalToggleValves->getBoolParameter("toggle_upper_gas_flow_circuit_valve");
				bool toggle_shielding_gas_valve = pSignalToggleValves->getBoolParameter("toggle_shielding_gas_valve");
				bool toggle_chamber_vacuum_valve = pSignalToggleValves->getBoolParameter("toggle_chamber_vacuum_valve");
				bool toggle_zAxis_vacuum_valve = pSignalToggleValves->getBoolParameter("toggle_zAxis_vacuum_valve");
				pSignalToggleValves->setBoolResult ("success", true);
				pSignalToggleValves->finishProcessing ();
				
				pDigitalOutputModule114KF25->setOutput(1, toggle_lower_gas_flow_circuit_valve);
				pDigitalOutputModule114KF25->setOutput(2, toggle_upper_gas_flow_circuit_valve);
				pDigitalOutputModule114KF25->setOutput(3, toggle_shielding_gas_valve);
				pDigitalOutputModule114KF25->setOutput(4, toggle_chamber_vacuum_valve);
				pDigitalOutputModule114KF25->setOutput(5, toggle_zAxis_vacuum_valve);
			}
		}
		
	};



	class CState_FatalError : public CState {
		public:

		std::string getName () 
		{
			return "fatalerror";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState ("fatalerror");
		}
	
	};



	// register all hardware modules here
	
	class CMainStateHandler : public CStateHandler {
		public:

		CMainStateHandler (CApplication* pApplication)
			: CStateHandler (pApplication->getJournal (), "main", pApplication->getModuleHandler (), JOURNALGROUP_MAIN)
		{
				
			addState (std::make_shared<CState_Init> ());
			addState (std::make_shared<CState_Idle> ());
			addState (std::make_shared<CState_FatalError> ());
			
			//register the signals
			auto pSignalSingleAxisMovement = registerSignal ("togglevalves", 4, 1000);
			pSignalSingleAxisMovement->addBoolParameter ("toggle_lower_gas_flow_circuit_valve", false);
			pSignalSingleAxisMovement->addBoolParameter ("toggle_upper_gas_flow_circuit_valve", false);
			pSignalSingleAxisMovement->addBoolParameter ("toggle_shielding_gas_valve", false);
			pSignalSingleAxisMovement->addBoolParameter ("toggle_chamber_vacuum_valve", false);
			pSignalSingleAxisMovement->addBoolParameter ("toggle_zAxis_vacuum_valve", false);
			pSignalSingleAxisMovement->addBoolResult ("success", false);
		
		}
	
		virtual ~CMainStateHandler ()
		
		{
		}
			

	
	};


	void registerMainStateHandler (CApplication * pApplication)
	{
		auto pMainStateHandler = std::make_shared<CMainStateHandler> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pMainStateHandler->setDebugVariables (CURRENT_STATE_MAIN, 80);
		pApplication->registerStateHandler (pMainStateHandler);
	}

}