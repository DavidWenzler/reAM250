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

#include "IOModule_X20AI4622.hpp"

// Raw Registers
#define JOURNALVARIABLE_X20AI4622_MODULEOK 1
#define JOURNALVARIABLE_X20AI4622_STALEDATA 2
#define JOURNALVARIABLE_X20AI4622_SERIALNUMBER 3
#define JOURNALVARIABLE_X20AI4622_MODULEID 4
#define JOURNALVARIABLE_X20AI4622_HARDWAREVARIANT 5
#define JOURNALVARIABLE_X20AI4622_FIRMWAREVERSION 6
#define JOURNALVARIABLE_X20AI4622_ANALOGINPUT01 7
#define JOURNALVARIABLE_X20AI4622_ANALOGINPUT02 8
#define JOURNALVARIABLE_X20AI4622_ANALOGINPUT03 9
#define JOURNALVARIABLE_X20AI4622_ANALOGINPUT04 10
#define JOURNALVARIABLE_X20AI4622_STATUSINPUT01 11

// Derived Values
#define JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE01 1001
#define JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE02 1002
#define JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE03 1003
#define JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE04 1004
#define JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE01 1005
#define JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE02 1006
#define JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE03 1007
#define JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE04 1008



namespace BuRCPP {

	CIOModule_X20AI4622	::CIOModule_X20AI4622 (const std::string & sName, IOMappingX20AI4622_TYP * pMapping)
	: CIOModule (sName), m_pMapping (pMapping)
	{
		for (auto &channelType:m_ChannelTypes)
			channelType = eIOChannelType_X20AI4622::mtVoltage10V;
			
		for (auto &LowerLimits:m_nLowerLimit)
			LowerLimits = -32767;
		
		for (auto &UpperLimits:m_nUpperLimit)
			UpperLimits = 32766;
				
	}
	
	CIOModule_X20AI4622::~CIOModule_X20AI4622 ()
	{
		
	}
		
	void CIOModule_X20AI4622::onRegisterJournal () 
	{
		registerBoolValue ("ModuleOk", JOURNALVARIABLE_X20AI4622_MODULEOK);
		registerBoolValue ("StaleData", JOURNALVARIABLE_X20AI4622_STALEDATA);
		registerUInt32Value ("SerialNumber", JOURNALVARIABLE_X20AI4622_SERIALNUMBER);
		registerUInt16Value ("ModuleID", JOURNALVARIABLE_X20AI4622_MODULEID);
		registerUInt16Value ("HardwareVariant", JOURNALVARIABLE_X20AI4622_HARDWAREVARIANT);
		registerUInt16Value ("FirmwareVersion", JOURNALVARIABLE_X20AI4622_FIRMWAREVERSION);
		registerInt16Value ("AnalogInput01", JOURNALVARIABLE_X20AI4622_ANALOGINPUT01);
		registerInt16Value ("AnalogInput02", JOURNALVARIABLE_X20AI4622_ANALOGINPUT02);
		registerInt16Value ("AnalogInput03", JOURNALVARIABLE_X20AI4622_ANALOGINPUT03);
		registerInt16Value ("AnalogInput04", JOURNALVARIABLE_X20AI4622_ANALOGINPUT04);
		registerUInt8Value ("StatusInput01", JOURNALVARIABLE_X20AI4622_STATUSINPUT01);
		
		
		
		switch (getChannelType (1)) {
			case eIOChannelType_X20AI4622::mtVoltage10V:
				registerDoubleValue ("InputVoltage01", JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE01, -10.0, 10.0, 65536);
				break;
			
			case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				registerDoubleValue ("InputCurrentInAmpere01", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE01, 0.000, 0.020, 65536);
				break;

			case eIOChannelType_X20AI4622::mtCurrent4to20mA:
				registerDoubleValue ("InputCurrentInAmpere01", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE01, 0.004, 0.020, 65536);
				break;
		}
		
		switch (getChannelType (2)) {
			case eIOChannelType_X20AI4622::mtVoltage10V:
				registerDoubleValue ("InputVoltage02", JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE02, -10.0, 10.0, 65536);
				break;
			
			case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				registerDoubleValue ("InputCurrentInAmpere02", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE02, 0.000, 0.020, 65536);
				break;

			case eIOChannelType_X20AI4622::mtCurrent4to20mA:
				registerDoubleValue ("InputCurrentInAmpere02", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE02, 0.004, 0.020, 65536);
				break;
		}
		
		switch (getChannelType (3)) {
			case eIOChannelType_X20AI4622::mtVoltage10V:
				registerDoubleValue ("InputVoltage03", JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE03, -10.0, 10.0, 65536);
				break;
			
			case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				registerDoubleValue ("InputCurrentInAmpere03", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE03, 0.000, 0.020, 65536);
				break;

			case eIOChannelType_X20AI4622::mtCurrent4to20mA:
				registerDoubleValue ("InputCurrentInAmpere03", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE03, 0.004, 0.020, 65536);
				break;
		}
		
		switch (getChannelType (4)) {
			case eIOChannelType_X20AI4622::mtVoltage10V:
				registerDoubleValue ("InputVoltage04", JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE04, -10.0, 10.0, 65536);
				break;
			
			case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				registerDoubleValue ("InputCurrentInAmpere04", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE04, 0.000, 0.020, 65536);
				break;

			case eIOChannelType_X20AI4622::mtCurrent4to20mA:
				registerDoubleValue ("InputCurrentInAmpere04", JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE04, 0.004, 0.020, 65536);
				break;
		}
	}

	void CIOModule_X20AI4622::onUpdateJournal () 
	{
		setBoolValue (JOURNALVARIABLE_X20AI4622_MODULEOK, m_pMapping->ModuleOk);
		setBoolValue (JOURNALVARIABLE_X20AI4622_STALEDATA, m_pMapping->StaleData);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_SERIALNUMBER, m_pMapping->SerialNumber);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_MODULEID, m_pMapping->ModuleID);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_HARDWAREVARIANT, m_pMapping->HardwareVariant);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_FIRMWAREVERSION, m_pMapping->FirmwareVersion);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_ANALOGINPUT01, m_pMapping->AnalogInput01);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_ANALOGINPUT02, m_pMapping->AnalogInput02);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_ANALOGINPUT03, m_pMapping->AnalogInput03);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_ANALOGINPUT04, m_pMapping->AnalogInput04);
		setIntegerValue (JOURNALVARIABLE_X20AI4622_STATUSINPUT01, m_pMapping->StatusInput01);
		
		
		for (int index = 0; index < 4; index++)
		{
			uint32_t nChannelNo = index + 1;
			switch (getChannelType (nChannelNo)) {
				
				case eIOChannelType_X20AI4622::mtVoltage10V:
				
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE01 + index, getInputVoltageInVolt (nChannelNo));	
					/*setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE02, getInputVoltageInVolt (2));
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE03, getInputVoltageInVolt (3));
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTVOLTAGE04, getInputVoltageInVolt (4));*/
					break;	
			
				case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				case eIOChannelType_X20AI4622::mtCurrent4to20mA:
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE01 + index, getInputCurrentInAmpere (nChannelNo));
					/*setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE02, getInputCurrentInAmpere (2));
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE03, getInputCurrentInAmpere (3));
					setDoubleValue (JOURNALVARIABLE_X20AI4622_INPUTCURRENTINAMPERE04, getInputCurrentInAmpere (4));*/
					break;
			}
		}
	}
	
	bool CIOModule_X20AI4622::isActive ()
	{
		return m_pMapping->ModuleOk != 0;
	}
	
	uint32_t CIOModule_X20AI4622::getSerialNumber ()
	{
		return m_pMapping->SerialNumber;		
	}
		
	uint16_t CIOModule_X20AI4622::getModuleID () 
	{
		return m_pMapping->ModuleID;
	}
	
	uint16_t CIOModule_X20AI4622::getHardwareVariant () 
	{
		return m_pMapping->HardwareVariant;
	}
		
	uint16_t CIOModule_X20AI4622::getFirmwareVersion () 
	{
		return m_pMapping->FirmwareVersion;
	}
	
	int16_t CIOModule_X20AI4622::getRawValue (uint32_t nChannelNo)
	{		
		
		switch (nChannelNo) {
			case 1: return m_pMapping->AnalogInput01;
			case 2: return m_pMapping->AnalogInput02;
			case 3: return m_pMapping->AnalogInput03;
			case 4: return m_pMapping->AnalogInput04;
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}
	
	
	double CIOModule_X20AI4622::getRawValueNormalizedZeroToOne (uint32_t nChannelNo)
	{
		if (nChannelNo > 0 && nChannelNo < 5)
		{
			int32_t rawValue = getRawValue (nChannelNo);
			int32_t nRange = m_nUpperLimit[nChannelNo -1] - m_nLowerLimit[nChannelNo -1];
			return (double) (rawValue - (int32_t) m_nLowerLimit[nChannelNo -1]) / (double) nRange;
		}
		else
		{
			throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}

	
	double CIOModule_X20AI4622::getInputVoltageInVolt (uint32_t nChannelNo)
	{
		switch (getChannelType (nChannelNo)) {
			case eIOChannelType_X20AI4622::mtVoltage10V:
				return (getRawValueNormalizedZeroToOne (nChannelNo) - 0.5) * 20.0;
			default: 
				throw CException (eErrorCode::NOVOLTAGEMODULE, "IO module does not measure voltage: " + m_sName );
		}
		
	}
		
	double CIOModule_X20AI4622::getInputCurrentInAmpere (uint32_t nChannelNo)
	{
		switch (getChannelType (nChannelNo)) {
			case eIOChannelType_X20AI4622::mtCurrent0to20mA:
				return (getRawValueNormalizedZeroToOne (nChannelNo)) * 0.020;
			case eIOChannelType_X20AI4622::mtCurrent4to20mA:
				return (getRawValueNormalizedZeroToOne (nChannelNo)) * 0.016 + 0.004;
			default: 
				throw CException (eErrorCode::NOCURRENTMODULE, "IO module does not measure current: " + m_sName );
		}
		
		
	}
	
	bool CIOModule_X20AI4622::setRange(uint32_t nChannelNo, uint16_t nLower, uint16_t nUpper)
	{
		if (nChannelNo > 0 && nChannelNo < 5)
		{
			m_nLowerLimit[nChannelNo - 1] = nLower; 
			m_nUpperLimit[nChannelNo - 1] = nUpper; 
			return true;
		}
		else
		{
			return false;
		}
	}
	
	uint16_t CIOModule_X20AI4622::getIOStatus (uint32_t nChannelNo)
	{
		//status IDs: 0 = no error, 1 = lower limit value undershot, 2 = upper limit value exceeded, 3 = wire breakage 
		switch (nChannelNo) {
			case 1: return (m_pMapping->StatusInput01 & 0x03);
			case 2: return ((m_pMapping->StatusInput01 >> 2) & 0x03);
			case 3: return ((m_pMapping->StatusInput01 >> 4) & 0x03);
			case 4: return ((m_pMapping->StatusInput01 >> 6) & 0x03);
			default:
				throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}
	}
	

	eIOChannelType_X20AI4622 CIOModule_X20AI4622::getChannelType (uint32_t nChannelNo)
	{
		if ((nChannelNo >= 1) && (nChannelNo <= 4))
		{
			return m_ChannelTypes[nChannelNo - 1];
		}
		else
			return eIOChannelType_X20AI4622::mtUnknown;
	}
	
	bool CIOModule_X20AI4622::setChannelType (uint32_t nChannelNo, eIOChannelType_X20AI4622 eChannelTypes)
	{
		if ((nChannelNo >= 1) && (nChannelNo <= 4))
		{				
			switch (eChannelTypes) {
				case eIOChannelType_X20AI4622::mtVoltage10V:
					setRange(nChannelNo, -32768 , 32767);
					break;
				case eIOChannelType_X20AI4622::mtCurrent0to20mA:
					setRange(nChannelNo, 0, 32767);
					break;
				case eIOChannelType_X20AI4622::mtCurrent4to20mA:
					setRange(nChannelNo, -8192 , 32767);
					break;
				default: 
					throw CException (eErrorCode::INVALIDCHANNELTYPE, "invalid channel type");
			}
			m_ChannelTypes[nChannelNo - 1] = eChannelTypes;	
			return true;
		}
		else 
		{
			throw CException (eErrorCode::INVALIDCHANNELNUMBER, "invalid channel number: " + std::to_string (nChannelNo));
		}	
	}

}