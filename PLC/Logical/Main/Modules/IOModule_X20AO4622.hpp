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

#ifndef __IOMODULE_X20AO4622_HPP
#define __IOMODULE_X20AO4622_HPP

#include "../Framework/Framework.hpp"

namespace BuRCPP {
	
	enum class eIOChannelType_X20AO4622 : uint32_t {
		mtUnknown = 0,
		mtVoltage10V = 1,
		mtCurrent0to20mA = 2,
		mtCurrent4to20mA = 3
	};
	

	class CIOModule_X20AO4622 : public CIOModule {
		protected:
		IOMappingX20AO4622_TYP * m_pMapping;
		std::array<eIOChannelType_X20AO4622, 4>  m_ChannelTypes;
		std::array<int16_t,4> m_nLowerLimit;
		std::array<int16_t,4> m_nUpperLimit;
		
		public:
		CIOModule_X20AO4622 (const std::string & sName, IOMappingX20AO4622_TYP * pMapping);
		virtual ~CIOModule_X20AO4622 ();
		
		bool isActive () override;
		
		bool setRange(uint32_t nChannelNo, uint16_t nLower, uint16_t nUpper);
		
		uint32_t getSerialNumber () override;
		uint16_t getModuleID () override;
		uint16_t getHardwareVariant () override;
		uint16_t getFirmwareVersion () override;
		eIOChannelType_X20AO4622 getChannelType (uint32_t nChannelNo);
		bool setChannelType (uint32_t nChannelNo, eIOChannelType_X20AO4622 eChannelTypes);
		
		int16_t getRawValue (uint32_t nChannelNo);
		double getRawValueNormalizedZeroToOne (uint32_t nChannelNo);
		double getOutputVoltageInVolt (uint32_t nChannelNo);
		double getOutputCurrentInAmpere (uint32_t nChannelNo);
		
		void setRawValueNormalizedZeroToOne (uint32_t nChannelNo, double dRawValueNormalizedZeroToOne);
		void setOutputVoltageInVolt (uint32_t nChannelNo, double dOutputVoltageInVolt);
		void setOutputCurrentInAmpere (uint32_t nChannelNo, double dOutputCurrentInAmpere);
		
		virtual void onRegisterJournal () override;
		virtual void onUpdateJournal () override;
	
	};


}

#endif //__IOMODULE_X20AO4622_HPP