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

#include "SignalHandler.hpp"
#include "Utils.hpp"

#include <cstdint>
#include <limits>

#define SIGNALDEFINITION_MINQUEUESIZE 1
#define SIGNALDEFINITION_MAXQUEUESIZE 64

namespace BuRCPP
{

	CSignalParameterDefinition::CSignalParameterDefinition (const std::string & sName, uint32_t nMemoryAddress)
		: m_sName (sName), m_nMemoryAddress (nMemoryAddress)
	{
	}
		
	CSignalParameterDefinition::~CSignalParameterDefinition ()
	{
	}
		
	std::string CSignalParameterDefinition::getName ()
	{
		return m_sName;
	}
	
	
	uint32_t CSignalParameterDefinition::getMemoryAddress () const
	{
		return m_nMemoryAddress;
	}
	
	void CSignalParameterDefinition::writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue)
	{
		throw CException (eErrorCode::COULDNOTWRITEINTEGERTOPARAMETER, "could not write integer value to signal parameter:." + m_sName);
	}
	
	
	void CSignalParameterDefinition::writeDoubleToInstance (CSignalInstanceBase * pInstance, double dValue)
	{
		throw CException (eErrorCode::COULDNOTWRITEDOUBLETOPARAMETER, "could not write double value to signal parameter:." + m_sName);
	}
	
	int64_t CSignalParameterDefinition::readIntegerFromInstance (CSignalInstanceBase * pInstance)
	{
		throw CException (eErrorCode::COULDNOTREADINTEGERFROMPARAMETER, "could not read integer value from signal parameter:." + m_sName);
	}
	
	double CSignalParameterDefinition::readDoubleFromInstance (CSignalInstanceBase * pInstance)
	{
		throw CException (eErrorCode::COULDNOTREADDOUBLEFROMPARAMETER, "could not read double value from signal parameter:." + m_sName);
	}

		
	CSignalBoolParameterDefinition::CSignalBoolParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, bool bDefaultValue)
		: CSignalParameterDefinition (sName, nMemoryAddress), m_bDefaultValue (bDefaultValue)
	{
	}
	
	CSignalBoolParameterDefinition::~CSignalBoolParameterDefinition ()
	{
	}
	
	eSignalParameterType CSignalBoolParameterDefinition::getSignalType ()
	{
		return eSignalParameterType::BoolParameterType;
	}
	
	uint32_t CSignalBoolParameterDefinition::getSizeInBytes ()
	{
		return sizeof (uint8_t);
	}
	
	void CSignalBoolParameterDefinition::writeDefaultToInstance (CSignalInstanceBase * pInstance)
	{
		if (m_bDefaultValue)
			writeIntegerToInstance (pInstance,  1);
		else
			writeIntegerToInstance (pInstance,  0);
	}
	
	void CSignalBoolParameterDefinition::writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");

		uint8_t nValueToWrite = 0;
		if (nValue != 0)
			nValueToWrite = 1;
		
		pInstance->writeData (&nValueToWrite, getMemoryAddress (), 1);
		
	}
	
		
	int64_t CSignalBoolParameterDefinition::readIntegerFromInstance (CSignalInstanceBase * pInstance) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
	
		uint8_t nReadValue = 0;		
		pInstance->readData (&nReadValue, getMemoryAddress (), 1);
		
		if (nReadValue != 0)
			return 1;
		else		
			return 0;

	}

			
	CSignalInt32ParameterDefinition::CSignalInt32ParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, int32_t nDefaultValue)
		: CSignalParameterDefinition (sName, nMemoryAddress), m_nDefaultValue (nDefaultValue)
	{
	}
	
	CSignalInt32ParameterDefinition::~CSignalInt32ParameterDefinition ()
	{
	}
	
	eSignalParameterType CSignalInt32ParameterDefinition::getSignalType ()
	{
		return eSignalParameterType::Int32ParameterType;
	}
	
	uint32_t CSignalInt32ParameterDefinition::getSizeInBytes ()
	{
		return sizeof (int32_t);
	}
	
	void CSignalInt32ParameterDefinition::writeDefaultToInstance (CSignalInstanceBase * pInstance)
	{
		writeIntegerToInstance (pInstance,  m_nDefaultValue);
	}
	
	void CSignalInt32ParameterDefinition::writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
		
		if ((nValue < std::numeric_limits<std::int32_t>::min ()) || (nValue > std::numeric_limits<std::int32_t>::max ()))
			throw CException (eErrorCode::VALUEISOUTSIDEOFINTEGER32RANGE, "value is outside of integer 32 range: " + getName ());

		int32_t nValueToWrite = (int32_t) nValue;		
		pInstance->writeData ((uint8_t*) &nValueToWrite, getMemoryAddress (), sizeof (int32_t));
		
	}
	
		
	int64_t CSignalInt32ParameterDefinition::readIntegerFromInstance (CSignalInstanceBase * pInstance) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
	
		int32_t nReadValue = 0;		
		pInstance->readData ((uint8_t*)&nReadValue, getMemoryAddress (), sizeof (int32_t));
		
		return nReadValue;
	}
	
	CSignalUint32ParameterDefinition::CSignalUint32ParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, uint32_t nDefaultValue)
		: CSignalParameterDefinition (sName, nMemoryAddress), m_nDefaultValue (nDefaultValue)
	{
	}
	
	CSignalUint32ParameterDefinition::~CSignalUint32ParameterDefinition ()
	{
	}
	
	eSignalParameterType CSignalUint32ParameterDefinition::getSignalType ()
	{
		return eSignalParameterType::Uint32ParameterType;
	}
	
	uint32_t CSignalUint32ParameterDefinition::getSizeInBytes ()
	{
		return sizeof (uint32_t);
	}
	
	
	void CSignalUint32ParameterDefinition::writeDefaultToInstance (CSignalInstanceBase * pInstance)
	{
		writeIntegerToInstance (pInstance,  m_nDefaultValue);
	}
	
	void CSignalUint32ParameterDefinition::writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
		
		if ((nValue < std::numeric_limits<std::uint32_t>::min ()) || (nValue > std::numeric_limits<std::uint32_t>::max ()))
			throw CException (eErrorCode::VALUEISOUTSIDEOFUNSIGNEDINTEGER32RANGE, "value is outside of unsigned integer 32 range: " + getName ());

		int32_t nValueToWrite = (int32_t) nValue;		
		pInstance->writeData ((uint8_t*) &nValueToWrite, getMemoryAddress (), sizeof (int32_t));
		
	}
	
		
	int64_t CSignalUint32ParameterDefinition::readIntegerFromInstance (CSignalInstanceBase * pInstance) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
	
		int32_t nReadValue = 0;		
		pInstance->readData ((uint8_t*)&nReadValue, getMemoryAddress (), sizeof (uint32_t));
		
		return nReadValue;
	}
	
	CSignalDoubleParameterDefinition::CSignalDoubleParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, double dDefaultValue)
		: CSignalParameterDefinition (sName, nMemoryAddress), m_dDefaultValue (dDefaultValue)
	{
	}
	
	CSignalDoubleParameterDefinition::~CSignalDoubleParameterDefinition ()
	{
	}
	
	eSignalParameterType CSignalDoubleParameterDefinition::getSignalType ()
	{
		return eSignalParameterType::DoubleParameterType;
	}
	
	uint32_t CSignalDoubleParameterDefinition::getSizeInBytes ()
	{
		return sizeof (double);
	}
	
	void CSignalDoubleParameterDefinition::writeDefaultToInstance (CSignalInstanceBase * pInstance)
	{
		writeDoubleToInstance (pInstance,  m_dDefaultValue);
	}
	
	void CSignalDoubleParameterDefinition::writeDoubleToInstance (CSignalInstanceBase * pInstance, double dValue) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
		
		pInstance->writeData ((uint8_t*) &dValue, getMemoryAddress (), sizeof (dValue));
		
	}
	
		
	double CSignalDoubleParameterDefinition::readDoubleFromInstance (CSignalInstanceBase * pInstance) 
	{
		if (pInstance == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid instance parameter");
	
		double dReadValue = 0.0;		
		pInstance->readData ((uint8_t*)&dReadValue, getMemoryAddress (), sizeof (double));
		
		return dReadValue;
	}
	
	CSignalDefinition::CSignalDefinition (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifeTimeInMilliseconds, std::shared_ptr<CSystemInfo> pSystemInfo)
		: m_sName (sName), m_nQueueSize (nQueueSize), m_nCurrentMemorySizePerInstance (0), m_nLifeTimeInMilliseconds (nLifeTimeInMilliseconds), m_pSystemInfo (pSystemInfo)
	{
		if (pSystemInfo.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid system info parameter");
			
		if ((nQueueSize < SIGNALDEFINITION_MINQUEUESIZE) || (nQueueSize > SIGNALDEFINITION_MAXQUEUESIZE))
			throw CException (eErrorCode::INVALIDSIGNALQUEUESIZE, "invalid signal queue size.");
		
		addBoolParameter ("__active", false);
		addBoolResult ("__processed", false);
	}
	
	CSignalDefinition::~CSignalDefinition ()
	{
	}
		
	std::string CSignalDefinition::getName ()
	{
		return m_sName;
	}
	
	bool CSignalDefinition::isInitializing ()
	{
		return (m_Instances.empty ());
	}
	
	void CSignalDefinition::registerParameter (std::shared_ptr<CSignalParameterDefinition> pParameter)
	{
		if (pParameter.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal parameter instance.");
			
		if (!isInitializing ())
			throw CException (eErrorCode::CANNOTREGISTERPARAMETER, "signal parameters can only be registered initialization mode.");
		
		if (pParameter->getMemoryAddress () != m_nCurrentMemorySizePerInstance)
			throw CException (eErrorCode::SIGNALMEMORYALLOCATIONERROR, "signal memory allocation error.");
		
		std::string sName = pParameter->getName ();
		auto iIter = m_Parameters.find (sName);
		if (iIter != m_Parameters.end ())
			throw CException (eErrorCode::DUPLICATESIGNALPARAMETERNAME, "duplicate signal parameter name: " + sName);
			
		m_Parameters.insert (std::make_pair (sName, pParameter));
		
		m_nCurrentMemorySizePerInstance += pParameter->getSizeInBytes ();
		
	}
	
	
	void CSignalDefinition::registerResult (std::shared_ptr<CSignalParameterDefinition> pResult)
	{
		if (pResult.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal result instance.");
			
		if (!isInitializing ())
			throw CException (eErrorCode::CANNOTREGISTERRESULT, "signal results can only be registered initialization mode.");
		
		if (pResult->getMemoryAddress () != m_nCurrentMemorySizePerInstance)
			throw CException (eErrorCode::SIGNALMEMORYALLOCATIONERROR, "signal memory allocation error.");
		
		std::string sName = pResult->getName ();
		auto iIter = m_Results.find (sName);
		if (iIter != m_Results.end ())
			throw CException (eErrorCode::DUPLICATESIGNALRESULTNAME, "duplicate signal result name: " + sName);
			
		m_Results.insert (std::make_pair (sName, pResult));
		
		m_nCurrentMemorySizePerInstance += pResult->getSizeInBytes ();
		
	}
	
	void CSignalDefinition::addBoolParameter (const std::string & sName, bool bDefault)
	{
		registerParameter (std::make_shared<CSignalBoolParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, bDefault));
	}
	
	void CSignalDefinition::addInt32Parameter (const std::string & sName, int32_t nDefault)
	{
		registerParameter (std::make_shared<CSignalInt32ParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, nDefault));
		
	}
	
	void CSignalDefinition::addUint32Parameter (const std::string & sName, uint32_t nDefault)
	{
		registerParameter (std::make_shared<CSignalUint32ParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, nDefault));
	}
	
	void CSignalDefinition::addDoubleParameter (const std::string & sName, double dDefault)
	{
		registerParameter (std::make_shared<CSignalDoubleParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, dDefault));
	}

	void CSignalDefinition::addBoolResult (const std::string & sName, bool bDefault)
	{
		registerResult (std::make_shared<CSignalBoolParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, bDefault));
	}
	
	void CSignalDefinition::addInt32Result (const std::string & sName, int32_t nDefault)
	{
		registerResult (std::make_shared<CSignalInt32ParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, nDefault));
	}
	
	void CSignalDefinition::addUint32Result (const std::string & sName, uint32_t nDefault)
	{
		registerResult (std::make_shared<CSignalUint32ParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, nDefault));
	}
	
	void CSignalDefinition::addDoubleResult (const std::string & sName, double dDefault)
	{
		registerResult (std::make_shared<CSignalDoubleParameterDefinition> (sName, m_nCurrentMemorySizePerInstance, dDefault));
	}
	
	
	void CSignalDefinition::buildInstances ()
	{
		if (!isInitializing ())
			throw CException (eErrorCode::SIGNALINSTANCESALREADYBUILT, "signal instances have benn already built");
		
		m_MemoryBuffer.resize (m_nCurrentMemorySizePerInstance * m_nQueueSize);
		
		for (uint32_t nIndex = 0; nIndex < m_nQueueSize; nIndex++) {
			
			
			auto pSignal = std::make_shared<CSignalInstance> (this, nIndex + 1, &m_MemoryBuffer.at (nIndex * m_nCurrentMemorySizePerInstance), m_nCurrentMemorySizePerInstance);
			m_Instances.insert (std::make_pair(pSignal->getInstanceID (), pSignal));
			m_UnusedInstanceQueue.push (pSignal);
			
					
			
			
		}
		
	}
	
	CSignalParameterDefinition * CSignalDefinition::findParameter (const std::string & sName, bool bMustExist)
	{
		auto iIter = m_Parameters.find (sName);
		if (iIter == m_Parameters.end ()) {
			if (bMustExist)	
				throw CException (eErrorCode::SIGNALPARAMETERNOTFOUND, "signal parameter not found: " + sName);
			
			return nullptr;
		}
		
		return iIter->second.get ();
	}
	
	CSignalSendInstance * CSignalDefinition::prepareSignal ()
	{
		
		if (m_Instances.size () == 0)
			throw CException (eErrorCode::SIGNALHASNOINSTANCES, "signal has no instances: " + m_sName);
		
		if (m_UnusedInstanceQueue.empty ()) 
			throw CException (eErrorCode::COULDNOTPREPARESIGNAL, "signal instances queue is full: " + m_sName);
		
		auto pSignal = m_UnusedInstanceQueue.front ();
		m_UnusedInstanceQueue.pop ();
		m_InPreparationInstanceQueue.insert (std::make_pair (pSignal->getInstanceID (), pSignal));
		
		pSignal->resetTimer ();
				
		for (auto pParameter: m_Parameters)
			pParameter.second->writeDefaultToInstance (pSignal.get ());
		for (auto pResult: m_Results)
			pResult.second->writeDefaultToInstance (pSignal.get ());
		
							
		return pSignal->getSendInstance ().get ();
	
	}
	
	CSignalProcessingInstance * CSignalDefinition::checkSignal ()
	{
		if (m_Instances.size () == 0)
			throw CException (eErrorCode::SIGNALHASNOINSTANCES, "signal has no instances: " + m_sName);
		
		
		if (m_ActiveInstanceQueue.empty ())
			return nullptr;
		
		auto pSignal = m_ActiveInstanceQueue.front ();
		m_ActiveInstanceQueue.pop ();
		m_InProcessInstanceQueue.insert (std::make_pair (pSignal->getInstanceID (), pSignal));
		
		return pSignal->getProcessingInstance ().get ();
		
		
	}

	
	void CSignalDefinition::finishProcessing (CSignalProcessingInstance * pProcessingInstance)
	{
		if (m_Instances.size () == 0)
			throw CException (eErrorCode::SIGNALHASNOINSTANCES, "signal has no instances: " + m_sName);
		
		uint32_t nInstanceID = pProcessingInstance->getInstanceID();
		auto iIter = m_InProcessInstanceQueue.find (nInstanceID);
		if (iIter == m_InProcessInstanceQueue.end ())
			throw CException (eErrorCode::SIGNALISNOTINPROCESS, "signal is not in process" + m_sName);
		
		auto pSignal = iIter->second;
		m_InProcessInstanceQueue.erase (nInstanceID);

		pProcessingInstance->setBoolResult ("__processed", true);
		
		if (pSignal->signalLifeTimeIsExpired ()) {
			m_UnusedInstanceQueue.push (pSignal);
			pSignal->resetTimer ();
		} else {
			
			m_FinishedInstanceQueue.push (pSignal);
		}
						
					
	}
	
	void CSignalDefinition::releaseExpiredSignals ()
	{
		
		while (!m_FinishedInstanceQueue.empty ()) {
			auto pSignal = m_FinishedInstanceQueue.front ();
			if (pSignal->signalLifeTimeIsExpired ()) {
				m_FinishedInstanceQueue.pop ();
				m_UnusedInstanceQueue.push (pSignal);
				pSignal->resetTimer ();
			} else {
				break;
			}
		}				
		
	}
	
	void CSignalDefinition::finishPreparation (CSignalSendInstance * pSignalInstance)
	{
		if (m_Instances.size () == 0)
			throw CException (eErrorCode::SIGNALHASNOINSTANCES, "signal has no instances: " + m_sName);
			
		uint32_t nInstanceID = pSignalInstance->getInstanceID();
		auto iIter = m_InPreparationInstanceQueue.find (nInstanceID);
		if (iIter == m_InPreparationInstanceQueue.end ())
			throw CException (eErrorCode::SIGNALISNOTINPREPARATION, "signal is not in preparation" + m_sName);
		
		auto pSignal = iIter->second;
		m_InPreparationInstanceQueue.erase (nInstanceID);
		m_ActiveInstanceQueue.push (pSignal);
			
		pSignalInstance->setBoolParameter ("__active", true);
	}
	
	CSignalParameterDefinition * CSignalDefinition::findResult (const std::string & sName, bool bMustExist)
	{
		auto iIter = m_Results.find (sName);
		if (iIter == m_Results.end ()) {
			if (bMustExist)	
				throw CException (eErrorCode::SIGNALRESULTNOTFOUND, "signal result not found: " + sName);
			
			return nullptr;
		}
		
		return iIter->second.get ();
	}
	
	uint32_t CSignalDefinition::getLifeTimeInMilliseconds ()
	{
		return m_nLifeTimeInMilliseconds;
	}
	
	uint64_t CSignalDefinition::getSystemTimeInMicroseconds ()
	{
		return m_pSystemInfo->getSystemTimeInMicroseconds ();
	}
		
	CSignalInstanceBase::CSignalInstanceBase (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize)
	: m_pDefinition (pDefinition), m_pMemory (pMemory), m_nMemorySize (nMemorySize), m_nInstanceID (nInstanceID)
	{
		if (pDefinition == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal definition parameter");
		
		// ATTENTION: pMemory is allowed to be NULL!
		if (m_pMemory == nullptr) {
			if (m_nMemorySize != 0)
				throw CException (eErrorCode::INVALIDPARAM, "invalid memory size parameter");
							
		} else {
			if (m_nMemorySize == 0)
				throw CException (eErrorCode::INVALIDPARAM, "invalid memory size parameter");
		}
			
		
	}
	
	CSignalInstanceBase::~CSignalInstanceBase ()
	{
		
	}
	
	
	bool CSignalInstanceBase::signalHasBeenProcessed ()
	{
		return getBoolResult ("__processed");
	}		
			
	void CSignalInstanceBase::writeData (uint8_t * pSource, uint32_t nOffset, uint32_t nSize)
	{
		if (nSize == 0)
			return;
		if (pSource == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal parameter source data: " +  m_pDefinition->getName ());		
		if (m_pMemory == nullptr)
			throw CException (eErrorCode::SIGNALDATAMISSINGMEMORY, "signal data is missing memory: " + m_pDefinition->getName ());
			
		if (nOffset >= m_nMemorySize)
			throw CException (eErrorCode::SIGNALDATAWRITEOUTOFRANGE, "signal data wanted to write out of range: " +  m_pDefinition->getName ());
		
		if ((nOffset + nSize) > m_nMemorySize)
			throw CException (eErrorCode::SIGNALDATAWRITEOUTOFRANGE, "signal data write exceeds buffer: " +  m_pDefinition->getName ());
		
		for (uint32_t nIndex = 0; nIndex < nSize; nIndex++)
			m_pMemory[nOffset + nIndex] = pSource[nIndex];
	}
	
	void CSignalInstanceBase::readData (uint8_t * pTarget, uint32_t nOffset, uint32_t nSize)
	{
		if (nSize == 0)
			return;
		if (pTarget == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal parameter target data: " +  m_pDefinition->getName ());		
		if (m_pMemory == nullptr)
			throw CException (eErrorCode::SIGNALDATAMISSINGMEMORY, "signal data is missing memory: " + m_pDefinition->getName ());
			
		if (nOffset >= m_nMemorySize)
			throw CException (eErrorCode::SIGNALDATAREADOUTOFRANGE, "signal data wanted to read out of range: " +  m_pDefinition->getName ());
		
		if ((nOffset + nSize) > m_nMemorySize)
			throw CException (eErrorCode::SIGNALDATAREADOUTOFRANGE, "signal data read exceeds buffer: " +  m_pDefinition->getName ());
		
		for (uint32_t nIndex = 0; nIndex < nSize; nIndex++)
			pTarget[nIndex] = m_pMemory[nOffset + nIndex];
	}
		
	
	CSignalProcessingInstance::CSignalProcessingInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize)
	  : CSignalInstanceBase (pDefinition, nInstanceID, pMemory, nMemorySize)
	{
		if (pDefinition == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal definition variable");
	}
	
	CSignalProcessingInstance::~CSignalProcessingInstance ()
	{
	}
	
void CSignalProcessingInstance::setBoolResult (const std::string & sName, bool bValue)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	if (bValue)
		pResult->writeIntegerToInstance (this, 1);
	else
		pResult->writeIntegerToInstance (this, 0);
}
	
void CSignalProcessingInstance::setInt32Result (const std::string & sName, int32_t nValue)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	pResult->writeIntegerToInstance (this, (int64_t) nValue);
}
	
void CSignalProcessingInstance::setUint32Result (const std::string & sName, uint32_t nValue)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	pResult->writeIntegerToInstance (this, (int64_t) nValue);
}
	
void CSignalProcessingInstance::setDoubleResult (const std::string & sName, double dValue)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	pResult->writeDoubleToInstance (this, dValue);
}
		
void CSignalProcessingInstance::setFloatResult (const std::string & sName, float fValue)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	pResult->writeDoubleToInstance (this, (double) fValue);
}

uint32_t CSignalInstanceBase::getInstanceID ()
{
	return m_nInstanceID;
}
	
bool CSignalInstanceBase::getBoolParameter (const std::string & sName)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	int64_t nValue = pParameter->readIntegerFromInstance (this);
		
	return (nValue != 0);
}
	
int32_t CSignalInstanceBase::getInt32Parameter (const std::string & sName)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	int64_t nValue = pParameter->readIntegerFromInstance (this);
		
	if ((nValue < std::numeric_limits<std::int32_t>::min ()) || (nValue > std::numeric_limits<std::int32_t>::max ()))
		throw CException (eErrorCode::VALUEISOUTSIDEOFINTEGER32RANGE, "value is outside of integer 32 range: " + sName);
		
	return (int32_t) nValue;
		
}
	
uint32_t CSignalInstanceBase::getUint32Parameter (const std::string & sName)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	int64_t nValue = pParameter->readIntegerFromInstance (this);
		
	if ((nValue < std::numeric_limits<std::uint32_t>::min ()) || (nValue > std::numeric_limits<std::uint32_t>::max ()))
		throw CException (eErrorCode::VALUEISOUTSIDEOFUNSIGNEDINTEGER32RANGE, "value is outside of unsigned integer 32 range: " + sName);
		
	return (uint32_t) nValue;
}
	
double CSignalInstanceBase::getDoubleParameter (const std::string & sName)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	return pParameter->readDoubleFromInstance (this);
}

float CSignalInstanceBase::getFloatParameter (const std::string & sName)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	return (float) pParameter->readDoubleFromInstance (this);
}
	
bool CSignalInstanceBase::getBoolResult (const std::string & sName)
{
	auto pParameter = m_pDefinition->findResult (sName, true);
	int64_t nValue = pParameter->readIntegerFromInstance (this);
		
	return (nValue != 0);
}
	
int32_t CSignalInstanceBase::getInt32Result (const std::string & sName)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	int64_t nValue = pResult->readIntegerFromInstance (this);
		
	if ((nValue < std::numeric_limits<std::int32_t>::min ()) || (nValue > std::numeric_limits<std::int32_t>::max ()))
		throw CException (eErrorCode::VALUEISOUTSIDEOFINTEGER32RANGE, "value is outside of integer 32 range: " + sName);
		
	return (int32_t) nValue;
}
		
uint32_t CSignalInstanceBase::getUint32Result (const std::string & sName)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	int64_t nValue = pResult->readIntegerFromInstance (this);
		
	if ((nValue < std::numeric_limits<std::uint32_t>::min ()) || (nValue > std::numeric_limits<std::uint32_t>::max ()))
		throw CException (eErrorCode::VALUEISOUTSIDEOFUNSIGNEDINTEGER32RANGE, "value is outside of unsigned integer 32 range: " + sName);
		
	return (int32_t) nValue;
}
	
double CSignalInstanceBase::getDoubleResult (const std::string & sName)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	return pResult->readDoubleFromInstance (this);
		
}
	
float CSignalInstanceBase::getFloatResult (const std::string & sName)
{
	auto pResult = m_pDefinition->findResult (sName, true);
	return (float) pResult->readDoubleFromInstance (this);
		
}

	
	void CSignalProcessingInstance::finishProcessing ()
	{
		m_pDefinition->finishProcessing (this);
	}

	
	
	CSignalSendInstance::CSignalSendInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize)
	: CSignalInstanceBase (pDefinition, nInstanceID, pMemory, nMemorySize), m_nTriggerTimeInMicroseconds (0)
	{
		if (pDefinition == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid signal definition variable");
	}
		
	CSignalSendInstance::~CSignalSendInstance ()
	{
	}
	
	void CSignalSendInstance::resetTriggerTime ()
	{
		m_nTriggerTimeInMicroseconds = 0;
	}
	
	
void CSignalSendInstance::setBoolParameter (const std::string & sName, bool bValue)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	if (bValue)
		pParameter->writeIntegerToInstance (this, 1);
	else
		pParameter->writeIntegerToInstance (this, 0);
		
		
}
	
void CSignalSendInstance::setInt32Parameter (const std::string & sName, int32_t nValue)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	pParameter->writeIntegerToInstance (this, (int64_t) nValue);
}
	
void CSignalSendInstance::setUint32Parameter (const std::string & sName, uint32_t nValue)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	pParameter->writeIntegerToInstance (this, (int64_t) nValue);
}
	
void CSignalSendInstance::setDoubleParameter (const std::string & sName, double dValue)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	pParameter->writeDoubleToInstance (this, dValue);
}
	
void CSignalSendInstance::setFloatParameter (const std::string & sName, float fValue)
{
	auto pParameter = m_pDefinition->findParameter (sName, true);
	pParameter->writeDoubleToInstance (this, (double)fValue);
}
	
	

	
	bool CSignalInstanceBase::signalIsTriggered ()
	{
		return getBoolParameter ("__active");
	}	
	
	bool CSignalSendInstance::triggerSignal ()
	{
		m_pDefinition->finishPreparation (this);
					
		m_nTriggerTimeInMicroseconds = m_pDefinition->getSystemTimeInMicroseconds ();
		
		return true;
		
	}
	
	uint64_t CSignalSendInstance::getTriggerTimeInMicroseconds ()
	{
		return m_nTriggerTimeInMicroseconds;
	}

	CSignalInstance::CSignalInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize)
	:  CSignalInstanceBase (pDefinition, nInstanceID, pMemory, nMemorySize)
	{
		m_SendInstance = std::make_shared<CSignalSendInstance> (pDefinition, getInstanceID(), pMemory, nMemorySize);
		m_ProcessingInstance = std::make_shared<CSignalProcessingInstance> (pDefinition, getInstanceID(),pMemory, nMemorySize);
	}
	
	CSignalInstance::~CSignalInstance ()
	{
	}
			
	std::shared_ptr<CSignalSendInstance> CSignalInstance::getSendInstance ()
	{
		return m_SendInstance;
	}
	
	std::shared_ptr<CSignalProcessingInstance> CSignalInstance::getProcessingInstance ()
	{
		return m_ProcessingInstance;
	}
	
	void CSignalInstance::resetTimer ()
	{
		m_SendInstance->resetTriggerTime();
	}
	
	bool CSignalInstance::signalLifeTimeIsExpired ()
	{
		uint64_t nTriggerTimeInMicroseconds = m_SendInstance->getTriggerTimeInMicroseconds ();
		uint64_t nCurrentTimeInMicroseconds = m_pDefinition->getSystemTimeInMicroseconds ();
		
		if (nCurrentTimeInMicroseconds >= nTriggerTimeInMicroseconds) {
			
			uint64_t nSignalExistenceTimeInMicroseconds = nCurrentTimeInMicroseconds - nTriggerTimeInMicroseconds;
			uint64_t nSignalExistenceTimeInMilliseconds = nSignalExistenceTimeInMicroseconds / 1000;
			
			return (nSignalExistenceTimeInMilliseconds > m_pDefinition->getLifeTimeInMilliseconds ());
			
			
		} else {
			throw CException (eErrorCode::SIGNALTRIGGERTIMEISINFUTURE, "signal trigger time is in the future");
		}
			
	}


CSignalHandler::CSignalHandler (std::shared_ptr<CSystemInfo> pSystemInfo)
	: m_bIsInitializing (true), m_pSystemInfo (pSystemInfo)
{
	if (pSystemInfo.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid system info parameter");
}
	
CSignalHandler::~CSignalHandler ()
{
}
		
		
std::shared_ptr<CSignalDefinition> CSignalHandler::registerSignal (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifetimeInMilliseconds)
{
	if (m_bIsInitializing) {
		
		auto iIter = m_SignalDefinitions.find (sName);
		if (iIter != m_SignalDefinitions.end ())
			throw CException (eErrorCode::DUPLICATESIGNALDEFINITION, "duplicate signal definition: " + sName);
			
		auto pSignalDefinition = std::make_shared<CSignalDefinition> (sName, nQueueSize, nLifetimeInMilliseconds, m_pSystemInfo);
		m_SignalDefinitions.insert (std::make_pair (sName, pSignalDefinition));		
		
		return pSignalDefinition;
		
	} else {
		throw CException (eErrorCode::CANNOTREGISTERSIGNAL, "can not register signal, if not in initialization mode.");
	}
	
}
	
		
CSignalProcessingInstance * CSignalHandler::checkSignal (const std::string & sName)
{
		if (m_bIsInitializing) 
			throw CException (eErrorCode::COULDNOTCHECKSIGNAL, "can not check signal, if in initialization mode.");
		
	
		auto iIter = m_SignalDefinitions.find (sName);		
		if (iIter != m_SignalDefinitions.end ()) {
			auto pSignalDefinition = iIter->second;
			
			return pSignalDefinition->checkSignal ();
		}
		
		throw CException (eErrorCode::SIGNALDEFINITIONNOTFOUND, "signal definition not found: " + sName);
		
	}
	
	
CSignalSendInstance * CSignalHandler::prepareSignal (const std::string & sName)
{
	if (m_bIsInitializing) 
		throw CException (eErrorCode::COULDNOTPREPARESIGNAL, "can not prepare signal, if in initialization mode.");
		
	
	auto iIter = m_SignalDefinitions.find (sName);		
	if (iIter != m_SignalDefinitions.end ()) {
		auto pSignalDefinition = iIter->second;
			
		return pSignalDefinition->prepareSignal ();
	}
		
	throw CException (eErrorCode::SIGNALDEFINITIONNOTFOUND, "signal definition not found: " + sName);
		
		
}

void CSignalHandler::buildInstances ()
{
	if (m_bIsInitializing) {
			
		for (auto iIter : m_SignalDefinitions)
			iIter.second->buildInstances ();
			
		m_bIsInitializing = false;
		
	} else {
		throw CException (eErrorCode::CANNOTBUILDSIGNALINSTANCES, "signal instances have already been built.");
	}
}
	
void CSignalHandler::releaseExpiredSignals ()
{
	for (auto iIter : m_SignalDefinitions)
		iIter.second->releaseExpiredSignals ();
}
	
	
}
