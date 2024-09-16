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
#include "MappMotion_SingleAxis.hpp"

#include <bur/plctypes.h>


#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <string.h>

#define MAPPMOTION_LINEARAXIS_DEFAULTMINSPEED_IN_MMPERSECOND 0.001f
#define MAPPMOTION_LINEARAXIS_DEFAULTMAXSPEED_IN_MMPERSECOND 1000000.0f
#define MAPPMOTION_LINEARAXIS_DEFAULTMINACCELERATION_IN_MMPERSECONDSQUARED 0.001f
#define MAPPMOTION_LINEARAXIS_DEFAULTMAXACCELERATION_IN_MMPERSECONDSQUARED 1000000.0f

#define MAPPMOTION_ROTARYAXIS_DEFAULTMINSPEED_IN_DEGREEPERSECOND 0.001f
#define MAPPMOTION_ROTARYAXIS_DEFAULTMAXSPEED_IN_DEGREEPERSECOND 1000000.0f
#define MAPPMOTION_ROTARYAXIS_DEFAULTMINACCELERATION_IN_DEGREEPERSECONDSQUARED 0.001f
#define MAPPMOTION_ROTARYAXIS_DEFAULTMAXACCELERATION_IN_DEGREEPERSECONDSQUARED 1000000.0f


#define JOURNALVARIABLE_AXIS_PLCOPENSTATE 1
#define JOURNALVARIABLE_AXIS_CANSETPOWER 2
#define JOURNALVARIABLE_AXIS_ISPOWERED 3
#define JOURNALVARIABLE_AXIS_ISREFERENCED 4
#define JOURNALVARIABLE_AXIS_ISMOVING 5
#define JOURNALVARIABLE_AXIS_ISINPOSITION 6
#define JOURNALVARIABLE_AXIS_ACTUALPOSITION 7
#define JOURNALVARIABLE_AXIS_ACTUALVELOCITY 8





namespace BuRCPP {

	
	class CMappMotion_SingleAxisImpl {
		private:
		MpAxisBasicParType m_Parameters;
		MpAxisBasic_typ m_FunctionBlock;
		public:
		
		CMappMotion_SingleAxisImpl (McAxisType * pLink)
		{
			memset ((void*) &m_Parameters, 0, sizeof (MpAxisBasicParType));
			memset ((void*) &m_FunctionBlock, 0, sizeof (MpAxisBasic_typ));
					
			m_FunctionBlock.MpLink = pLink;
			m_FunctionBlock.Parameters = &m_Parameters;
			m_FunctionBlock.Enable = true;
		}
		
		virtual ~CMappMotion_SingleAxisImpl ()
		{
			memset ((void*) &m_Parameters, 0, sizeof (MpAxisBasicParType));
			memset ((void*) &m_FunctionBlock, 0, sizeof (MpAxisBasic_typ));
		}
		
		int32_t getPLCOpenState () const
		{
			return m_FunctionBlock.Info.PLCopenState;
		}

		bool isError () const
		{
			return m_FunctionBlock.Error;
		}

		bool canSetPower () const
		{
			return m_FunctionBlock.Info.ReadyToPowerOn;
		}
			
		bool isPowered () const
		{
			return m_FunctionBlock.PowerOn;
		}
			
		bool isReferenced () const
		{
			return m_FunctionBlock.IsHomed;
		}
			
		bool isMoving () const
		{
			return m_FunctionBlock.MoveActive;
		}
		
		bool isInPosition () const
		{
			return m_FunctionBlock.InPosition;
		}
		
		float getCurrentPosition () const
		{
			return m_FunctionBlock.Position;
		}

		float getCurrentVelocity () const
		{
			return m_FunctionBlock.Velocity;
		}
		
		void setErrorResetFlag (bool bErrorResetFlag) 
		{
			m_FunctionBlock.ErrorReset = bErrorResetFlag;
		}
		
		void setPowerFlag (bool bPowerFlag) 
		{
			m_FunctionBlock.Power = bPowerFlag;
		}
	
		void setHomeFlag (bool bHomeFlag) 
		{
			m_FunctionBlock.Home = bHomeFlag;
		}
		
		void setVelocityParameter (float fVelocity)
		{
			m_Parameters.Velocity = fVelocity;
		}
		
		void setAccelerationDecelerationParameter (float fAccelerationDeceleration)
		{
			m_Parameters.Acceleration = fAccelerationDeceleration;
			m_Parameters.Deceleration = fAccelerationDeceleration;
		}
		
		void setAbsoluteMovementTarget (float fTargetPosition)			
		{
			m_Parameters.Position = fTargetPosition;
		}
		
		void setAbsoluteMovementFlag (bool bMovementFlag)
		{
			m_FunctionBlock.MoveAbsolute = bMovementFlag;
		}

		void setRelativeMovementDistance (float fRelativeDistance)			
		{
			m_Parameters.Distance = fRelativeDistance;
		}
		
		void setRelativeMovementFlag (bool bMovementFlag)
		{
			m_FunctionBlock.MoveAdditive = bMovementFlag;
		}
		
		void setVelocityMovementFlag (bool bMovementFlag)
		{
			m_FunctionBlock.MoveVelocity = bMovementFlag;
		}
		
		void setHomingMode (McHomingModeEnum homingMode)
		{
			m_Parameters.Homing.Mode = homingMode; 		
		}

		void handleCyclic ()
		{		
			MpAxisBasic(&m_FunctionBlock);
		}

		void * getFunctionBlockPtr ()
		{
			return &m_FunctionBlock;
		}
		

		void * getParameterBlockPtr ()
		{
			return &m_Parameters;		
		}
		
			
	};
	

	
	CMappMotion_SingleAxis::CMappMotion_SingleAxis (const std::string & sName, void * pLink)
		: CAxisModule (sName), 
		m_State (eMappMotion_SingleAxisState::STATE_IDLE), 
		m_dSpeedInMMperSecondToSet (0.0),
		m_dAccelerationInMMPerSecondSquaredToSet (0.0),
		m_dTargetPositionInMMToSet (0.0),
		m_dDistanceInMMToSet (0.0)
	{
		m_HomingMode = mcHOMING_DEFAULT;
		
		if (pLink == nullptr)
			throw CException (eErrorCode::INVALIDAXISLINK, "invalid axis link: " + sName);
/*	if (pFunctionBlock == nullptr)
		throw CException (eErrorCode::INVALIDFUNCTIONBLOCK, "invalid axis function block: " + sName);
	if (pParameterBlock == nullptr)
		throw CException (eErrorCode::INVALIDPARAMETERBLOCK, "invalid axis parameter block: " + sName);*/
		
		m_pImpl.reset ( new CMappMotion_SingleAxisImpl ((McAxisType*) pLink) );
		
	
		// TODO: Read out speed and acceleration limits...
	}
		
	CMappMotion_SingleAxis::~CMappMotion_SingleAxis ()
	{	
	}
		
	void * CMappMotion_SingleAxis::getFunctionBlockPtr ()
	{
		return m_pImpl->getFunctionBlockPtr ();
	}


	void * CMappMotion_SingleAxis::getParameterBlockPtr ()
	{
		return m_pImpl->getParameterBlockPtr ();
	}
	
	
	bool CMappMotion_SingleAxis::isActive () 
	{
		return true;
	}
		
	ePLCOpenAxisState CMappMotion_SingleAxis::getPLCOpenState () 
	{
		return (ePLCOpenAxisState) m_pImpl->getPLCOpenState ();
		
	}
	
	bool CMappMotion_SingleAxis::isIdle ()
	{
		return (m_State == eMappMotion_SingleAxisState::STATE_IDLE);
	}

	
	bool CMappMotion_SingleAxis::isPowered ()
	{
		return m_pImpl->isPowered ();
	}
	
	bool CMappMotion_SingleAxis::isReferenced () 
	{
		return m_pImpl->isReferenced ();
	}
	
	bool CMappMotion_SingleAxis::isMoving ()
	{
		return m_pImpl->isMoving ();
	}
	
	bool CMappMotion_SingleAxis::isInPosition ()
	{
		return m_pImpl->isInPosition ();
	}
	
	bool CMappMotion_SingleAxis::canSetPower () 
	{
		return m_pImpl->canSetPower ();
	}
	
	bool CMappMotion_SingleAxis::isError () 
	{
		return m_pImpl->isError ();
	}
	
	void CMappMotion_SingleAxis::setPower (bool bPowerOn)
	{
		if (bPowerOn) {
			if (canSetPower ()) {		
				m_pImpl->setPowerFlag (true);
				m_State = eMappMotion_SingleAxisState::STATE_SETTINGPOWERON;
			} else {
				throw CException (eErrorCode::COULDNOTPOWERAXIS, "could not power axis: " + m_sName);
			}
		
		}
		else {
			if (isIdle ()) {				
				m_pImpl->setPowerFlag (false);
				m_State = eMappMotion_SingleAxisState::STATE_SETTINGPOWEROFF;
				
			} else {
				throw CException (eErrorCode::COULDNOTPOWERAXIS, "could not gracefully unpower axis: " + m_sName);
			}
		}		
		
	}

	bool CMappMotion_SingleAxis::canReference ()
	{
		if (isIdle () && isPowered () && (m_pImpl->getPLCOpenState () == mcAXIS_STANDSTILL)) {
			return true;
		} else {
			return false;
		}
	}
	
	void CMappMotion_SingleAxis::startReference ()
	{
		if (canReference ()) {
			
			if (DiagCpuIsSimulated()) {
				m_HomingMode = mcHOMING_DIRECT;
				m_pImpl->setHomingMode(m_HomingMode);
			
			}
			else 
			{
				m_pImpl->setHomingMode(m_HomingMode);
			}
				
			m_pImpl->setHomeFlag (true);
			m_State = eMappMotion_SingleAxisState::STATE_REFERENCING;
						
		} else {
			
			throw CException (eErrorCode::COULDNOTREFERENCEAXIS, "could not reference axis: " + m_sName);
			
		}
	}
	
	void CMappMotion_SingleAxis::setHomingMode (McHomingModeEnum homingMode)
	{
		m_HomingMode = homingMode;
		m_pImpl->setHomingMode(m_HomingMode);
	}
		
	void CMappMotion_SingleAxis::setPowerOnAndStartReference ()
	{
		if (canSetPower ()) {		
			m_pImpl->setPowerFlag (true);
			m_State = eMappMotion_SingleAxisState::STATE_SETTINGPOWERON_TO_REFERENCE;
		} else {
			throw CException (eErrorCode::COULDNOTPOWERAXIS, "could not power axis: " + m_sName);
		}		
	}
	
	bool CMappMotion_SingleAxis::canMoveAxis ()
	{
		if (isIdle () && isPowered () && isReferenced() && (m_pImpl->getPLCOpenState () == mcAXIS_STANDSTILL)) {
			return true;
		} else {
			return false;
		}
	}
	
	void CMappMotion_SingleAxis::resetError ()
	{
		if (m_pImpl->isError ()) {		
			m_pImpl->setPowerFlag(false);
			m_pImpl->setErrorResetFlag (true);
		}
		else{	
			m_pImpl->setErrorResetFlag (false);
			m_pImpl->setPowerFlag(true);
			m_State = eMappMotion_SingleAxisState::STATE_SETTINGPOWERON;
		}
				
	}
	
	void CMappMotion_SingleAxis::moveAxisReset ()
	{
		m_pImpl->setVelocityMovementFlag(false);
		m_pImpl->setAbsoluteMovementFlag(false);
		m_pImpl->setRelativeMovementFlag(false);
	}
	
	
	void CMappMotion_SingleAxis::onRegisterJournal ()
	{
		registerUInt16Value ("PlcOpenState", JOURNALVARIABLE_AXIS_PLCOPENSTATE);
		registerBoolValue ("CanSetPower", JOURNALVARIABLE_AXIS_CANSETPOWER);
		registerBoolValue ("IsPowered", JOURNALVARIABLE_AXIS_ISPOWERED);
		registerBoolValue ("IsReferenced", JOURNALVARIABLE_AXIS_ISREFERENCED);
		registerBoolValue ("IsMoving", JOURNALVARIABLE_AXIS_ISMOVING);
		registerBoolValue ("IsInPosition", JOURNALVARIABLE_AXIS_ISINPOSITION);
		registerDoubleValue ("ActualPosition", JOURNALVARIABLE_AXIS_ACTUALPOSITION, -1000000, 1000000, 1);
		registerDoubleValue ("ActualVelocity", JOURNALVARIABLE_AXIS_ACTUALVELOCITY, -1000000, 1000000, 1);

	}

void CMappMotion_SingleAxis::onUpdateJournal ()
	{
		setIntegerValue (JOURNALVARIABLE_AXIS_PLCOPENSTATE, m_pImpl->getPLCOpenState());
		setBoolValue (JOURNALVARIABLE_AXIS_CANSETPOWER, canSetPower());
		setBoolValue (JOURNALVARIABLE_AXIS_ISPOWERED, isPowered());
		setBoolValue (JOURNALVARIABLE_AXIS_ISREFERENCED, isReferenced());
		setBoolValue (JOURNALVARIABLE_AXIS_ISMOVING, isMoving());
		setBoolValue (JOURNALVARIABLE_AXIS_ISINPOSITION,  isInPosition());
		setDoubleValue (JOURNALVARIABLE_AXIS_ACTUALPOSITION, m_pImpl->getCurrentPosition());
		setDoubleValue (JOURNALVARIABLE_AXIS_ACTUALVELOCITY, m_pImpl->getCurrentVelocity());

	}
	
	
CMappMotion_SingleLinearAxis::CMappMotion_SingleLinearAxis (const std::string & sName, void * pLink)
	: CMappMotion_SingleAxis (sName, pLink),
	m_dMinSpeedInMMperSecond (MAPPMOTION_LINEARAXIS_DEFAULTMINSPEED_IN_MMPERSECOND),
	m_dMaxSpeedInMMperSecond (MAPPMOTION_LINEARAXIS_DEFAULTMAXSPEED_IN_MMPERSECOND),
	m_dMinAccelerationInMMperSecond (MAPPMOTION_LINEARAXIS_DEFAULTMINACCELERATION_IN_MMPERSECONDSQUARED),
	m_dMaxAccelerationInMMperSecond (MAPPMOTION_LINEARAXIS_DEFAULTMAXACCELERATION_IN_MMPERSECONDSQUARED)	
{
		m_Type = eMappMotion_SingleAxisType::mtLinearAxis;
}

	
CMappMotion_SingleLinearAxis::~CMappMotion_SingleLinearAxis ()
{
}	
		
void CMappMotion_SingleLinearAxis::moveAxisAbsolute (double targetPositionInMM, double speedInMMperSecond, double accelerationInMMPerSecondSquared)
{
	if ((speedInMMperSecond < m_dMinSpeedInMMperSecond) || (speedInMMperSecond > m_dMaxSpeedInMMperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationInMMPerSecondSquared < m_dMinAccelerationInMMperSecond) || (accelerationInMMPerSecondSquared > m_dMaxAccelerationInMMperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);
	
	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);
		
	m_dTargetPositionInMMToSet = targetPositionInMM;
	m_dSpeedInMMperSecondToSet = speedInMMperSecond;
	m_dAccelerationInMMPerSecondSquaredToSet = accelerationInMMPerSecondSquared;
	
	m_State = eMappMotion_SingleAxisState::STATE_INITABSOLUTEMOVEMENT;
		
}


void CMappMotion_SingleLinearAxis::moveAxisRelative (double distanceInMM, double speedInMMperSecond, double accelerationInMMPerSecondSquared)
{
	if ((speedInMMperSecond < m_dMinSpeedInMMperSecond) || (speedInMMperSecond > m_dMaxSpeedInMMperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationInMMPerSecondSquared < m_dMinAccelerationInMMperSecond) || (accelerationInMMPerSecondSquared > m_dMaxAccelerationInMMperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);

	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);	
	
	m_dDistanceInMMToSet = distanceInMM;
	m_dSpeedInMMperSecondToSet = speedInMMperSecond;
	m_dAccelerationInMMPerSecondSquaredToSet = accelerationInMMPerSecondSquared;
		
	m_State = eMappMotion_SingleAxisState::STATE_INITRELATIVEMOVEMENT;
}

void CMappMotion_SingleLinearAxis::moveAxisVelocity (double speedInMMperSecond, double accelerationInMMPerSecondSquared)
{
	if ((speedInMMperSecond < m_dMinSpeedInMMperSecond) || (speedInMMperSecond > m_dMaxSpeedInMMperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationInMMPerSecondSquared < m_dMinAccelerationInMMperSecond) || (accelerationInMMPerSecondSquared > m_dMaxAccelerationInMMperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);

	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);	

	
	m_dSpeedInMMperSecondToSet = speedInMMperSecond;
	m_dAccelerationInMMPerSecondSquaredToSet = accelerationInMMPerSecondSquared;
	
	m_State = eMappMotion_SingleAxisState::STATE_INITVELOCITYMOVEMENT;
}
	
	
double CMappMotion_SingleLinearAxis::getCurrentPositionInMM ()
{
	return (double) m_pImpl->getCurrentPosition ();
}
	
double CMappMotion_SingleLinearAxis::getCurrentVelocityInMMPerSecond ()
{
	return (double) m_pImpl->getCurrentVelocity ();
}
	
CMappMotion_SingleRotationalAxis::CMappMotion_SingleRotationalAxis (const std::string & sName, void * pLink)
	: CMappMotion_SingleAxis (sName, pLink),
	m_dMinSpeedInDegreeperSecond (MAPPMOTION_ROTARYAXIS_DEFAULTMINSPEED_IN_DEGREEPERSECOND),
	m_dMaxSpeedInDegreeperSecond (MAPPMOTION_ROTARYAXIS_DEFAULTMAXSPEED_IN_DEGREEPERSECOND),
	m_dMinAccelerationInDegreeperSecond (MAPPMOTION_ROTARYAXIS_DEFAULTMINACCELERATION_IN_DEGREEPERSECONDSQUARED),
	m_dMaxAccelerationInDegreeperSecond (MAPPMOTION_ROTARYAXIS_DEFAULTMAXACCELERATION_IN_DEGREEPERSECONDSQUARED)
{
		m_Type = eMappMotion_SingleAxisType::mtRotationalAxis;
}

	
CMappMotion_SingleRotationalAxis::~CMappMotion_SingleRotationalAxis ()
{
}
	
void CMappMotion_SingleRotationalAxis::moveAxisAbsolute (double targetPositionInDegree, double speedInDegreeperSecond, double accelerationinDegreeSecondsSquared)
{
	
	if ((speedInDegreeperSecond < m_dMinSpeedInDegreeperSecond) || (speedInDegreeperSecond > m_dMaxSpeedInDegreeperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationinDegreeSecondsSquared < m_dMinAccelerationInDegreeperSecond) || (accelerationinDegreeSecondsSquared > m_dMaxAccelerationInDegreeperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);
		
	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);	
			
	m_dTargetPositionInDegreeToSet = targetPositionInDegree;
	m_dSpeedInDegreeperSecondToSet = speedInDegreeperSecond;
	m_dAccelerationInDegreePerSecondSquaredToSet = accelerationinDegreeSecondsSquared;
				
	m_State = eMappMotion_SingleAxisState::STATE_INITABSOLUTEMOVEMENT;
	
}


void CMappMotion_SingleRotationalAxis::moveAxisRelative (double distanceInDegree, double speedInDegreeperSecond, double accelerationInDegreePerDegreeSecond)
{
	if ((speedInDegreeperSecond < m_dMinSpeedInDegreeperSecond) || (speedInDegreeperSecond > m_dMaxSpeedInDegreeperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationInDegreePerDegreeSecond < m_dMinAccelerationInDegreeperSecond) || (accelerationInDegreePerDegreeSecond > m_dMaxAccelerationInDegreeperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);
	
	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);	
		
	m_dDistanceInDegreeToSet = distanceInDegree;
	m_dSpeedInDegreeperSecondToSet = speedInDegreeperSecond;
	m_dAccelerationInDegreePerSecondSquaredToSet = accelerationInDegreePerDegreeSecond;
			
	m_State = eMappMotion_SingleAxisState::STATE_INITRELATIVEMOVEMENT;
}
	
void CMappMotion_SingleRotationalAxis::moveAxisVelocity (double speedInDegreeperSecond, double accelerationInDegreePerSecondSquared)
{
	if ((speedInDegreeperSecond < m_dMinSpeedInDegreeperSecond) || (speedInDegreeperSecond > m_dMaxSpeedInDegreeperSecond))
		throw CException (eErrorCode::INVALIDSPEEDVALUE, "invalid speed value for axis: " + m_sName);
	if ((accelerationInDegreePerSecondSquared < m_dMinAccelerationInDegreeperSecond) || (accelerationInDegreePerSecondSquared > m_dMaxAccelerationInDegreeperSecond))
		throw CException (eErrorCode::INVALIDACCELERATIONVALUE, "invalid acceleration value for axis: " + m_sName);

	if (m_State != eMappMotion_SingleAxisState::STATE_IDLE)
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "axis is not in idle mode: " + m_sName);
	if (!canMoveAxis ())
		throw CException (eErrorCode::COULDNOTMOVEAXIS, "could not move axis: " + m_sName);	


	m_dSpeedInDegreeperSecondToSet = speedInDegreeperSecond;
	m_dAccelerationInDegreePerSecondSquaredToSet = accelerationInDegreePerSecondSquared;

	m_State = eMappMotion_SingleAxisState::STATE_INITVELOCITYMOVEMENT;
}



double CMappMotion_SingleRotationalAxis::getCurrentPositionInDegree ()
{
	return (double) m_pImpl->getCurrentPosition ();
}
		
double CMappMotion_SingleRotationalAxis::getCurrentVelocityInDegreePerSecond ()
{
	return (double) m_pImpl->getCurrentVelocity ();
}
	
	
	

		
void CMappMotion_SingleAxis::handleCyclic ()
{

	m_pImpl->handleCyclic ();
		
	switch (m_State) {
		case eMappMotion_SingleAxisState::STATE_SETTINGPOWERON:
				
			if (m_pImpl->isPowered ())
				m_State = eMappMotion_SingleAxisState::STATE_IDLE;
				
			if (m_pImpl->isError ())
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
				
			break;
			
			
		case eMappMotion_SingleAxisState::STATE_SETTINGPOWERON_TO_REFERENCE:
			if (m_pImpl->isPowered ()) {
				if ((m_pImpl->getPLCOpenState () == mcAXIS_STANDSTILL)) {
						if (DiagCpuIsSimulated()) {
							m_HomingMode = mcHOMING_DIRECT;
							m_pImpl->setHomingMode(m_HomingMode);
			
						}
						else 
						{
							m_pImpl->setHomingMode(m_HomingMode);
						}
						m_pImpl->setHomingMode(m_HomingMode);
						m_pImpl->setHomeFlag (true);
					m_State = eMappMotion_SingleAxisState::STATE_REFERENCING;
				} else {
					m_State = eMappMotion_SingleAxisState::STATE_ERROR;				
				}
			}
			if (m_pImpl->isError ())
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;				
			break;

		case eMappMotion_SingleAxisState::STATE_SETTINGPOWEROFF:
			if (!m_pImpl->isPowered ())
				m_State = eMappMotion_SingleAxisState::STATE_IDLE;
			if (m_pImpl->isError ())
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;

			break;

		case eMappMotion_SingleAxisState::STATE_REFERENCING:
			if (m_pImpl->isReferenced ()) {
				m_pImpl->setHomeFlag (false);
				m_State = eMappMotion_SingleAxisState::STATE_IDLE;
			} 
			if (m_pImpl->isError ()) {
				m_pImpl->setHomeFlag (false);
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
			}
								
			break;
		
			
		case eMappMotion_SingleAxisState::STATE_INITABSOLUTEMOVEMENT:
			if (m_pImpl->isError ()) {					
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
			} else {
					if(m_Type == eMappMotion_SingleAxisType::mtLinearAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInMMperSecondToSet);	
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInMMPerSecondSquaredToSet);
						m_pImpl->setAbsoluteMovementTarget (m_dTargetPositionInMMToSet);
					}
					else if (m_Type == eMappMotion_SingleAxisType::mtRotationalAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInDegreeperSecondToSet);	
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInDegreePerSecondSquaredToSet);
						m_pImpl->setAbsoluteMovementTarget (m_dTargetPositionInDegreeToSet);	
					}
					m_pImpl->setAbsoluteMovementFlag (true);
					m_State = eMappMotion_SingleAxisState::STATE_WAITINGFORMOVEMENT;
			}
				
			break;
				
		case eMappMotion_SingleAxisState::STATE_INITRELATIVEMOVEMENT:
			if (m_pImpl->isError ()) {
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
			} else {
					if(m_Type == eMappMotion_SingleAxisType::mtLinearAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInMMperSecondToSet);	
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInMMPerSecondSquaredToSet);
						m_pImpl->setRelativeMovementDistance (m_dDistanceInMMToSet);
					}
					else if (m_Type == eMappMotion_SingleAxisType::mtRotationalAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInDegreeperSecondToSet);	
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInDegreePerSecondSquaredToSet);
						m_pImpl->setRelativeMovementDistance (m_dDistanceInDegreeToSet);	
					}
					m_pImpl->setRelativeMovementFlag (true);
					m_State = eMappMotion_SingleAxisState::STATE_WAITINGFORMOVEMENT;
			}
				
			break;
			
		case eMappMotion_SingleAxisState::STATE_INITVELOCITYMOVEMENT:
			if (m_pImpl->isError ()) {
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
			} else {
					if(m_Type == eMappMotion_SingleAxisType::mtLinearAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInMMperSecondToSet);
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInMMPerSecondSquaredToSet);
					}
					else if (m_Type == eMappMotion_SingleAxisType::mtRotationalAxis)
					{
						m_pImpl->setVelocityParameter(m_dSpeedInDegreeperSecondToSet);	
						m_pImpl->setAccelerationDecelerationParameter(m_dAccelerationInDegreePerSecondSquaredToSet);	
					}	
					m_pImpl->setVelocityMovementFlag (true);
					m_State = eMappMotion_SingleAxisState::STATE_WAITINGFORMOVEMENT;
			}
			
			break;
				
			
		case eMappMotion_SingleAxisState::STATE_WAITINGFORMOVEMENT:
			if (m_pImpl->isInPosition ()) {
				m_pImpl->setRelativeMovementFlag (false);
				m_pImpl->setAbsoluteMovementFlag (false);
				m_pImpl->setVelocityMovementFlag (false);
				m_State = eMappMotion_SingleAxisState::STATE_IDLE;
			}
			if (m_pImpl->isError ()) {
				m_pImpl->setRelativeMovementFlag (false);
				m_pImpl->setAbsoluteMovementFlag (false);
				m_pImpl->setVelocityMovementFlag (false);
				m_State = eMappMotion_SingleAxisState::STATE_ERROR;
			}
							
			break;
	}
	
	
}
	
}