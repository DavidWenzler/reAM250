/*++

Copyright (C) 2024 Institut für Werkzeugmaschinen und Betriebswissenschaften (iwb)
TUM School of Engineering and Design 
Technische Universität München

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

#include "Framework/Application.hpp"

#include "CustomConstants.hpp"

//include required hardware modules
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"



namespace BuRCPP {
	// change the name of the state handler class
	// change the name of the register state handler function
	// globally register the state handler and all the hardware modules in the CustomApplication.cpp
	// creat a new journalgroup for your state machine in the CustomConstats.hpp, make shure to use a unique adress
	// for example: #define JOURNALGROUP_TEMPLATE 0x300
	// add custom states by using the template state, states have to be registered in the state handler
	// Create global debug variable CURRENT_STATE_TEMPLATE (string[80])
	class CStateTEMPLATE_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// add your custom implementation of the init state here
			
			// for example, access an IO module, has to be globally registered inside the CustomApplication.cpp
			//ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule1 (pEnvironment, "OutputModuleName");
			//ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule1 (pEnvironment, "InputModuleName");
			
			//or access an axis module, has to be globally registered inside the CustomApplication.cpp
			//ioModuleAccess<CMappMotion_SingleLinearAxis> pTemplateAxisModule (pEnvironment, "Axisname");	
			
			//add your custom method for the transition to the next state
			
			//for example, 
			
			//if input 2 of the above accessed IOModule pDigitalInputModule1 "InputModuleName" is true, 
			//set the output 1 of the above accessed IOModule pDigitalOutputModule1 "OutputModuleName" to true 
			//and transition to the next state "example_state"
			//if not, stay in the init state and reset output 1 to false
			
			/*if(pDigitalInputModule1->getInput(2)){		
				pEnvironment->setNextState ("example_state");
				pDigitalOutputModule1->setOutput(1, true);
			}
			else{
				pEnvironment->setNextState ("init");
				pDigitalOutputModule->setOutput(1, false);
			}*/
			
			// ensure pEnvironment->setNextState() is called at least once in all cases
			
		}
	};
	
	// add a new state by:
	//copying this template state, 
	//changing the name in the class name and the getter function getName(), 
	//and registering it in the state handler, 
	class CStateTEMPLATE_Example_State : public CState {
		public:

		std::string getName () 
		{
			return "example_state";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// register IOmodules
			// implement functionality
			// implement transition requirenments to go to the next state or to stay here
			// ensure pEnvironment->setNextState() is calles at least once in all cases
			// pEnvironment->setNextState("init");

		}
	
	};
	
		
	
	class CStateHandlerTEMPLATE : public CStateHandler {
		public:

		CStateHandlerTEMPLATE (CApplication* pApplication)
			// retrieve the journal group variable for this template state machine
			: CStateHandler (pApplication->getJournal (), "template", pApplication->getModuleHandler (), JOURNALGROUP_TEMPLATE)
		{
			// register all states of this state machine here
			addState (std::make_shared<CStateTEMPLATE_Init> ());
			addState (std::make_shared<CStateTEMPLATE_Example_State> ());
		
		}
	
		virtual ~CStateHandlerTEMPLATE ()		
		{
		}
			

	
	};

	void registerTEMPLATEStateHandler (CApplication * pApplication)
	{
		auto pTEMPLATEStateHandler = std::make_shared<CStateHandlerTEMPLATE> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pTEMPLATEStateHandler->setDebugVariables (CURRENT_STATE_TEMPLATE, 80);
		pApplication->registerStateHandler (pTEMPLATEStateHandler);
	}


}

