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
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20SC0842.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"



namespace BuRCPP {
	
	class CStateBuildPlatformAxis_WaitForInit : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			
			// check for PC signals
			auto pSignalInitPlatformAxis = pEnvironment->checkSignal ("initaxis");
			
			if(pSignalInitPlatformAxis)
			{ // wait for PC signal to init
				pSignalInitPlatformAxis->setBoolResult("success", true);
				pSignalInitPlatformAxis->finishProcessing ();
				pEnvironment->setNextState("init");
			}
			else if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState("wait_for_init");
			}
						
		}
	};

	class CStateBuildPlatformAxis_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			
			if (pBuildPlatformAxisModule->canSetPower ()) 
			{
				if(pBuildPlatformAxisModule->isReferenced ())
				{
					pBuildPlatformAxisModule->setPower(true);
					pEnvironment->setNextState ("idle");
				}
				else
				{
					pBuildPlatformAxisModule->setPowerOnAndStartReference ();
					pEnvironment->setNextState ("wait_for_referencing");	
				}
				
			} 
			else if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
			
		}
	};
	
	
	class CStateBuildPlatformAxis_Idle : public CState {
		public:

		std::string getName () 
		{
			return "idle";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("idle");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			
			// check for PC signals
			auto pSignalReferenceAxis = pEnvironment->checkSignal ("referenceaxis");
			auto pSignalSingleAxisMovement = pEnvironment->checkSignal ("triggersingleaxismovement");
			auto pSignalAbsoluteSwitchReferencing = pEnvironment->checkSignal ("absoluteswitchreferencing");
			
			if (pSignalReferenceAxis) 
			{
				bool referencebuildplatformaxis = pSignalReferenceAxis->getBoolParameter("reference_platform");
				
				if (referencebuildplatformaxis)
				{
					pEnvironment->setIntegerValue(JOURNALVARIABLE_REFERENCEBUILDPLATFORM, referencebuildplatformaxis);
					pEnvironment->setNextState("manual_referencing");
					pSignalReferenceAxis->finishProcessing ();
					return;
				}
			}
			if (pSignalAbsoluteSwitchReferencing) 
			{
				pEnvironment->setNextState("manual_referencing");
				pSignalAbsoluteSwitchReferencing->finishProcessing ();
				return;
			}
			if (pSignalSingleAxisMovement) 
			{
				int axisid = pSignalSingleAxisMovement->getInt32Parameter("axisid");
				if (axisid == AXISID_BUILDPLATFORM)
				{
					pEnvironment->setNextState("axis_movement");
					pEnvironment->setIntegerValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTABSOLUTERELATIVE, pSignalSingleAxisMovement->getInt32Parameter("absoluterelative"));
					pEnvironment->setDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTPOSITION, pSignalSingleAxisMovement->getInt32Parameter("position") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTSPEED, pSignalSingleAxisMovement->getInt32Parameter("speed") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTACCELERATION, pSignalSingleAxisMovement->getInt32Parameter("acceleration") * 0.001);
					pSignalSingleAxisMovement->finishProcessing ();
					return;
				}
			}
			if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
		}
	};
	

	class CStateBuildPlatformAxis_AxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("axis_movement");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
		
			if (pBuildPlatformAxisModule->canMoveAxis ()) 
			{	
				auto absoluterelative = pEnvironment->getInt32Value(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTABSOLUTERELATIVE);
				auto position = pEnvironment->getDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTPOSITION);
				auto speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTSPEED);
				auto acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_BUILDPLATFORMMOVEMENTACCELERATION);
			
				if (absoluterelative == AXISMOVEMENT_ABSOLUTE){	
					pBuildPlatformAxisModule->moveAxisAbsolute (position, speed, acceleration);	
						
				}else if (absoluterelative == AXISMOVEMENT_RELATIVE){
					pBuildPlatformAxisModule->moveAxisRelative (position, speed, acceleration);
				}
				pEnvironment->setNextState ("wait_for_axis_movement");
			} 
			else if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("axis_movement");
			}
		}
	
	};

	class CStateBuildPlatformAxis_WaitForAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_axis_movement");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
				
			if (pBuildPlatformAxisModule->isInPosition())
			{	
				pEnvironment->setNextState ("idle");
			} 
			else if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
			pEnvironment->setNextState ("wait_for_axis_movement");
			}

		}
	
	};

	class CStateBuildPlatformAxis_ManualReferencing : public CState {
		public:

		std::string getName () 
		{
			return "manual_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			
			auto referencePlatformAxis = pEnvironment->getInt32Value(JOURNALVARIABLE_REFERENCEBUILDPLATFORM);
			
			if (pBuildPlatformAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if (referencePlatformAxis)
			{
				pBuildPlatformAxisModule->startReference ();
				pEnvironment->setNextState("wait_for_referencing");
			}
			else
			{
				pEnvironment->setNextState("manual_referencing");
			}

		}
	
	};

	class CStateBuildPlatformAxis_WaitForReferencing : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_referencing");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			
			if (pBuildPlatformAxisModule->isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if(pBuildPlatformAxisModule->isReferenced ())
			{
				pEnvironment->setNextState("idle");
			}
			else
			{
				pEnvironment->setNextState("wait_for_referencing");
			}

		}
	
	};

	class CStateBuildPlatformAxis_Error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("error");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pBuildPlatformAxisModule (pEnvironment, "BuildPlatformAxis");
			ioModuleAccess<CIOModule_X20SC0842> pSafeDigitalInputModule115KF53 (pEnvironment, "115KF53"); //acknowledge button
					
			if(pSafeDigitalInputModule115KF53->getInput(2) == 1) //acknowledge button pressed
			{
				pBuildPlatformAxisModule->resetError ();
			}
			
			if (pBuildPlatformAxisModule->isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
					
		}
	
	};
	
		
	
	class CStateHandlerBuildPlatformAxis : public CStateHandler {
		public:

		CStateHandlerBuildPlatformAxis (CApplication* pApplication)
			// retrieve the journal group variable
			: CStateHandler (pApplication->getJournal (), "build_platform_axis", pApplication->getModuleHandler (), JOURNALGROUP_BUILD_PLATFORM_AXIS)
			
		{
			// register state machines
			addState (std::make_shared<CStateBuildPlatformAxis_WaitForInit> ());
			addState (std::make_shared<CStateBuildPlatformAxis_Init> ());
			addState (std::make_shared<CStateBuildPlatformAxis_Idle> ());
			addState (std::make_shared<CStateBuildPlatformAxis_AxisMovement> ());
			addState (std::make_shared<CStateBuildPlatformAxis_WaitForAxisMovement> ());
			addState (std::make_shared<CStateBuildPlatformAxis_ManualReferencing> ());
			addState (std::make_shared<CStateBuildPlatformAxis_WaitForReferencing> ());
			addState (std::make_shared<CStateBuildPlatformAxis_Error> ());
			
			// register journal variables
			registerIntegerValue("platform_absoluterelative", JOURNALVARIABLE_BUILDPLATFORMMOVEMENTABSOLUTERELATIVE, 0, 1);
			registerDoubleValue("platform_position", JOURNALVARIABLE_BUILDPLATFORMMOVEMENTPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("platform_speed", JOURNALVARIABLE_BUILDPLATFORMMOVEMENTSPEED, 0.0, 1000.0, 20000000);
			registerDoubleValue("platform_acceleration", JOURNALVARIABLE_BUILDPLATFORMMOVEMENTACCELERATION, 0.0, 1000.0, 20000000);
			registerIntegerValue("platform_referencing", JOURNALVARIABLE_REFERENCEBUILDPLATFORM, 0, 1);

			
			// register signals
			
			auto pSignalInitPlatformAxis = registerSignal ("initaxis", 4, 1000);
			pSignalInitPlatformAxis->addBoolResult ("success", false);
			
			auto pSignalSingleAxisMovement = registerSignal ("triggersingleaxismovement", 4, 1000);
			pSignalSingleAxisMovement->addInt32Parameter ("axisid", 0);
			pSignalSingleAxisMovement->addInt32Parameter ("absoluterelative", 0);
			pSignalSingleAxisMovement->addInt32Parameter ("position", 0);
			pSignalSingleAxisMovement->addInt32Parameter ("speed", 0);
			pSignalSingleAxisMovement->addInt32Parameter ("acceleration", 0);
			pSignalSingleAxisMovement->addBoolResult ("success", false);
		
			auto pSignalReferenceAxis = registerSignal ("referenceaxis", 4, 1000);
			pSignalReferenceAxis->addBoolParameter ("reference_platform", false);
			pSignalReferenceAxis->addBoolParameter ("reference_powderreservoir", false);
			pSignalReferenceAxis->addBoolParameter ("reference_recoateraxis_powder", false);
			pSignalReferenceAxis->addBoolParameter ("reference_recoateraxis_linear", false);
			pSignalReferenceAxis->addBoolResult ("success", false);
			
			auto pSignalAbsoluteSwitchReferencing = registerSignal ("absoluteswitchreferencing", 4, 1000);
			pSignalAbsoluteSwitchReferencing->addBoolResult ("success", false);
		
		}
	
		virtual ~CStateHandlerBuildPlatformAxis ()		
		{
		}
			

	
	};

	void registerBuildPlatformAxisStateHandler (CApplication * pApplication)
	{
		auto pBuildPlatformAxisStateHandler = std::make_shared<CStateHandlerBuildPlatformAxis> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pBuildPlatformAxisStateHandler->setDebugVariables (CURRENT_STATE_PLATFORM_AXIS, 80);
		pApplication->registerStateHandler (pBuildPlatformAxisStateHandler);
		
	}


}

