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
#include "Modules/MappMotion_SingleAxis.hpp"
#include "Modules/IOModule_X20SC0842.hpp"



namespace BuRCPP {
	
	class CStateRecoaterAxes_WaitForInit : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_init");
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			// check for PC signals
			auto pSignalInitRecoateraxisPowder = pEnvironment->checkSignal ("initpowderaxis");
			auto pSignalInitRecoateraxisLinear = pEnvironment->checkSignal ("initlinearaxis");
			
			// get journal variables
			auto bInitRecoateraxisPowder = pEnvironment->getBoolValue(JOURNALVARIABLE_INITRECOATERPOWDERBELT);
			auto bInitRecoateraxisLinear = pEnvironment->getBoolValue(JOURNALVARIABLE_INITRECOATERLINEAR);
			
			if(bInitRecoateraxisPowder && bInitRecoateraxisLinear)
			{
				// wait for PC signal to init
				pEnvironment->setNextState("init");
			}
			else if(pSignalInitRecoateraxisPowder)
			{
				pEnvironment->setBoolValue(JOURNALVARIABLE_INITRECOATERPOWDERBELT, true);
				pSignalInitRecoateraxisPowder->setBoolResult("success", true);
				pSignalInitRecoateraxisPowder->finishProcessing ();
			}
			else if (pSignalInitRecoateraxisLinear)
			{ 
				pEnvironment->setBoolValue(JOURNALVARIABLE_INITRECOATERLINEAR, true);
				pSignalInitRecoateraxisLinear->setBoolResult("success", true);
				pSignalInitRecoateraxisLinear->finishProcessing ();
			}
			else if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState("wait_for_init");
			}
						
		}
	};
	
	class CStateRecoaterAxes_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			if (pRecoaterAxisLinearModule->canSetPower () && pRecoaterAxisPowderbeltModule->canSetPower () ) 
			{
				if(pRecoaterAxisLinearModule->isReferenced () && pRecoaterAxisLinearModule->isReferenced ())
				{
					pRecoaterAxisLinearModule->setPower(true);
					pRecoaterAxisPowderbeltModule->setPower(true);
					pEnvironment->setNextState ("idle");
				}
				else
				{
					pRecoaterAxisLinearModule->setPowerOnAndStartReference ();
					pRecoaterAxisPowderbeltModule->setPowerOnAndStartReference ();
					pEnvironment->setNextState ("wait_for_referencing");	
				}
			
			} 
			else if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
			
		}
	};
	
	
	class CStateRecoaterAxes_Idle : public CState {
		public:

		std::string getName () 
		{
			return "idle";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("idle");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			// check for PC signals
			auto pSignalReferenceAxis = pEnvironment->checkSignal ("referenceaxis");
			auto pSignalSingleAxisMovement = pEnvironment->checkSignal ("triggersingleaxismovement");
			auto pSignalDualAxisMovement = pEnvironment->checkSignal ("recoaterdualaxismovement");
			
			if (pSignalReferenceAxis) 
			{
				bool referenceRecoaterAxisLinear = pSignalReferenceAxis->getBoolParameter("reference_recoateraxis_linear");
				bool referenceRecoaterAxisPowder = pSignalReferenceAxis->getBoolParameter("reference_recoateraxis_powder");
				
				if (referenceRecoaterAxisLinear || referenceRecoaterAxisLinear)
				{
					pEnvironment->setIntegerValue(JOURNALVARIABLE_REFERENCERECOATERPOWDERBELT, referenceRecoaterAxisPowder);	
					pEnvironment->setIntegerValue(JOURNALVARIABLE_REFERENCERECOATERLINEAR, referenceRecoaterAxisLinear);
					pEnvironment->setNextState("manual_referencing");
					pSignalReferenceAxis->finishProcessing (); 
					return;
				}
			}
			if (pSignalSingleAxisMovement) 
			{ 
				int axisid = pSignalSingleAxisMovement->getInt32Parameter("axisid");
				if (axisid == AXISID_RECOATELINEAR)
				{
					pEnvironment->setNextState("linear_axis_movement");
					pEnvironment->setIntegerValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTABSOLUTERELATIVE, pSignalSingleAxisMovement->getInt32Parameter("absoluterelative"));
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTPOSITION, pSignalSingleAxisMovement->getInt32Parameter("position") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTSPEED, pSignalSingleAxisMovement->getInt32Parameter("speed") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTACCELERATION, pSignalSingleAxisMovement->getInt32Parameter("acceleration") * 0.001);
					pSignalSingleAxisMovement->finishProcessing (); 
					return;
				} 
				else if (axisid == AXISID_RECOATERPOWDERBELT)
				{
					pEnvironment->setNextState("powder_belt_axis_movement");
					pEnvironment->setIntegerValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTABSOLUTERELATIVE, pSignalSingleAxisMovement->getInt32Parameter("absoluterelative"));
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTPOSITION, pSignalSingleAxisMovement->getInt32Parameter("position") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTSPEED, pSignalSingleAxisMovement->getInt32Parameter("speed") * 0.001);
					pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTACCELERATION, pSignalSingleAxisMovement->getInt32Parameter("acceleration") * 0.001);
					pSignalSingleAxisMovement->finishProcessing (); 
					return;
				}
			}
			if (pSignalDualAxisMovement)
			{
				pEnvironment->setNextState("dual_axis_movement");
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTSTARTPOSITION, pSignalDualAxisMovement->getInt32Parameter("recoateraxis_linear_start_position") * 0.001);
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTTARGETPOSITION, pSignalDualAxisMovement->getInt32Parameter("recoateraxis_linear_target_position") * 0.001);
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISSPEED, pSignalDualAxisMovement->getInt32Parameter("recoateraxis_linear_speed") * 0.001);
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISSPEED, pSignalDualAxisMovement->getInt32Parameter("recoateraxis_powder_speed") * 0.001);
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISACCELERATION, pSignalDualAxisMovement->getInt32Parameter("recoater_axes_linear_acceleration") * 0.001);
				pEnvironment->setDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISACCELERATION, pSignalDualAxisMovement->getInt32Parameter("recoater_axes_powder_acceleration") * 0.001);
				pSignalDualAxisMovement->finishProcessing (); 
			}
			if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
		}
	};
	
	class CStateRecoaterAxes_LinearAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "linear_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("linear_axis_movement");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			
			if (pRecoaterAxisLinearModule->canMoveAxis ()) 
			{	
				auto absoluterelative = pEnvironment->getInt32Value(JOURNALVARIABLE_RECOATERLINEARMOVEMENTABSOLUTERELATIVE);
				auto position = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTPOSITION);
				auto speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTSPEED);
				auto acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERLINEARMOVEMENTACCELERATION);
			
				if (absoluterelative == AXISMOVEMENT_ABSOLUTE){	
					pRecoaterAxisLinearModule->moveAxisAbsolute (position, speed, acceleration);	
						
				}else if (absoluterelative == AXISMOVEMENT_RELATIVE){
					pRecoaterAxisLinearModule->moveAxisRelative (position, speed, acceleration);
				}
				pEnvironment->setNextState ("wait_for_linear_axis_movement");
			} 
			else if (pRecoaterAxisLinearModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("linear_axis_movement");
			}
		}
	
	};
	
	class CStateRecoaterAxes_WaitForLinearAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_linear_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_linear_axis_movement");
				
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
				
			if (pRecoaterAxisLinearModule->isInPosition())
			{	
				pEnvironment->setNextState ("idle");
			} 
			else if (pRecoaterAxisLinearModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("wait_for_linear_axis_movement");
			}

		}
	
	};
	
	class CStateRecoaterAxes_PowderBeltAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "powder_belt_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("powder_belt_axis_movement");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			if (pRecoaterAxisPowderbeltModule->canMoveAxis ()) 
			{	
				auto absoluterelative = pEnvironment->getInt32Value(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTABSOLUTERELATIVE);
				auto position = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTPOSITION);
				auto speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTSPEED);
				auto acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTACCELERATION);
			
				if (absoluterelative == AXISMOVEMENT_ABSOLUTE){	
					pRecoaterAxisPowderbeltModule->moveAxisAbsolute (position, speed, acceleration);	
						
				}else if (absoluterelative == AXISMOVEMENT_RELATIVE){
					pRecoaterAxisPowderbeltModule->moveAxisRelative (position, speed, acceleration);
				}
				pEnvironment->setNextState ("wait_for_powder_belt_axis_movement");
			} 
			else if (pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("powder_belt_axis_movement");
			}
		}
	
	};
	
	class CStateRecoaterAxes_WaitForPowderBeltAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_powder_belt_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_powder_belt_axis_movement");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
				
			if (pRecoaterAxisPowderbeltModule->isInPosition())
			{	
				pEnvironment->setNextState ("idle");
			} 
			else if (pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("wait_for_powder_belt_axis_movement");
			}

		}
	
	};
	
	class CStateRecoaterAxes_DualAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "dual_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("dual_axis_movement");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			
			if (pRecoaterAxisLinearModule->canMoveAxis () && pRecoaterAxisPowderbeltModule->canMoveAxis ()) 
			{	
				auto recoateraxis_linear_start_position = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTSTARTPOSITION);
				auto recoateraxis_linear_target_position = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTTARGETPOSITION);
				auto recoateraxis_linear_speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISSPEED);
				auto recoateraxis_powder_speed = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISSPEED);
				auto recoater_axes_linear_acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISACCELERATION);
				auto recoater_axes_powder_acceleration = pEnvironment->getDoubleValue(JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISACCELERATION);
				
				pRecoaterAxisLinearModule->moveAxisAbsolute (recoateraxis_linear_target_position, recoateraxis_linear_speed, recoater_axes_linear_acceleration);
				auto recoateraxis_powder_target_position = ((-(recoateraxis_linear_target_position-recoateraxis_linear_start_position))/recoateraxis_linear_speed)*recoateraxis_powder_speed;
				pRecoaterAxisPowderbeltModule->moveAxisRelative (recoateraxis_powder_target_position, recoateraxis_powder_speed, recoater_axes_powder_acceleration);
				
				pEnvironment->setNextState ("wait_for_dual_axis_movement");
			} 
			else if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("dual_axis_movement");
			}
		}
	
	};
	
	class CStateRecoaterAxes_WaitForDualAxisMovement : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_dual_axis_movement";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_dual_axis_movement");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
				
			if (pRecoaterAxisLinearModule->isInPosition() && pRecoaterAxisPowderbeltModule->isInPosition())
			{	
				pEnvironment->setNextState ("idle");
			} 
			else if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else 
			{
				pEnvironment->setNextState ("wait_for_dual_axis_movement");
			}

		}
	
	};

	class CStateRecoaterAxes_ManualReferencing : public CState {
		public:

		std::string getName () 
		{
			return "manual_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			auto referenceRecoaterAxisLinear = pEnvironment->getInt32Value(JOURNALVARIABLE_REFERENCERECOATERLINEAR);
			auto referenceRecoaterAxisPowder = pEnvironment->getInt32Value(JOURNALVARIABLE_REFERENCERECOATERPOWDERBELT);
				
			if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if (referenceRecoaterAxisLinear || referenceRecoaterAxisPowder)
			{
				if (referenceRecoaterAxisLinear)
				{
					pRecoaterAxisLinearModule->startReference ();
				}
				if (referenceRecoaterAxisPowder)
				{
					pRecoaterAxisPowderbeltModule->startReference ();
				}
				pEnvironment->setNextState("wait_for_referencing");
			}
			else
			{
				pEnvironment->setNextState("manual_referencing");
			}
			
		}
	
	};

	class CStateRecoaterAxes_WaitForReferencing : public CState {
		public:

		std::string getName () 
		{
			return "wait_for_referencing";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("wait_for_referencing");
				
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			
			if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else if(pRecoaterAxisLinearModule->isReferenced () && pRecoaterAxisPowderbeltModule->isReferenced ())
			{
				pEnvironment->setNextState("idle");
			}
			else
			{
				pEnvironment->setNextState("wait_for_referencing");
			}

		}
	
	};

	class CStateRecoaterAxes_Error : public CState {
		public:

		std::string getName () 
		{
			return "error";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			pEnvironment->setNextState("error");
			
			// access an IO modules
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisLinearModule (pEnvironment, "RecoaterLinear");
			ioModuleAccess<CMappMotion_SingleLinearAxis> pRecoaterAxisPowderbeltModule (pEnvironment, "RecoaterAxisPowderbelt");
			ioModuleAccess<CIOModule_X20SC0842> pSafeDigitalInputModule115KF53 (pEnvironment, "115KF53"); //acknowledge button
					
			if(pSafeDigitalInputModule115KF53->getInput(2) == 1) //acknowledge button pressed
			{
				pRecoaterAxisLinearModule->resetError ();
				pRecoaterAxisPowderbeltModule->resetError ();
			}
			
			if (pRecoaterAxisLinearModule-> isError () || pRecoaterAxisPowderbeltModule-> isError ())
			{
				pEnvironment->setNextState ("error");
			}
			else
			{
				pEnvironment->setNextState ("init");
			}
								
		}
	
	};
	
		
	
	class CStateHandlerRecoaterAxes : public CStateHandler {
		public:

		CStateHandlerRecoaterAxes (CApplication* pApplication)
			// retrieve the journal group variable
			: CStateHandler (pApplication->getJournal(), "recoater_axes", pApplication->getModuleHandler (), JOURNALGROUP_RECOATER_AXES)
		{
			// register state machines
			addState (std::make_shared<CStateRecoaterAxes_WaitForInit> ());
			addState (std::make_shared<CStateRecoaterAxes_Init> ());
			addState (std::make_shared<CStateRecoaterAxes_Idle> ());
			addState (std::make_shared<CStateRecoaterAxes_LinearAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_WaitForLinearAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_PowderBeltAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_WaitForPowderBeltAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_DualAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_WaitForDualAxisMovement> ());
			addState (std::make_shared<CStateRecoaterAxes_ManualReferencing> ());
			addState (std::make_shared<CStateRecoaterAxes_WaitForReferencing> ());
			addState (std::make_shared<CStateRecoaterAxes_Error> ());
			
			// register journal variables
			registerIntegerValue("recoater_powder_absoluterelative", JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTABSOLUTERELATIVE, 0, 1);
			registerDoubleValue("recoater_powder_position", JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoater_powder_speed", JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTSPEED, 0.0, 1000.0, 20000000);
			registerDoubleValue("recoater_powder_acceleration", JOURNALVARIABLE_RECOATERPOWDERBELTMOVEMENTACCELERATION, 0.0, 1000.0, 20000000);
			registerIntegerValue("recoater_powder_referencing", JOURNALVARIABLE_REFERENCERECOATERPOWDERBELT, 0, 1);
			registerIntegerValue("Recoaterlinear_absoluterelative", JOURNALVARIABLE_RECOATERLINEARMOVEMENTABSOLUTERELATIVE, 0, 1);
			registerDoubleValue("recoaterlinear_position", JOURNALVARIABLE_RECOATERLINEARMOVEMENTPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoaterlinear_speed", JOURNALVARIABLE_RECOATERLINEARMOVEMENTSPEED, 0.0, 1000.0, 20000000);
			registerDoubleValue("recoaterlinear_acceleration", JOURNALVARIABLE_RECOATERLINEARMOVEMENTACCELERATION, 0.0, 1000.0, 20000000);
			registerIntegerValue("recoaterlinear_referencing", JOURNALVARIABLE_REFERENCERECOATERLINEAR, 0, 1);

			registerDoubleValue("recoating_startposition", JOURNALVARIABLE_RECOATERMOVEMENTSTARTPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoating_targetposition", JOURNALVARIABLE_RECOATERMOVEMENTTARGETPOSITION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoating_linearaxisspeed", JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISSPEED, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoating_powderaxisspeed", JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISSPEED, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoating_linearaxisacceleration", JOURNALVARIABLE_RECOATERMOVEMENTLINEARAXISACCELERATION, -1000.0, 1000.0, 20000000);
			registerDoubleValue("recoating_powderaxisacceleration", JOURNALVARIABLE_RECOATERMOVEMENTPOWDERAXISACCELERATION, -1000.0, 1000.0, 20000000);
			
			registerBoolValue("init_powderaxis", JOURNALVARIABLE_INITRECOATERPOWDERBELT);
			registerBoolValue("init_linearaxis", JOURNALVARIABLE_INITRECOATERLINEAR);
				
			// register signals
			auto pSignalInitRecoateraxisPowder = registerSignal ("initpowderaxis", 4, 1000);
			pSignalInitRecoateraxisPowder->addBoolResult ("success", false);
			
			auto pSignalInitRecoateraxisLinear = registerSignal ("initlinearaxis", 4, 1000);
			pSignalInitRecoateraxisLinear->addBoolResult ("success", false);
			
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
			
			auto pSignalRecoaterDualAxisMovement = registerSignal ("recoaterdualaxismovement", 4, 1000);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoateraxis_linear_start_position", 0);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoateraxis_linear_target_position", 0);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoateraxis_linear_speed", 0);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoateraxis_powder_speed", 0);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoater_axes_linear_acceleration", 0);
			pSignalRecoaterDualAxisMovement->addInt32Parameter ("recoater_axes_powder_acceleration", 0);
			pSignalRecoaterDualAxisMovement->addBoolResult ("success", false);
		
		}
	
		virtual ~CStateHandlerRecoaterAxes ()		
		{
		}
			

	
	};
	
	void registerRecoaterAxesStateHandler (CApplication * pApplication)
	{
		auto pRecoaterAxesStateHandler = std::make_shared<CStateHandlerRecoaterAxes> (pApplication);
		//pMainStateHandler->setCycleTime (20);
		pRecoaterAxesStateHandler->setDebugVariables (CURRENT_STATE_RECOATER_AXES, 80);
		pApplication->registerStateHandler (pRecoaterAxesStateHandler);
	}


}

