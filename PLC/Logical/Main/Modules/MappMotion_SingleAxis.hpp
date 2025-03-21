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

#ifndef __MAPPMOTION_SINGLEAXIS_HPP
#define __MAPPMOTION_SINGLEAXIS_HPP

#include "../Framework/Framework.hpp"
#include <memory>

namespace BuRCPP {
	
	class CMappMotion_SingleAxisImpl;
	
	enum class eMappMotion_SingleAxisType : int32_t {
		mtLinearAxis = 0,
		mtRotationalAxis = 1,
	};
	
//	enum class eMappMotion_SingleLinearAxisHomingMode : int32_t {
//		mtDefault = 0,
//		mtRestorePosition = 1,
//	};
		
	enum class eMappMotion_SingleAxisState : int32_t {
		UNKNOWN = 0,
		STATE_IDLE = 1,
		STATE_SETTINGPOWERON = 2,
		STATE_SETTINGPOWEROFF = 3,
		STATE_REFERENCING = 4,
		STATE_INITABSOLUTEMOVEMENT = 5,
		STATE_INITRELATIVEMOVEMENT = 6,
		STATE_INITVELOCITYMOVEMENT = 7,
		STATE_WAITINGFORMOVEMENT = 8,
		STATE_SETTINGPOWERON_TO_REFERENCE = 9,
		STATE_ERROR = 255,
	};
	
		
	class CMappMotion_SingleAxis : public CAxisModule {
		protected:
		McHomingModeEnum m_HomingMode;		

		std::shared_ptr<CMappMotion_SingleAxisImpl> m_pImpl;
		eMappMotion_SingleAxisType m_Type;
		eMappMotion_SingleAxisState m_State;
		
		double m_dSpeedInMMperSecondToSet;
		double m_dAccelerationInMMPerSecondSquaredToSet;
		double m_dTargetPositionInMMToSet;
		double m_dDistanceInMMToSet;
		
		
		double m_dSpeedInDegreeperSecondToSet;
		double m_dAccelerationInDegreePerSecondSquaredToSet;
		double m_dTargetPositionInDegreeToSet;
		double m_dDistanceInDegreeToSet;
		
		public:
		
		CMappMotion_SingleAxis (const std::string & sName, void * pLink);
		virtual ~CMappMotion_SingleAxis ();
			
		bool isActive () override;
		bool isIdle ();
			
		virtual ePLCOpenAxisState getPLCOpenState () override;
		virtual bool isPowered () override;
		virtual bool isReferenced () override;
		virtual bool isMoving () override;
	//	virtual bool isMoveDone () override;
					
		virtual bool canSetPower () override;
		virtual void setPower (bool bPowerOn) override;		

		virtual bool canReference () override;
		virtual void startReference () override;
		
		virtual void setPowerOnAndStartReference () override;
		
		void setHomingMode (McHomingModeEnum homingMode);
		
		virtual bool canMoveAxis ();
		
		
		void resetError ();
		void moveAxisReset ();
		bool isError ();
		bool isInPosition ();
		
		
		virtual void handleCyclic () override;
		
		virtual void * getFunctionBlockPtr ();

		virtual void * getParameterBlockPtr ();
		
		virtual void onRegisterJournal () override;
		virtual void onUpdateJournal () override;
		
	};
	
	
	class CMappMotion_SingleRotationalAxis : public CMappMotion_SingleAxis 
	{
		private:
		
		double m_dMinSpeedInDegreeperSecond;		
		double m_dMaxSpeedInDegreeperSecond;
		
		double m_dMinAccelerationInDegreeperSecond;		
		double m_dMaxAccelerationInDegreeperSecond;	
		

		
		
		public:
		
		CMappMotion_SingleRotationalAxis (const std::string & sName, void * pLink);
		virtual ~CMappMotion_SingleRotationalAxis ();
		
		
		
		void moveAxisAbsolute (double targetPositionInDegree, double speedInDegreeperSecond, double accelerationinDegreeSecondsSquared);
		void moveAxisRelative (double targetPositionInDegree, double speedInDegreeperSecond, double accelerationinDegreeSecondsSquared);
		void moveAxisVelocity (double speedInDegreeperSecond, double accelerationinDegreeSecondsSquared);
		
	
		
		double getCurrentPositionInDegree ();
		double getCurrentVelocityInDegreePerSecond ();
	};
	class CMappMotion_SingleLinearAxis : public CMappMotion_SingleAxis 
	{
		private:
		
		double m_dMinSpeedInMMperSecond;		
		double m_dMaxSpeedInMMperSecond;
		
		double m_dMinAccelerationInMMperSecond;		
		double m_dMaxAccelerationInMMperSecond;

		public:
		
		CMappMotion_SingleLinearAxis (const std::string & sName, void * pLink);
		virtual ~CMappMotion_SingleLinearAxis ();
	
		void moveAxisAbsolute (double targetPositionInMM, double speedInMMperSecond, double accelerationInMMPerSecondSquared);
		void moveAxisRelative (double targetPositionInMM, double speedInMMperSecond, double accelerationInMMPerSecondSquared);
		void moveAxisVelocity (double speedInMMperSecond, double accelerationInMMPerSecondSquared);
		
		double getCurrentPositionInMM ();
		double getCurrentVelocityInMMPerSecond ();
		
		
	};




}


#endif // __MAPPMOTION_SINGLEAXIS_HPP