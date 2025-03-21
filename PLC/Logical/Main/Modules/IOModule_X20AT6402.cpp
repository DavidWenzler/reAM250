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

#include "IOModule_X20AT6402.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20AT6402_MODULEOK 1
#define JOURNALVARIABLE_X20AT6402_SERIALNUMBER 2
#define JOURNALVARIABLE_X20AT6402_MODULEID 3
#define JOURNALVARIABLE_X20AT6402_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20AT6402_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE01 6
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE02 7
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE03 8
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE04 9
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE05 10
#define JOURNALVARIABLE_X20AT6402_TEMPERATURE06 11
#define JOURNALVARIABLE_X20AT6402_STATUSINPUT01 12
#define JOURNALVARIABLE_X20AT6402_STATUSINPUT02 13


namespace BuRCPP {

	CIOModule_X20AT6402	::CIOModule_X20AT6402 (const std::string & sName, IOMappingX20AT6402_TYP * pMapping)
		: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20AT6402::~CIOModule_X20AT6402 ()
	{
	}
	
	void CIOModule_X20AT6402::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20AT6402_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20AT6402_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20AT6402_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20AT6402_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20AT6402_FIRMWAREVERSION);
		registerInt16Value ("Temperature01", JOURNALVARIABLE_X20AT6402_TEMPERATURE01);
		registerInt16Value ("Temperature02", JOURNALVARIABLE_X20AT6402_TEMPERATURE02);
		registerInt16Value ("Temperature03", JOURNALVARIABLE_X20AT6402_TEMPERATURE03);
		registerInt16Value ("Temperature04", JOURNALVARIABLE_X20AT6402_TEMPERATURE04);
		registerInt16Value ("Temperature05", JOURNALVARIABLE_X20AT6402_TEMPERATURE05);
		registerInt16Value ("Temperature06", JOURNALVARIABLE_X20AT6402_TEMPERATURE06);
		registerUInt8Value ("StatusInput01", JOURNALVARIABLE_X20AT6402_STATUSINPUT01);
		registerUInt8Value ("StatusInput02", JOURNALVARIABLE_X20AT6402_STATUSINPUT02);
	}

	void CIOModule_X20AT6402::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20AT6402_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE01, m_pMapping->Temperature01);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE02, m_pMapping->Temperature02);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE03, m_pMapping->Temperature03);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE04, m_pMapping->Temperature04);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE05, m_pMapping->Temperature05);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_TEMPERATURE06, m_pMapping->Temperature06);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_STATUSINPUT01, m_pMapping->StatusInput01);
		setIntegerValue (JOURNALVARIABLE_X20AT6402_STATUSINPUT02, m_pMapping->StatusInput02);
	}
	
	bool CIOModule_X20AT6402::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20AT6402::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20AT6402::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20AT6402::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20AT6402::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	
	int16_t CIOModule_X20AT6402::getRawValue (uint32_t nChannelNo)
	{		
		
		switch (nChannelNo) {
			case 1: return m_pMapping->Temperature01;
			case 2: return m_pMapping->Temperature02;
			case 3: return m_pMapping->Temperature03;
			case 4: return m_pMapping->Temperature04;
			case 5: return m_pMapping->Temperature05;
			case 6: return m_pMapping->Temperature06;
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}
	
	

	
	uint16_t CIOModule_X20AT6402::getIOStatus (uint32_t nChannelNo)
	{
		//status IDs: 0 = no error, 1 = lower limit value undershot, 2 = upper limit value exceeded, 3 = wire breakage 
		switch (nChannelNo) {
			case 1: return (m_pMapping->StatusInput01 & 0x03);
			case 2: return ((m_pMapping->StatusInput01 >> 2) & 0x03);
			case 3: return ((m_pMapping->StatusInput01 >> 4) & 0x03);
			case 4: return ((m_pMapping->StatusInput01 >> 6) & 0x03);
			case 5: return (m_pMapping->StatusInput02 & 0x03);
			case 6: return ((m_pMapping->StatusInput02 >> 2) & 0x03);
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}
	
	

}