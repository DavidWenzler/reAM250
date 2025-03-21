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


#ifndef __FRAMEWORK_HPP
#define __FRAMEWORK_HPP

#include <cstdint>
#include <memory>
#include <map>
#include <vector>

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#define COMMAND_DEFAULT_BEGINLIST 101
#define COMMAND_DEFAULT_FINISHLIST 102
#define COMMAND_DEFAULT_EXECUTELIST 103
#define COMMAND_DEFAULT_PAUSELIST 104
#define COMMAND_DEFAULT_LISTSTATUS 105
#define COMMAND_DEFAULT_ABORTLIST 106
#define COMMAND_DEFAULT_RESUMELIST 107
#define COMMAND_DEFAULT_DELETELIST 112
#define COMMAND_DEFAULT_CURRENTJOURNALSTATUS 120
#define COMMAND_DEFAULT_CURRENTJOURNALSCHEMA 121
#define COMMAND_DEFAULT_RETRIEVEJOURNALVARIABLE 122
#define COMMAND_DEFAULT_RETRIEVEJOURNALHISTORY 123

namespace BuRCPP {
	
	class CJournal;
	
	
	enum class eErrorCode : int32_t {
		UNKNOWN = 0,
		INVALIDPARAM = 1,
		STATEALREADYEXISTS = 2,
		STATENOTFOUND = 3,
		NEXTSTATEHASNOTBEENSET = 4,
		MODULEALREADYEXISTS = 5,
		NOVOLTAGEMODULE = 6,
		NOCURRENTMODULE = 7,
		INVALIDCHANNELNUMBER = 8,
		MODULENOTFOUND = 9,
		INVALIDMODULETYPE = 10,
		MODULENOTACTIVE = 11,
		INVALIDAXISLINK = 12,
		COULDNOTPOWERAXIS = 13,
		COULDNOTREFERENCEAXIS = 14,
		INVALIDFUNCTIONBLOCK = 15,
		INVALIDPARAMETERBLOCK = 16,
		INVALIDSPEEDVALUE = 17,
		INVALIDACCELERATIONVALUE = 18,
		COULDNOTMOVEAXIS = 19,
		NOTIMPLEMENTED = 20,
		SERVERISALREADYRUNNING = 21,
		SERVERISNOTRUNNING = 22,
		UNKNOWNTCPSERVERSTATE = 23,
		UNKNOWNTCPRECVSTATE = 24,
		UNKNOWNTCPSENDSTATE = 25,
		INVALIDTCPBUFFERSIZE = 26,
		TCPSENDBUFFERSIZEEXCEEDED = 27,
		TCPSENDBUFFERISFULL = 28,
		PACKETHANDLERALREADYREGISTERED = 29,
		INVALIDPAYLOAD = 30,
		INVALIDTCPRESPONSE = 31,
		NOLISTTOWRITETO = 32,
		LISTEXCEEDSMAXIMUMSIZE = 33,
		TOOMANYOPENLISTS = 34,
		NOLISTENTRIESLEFT = 35,
		INTERNALLISTERROR = 36,
		INVALIDPAYLOADOFFSET = 37,
		INVALIDLISTID = 38,
		LISTISNOTINQUEUE = 39,
		NOTWRITINGTOANYLIST = 40,
		NOTINLISTCREATION = 41,
		LISTISEMPTY = 42,
		LISTDOESNOTEXIST = 43,
		LISTISNOTFINISHED = 44,
		INVALIDNAME = 45,
		DUPLICATESIGNALDEFINITION = 46,
		CANNOTREGISTERSIGNAL = 47,
		CANNOTBUILDSIGNALINSTANCES = 48,
		CANNOTREGISTERPARAMETER = 49,
		SIGNALMEMORYALLOCATIONERROR = 50,
		DUPLICATESIGNALPARAMETERNAME = 51,
		CANNOTREGISTERRESULT = 52,
		DUPLICATESIGNALRESULTNAME = 53,
		INVALIDSIGNALQUEUESIZE = 54,
		SIGNALINSTANCESALREADYBUILT = 55,
		SIGNALDATAMISSINGMEMORY = 56,
		SIGNALDATAWRITEOUTOFRANGE = 57,
		SIGNALDATAREADOUTOFRANGE = 58,
		VALUEISOUTSIDEOFINTEGER32RANGE = 59,
		VALUEISOUTSIDEOFUNSIGNEDINTEGER32RANGE = 60,
		SIGNALPARAMETERNOTFOUND = 61,
		SIGNALRESULTNOTFOUND = 62,
		COULDNOTREADDOUBLEFROMPARAMETER = 63,
		COULDNOTREADINTEGERFROMPARAMETER = 64,
		COULDNOTWRITEDOUBLETOPARAMETER = 65,
		COULDNOTWRITEINTEGERTOPARAMETER = 66,
		INVALIDPAYLOADADDRESS = 67,
		INVALIDPAYLOADREADOPERATION = 68,
		INVALIDCONTEXTADDRESS = 69,
		INVALIDCONTEXTREADOPERATION = 70,
		INVALIDCONTEXTWRITEOPERATION = 71,
		LISTCONTEXT_PAYLOADSIGNALSLOTCOUNT = 72,
		INVALIDSIGNALSLOTINDEX = 73,
		PAYLOADSIGNALSLOTINDEXALREADYTAKEN = 74,
		SIGNALSLOTISEMPTY = 75,
		PAYLOADSIGNALSLOTALREADYTAKEN = 76,
		SIGNALHANDLERNOTFOUND = 77,
		SIGNALHASNOINSTANCES = 78,
		COULDNOTPREPARESIGNAL = 79,
		SIGNALDEFINITIONNOTFOUND = 80,
		COULDNOTCHECKSIGNAL = 81,
		NOSIGNALTOFINISH = 82,
		FINISHEDSIGNALINWRONGORDER = 83,
		SIGNALISNOTINPREPARATION = 84,
		SIGNALISNOTINPROCESS = 85,
		INVALIDREQUEST = 86,
		JOURNALALREADYREGISTERING = 87,
		JOURNALISNOTREGISTERING = 88,
		JOURNALNOTSET = 89,
		EMPTYJOURNALENTRYNAME = 90,
		INVALIDJOURNALENTRYNAME = 91,
		INVALIDJOURNALENTRYID = 92,
		JOURNALISNOTINITIALIZING = 93,
		DUPLICATEJOURNALGROUPID = 94,
		DUPLICATEJOURNALGROUPNAME = 95,
		JOURNALGROUPIDNOTFOUND = 96,
		EMPTYJOURNALGROUPDNAME = 97,
		INVALIDJOURNALGROUPDNAME = 98,
		INVALIDJOURNALGROUPID = 99,
		JOURNALGROUPNAMENOTFOUND = 100,
		EMPTYJOURNALGROUPNAME = 101,
		INVALIDJOURNALGROUPNAME = 102,
		JOURNALENTRYALREADYREGISTERED = 103,
		EMPTYJOURNALNOTALLOWED = 104,
		JOURNALVALUEOUTSIDEOFRANGE = 105,
		JOURNALENTRYTYPEMISMATCH = 106,
		JOURNALENTRYNOTFOUND = 107,
		INVALIDJOURNALADDRESS = 108,
		INVALIDJOURNALENTRYSIZE = 109,
		JOURNALDATABUFFEROVERRUN = 110,
		UNHANDLEDEXCEPTION = 111,
		VARIABLEGROUPNOTFOUND = 112,
		INVALIDENTRYID = 113,
		JOURNALRINGBUFFERISEMPTY = 114,
		JOURNALRINGBUFFERISFULL = 115,
		INVALIDCHANNELTYPE = 116,
		SIGNALTRIGGERTIMEISINFUTURE = 117,
		INVALIDCHANNELVALUE = 118,
		
	};
	

	class CStateHandler;
	class CSignalDefinition;
	class CSignalProcessingInstance;
	class CSignalHandler;
	class CState;
	class CEnvironment;
	class CIOModule;
	class CAxisModule;

	class CException {
		private:
		eErrorCode m_Code;
		std::string m_sMessage;
		
		public:	
		CException (eErrorCode code, const std::string & sMessage);
		eErrorCode getCode () const;
		const char * getMessage () const;
		
	};

	typedef struct _TcpIncomingPayload {
		uint8_t m_Data[24];
	} TcpIncomingPayload;
	

	typedef struct _TcpIncomingMessage {
		uint32_t m_nSignature;
		uint32_t m_nClientId;
		uint32_t m_nSequenceId;
		uint32_t m_nCommandId;
		TcpIncomingPayload m_Payload;
		uint32_t m_nChecksum;		
	} TcpIncomingMessage;
	
	
	typedef struct _TcpOutgoingMessageHeader {
		uint32_t m_nSignature;
		uint32_t m_nClientId;
		uint32_t m_nSequenceId;
		uint32_t m_nStatusCode;
		uint32_t m_nPayloadLength;		
		uint32_t m_nPayloadChecksum;		
		uint32_t m_nHeaderChecksum;		
	} TcpOutgoingMessageHeader;
	
/*	
	
	
	class CIOChannel {
		private:
		
		public:
		
		bool getValue ();
		
		void setValue (const bool bValue);
		
		bool isReadOnly ();
		
		bool hasError ();
		
		eIOChannelState getState ();
		
		...
				
		
	};
	
	
	class CSignleAxisDriver {
		private:
		
		public:
		
		bool getValue ();
		
		void setValue (const bool bValue);
		
		bool isReadOnly ();
		
		bool hasError ();
		
		eIOChannelState getState ();
		
		...
				
		
	};
	 */

	class CModule {		
		protected:
		std::string m_sName;
		std::shared_ptr<CJournal> m_pJournal;
		uint32_t m_nJournalGroupID;
		bool m_bJournalIsRegistering;

		public:
		CModule (const std::string & sName);
		virtual ~CModule ();
			
		virtual std::string getName ();
		virtual bool isActive () = 0;
					
		virtual void handleCyclic ();
				
		void setJournal (std::shared_ptr<CJournal> pJournal, uint32_t nJournalGroupID);
		
		virtual void onRegisterJournal ();
		virtual void onUpdateJournal ();
		
		void registerIntegerValue (const std::string & sEntryName,const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue);
		void registerBoolValue (const std::string & sEntryName,const uint32_t nEntryID);
		void registerDoubleValue (const std::string & sEntryName,const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps);

		void registerUInt8Value (const std::string & sEntryName,const uint32_t nEntryID);
		void registerUInt16Value (const std::string & sEntryName,const uint32_t nEntryID);
		void registerUInt32Value (const std::string & sEntryName,const uint32_t nEntryID);
		void registerInt8Value (const std::string & sEntryName,const uint32_t nEntryID);
		void registerInt16Value (const std::string & sEntryName,const uint32_t nEntryID);
		void registerInt32Value (const std::string & sEntryName,const uint32_t nEntryID);
		
		void setIntegerValue (const uint32_t nEntryID, int64_t nValue);
		void setBoolValue (const uint32_t nEntryID, bool bValue);
		void setDoubleValue (const uint32_t nEntryID, double dValue);
		
	};
	
	
	
	class CIOModule : public CModule {		
		public:
		CIOModule (const std::string & sName);
		virtual ~CIOModule ();
						
		virtual uint32_t getSerialNumber () = 0;
		virtual uint16_t getModuleID () = 0;
		virtual uint16_t getHardwareVariant () = 0;
		virtual uint16_t getFirmwareVersion () = 0;				
	};
	
	
	enum class ePLCOpenAxisState : int32_t {
		UNKNOWN = 0,
		AXIS_DISABLED = 1,
		AXIS_STANDSTILL = 2,
		AXIS_HOMING = 2,
		AXIS_STOPPING = 3,
		AXIS_DISCRETE_MOTION = 4,
		AXIS_CONTINUOUS_MOTION = 5,
		AXIS_SYNCHRONIZED_MOTION = 6,
		AXIS_ERRORSTOP = 7,
		AXIS_STARTUP = 8,
		AXIS_INVALID_CONFIGURATION = 9
	};
	

	
	class CAxisModule : public CModule {		
		public:
		CAxisModule (const std::string & sName);
		virtual ~CAxisModule ();
						
		virtual ePLCOpenAxisState getPLCOpenState () = 0;
	
		virtual bool isPowered () = 0;
		virtual bool isReferenced () = 0;
		virtual bool isMoving () = 0;
				
		virtual bool canSetPower () = 0;
		virtual void setPower (bool bPowerOn) = 0;		
		void setPowerOn ();		
		void setPowerOff ();		

		virtual bool canReference () = 0;
		virtual void startReference () = 0;
		
		virtual void setPowerOnAndStartReference () = 0;
		
	};
     

	
	class CEnvironment {
		private:
	
		CStateHandler * m_pStateHandler;
		CState * m_pNextState;
	
		public:
	
		CEnvironment (CStateHandler * pStateHandler);
		
		virtual ~CEnvironment ();
		
		void setNextState (const std::string & sNextState);
		
		CState * getNextState ();
		
		
		CModule * findModule (const std::string & sName, bool bFailIfNotExist);
		

		CSignalProcessingInstance * checkSignal (const std::string & sName);
	
		CSignalProcessingInstance * findSignal (uint32_t nSignalID);
		
		void setIntegerValue (const uint32_t nEntryID, int64_t nValue);
		void setBoolValue (const uint32_t nEntryID, bool bValue);
		void setDoubleValue (const uint32_t nEntryID, double dValue);
		
		bool getBoolValue (const uint32_t nEntryID);
		double getDoubleValue (const uint32_t nEntryID);
		int64_t getInt64Value (const uint32_t nEntryID);
		int32_t getInt32Value (const uint32_t nEntryID);
		int16_t getInt16Value (const uint32_t nEntryID);
		int8_t getInt8Value (const uint32_t nEntryID);
		uint64_t getUint64Value (const uint32_t nEntryID);
		uint32_t getUint32Value (const uint32_t nEntryID);
		uint16_t getUint16Value (const uint32_t nEntryID);
		uint8_t getUint8Value (const uint32_t nEntryID);		
	
	};


	class CState {

		private:
	
		public:
	
		CState ();
				
		virtual ~CState ();
		
		virtual std::string getName () = 0;
		
		virtual void Execute (CEnvironment * pEnvironment) = 0;
		
		
	};

	class CModuleHandler {
		private:
			std::map<std::string, std::shared_ptr<CModule>> m_Modules;		
			std::shared_ptr<CJournal> m_pJournal;
		public:
			CModuleHandler (std::shared_ptr<CJournal> pJournal);
		
			virtual ~CModuleHandler ();
	
			void registerModule (std::shared_ptr<CModule> pModule, uint32_t nJournalGroupID);
		
			void handleModules ();
		
			CModule * findModule (const std::string & sName);
		
	};

	class CStateHandler {
		private:
	
		
		std::map<std::string, std::shared_ptr<CState>> m_States;
		std::shared_ptr<CModuleHandler> m_pModuleHandler;
		
		CState * m_pCurrentState;
		char * m_pStateNameDebug;
		uint32_t m_nStateNameDebugLength;
		
		std::shared_ptr<CSignalHandler> m_pSignalHandler;
		std::shared_ptr<CJournal> m_pJournal;
		
		uint32_t m_nJournalGroupID;
		std::string m_sName;	
		
		protected:		
		
		void addState (std::shared_ptr<CState> pState);
				
		
		
		void registerIntegerValue (const std::string & sEntryName,const uint32_t nEntryID, int64_t nMinValue, int64_t nMaxValue);
		void registerBoolValue (const std::string & sEntryName,const uint32_t nEntryID);
		void registerDoubleValue (const std::string & sEntryName,const uint32_t nEntryID, double dMinValue, double dMaxValue, int64_t nQuantizationSteps);
		
		public:
	
		CStateHandler (std::shared_ptr<CJournal> pJournal, const std::string & sName, std::shared_ptr<CModuleHandler> pModuleHandler, uint32_t nJournalGroupID);
			
		virtual ~CStateHandler();
	
		
		CState * findState (const std::string & sName);
		
		CModule * findModule (const std::string & sName);
				
		CState * getCurrentState ();
		
		void setCurrentState (CState * pState);	
		
		std::string getName ();
				
		std::shared_ptr<CSignalDefinition> registerSignal (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifetimeInMilliseconds);		
		
		void setDebugVariables (char * pStateNameDebug, uint32_t nStateNameDebugLength);
		void writeDebugInformation ();
		
		virtual void onRegister ();
		
		CSignalHandler* getSignalHandler ();
		
		void releaseExpiredSignals ();		
		
		void setIntegerValue (const uint32_t nEntryID, int64_t nValue);
		void setBoolValue (const uint32_t nEntryID, bool bValue);
		void setDoubleValue (const uint32_t nEntryID, double dValue);

		bool getBoolValue (const uint32_t nEntryID);
		double getDoubleValue (const uint32_t nEntryID);
		int64_t getInt64Value (const uint32_t nEntryID);
		int32_t getInt32Value (const uint32_t nEntryID);
		int16_t getInt16Value (const uint32_t nEntryID);
		int8_t getInt8Value (const uint32_t nEntryID);
		uint64_t getUint64Value (const uint32_t nEntryID);
		uint32_t getUint32Value (const uint32_t nEntryID);
		uint16_t getUint16Value (const uint32_t nEntryID);
		uint8_t getUint8Value (const uint32_t nEntryID);
		
		
	};




	
	
	template<typename T> class ioModuleAccess {
		
		private:
		T * m_Module;
			
		
		public:
	
		ioModuleAccess (CEnvironment * pEnvironment, const std::string & sModuleName)
			: m_Module (nullptr)
		{
			auto pModule = pEnvironment->findModule (sModuleName, true);
			if (pModule->isActive ()) {
				auto pCastedModule = dynamic_cast<T *> (pModule);
				
				if (pCastedModule != nullptr) 
				{
					m_Module = pCastedModule;
				} else
				{
					throw CException (eErrorCode::INVALIDMODULETYPE, "invalid module type: " + sModuleName);
				}
													
			} else 
				throw CException (eErrorCode::MODULENOTACTIVE, "module not active: " + sModuleName);
			
			
		}
		
		
		virtual ~ioModuleAccess  ()
		{
		}
		
		T& operator* ()
		{
			return *m_Module;
		}
		
		T* operator-> ()
		{
			return m_Module;
		}
	
	};
	
	
}


#endif // __FRAMEWORK_HPP