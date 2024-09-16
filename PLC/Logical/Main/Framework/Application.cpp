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

#include "Application.hpp"
#include "Utils.hpp"

namespace BuRCPP
{
	


	
	CApplication::CApplication ()
	{
		m_pSystemInfo = std::make_shared<CSystemInfo> ();
	}
		
	CApplication::~CApplication()
	{
	}
			
	void CApplication::Initialize ()
	{
		m_pTcpServer = std::make_shared<CTcpServer> (12200, 8, 171);
		m_pListHandler = std::make_shared<CTcpListHandler> (1024, 1024, this);
		m_pJournal = std::make_shared<CJournal> (65536, m_pSystemInfo);
		
		m_pModuleHandler = std::make_shared<CModuleHandler> (m_pJournal);
	
		auto pPacketRegistry = m_pTcpServer->getPacketRegistry ();
	
		m_pListHandler->registerDefaultCommands (pPacketRegistry);
		m_pJournal->registerDefaultCommands (pPacketRegistry);
		
		registerHandlers ();
		
		fbTcpServer = (TcpServer_typ*) m_pTcpServer->getFunctionBlockServer ();
		fbTcpOpen = (TcpOpen_typ*) m_pTcpServer->getFunctionBlockOpen ();
		fbTcpClose = (TcpClose_typ*) m_pTcpServer->getFunctionBlockClose ();
	
		m_pJournal->prepareJournal ();

		m_pTcpServer->startServer ();
		
	}
	
	void CApplication::handleCyclic ()
	{
		
		// Update system information, for example System Time Counter
		m_pSystemInfo->handleCyclic ();
		
		// Handle all states
		for (auto iter : m_StateHandlers) {
			auto pStateHandler = iter.second;
			
			CState * pCurrentState = pStateHandler->getCurrentState ();
			if (pCurrentState != nullptr) {
			
				std::string sName = pCurrentState->getName();
			
				CEnvironment environment (pStateHandler.get ());
				pCurrentState->Execute (&environment);
			
				CState * pNextState = environment.getNextState ();
				if (pNextState == nullptr)
					throw CException (eErrorCode::NEXTSTATEHASNOTBEENSET, "next state has not been set!");
			
			
				pStateHandler->setCurrentState (pNextState);				
				
				pStateHandler->writeDebugInformation ();
			
			}
			
			pStateHandler->releaseExpiredSignals ();
			
			
		}
		
		m_pModuleHandler->handleModules ();
	
		
		// Handle TCP Communication
		if (m_pTcpServer.get () != nullptr) {		
			m_pTcpServer->handleServer ();				
		}
	
		// Handle List Execution
		if (m_pListHandler.get () != nullptr) {
			m_pListHandler->handleCyclic ();
		}
		
	}

		
	void CApplication::registerPacketHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler)
	{
		if (pPacketHandler.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "packet handler is null.");
				
		m_pTcpServer->registerPacketHandler (pPacketHandler);
	}
		
	void CApplication::registerStateHandler (std::shared_ptr<CStateHandler> pStateHandler)
	{
		if (pStateHandler.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "state handler is null.");
				
		std::string sName = pStateHandler->getName ();
		if (sName.empty ())
			throw CException (eErrorCode::INVALIDNAME, "state handler has empty name.");
		
		auto iIter = m_StateHandlers.find (sName);
		if (iIter != m_StateHandlers.end ())
			throw CException (eErrorCode::INVALIDNAME, "duplicate state handler registration: " + sName);
		
		pStateHandler->onRegister ();
		
		m_StateHandlers.insert (std::make_pair (sName, pStateHandler));
	}
	
	CTcpListHandler * CApplication::getListHandler ()
	{
		return m_pListHandler.get ();
	}
	
	CSignalHandler * CApplication::findSignalHandler (const std::string & sStateMachineName, bool bMustExist) 
	{
		
		auto iIter = m_StateHandlers.find (sStateMachineName);
		if (iIter != m_StateHandlers.end ()) {
			auto pStateMachineInstance = iIter->second;
			return pStateMachineInstance->getSignalHandler ();
		}
		
		if  (bMustExist)
			throw CException (eErrorCode::SIGNALHANDLERNOTFOUND, "signal handler not found: " + sStateMachineName);
		
		return nullptr;
		
	}
	
	std::shared_ptr<CJournal> CApplication::getJournal ()
	{
		return m_pJournal;
	}
	
	std::shared_ptr<CModuleHandler> CApplication::getModuleHandler ()
	{
		return m_pModuleHandler;
	}

	void CApplication::registerModule (std::shared_ptr<CModule> pModule, uint32_t nJournalGroupID)
	{
		m_pModuleHandler->registerModule (pModule, nJournalGroupID);
	}

	
}