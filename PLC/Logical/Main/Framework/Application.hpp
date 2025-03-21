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

#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP

#include "Framework.hpp"
#include "TcpServer.hpp"
#include "TcpPacketHandler.hpp"
#include "TcpListHandler.hpp"
#include "Journal.hpp"
#include "SystemInfo.hpp"

#include <map>

namespace BuRCPP {
	
	class CApplication : public CSignalHandlerRegistry
	{	
		private:
		std::shared_ptr<CTcpServer> m_pTcpServer;
		std::shared_ptr<CTcpListHandler> m_pListHandler;		
		std::shared_ptr<CJournal> m_pJournal;
		std::shared_ptr<CModuleHandler> m_pModuleHandler;
		std::shared_ptr<CSystemInfo> m_pSystemInfo;
		std::map<std::string, std::shared_ptr<CStateHandler>> m_StateHandlers;
		public:
		
		CApplication ();
		virtual ~CApplication();
			
		void Initialize ();		
		void handleCyclic ();		
		
		void registerPacketHandler (std::shared_ptr<CTcpPacketHandler> pPacketHandler);
		void registerStateHandler (std::shared_ptr<CStateHandler> pStateHandler);
		
		CTcpListHandler * getListHandler ();
		
		virtual void registerHandlers () = 0;	
		
		virtual CSignalHandler * findSignalHandler (const std::string & sStateMachineName, bool bMustExist) override;		
		
		std::shared_ptr<CJournal> getJournal ();
		
		std::shared_ptr<CModuleHandler> getModuleHandler ();
		
		void registerModule (std::shared_ptr<CModule> pModule, uint32_t nJournalGroupID);

	};
	
	
	class CCustomApplication : public CApplication {
		public:		
		
		CCustomApplication ()
			: CApplication ()
		{
		}
		
		virtual ~CCustomApplication()
		{
		}
		
		virtual void registerHandlers () override;	
		
	};
	
}

#endif // __APPLICATION_HPP
