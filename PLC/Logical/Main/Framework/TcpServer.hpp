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

#ifndef __TCPSERVER_HPP
#define __TCPSERVER_HPP


#include "Framework.hpp"
#include "TcpPacketHandler.hpp"
#include <list>
#include <vector>

#define TCPMINBUFFERSIZE 1024
#define TCPMAXBUFFERSIZE (16*1024*1024)

namespace BuRCPP {
	
	


	class CTcpServerImpl;
	class CTcpConnectionImpl;
	
	enum class eTcpServer_State : int32_t
	{
		UNKNOWN = 0,
		INACTIVE = 1,
		INIT	 = 2,
		INITIALIZING = 3,
		LISTENING	= 4,
		CLOSINGCONNECTION = 5,
		ERROR =	6
	};

	
	enum class eTcpConnectionRecv_State : int32_t
	{
		UNKNOWN = 0,
		INACTIVE = 1,
		WAITINGFORDATA = 2,
		RESETCONNECTION = 3,
		CLOSINGCONNECTION = 4,
		ERROR =	6
	};	

	enum class eTcpConnectionSend_State : int32_t
	{
		UNKNOWN = 0,
		INACTIVE = 1,
		WAITINGFORDATA = 2,
		CLOSINGCONNECTION = 4,
		SENDING = 5,
		ERROR =	6
	};	
	
	class CTcpConnection {
		protected:
			std::shared_ptr<CTcpConnectionImpl> m_pImpl;
			uint32_t m_ClientIdent;
			eTcpConnectionRecv_State m_RecvState;
			eTcpConnectionSend_State m_SendState;
								
			std::vector<uint8_t> m_ReceiveBuffer;
			std::vector<uint8_t> m_SendBuffer1;
			std::vector<uint8_t> m_SendBuffer2;
					
			uint8_t * m_pSendBufferInProcess;
			uint8_t * m_pSendBufferNextInQueue;
			uint32_t m_SendBufferInProcessSize;
			uint32_t m_SendBufferNextInQueueSize;
			uint32_t m_SendBufferMemorySize;
			
			CTcpPacketRegistry* m_pPacketRegistry;
			
			CTcpPacketResponse m_TempResponse;
						
			uint32_t m_LastError;

		public:
		
		CTcpConnection (uint32_t nReceiveBufferSize, uint32_t nSendBufferSize, CTcpPacketRegistry* pPacketRegistry);
		virtual ~CTcpConnection ();
		
		void initialize (uint32_t clientIdent);
		
		void handleCyclic ();
		
		bool canSendData (uint32_t nByteCount);
		
		void sendData (uint8_t * pBytes, uint32_t nByteCount);

	};

	
	class CTcpServer {
	
		protected:
		std::shared_ptr<CTcpServerImpl> m_pImpl;
		std::list<std::shared_ptr<CTcpConnection>> m_InactiveConnections;
		std::list<std::shared_ptr<CTcpConnection>> m_ActiveConnections;
		std::shared_ptr<CTcpPacketRegistry> m_PacketRegistry;
	
		eTcpServer_State m_State;
		uint32_t m_Port;
		uint32_t m_MaxConnections;
		uint32_t m_LastError;
		
		bool enableConnection (uint32_t nClientIdent);
		
		public:
		
		CTcpServer (uint32_t port, uint32_t maxConnections, uint32_t nPacketSignature);
		virtual ~CTcpServer();
		
		
		virtual bool serverRunning ();
		virtual bool clientConnected ();


		virtual void startServer ();
		virtual void stopServer ();
		
		virtual void handleServer ();
		
		void registerPacketHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler);
		
		void * getFunctionBlockOpen ();
		void * getFunctionBlockClose ();
		void * getFunctionBlockServer ();
		
		CTcpPacketRegistry * getPacketRegistry ();
		

	};


}


#endif
