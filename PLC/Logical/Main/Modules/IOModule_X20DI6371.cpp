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

#include "IOModule_X20DI6371.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20DI6371_MODULEOK 1
#define JOURNALVARIABLE_X20DI6371_SERIALNUMBER 2
#define JOURNALVARIABLE_X20DI6371_MODULEID 3
#define JOURNALVARIABLE_X20DI6371_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20DI6371_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT01 6
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT02 7
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT03 8
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT04 9
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT05 10
#define JOURNALVARIABLE_X20DI6371_DIGITALINPUT06 11



namespace BuRCPP {


	CIOModule_X20DI6371::CIOModule_X20DI6371 (const std::string & sName, IOMappingX20DI6371_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20DI6371::~CIOModule_X20DI6371 ()
	{
	}
	
	void CIOModule_X20DI6371::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20DI6371_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20DI6371_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20DI6371_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20DI6371_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20DI6371_FIRMWAREVERSION);
		registerBoolValue ("DigitalInput01", JOURNALVARIABLE_X20DI6371_DIGITALINPUT01);
		registerBoolValue ("DigitalInput02", JOURNALVARIABLE_X20DI6371_DIGITALINPUT02);
		registerBoolValue ("DigitalInput03", JOURNALVARIABLE_X20DI6371_DIGITALINPUT03);
		registerBoolValue ("DigitalInput04", JOURNALVARIABLE_X20DI6371_DIGITALINPUT04);
		registerBoolValue ("DigitalInput05", JOURNALVARIABLE_X20DI6371_DIGITALINPUT05);
		registerBoolValue ("DigitalInput06", JOURNALVARIABLE_X20DI6371_DIGITALINPUT06);

	}

	void CIOModule_X20DI6371::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20DI6371_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20DI6371_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20DI6371_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20DI6371_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20DI6371_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT01, m_pMapping->DigitalInput01);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT02, m_pMapping->DigitalInput02);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT03, m_pMapping->DigitalInput03);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT04, m_pMapping->DigitalInput04);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT05, m_pMapping->DigitalInput05);
		setBoolValue (JOURNALVARIABLE_X20DI6371_DIGITALINPUT06, m_pMapping->DigitalInput06);
	}
		
	bool CIOModule_X20DI6371::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20DI6371::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20DI6371::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20DI6371::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20DI6371::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	

	uint16_t CIOModule_X20DI6371::getInput (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->DigitalInput01;
				break;
			
			case 2:
				return m_pMapping->DigitalInput02;
				break;
		
			case 3:
				return m_pMapping->DigitalInput03;
				break;
			
			case 4:
				return m_pMapping->DigitalInput04;
				break;
			
			case 5:
				return m_pMapping->DigitalInput05;
				break;
			
			case 6:
				return m_pMapping->DigitalInput06;
				break;
			default:
				return 0;
				break;
			
				
			
		}
	}
	
	

}