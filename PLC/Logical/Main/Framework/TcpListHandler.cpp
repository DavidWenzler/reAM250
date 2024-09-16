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

#include "TcpListHandler.hpp"

#include <cstring>



namespace BuRCPP {
	

	CPayloadEnvironment::CPayloadEnvironment (TcpListEntryContext * pContext, TcpIncomingPayload * pPayload, CSignalHandlerRegistry * pSignalHandlerRegistry)
		: m_pContext (pContext), m_pPayload (pPayload), m_pSignalHandlerRegistry (pSignalHandlerRegistry)
	{
		if ((pContext == nullptr) || (pPayload == nullptr) || (pSignalHandlerRegistry == nullptr))
			throw CException (eErrorCode::INVALIDPARAM, "invalid payload environment parameters");
		
	}
		
	CPayloadEnvironment::~CPayloadEnvironment ()
	{
	}
		
	eListEntryState CPayloadEnvironment::getState ()
	{
		return m_pContext->m_nEntryState;
	}
		
	bool CPayloadEnvironment::isFirstCycle ()
	{
		return m_pContext->m_nEntryState == eListEntryState::InitialExecution;
	}
		
	uint32_t CPayloadEnvironment::getPayloadSize ()
	{
		return sizeof (TcpIncomingPayload);
	}
		
	void CPayloadEnvironment::readPayloadData (uint8_t * pTarget, uint32_t nAddress, uint32_t nByteCount)
	{
		if (nByteCount == 0)
			return;
		
		if (pTarget == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid read payload target parameter");
		
		if (nAddress >=  sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADADDRESS, "invalid payload address");
		
		if (nByteCount >=  sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADREADOPERATION, "invalid payload read size");
		if ((nAddress + nByteCount) > sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADREADOPERATION, "payload read buffer overflow");

		for (uint32_t nIndex = 0; nIndex < nByteCount; nIndex++)
			pTarget[nIndex] = m_pPayload->m_Data[nAddress + nIndex];
		
	}
	
	uint8_t CPayloadEnvironment::readPayloadUint8 (uint32_t nAddress)
	{
		uint8_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
	}
		
	uint16_t CPayloadEnvironment::readPayloadUint16 (uint32_t nAddress)	
	{
		uint16_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
	}
	
	uint32_t CPayloadEnvironment::readPayloadUint32 (uint32_t nAddress)
	{
		uint32_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
	}
	
	int8_t CPayloadEnvironment::readPayloadInt8 (uint32_t nAddress)
	{
		int8_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
	}
	
	int16_t CPayloadEnvironment::readPayloadInt16 (uint32_t nAddress)
	{
		int16_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
	}
	
	int32_t CPayloadEnvironment::readPayloadInt32 (uint32_t nAddress)
	{
		uint32_t nResult = 0;
		readPayloadData ((uint8_t*)&nResult, nAddress, sizeof (nResult));
		return nResult;
		
	}
	
	double CPayloadEnvironment::readPayloadDouble (uint32_t nAddress)
	{
		double dResult = 0.0;
		readPayloadData ((uint8_t*)&dResult, nAddress, sizeof (dResult));
		return dResult;
		
	}
	
	float CPayloadEnvironment::readPayloadFloat (uint32_t nAddress)
	{
		float fResult = 0.0;
		readPayloadData ((uint8_t*)&fResult, nAddress, sizeof (fResult));
		return fResult;
		
	}
		
	uint32_t CPayloadEnvironment::getContextSize ()
	{
		return sizeof (m_pContext->m_ContextData);
	}
		
	void CPayloadEnvironment::readContextData (uint8_t * pTarget, uint32_t nAddress, uint32_t nByteCount)
	{
	}
	
	uint8_t CPayloadEnvironment::readContextUint8 (uint32_t nAddress)
	{
		
	}
	
	uint16_t CPayloadEnvironment::readContextUint16 (uint32_t nAddress)
	{
	
	}
	
	
	uint32_t CPayloadEnvironment::readContextUint32 (uint32_t nAddress)
	{
		
	}
	
	int8_t CPayloadEnvironment::readContextInt8 (uint32_t nAddress)
	{
		
	}
		
	int16_t CPayloadEnvironment::readContextInt16 (uint32_t nAddress)
	{
	
	}
	
	int32_t CPayloadEnvironment::readContextInt32 (uint32_t nAddress)
	{
		
	}
	
	double CPayloadEnvironment::readContextDouble (uint32_t nAddress)
	{
		
	}
	
	float CPayloadEnvironment::readContextFloat (uint32_t nAddress)
	{
	
	}

	void CPayloadEnvironment::writeContextData (uint8_t * pSource, uint32_t nAddress, uint32_t nByteCount)
	{
		
	}
	
	void CPayloadEnvironment::writeContextUint8 (uint32_t nAddress, uint8_t nValue)
	{
	}
	
	void CPayloadEnvironment::writeContextUint16 (uint32_t nAddress, uint16_t nValue)
	{
	}
	
	void CPayloadEnvironment::writeContextUint32 (uint32_t nAddress, uint32_t nValue)
	{
	}
	
	void CPayloadEnvironment::writeContextInt8 (uint32_t nAddress, int8_t nValue)
	{
	}
	
	void CPayloadEnvironment::writeContextInt16 (uint32_t nAddress, int16_t nValue)
	{
	}
		
	void CPayloadEnvironment::writeContextInt32 (uint32_t nAddress, int32_t nValue)
	{
	}
	
	void CPayloadEnvironment::writeContextDouble (uint32_t nAddress, double dValue)
	{
	}
	
	void CPayloadEnvironment::writeContextFloat (uint32_t nAddress, float dValue)
	{
	}
	
	
	void CPayloadEnvironment::setLifetimeInMillseconds (uint32_t nLifeTimeInMilliseconds)
	{
		m_pContext->m_nLifeTimeInMilliseconds = nLifeTimeInMilliseconds;
	}
		
	CSignalSendInstance * CPayloadEnvironment::prepareSignal (uint32_t nSignalSlotIndex, const std::string & sStateHandlerName, const std::string & sSignalName)
	{
		if (nSignalSlotIndex >= LISTCONTEXT_SIGNALSLOTCOUNT)
			throw CException (eErrorCode::INVALIDSIGNALSLOTINDEX, "invalid payload signal slot index: " + std::to_string (nSignalSlotIndex));

		if (m_pContext->m_pSignalSlots[nSignalSlotIndex] != nullptr)
			throw CException (eErrorCode::PAYLOADSIGNALSLOTALREADYTAKEN, "signal slot already taken: " + std::to_string (nSignalSlotIndex));
		
		auto pSignalHandler = m_pSignalHandlerRegistry->findSignalHandler (sStateHandlerName, true);
		
		CSignalSendInstance * pSignalInstance = pSignalHandler->prepareSignal (sSignalName);		
		
		m_pContext->m_pSignalSlots[nSignalSlotIndex] = pSignalInstance;
		
		return pSignalInstance;
	}
	
	CSignalSendInstance * CPayloadEnvironment::getSignal (uint32_t nSignalSlotIndex, bool bMustExist)
	{
		if (nSignalSlotIndex >= LISTCONTEXT_SIGNALSLOTCOUNT)
			throw CException (eErrorCode::INVALIDSIGNALSLOTINDEX, "invalid payload signal slot index: " + std::to_string (nSignalSlotIndex));
		
		CSignalSendInstance * pSignalInstance =	m_pContext->m_pSignalSlots[nSignalSlotIndex];
		if ((pSignalInstance == nullptr) && bMustExist)
			throw CException (eErrorCode::SIGNALSLOTISEMPTY, "payload signal slot is empty: " + std::to_string (nSignalSlotIndex));
		
		return pSignalInstance;
	}
	
	bool CPayloadEnvironment::signalHasBeenProcessed (uint32_t nSignalSlot)
	{
		CSignalSendInstance * pSignalInstance = getSignal (nSignalSlot, true);
		return pSignalInstance->signalHasBeenProcessed ();
	}
	
	class CTcpPacketHandler_BeginList : public CTcpPacketHandler_Direct {
		private:
			CTcpListHandler* m_pListHandler;
		
		public: 
		
			CTcpPacketHandler_BeginList (CTcpListHandler * pListHandler)
			: CTcpPacketHandler_Direct (), m_pListHandler (pListHandler)
				{
				}
		
			virtual ~CTcpPacketHandler_BeginList ()
			{
			}
			
		
			virtual uint32_t getCommandID () override
			{
				return COMMAND_DEFAULT_BEGINLIST;
			}
						
			void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
			{
				beginListCalled++;
				pResponse->addUint32(m_pListHandler->beginList ());
			}
	
	};	


	
	class CTcpPacketHandler_FinishList : public CTcpPacketHandler_Direct {
		private:
		CTcpListHandler* m_pListHandler;
			
		public: 
			
		CTcpPacketHandler_FinishList (CTcpListHandler * pListHandler)
			: CTcpPacketHandler_Direct (), m_pListHandler (pListHandler)
		{
		}
			
		virtual ~CTcpPacketHandler_FinishList ()
		{
		}
				
			
		virtual uint32_t getCommandID () override
		{
			return COMMAND_DEFAULT_FINISHLIST;
		}
						
			void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
			{
				finishListCalled++;
				TcpList* pList = m_pListHandler->finishList ();
				pResponse->addUint32(pList->m_nListId);
				pResponse->addUint32(pList->m_nEntryCount);
			}
	
	};
	
	class CTcpPacketHandler_ExecuteList : public CTcpPacketHandler_Direct {
		private:
		CTcpListHandler* m_pListHandler;
			
		public: 
			
		CTcpPacketHandler_ExecuteList (CTcpListHandler * pListHandler)
			: CTcpPacketHandler_Direct (), m_pListHandler (pListHandler)
		{
		}
			
		virtual ~CTcpPacketHandler_ExecuteList ()
		{
		}
				
			
		virtual uint32_t getCommandID () override
		{
			return COMMAND_DEFAULT_EXECUTELIST;
		}
					
		void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
		{
			uint32_t nListID = readUint32FromPayload (pPayload, 0);
			TcpList * pList = m_pListHandler->executeList (nListID);
		
			pResponse->addUint32(pList->m_nEntryCount);
		}
	};

		class CTcpPacketHandler_ListStatus : public CTcpPacketHandler_Direct {
			private:
			CTcpListHandler* m_pListHandler;
					
			public: 
					
				CTcpPacketHandler_ListStatus (CTcpListHandler * pListHandler)
					: CTcpPacketHandler_Direct (), m_pListHandler (pListHandler)
				{
				}
					
				virtual ~CTcpPacketHandler_ListStatus ()
				{
				}
						
					
				virtual uint32_t getCommandID () override
				{
					return COMMAND_DEFAULT_LISTSTATUS;
				}
							
				void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
				{
					uint32_t nListID = readUint32FromPayload (pPayload, 0);
					TcpList * pList = m_pListHandler->getListByID (nListID, false);

					if (pList != nullptr) {
						pResponse->addUint32(pList->m_nListId);
						pResponse->addUint32((uint32_t)pList->m_ListState);
						pResponse->addUint32(pList->m_nEntryCount);
						if (pList->m_pCurrentEntry != nullptr) {
							pResponse->addUint32(pList->m_pCurrentEntry->m_nIndexInList);
						} else {
							pResponse->addUint32(0);
						}

					} else {
						pResponse->addUint32(0);
						pResponse->addUint32(0);
						pResponse->addUint32(0);
						pResponse->addUint32(0);
					}
				
					
				}
			
	};	

	
CTcpPacketHandler_Buffered::CTcpPacketHandler_Buffered (CTcpListHandler * pListHandler)
	: CTcpPacketHandler (), m_pListHandler (pListHandler)
{
}
		
CTcpPacketHandler_Buffered::~CTcpPacketHandler_Buffered()
{
}
	
			
bool CTcpPacketHandler_Buffered::isBufferedCommand () 
{
	return true;
}
	
void CTcpPacketHandler_Buffered::handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse)
{			
	TcpListEntry* pNewEntry = m_pListHandler->addCommandToCurrentList (this, pPayload);
	pResponse->addUint32(pNewEntry->m_nIndexInList);
	
}

void CTcpPacketHandler_Buffered::enterExecution (CPayloadEnvironment * pEnvironment)
{
	
}

bool CTcpPacketHandler_Buffered::cyclicExecution (CPayloadEnvironment * pEnvironment)
{
	return true; 
}

	
	
	CTcpListHandler::CTcpListHandler (uint32_t nListBufferSize, uint32_t nListEntryBufferSize, CSignalHandlerRegistry * pSignalHandlerRegistry)
	: m_pUnusedLists (nullptr), m_pUnusedListEntries (nullptr), m_pCurrentWriteList (nullptr), m_pCurrentExecutionList (nullptr), m_pSignalHandlerRegistry (pSignalHandlerRegistry)
	{
	
		if (pSignalHandlerRegistry == nullptr)
			throw std::runtime_error ("invalid signal handler registry param");
	
		m_ListEntryBuffer.resize (nListEntryBufferSize);
		m_ListBuffer.resize (nListBufferSize);
	
		uint32_t nListIndex = nListBufferSize;	
		while (nListIndex > 0) {
			nListIndex--;
		
			auto pList = &m_ListBuffer[nListIndex];
			pList->m_nListId = nListIndex + 1;
			pList->m_nEntryCount = 0;
			pList->m_pLastEntry = nullptr;
			pList->m_pFirstEntry = nullptr;
			pList->m_pCurrentEntry = nullptr;
			pList->m_ListState = eListState::ListInQueue;
			
			pList->m_pNextUnusedList = m_pUnusedLists;
			m_pUnusedLists = pList;
			
		}
	
		uint32_t nListEntryIndex = nListEntryBufferSize;	
		while (nListEntryIndex > 0) {
			nListEntryIndex--;
			
			auto pListEntry = &m_ListEntryBuffer[nListEntryIndex];
			pListEntry->m_pNext = m_pUnusedListEntries;
			pListEntry->m_PacketHandler = nullptr;
			pListEntry->m_nIndexInList = 0;
			memset ((void*) &pListEntry->m_Payload, 0, sizeof (pListEntry->m_Payload));
			m_pUnusedListEntries = pListEntry;
				
		}
	}
		
	CTcpListHandler::~CTcpListHandler ()
	{
	}
		
	void CTcpListHandler::registerDefaultCommands (CTcpPacketRegistry * pPacketRegistry)
	{
		if (pPacketRegistry == nullptr) 
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet registry parameter");
	
		pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_BeginList> (this));
		pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_FinishList> (this));
		pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_ExecuteList> (this));
		pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_ListStatus> (this));
	
	}
		
	uint32_t CTcpListHandler::beginList ()
	{
		if (m_pUnusedLists == nullptr)
			throw CException (eErrorCode::TOOMANYOPENLISTS, "too many open lists!");
	
		if (m_pUnusedLists->m_ListState != eListState::ListInQueue)
			throw CException (eErrorCode::LISTISNOTINQUEUE, "list is not in queue!");
	
		m_pCurrentWriteList = m_pUnusedLists;
		m_pUnusedLists = m_pUnusedLists->m_pNextUnusedList;

		m_pCurrentWriteList->m_nEntryCount = 0;
		m_pCurrentWriteList->m_pCurrentEntry = nullptr;
		m_pCurrentWriteList->m_pFirstEntry = nullptr;
		m_pCurrentWriteList->m_pLastEntry = nullptr;
		m_pCurrentWriteList->m_pNextUnusedList = nullptr;
		m_pCurrentWriteList->m_ListState = eListState::ListInCreation;
	
		return m_pCurrentWriteList->m_nListId;
	}


	TcpList* CTcpListHandler::finishList ()
	{
	
		if (m_pCurrentWriteList == nullptr)
			throw CException (eErrorCode::NOTWRITINGTOANYLIST, "not writing to any list!");
		if (m_pCurrentWriteList->m_ListState != eListState::ListInCreation)
			throw CException (eErrorCode::NOTINLISTCREATION, "list not in creation!");	
		if (m_pCurrentWriteList->m_pFirstEntry == nullptr)
			throw CException (eErrorCode::LISTISEMPTY, "list is empty!");
	
		auto pList = m_pCurrentWriteList;
		m_pCurrentWriteList = nullptr;
	
		pList->m_ListState = eListState::ListFinished;
		return pList;
	}


	TcpList* CTcpListHandler::getListByID (uint32_t nListID, bool bListMustExist)
	{
		TcpList * pList = nullptr;
		if ((nListID > 0) || (nListID <= m_ListBuffer.size ())) {
			pList = &m_ListBuffer.at (nListID - 1);
			if (pList->m_ListState == eListState::ListInQueue)
				pList = nullptr;
		}
	
		if ((pList == nullptr) && bListMustExist)
			throw CException (eErrorCode::LISTDOESNOTEXIST, "list does not exist");
	
		return pList;
	}

	TcpList* CTcpListHandler::executeList (uint32_t nListID)
	{
		m_pCurrentExecutionList = nullptr;
	
		if ((nListID == 0) || (nListID > m_ListBuffer.size ()))
			throw CException (eErrorCode::INVALIDLISTID, "invalid list ID");
	
		auto pList = &m_ListBuffer.at (nListID - 1);	
		if (pList->m_ListState != eListState::ListFinished)
			throw CException (eErrorCode::LISTISNOTFINISHED, "list is not in finished!");
		if (pList->m_pFirstEntry == nullptr)
			throw CException (eErrorCode::LISTISEMPTY, "list is empty!");
	
		m_pCurrentExecutionList = pList;	
		m_pCurrentExecutionList->m_pCurrentEntry = m_pCurrentExecutionList->m_pFirstEntry;
		m_pCurrentExecutionList->m_ListState = eListState::ExecutingList;
	
		return m_pCurrentExecutionList;
	}

	bool CTcpListHandler::hasCurrentList ()
	{
		return (m_pCurrentWriteList != nullptr);
	}

		
	TcpListEntry* CTcpListHandler::addCommandToCurrentList (CTcpPacketHandler_Buffered * pHandler, TcpIncomingPayload * pPayload)
	{
		if (pHandler == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet handler parameter");
		if (pPayload == nullptr)
			throw CException (eErrorCode::INVALIDPAYLOAD, "invalid payload.");	
		if (m_pCurrentWriteList == nullptr)
			throw CException (eErrorCode::NOLISTTOWRITETO, "no list to write to.");	
		if (m_pUnusedListEntries == nullptr)
			throw CException (eErrorCode::NOLISTENTRIESLEFT, "no list entries left");
	
		auto pNewListEntry = m_pUnusedListEntries;
		m_pUnusedListEntries = m_pUnusedListEntries->m_pNext;
	
		pNewListEntry->m_PacketHandler = pHandler;
		pNewListEntry->m_Payload = *pPayload;
		pNewListEntry->m_pNext = nullptr;
		pNewListEntry->m_nIndexInList = m_pCurrentWriteList->m_nEntryCount;
	
		memset ((void*)&pNewListEntry->m_ExecutionContext, 0, sizeof (pNewListEntry->m_ExecutionContext));
		pNewListEntry->m_ExecutionContext.m_nEntryState = eListEntryState::InQueue;
	
		m_pCurrentWriteList->m_nEntryCount++;
		if (m_pCurrentWriteList->m_pFirstEntry == nullptr) 
			m_pCurrentWriteList->m_pFirstEntry = pNewListEntry;		
		if (m_pCurrentWriteList->m_pLastEntry != nullptr)
			m_pCurrentWriteList->m_pLastEntry->m_pNext = pNewListEntry;
		m_pCurrentWriteList->m_pLastEntry = pNewListEntry;
	
		bufferedListEntries++;
		
		return pNewListEntry;
	}


	void CTcpListHandler::handleCyclic ()
	{
		if (m_pCurrentExecutionList != nullptr) {
		
			auto pEntryToExecute = m_pCurrentExecutionList->m_pCurrentEntry;
			if (pEntryToExecute != nullptr) {
				switch (pEntryToExecute->m_ExecutionContext.m_nEntryState) {
					case eListEntryState::InQueue:
					{
						pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::InitialExecution;
						break;
					}
					
					case eListEntryState::InitialExecution: 
					{
						try {
						
							if (pEntryToExecute->m_PacketHandler == nullptr)
								throw CException (eErrorCode::INTERNALLISTERROR, "internal list error");						
						
							CPayloadEnvironment environment (&pEntryToExecute->m_ExecutionContext, &pEntryToExecute->m_Payload, m_pSignalHandlerRegistry);
							
							pEntryToExecute->m_PacketHandler->enterExecution (&environment);							
							pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::CyclicExecution;
							
						} catch (...) {
							pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::ExecutionError;
						}

						break;
					}
					
					
					case eListEntryState::CyclicExecution: 
					{
						try {
						
							if (pEntryToExecute->m_PacketHandler == nullptr)
								throw CException (eErrorCode::INTERNALLISTERROR, "internal list error");						
						
							CPayloadEnvironment environment (&pEntryToExecute->m_ExecutionContext, &pEntryToExecute->m_Payload, m_pSignalHandlerRegistry);
							
							bool bIsFinished = pEntryToExecute->m_PacketHandler->cyclicExecution (&environment);
							if (bIsFinished) {
								pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::Finished;
							} else {
								pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::CyclicExecution;
							}
							
						} catch (...) {
							pEntryToExecute->m_ExecutionContext.m_nEntryState = eListEntryState::ExecutionError;
						}

						break;
					}
					
					case eListEntryState::Finished:
					{
						m_pCurrentExecutionList->m_pCurrentEntry = pEntryToExecute->m_pNext;						
						break;
					}
					
					case eListEntryState::ExecutionError:
					{
						m_pCurrentExecutionList = nullptr;
						break;
					}
					
				}
			
			}
		
		}
	}

}

