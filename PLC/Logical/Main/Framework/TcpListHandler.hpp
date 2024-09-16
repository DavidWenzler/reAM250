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


#ifndef __TCPSYSTEMSTATE_HPP
#define __TCPSYSTEMSTATE_HPP

#include "Framework.hpp"
#include "TcpPacketHandler.hpp"
#include "SignalHandler.hpp"

#include <memory>

#define LISTCONTEXT_SIGNALSLOTCOUNT 16

namespace BuRCPP {
	
	enum class eListEntryState : int32_t {
		InQueue = 0,
		InitialExecution = 1,
		CyclicExecution = 2,
		Finished = 3,
		ExecutionError = 4
	};
	
	enum class eListState : int32_t {
		ListInQueue = 0,
		ListInCreation = 1,
		ListFinished = 2,
		ExecutingList = 3,
		ExecutionFinished = 4,
		ExecutionError = 5
	};	
	
	typedef struct _TcpListEntryContext {
		eListEntryState m_nEntryState;
		uint32_t m_nLifeTimeInMilliseconds;
		CSignalSendInstance * m_pSignalSlots[LISTCONTEXT_SIGNALSLOTCOUNT];
		uint8_t m_ContextData[32];		
	} TcpListEntryContext;
	
	class CTcpListHandler;
	
	
	class CSignalHandlerRegistry {
		private:
		public:
		
			virtual CSignalHandler * findSignalHandler (const std::string & sStateMachineName, bool bMustExist) = 0;	
	};
	
	
	class CPayloadEnvironment
	{
		private:
		
		TcpListEntryContext * m_pContext;
		TcpIncomingPayload * m_pPayload;
		CSignalHandlerRegistry * m_pSignalHandlerRegistry;
				
			
		public:
		
		CPayloadEnvironment (TcpListEntryContext * pContext, TcpIncomingPayload * pPayload, CSignalHandlerRegistry * pSignalHandlerRegistry);
		
		virtual ~CPayloadEnvironment ();
		
		eListEntryState getState ();
		
		bool isFirstCycle ();
		
		uint32_t getPayloadSize ();
		
		void readPayloadData (uint8_t * pTarget, uint32_t nAddress, uint32_t nByteCount);
		uint8_t readPayloadUint8 (uint32_t nAddress);
		uint16_t readPayloadUint16 (uint32_t nAddress);
		uint32_t readPayloadUint32 (uint32_t nAddress);
		int8_t readPayloadInt8 (uint32_t nAddress);
		int16_t readPayloadInt16 (uint32_t nAddress);
		int32_t readPayloadInt32 (uint32_t nAddress);
		double readPayloadDouble (uint32_t nAddress);
		float readPayloadFloat (uint32_t nAddress);
		
		uint32_t getContextSize ();
		
		void readContextData (uint8_t * pTarget, uint32_t nAddress, uint32_t nByteCount);
		uint8_t readContextUint8 (uint32_t nAddress);
		uint16_t readContextUint16 (uint32_t nAddress);
		uint32_t readContextUint32 (uint32_t nAddress);
		int8_t readContextInt8 (uint32_t nAddress);
		int16_t readContextInt16 (uint32_t nAddress);
		int32_t readContextInt32 (uint32_t nAddress);
		double readContextDouble (uint32_t nAddress);
		float readContextFloat (uint32_t nAddress);		

		void writeContextData (uint8_t * pSource, uint32_t nAddress, uint32_t nByteCount);
		void writeContextUint8 (uint32_t nAddress, uint8_t nValue);
		void writeContextUint16 (uint32_t nAddress, uint16_t nValue);
		void writeContextUint32 (uint32_t nAddress, uint32_t nValue);
		void writeContextInt8 (uint32_t nAddress, int8_t nValue);
		void writeContextInt16 (uint32_t nAddress, int16_t nValue);
		void writeContextInt32 (uint32_t nAddress, int32_t nValue);
		void writeContextDouble (uint32_t nAddress, double dValue);
		void writeContextFloat (uint32_t nAddress, float dValue);
		
		void setLifetimeInMillseconds (uint32_t nLifeTimeInMilliseconds);
		
		CSignalSendInstance * prepareSignal (uint32_t nSignalSlotIndex, const std::string & sStateHandlerName, const std::string & sSignalName);
		CSignalSendInstance * getSignal (uint32_t nSignalSlotIndex, bool bMustExist);
		bool signalHasBeenProcessed (uint32_t nSignalSlotIndex);
		
	};
	
	class CTcpPacketHandler_Buffered : public CTcpPacketHandler {		
		
		private:
		CTcpListHandler * m_pListHandler;

		public:

		CTcpPacketHandler_Buffered (CTcpListHandler * pListHandler);
		
		virtual ~CTcpPacketHandler_Buffered();
		
		virtual bool isBufferedCommand () override;

		virtual void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override;
		
		virtual void enterExecution (CPayloadEnvironment * pEnvironment);

		virtual bool cyclicExecution (CPayloadEnvironment * pEnvironment);
				
	};


	

	
	
	struct _TcpListEntry;
	typedef struct _TcpListEntry TcpListEntry;
	
	struct _TcpList;
	typedef struct _TcpList TcpList;
	
	struct _TcpListEntry {
		CTcpPacketHandler_Buffered * m_PacketHandler;
		TcpIncomingPayload m_Payload;
		uint32_t m_nIndexInList;
		TcpListEntryContext m_ExecutionContext;
		TcpListEntry * m_pNext;
	};
	
	
	struct _TcpList {
		uint32_t m_nListId;
		uint32_t m_nEntryCount;	
		eListState m_ListState;
		TcpListEntry * m_pFirstEntry;
		TcpListEntry * m_pLastEntry;
		TcpListEntry * m_pCurrentEntry;		
		TcpList * m_pNextUnusedList;
	};
	
	class CTcpListHandler {
	
		private:
		std::vector<TcpListEntry> m_ListEntryBuffer;
		std::vector<TcpList> m_ListBuffer;
		TcpList * m_pUnusedLists;
		TcpListEntry * m_pUnusedListEntries;
		
		TcpList * m_pCurrentWriteList;
		
		TcpList * m_pCurrentExecutionList;
		
		CSignalHandlerRegistry * m_pSignalHandlerRegistry;
			
		void addEntryToList (TcpList *, CTcpPacketHandler_Buffered * pHandler, TcpIncomingPayload * pPayload);
		
		public:
		
		CTcpListHandler (uint32_t nListBufferSize, uint32_t nListEntryBufferSize, CSignalHandlerRegistry * pSignalHandlerRegistry);
			
		virtual ~CTcpListHandler ();
		
		
			
		void registerDefaultCommands (CTcpPacketRegistry * pPacketRegistry);
			
		uint32_t beginList ();
		TcpList * finishList ();
		TcpList* executeList (uint32_t nListID);
		TcpList* getListByID (uint32_t nListID, bool bListMustExist);
			
		bool hasCurrentList ();
		
		
		
		TcpListEntry * addCommandToCurrentList (CTcpPacketHandler_Buffered * pHandler, TcpIncomingPayload * pPayload);
			
		void handleCyclic ();
			 
	};
	
	
}


#endif // __TCPSYSTEMSTATE_HPP


