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

#include "IOModule_PLC.hpp"

// Raw Registers
#define JOURNALVARIABLE_PLC_MODULEOK 1
#define JOURNALVARIABLE_PLC_STALEDATA 2
#define JOURNALVARIABLE_PLC_SERIALNUMBER 3
#define JOURNALVARIABLE_PLC_MODULEID 4
#define JOURNALVARIABLE_PLC_HARDWAREVERSION 5
#define JOURNALVARIABLE_PLC_FIRMWAREVERSION 6
#define JOURNALVARIABLE_PLC_TEMPERATURECPU 7
#define JOURNALVARIABLE_PLC_TEMPERATUREENV 8
#define JOURNALVARIABLE_PLC_SYSTEMTIME 9
#define JOURNALVARIABLE_PLC_STATUSINPUT01 10


namespace BuRCPP {

	CIOModule_PLC::CIOModule_PLC (const std::string & sName, IOMappingPLC_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
				
	}
	
	CIOModule_PLC::~CIOModule_PLC ()
	{
		
	}
		
	void CIOModule_PLC::onRegisterJournal () 
	{
		
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_PLC_MODULEOK);
		registerBoolValue ("StaleData", JOURNALVARIABLE_PLC_STALEDATA);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_PLC_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_PLC_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_PLC_HARDWAREVERSION);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_PLC_FIRMWAREVERSION);
		registerUInt8Value ("StatusInput01", JOURNALVARIABLE_PLC_STATUSINPUT01);
		
	
	}

	void CIOModule_PLC::onUpdateJournal () 
	{
		
		setBoolValue (JOURNALVARIABLE_PLC_MODULEOK, m_pMapping->ModuleOk);
		setBoolValue (JOURNALVARIABLE_PLC_STALEDATA, m_pMapping->StaleData);
		setIntegerValue (JOURNALVARIABLE_PLC_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_PLC_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_PLC_HARDWAREVERSION, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_PLC_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setIntegerValue (JOURNALVARIABLE_PLC_STATUSINPUT01, m_pMapping->StatusInput01);
		
	}
	
	bool CIOModule_PLC::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_PLC::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_PLC::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_PLC::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_PLC::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	
	uint32_t CIOModule_PLC::getSystemTime () 
	{
		return m_pMapping->SystemTime;
	}
}