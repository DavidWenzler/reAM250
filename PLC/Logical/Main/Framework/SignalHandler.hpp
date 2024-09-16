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

#ifndef __SIGNALHANDLER_HPP
#define __SIGNALHANDLER_HPP

#include "Framework.hpp"
#include "SystemInfo.hpp"
#include <queue>

namespace BuRCPP {
	
	enum class eSignalParameterType : int32_t {		
		UnknownParameterType = 0,
		BoolParameterType = 1,
		Int32ParameterType = 2,
		Uint32ParameterType = 3,
		DoubleParameterType = 4		
	};

	class CSignalSendInstance;	
	class CSignalProcessingInstance;	
	class CSignalDefinition;	
	class CSignalInstanceBase;

	class CSignalParameterDefinition {

		private:
		
		std::string m_sName;
		uint32_t m_nMemoryAddress;		
		
		public:		
		
		CSignalParameterDefinition (const std::string & sName, uint32_t nMemoryAddress);
		virtual ~CSignalParameterDefinition ();
		
		std::string getName ();

		uint32_t getMemoryAddress () const;
		virtual eSignalParameterType getSignalType () = 0;
		virtual uint32_t getSizeInBytes () = 0; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) = 0;
		
		virtual void writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue);
		virtual void writeDoubleToInstance (CSignalInstanceBase * pInstance, double dValue);		
		virtual int64_t readIntegerFromInstance (CSignalInstanceBase * pInstance);
		virtual double readDoubleFromInstance (CSignalInstanceBase * pInstance);	
	};
		
	
	class CSignalBoolParameterDefinition : public CSignalParameterDefinition {	
		private:
		bool m_bDefaultValue;

		public:		
		
		CSignalBoolParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, bool bDefaultValue);
		virtual ~CSignalBoolParameterDefinition ();
		virtual eSignalParameterType getSignalType () override;
		virtual uint32_t getSizeInBytes () override; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) override;
		virtual void writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) override;
		virtual int64_t readIntegerFromInstance (CSignalInstanceBase * pInstance) override;
	};
	

	class CSignalInt32ParameterDefinition : public CSignalParameterDefinition {	
		private:
		int32_t m_nDefaultValue;
		public:		
		
		CSignalInt32ParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, int32_t nDefaultValue);
		virtual ~CSignalInt32ParameterDefinition ();
		virtual eSignalParameterType getSignalType () override;
		virtual uint32_t getSizeInBytes () override; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) override;
		virtual void writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) override;
		virtual int64_t readIntegerFromInstance (CSignalInstanceBase * pInstance) override;

	};

	class CSignalUint32ParameterDefinition : public CSignalParameterDefinition {	
		private:
		uint32_t m_nDefaultValue;
		public:		
		
		CSignalUint32ParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, uint32_t nDefaultValue);
		virtual ~CSignalUint32ParameterDefinition ();
		virtual eSignalParameterType getSignalType () override;
		virtual uint32_t getSizeInBytes () override; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) override;
		virtual void writeIntegerToInstance (CSignalInstanceBase * pInstance, int64_t nValue) override;
		virtual int64_t readIntegerFromInstance (CSignalInstanceBase * pInstance) override;

	};
	
	class CSignalFloatParameterDefinition : public CSignalParameterDefinition {	
		private:
		float m_fDefaultValue;
		public:		
		
		CSignalFloatParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, float fDefaultValue);
		virtual ~CSignalFloatParameterDefinition ();
		virtual eSignalParameterType getSignalType () override;
		virtual uint32_t getSizeInBytes () override; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) override;
		virtual void writeDoubleToInstance (CSignalInstanceBase * pInstance, double dValue) override;
		virtual double readDoubleFromInstance (CSignalInstanceBase * pInstance) override;

	};	

	class CSignalDoubleParameterDefinition : public CSignalParameterDefinition {	
		private:
		double m_dDefaultValue;
		public:		
		
		CSignalDoubleParameterDefinition (const std::string & sName, uint32_t nMemoryAddress, double dDefaultValue);
		virtual ~CSignalDoubleParameterDefinition ();
		virtual eSignalParameterType getSignalType () override;
		virtual uint32_t getSizeInBytes () override; 	
		
		virtual void writeDefaultToInstance (CSignalInstanceBase * pInstance) override;
		virtual void writeDoubleToInstance (CSignalInstanceBase * pInstance, double dValue) override;
		virtual double readDoubleFromInstance (CSignalInstanceBase * pInstance) override;

	};
	
		
	class CSignalInstanceBase {
		protected:
		
		CSignalDefinition* m_pDefinition;
		uint32_t m_nInstanceID;
		
		uint8_t * m_pMemory;
		uint32_t m_nMemorySize;
		
		public:
		
		CSignalInstanceBase	(CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize);
		
		virtual ~CSignalInstanceBase ();
		
		void writeData (uint8_t * pSource, uint32_t nOffset, uint32_t nSize);
		void readData (uint8_t * pTarget, uint32_t nOffset, uint32_t nSize);

		bool signalHasBeenProcessed ();
		
		
		bool getBoolParameter (const std::string & sName);
		int32_t getInt32Parameter (const std::string & sName);
		uint32_t getUint32Parameter (const std::string & sName);
		double getDoubleParameter (const std::string & sName);
		float getFloatParameter (const std::string & sName);
		
		bool getBoolResult (const std::string & sName);
		int32_t getInt32Result (const std::string & sName);
		uint32_t getUint32Result (const std::string & sName);
		double getDoubleResult (const std::string & sName);
		float getFloatResult (const std::string & sName);

		bool signalIsTriggered ();
		
		uint32_t getInstanceID ();
		
	};

	
	class CSignalProcessingInstance : public CSignalInstanceBase {

				
		public:

		CSignalProcessingInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize);
		virtual ~CSignalProcessingInstance ();
			
		void setBoolResult (const std::string & sName, bool bValue);
		void setInt32Result (const std::string & sName, int32_t nValue);
		void setUint32Result (const std::string & sName, uint32_t nValue);
		void setDoubleResult (const std::string & sName, double dValue);
		void setFloatResult (const std::string & sName, float fValue);

				
		void finishProcessing ();

	};	
	
	class CSignalSendInstance : public CSignalInstanceBase {
		private:
		
			uint64_t m_nTriggerTimeInMicroseconds;		
						
		public:

		CSignalSendInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize);
		virtual ~CSignalSendInstance ();
		
		void setBoolParameter (const std::string & sName, bool bValue);
		void setInt32Parameter (const std::string & sName, int32_t nValue);
		void setUint32Parameter (const std::string & sName, uint32_t nValue);
		void setDoubleParameter (const std::string & sName, double dValue);
		void setFloatParameter (const std::string & sName, float fValue);

				
		bool triggerSignal ();
		
		void resetTriggerTime ();
		uint64_t getTriggerTimeInMicroseconds ();

	};	
	
	class CSignalInstance : public CSignalInstanceBase {
		private:
		
		
		std::shared_ptr<CSignalSendInstance> m_SendInstance;
		std::shared_ptr<CSignalProcessingInstance> m_ProcessingInstance;
		public:
		
		CSignalInstance (CSignalDefinition* pDefinition, uint32_t nInstanceID, uint8_t * pMemory, uint32_t nMemorySize);
		virtual ~CSignalInstance ();
			
		std::shared_ptr<CSignalSendInstance> getSendInstance ();
		std::shared_ptr<CSignalProcessingInstance> getProcessingInstance ();
		
		bool signalLifeTimeIsExpired ();
		void resetTimer ();
	};
	
	
	class CSignalDefinition {
		private:

		uint32_t m_nLifeTimeInMilliseconds;		
		std::shared_ptr<CSystemInfo> m_pSystemInfo;

		std::string m_sName;
		uint32_t m_nQueueSize;
		std::map<std::string, std::shared_ptr<CSignalParameterDefinition>> m_Parameters;
		std::map<std::string, std::shared_ptr<CSignalParameterDefinition>> m_Results;
		
		std::vector<uint8_t> m_MemoryBuffer;
		uint32_t m_nCurrentMemorySizePerInstance;
		
		std::map<uint32_t, std::shared_ptr<CSignalInstance>> m_Instances;
		std::queue<std::shared_ptr<CSignalInstance>> m_UnusedInstanceQueue;
		std::map<uint32_t, std::shared_ptr<CSignalInstance>> m_InPreparationInstanceQueue;
		std::queue<std::shared_ptr<CSignalInstance>> m_ActiveInstanceQueue;
		std::map<uint32_t, std::shared_ptr<CSignalInstance>> m_InProcessInstanceQueue;
		std::queue<std::shared_ptr<CSignalInstance>> m_FinishedInstanceQueue;
		
		bool isInitializing ();

		void registerParameter (std::shared_ptr<CSignalParameterDefinition> pParameter);
		void registerResult (std::shared_ptr<CSignalParameterDefinition> pResult);
		
		public:

		CSignalDefinition (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifeTimeInMilliseconds, std::shared_ptr<CSystemInfo> pSystemInfo);
		virtual ~CSignalDefinition ();
		
		std::string getName ();
		
		void addBoolParameter (const std::string & sName, bool bDefault);
		void addInt32Parameter (const std::string & sName, int32_t nDefault);
		void addUint32Parameter (const std::string & sName, uint32_t nDefault);
		void addDoubleParameter (const std::string & sName, double dDefault);

		void addBoolResult (const std::string & sName, bool bDefault);
		void addInt32Result (const std::string & sName, int32_t nDefault);
		void addUint32Result (const std::string & sName, uint32_t nDefault);
		void addDoubleResult (const std::string & sName, double dDefault);

		void buildInstances ();
		
		CSignalParameterDefinition * findParameter (const std::string & sName, bool bMustExist);
		CSignalParameterDefinition * findResult (const std::string & sName, bool bMustExist);
		
		CSignalSendInstance * prepareSignal ();
		CSignalProcessingInstance * checkSignal ();
		
		void finishPreparation (CSignalSendInstance * pSignalInstance);
		void finishProcessing (CSignalProcessingInstance * pSignalInstance);
		
		uint32_t getLifeTimeInMilliseconds ();
		uint64_t getSystemTimeInMicroseconds ();
		
		bool signalLifeTimeIsExpired (CSignalSendInstance * pSignalInstance);
		void releaseExpiredSignals ();

	};

	

	
	class CSignalHandler {
		
		private:

		std::shared_ptr<CSystemInfo> m_pSystemInfo;

		std::map<std::string, std::shared_ptr<CSignalDefinition>> m_SignalDefinitions;
		
		bool m_bIsInitializing;
		
		public:
		
		CSignalHandler (std::shared_ptr<CSystemInfo> pSystemInfo);
		
		virtual ~CSignalHandler ();
		
		
		std::shared_ptr<CSignalDefinition> registerSignal (const std::string & sName, const uint32_t nQueueSize, const uint32_t nLifetimeInMilliseconds);
		
		CSignalProcessingInstance * checkSignal (const std::string & sName);
		CSignalSendInstance * prepareSignal (const std::string & sName);
		
		void buildInstances ();
		
		void releaseExpiredSignals ();
		
	};

	
};


#endif
