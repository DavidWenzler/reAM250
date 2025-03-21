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
#include "IOModule_X20DO6322.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20DO6322_MODULEOK 1
#define JOURNALVARIABLE_X20DO6322_SERIALNUMBER 2
#define JOURNALVARIABLE_X20DO6322_MODULEID 3
#define JOURNALVARIABLE_X20DO6322_HARDWAREVARIANT 4
#define JOURNALVARIABLE_X20DO6322_FIRMWAREVERSION 5
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT01 6
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT02 7
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT03 8
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT04 9
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT05 10
#define JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT06 11
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT01 12
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT02 13
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT03 14
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT04 15
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT05 16
#define JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT06 17

namespace BuRCPP {

	CIOModule_X20DO6322	::CIOModule_X20DO6322 (const std::string & sName, IOMappingX20DO6322_TYP * pMapping)
	: CIOModule (sName), m_pMapping (pMapping)
	{
		
	}
	
	CIOModule_X20DO6322::~CIOModule_X20DO6322 ()
	{
	}
	
	void CIOModule_X20DO6322::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20DO6322_MODULEOK);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20DO6322_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20DO6322_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20DO6322_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20DO6322_FIRMWAREVERSION);
		registerBoolValue ("DigitalOutput01", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT01);
		registerBoolValue ("DigitalOutput02", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT02);
		registerBoolValue ("DigitalOutput03", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT03);
		registerBoolValue ("DigitalOutput04", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT04);
		registerBoolValue ("DigitalOutput05", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT05);
		registerBoolValue ("DigitalOutput06", JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT06);
		registerBoolValue ("StatusDigitalOutput01", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT01);
		registerBoolValue ("StatusDigitalOutput02", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT02);
		registerBoolValue ("StatusDigitalOutput03", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT03);
		registerBoolValue ("StatusDigitalOutput04", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT04);
		registerBoolValue ("StatusDigitalOutput05", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT05);
		registerBoolValue ("StatusDigitalOutput06", JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT06);

	}

	void CIOModule_X20DO6322::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20DO6322_MODULEOK, m_pMapping->ModuleOk);
		setIntegerValue (JOURNALVARIABLE_X20DO6322_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20DO6322_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20DO6322_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20DO6322_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT01, m_pMapping->DigitalOutput01);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT02, m_pMapping->DigitalOutput02);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT03, m_pMapping->DigitalOutput03);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT04, m_pMapping->DigitalOutput04);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT05, m_pMapping->DigitalOutput05);
		setBoolValue (JOURNALVARIABLE_X20DO6322_DIGITALOUTPUT06, m_pMapping->DigitalOutput06);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT01, m_pMapping->StatusDigitalOutput01);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT02, m_pMapping->StatusDigitalOutput02);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT03, m_pMapping->StatusDigitalOutput03);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT04, m_pMapping->StatusDigitalOutput04);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT05, m_pMapping->StatusDigitalOutput05);
		setBoolValue (JOURNALVARIABLE_X20DO6322_STATUSDIGITALOUTPUT06, m_pMapping->StatusDigitalOutput06);
	}
	
	bool CIOModule_X20DO6322::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20DO6322::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20DO6322::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20DO6322::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20DO6322::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	
	
	void CIOModule_X20DO6322::setOutput (uint32_t nChannelNo, bool nValue)
	{
		switch (nChannelNo)
		{
			case 1:
				m_pMapping->DigitalOutput01 = nValue;
				break;
			
			case 2:
				m_pMapping->DigitalOutput02 = nValue;
				break;
			
			case 3:
				m_pMapping->DigitalOutput03 = nValue;
				break;
			
			case 4:
				m_pMapping->DigitalOutput04 = nValue;
				break;
			
			case 5:
				m_pMapping->DigitalOutput05 = nValue;
				break;
			
			case 6:
				m_pMapping->DigitalOutput06 = nValue;
				break;
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	
	}
	
	bool CIOModule_X20DO6322::getOutput (uint32_t nChannelNo)
	{
		switch (nChannelNo)
		{
			case 1:
				return m_pMapping->DigitalOutput01;
			
			case 2:
				return m_pMapping->DigitalOutput02;
			
			case 3:
				return m_pMapping->DigitalOutput03;
			
			case 4:
				return m_pMapping->DigitalOutput04;
			
			case 5:
				return m_pMapping->DigitalOutput05;
			
			case 6:
				return m_pMapping->DigitalOutput06;
			
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	
	}
	
	uint16_t CIOModule_X20DO6322::getIOStatus (uint32_t nChannelNo)
	{
		/*status IDs: 0 = no error, 1 = short circuit or overload, or channel switched on and missing I/O power supply, 
		or channel switched off and external voltage applied on channel*/

		switch (nChannelNo) 
		{
			case 1: return m_pMapping->StatusDigitalOutput01;
			case 2: return m_pMapping->StatusDigitalOutput02;
			case 3: return m_pMapping->StatusDigitalOutput03;
			case 4: return m_pMapping->StatusDigitalOutput04;
			case 5: return m_pMapping->StatusDigitalOutput05;
			case 6: return m_pMapping->StatusDigitalOutput06;
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}


}