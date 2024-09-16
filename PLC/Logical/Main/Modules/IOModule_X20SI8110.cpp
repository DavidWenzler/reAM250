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

#include "IOModule_X20SI8110.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20SI8110_MODULEOK 1
#define JOURNALVARIABLE_X20SI8110_SERIALNUMBER 2
#define JOURNALVARIABLE_X20SI8110_MODULEID 3
#define JOURNALVARIABLE_X20SI8110_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20SI8110_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20SI8110_SAFEMODULEOK 6
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT01 7
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT02 8
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT03 9
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT04 10
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT05 11
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT06 12
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT07 13
#define JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT08 14
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0102 15
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0304 16
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0506 17
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0708 18
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK01 19
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK02 20
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK03 21
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK04 22
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK05 23
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK06 24
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK07 25
#define JOURNALVARIABLE_X20SI8110_SAFEINPUTOK08 26
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0102 27
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0304 28
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0506 29
#define JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0708 30


namespace BuRCPP {


	CIOModule_X20SI8110::CIOModule_X20SI8110 (const std::string & sName, IOMappingX20SI8110_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20SI8110::~CIOModule_X20SI8110 ()
	{
	}
	
	void CIOModule_X20SI8110::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20SI8110_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20SI8110_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20SI8110_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20SI8110_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20SI8110_FIRMWAREVERSION);
		registerBoolValue ("SafeModuleOK", JOURNALVARIABLE_X20SI8110_SAFEMODULEOK);
		registerBoolValue ("SafeDigitalInput01", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT01);
		registerBoolValue ("SafeDigitalInput02", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT02);
		registerBoolValue ("SafeDigitalInput03", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT03);
		registerBoolValue ("SafeDigitalInput04", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT04);
		registerBoolValue ("SafeDigitalInput05", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT05);
		registerBoolValue ("SafeDigitalInput06", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT06);
		registerBoolValue ("SafeDigitalInput07", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT07);
		registerBoolValue ("SafeDigitalInput08", JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT08);
		registerBoolValue ("SafeTwoChannelInput0102", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0102);
		registerBoolValue ("SafeTwoChannelInput0304", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0304);
		registerBoolValue ("SafeTwoChannelInput0506", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0506);
		registerBoolValue ("SafeTwoChannelInput0708", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0708);
		registerBoolValue ("SafeInputOK01", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK01);
		registerBoolValue ("SafeInputOK02", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK02);
		registerBoolValue ("SafeInputOK03", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK03);
		registerBoolValue ("SafeInputOK04", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK04);
		registerBoolValue ("SafeInputOK05", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK05);
		registerBoolValue ("SafeInputOK06", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK06);
		registerBoolValue ("SafeInputOK07", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK07);
		registerBoolValue ("SafeInputOK08", JOURNALVARIABLE_X20SI8110_SAFEINPUTOK08);
		registerBoolValue ("SafeTwoChannelOK0102", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0102);
		registerBoolValue ("SafeTwoChannelOK0304", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0304);
		registerBoolValue ("SafeTwoChannelOK0506", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0506);
		registerBoolValue ("SafeTwoChannelOK0708", JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0708);
	}

	void CIOModule_X20SI8110::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20SI8110_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20SI8110_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20SI8110_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20SI8110_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20SI8110_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEMODULEOK, m_pMapping->SafeModuleOK);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT01, m_pMapping->SafeDigitalInput01);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT02, m_pMapping->SafeDigitalInput02);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT03, m_pMapping->SafeDigitalInput03);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT04, m_pMapping->SafeDigitalInput04);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT05, m_pMapping->SafeDigitalInput05);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT06, m_pMapping->SafeDigitalInput06);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT07, m_pMapping->SafeDigitalInput07);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEDIGITALINPUT08, m_pMapping->SafeDigitalInput08);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0102, m_pMapping->SafeTwoChannelInput0102);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0304, m_pMapping->SafeTwoChannelInput0304);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0506, m_pMapping->SafeTwoChannelInput0506);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELINPUT0708, m_pMapping->SafeTwoChannelInput0708);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK01, m_pMapping->SafeInputOK01);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK02, m_pMapping->SafeInputOK02);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK03, m_pMapping->SafeInputOK03);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK04, m_pMapping->SafeInputOK04);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK05, m_pMapping->SafeInputOK05);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK06, m_pMapping->SafeInputOK06);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK07, m_pMapping->SafeInputOK07);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFEINPUTOK08, m_pMapping->SafeInputOK08);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0102, m_pMapping->SafeTwoChannelOK0102);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0304, m_pMapping->SafeTwoChannelOK0304);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0506, m_pMapping->SafeTwoChannelOK0506);
		setBoolValue (JOURNALVARIABLE_X20SI8110_SAFETWOCHANNELOK0708, m_pMapping->SafeTwoChannelOK0708);
	}
	
	bool CIOModule_X20SI8110::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20SI8110::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20SI8110::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20SI8110::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20SI8110::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	

	uint16_t CIOModule_X20SI8110::getInput (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->SafeDigitalInput01;
				break;
			
			case 2:
				return m_pMapping->SafeDigitalInput02;
				break;
		
			case 3:
				return m_pMapping->SafeDigitalInput03;
				break;
			
			case 4:
				return m_pMapping->SafeDigitalInput04;
				break;
			
			case 5:
				return m_pMapping->SafeDigitalInput05;
				break;
			
			case 6:
				return m_pMapping->SafeDigitalInput06;
				break;
			
			case 7:
				return m_pMapping->SafeDigitalInput07;
				break;
			
			case 8:
				return m_pMapping->SafeDigitalInput08;
				break;
			default:
				return 0;
				break;
			
				
			
		}
	}
	
	uint16_t CIOModule_X20SI8110::getDualInput (uint32_t nDualChannelNo)
	{
	
		
		switch (nDualChannelNo)
		{
			case 1:
				return m_pMapping->SafeTwoChannelInput0102;
				break;
			
			case 2:
				return m_pMapping->SafeTwoChannelInput0304;
				break;
		
			case 3:
				return m_pMapping->SafeTwoChannelInput0506;
				break;
			
			case 4:
				return m_pMapping->SafeTwoChannelInput0708;
				break;

			default:
				return 0;
				break;
			
				
			
		}
	
	}
	uint16_t CIOModule_X20SI8110::getSafeInputStatus (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->SafeInputOK01;
				break;
			
			case 2:
				return m_pMapping->SafeInputOK02;
				break;
		
			case 3:
				return m_pMapping->SafeInputOK03;
				break;
			
			case 4:
				return m_pMapping->SafeInputOK04;
				break;
			
			case 5:
				return m_pMapping->SafeInputOK05;
				break;
			
			case 6:
				return m_pMapping->SafeInputOK06;
				break;
			
			case 7:
				return m_pMapping->SafeInputOK07;
				break;
			
			case 8:
				return m_pMapping->SafeInputOK08;
				break;
			default:
				return 0;
				break;
			
				
			
		}
	}
	
	uint16_t CIOModule_X20SI8110::getSafeDualInputStatus (uint32_t nDualChannelNo)
	{
		switch (nDualChannelNo)
		{
			case 1:
				return m_pMapping->SafeTwoChannelOK0102;
				break;
			
			case 2:
				return m_pMapping->SafeTwoChannelOK0304;
				break;
		
			case 3:
				return m_pMapping->SafeTwoChannelOK0506;
				break;
			
			case 4:
				return m_pMapping->SafeTwoChannelOK0708;
				break;

			default:
				return 0;
				break;
			
		}
	}


}