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

#include "IOModule_X20SO6300.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20SO6300_MODULEOK 1
#define JOURNALVARIABLE_X20SO6300_SERIALNUMBER 2
#define JOURNALVARIABLE_X20SO6300_MODULEID 3
#define JOURNALVARIABLE_X20SO6300_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20SO6300_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20SO6300_SAFEMODULEOK 6
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT01 7
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT02 8
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT03 9
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT04 10
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT05 11
#define JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT06 12
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK01 13
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK02 14
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK03 15
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK04 16
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK05 17
#define JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK06 18



namespace BuRCPP {


	CIOModule_X20SO6300::CIOModule_X20SO6300 (const std::string & sName, IOMappingX20SO6300_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20SO6300::~CIOModule_X20SO6300 ()
	{
	}
	
	void CIOModule_X20SO6300::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20SO6300_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20SO6300_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20SO6300_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20SO6300_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20SO6300_FIRMWAREVERSION);
		registerBoolValue ("SafeModuleOK", JOURNALVARIABLE_X20SO6300_SAFEMODULEOK);
		registerBoolValue ("SafeDigitalOutput01", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT01);
		registerBoolValue ("SafeDigitalOutput02", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT02);
		registerBoolValue ("SafeDigitalOutput03", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT03);
		registerBoolValue ("SafeDigitalOutput04", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT04);
		registerBoolValue ("SafeDigitalOutput05", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT05);
		registerBoolValue ("SafeDigitalOutput06", JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT06);
		registerBoolValue ("SafeOutputOK01", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK01);
		registerBoolValue ("SafeOutputOK02", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK02);
		registerBoolValue ("SafeOutputOK03", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK03);
		registerBoolValue ("SafeOutputOK04", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK04);
		registerBoolValue ("SafeOutputOK05", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK05);
		registerBoolValue ("SafeOutputOK06", JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK06);
	}

	void CIOModule_X20SO6300::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20SO6300_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20SO6300_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20SO6300_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20SO6300_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20SO6300_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEMODULEOK, m_pMapping->SafeModuleOK);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT01, m_pMapping->PhysicalStateOutput01);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT02, m_pMapping->PhysicalStateOutput02);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT03, m_pMapping->PhysicalStateOutput03);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT04, m_pMapping->PhysicalStateOutput04);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT05, m_pMapping->PhysicalStateOutput05);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEDIGITALOUTPUT06, m_pMapping->PhysicalStateOutput06);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK01, m_pMapping->SafeOutputOK01);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK02, m_pMapping->SafeOutputOK02);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK03, m_pMapping->SafeOutputOK03);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK04, m_pMapping->SafeOutputOK04);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK05, m_pMapping->SafeOutputOK05);
		setBoolValue (JOURNALVARIABLE_X20SO6300_SAFEOUTPUTOK06, m_pMapping->SafeOutputOK06);
	}
	
	bool CIOModule_X20SO6300::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20SO6300::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20SO6300::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20SO6300::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20SO6300::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	

	uint16_t CIOModule_X20SO6300::getPhysicalStateOutput (uint32_t nChannelNo)
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
	
	uint16_t CIOModule_X20SO6300::getSafeOutputStatus (uint32_t nChannelNo)
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
	
	

}