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

#include "Journal.hpp"
#include "Utils.hpp"
#include "TcpPacketHandler.hpp"
#include <sstream>

#define JOURNAL_MINGROUPID 1
#define JOURNAL_MAXGROUPID 32767



#define JOURNAL_TCPSTREAMENTRYSIGNATURE_UINT8 0x10000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_INT8 0x20000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_UINT16 0x30000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_INT16 0x40000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_UINT32 0x50000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_INT32 0x60000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_UINT64 0x70000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_INT64 0x80000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_DOUBLE 0x90000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_BOOL_TRUE 0xA0000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_BOOL_FALSE 0xB0000000

#define JOURNAL_TCPSTREAMENTRYSIGNATURE_GROUPLISTSIZE 0xC0000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_ENTRYLISTSIZE 0xD0000000
#define JOURNAL_TCPSTREAMENTRYSIGNATURE_GROUPID 0xE0000000

namespace BuRCPP {

	
	class CTcpPacketHandler_CurrentJournalStatus : public CTcpPacketHandler_Direct {
		private:
		CJournal* m_pJournal;
			
		public: 
			
		CTcpPacketHandler_CurrentJournalStatus (CJournal * pJournal)
			: CTcpPacketHandler_Direct (), m_pJournal (pJournal)
		{
			if (pJournal == nullptr)
				throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");		
		}
			
		virtual ~CTcpPacketHandler_CurrentJournalStatus ()
		{
		}
				
			
		virtual uint32_t getCommandID () override
		{
			return COMMAND_DEFAULT_CURRENTJOURNALSTATUS;
		}
					
		void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
		{
			m_pJournal->writeStatusToTCPResponse (pResponse);	
	
		}

	};
	

class CTcpPacketHandler_CurrentJournalSchema : public CTcpPacketHandler_Direct {
	private:
	CJournal* m_pJournal;
			
	public: 
				
		CTcpPacketHandler_CurrentJournalSchema (CJournal * pJournal)
			: CTcpPacketHandler_Direct (), m_pJournal (pJournal)
		{
			if (pJournal == nullptr)
				throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");		
		}
				
		virtual ~CTcpPacketHandler_CurrentJournalSchema ()
		{
		}
					
				
		virtual uint32_t getCommandID () override
		{
			return COMMAND_DEFAULT_CURRENTJOURNALSCHEMA;
		}
						
		void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
		{
			m_pJournal->writeSchemaToTCPResponse (pResponse);			
		}

	};

class CTcpPacketHandler_RetrieveJournalHistory : public CTcpPacketHandler_Direct {
	private:
	CJournal* m_pJournal;
			
	public: 
				
		CTcpPacketHandler_RetrieveJournalHistory (CJournal * pJournal)
			: CTcpPacketHandler_Direct (), m_pJournal (pJournal)
		{
			if (pJournal == nullptr)
				throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");		
		}
				
		virtual ~CTcpPacketHandler_RetrieveJournalHistory ()
		{
		}
					
				
		virtual uint32_t getCommandID () override
		{
			return COMMAND_DEFAULT_RETRIEVEJOURNALHISTORY;
		}
						
		void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
		{
			m_pJournal->retrieveJournalHistory (pResponse);			
		}

	};


class CTcpPacketHandler_RetrieveJournalVariable : public CTcpPacketHandler_Direct {
	private:
	CJournal* m_pJournal;
			
	public: 
				
	CTcpPacketHandler_RetrieveJournalVariable (CJournal * pJournal)
		: CTcpPacketHandler_Direct (), m_pJournal (pJournal)
	{
		if (pJournal == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid journal parameter");		
	}
				
	virtual ~CTcpPacketHandler_RetrieveJournalVariable ()
	{
	}
	
				
	virtual uint32_t getCommandID () override
	{
	return COMMAND_DEFAULT_RETRIEVEJOURNALVARIABLE;
}
						
		void handlePacket (TcpIncomingPayload * pPayload, CTcpPacketResponse * pResponse) override
		{
			uint32_t nGroupID = readUint32FromPayload (pPayload, 0);
			uint32_t nEntryID = readUint32FromPayload (pPayload, 4);

			m_pJournal->writeVariableToTCPResponse (pResponse, nGroupID, nEntryID);			
		}

	};



CJournalData::CJournalData (std::shared_ptr<CSystemInfo> pSystemInfo)
  : m_nRingBufferHead (0), m_nRingBufferTail (0), m_nRingBufferSize (0), m_nJournalOverFlowCounter (0), m_pSystemInfo (pSystemInfo)
{
	if (pSystemInfo.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid system info parameter");


}

CJournalData::CJournalData (uint32_t nCurrentValueSize, uint32_t nRingBufferSize, std::shared_ptr<CSystemInfo> pSystemInfo)
  :  m_nRingBufferHead (0), 
	m_nRingBufferTail (0), 
	m_nRingBufferSize (nRingBufferSize), 
	m_nJournalOverFlowCounter (0), 
	m_pSystemInfo (pSystemInfo)

{
	if (nCurrentValueSize == 0)
		throw CException (eErrorCode::INVALIDPARAM, "invalid current buffer size");
	if (nRingBufferSize == 0)
		throw CException (eErrorCode::INVALIDPARAM, "invalid journal ring buffer size");
	if (pSystemInfo.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid system info parameter");

	m_CurrentValueBuffer.resize (nCurrentValueSize);
	for (auto & it : m_CurrentValueBuffer)
		it = 0;

	m_JournalRingBuffer.resize (m_nRingBufferSize);

	clearRingBuffer ();
}
			
CJournalData::~CJournalData ()
{
}

		
void CJournalData::readData (uint32_t nAddress, uint8_t * pTarget, uint32_t nSize) const
{
	if (nAddress >  JOURNAL_MAXSIZE)
		throw CException (eErrorCode::INVALIDJOURNALADDRESS, "invalid journal address");
	if (nSize > JOURNAL_MAXSIZE)
		throw CException (eErrorCode::INVALIDJOURNALENTRYSIZE, "invalid journal entry size");
	
	
	if (nAddress + nSize > m_CurrentValueBuffer.size ())
		throw CException (eErrorCode::JOURNALDATABUFFEROVERRUN, "journal data buffer overrun");
	if (pTarget == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid memory target");
	
	for (uint32_t nIndex = 0; nIndex < nSize; nIndex++)
		pTarget[nIndex] = m_CurrentValueBuffer.at (nAddress + nIndex);
	
}

void CJournalData::writeData (uint32_t nAddress, uint32_t nGroupID, uint32_t nEntryID, uint8_t * pSource, uint32_t nSize)
{
	if (nAddress >  JOURNAL_MAXSIZE)
		throw CException (eErrorCode::INVALIDJOURNALADDRESS, "invalid journal address");
	if (nSize > JOURNAL_MAXENTRYSIZE)
		throw CException (eErrorCode::INVALIDJOURNALENTRYSIZE, "invalid journal entry size");
	
	size_t nBufferSize = m_CurrentValueBuffer.size ();
	if (nAddress + nSize > nBufferSize)
		throw CException (eErrorCode::JOURNALDATABUFFEROVERRUN, "journal data buffer overrun");
	if (pSource == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid memory target");

	bool bHasChange = false;
	for (uint32_t nIndex = 0; nIndex < nSize; nIndex++) {
		uint8_t* pTargetByte = &m_CurrentValueBuffer.at (nAddress + nIndex);
		uint8_t nSource = pSource[nIndex];

		if (*pTargetByte != nSource) {
			*pTargetByte = nSource;
			bHasChange = true;
		}
	}

	if (bHasChange) {

		if (!ringBufferIsFull ()) {
			sJournalEntry * pJournalEntry = pushRingBufferEntry ();
			pJournalEntry->m_nTimeStampInMicroseconds = m_pSystemInfo->getSystemTimeInMicroseconds ();
			pJournalEntry->m_nGroupID = (uint16_t) nGroupID;
			pJournalEntry->m_nEntryID = (uint16_t) nEntryID;

			for (uint32_t nIndex = 0; nIndex < nSize; nIndex++) {
				pJournalEntry->m_nBuffer[nIndex] = pSource[nIndex];
			}

			for (uint32_t nIndex = nSize; nIndex < JOURNAL_MAXENTRYSIZE; nIndex++)
				pJournalEntry->m_nBuffer[nIndex] = 0;
		} else {
			m_nJournalOverFlowCounter++;
		}
	}
}

void CJournalData::clearRingBuffer ()
{
	m_nRingBufferHead = 0;
	m_nRingBufferTail = m_nRingBufferSize - 1;
	m_nJournalOverFlowCounter = 0;
}
		
bool CJournalData::ringBufferIsFull ()
{
	return (m_nRingBufferHead == m_nRingBufferTail);
}

bool CJournalData::ringBufferIsEmpty ()
{
	uint32_t nNextTail = (m_nRingBufferTail + 1) % m_nRingBufferSize;
	return (m_nRingBufferHead == nNextTail);
}

uint32_t CJournalData::getBufferEntryCount ()
{	
	if (m_nRingBufferHead == m_nRingBufferTail)
		return m_nRingBufferSize;
	
	uint32_t nNextTail = (m_nRingBufferTail + 1);
	if (m_nRingBufferHead > m_nRingBufferTail) {
		return m_nRingBufferHead - nNextTail;		
	} else {
		return (m_nRingBufferHead + m_nRingBufferSize) - nNextTail;		
	}
	
}

uint32_t CJournalData::getOverFlowCounter ()
{	
	return m_nJournalOverFlowCounter;
}



sJournalEntry * CJournalData::popRingBufferEntry ()
{
	if (ringBufferIsEmpty ())
		throw CException (eErrorCode::JOURNALRINGBUFFERISEMPTY, "journal ring buffer is empty."); 

	uint32_t nCurrentTail = m_nRingBufferTail;
	uint32_t nNextTail = (m_nRingBufferTail + 1) % m_nRingBufferSize;

	m_nRingBufferTail = nNextTail;

	return &m_JournalRingBuffer.at (nNextTail);
}

sJournalEntry * CJournalData::pushRingBufferEntry ()
{
	if (ringBufferIsFull ())
		throw CException (eErrorCode::JOURNALRINGBUFFERISFULL, "journal ring buffer is full."); 

	uint32_t nCurrentHead = m_nRingBufferHead;
	uint32_t nNextHead = (m_nRingBufferHead + 1) % m_nRingBufferSize;

	m_nRingBufferHead = nNextHead;

	return &m_JournalRingBuffer.at (nCurrentHead);

}

	CJournalEntryDefinition::CJournalEntryDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName)
		: m_nGroupID (nGroupID), m_nEntryID (nEntryID), m_sName (sName), m_nAddress (0)
	{
		if (sName.empty ())
			throw CException (eErrorCode::EMPTYJOURNALENTRYNAME, "empty journal entry name");
		if (sName.size () > JOURNAL_MAXNAMELENGTH)
			throw CException (eErrorCode::INVALIDJOURNALENTRYNAME, "journal entry name too long");
		for (auto ch : sName) {
			if (! (((ch >= 'A') && (ch <= 'Z')) ||((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')) || (ch == '_')))
				throw CException (eErrorCode::INVALIDJOURNALENTRYNAME, "invalid characters in journal entry name");
		}
		
		if ((nEntryID < JOURNAL_MINENTRYID) || (nEntryID > JOURNAL_MAXENTRYID))
			throw CException (eErrorCode::INVALIDJOURNALENTRYID, "invalid entry ID.");		
	}
	
	CJournalEntryDefinition::~CJournalEntryDefinition ()
	{
	}
		
	uint32_t CJournalEntryDefinition::getEntryID ()
	{
		return m_nEntryID;
	}

	uint32_t CJournalEntryDefinition::getGroupID ()
	{
		return m_nGroupID;
	}
	
	std::string CJournalEntryDefinition::getName ()
	{
		return m_sName;
	}
	
	size_t CJournalEntryDefinition::getAddress ()
	{
		return m_nAddress;
	}
	
	void CJournalEntryDefinition::setAddress (size_t nAddress)
	{
		m_nAddress = nAddress;
	}
	
	CJournalEntryIntegerDefinition::CJournalEntryIntegerDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName, int64_t nMinimum, int64_t nMaximum)
		: CJournalEntryDefinition (nGroupID, nEntryID, sName), m_nMinimum (nMinimum), m_nMaximum (nMaximum)
	{
		if (nMinimum > nMaximum)
			throw CException (eErrorCode::INVALIDPARAM, "invalid journal group entry range: " + sName);
		
		m_DataSize = 8;
	
		
	}
	
	CJournalEntryIntegerDefinition::~CJournalEntryIntegerDefinition ()
	{
	}
		
	int64_t CJournalEntryIntegerDefinition::getMinimum ()
	{
		return m_nMinimum;
	}
	
	int64_t CJournalEntryIntegerDefinition::getMaximum ()
	{
		return m_nMaximum;
	}
	
	size_t CJournalEntryIntegerDefinition::getDataSize ()
	{
		return m_DataSize;
	}

	void CJournalEntryIntegerDefinition::buildSchemaJSON (std::stringstream & jsonStream)
	{
		jsonStream << "{"; 
		jsonStream << " \"type\": \"integer\", ";		
		jsonStream << " \"name\": \"" << getName () << "\", ";
		jsonStream << " \"id\": " << getEntryID () << ", ";		
		jsonStream << " \"size\": " << getDataSize () << ", ";		
		jsonStream << " \"minimum\": " << getMinimum () << ", ";		
		jsonStream << " \"maximum\": " << getMaximum () << " ";		
		jsonStream << "}";
	}

	
	int64_t CJournalEntryIntegerDefinition::readValue (const CJournalData & JournalData)
	{
		int64_t nReturnValue = 0;
		JournalData.readData (getAddress (), (uint8_t*) &nReturnValue, m_DataSize);
	
		return nReturnValue;
	}
	
	void CJournalEntryIntegerDefinition::writeValue (CJournalData & JournalData, int64_t nValue)
	{
		JournalData.writeData (getAddress (), getGroupID (), getEntryID (), (uint8_t*) &nValue, m_DataSize);
	}

	void CJournalEntryIntegerDefinition::writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData)
	{
		pResponse->addUint32 (getEntryID () | JOURNAL_TCPSTREAMENTRYSIGNATURE_INT32);
		pResponse->addInt32 (readValue (JournalData));
	}

			
	CJournalEntryDoubleDefinition::CJournalEntryDoubleDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName, double dMinimum, double dMaximum, uint32_t nQuantizationSteps)
		: CJournalEntryDefinition (nGroupID, nEntryID, sName), m_dMinimum (dMinimum), m_dMaximum (dMaximum), m_nQuantizationSteps (nQuantizationSteps)
	{
	}
	
	CJournalEntryDoubleDefinition::~CJournalEntryDoubleDefinition ()
	{
	}
		
	double CJournalEntryDoubleDefinition::getMinimum ()
	{
		return m_dMinimum;
	}
	
	double CJournalEntryDoubleDefinition::getMaximum ()
	{
		return m_dMaximum;
	}
	
	size_t CJournalEntryDoubleDefinition::getDataSize ()
	{
		return 8;
	}

	void CJournalEntryDoubleDefinition::buildSchemaJSON (std::stringstream & jsonStream)
	{
		jsonStream << "{"; 
		jsonStream << " \"type\": \"double\", ";		
		jsonStream << " \"name\": \"" << getName () << "\", ";
		jsonStream << " \"id\": " << getEntryID () << ", ";		
		jsonStream << " \"size\": " << getDataSize () << ", ";		
		jsonStream << " \"minimum\": " << getMinimum () << ", ";		
		jsonStream << " \"maximum\": " << getMaximum () << ", ";		
		jsonStream << " \"quantization\": " << m_nQuantizationSteps << " ";		
		jsonStream << "}";
	}
	
	double CJournalEntryDoubleDefinition::readValue (const CJournalData & JournalData)
	{
		double dReturnValue = 0.0;
		JournalData.readData (getAddress (), (uint8_t*) &dReturnValue, 8);
	
		return dReturnValue;
	}
		
	void CJournalEntryDoubleDefinition::writeValue (CJournalData & JournalData, double dValue)
	{
		JournalData.writeData (getAddress (), getGroupID (), getEntryID(), (uint8_t*) &dValue, 8);	
	}
		

	void CJournalEntryDoubleDefinition::writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData)
	{
		pResponse->addUint32 (getEntryID () | JOURNAL_TCPSTREAMENTRYSIGNATURE_DOUBLE);
		pResponse->addDouble (readValue (JournalData));
	}

	CJournalEntryBoolDefinition::CJournalEntryBoolDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName)
		: CJournalEntryDefinition (nGroupID, nEntryID, sName)
	{
	}
	
	
	CJournalEntryBoolDefinition::~CJournalEntryBoolDefinition ()
	{
	}
	
	size_t CJournalEntryBoolDefinition::getDataSize ()
	{
		return 1;
	}	
	
	bool CJournalEntryBoolDefinition::readValue (const CJournalData & JournalData)	
	{
		uint8_t nReturnValue = 0;
		JournalData.readData (getAddress (), (uint8_t*) &nReturnValue, 1);
		return nReturnValue != 0;
	}
	
	void CJournalEntryBoolDefinition::writeValue (CJournalData & JournalData, bool bValue)
	{
		uint8_t nValue = bValue ? 1 : 0;
		JournalData.writeData (getAddress (), getGroupID (), getEntryID(), (uint8_t*) &nValue, 1);
	}
	
	void CJournalEntryBoolDefinition::writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData)
	{
		if (readValue (JournalData)) {
			pResponse->addUint32 (getEntryID () | JOURNAL_TCPSTREAMENTRYSIGNATURE_BOOL_TRUE);
		} else {
			pResponse->addUint32 (getEntryID () | JOURNAL_TCPSTREAMENTRYSIGNATURE_BOOL_FALSE);
		}
	}
	
	void CJournalEntryBoolDefinition::buildSchemaJSON (std::stringstream & jsonStream)
	{
		jsonStream << "{"; 
		jsonStream << " \"type\": \"bool\", ";		
		jsonStream << " \"name\": \"" << getName () << "\", ";
		jsonStream << " \"id\": " << getEntryID () << ", ";		
		jsonStream << " \"size\": " << getDataSize () << " ";		
		jsonStream << "}";
	}
	
	CJournalGroup::CJournalGroup (uint32_t nGroupID, const std::string & sName)
		: m_nGroupID (nGroupID), m_sName (sName)
	{			
		if (sName.empty ())
			throw CException (eErrorCode::EMPTYJOURNALGROUPNAME, "empty journal group name.");
		if (sName.size () > JOURNAL_MAXNAMELENGTH)
			throw CException (eErrorCode::INVALIDJOURNALGROUPNAME, "journal entry name too long");
		for (auto ch : sName) {
			if (! (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')) || (ch == '_')))
				throw CException (eErrorCode::INVALIDJOURNALGROUPNAME, "invalid characters in journal entry name");
		}
		
		if ((nGroupID < JOURNAL_MINGROUPID) || (nGroupID > JOURNAL_MAXGROUPID))
			throw CException (eErrorCode::INVALIDJOURNALGROUPID, "invalid group ID.");
	}
	
	CJournalGroup::~CJournalGroup ()
	{
	}
		
	uint32_t CJournalGroup::getGroupID ()
	{
		return m_nGroupID;
	}
	
	std::string CJournalGroup::getName ()
	{
		return m_sName;
	}

	void CJournalGroup::addEntry (std::shared_ptr<CJournalEntryDefinition> pDefinition)
	{
		if (pDefinition.get () == nullptr)
			throw CException (eErrorCode::INVALIDPARAM, "invalid journal entry parameter");
		
		uint32_t nEntryID = pDefinition->getEntryID ();
		auto iIDIter = m_EntryDefinitionsByID.find (nEntryID);
		if (iIDIter != m_EntryDefinitionsByID.end ())
			throw CException (eErrorCode::JOURNALENTRYALREADYREGISTERED, "journal entry id already registered: " + std::to_string (nEntryID) + " (" + m_sName + ")");
		
		std::string sName = pDefinition->getName ();
		auto iNameIter = m_EntryDefinitionsByName.find (sName);
		if (iNameIter != m_EntryDefinitionsByName.end ())
			throw CException (eErrorCode::JOURNALENTRYALREADYREGISTERED, "journal entry name already registered: " + std::to_string (nEntryID) + " (" + sName + ")");
		
		m_EntryDefinitionsByID.insert (std::make_pair (nEntryID, pDefinition));
		m_EntryDefinitionsByName.insert (std::make_pair (sName, pDefinition));
	}

	
		

	size_t CJournalGroup::calculateDataAddresses (size_t nBaseOffset)
	{
		size_t nSize = 0;
		for (auto iIter : m_EntryDefinitionsByID) {
			size_t nEntrySize = iIter.second->getDataSize ();
			iIter.second->setAddress (nBaseOffset + nSize);
			nSize += nEntrySize;
			
		}
		
		return nSize;
	}	
		
	CJournalEntryDefinition* CJournalGroup::findEntryByID (uint32_t nEntryID, bool bMustExist)
	{
		auto iIter = m_EntryDefinitionsByID.find (nEntryID);
		if (iIter == m_EntryDefinitionsByID.end ()) {
			if (bMustExist)
				throw CException (eErrorCode::JOURNALENTRYNOTFOUND, "journal entry not found: " + std::to_string (nEntryID) + " (" + m_sName + ")");
			
			return nullptr;
		}
		
		return iIter->second.get ();
	}
	
	
	int64_t CJournalGroup::readIntegerValue (const CJournalData & JournalData, uint32_t nEntryID)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pIntegerEntry = dynamic_cast<CJournalEntryIntegerDefinition*> (pEntry);
		if (pIntegerEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type integer: " + pEntry->getName () + " (" + m_sName + ")");
		
		return pIntegerEntry->readValue (JournalData);
	}
	
	double CJournalGroup::readDoubleValue (const CJournalData & JournalData, uint32_t nEntryID)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pDoubleEntry = dynamic_cast<CJournalEntryDoubleDefinition*> (pEntry);
		if (pDoubleEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type double: " + pEntry->getName () + " (" + m_sName + ")");
		
		return pDoubleEntry->readValue (JournalData);
	}
	
	bool CJournalGroup::readBoolValue (const CJournalData & JournalData, uint32_t nEntryID)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pBoolEntry = dynamic_cast<CJournalEntryBoolDefinition*> (pEntry);
		if (pBoolEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type bool: " + pEntry->getName () + " (" + m_sName + ")");
		
		return pBoolEntry->readValue (JournalData);

	}

	void CJournalGroup::writeIntegerValue (CJournalData & JournalData, uint32_t nEntryID, int64_t nValue)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pIntegerEntry = dynamic_cast<CJournalEntryIntegerDefinition*> (pEntry);
		if (pIntegerEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type integer: " + pEntry->getName () + " (" + m_sName + ")");
		
		pIntegerEntry->writeValue (JournalData, nValue);
	}
	
	void CJournalGroup::writeDoubleValue (CJournalData & JournalData, uint32_t nEntryID, double dValue)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pDoubleEntry = dynamic_cast<CJournalEntryDoubleDefinition*> (pEntry);
		if (pDoubleEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type double: " + pEntry->getName () + " (" + m_sName + ")");
		
		pDoubleEntry->writeValue (JournalData, dValue);
	}
	
	void CJournalGroup::writeBoolValue (CJournalData & JournalData, uint32_t nEntryID, bool bValue)
	{
		auto pEntry = findEntryByID (nEntryID, true);
		auto pBoolEntry = dynamic_cast<CJournalEntryBoolDefinition*> (pEntry);
		if (pBoolEntry == nullptr)
			throw CException (eErrorCode::JOURNALENTRYTYPEMISMATCH, "journal entry is not of type bool: " + pEntry->getName () + " (" + m_sName + ")");
		
		pBoolEntry->writeValue (JournalData, bValue);
	}
	
void CJournalGroup::writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");
	
	pResponse->addUint32 (m_nGroupID | JOURNAL_TCPSTREAMENTRYSIGNATURE_GROUPID);
	pResponse->addUint32 (m_EntryDefinitionsByID.size () | JOURNAL_TCPSTREAMENTRYSIGNATURE_ENTRYLISTSIZE);
	
	for (auto nEntryIter : m_EntryDefinitionsByID) {
		nEntryIter.second->writeStatusToTCPResponse (pResponse, JournalData);
	}
}

void CJournalGroup::writeVariableToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData, uint32_t nEntryID)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");
	
	pResponse->addUint32 (m_nGroupID);
	pResponse->addUint32 (1);
	
	auto nEntryIter = m_EntryDefinitionsByID.find(nEntryID);
	
	if (nEntryIter == m_EntryDefinitionsByID.end())
		throw CException (eErrorCode::INVALIDENTRYID, "invalid entry id: " +  std::to_string(nEntryID));
		
	nEntryIter->second->writeStatusToTCPResponse (pResponse, JournalData);
}



void CJournalGroup::buildSchemaJSON (std::stringstream & jsonStream)
{
	jsonStream << "{"; 
	jsonStream << " \"groupname\": \"" << m_sName << "\", ";
	jsonStream << " \"groupid\": " << m_nGroupID << ", ";
	jsonStream << " \"values\":  [";
	
	bool bIsFirst = true;
	
	for (auto nEntryIter : m_EntryDefinitionsByID) {
		if (!bIsFirst) 
			jsonStream << ","; 
		
		nEntryIter.second->buildSchemaJSON (jsonStream);
		
		bIsFirst = false;
		
	}
	
	
	jsonStream << " ] }";
}

	
CJournal::CJournal (uint32_t nRingBufferSize, std::shared_ptr<CSystemInfo> pSystemInfo)
	: m_bIsInitializing (true), m_nRingBufferSize (nRingBufferSize), m_pSystemInfo (pSystemInfo), m_JournalData (pSystemInfo)
{
	if (nRingBufferSize == 0)
		throw CException (eErrorCode::INVALIDPARAM, "invalid journal ring buffer size");
	if (pSystemInfo.get () == nullptr)
		throw CException (eErrorCode::INVALIDPARAM, "invalid system info parameter");
}
	
CJournal::~CJournal ()
{
}
		
void CJournal::registerGroup (uint32_t nGroupID, const std::string & sGroupName)
{
	if (!m_bIsInitializing)
		throw CException (eErrorCode::JOURNALISNOTINITIALIZING, "journal is not initializing");
			
	auto iIDIter = m_GroupIDMap.find (nGroupID);
	if (iIDIter != m_GroupIDMap.end ())
		throw CException (eErrorCode::DUPLICATEJOURNALGROUPID, "duplicate journal group id: " + std::to_string (nGroupID));

	auto iNameIter = m_GroupNameMap.find (sGroupName);
	if (iNameIter != m_GroupNameMap.end ())
		throw CException (eErrorCode::DUPLICATEJOURNALGROUPNAME, "duplicate journal group name: " + sGroupName);
		
		
	auto pGroup = std::make_shared<CJournalGroup> (nGroupID, sGroupName);
		
	m_GroupIDMap.insert (std::make_pair (nGroupID, pGroup));
	m_GroupNameMap.insert (std::make_pair (sGroupName, pGroup));
		
}
		
CJournalGroup* CJournal::findGroupByID (uint32_t nGroupID, bool bMustExist)
{
	auto iIDIter = m_GroupIDMap.find (nGroupID);
	if (iIDIter == m_GroupIDMap.end ()) {
		if (bMustExist)
			throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found: " + std::to_string (nGroupID));
		return nullptr;
	}
		
	return iIDIter->second.get ();
}
	
	
CJournalGroup* CJournal::findGroupByName (const std::string & sGroupName, bool bMustExist)
{
	auto iNameIter = m_GroupNameMap.find (sGroupName);
	if (iNameIter == m_GroupNameMap.end ()) {
		if (bMustExist)
			throw CException (eErrorCode::JOURNALGROUPNAMENOTFOUND, "journal group name not found: " + sGroupName);
			
		return nullptr;			
	}
		
	return iNameIter->second.get ();
}
	
	
void CJournal::registerIntegerValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue)
{
	if (!m_bIsInitializing)
		throw CException (eErrorCode::JOURNALISNOTINITIALIZING, "journal is not initializing");

		
	auto pGroup = findGroupByID (nGroupID, true);
		
	auto pEntry = std::make_shared<CJournalEntryIntegerDefinition> (nGroupID, nEntryID, sEntryName, nMinValue, nMaxValue);		
	pGroup->addEntry (pEntry);
		
}
	
void CJournal::registerBoolValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID)
{
	if (!m_bIsInitializing)
		throw CException (eErrorCode::JOURNALISNOTINITIALIZING, "journal is not initializing");
	
	auto pGroup = findGroupByID (nGroupID, true);
	
	auto pEntry = std::make_shared<CJournalEntryBoolDefinition> (nGroupID, nEntryID, sEntryName);		
	pGroup->addEntry (pEntry);
}
	
void CJournal::registerDoubleValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps)
{
	if (!m_bIsInitializing)
		throw CException (eErrorCode::JOURNALISNOTINITIALIZING, "journal is not initializing");
	
	auto pGroup = findGroupByID (nGroupID, true);
	
	auto pEntry = std::make_shared<CJournalEntryDoubleDefinition> (nGroupID, nEntryID, sEntryName, dMinValue, dMaxValue, nQuantizationSteps);		
	pGroup->addEntry (pEntry);
}
	
		
void CJournal::prepareJournal ()
{
	if (!m_bIsInitializing)
		throw CException (eErrorCode::JOURNALISNOTINITIALIZING, "journal is not initializing");

	size_t nCurrentValueSize = 0;
	for (auto iIter : m_GroupIDMap) {
		size_t nGroupDataSize = iIter.second->calculateDataAddresses (nCurrentValueSize);
		nCurrentValueSize += nGroupDataSize;
	}
		
	if (nCurrentValueSize == 0)
		throw CException (eErrorCode::EMPTYJOURNALNOTALLOWED, "an empty journal is not allowed");
		
	m_JournalData = CJournalData (nCurrentValueSize, m_nRingBufferSize, m_pSystemInfo);
	
	
	std::stringstream schemaStream;
	schemaStream << "{";
	schemaStream << "\"schema\": \"com.br-automation.brcpp.2023-12\", ";
	schemaStream << "\"groups\": [" ;
	bool bIsFirst = true;
	for (auto group: m_GroupIDMap) {
		if (!bIsFirst)
			schemaStream << ", ";
		group.second->buildSchemaJSON (schemaStream);
		
		bIsFirst = false;
	}
	schemaStream << "] }";

	m_sJSONSchema = schemaStream.str ();
		
	m_bIsInitializing = false;
}
	

		
void CJournal::setIntegerValue (const uint32_t nGroupID, const uint32_t nEntryID, int64_t nValue)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));
		
	iIter->second->writeIntegerValue (m_JournalData, nEntryID, nValue);
			
}
		
void CJournal::setBoolValue (const uint32_t nGroupID, const uint32_t nEntryID, bool bValue)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));
	
	iIter->second->writeBoolValue (m_JournalData, nEntryID, bValue);
}
	
void CJournal::setDoubleValue (const uint32_t nGroupID, const uint32_t nEntryID, double dValue)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	iIter->second->writeDoubleValue (m_JournalData, nEntryID, dValue);
}
	
	
bool CJournal::getBoolValue (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));
	
	return iIter->second->readBoolValue (m_JournalData, nEntryID);
		
}
	
double CJournal::getDoubleValue (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	return iIter->second->readDoubleValue (m_JournalData, nEntryID);
}
	
int64_t CJournal::getInt64Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	return iIter->second->readIntegerValue (m_JournalData, nEntryID);
}
	
int32_t CJournal::getInt32Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > INT32_MAX) || (nValue < INT32_MIN))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));
		
	return (int32_t) nValue;
		
}
	
int16_t CJournal::getInt16Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > INT16_MAX) || (nValue < INT16_MIN))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));

	return (int16_t) nValue;
}
	
int8_t CJournal::getInt8Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > INT8_MAX) || (nValue < INT8_MIN))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));
	
	return (int8_t) nValue;
}
	
uint64_t CJournal::getUint64Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));
	
	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if (nValue < 0)
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));

	return (uint64_t) nValue;
}
	
uint32_t CJournal::getUint32Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > UINT32_MAX) || (nValue < 0))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));

	return (uint32_t) nValue;
}
	
		
uint16_t CJournal::getUint16Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > UINT16_MAX) || (nValue < 0))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));

	return (uint16_t) nValue;
}
	
	
uint8_t CJournal::getUint8Value (const uint32_t nGroupID, const uint32_t nEntryID)
{
	auto iIter = m_GroupIDMap.find (nGroupID);
	if (iIter == m_GroupIDMap.end ())
		throw CException (eErrorCode::JOURNALGROUPIDNOTFOUND, "journal group id not found:" + std::to_string (nGroupID));

	int64_t nValue = iIter->second->readIntegerValue (m_JournalData, nEntryID);
	if ((nValue > UINT8_MAX) || (nValue < 0))
		throw CException (eErrorCode::JOURNALVALUEOUTSIDEOFRANGE, "journal value outside of range:" + std::to_string (nGroupID) + "/" + std::to_string (nEntryID));

	return (uint8_t) nValue;
}
		
void CJournal::registerDefaultCommands (CTcpPacketRegistry * pPacketRegistry)
{
	if (pPacketRegistry == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet registry parameter");
	
	pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_CurrentJournalStatus> (this));
	pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_CurrentJournalSchema> (this));
	pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_RetrieveJournalVariable> (this));
	pPacketRegistry->registerHandler (std::make_shared<CTcpPacketHandler_RetrieveJournalHistory> (this));
	
}

void CJournal::writeStatusToTCPResponse (CTcpPacketResponse * pResponse)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");
		
	pResponse->addUint32 (m_GroupIDMap.size () | JOURNAL_TCPSTREAMENTRYSIGNATURE_GROUPLISTSIZE);
	for (auto groupIter : m_GroupIDMap) {
		groupIter.second->writeStatusToTCPResponse (pResponse, m_JournalData);
	}
		
}

void CJournal::writeVariableToTCPResponse (CTcpPacketResponse * pResponse, uint32_t nGroupId, uint32_t nEntryId)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");
		
	pResponse->addUint32 (1);
	auto groupIter = m_GroupIDMap.find(nGroupId);
	if (groupIter == m_GroupIDMap.end())
		throw CException (eErrorCode::VARIABLEGROUPNOTFOUND, "variable group not found: " + std::to_string (nGroupId));
	
	
	groupIter->second->writeVariableToTCPResponse (pResponse, m_JournalData, nEntryId);
	
		
}


void CJournal::writeSchemaToTCPResponse (CTcpPacketResponse * pResponse)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");
	
	pResponse->addString (m_sJSONSchema);
}

std::shared_ptr<CSystemInfo> CJournal::getSystemInfo ()
{
	return m_pSystemInfo;
}


void CJournal::retrieveJournalHistory (CTcpPacketResponse * pResponse)
{
	if (pResponse == nullptr) 
		throw CException (eErrorCode::INVALIDPARAM, "invalid packet response parameter");

	uint32_t nMaxEntriesToSend = 64;
	
	pResponse->addUint32 (m_JournalData.getBufferEntryCount ());
	pResponse->addUint32 (m_JournalData.getOverFlowCounter ());

	while ((!m_JournalData.ringBufferIsEmpty ()) && (nMaxEntriesToSend > 0)) {
		auto pEntry = m_JournalData.popRingBufferEntry ();
		pResponse->addUint32 (pEntry->m_nTimeStampInMicroseconds);
		pResponse->addUint16 ((uint16_t)pEntry->m_nGroupID);
		pResponse->addUint16 ((uint16_t)pEntry->m_nEntryID);
		pResponse->addPayload (pEntry->m_nBuffer, JOURNAL_MAXENTRYSIZE);

		nMaxEntriesToSend--;
	}

}


}	
