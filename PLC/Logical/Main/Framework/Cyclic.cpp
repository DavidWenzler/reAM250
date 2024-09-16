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

#include <bur/plctypes.h>


#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <memory>
#include <map>
#include <string>
#include <exception>


// amount of memory to be allocated for heap storage must be specified for every ANSI C++ program with the bur_heap_size variable
unsigned long bur_heap_size = 1024 * 1024 * 64; 

#include "Application.hpp"

std::shared_ptr<BuRCPP::CApplication> pGlobalApplication;



void setLastException (int32_t nCode, const char * pMessage)
{
	LastException = nCode;
	
	char * pTarget = LastExceptionMessage;
	const char * pSource = pMessage;
	uint32_t nBufferLeft = 254;
	
	if (pSource) {
		while ((nBufferLeft > 0) && (*pSource)) {
			*pTarget = *pSource;
			pTarget++;
			pSource++;
			nBufferLeft--;
		}
	}
	
	while (nBufferLeft > 0) {
		*pTarget = 0;
		pTarget++;
		nBufferLeft--;
		
	}

	// Adding final 0 character
	*pTarget = 0;
}


void _INIT ProgramInit(void)
{
	

	setLastException ((int32_t)BuRCPP::eErrorCode::UNKNOWN, "no error");
	
	try 
	{
		
		pGlobalApplication = std::make_shared<BuRCPP::CCustomApplication> ();
		pGlobalApplication->Initialize ();
		
	} 
	catch (BuRCPP::CException & Exception) {
		setLastException ((int32_t)Exception.getCode (), Exception.getMessage ());
			
			
	}
	catch (std::exception & StdException) {
		setLastException ((int32_t)BuRCPP::eErrorCode::UNHANDLEDEXCEPTION, StdException.what ());
		
		
	}
	catch (...) {
		setLastException ((int32_t)BuRCPP::eErrorCode::UNHANDLEDEXCEPTION, "<untyped exception>");		
			
	}
}


void _CYCLIC ProgramCyclic(void)
{

	if (LastException == (int32_t)BuRCPP::eErrorCode::UNKNOWN) {
		try 
		{
	
			if (pGlobalApplication.get () != nullptr) {
				pGlobalApplication->handleCyclic ();
				
			}

		} 
		catch (BuRCPP::CException & Exception) {
			setLastException ((int32_t)Exception.getCode (), Exception.getMessage ());
			
			
			}
		catch (std::exception & StdException) {
			setLastException ((int32_t)BuRCPP::eErrorCode::UNHANDLEDEXCEPTION, StdException.what ());
		
		
			}
		catch (...) {
			setLastException ((int32_t)BuRCPP::eErrorCode::UNHANDLEDEXCEPTION, "<untyped exception>");		
			
		}
	}
	
}



void _EXIT ProgramExit(void)
{
	// Insert code here 

}


