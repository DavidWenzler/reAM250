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
#include "Modules/IOModule_X20SI8110.hpp"
#include "Modules/IOModule_PLC.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"



namespace BuRCPP {

	class CStateDoor_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20SI8110> pSafetyDigitalInputModule (pEnvironment, "115KF51");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF24");
			
			// ensure door release is false
			pDigitalOutputModule->setOutput(1, false);
			
			// check if the door is closed
			if(pSafetyDigitalInputModule->getInput(3)&& pSafetyDigitalInputModule->getInput(4)){
				// if closed set next state locked_waitforrelease
				pEnvironment->setNextState ("locked_waitforrelease");
			}
			else{
				// if door is open, remain in init
				pEnvironment->setNextState ("init");
			}
			
		}
	};

	class CStateDoor_Locked_WaitForRelease : public CState {
		public:

		std::string getName () 
		{
			return "locked_waitforrelease";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF20");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF24");
			
			// Door open button
			
			auto pReleaseDoorSignal = pEnvironment->checkSignal ("releasedoor");
			auto pSignalLockDoor = pEnvironment->checkSignal ("lockdoor");
					
			if(pDigitalInputModule->getInput(1) || (pReleaseDoorSignal != nullptr)){
				// if door release button is pressed release the door for 10s and set next state unlocked_closed
				pEnvironment->setNextState ("unlocked_closed");
				pDigitalOutputModule->setOutput(1, true); // unlock the door
				fbDelayUnlockDoor.IN = true;
				fbDelayUnlockDoor.PT = 10000;
				TOF(&fbDelayUnlockDoor);
				
				if (pReleaseDoorSignal != nullptr)
					pReleaseDoorSignal->finishProcessing ();
				
			}else if (pSignalLockDoor){
				bool bDoorState = pSignalLockDoor->getBoolParameter ("doorstate");
				if (bDoorState)
				{
					pEnvironment->setNextState ("locked_closed");
				}
				else
				{
					pEnvironment->setNextState ("locked_waitforrelease");	
				}
				pSignalLockDoor->finishProcessing ();

			}
			else{
				// if door is open, remain in init
				pEnvironment->setNextState ("locked_waitforrelease");
			}
		}
	
	};
	
	class CStateDoor_Locked_Closed : public CState {
		public:

		std::string getName () 
		{
			return "locked_closed";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			auto pSignalLockDoor = pEnvironment->checkSignal ("lockdoor");
			
			if (pSignalLockDoor){
				bool bDoorState = pSignalLockDoor->getBoolParameter ("doorstate");
				if (!bDoorState)
				{
					pEnvironment->setNextState ("locked_waitforrelease");
				}
				else
				{
					pEnvironment->setNextState ("locked_closed");	
				}
				pSignalLockDoor->finishProcessing ();

			} else {
				pEnvironment->setNextState ("locked_closed");
			}
			
		}
	
	};

	class CStateDoor_Unlocked_Closed : public CState {
		public:

		std::string getName () 
		{
			return "unlocked_closed";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			
			// access io modules
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule (pEnvironment, "113KF20");
			ioModuleAccess<CIOModule_X20SI8110> pSafetyDigitalInputModule (pEnvironment, "115KF51");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF24");
			
			// reset timer function block input
			fbDelayUnlockDoor.IN = false;
			
			// check if the door was opened
			if (pSafetyDigitalInputModule->getInput(3) == false){
				// if the door was openend set next state unlocked_open
				pEnvironment->setNextState("unlocked_open");
			}
			else{	
				// if the door is closed, check if the door release singal is still holded
				if (fbDelayUnlockDoor.Q){
					// if it is holded, release the door and remain in the state unlocked_closed
					pDigitalOutputModule->setOutput(1, true);
					pEnvironment->setNextState("unlocked_closed");
				}
				else {
					// if the dorr release signal has expired, lock the door and set next state to locked_closed
					pDigitalOutputModule->setOutput(1, false);
					pEnvironment->setNextState("locked_waitforrelease");
				}
			}
				
			TOF(&fbDelayUnlockDoor);		
			//TODO: Include Signal from PC to open the door
			
		}
	
	};
	
	class CStateDoor_Unlocked_Open : public CState {
		public:

		std::string getName () 
		{
			return "unlocked_open";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20SI8110> pSafetyDigitalInputModule (pEnvironment, "115KF51");
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule (pEnvironment, "114KF24");
			
			// if the door is closed, check if the door release singal is still holded
			if (fbDelayUnlockDoor.Q){
				// if it is holded, release the door and remain in the state unlocked_closed
				pDigitalOutputModule->setOutput(1, true);
				pEnvironment->setNextState("unlocked_open");
			} else if (fbDelayUnlockDoor.Q == false){
				// if it is holded, release the door and remain in the state unlocked_closed
				pDigitalOutputModule->setOutput(1, false);
				pEnvironment->setNextState("unlocked_open");
			}
			
			if (pSafetyDigitalInputModule->getInput(3)&& pSafetyDigitalInputModule->getInput(4)){
				pEnvironment->setNextState("locked_waitforrelease");
			}
			else if (pSafetyDigitalInputModule->getInput(3)  == false || pSafetyDigitalInputModule->getInput(4) == false){
				pEnvironment->setNextState("unlocked_open");
			}
		
		TOF(&fbDelayUnlockDoor);
		}
	
	};
	


	class CDoorStateHandler : public CStateHandler {
		public:

		CDoorStateHandler (CApplication* pApplication)
			: CStateHandler (pApplication->getJournal (), "door", pApplication->getModuleHandler (), JOURNALGROUP_DOOR)
		{
				
			//registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF20", &IOMapping_113KF20), JOURNALGROUP_MODULE_GPIO3);
		
			
			addState (std::make_shared<CStateDoor_Init> ());
			addState (std::make_shared<CStateDoor_Locked_WaitForRelease> ());
			addState (std::make_shared<CStateDoor_Unlocked_Open> ());
			addState (std::make_shared<CStateDoor_Unlocked_Closed> ());
			addState (std::make_shared<CStateDoor_Locked_Closed> ());
		
			registerSignal ("releasedoor", 4, 1000);
			
			auto pSignalLockDoor = registerSignal ("lockdoor", 4, 1000);
			pSignalLockDoor->addBoolParameter ("doorstate", false);
			pSignalLockDoor->addBoolResult ("success", false);
		}
	
		virtual ~CDoorStateHandler ()		
		{
		}
			

	
	};


	void registerDoorStateHandler (CApplication * pApplication)
	{
		auto pDoorStateHandler = std::make_shared<CDoorStateHandler> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pDoorStateHandler->setDebugVariables (CURRENT_STATE_DOOR, 80);
		pApplication->registerStateHandler (pDoorStateHandler);
	}


}

