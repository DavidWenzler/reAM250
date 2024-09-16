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

// Include modules specific to your I/O and motion setup
#include "Modules/IOModule_X20AT6402.hpp"
#include "Modules/IOModule_X20AO4622.hpp"
#include "Modules/IOModule_X20AI4622.hpp"
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20DI9371.hpp"
#include "Modules/IOModule_X20SI8110.hpp"
#include "Modules/IOModule_X20SO6300.hpp"
#include "Modules/IOModule_X20SC0842.hpp"
#include "Modules/IOModule_PLC.hpp"
#include "Modules/MappMotion_SingleAxis.hpp"

#include "CustomConstants.hpp"

namespace BuRCPP
{
	// Import custom state machines and TCP command handlers
	extern void registerDoorStateHandler (CApplication * pApplication);
	extern void registerHeaterStateHandler (CApplication * pApplication);
	extern void registerTCPHandlers (CApplication * pApplication);
	extern void registerBuildPlatformAxisStateHandler (CApplication * pApplication);
	extern void registerPowderReservoirAxisStateHandler (CApplication * pApplication);
	extern void registerRecoaterAxesStateHandler (CApplication * pApplication);
	extern void registerMainStateHandler (CApplication * pApplication);
	extern void registerO2SensorStateHandler (CApplication * pApplication);
	extern void registerGasCirculationStateHandler (CApplication * pApplication);
	extern void registerVacuumSystemStateHandler (CApplication * pApplication);
	extern void registerOxygenControlStateHandler (CApplication * pApplication);

	/**
	 * @brief Registers the handlers and modules..
	 * This method is responsible for initializing and registering all the necessary I/O and
	 * motion control modules, as well as the state machine handlers.
	 */
	void CCustomApplication::registerHandlers ()
	{
		// Register the main PLC module
		registerModule (std::make_shared<CIOModule_PLC> ("5APC2100_BY44_000", &IOMapping_PLC), JOURNALGROUP_MODULE_PLC);
		
		// Register analoge IO modules
		registerModule (std::make_shared<CIOModule_X20AT6402> ("112KF11", &IOMapping_112KF11), JOURNALGROUP_MODULE_GPIO1);
		registerModule (std::make_shared<CIOModule_X20AO4622> ("112KF12", &IOMapping_112KF12), JOURNALGROUP_MODULE_GPIO2);
		registerModule (std::make_shared<CIOModule_X20AO4622> ("112KF13", &IOMapping_112KF13), JOURNALGROUP_MODULE_GPIO3);
		registerModule (std::make_shared<CIOModule_X20AI4622> ("112KF15", &IOMapping_112KF15), JOURNALGROUP_MODULE_GPIO5);
		
		// Initialize AI module with specific channel types
		auto pModule112KF14 = std::make_shared<CIOModule_X20AI4622> ("112KF14", &IOMapping_112KF14);
		pModule112KF14->setChannelType(1, eIOChannelType_X20AI4622::mtCurrent4to20mA);
		pModule112KF14->setChannelType(2, eIOChannelType_X20AI4622::mtCurrent4to20mA);
		registerModule (pModule112KF14, JOURNALGROUP_MODULE_GPIO4);
		
		// Register digital IO modules
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF16", &IOMapping_113KF16), JOURNALGROUP_MODULE_GPIO6);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF17", &IOMapping_113KF17), JOURNALGROUP_MODULE_GPIO7);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF18", &IOMapping_113KF18), JOURNALGROUP_MODULE_GPIO8);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF19", &IOMapping_113KF19), JOURNALGROUP_MODULE_GPIO9);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF20", &IOMapping_113KF20), JOURNALGROUP_MODULE_GPIO10);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF21", &IOMapping_113KF21), JOURNALGROUP_MODULE_GPIO11);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF22", &IOMapping_113KF22), JOURNALGROUP_MODULE_GPIO12);
		registerModule (std::make_shared<CIOModule_X20DI6371> ("113KF23", &IOMapping_113KF23), JOURNALGROUP_MODULE_GPIO13);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF24", &IOMapping_114KF24), JOURNALGROUP_MODULE_GPIO14);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF25", &IOMapping_114KF25), JOURNALGROUP_MODULE_GPIO15);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF26", &IOMapping_114KF26), JOURNALGROUP_MODULE_GPIO16);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF27", &IOMapping_114KF27), JOURNALGROUP_MODULE_GPIO17);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF28", &IOMapping_114KF28), JOURNALGROUP_MODULE_GPIO18);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF29", &IOMapping_114KF29), JOURNALGROUP_MODULE_GPIO19);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF30", &IOMapping_114KF30), JOURNALGROUP_MODULE_GPIO20);
		registerModule (std::make_shared<CIOModule_X20DO6322> ("114KF31", &IOMapping_114KF31), JOURNALGROUP_MODULE_GPIO21);
				
		// Register safety modules
		registerModule (std::make_shared<CIOModule_X20SI8110> ("115KF51", &IOMapping_115KF51), JOURNALGROUP_MODULE_SAFEIO1);
		registerModule (std::make_shared<CIOModule_X20SO6300> ("115KF52", &IOMapping_115KF52), JOURNALGROUP_MODULE_SAFEIO2);
		registerModule (std::make_shared<CIOModule_X20SC0842> ("115KF53", &IOMapping_115KF53), JOURNALGROUP_MODULE_SAFEIO3);

		// Register axis modules for motion control
		auto pBuildPlatformAxisModule = std::make_shared<CMappMotion_SingleLinearAxis> ("BuildPlatformAxis", &axBuildPlatform);
		registerModule (pBuildPlatformAxisModule, JOURNALGROUP_MODULE_BUILDPLATFORMAXIS);
		
		// Function block and parameter block for the Build Platform Axis
		fbBuildPlatformAxis = (MpAxisBasic_typ*) pBuildPlatformAxisModule->getFunctionBlockPtr ();
		parBuildPlatformAxis = (MpAxisBasicParType*) pBuildPlatformAxisModule->getParameterBlockPtr ();
			
		auto pReservoirAxisModule = std::make_shared<CMappMotion_SingleRotationalAxis> ("PowderReservoirAxis", &axPowderReservoir);
		registerModule (pReservoirAxisModule, JOURNALGROUP_MODULE_POWDERRESERVOIRAXIS);
		
		// Function block and parameter block for the Powder Reservoir Axis
		fbPowderReservoirAxis = (MpAxisBasic_typ*) pReservoirAxisModule->getFunctionBlockPtr ();
		parPowderReservoirAxis = (MpAxisBasicParType*) pReservoirAxisModule->getParameterBlockPtr ();
				
		auto pRecoaterAxisPowderbeltModule = std::make_shared<CMappMotion_SingleLinearAxis> ("RecoaterAxisPowderbelt", &axRecoaterPowderBelt);
		registerModule (pRecoaterAxisPowderbeltModule, JOURNALGROUP_MODULE_RECOATERAXISPOWDERBELT);
		
		// Function block and parameter block for the Recoater Axis Powder Belt
		fbRecoaterAxisPowderbelt = (MpAxisBasic_typ*) pRecoaterAxisPowderbeltModule->getFunctionBlockPtr ();
		parRecoaterAxisPowderbelt = (MpAxisBasicParType*) pRecoaterAxisPowderbeltModule->getParameterBlockPtr ();
		
		auto pRecoaterAxisLinearModule = std::make_shared<CMappMotion_SingleLinearAxis> ("RecoaterLinear", &axRecoater);
		registerModule (pRecoaterAxisLinearModule, JOURNALGROUP_MODULE_RECOATERAXISLINEAR); 
		
		// Function block and parameter block for the Recoater Axis Linear
		fbRecoaterAxisLinear = (MpAxisBasic_typ*) pRecoaterAxisLinearModule->getFunctionBlockPtr ();
		parRecoaterAxisLinear = (MpAxisBasicParType*) pRecoaterAxisLinearModule->getParameterBlockPtr (); 
		
		// Register state handlers and TCP handlers for the application
		registerTCPHandlers (this);		
		registerDoorStateHandler (this);
		registerHeaterStateHandler (this);
		registerBuildPlatformAxisStateHandler (this);
		registerPowderReservoirAxisStateHandler (this);
		registerRecoaterAxesStateHandler (this); 
		registerMainStateHandler (this);
		registerO2SensorStateHandler (this);
		registerGasCirculationStateHandler(this);
		registerVacuumSystemStateHandler(this);
		registerOxygenControlStateHandler(this);
	}
	
}
