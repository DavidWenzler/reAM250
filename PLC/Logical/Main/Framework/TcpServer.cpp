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

#include "TcpServer.hpp"

#include <bur/plctypes.h>


#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <string.h>



namespace BuRCPP
{


	class CTcpServerImpl
	{
		private:
		
		TcpOpen_typ m_TcpOpen;
		TcpServer_typ m_TcpServer;
		TcpClose_typ m_TcpClose;
		
		char m_ServerClientAddress[80];
		
		public:
		
		CTcpServerImpl () {
			memset ((void*) &m_TcpOpen, 0, sizeof (m_TcpOpen));
			memset ((void*) &m_TcpServer, 0, sizeof (m_TcpServer));
			memset ((void*) &m_TcpClose, 0, sizeof (m_TcpClose));
						
		}
		
		void handleCyclic ()
		{
			TcpOpen(&m_TcpOpen);
			TcpServer(&m_TcpServer);
			TcpClose(&m_TcpClose);
		}
		
		void * getFunctionBlockOpen ()
		{
			return &m_TcpOpen;
		}

		void * getFunctionBlockClose ()
		{
			return &m_TcpClose;
		}

		void * getFunctionBlockServer ()
		{
			return &m_TcpServer;
		}
		
		void initialiseTCP (uint32_t nPort)
		{
			m_TcpOpen.pIfAddr = 0; // Take IP Adress vom ETH Configuration
			m_TcpOpen.port = nPort;
			m_TcpOpen.options = 0;
			m_TcpOpen.enable = 1;
		}
		
		bool tcpOpenIsBusy ()
		{
			return (tcpOpenErrorCode () == 65535);
		}
		
		bool tcpOpenIsFinished ()
		{
			return (tcpOpenErrorCode () == 0);
		}
		
		uint32_t tcpOpenErrorCode ()
		{
			return m_TcpOpen.status;
		}
		
		uint32_t tcpOpenIdent ()
		{
			return m_TcpOpen.ident;
		}
		
		uint32_t tcpListenClientIdent ()
		{
			return m_TcpServer.identclnt;
		}
		
		bool tcpListenClientConnected ()
		{
			return (tcpListenErrorCode () == 0);
		}

		bool tcpListenIsBusy ()
		{
			return (tcpListenErrorCode() == 65535);
		}
		
		uint32_t tcpListenErrorCode ()
		{
			return m_TcpServer.status;
		}
				
		bool tcpCloseFinished ()
		{
			return (tcpCloseErrorCode () == 0);
		}

		bool tcpCloseIsBusy ()
		{
			return (tcpCloseErrorCode() == 65535);
		}
		
		uint32_t tcpCloseErrorCode ()
		{
			return m_TcpClose.status;
		}
						
		
		void listenOnSocket (uint32_t nSocketIdent, uint32_t nMaxConnections)
		{
			//Configure TCP Server
			m_TcpServer.enable = 1;
			m_TcpServer.ident = nSocketIdent;
			m_TcpServer.backlog = nMaxConnections;
			m_TcpServer.pIpAddr = (UDINT)&m_ServerClientAddress;			
		}
		
		void closeClientConnection (uint32_t nClientIdent)
		{
			m_TcpClose.enable = 1;
			m_TcpClose.ident = nClientIdent;
			m_TcpClose.how = 0;
			
		}
		
		void resetClose ()
		{
			m_TcpClose.enable = 0;
		}
	
	};
	
	
	class CTcpConnectionImpl
	{
		private:
		
			TcpRecv_typ m_TcpReceive;
			TcpSend_typ m_TcpSend;
			TcpClose_typ m_TcpClose;
		
		public:
		
			CTcpConnectionImpl () {
				resetFunctionBlocks ();
							
			}
		
			virtual ~CTcpConnectionImpl ()
			{
			}
		
			void resetFunctionBlocks ()
			{
			memset ((void*) &m_TcpReceive, 0, sizeof (m_TcpReceive));
			memset ((void*) &m_TcpSend, 0, sizeof (m_TcpSend));
			memset ((void*) &m_TcpClose, 0, sizeof (m_TcpClose));
		}
		
		
		void handleCyclic ()
		{
			TcpRecv(&m_TcpReceive);
			TcpSend(&m_TcpSend);
		}
		
		
		void * getFunctionBlockClose ()
		{
			return &m_TcpClose;
		}

		void * getFunctionBlockSend ()
		{
			return &m_TcpSend;
		}

		void * getFunctionBlockRecv ()
		{
			return &m_TcpReceive;
		}
		
		void initReceive (uint32_t nClientIdent, void * pBuffer, uint32_t nBufferSize)
		{
			m_TcpReceive.enable = 1;
			m_TcpReceive.ident = nClientIdent;
			m_TcpReceive.flags = 0;
			m_TcpReceive.datamax = nBufferSize;
			m_TcpReceive.pData = (UDINT) pBuffer;
		}
		
		void resetReceive ()
		{
			memset ((void*) &m_TcpReceive, 0, sizeof (m_TcpReceive));
		}
		
		
		bool tcpRecvIsFinished ()
		{
			return (tcpRecvErrorCode () == 0);
		}
		
		bool tcpRecvIsBusy ()
		{
			return (tcpRecvErrorCode () == 65535) || (tcpRecvErrorCode () == 32605);
		}
		
		uint32_t tcpRecvErrorCode ()
		{
			return m_TcpReceive.status;
		}
		
		uint32_t tcpBytesReceived ()
		{
			return m_TcpReceive.recvlen;
		}

		void initSend (uint32_t nClientIdent, void * pBuffer, uint32_t nBufferSize)
		{
			m_TcpSend.enable = 1;
			m_TcpSend.ident = nClientIdent;
			m_TcpSend.datalen = nBufferSize;
			m_TcpSend.flags = 0;
			m_TcpSend.pData = (UDINT) pBuffer;
		}
		
		void resetSend ()
		{
			memset ((void*) &m_TcpSend, 0, sizeof (m_TcpSend));
		}
		
		bool tcpSendIsFinished ()
		{
			return (tcpSendErrorCode () == 0);
		}
		
		bool tcpSendIsBusy ()
		{
			return (tcpSendErrorCode () == 65535);
		}
		
		uint32_t tcpSendErrorCode ()
		{
			return m_TcpSend.status;
		}
		
		uint32_t tcpBytesSent ()
		{
			return m_TcpSend.sentlen;
		}

		
	};
	
	
	
	CTcpConnection::CTcpConnection (uint32_t nReceiveBufferSize, uint32_t nSendBufferSize, CTcpPacketRegistry* pPacketRegistry)
		: m_SendState (eTcpConnectionSend_State::INACTIVE),
		m_RecvState (eTcpConnectionRecv_State::INACTIVE),
		m_ClientIdent (0), m_LastError (0), 
		m_SendBufferInProcessSize (0), 
		m_SendBufferNextInQueueSize (0),
		m_SendBufferMemorySize (nSendBufferSize),
		m_pPacketRegistry (pPacketRegistry)
		
	{
		if (pPacketRegistry == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid packet registry.");
		if ((nReceiveBufferSize < TCPMINBUFFERSIZE) || (nReceiveBufferSize > TCPMAXBUFFERSIZE))
			throw CException (eErrorCode::INVALIDTCPBUFFERSIZE, "invalid tcp buffer size.");
		if ((nSendBufferSize < TCPMINBUFFERSIZE) || (nSendBufferSize > TCPMAXBUFFERSIZE))
			throw CException (eErrorCode::INVALIDTCPBUFFERSIZE, "invalid tcp buffer size.");
		
		m_pImpl.reset ( new CTcpConnectionImpl () );
		m_ReceiveBuffer.resize (nReceiveBufferSize);
		m_SendBuffer1.resize (nSendBufferSize);
		m_SendBuffer2.resize (nSendBufferSize);
		m_pSendBufferInProcess = m_SendBuffer1.data();
		m_pSendBufferNextInQueue = m_SendBuffer2.data();
	}
	
		
	CTcpConnection::~CTcpConnection()
	{
			
	}
		
	void CTcpConnection::initialize (uint32_t clientIdent)
	{
		m_pImpl->resetFunctionBlocks ();
		m_ClientIdent = clientIdent;
		m_pImpl->initReceive (m_ClientIdent, m_ReceiveBuffer.data (), m_ReceiveBuffer.size ());
		m_RecvState = eTcpConnectionRecv_State::WAITINGFORDATA;
		m_SendState = eTcpConnectionSend_State::WAITINGFORDATA;
		m_LastError = 0;
		m_SendBufferInProcessSize = 0;
		m_SendBufferNextInQueueSize = 0;
	}
		
	
	bool CTcpConnection::canSendData (uint32_t nByteCount)
	{
		if (nByteCount > m_SendBufferMemorySize)
			return false;
		
		if (m_SendBufferNextInQueueSize + nByteCount > m_SendBufferMemorySize)
			return false;
		
		return true;
	}
		
	void CTcpConnection::sendData (uint8_t * pBytes, uint32_t nByteCount)
	{
		if ((pBytes == nullptr) || (nByteCount == 0))
			return;
	
		if (nByteCount > m_SendBufferMemorySize)
			throw CException (eErrorCode::TCPSENDBUFFERSIZEEXCEEDED, "tcp send byte count exceeds buffer size.");
		
		if (m_SendBufferNextInQueueSize + nByteCount > m_SendBufferMemorySize)
			throw CException (eErrorCode::TCPSENDBUFFERISFULL, "tcp send buffer is full.");
		
		uint8_t * pSource = pBytes;
		uint8_t * pTarget = &m_pSendBufferNextInQueue[m_SendBufferNextInQueueSize];
		memcpy (pTarget, pSource, nByteCount);
		m_SendBufferNextInQueueSize += nByteCount;
		queueDataCounter++;
		queueDataBytes += nByteCount;
				
	}
	
	void CTcpConnection::handleCyclic ()
	{
		
		queueLength = m_SendBufferNextInQueueSize;
		sendLength = m_SendBufferInProcessSize;
		currentSendBuffer = (uint8_t*) &m_pSendBufferInProcess[0];
		currentQueueBuffer = (uint8_t*) &m_pSendBufferNextInQueue[0];
		
		
		switch (m_RecvState) {
			
			case eTcpConnectionRecv_State::WAITINGFORDATA:
				
							
				if (m_pImpl->tcpRecvIsFinished ()) {
					uint32_t bytesReceived = m_pImpl->tcpBytesReceived ();
					m_pImpl->resetReceive();
					
					if (bytesReceived > 0) {
						
						bool bHadError = false;
						uint8_t * pData = m_ReceiveBuffer.data();
						uint32_t bytesToHandle = bytesReceived;
						while ((!bHadError) && (bytesToHandle >= sizeof (TcpIncomingMessage))) {
							
							if (m_pPacketRegistry->handlePacket (pData, sizeof (TcpIncomingMessage), &m_TempResponse)) {
								
								TcpOutgoingMessageHeader responseHeader;
								m_TempResponse.buildHeader (responseHeader);
																
								auto & payLoad = m_TempResponse.getPayload();
								uint32_t nPayLoadSize = m_TempResponse.getCurrentSize();													

								sendData ((uint8_t*) &responseHeader, sizeof (responseHeader));
								if (nPayLoadSize > 0)
									sendData (&payLoad[0], nPayLoadSize);
								
								
								pData += sizeof (TcpIncomingMessage);
								bytesToHandle -= sizeof (TcpIncomingMessage);
								
							} else {
								bHadError = true;
							}

														
						}
						
						if (bHadError ||(bytesToHandle > 0)) {
							
							m_RecvState = eTcpConnectionRecv_State::ERROR;
							
						} else {							
							m_RecvState = eTcpConnectionRecv_State::RESETCONNECTION;
						}
						
						
					} else {
						
						m_RecvState = eTcpConnectionRecv_State::RESETCONNECTION;
						
					}
					
					totalBytesReceived += bytesReceived;
																		
					
					
					
					
				} else if (m_pImpl->tcpRecvIsBusy ()) {
					m_RecvState = eTcpConnectionRecv_State::WAITINGFORDATA;					
				}
				else {			
					m_RecvState = eTcpConnectionRecv_State::ERROR;
					m_LastError = m_pImpl->tcpRecvErrorCode ();
				}
										
				break;
			
			
			case eTcpConnectionRecv_State::RESETCONNECTION:
				m_pImpl->initReceive (m_ClientIdent, m_ReceiveBuffer.data (), m_ReceiveBuffer.size ());
				m_RecvState = eTcpConnectionRecv_State::WAITINGFORDATA;					
										
				break;
			
			case eTcpConnectionRecv_State::INACTIVE:
				break;
			
			case eTcpConnectionRecv_State::ERROR:
				break;
			
			default:
				throw CException (eErrorCode::UNKNOWNTCPRECVSTATE, "tcp connection is in unknown recv state.");
		}
		
		switch (m_SendState)
		{
			case eTcpConnectionSend_State::WAITINGFORDATA: 			
				if (m_SendBufferNextInQueueSize > 0) {
					m_SendBufferInProcessSize = m_SendBufferNextInQueueSize;
					m_SendBufferNextInQueueSize = 0;
					
					std::swap (m_pSendBufferInProcess, m_pSendBufferNextInQueue);
					
					m_pImpl->initSend (m_ClientIdent, m_pSendBufferInProcess, m_SendBufferInProcessSize);
					
					m_SendState = eTcpConnectionSend_State::SENDING;
					
				} else {
					m_SendState = eTcpConnectionSend_State::WAITINGFORDATA;
				}
				break;
			
			case eTcpConnectionSend_State::SENDING:
				
				if (m_pImpl->tcpSendIsFinished ())
				{
					uint32_t bytesSent = m_pImpl->tcpBytesSent ();
					m_pImpl->resetSend ();
					m_SendState = eTcpConnectionSend_State::WAITINGFORDATA;
					
				} else if (m_pImpl->tcpSendIsBusy ())
				{
					m_SendState = eTcpConnectionSend_State::SENDING;
				} else {
					m_SendState = eTcpConnectionSend_State::ERROR;
				}
				
				break;
			
			case eTcpConnectionSend_State::INACTIVE:
				break;
			
			case eTcpConnectionSend_State::ERROR:
				break;
		
			default:
				throw CException (eErrorCode::UNKNOWNTCPSENDSTATE, "tcp connection is in unknown send state.");
		}
	
		
		
		m_pImpl->handleCyclic ();
	}
	
	
	CTcpServer::CTcpServer (uint32_t port, uint32_t maxConnections, uint32_t nPacketSignature)
		: m_State (eTcpServer_State::INACTIVE), m_Port (port), m_LastError (0), m_MaxConnections (maxConnections)
	{
		m_pImpl.reset ( new CTcpServerImpl () );			
		m_PacketRegistry.reset (new CTcpPacketRegistry (nPacketSignature));
							
		for (uint32_t nIndex = 0; nIndex < m_MaxConnections; nIndex++) {
			m_InactiveConnections.push_back (std::make_shared<CTcpConnection> (1024, 1024*1024, m_PacketRegistry.get()));
		}
		
	}
	
		
		

	
CTcpServer::~CTcpServer()
{
		
}
		
		
bool CTcpServer::serverRunning ()
{
	return (m_State != eTcpServer_State::INACTIVE);
}
		
bool CTcpServer::clientConnected ()
{
	throw CException (eErrorCode::NOTIMPLEMENTED, "not implemented");
	//return (m_TcpServer.identclnt != 0);
}

void CTcpServer::startServer ()
{
	if (m_State != eTcpServer_State::INACTIVE)
		throw CException (eErrorCode::SERVERISALREADYRUNNING, "server is already running");
		
	m_State = eTcpServer_State::INIT;
}
		
void CTcpServer::stopServer ()
{
	if (m_State == eTcpServer_State::INACTIVE)
		throw CException (eErrorCode::SERVERISALREADYRUNNING, "server is already stopped");
		
	m_State = eTcpServer_State::INACTIVE;
}
	
	
bool CTcpServer::enableConnection (uint32_t nClientIdent)
{
	if (m_InactiveConnections.empty ()) {
		return false;
	}
		
	auto iIter = m_InactiveConnections.begin ();
	auto pConnection = *iIter;
	m_InactiveConnections.erase (iIter);
		
	pConnection->initialize (nClientIdent);		
	m_ActiveConnections.push_back (pConnection);		
		
	return true;
	
		
}
	
	
void CTcpServer::handleServer ()
{
		
	switch (m_State) {
		case eTcpServer_State::INIT:
			m_pImpl->initialiseTCP (m_Port);
			m_State = eTcpServer_State::INITIALIZING;
			break;
			
		case eTcpServer_State::INITIALIZING:
			
			if (m_pImpl->tcpOpenIsFinished ()) {
				m_pImpl->listenOnSocket (m_pImpl->tcpOpenIdent (), m_MaxConnections);
				m_State = eTcpServer_State::LISTENING;
					
			} else if (m_pImpl->tcpOpenIsBusy ()) {
				m_State = eTcpServer_State::INITIALIZING;
					
			}
			else {
			
				m_State = eTcpServer_State::ERROR;
				m_LastError = m_pImpl->tcpOpenErrorCode ();
			}
										
			break;
			
		case eTcpServer_State::LISTENING:
				
			if (m_pImpl->tcpListenClientConnected ()) {
				
				uint32_t nClientIdent = m_pImpl->tcpListenClientIdent ();
				
				if (enableConnection (nClientIdent)) {
					m_State = eTcpServer_State::LISTENING;
				} else {
					//  Too many connections!
					m_pImpl->closeClientConnection (nClientIdent);
					m_State = eTcpServer_State::CLOSINGCONNECTION;
				}
			
			
			} else if (m_pImpl->tcpListenIsBusy ()) {
				m_State = eTcpServer_State::LISTENING;
				
			}
			else {
		
				m_State = eTcpServer_State::ERROR;
				m_LastError = m_pImpl->tcpListenErrorCode ();
			}
		
			break;
			
		case eTcpServer_State::CLOSINGCONNECTION:
				if (m_pImpl->tcpCloseFinished ()) {
					
					m_pImpl->resetClose ();					
					m_State = eTcpServer_State::LISTENING;
										
				} else if (m_pImpl->tcpCloseIsBusy ()) {
					m_State = eTcpServer_State::CLOSINGCONNECTION;
				
				}
				else {
		
					m_State = eTcpServer_State::ERROR;
					m_LastError = m_pImpl->tcpCloseErrorCode ();
				}
			break;			
			
		case eTcpServer_State::INACTIVE:
			break;
			
		case eTcpServer_State::ERROR:
			break;			
			
		default: 
			throw CException (eErrorCode::UNKNOWNTCPSERVERSTATE, "tcp server is in unknown state.");
			
		};
		
	
	for (auto pConnection : m_ActiveConnections)
		pConnection->handleCyclic ();
	
	m_pImpl->handleCyclic ();
		
		
}

void * CTcpServer::getFunctionBlockOpen ()
{
	return m_pImpl->getFunctionBlockOpen ();
}
		
void * CTcpServer::getFunctionBlockClose ()
{
	return m_pImpl->getFunctionBlockClose ();
}

	
void * CTcpServer::getFunctionBlockServer ()
{
	return m_pImpl->getFunctionBlockServer ();
}
	
void CTcpServer::registerPacketHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler)
{
	m_PacketRegistry->registerHandler (pPacketHandler);
}

CTcpPacketRegistry * CTcpServer::getPacketRegistry ()
{
	return m_PacketRegistry.get ();
}


}