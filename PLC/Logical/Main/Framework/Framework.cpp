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

#include "Framework.hpp"
#include "SignalHandler.hpp"
#include "Utils.hpp"
#include "Journal.hpp"
#include <stdint.h>

namespace BuRCPP {

	CException::CException (eErrorCode code, const std::string & sMessage)
		: m_Code (code), m_sMessage (sMessage)
	{
	}

	
	eErrorCode CException::getCode () const
	{
		return m_Code;
	}
	
	const char * CException::getMessage () const
	{
		return m_sMessage.c_str ();
	}

			

CModule::CModule (const std::string & sName)
	: m_sName (sName), m_bJournalIsRegistering (false)
{
}
		
CModule::~CModule ()
{
}
			
std::string CModule::getName ()
{
	return m_sName;
}
	
void CModule::handleCyclic ()
{
}
	
	
void CModule::setJournal (std::shared_ptr<CJournal> pJournal, uint32_t nJournalGroupID)
{
	if (pJournal.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");
	if (m_bJournalIsRegistering)
		throw CException (eErrorCode::JOURNALALREADYREGISTERING, "journal is already registering");
		
	m_pJournal = pJournal;
	m_nJournalGroupID = nJournalGroupID;
		
	m_pJournal->registerGroup (nJournalGroupID, m_sName);
		
	m_bJournalIsRegistering = true;
	try {
		onRegisterJournal ();
	}
	catch (...) {
		m_bJournalIsRegistering = false;
		throw;
	}
}
		
void CModule::onRegisterJournal ()
{
}
		
void CModule::onUpdateJournal ()
{
}
	
void CModule::registerIntegerValue (const std::string & sEntryName,const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
	if (!m_bJournalIsRegistering)
		throw CException (eErrorCode::JOURNALISNOTREGISTERING, "journal is not registering");
		
	m_pJournal->registerIntegerValue (sEntryName, m_nJournalGroupID, nEntryID, nMinValue, nMaxValue);
}
	
void CModule::registerBoolValue (const std::string & sEntryName,const uint32_t nEntryID)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
	if (!m_bJournalIsRegistering)
		throw CException (eErrorCode::JOURNALISNOTREGISTERING, "journal is not registering");

	m_pJournal->registerBoolValue (sEntryName, m_nJournalGroupID, nEntryID);
}
	
void CModule::registerDoubleValue (const std::string & sEntryName,const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
	if (!m_bJournalIsRegistering)
		throw CException (eErrorCode::JOURNALISNOTREGISTERING, "journal is not registering");
		
	m_pJournal->registerDoubleValue (sEntryName, m_nJournalGroupID, nEntryID, dMinValue, dMaxValue, nQuantizationSteps);
		
}
	
void CModule::registerUInt8Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, 0, UINT8_MAX);
}
	
void CModule::registerUInt16Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, 0, UINT16_MAX);
}
	
void CModule::registerUInt32Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, 0, UINT32_MAX);
}
	
void CModule::registerInt8Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, INT8_MIN, INT8_MAX);
}
	
void CModule::registerInt16Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, INT16_MIN, INT16_MAX);
}
	
void CModule::registerInt32Value (const std::string & sEntryName,const uint32_t nEntryID)
{
	registerIntegerValue (sEntryName, nEntryID, INT32_MIN, INT32_MAX);
}
			
		
void CModule::setIntegerValue (const uint32_t nEntryID, int64_t nValue)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
		
	m_pJournal->setIntegerValue (m_nJournalGroupID, nEntryID, nValue);
}
	
void CModule::setBoolValue (const uint32_t nEntryID, bool bValue)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
		
	m_pJournal->setBoolValue (m_nJournalGroupID, nEntryID, bValue);
}
	
void CModule::setDoubleValue (const uint32_t nEntryID, double dValue)
{
	if (m_pJournal.get () == nullptr)
		throw CException (eErrorCode::JOURNALNOTSET, "journal is not set");
		
	m_pJournal->setDoubleValue (m_nJournalGroupID, nEntryID, dValue);
}
	
CIOModule::CIOModule (const std::string & sName)
	: CModule (sName)
{
}
		
CIOModule::~CIOModule ()
{
}

	
CAxisModule::CAxisModule (const std::string & sName)
	: CModule (sName)
{
}
		
CAxisModule::~CAxisModule ()
{
}
	
void CAxisModule::setPowerOn ()
{
	setPower (true);
}
	
void CAxisModule::setPowerOff ()
{
	setPower (false);
}
	
CEnvironment::CEnvironment (CStateHandler * pStateHandler)
	: m_pStateHandler (pStateHandler), m_pNextState (nullptr)
{
	if (pStateHandler == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid state handler parameter");
}
	
CEnvironment::~CEnvironment ()
{
}
	
	
CState * CEnvironment::getNextState ()
{
	return m_pNextState;
}


void CEnvironment::setNextState (const std::string & sNextState)
{
	CState * pState = m_pStateHandler->findState (sNextState);
	if (pState == nullptr)
		throw CException (eErrorCode::STATENOTFOUND, "state has not been found: " + sNextState);
		
	m_pNextState = pState;
}

CModule * CEnvironment::findModule (const std::string & sName, bool bFailIfNotExist)
{
	auto pModule = m_pStateHandler->findModule (sName);
	if (pModule == nullptr) {
		if (bFailIfNotExist) 
			throw CException (eErrorCode::MODULENOTFOUND, "module has not been found: " + sName);
	}
		
	return pModule;
		
}
	
CSignalProcessingInstance * CEnvironment::checkSignal (const std::string & sName)
{
	auto pSignalHandler = m_pStateHandler->getSignalHandler();
	if (pSignalHandler != nullptr) {
		return pSignalHandler->checkSignal (sName);
	}
		
	return nullptr;
}
	
void CEnvironment::setIntegerValue (const uint32_t nEntryID, int64_t nValue)
{
	m_pStateHandler->setIntegerValue (nEntryID, nValue);
}
	
void CEnvironment::setBoolValue (const uint32_t nEntryID, bool bValue)
{
	m_pStateHandler->setBoolValue (nEntryID, bValue);
}

void CEnvironment::setDoubleValue (const uint32_t nEntryID, double dValue)
{
	m_pStateHandler->setDoubleValue (nEntryID, dValue);
}
		
bool CEnvironment::getBoolValue (const uint32_t nEntryID)
{
	return m_pStateHandler->getBoolValue (nEntryID);
}
	
double CEnvironment::getDoubleValue (const uint32_t nEntryID)
{
	return m_pStateHandler->getDoubleValue (nEntryID);
}
	
int64_t CEnvironment::getInt64Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getInt64Value (nEntryID);
}
	
int32_t CEnvironment::getInt32Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getInt32Value (nEntryID);
}
	
int16_t CEnvironment::getInt16Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getInt16Value (nEntryID);
}
	
int8_t CEnvironment::getInt8Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getInt8Value (nEntryID);
}

uint64_t CEnvironment::getUint64Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getUint64Value (nEntryID);
}
	
uint32_t CEnvironment::getUint32Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getUint32Value (nEntryID);
}
	
uint16_t CEnvironment::getUint16Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getUint32Value (nEntryID);
}
	
uint8_t CEnvironment::getUint8Value (const uint32_t nEntryID)
{
	return m_pStateHandler->getUint8Value (nEntryID);
}
	
CState::CState ()
{
}
			
CState::~CState ()
{
}

CModuleHandler::CModuleHandler (std::shared_ptr<CJournal> pJournal)
		: m_pJournal (pJournal)
{
	if (pJournal.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");
	
}
	
		
CModuleHandler::~CModuleHandler ()
{
}
	
void CModuleHandler::handleModules ()
{
	for (auto iIterator : m_Modules)
		iIterator.second->handleCyclic ();
	for (auto iIterator : m_Modules)
		iIterator.second->onUpdateJournal ();
}
		
		
CModule * CModuleHandler::findModule (const std::string & sName)
{
	auto iIter = m_Modules.find (sName);
	if (iIter != m_Modules.end ())
		return iIter->second.get();
	
	return nullptr;
}
	
void CModuleHandler::registerModule (std::shared_ptr<CModule> pModule, uint32_t nJournalGroupID)
{
	if (pModule.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid module parameter");
	
	std::string sName = pModule->getName ();
	if (findModule (sName) != nullptr)
		throw CException (eErrorCode::MODULEALREADYEXISTS, "module already exists");
	
	m_Modules.insert (std::make_pair (sName, pModule));
	
	pModule->setJournal (m_pJournal, nJournalGroupID);
	
}


CStateHandler::CStateHandler (std::shared_ptr<CJournal> pJournal, const std::string & sName, std::shared_ptr<CModuleHandler> pModuleHandler, uint32_t nJournalGroupID)
	: m_pCurrentState (nullptr), m_pStateNameDebug (nullptr), m_nStateNameDebugLength (0), m_pJournal (pJournal), m_nJournalGroupID (nJournalGroupID), m_sName (sName), m_pModuleHandler (pModuleHandler)
{
	if (pJournal.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");
		
	if (pModuleHandler.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid module handler parameter");
		
	m_pSignalHandler = std::make_shared<CSignalHandler> (pJournal->getSystemInfo ());
	pJournal->registerGroup (nJournalGroupID, getName ());
		
}
		
CStateHandler::~CStateHandler()
{
}	
	
std::string CStateHandler::getName ()
{
	return m_sName;
}
	
CState * CStateHandler::findState (const std::string & sName) {
		
	auto iIter = m_States.find (sName);
	if (iIter != m_States.end ())
		return iIter->second.get();
		
	return nullptr;
		
}
		
	
void CStateHandler::addState (std::shared_ptr<CState> pState)
{
		
	if (pState.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid state parameter");
		
	std::string sName = pState->getName ();		
	if (findState (sName) != nullptr)
		throw CException (eErrorCode::STATEALREADYEXISTS, "state already exists");
			
	m_States.insert (std::make_pair (sName, pState));
		
	if (m_pCurrentState == nullptr)
		m_pCurrentState = pState.get();
		
		
}
	
void CStateHandler::setCurrentState (CState * pState)
{
	if (pState == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid state parameter");
		
	m_pCurrentState = pState;
		
}
	
CState * CStateHandler::getCurrentState ()
{
	return m_pCurrentState;
}
	

	
	
CModule * CStateHandler::findModule (const std::string & sName)
{
	return m_pModuleHandler->findModule (sName);
}


CSignalHandler* CStateHandler::getSignalHandler ()
{
	return m_pSignalHandler.get ();
}
		
std::shared_ptr<CSignalDefinition> CStateHandler::registerSignal (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifetimeInMilliseconds)
{
	return m_pSignalHandler->registerSignal (sName, nQueueSize, nLifetimeInMilliseconds);
}
	
	
void CStateHandler::onRegister ()
{
	// Build Signal Handler Instances
	m_pSignalHandler->buildInstances ();
}
	
void CStateHandler::setDebugVariables (char * pStateNameDebug, uint32_t nStateNameDebugLength)
{
	m_pStateNameDebug = pStateNameDebug;
	m_nStateNameDebugLength = nStateNameDebugLength;
}

void CStateHandler::writeDebugInformation ()
{
	if ((m_pStateNameDebug != nullptr) && (m_nStateNameDebugLength > 0)) {
						
		if (m_pCurrentState != nullptr) {
				
			std::string sStateName = m_pCurrentState->getName();
			CUtils::writeStringVariable (sStateName, m_pStateNameDebug, m_nStateNameDebugLength);
				
		} else {
				
			CUtils::writeStringVariable ("<null>", m_pStateNameDebug, m_nStateNameDebugLength);
				
		}
			
	}
}
	
void CStateHandler::registerIntegerValue (const std::string & sEntryName,const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue)
{
	m_pJournal->registerIntegerValue (sEntryName, m_nJournalGroupID, nEntryID, nMinValue, nMaxValue);
}
		
void CStateHandler::registerBoolValue (const std::string & sEntryName,const uint32_t nEntryID)
{
	m_pJournal->registerBoolValue (sEntryName, m_nJournalGroupID, nEntryID);
}
	
void CStateHandler::registerDoubleValue (const std::string & sEntryName,const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps)
{
	m_pJournal->registerDoubleValue (sEntryName, m_nJournalGroupID, nEntryID, dMinValue, dMaxValue, nQuantizationSteps);
}

void CStateHandler::setIntegerValue (const uint32_t nEntryID, int64_t nValue)
{
	m_pJournal->setIntegerValue (m_nJournalGroupID, nEntryID, nValue );
}
	
void CStateHandler::setBoolValue (const uint32_t nEntryID, bool bValue)
{
	m_pJournal->setBoolValue (m_nJournalGroupID, nEntryID, bValue );
}
	
void CStateHandler::setDoubleValue (const uint32_t nEntryID, double dValue)
{
	m_pJournal->setDoubleValue (m_nJournalGroupID, nEntryID, dValue );
}
	
bool CStateHandler::getBoolValue (const uint32_t nEntryID)
{
	return m_pJournal->getBoolValue (m_nJournalGroupID, nEntryID);
}
		
double CStateHandler::getDoubleValue (const uint32_t nEntryID)
{
	return m_pJournal->getDoubleValue (m_nJournalGroupID, nEntryID);
}
	
int64_t CStateHandler::getInt64Value (const uint32_t nEntryID)
{
	return m_pJournal->getInt64Value (m_nJournalGroupID, nEntryID);
}
	
int32_t CStateHandler::getInt32Value (const uint32_t nEntryID)
{
	return m_pJournal->getInt32Value (m_nJournalGroupID, nEntryID);
}
	
int16_t CStateHandler::getInt16Value (const uint32_t nEntryID)
{
	return m_pJournal->getInt16Value (m_nJournalGroupID, nEntryID);
}
	
int8_t CStateHandler::getInt8Value (const uint32_t nEntryID)
{
	return m_pJournal->getInt8Value (m_nJournalGroupID, nEntryID);
}
	
uint64_t CStateHandler::getUint64Value (const uint32_t nEntryID)
{
	return m_pJournal->getUint64Value (m_nJournalGroupID, nEntryID);
}
	
uint32_t CStateHandler::getUint32Value (const uint32_t nEntryID)
{
	return m_pJournal->getUint32Value (m_nJournalGroupID, nEntryID);
}
	
uint16_t CStateHandler::getUint16Value (const uint32_t nEntryID)
{
	return m_pJournal->getUint16Value (m_nJournalGroupID, nEntryID);
}
	
uint8_t CStateHandler::getUint8Value (const uint32_t nEntryID)
{
	return m_pJournal->getUint8Value (m_nJournalGroupID, nEntryID);
}

void CStateHandler::releaseExpiredSignals ()
{
		m_pSignalHandler->releaseExpiredSignals ();
}
	

	
}

