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
	
	class CStatePowderReservoirAxis_WaitForInit : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			// check for PC signals
			auto pSignalInitPowderreservoirAxis = pEnvironment->checkSignal ("initaxis");
			
			if(pSignalInitPowderreservoirAxis)
			{ // wait for PC signal to init
				pSignalInitPowderreservoirAxis->setBoolResult("success", true);
				pSignalInitPowderreservoirAxis->finishProcessing ();
				pEnvironment->setNextState("init");
			}
			else if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState("wait_for_init");
			}
						
		}
	};
	
	class CStatePowderReservoirAxis_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			
			if (pReservoirAxisModule->canSetPower ()) 
			{
				if(pReservoirAxisModule->isReferenced ())
				{
					pReservoirAxisModule->setPower(true);
					pEnvironment->setNextState ("idle");
				}
				else
				{
					pReservoirAxisModule->setPowerOnAndStartReference ();
					pEnvironment->setNextState ("wait_for_referencing");	
				}
			} 
			else if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
			
		}
	};
	
	
	class CStatePowderReservoirAxis_Idle : public CState {
		public:

		std::string getName () 
		{
			return "idle";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("idle");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			// check for PC signals
			auto pSignalReferenceAxis = pEnvironment->checkSignal ("referenceaxis");
			auto pSignalSingleAxisMovement = pEnvironment->checkSignal ("triggersingleaxismovement");
			
			if (pSignalReferenceAxis) 
			{
				bool referenceReservoirAxis = pSignalReferenceAxis->getBoolParameter("reference_powderreservoir");
				
				if (referenceReservoirAxis)
				{
					pEnvironment->setIntegerValue(JOURNALVARIABLE_REFERENCEPOWDERRESERVOIR, referenceReservoirAxis);
					pSignalReferenceAxis->finishProcessing ();
					pEnvironment->setNextState("manual_referencing");
					return;
				}
			}
			if (pSignalSingleAxisMovement) 
			{
				int axisid = pSignalSingleAxisMovement->getInt32Parameter("axisid");
				if (axisid == AXISID_POWDERRESERVOIR)
				{
					pEnvironment->setNextState("axis_movement");
					pEnvironment->setIntegerValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTABSOLUTERELATIVE, pSignalSingleAxisMovement->getInt32Parameter("absoluterelative"));
					pEnvironment->setDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTPOSITION, pSignalSingleAxisMovement->getInt32Parameter("position") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTSPEED, pSignalSingleAxisMovement->getInt32Parameter("speed") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTACCELERATION, pSignalSingleAxisMovement->getInt32Parameter("acceleration") * 0.001);
					pSignalSingleAxisMovement->finishProcessing ();
					return;
				}
			}
			if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
		}
	};
	
	class CStatePowderReservoirAxis_AxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("axis_movement");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			if (true)//(pReservoirAxisModule->canMoveAxis ()) 
			{	
				auto absoluterelative = pEnvironment->getInt32Value(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTABSOLUTERELATIVE);
				auto position = pEnvironment->getDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTPOSITION);
				auto speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTSPEED);
				auto acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTACCELERATION);
			
				if (absoluterelative == AXISMOVEMENT_ABSOLUTE){	
					pReservoirAxisModule->moveAxisAbsolute (position, speed, acceleration);	
						
				}else if (absoluterelative == AXISMOVEMENT_RELATIVE){
					pReservoirAxisModule->moveAxisRelative (position, speed, acceleration);
				}
				pEnvironment->setNextState ("wait_for_axis_movement");
			} 
			else if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("axis_movement");
			}
		}
	
	};
	
	class CStatePowderReservoirAxis_WaitForAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_axis_movement");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
				
			if (pReservoirAxisModule->isInPosition())
			{	
				pEnvironment->setNextState ("idle");
			} 
			else if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("wait_for_axis_movement");
			}

		}
	
	};

	class CStatePowderReservoirAxis_ManualReferencing : public CState {
		public:

		std::string getName () 
		{
			return "manual_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			auto referenceReservoirAxis = pEnvironment->getInt32Value(JOURNALVARIABLE_REFERENCEPOWDERRESERVOIR);
			
			if (pReservoirAxisModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if(referenceReservoirAxis)
			{
				pReservoirAxisModule->startReference ();
				pEnvironment->setNextState("wait_for_referencing");
			}
			else
			{
				pEnvironment->setNextState("manual_referencing");
			}

		}
	
	};

	class CStatePowderReservoirAxis_WaitForReferencing : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_referencing");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			
			if (pReservoirAxisModule->isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if(pReservoirAxisModule->isReferenced ())
			{
				pEnvironment->setNextState("idle");
			}
			else
			{
				pEnvironment->setNextState("wait_for_referencing");
			}

		}
	
	};

	class CStatePowderReservoirAxis_Error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("error");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleRotationalAxis> pReservoirAxisModule (pEnvironment, "PowderReservoirAxis");
			ioModuleAccess<CIOModule_X20SC0842> pSafeDigitalInputModule115KF53 (pEnvironment, "115KF53"); //acknowledge button
					
			if(pSafeDigitalInputModule115KF53->getInput(2) == 1) //acknowledge button pressed
			{
				pReservoirAxisModule->resetError ();
			}
			
			if (pReservoirAxisModule->isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
					
		}
	
	};
	
		
	
	class CStateHandlerPowderReservoirAxis : public CStateHandler {
		public:

		CStateHandlerPowderReservoirAxis (CApplication* pApplication)
			// retrieve the journal group variable
			: CStateHandler (pApplication->getJournal (), "powder_reservoir_axis", pApplication->getModuleHandler (), JOURNALGROUP_POWDER_RESERVOIR_AXIS)
		{
			// register state machines
			addState (std::make_shared<CStatePowderReservoirAxis_WaitForInit> ());
			addState (std::make_shared<CStatePowderReservoirAxis_Init> ());
			addState (std::make_shared<CStatePowderReservoirAxis_Idle> ());
			addState (std::make_shared<CStatePowderReservoirAxis_AxisMovement> ());
			addState (std::make_shared<CStatePowderReservoirAxis_WaitForAxisMovement> ());
			addState (std::make_shared<CStatePowderReservoirAxis_ManualReferencing> ());
			addState (std::make_shared<CStatePowderReservoirAxis_WaitForReferencing> ());
			addState (std::make_shared<CStatePowderReservoirAxis_Error> ());
			
			// register journal variables
			registerIntegerValue("powderreservoir_absoluterelative", JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTABSOLUTERELATIVE, 0, 1);
			registerDoubleValue("powderreservoir_position", JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("powderreservoir_speed", JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTSPEED, 0.0, 1000.0, 20000000);
			registerDoubleValue("powderreservoir_acceleration", JOURNALVARIABLE_POWDERRESERVOIRMOVEMENTACCELERATION, 0.0, 1000.0, 20000000);
			registerIntegerValue("powderreservoir_referencing", JOURNALVARIABLE_REFERENCEPOWDERRESERVOIR, 0, 1);
		
			
					
			// register signals
			auto pSignalInitPowderreservoirAxis = registerSignal ("initaxis", 4, 1000);
			pSignalInitPowderreservoirAxis->addBoolResult ("success", false);
			
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
		
		}
	
		virtual ~CStateHandlerPowderReservoirAxis ()		
		{
		}
			

	
	};

	void registerPowderReservoirAxisStateHandler (CApplication * pApplication)
	{
		auto pPowderReservoirAxisStateHandler = std::make_shared<CStateHandlerPowderReservoirAxis> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pPowderReservoirAxisStateHandler->setDebugVariables (CURRENT_STATE_RESERVOIR_AXIS, 80);
		pApplication->registerStateHandler (pPowderReservoirAxisStateHandler);
	}


}

