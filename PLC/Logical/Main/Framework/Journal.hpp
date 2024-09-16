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

#ifndef __JOURNAL_HPP
#define __JOURNAL_HPP

#include <memory>
#include <vector>
#include <sstream>
#include <map>

#include "SystemInfo.hpp"

#define JOURNAL_MINENTRYID 1
#define JOURNAL_MAXENTRYID 32767

#define JOURNAL_MAXNAMELENGTH 64
#define JOURNAL_MAXSIZE (16* 1024 * 1024)
#define JOURNAL_MAXENTRYSIZE 8

namespace BuRCPP 
{
	class CTcpPacketRegistry;
	class CTcpPacketResponse;
	
	typedef struct _sJournalEntry {
		uint64_t m_nTimeStampInMicroseconds;
		uint16_t m_nGroupID;
		uint16_t m_nEntryID;
		uint8_t m_nBuffer[JOURNAL_MAXENTRYSIZE];
	} sJournalEntry;

	class CJournalData {
		private:
		std::vector<uint8_t> m_CurrentValueBuffer;

		std::vector<sJournalEntry> m_JournalRingBuffer;
		uint32_t m_nRingBufferHead;
		uint32_t m_nRingBufferTail;
		uint32_t m_nRingBufferSize;
		
		std::shared_ptr<CSystemInfo> m_pSystemInfo;

		uint32_t m_nJournalOverFlowCounter;

		public:
		CJournalData (std::shared_ptr<CSystemInfo> pSystemInfo);
		CJournalData (uint32_t nCurrentValueSize, uint32_t nRingBufferSize, std::shared_ptr<CSystemInfo> pSystemInfo);
		virtual ~CJournalData ();
		
		void readData (uint32_t nAddress, uint8_t * pTarget, uint32_t nSize) const;
		void writeData (uint32_t nAddress, uint32_t nGroupID, uint32_t nEntryID, uint8_t * pSource, uint32_t nSize);

		void clearRingBuffer ();
		bool ringBufferIsFull ();
		bool ringBufferIsEmpty ();
		
		uint32_t getBufferEntryCount ();
		uint32_t getOverFlowCounter ();

		sJournalEntry * popRingBufferEntry ();
		sJournalEntry * pushRingBufferEntry ();


	};

	class CJournalEntryDefinition {
		private:
		uint32_t m_nGroupID;
		uint32_t m_nEntryID;
		std::string m_sName;
		size_t m_nAddress;		
		public:
		
		CJournalEntryDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName);
		virtual ~CJournalEntryDefinition ();
		
		uint32_t getEntryID ();
		uint32_t getGroupID ();
		std::string getName ();
		
		virtual size_t getDataSize () = 0;
		
		size_t getAddress ();
		void setAddress (size_t nAddress);
		
		virtual void writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData) = 0;
		virtual void buildSchemaJSON (std::stringstream & jsonStream) = 0;

	};	
	
	
	class CJournalEntryIntegerDefinition : public CJournalEntryDefinition {
		private:
		int64_t m_nMinimum;
		int64_t m_nMaximum;
		size_t m_DataSize;
		public:
		
		CJournalEntryIntegerDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName, int64_t nMinimum, int64_t nMaximum);
		virtual ~CJournalEntryIntegerDefinition ();
		
		int64_t getMinimum ();
		int64_t getMaximum ();
		
		size_t getDataSize () override;
		
		int64_t readValue (const CJournalData & JournalData);
		void writeValue (CJournalData & JournalData, int64_t nValue);

		virtual void writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData) override;
		virtual void buildSchemaJSON (std::stringstream & jsonStream) override;
		
	};

	class CJournalEntryDoubleDefinition : public CJournalEntryDefinition {
		private:
		double m_dMinimum;
		double m_dMaximum;
		uint32_t m_nQuantizationSteps;
		public:
		
		CJournalEntryDoubleDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName, double dMinimum, double dMaximum, uint32_t nQuantizationSteps);
		virtual ~CJournalEntryDoubleDefinition ();
		
		double getMinimum ();
		double getMaximum ();
		
		size_t getDataSize () override;
		
		double readValue (const CJournalData & JournalData);
		void writeValue (CJournalData & JournalData, double dValue);

		virtual void writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData) override;
		virtual void buildSchemaJSON (std::stringstream & jsonStream) override;
		
	};
	
	class CJournalEntryBoolDefinition : public CJournalEntryDefinition {
		private:
		public:
		
		CJournalEntryBoolDefinition (uint32_t nGroupID, uint32_t nEntryID, const std::string & sName);
		virtual ~CJournalEntryBoolDefinition ();
		
		size_t getDataSize () override;
		
		bool readValue (const CJournalData & JournalData);
		void writeValue (CJournalData & JournalData, bool dValue);

		virtual void writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData) override;
		
		
		virtual void buildSchemaJSON (std::stringstream & jsonStream) override;
		
	};	

	
	class CJournalGroup {
		private:
		uint32_t m_nGroupID;
		std::string m_sName;

		
		std::map<uint32_t, std::shared_ptr<CJournalEntryDefinition>> m_EntryDefinitionsByID;
		std::map<std::string, std::shared_ptr<CJournalEntryDefinition>> m_EntryDefinitionsByName;
		
		public:
		
		CJournalGroup (uint32_t nGroupID, const std::string & sName);
		virtual ~CJournalGroup ();
		
		uint32_t getGroupID ();
		std::string getName ();
		
		void addEntry (std::shared_ptr<CJournalEntryDefinition> pDefinition);
		CJournalEntryDefinition* findEntryByID (uint32_t nEntryID, bool bMustExist);
		
		size_t calculateDataAddresses (size_t nBaseOffset);
		
		int64_t readIntegerValue (const CJournalData & JournalData, uint32_t nEntryID);
		double readDoubleValue (const CJournalData & JournalData, uint32_t nEntryID);
		bool readBoolValue (const CJournalData & JournalData, uint32_t nEntryID);

		void writeIntegerValue (CJournalData & JournalData, uint32_t nEntryID, int64_t nValue);
		void writeDoubleValue (CJournalData& JournalData, uint32_t nEntryID, double dValue);
		void writeBoolValue (CJournalData & JournalData, uint32_t nEntryID, bool bValue);		
		
		void writeStatusToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData);
		void writeVariableToTCPResponse (CTcpPacketResponse * pResponse, const CJournalData & JournalData, uint32_t nEntryId);	
		
		void buildSchemaJSON (std::stringstream & jsonStream);

	};	


	class CJournal {

		private:
				
		bool m_bIsInitializing;
		CJournalData m_JournalData;

		uint32_t m_nRingBufferSize;
		
		std::string m_sJSONSchema;

		std::map<uint32_t, std::shared_ptr<CJournalGroup>> m_GroupIDMap;
		std::map<std::string, std::shared_ptr<CJournalGroup>> m_GroupNameMap;			
		
		std::shared_ptr<CSystemInfo> m_pSystemInfo;
			
		public:
		
		CJournal (uint32_t nRingBufferSize, std::shared_ptr<CSystemInfo> pSystemInfo);
		virtual ~CJournal ();
		
		void registerGroup (uint32_t nGroupID, const std::string & sGroupName);
		CJournalGroup* findGroupByID (uint32_t nGroupID, bool bMustExist);
		CJournalGroup* findGroupByName (const std::string & sGroupName, bool bMustExist);
		
		void registerIntegerValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue);
		void registerBoolValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID);
		void registerDoubleValue (const std::string & sEntryName, const uint32_t nGroupID, const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps);
		
		void prepareJournal ();
		
		void setIntegerValue (const uint32_t nGroupID, const uint32_t nEntryID, int64_t nValue);
		void setBoolValue (const uint32_t nGroupID, const uint32_t nEntryID, bool bValue);
		void setDoubleValue (const uint32_t nGroupID, const uint32_t nEntryID, double dValue);
		
		bool getBoolValue (const uint32_t nGroupID, const uint32_t nEntryID);
		double getDoubleValue (const uint32_t nGroupID, const uint32_t nEntryID);
		int64_t getInt64Value (const uint32_t nGroupID, const uint32_t nEntryID);
		int32_t getInt32Value (const uint32_t nGroupID, const uint32_t nEntryID);
		int16_t getInt16Value (const uint32_t nGroupID, const uint32_t nEntryID);
		int8_t getInt8Value (const uint32_t nGroupID, const uint32_t nEntryID);
		uint64_t getUint64Value (const uint32_t nGroupID, const uint32_t nEntryID);
		uint32_t getUint32Value (const uint32_t nGroupID, const uint32_t nEntryID);
		uint16_t getUint16Value (const uint32_t nGroupID, const uint32_t nEntryID);
		uint8_t getUint8Value (const uint32_t nGroupID, const uint32_t nEntryID);
		
		void registerDefaultCommands (CTcpPacketRegistry * pPacketRegistry);
		void writeStatusToTCPResponse (CTcpPacketResponse * pResponse);
		void writeVariableToTCPResponse (CTcpPacketResponse * pResponse, uint32_t nGroupId, uint32_t nEntryId);
		
		void writeSchemaToTCPResponse (CTcpPacketResponse * pResponse);
		void retrieveJournalHistory (CTcpPacketResponse * pResponse);
		
		std::shared_ptr<CSystemInfo> getSystemInfo ();

	};
	

}

#endif // __JOURNAL_HPP