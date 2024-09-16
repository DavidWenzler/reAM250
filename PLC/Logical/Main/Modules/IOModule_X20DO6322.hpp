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
#ifndef __IOMODULE_X20DO6322_HPP
#define __IOMODULE_X20DO6322_HPP

#include "../Framework/Framework.hpp"

namespace BuRCPP {
	
		
	class CIOModule_X20DO6322 : public CIOModule {
		protected:
		IOMappingX20DO6322_TYP * m_pMapping;
		
		public:
		CIOModule_X20DO6322 (const std::string & sName, IOMappingX20DO6322_TYP * pMapping);
		virtual ~CIOModule_X20DO6322 ();
		
		bool isActive () override;
		uint32_t getSerialNumber () override;
		uint16_t getModuleID () override;
		uint16_t getHardwareVariant () override;
		uint16_t getFirmwareVersion () override;			
		
		void setOutput (uint32_t, bool);
		
		uint16_t getIOStatus (uint32_t);
		
		void onRegisterJournal ();
		void onUpdateJournal ();
		bool getOutput (uint32_t nChannelNo);
	
		
	
	};


}


#endif // __IOMODULE_X20DO6322_HPP