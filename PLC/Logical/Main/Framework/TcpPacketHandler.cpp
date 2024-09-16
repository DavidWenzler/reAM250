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

#include "TcpPacketHandler.hpp"
#include "Utils.hpp"

#include <bur/plctypes.h>


#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <string.h>


namespace BuRCPP
{

	

	
	
	
	CTcpPacketResponse::CTcpPacketResponse ()
	:  m_nSignature (0), m_nClientID (0), m_nSequenceID (0), m_nCurrentSize (0), m_nErrorCode (0)
	{
	}
		
	CTcpPacketResponse::~CTcpPacketResponse ()
	{
	}
		
	void CTcpPacketResponse::addPayload (uint8_t * pData, uint32_t nDataSize)	
	{
		if ((pData != nullptr) && (nDataSize > 0)) {
			if (nDataSize > TCP_MAX_PACKET_RESPONSESIZE)
				throw CException (eErrorCode::INVALIDPARAM, "invalid packet response payload size.");
				
			uint32_t nNewDataSize = m_nCurrentSize + nDataSize;
			if (nNewDataSize > TCP_MAX_PACKET_RESPONSESIZE)
				throw CException (eErrorCode::INVALIDPARAM, "packet response payload overflow.");
			
			uint8_t * pSource = pData;
			uint8_t * pTarget = &m_Payload.at (m_nCurrentSize);
			
			for (uint32_t nIndex = 0; nIndex < nDataSize; nIndex++)
			{
				*pTarget = *pSource;
				pTarget++;
				pSource++;
			}
			
			m_nCurrentSize += nDataSize;
			
			
		}
	}
	
	void CTcpPacketResponse::addUint8 (uint8_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
	
	void CTcpPacketResponse::addUint16 (uint16_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
	
	void CTcpPacketResponse::addUint32 (uint32_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
		
	void CTcpPacketResponse::addInt8 (int8_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
	
	void CTcpPacketResponse::addInt16 (int16_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
		
	void CTcpPacketResponse::addInt32 (int32_t nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}
	
	void CTcpPacketResponse::addDouble (double nValue)
	{
		addPayload ((uint8_t*)&nValue, sizeof (nValue));
	}


	void CTcpPacketResponse::addString (const std::string & sValue)
	{
		uint32_t nLength = sValue.length ();
		addPayload ((uint8_t*) sValue.c_str (), nLength);
	}

	
	void CTcpPacketResponse::setErrorCode (eErrorCode nErrorCode)
	{
		m_nErrorCode = (uint32_t) nErrorCode;
	}
		
	void CTcpPacketResponse::beginResponse (uint32_t nClientID, uint32_t nSequenceID, uint32_t nSignature)
	{
		m_nClientID = nClientID;
		m_nSequenceID = nSequenceID;
		m_nCurrentSize = 0;
		m_nSignature = nSignature;
		m_nErrorCode = 0;
	}
	

	uint32_t CTcpPacketResponse::getClientID ()
	{
		return m_nClientID;
	}
	
	uint32_t CTcpPacketResponse::getSequenceID ()
	{
		return m_nSequenceID;
	}
	
	uint32_t CTcpPacketResponse::getCurrentSize ()
	{
		return m_nCurrentSize;
	}
		
	std::array<uint8_t, TCP_MAX_PACKET_RESPONSESIZE> & CTcpPacketResponse::getPayload ()
	{
		return m_Payload;
	}
	
	void CTcpPacketResponse::buildHeader (TcpOutgoingMessageHeader & header)
	{
		
		header.m_nClientId = m_nClientID;
		header.m_nPayloadLength = (uint32_t) m_nCurrentSize;
		header.m_nSequenceId = m_nSequenceID;
		header.m_nSignature = m_nSignature;
		header.m_nStatusCode = m_nErrorCode;
		
		if (m_nCurrentSize > 0) {
			header.m_nPayloadChecksum = CUtils::computeCRC32 (m_Payload.data (), (uint32_t) m_nCurrentSize);
		} else {
			header.m_nPayloadChecksum = 0;
		}
		header.m_nHeaderChecksum = CUtils::computeCRC32 ((uint8_t*) &header, sizeof (header) - 4);
	}
	
	void CTcpPacketResponse::clearPayload ()
	{
		m_nCurrentSize = 0;
	}
	
	
	
	CTcpPacketHandler::CTcpPacketHandler ()
	{
	}
	
	CTcpPacketHandler::~CTcpPacketHandler()
	{
	}
	
	uint8_t CTcpPacketHandler::readUint8FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset)
	{
		if (pPayload == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet payload param.");
		if (nOffset >= sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADOFFSET, "invalid packet payload offset.");
		
		return pPayload->m_Data[nOffset];
	}
	
	uint16_t CTcpPacketHandler::readUint16FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset)
	{
		if (pPayload == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet payload param.");
		if ((nOffset + sizeof (uint16_t)) > sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADOFFSET, "invalid packet payload offset.");
		
		return *((uint16_t*)&pPayload->m_Data[nOffset]);
	}
	
	uint32_t CTcpPacketHandler::readUint32FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset)
	{
		if (pPayload == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet payload param.");
		if ((nOffset + sizeof (uint32_t)) > sizeof (TcpIncomingPayload))
			throw CException (eErrorCode::INVALIDPAYLOADOFFSET, "invalid packet payload offset.");
		
		return *((uint32_t*)&pPayload->m_Data[nOffset]);
		
	}

	
	CTcpPacketHandler_Direct::CTcpPacketHandler_Direct ()
	: CTcpPacketHandler ()
	{
	}
		
	CTcpPacketHandler_Direct::~CTcpPacketHandler_Direct()
	{
	}

		
	bool CTcpPacketHandler_Direct::isBufferedCommand () 
	{
		return false;
	}
		
		


	CTcpPacketRegistry::CTcpPacketRegistry (uint32_t nPacketSignature)
		: m_nPacketSignature (nPacketSignature), m_bPerformChecksumCheck(false)
	{
	}
		
	CTcpPacketRegistry::~CTcpPacketRegistry()
	{
	}
		
	void CTcpPacketRegistry::registerHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler)
	{
		if (pPacketHandler.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet handler param.");
		
		uint32_t nCommand = pPacketHandler->getCommandID ();
		if (canHandlePacket (nCommand))
			throw CException (eErrorCode::PACKETHANDLERALREADYREGISTERED, "packet handler already registered: " + std::to_string (nCommand));
		
		m_Handlers.insert (std::make_pair (nCommand, pPacketHandler));
			
				
	}
		
	bool CTcpPacketRegistry::canHandlePacket (uint32_t nCommandID)
	{
		auto iIter = m_Handlers.find (nCommandID);
		return (iIter != m_Handlers.end ());
	}

	bool CTcpPacketRegistry::handlePacket (uint8_t * pData, uint32_t nDataSize, CTcpPacketResponse * pResponse)
	{
		
		if (pData == nullptr) 
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet data param.");
		if (nDataSize != sizeof (TcpIncomingMessage)) 
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet data size param.");
		if (pResponse == nullptr) 
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet response pointer.");
		
		TcpIncomingMessage * pMessage = (TcpIncomingMessage*) pData;
		uint32_t nCommandID = pMessage->m_nCommandId;
		
		if(pMessage->m_nSignature != m_nPacketSignature)
			return false;
		
		if (m_bPerformChecksumCheck) {
		
			uint32_t nChecksum = CUtils::computeCRC32 ((uint8_t*)pMessage, (uint32_t)sizeof(TcpIncomingMessage) - 4);
			if(pMessage->m_nChecksum != nChecksum)
				return false;
		}
		
		auto iIter = m_Handlers.find (nCommandID);
		if (iIter == m_Handlers.end ())
			return false;

	
		CTcpPacketHandler * pHandler = iIter->second.get();
		pResponse->beginResponse (pMessage->m_nClientId, pMessage->m_nSequenceId, pMessage->m_nSignature);
		try {
			pHandler->handlePacket (&pMessage->m_Payload, pResponse);
			return true;
			
		}
		catch (CException & E) {
			pResponse->setErrorCode (E.getCode ());
			pResponse->clearPayload ();
		}
		

		
	}

}

