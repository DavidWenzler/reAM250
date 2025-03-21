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

#ifndef __TCPPACKETHANDLER_HPP
#define __TCPPACKETHANDLER_HPP


#include "Framework.hpp"
#include <list>
#include <vector>
#include <map>
#include <array>
#define	TCP_MAX_PACKET_RESPONSESIZE (256 * 1024)




namespace BuRCPP {

	

	class CTcpPacketResponse {		
		private:
			std::array<uint8_t, TCP_MAX_PACKET_RESPONSESIZE> m_Payload;
					
			uint32_t m_nSignature;
			uint32_t m_nClientID;
			uint32_t m_nSequenceID;
			uint32_t m_nCurrentSize;
			uint32_t m_nErrorCode;			

		public:
				
			CTcpPacketResponse ();
			virtual ~CTcpPacketResponse ();
				
			void addUint8 (uint8_t nValue);
			void addUint16 (uint16_t nValue);
			void addUint32 (uint32_t nValue);
			void addInt8 (int8_t nValue);
			void addInt16 (int16_t nValue);
			void addInt32 (int32_t nValue);
			void addDouble (double nValue);
			void addString (const std::string & sValue);
			void addPayload (uint8_t * pData, uint32_t nDataSize);

			void setErrorCode (eErrorCode nErrorCode);
				
			void beginResponse (uint32_t nClientID, uint32_t nSequenceID, uint32_t nSignature);
			void clearPayload ();
		
			uint32_t getClientID ();
			uint32_t getSequenceID ();
			uint32_t getCurrentSize ();	
				
			std::array<uint8_t, TCP_MAX_PACKET_RESPONSESIZE> & getPayload ();
				
			void buildHeader (TcpOutgoingMessageHeader & header);
		
	};
	

			
	class CTcpPacketHandler {		
		private:
		

		public:

		CTcpPacketHandler ();
		virtual ~CTcpPacketHandler();
		
		virtual uint32_t getCommandID () = 0;
			
		virtual bool isBufferedCommand () = 0;
		
		virtual void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) = 0;
		
		static uint8_t readUint8FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset);
		static uint16_t readUint16FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset);
		static uint32_t readUint32FromPayload (TcpIncomingPayload * pPayload, uint32_t nOffset);
		
	};


	class CTcpPacketHandler_Direct : public CTcpPacketHandler {		
		public:

			CTcpPacketHandler_Direct ();
		
			virtual ~CTcpPacketHandler_Direct();
		
			virtual bool isBufferedCommand () override;
				
	};


	
	class CTcpPacketRegistry {		
		private:
		
		std::map<uint32_t, std::shared_ptr<CTcpPacketHandler>> m_Handlers;
		uint32_t m_nPacketSignature;
		bool m_bPerformChecksumCheck;

		public:

		CTcpPacketRegistry (uint32_t nPacketSignature);
		
		virtual ~CTcpPacketRegistry();
		
		void registerHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler);
		
		bool canHandlePacket (uint32_t nCommandID);		

		bool handlePacket (uint8_t * pData, uint32_t nDataSize, CTcpPacketResponse * pResponse);
		
	};




}


#endif // __TCPPACKETHANDLER_HPP
