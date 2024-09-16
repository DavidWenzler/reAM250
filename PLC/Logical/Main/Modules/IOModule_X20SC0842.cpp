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
#include "IOModule_X20SC0842.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20SC0842_MODULEOK 1
#define JOURNALVARIABLE_X20SC0842_SERIALNUMBER 2
#define JOURNALVARIABLE_X20SC0842_MODULEID 3
#define JOURNALVARIABLE_X20SC0842_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20SC0842_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20SC0842_SAFEMODULEOK 6
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT01 7
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT02 8
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT03 9
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT04 10
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT05 11
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT06 12
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK01 13
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK02 14
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK03 15
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK04 16
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK05 17
#define JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK06 18
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT01 19
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT02 20
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT03 21
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT04 22
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT05 23
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT06 24
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT07 25
#define JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT08 26
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0102 27
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0304 28
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0506 29
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0708 30
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK01 31
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK02 32
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK03 33
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK04 34
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK05 35
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK06 36
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK07 37
#define JOURNALVARIABLE_X20SC0842_SAFEINPUTOK08 38
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0102 39
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0304 40
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0506 41
#define JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0708 42



namespace BuRCPP {


	CIOModule_X20SC0842::CIOModule_X20SC0842 (const std::string & sName, IOMappingX20SC0842_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20SC0842::~CIOModule_X20SC0842 ()
	{
	}
	
	void CIOModule_X20SC0842::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20SC0842_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20SC0842_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20SC0842_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20SC0842_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20SC0842_FIRMWAREVERSION);
		registerBoolValue ("SafeModuleOK", JOURNALVARIABLE_X20SC0842_SAFEMODULEOK);
		registerBoolValue ("SafeDigitalOutput01", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT01);
		registerBoolValue ("SafeDigitalOutput02", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT02);
		registerBoolValue ("SafeDigitalOutput03", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT03);
		registerBoolValue ("SafeDigitalOutput04", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT04);
		registerBoolValue ("SafeDigitalOutput05", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT05);
		registerBoolValue ("SafeDigitalOutput06", JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT06);
		registerBoolValue ("SafeOutputOK01", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK01);
		registerBoolValue ("SafeOutputOK02", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK02);
		registerBoolValue ("SafeOutputOK03", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK03);
		registerBoolValue ("SafeOutputOK04", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK04);
		registerBoolValue ("SafeOutputOK05", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK05);
		registerBoolValue ("SafeOutputOK06", JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK06);
		registerBoolValue ("SafeDigitalInput01", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT01);
		registerBoolValue ("SafeDigitalInput02", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT02);
		registerBoolValue ("SafeDigitalInput03", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT03);
		registerBoolValue ("SafeDigitalInput04", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT04);
		registerBoolValue ("SafeDigitalInput05", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT05);
		registerBoolValue ("SafeDigitalInput06", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT06);
		registerBoolValue ("SafeDigitalInput07", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT07);
		registerBoolValue ("SafeDigitalInput08", JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT08);
		registerBoolValue ("SafeTwoChannelInput0102", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0102);
		registerBoolValue ("SafeTwoChannelInput0304", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0304);
		registerBoolValue ("SafeTwoChannelInput0506", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0506);
		registerBoolValue ("SafeTwoChannelInput0708", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0708);
		registerBoolValue ("SafeInputOK01", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK01);
		registerBoolValue ("SafeInputOK02", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK02);
		registerBoolValue ("SafeInputOK03", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK03);
		registerBoolValue ("SafeInputOK04", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK04);
		registerBoolValue ("SafeInputOK05", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK05);
		registerBoolValue ("SafeInputOK06", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK06);
		registerBoolValue ("SafeInputOK07", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK07);
		registerBoolValue ("SafeInputOK08", JOURNALVARIABLE_X20SC0842_SAFEINPUTOK08);
		registerBoolValue ("SafeTwoChannelOK0102", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0102);
		registerBoolValue ("SafeTwoChannelOK0304", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0304);
		registerBoolValue ("SafeTwoChannelOK0506", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0506);
		registerBoolValue ("SafeTwoChannelOK0708", JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0708);
	}

	void CIOModule_X20SC0842::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20SC0842_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20SC0842_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20SC0842_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20SC0842_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20SC0842_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEMODULEOK, m_pMapping->SafeModuleOK);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT01, m_pMapping->PhysicalStateOutput01);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT02, m_pMapping->PhysicalStateOutput02);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT03, m_pMapping->PhysicalStateOutput03);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT04, m_pMapping->PhysicalStateOutput04);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT05, m_pMapping->PhysicalStateOutput05);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALOUTPUT06, m_pMapping->PhysicalStateOutput06);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK01, m_pMapping->SafeOutputOK01);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK02, m_pMapping->SafeOutputOK02);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK03, m_pMapping->SafeOutputOK03);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK04, m_pMapping->SafeOutputOK04);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK05, m_pMapping->SafeOutputOK05);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEOUTPUTOK06, m_pMapping->SafeOutputOK06);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT01, m_pMapping->SafeDigitalInput01);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT02, m_pMapping->SafeDigitalInput02);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT03, m_pMapping->SafeDigitalInput03);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT04, m_pMapping->SafeDigitalInput04);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT05, m_pMapping->SafeDigitalInput05);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT06, m_pMapping->SafeDigitalInput06);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT07, m_pMapping->SafeDigitalInput07);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEDIGITALINPUT08, m_pMapping->SafeDigitalInput08);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0102, m_pMapping->SafeTwoChannelInput0102);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0304, m_pMapping->SafeTwoChannelInput0304);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0506, m_pMapping->SafeTwoChannelInput0506);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELINPUT0708, m_pMapping->SafeTwoChannelInput0708);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK01, m_pMapping->SafeInputOK01);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK02, m_pMapping->SafeInputOK02);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK03, m_pMapping->SafeInputOK03);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK04, m_pMapping->SafeInputOK04);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK05, m_pMapping->SafeInputOK05);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK06, m_pMapping->SafeInputOK06);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK07, m_pMapping->SafeInputOK07);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFEINPUTOK08, m_pMapping->SafeInputOK08);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0102, m_pMapping->SafeTwoChannelOK0102);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0304, m_pMapping->SafeTwoChannelOK0304);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0506, m_pMapping->SafeTwoChannelOK0506);
		setBoolValue (JOURNALVARIABLE_X20SC0842_SAFETWOCHANNELOK0708, m_pMapping->SafeTwoChannelOK0708);
	}
	
	bool CIOModule_X20SC0842::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20SC0842::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20SC0842::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20SC0842::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20SC0842::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	

	uint16_t CIOModule_X20SC0842::getPhysicalStateOutput (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->PhysicalStateOutput01;
				break;
			
			case 2:
				return m_pMapping->PhysicalStateOutput02;
				break;
		
			case 3:
				return m_pMapping->PhysicalStateOutput03;
				break;
			
			case 4:
				return m_pMapping->PhysicalStateOutput04;
				break;
			
			case 5:
				return m_pMapping->PhysicalStateOutput05;
				break;
			
			case 6:
				return m_pMapping->PhysicalStateOutput06;
				break;
			default:
				return 0;
				break;
			
				
			
		}
	}
	
	uint16_t CIOModule_X20SC0842::getSafeOutputStatus (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->SafeOutputOK01;
				break;
			
			case 2:
				return m_pMapping->SafeOutputOK02;
				break;
		
			case 3:
				return m_pMapping->SafeOutputOK03;
				break;
			
			case 4:
				return m_pMapping->SafeOutputOK04;
				break;
			
			case 5:
				return m_pMapping->SafeOutputOK05;
				break;
			
			case 6:
				return m_pMapping->SafeOutputOK06;
				break;
			default:
				return 0;
				break;
			
				
			
		}
	}
	
	uint16_t CIOModule_X20SC0842::getInput (uint32_t nChannelNo)
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
	
	uint16_t CIOModule_X20SC0842::getDualInput (uint32_t nDualChannelNo)
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
	uint16_t CIOModule_X20SC0842::getSafeInputStatus (uint32_t nChannelNo)
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
	
	uint16_t CIOModule_X20SC0842::getSafeDualInputStatus (uint32_t nDualChannelNo)
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