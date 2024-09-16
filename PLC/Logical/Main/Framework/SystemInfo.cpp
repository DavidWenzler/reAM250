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

#include "SystemInfo.hpp"

// Raw Registers

namespace BuRCPP {


	CSystemInfo::CSystemInfo ()
		: m_nSystemTimeCycle (0),
		m_nCurrentSystemTimeRegister (0),
		m_nStartSystemTime (0)
	{
		m_nStartSystemTime = IOMapping_PLC.SystemTime;
	}
		
	CSystemInfo::~CSystemInfo ()
	{
	}
		
	uint64_t CSystemInfo::getSystemTimeInMicroseconds ()
	{
		handleCyclic ();
		return (( m_nSystemTimeCycle << 32) | (uint64_t) m_nCurrentSystemTimeRegister) - m_nStartSystemTime;
	}
	
	uint64_t CSystemInfo::getSystemTimeInMilliseconds ()
	{
		return getSystemTimeInMicroseconds () / 1000;
	}
	
		
	void CSystemInfo::handleCyclic ()
	{
		uint32_t nNewRegister = IOMapping_PLC.SystemTime;
		if (nNewRegister < m_nCurrentSystemTimeRegister)
			m_nSystemTimeCycle ++;
		m_nCurrentSystemTimeRegister = nNewRegister;
	}
	
}