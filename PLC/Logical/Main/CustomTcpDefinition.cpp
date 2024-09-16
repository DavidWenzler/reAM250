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

#include "Framework/Application.hpp"
#include "CustomConstants.hpp"

#define CUSTOMCOMMAND_OPENDOOR 5001
#define CUSTOMCOMMAND_LOCKDOOR 5002
#define CUSTOMCOMMAND_INITAXIS 1999
#define CUSTOMCOMMAND_TRIGGERSINGLEAXISMOVEMENT 2000
#define CUSTOMCOMMAND_REFERENCEAXIS 2001
#define CUSTOMCOMMAND_ABSOLUTESWITCHREFERENCING 2002
#define CUSTOMCOMMAND_RECOATERDUALAXISMOVEMENT 2003
#define CUSTOMCOMMAND_TOGGLEVALVES 2004
#define CUSTOMCOMMAND_INITATMOSPHERECONTROL 2005
#define CUSTOMCOMMAND_STARTGASFLOW 2006
#define CUSTOMCOMMAND_UPDATEGASFLOWSETPOINT 2007
#define CUSTOMCOMMAND_TURNOFFGASFLOW 2008
#define CUSTOMCOMMAND_INITVACUUMSYSTEM 2009
#define CUSTOMCOMMAND_STARTVACUUMPUMP 2010
#define CUSTOMCOMMAND_TURNOFFVACUUMPUMP 2011

#define CUSTOMCOMMAND_ENABLEBUILDPLATETEMPCONTROL 2300
#define CUSTOMCOMMAND_UPDATECONTROLLERPIDPARAMETERS 2301
#define CUSTOMCOMMAND_UPDATECONTROLLERTUNERPARAMETERS 2302
#define CUSTOMCOMMAND_UPDATECONTROLLERPWMPARAMETERS 2303
#define CUSTOMCOMMAND_UPDATECONTROLLERSETPOINT 2304
#define CUSTOMCOMMAND_AUTOTUNECONTROLLER 2305
#define CUSTOMCOMMAND_ABORTAUTOTUNINGCONTROLLER 2306
#define CUSTOMCOMMAND_DISABLEBUILDPLATETEMPCONTROL 2307


#define CUSTOMCOMMAND_SIGNALSLOT_OPENDOORS 1
#define CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM 1
#define CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR 2
#define CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT 3
#define CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR 4
#define CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL 1
#define CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL 2
#define CUSTOMCOMMAND_SIGNALSLOT_GASCIRCULATION 1
#define CUSTOMCOMMAND_SIGNALSLOT_VACUUMPUMP 3

namespace BuRCPP
{


/**********************************************************************************************

***********************************************************************************************/

	class CTcpPacketHandler_Command_OpenDoor : public CTcpPacketHandler_Buffered
	{

		public:
		
		CTcpPacketHandler_Command_OpenDoor(CTcpListHandler *pListHandler)
			: CTcpPacketHandler_Buffered(pListHandler)
		{
		}

		virtual ~CTcpPacketHandler_Command_OpenDoor()
		{
		}

		virtual uint32_t getCommandID() override
		{
			return CUSTOMCOMMAND_OPENDOOR;
		}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			pEnvironment->setLifetimeInMillseconds (1000);
	
			auto pSignal = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OPENDOORS, "door", "releasedoor");
			pSignal->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OPENDOORS)) {
				return true;
			} else {
				return false;
			} 
		}

	};

class CTcpPacketHandler_Command_LockDoor : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_Command_LockDoor(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_Command_LockDoor()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_LOCKDOOR;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			pEnvironment->setLifetimeInMillseconds (1000);
			bool bLockDoor = pEnvironment->readPayloadUint8(0);

			auto pSignal = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OPENDOORS, "door", "lockdoor");
			pSignal->setBoolParameter("doorstate", bLockDoor);
			pSignal->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OPENDOORS)) {
				return true;
			} else {
				return false;
			} 
		}

	};

	
/**********************************************************************************************

***********************************************************************************************/


/*******************************
********COMMAND DEFINTION*******
*******************************/

/*CommandID 2000
**Name TriggerSingleAxisMovement
*/

/*CommandID 2001
**Name ReferenceAxis
*/

/*CommandID 2002
**Name CheckAxisState
*/

class CTcpPacketHandler_TriggerSingleAxisMovement : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_TriggerSingleAxisMovement(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_TriggerSingleAxisMovement()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_TRIGGERSINGLEAXISMOVEMENT;
	}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{

		pEnvironment->setLifetimeInMillseconds(15000);

		uint8_t nAxisID = pEnvironment->readPayloadUint8(0);
		uint8_t nAbsoluteRelative = pEnvironment->readPayloadUint8(2);
		int32_t nTargetPositionInMicron = pEnvironment->readPayloadInt32(4);
		int32_t nSpeedInMicronPerSecond = pEnvironment->readPayloadInt32(8);
		int32_t nAccelerationInMicronPerSecondSquared = pEnvironment->readPayloadInt32(12);

		if ((nAxisID < AXISMOVEMENT_MINAXISID) || (nAxisID > AXISMOVEMENT_MAXAXISID))
			throw CException(eErrorCode::INVALIDREQUEST, "invalid axis ID request");
		if ((nAbsoluteRelative != AXISMOVEMENT_RELATIVE) && (nAbsoluteRelative != AXISMOVEMENT_ABSOLUTE))
			throw CException(eErrorCode::INVALIDREQUEST, "invalid axis movement request. axis is neither relative nor absolute");

		if (nAxisID == AXISID_BUILDPLATFORM)
		{
			auto pSignalSingleAxisMovement = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM, "build_platform_axis", "triggersingleaxismovement");
			pSignalSingleAxisMovement->setInt32Parameter("axisid", nAxisID);
			pSignalSingleAxisMovement->setInt32Parameter("absoluterelative", nAbsoluteRelative);
			pSignalSingleAxisMovement->setInt32Parameter("position", nTargetPositionInMicron);
			pSignalSingleAxisMovement->setInt32Parameter("speed", nSpeedInMicronPerSecond);
			pSignalSingleAxisMovement->setInt32Parameter("acceleration", nAccelerationInMicronPerSecondSquared);
			pSignalSingleAxisMovement->triggerSignal();
		}
		else if (nAxisID == AXISID_POWDERRESERVOIR)
		{
			auto pSignalSingleAxisMovement = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR, "powder_reservoir_axis", "triggersingleaxismovement");
			pSignalSingleAxisMovement->setInt32Parameter("axisid", nAxisID);
			pSignalSingleAxisMovement->setInt32Parameter("absoluterelative", nAbsoluteRelative);
			pSignalSingleAxisMovement->setInt32Parameter("position", nTargetPositionInMicron);
			pSignalSingleAxisMovement->setInt32Parameter("speed", nSpeedInMicronPerSecond);
			pSignalSingleAxisMovement->setInt32Parameter("acceleration", nAccelerationInMicronPerSecondSquared);
			pSignalSingleAxisMovement->triggerSignal();
		}
		else if (nAxisID == AXISID_RECOATERPOWDERBELT)
		{
			auto pSignalSingleAxisMovement = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT, "recoater_axes", "triggersingleaxismovement");
			pSignalSingleAxisMovement->setInt32Parameter("axisid", nAxisID);
			pSignalSingleAxisMovement->setInt32Parameter("absoluterelative", nAbsoluteRelative);
			pSignalSingleAxisMovement->setInt32Parameter("position", nTargetPositionInMicron);
			pSignalSingleAxisMovement->setInt32Parameter("speed", nSpeedInMicronPerSecond);
			pSignalSingleAxisMovement->setInt32Parameter("acceleration", nAccelerationInMicronPerSecondSquared);
			pSignalSingleAxisMovement->triggerSignal();
		}
		else if (nAxisID == AXISID_RECOATELINEAR)
		{
			auto pSignalSingleAxisMovement = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR, "recoater_axes", "triggersingleaxismovement");
			pSignalSingleAxisMovement->setInt32Parameter("axisid", nAxisID);
			pSignalSingleAxisMovement->setInt32Parameter("absoluterelative", nAbsoluteRelative);
			pSignalSingleAxisMovement->setInt32Parameter("position", nTargetPositionInMicron);
			pSignalSingleAxisMovement->setInt32Parameter("speed", nSpeedInMicronPerSecond);
			pSignalSingleAxisMovement->setInt32Parameter("acceleration", nAccelerationInMicronPerSecondSquared);
			pSignalSingleAxisMovement->triggerSignal();
		}
		
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
	{

		if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM) 
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR)
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT)
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR)) {
				return true;
			} else {
				return false;
			}
	}
};

class CTcpPacketHandler_ReferenceAxis : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_ReferenceAxis(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_ReferenceAxis()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_REFERENCEAXIS;
	}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{

		pEnvironment->setLifetimeInMillseconds(15000);

		bool bReferencePlatform = pEnvironment->readPayloadUint8(0);
		bool bReferencePowderreservoir = pEnvironment->readPayloadUint8(1);
		bool bReferenceRecoateraxisPowder = pEnvironment->readPayloadUint8(2);
		bool bReferenceRecoateraxisLinear = pEnvironment->readPayloadUint8(3);
		
		if (bReferencePlatform)
		{
			auto pSignalReferencePlatformAxis = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM, "build_platform_axis", "referenceaxis");
			pSignalReferencePlatformAxis->setBoolParameter("reference_platform", bReferencePlatform);
			pSignalReferencePlatformAxis->triggerSignal();
		}
		if (bReferencePowderreservoir)
		{
			auto pSignalReferencePowderreservoirAxis = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR, "powder_reservoir_axis", "referenceaxis");
			pSignalReferencePowderreservoirAxis->setBoolParameter("reference_powderreservoir", bReferencePowderreservoir);
			pSignalReferencePowderreservoirAxis->triggerSignal();
		}
		if (bReferenceRecoateraxisPowder)
		{
			auto pSignalReferenceRecoateraxisPowder = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT, "recoater_axes", "referenceaxis");
			pSignalReferenceRecoateraxisPowder->setBoolParameter("reference_recoateraxis_powder", bReferenceRecoateraxisPowder);
			pSignalReferenceRecoateraxisPowder->triggerSignal();
		}
		if (bReferenceRecoateraxisLinear)
		{
			auto pSignalReferenceRecoateraxisLinear = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR, "recoater_axes", "referenceaxis");
			pSignalReferenceRecoateraxisLinear->setBoolParameter("reference_recoateraxis_linear", bReferenceRecoateraxisLinear);
			pSignalReferenceRecoateraxisLinear->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
	{
		if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM) 
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR)
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT)
				|| pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR)) {
				return true;
			} else {
				return false;
			}
	}
};

class CTcpPacketHandler_InitAxis : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_InitAxis(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_InitAxis()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_INITAXIS;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{

		pEnvironment->setLifetimeInMillseconds(15000);

		uint8_t nAxisID = pEnvironment->readPayloadUint8(0);
		
		if (nAxisID == AXISID_BUILDPLATFORM)
		{
			auto pSignalInitPlatformAxis = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM, "build_platform_axis", "initaxis");
			pSignalInitPlatformAxis->triggerSignal();
		}
		else if (nAxisID == AXISID_POWDERRESERVOIR)
		{
			auto pSignalInitPowderreservoirAxis = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR, "powder_reservoir_axis", "initaxis");
			pSignalInitPowderreservoirAxis->triggerSignal();
		}
		else if (nAxisID == AXISID_RECOATERPOWDERBELT)
		{
			auto pSignalInitRecoateraxisPowder = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT, "recoater_axes", "initpowderaxis");
			pSignalInitRecoateraxisPowder->triggerSignal();
		}
		else if (nAxisID == AXISID_RECOATELINEAR)
		{
			auto pSignalInitRecoateraxisLinear = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR, "recoater_axes", "initlinearaxis");
			pSignalInitRecoateraxisLinear->triggerSignal();
		}
		
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
	{
		if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUILDPLATFORM) 
				&& pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_POWDERRESERVOIR)
				&& pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATERPOWDERBELT)
				&& pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR)) {
				return true;
			} else {
				return false;
			}
	}
};


class CTcpPacketHandler_AbsoluteSwitchReferencing : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_AbsoluteSwitchReferencing(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_AbsoluteSwitchReferencing()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_ABSOLUTESWITCHREFERENCING;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			
			auto pSignalAbsoluteSwitchReferencing = pEnvironment->prepareSignal(1, "build_platform_axis", "absoluteswitchreferencing");
			pSignalAbsoluteSwitchReferencing->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_RecoaterDualAxisMovement : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_RecoaterDualAxisMovement(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_RecoaterDualAxisMovement()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_RECOATERDUALAXISMOVEMENT;
	}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{

		pEnvironment->setLifetimeInMillseconds(10000);

		int32_t recoateraxislinearstartposition = pEnvironment->readPayloadInt32(0);
		int32_t recoateraxislineartargetposition =pEnvironment->readPayloadInt32(4);
		int32_t recoateraxislinearspeed = pEnvironment->readPayloadInt32(8);
		int32_t recoateraxispowderspeed = pEnvironment->readPayloadInt32(12);
		int32_t recoateraxeslinearacceleration = pEnvironment->readPayloadInt32(16);
		int32_t recoateraxespowderacceleration = pEnvironment->readPayloadInt32(20);
				
		auto pSignalRecoaterDualAxisMovement = pEnvironment->prepareSignal(1, "recoater_axes", "recoaterdualaxismovement");
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoateraxis_linear_start_position", recoateraxislinearstartposition);
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoateraxis_linear_target_position", recoateraxislineartargetposition);
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoateraxis_linear_speed", recoateraxislinearspeed);
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoateraxis_powder_speed", recoateraxispowderspeed);
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoater_axes_linear_acceleration", recoateraxeslinearacceleration);
		pSignalRecoaterDualAxisMovement->setInt32Parameter ("recoater_axes_powder_acceleration", recoateraxespowderacceleration);
		pSignalRecoaterDualAxisMovement->triggerSignal();
		/*auto pSignalSingleAxisMovement = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR, "recoater_axes", "triggersingleaxismovement");
		pSignalSingleAxisMovement->setInt32Parameter("axisid", 4);
		pSignalSingleAxisMovement->setInt32Parameter("absoluterelative", AXISMOVEMENT_ABSOLUTE);
		pSignalSingleAxisMovement->setInt32Parameter("position", recoateraxislineartargetposition);
		pSignalSingleAxisMovement->setInt32Parameter("speed", recoateraxislinearspeed);
		pSignalSingleAxisMovement->setInt32Parameter("acceleration", recoateraxeslinearacceleration);
		pSignalSingleAxisMovement->triggerSignal();*/
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_RECOATELINEAR)) {
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_Toggle_Valves : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_Toggle_Valves(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_Toggle_Valves()
	{
	}

	virtual uint32_t getCommandID() override
	{
		return CUSTOMCOMMAND_TOGGLEVALVES;
	}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command togglevalves
			bool toggle_lower_gas_flow_circuit_valve =pEnvironment->readPayloadUint8(0);
			bool toggle_upper_gas_flow_circuit_valve = pEnvironment->readPayloadUint8(1);
			bool toggle_shielding_gas_valve = pEnvironment->readPayloadUint8(2);
			bool toggle_chamber_vacuum_valve = pEnvironment->readPayloadUint8(3);
			bool toggle_zAxis_vacuum_valve = pEnvironment->readPayloadUint8(4);
			
			auto pSignalToggleValvesGasCirculation = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_GASCIRCULATION, "gascirculation", "togglevalves");
			pSignalToggleValvesGasCirculation->setBoolParameter ("toggle_lower_gas_flow_circuit_valve", toggle_lower_gas_flow_circuit_valve);
			pSignalToggleValvesGasCirculation->setBoolParameter ("toggle_upper_gas_flow_circuit_valve", toggle_upper_gas_flow_circuit_valve);
			pSignalToggleValvesGasCirculation->setBoolParameter ("toggle_shielding_gas_valve", toggle_shielding_gas_valve);
			pSignalToggleValvesGasCirculation->setBoolParameter ("toggle_chamber_vacuum_valve", toggle_chamber_vacuum_valve);
			pSignalToggleValvesGasCirculation->setBoolParameter ("toggle_zAxis_vacuum_valve", toggle_zAxis_vacuum_valve);
			pSignalToggleValvesGasCirculation->triggerSignal();

			auto pSignalToggleValvesVacuumSystem = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_VACUUMPUMP, "vacuumsystem", "togglevalves");
			pSignalToggleValvesVacuumSystem->setBoolParameter ("toggle_lower_gas_flow_circuit_valve", toggle_lower_gas_flow_circuit_valve);
			pSignalToggleValvesVacuumSystem->setBoolParameter ("toggle_upper_gas_flow_circuit_valve", toggle_upper_gas_flow_circuit_valve);
			pSignalToggleValvesVacuumSystem->setBoolParameter ("toggle_shielding_gas_valve", toggle_shielding_gas_valve);
			pSignalToggleValvesVacuumSystem->setBoolParameter ("toggle_chamber_vacuum_valve", toggle_chamber_vacuum_valve);
			pSignalToggleValvesVacuumSystem->setBoolParameter ("toggle_zAxis_vacuum_valve", toggle_zAxis_vacuum_valve);
			pSignalToggleValvesVacuumSystem->triggerSignal();

			auto pSignalToggleValvesShieldingGasSystem = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "togglevalves");
			pSignalToggleValvesShieldingGasSystem->setBoolParameter ("toggle_lower_gas_flow_circuit_valve", toggle_lower_gas_flow_circuit_valve);
			pSignalToggleValvesShieldingGasSystem->setBoolParameter ("toggle_upper_gas_flow_circuit_valve", toggle_upper_gas_flow_circuit_valve);
			pSignalToggleValvesShieldingGasSystem->setBoolParameter ("toggle_shielding_gas_valve", toggle_shielding_gas_valve);
			pSignalToggleValvesShieldingGasSystem->setBoolParameter ("toggle_chamber_vacuum_valve", toggle_chamber_vacuum_valve);
			pSignalToggleValvesShieldingGasSystem->setBoolParameter ("toggle_zAxis_vacuum_valve", toggle_zAxis_vacuum_valve);
			pSignalToggleValvesShieldingGasSystem->triggerSignal();

		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

	};

class CTcpPacketHandler_InitAtmosphereControl : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_InitAtmosphereControl(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_InitAtmosphereControl()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_INITATMOSPHERECONTROL;
	}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command InitAtmosphereControl
			int o2_threshold_circulation_on_in_ppm = pEnvironment->readPayloadInt32(0);
			int o2_threshold_circulation_off_in_ppm = pEnvironment->readPayloadInt32(4);
			
			auto pSignalInitAtmosphereControl = pEnvironment->prepareSignal(1, "gascirculation", "initatmospherecontrol");
			pSignalInitAtmosphereControl->setInt32Parameter ("o2thresholdcirculationoninppm", o2_threshold_circulation_on_in_ppm);
			pSignalInitAtmosphereControl->setInt32Parameter ("o2thresholdcirculationoffinppm", o2_threshold_circulation_off_in_ppm);
			pSignalInitAtmosphereControl->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_StartGasFlow : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_StartGasFlow(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_StartGasFlow()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_STARTGASFLOW;
	}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command StartGasFlow
			int setpoint_in_percent = pEnvironment->readPayloadInt32(0);
			
			auto pSignalStartGasFlow = pEnvironment->prepareSignal(1, "gascirculation", "startgasflow");
			pSignalStartGasFlow->setInt32Parameter ("setpointinpercent", setpoint_in_percent);
			pSignalStartGasFlow->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_UpdateGasFlowSetpoint : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_UpdateGasFlowSetpoint(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_UpdateGasFlowSetpoint()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_UPDATEGASFLOWSETPOINT;
	}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command UpdateGasFlowSetpoint
			int setpoint_in_percent = pEnvironment->readPayloadInt32(0);
			
			auto pSignalUpdateGasFlowSetpoint = pEnvironment->prepareSignal(1, "gascirculation", "updategasflowsetpoint");
			pSignalUpdateGasFlowSetpoint->setInt32Parameter ("setpointinpercent", setpoint_in_percent);
			pSignalUpdateGasFlowSetpoint->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_TurnOffGasFlow : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_TurnOffGasFlow(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_TurnOffGasFlow()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_TURNOFFGASFLOW;
	}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command TurnOffGasFlow
			
			auto pSignalTurnOffGasFlow = pEnvironment->prepareSignal(1, "gascirculation", "turnoffgasflow");
			pSignalTurnOffGasFlow->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_InitVacuumSystem : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_InitVacuumSystem(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_InitVacuumSystem()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_INITVACUUMSYSTEM;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			// read values of the command InitVacuumSystem
			int pressure_threshold_vacuum_off_in_mbar = pEnvironment->readPayloadInt32(0);
			
			auto pSignalInitVacuumSystem = pEnvironment->prepareSignal(1, "vacuumsystem", "initvacuumsystem");
			pSignalInitVacuumSystem->setInt32Parameter ("pressurethresholdvacuumoffinmbar", pressure_threshold_vacuum_off_in_mbar);
			pSignalInitVacuumSystem->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_StartVacuumPump : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_StartVacuumPump(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_StartVacuumPump()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_STARTVACUUMPUMP;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			
			auto pSignalStartVacuumPump = pEnvironment->prepareSignal(1, "vacuumsystem", "startvacuumpump");
			pSignalStartVacuumPump->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_TurnOffVacuumPump : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_TurnOffVacuumPump(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_TurnOffVacuumPump()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_TURNOFFVACUUMPUMP;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			
			auto pSignalTurnOffVacuumPump = pEnvironment->prepareSignal(1, "vacuumsystem", "turnoffvacuumpump");
			pSignalTurnOffVacuumPump->triggerSignal();
		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (1)) {
				return true;
			} else {
				return false;
			} 
		}

};

class CTcpPacketHandler_EnableController : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_EnableController(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_EnableController()
	{
	}

	virtual uint32_t getCommandID() override
	{
		return CUSTOMCOMMAND_ENABLEBUILDPLATETEMPCONTROL;
	}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{

		pEnvironment->setLifetimeInMillseconds(1000);

		// read values of the command disablecontroller
		int controller_ID = pEnvironment->readPayloadInt16(0); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
	
		
		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalEnableBuildPlateTempControl = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "enablecontroller");
			pSignalEnableBuildPlateTempControl->triggerSignal();
	
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalEnableOxygenControl = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "enablecontroller");
			pSignalEnableOxygenControl->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
	{
		if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) 
		{
			return true;
		} 
		else 
		{
			return false;
		} 
	}
};

class CTcpPacketHandler_UpdateControllerPidParameters : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_UpdateControllerPidParameters(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_UpdateControllerPidParameters()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_UPDATECONTROLLERPIDPARAMETERS;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerPidParameters
		bool isinit = pEnvironment->readPayloadInt8(0); //Flag if this is an init command or an update command, 1 = init, 0 = update
		int controller_ID = pEnvironment->readPayloadInt16(1); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
		int derivativetime = pEnvironment->readPayloadInt32(3); //Derivative time of the PID controller in milli seconds
		int integrationtime = pEnvironment->readPayloadInt32(7); //Integration time of the PID controller in milli seconds
		int gain = pEnvironment->readPayloadInt32(11); //Gain of the PID controller in milli degree celcius or milli ppm per normalized output
		int filtertime = pEnvironment->readPayloadInt32(15); //Filter time of the PID controller in milli seconds
		int maxout = pEnvironment->readPayloadInt16(19); //Max output of the PID controller in percent, maximum is 100 percent
		int minout = pEnvironment->readPayloadInt16(21); //Min output of the PID controller in percent, must be positive
		

		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalUpdateHeaterControllerPidParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "updatecontrollerparameters");
			pSignalUpdateHeaterControllerPidParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("derivativetime", derivativetime);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("integrationtime", integrationtime);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("gain", gain);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("filtertime", filtertime);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("maxout", maxout);
			pSignalUpdateHeaterControllerPidParameters->setInt32Parameter ("minout", minout);
			pSignalUpdateHeaterControllerPidParameters->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalUpdateOxygenControllerPidParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "updatecontrollerparameters");
			pSignalUpdateOxygenControllerPidParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("derivativetime", derivativetime);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("integrationtime", integrationtime);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("gain", gain);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("filtertime", filtertime);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("maxout", maxout);
			pSignalUpdateOxygenControllerPidParameters->setInt32Parameter ("minout", minout);
			pSignalUpdateOxygenControllerPidParameters->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_UpdateControllerTunerParameters : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_UpdateControllerTunerParameters(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_UpdateControllerTunerParameters()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_UPDATECONTROLLERTUNERPARAMETERS;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerTunerParameters
		bool isinit = pEnvironment->readPayloadInt8(0); //Flag if this is an init command or an update command, 1 = init, 0 = update
		int controller_ID = pEnvironment->readPayloadInt16(1); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
		int stepheight = pEnvironment->readPayloadInt16(3); //Height of the step to be applied during tuning of the PID controller in percent
		int maxactvalue = pEnvironment->readPayloadInt32(5); //Max value of the range of the controlled variable during training in degree celcius or ppm
		int minactvalue = pEnvironment->readPayloadInt16(9); //Min value of the range of the controlled variable during training in degree celcius or ppm
		int systemsettlingtime = pEnvironment->readPayloadInt32(11); //Time for the system to settle at the start setpoint before the step for tuning is applied in seconds
		int maxtuningtime = pEnvironment->readPayloadInt32(15); //Maximum time for the tuning including the settling time in seconds
		


		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalUpdateHeaterControllerTunerParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "updatecontrollertunerparameters");
			pSignalUpdateHeaterControllerTunerParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateHeaterControllerTunerParameters->setInt32Parameter ("stepheight", stepheight);
			pSignalUpdateHeaterControllerTunerParameters->setInt32Parameter ("maxactvalue", maxactvalue);
			pSignalUpdateHeaterControllerTunerParameters->setInt32Parameter ("minactvalue", minactvalue);
			pSignalUpdateHeaterControllerTunerParameters->setInt32Parameter ("systemsettlingtime", systemsettlingtime);
			pSignalUpdateHeaterControllerTunerParameters->setInt32Parameter ("maxtuningtime", maxtuningtime);
			pSignalUpdateHeaterControllerTunerParameters->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalUpdateOxygenControllerTunerParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "updatecontrollertunerparameters");
			pSignalUpdateOxygenControllerTunerParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateOxygenControllerTunerParameters->setInt32Parameter ("stepheight", stepheight);
			pSignalUpdateOxygenControllerTunerParameters->setInt32Parameter ("maxactvalue", maxactvalue);
			pSignalUpdateOxygenControllerTunerParameters->setInt32Parameter ("minactvalue", minactvalue);
			pSignalUpdateOxygenControllerTunerParameters->setInt32Parameter ("systemsettlingtime", systemsettlingtime);
			pSignalUpdateOxygenControllerTunerParameters->setInt32Parameter ("maxtuningtime", maxtuningtime);
			pSignalUpdateOxygenControllerTunerParameters->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_UpdateControllerPwmParameters : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_UpdateControllerPwmParameters(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_UpdateControllerPwmParameters()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_UPDATECONTROLLERPWMPARAMETERS;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerPwmParameters
		bool isinit = pEnvironment->readPayloadInt8(0); //Flag if this is an init command or an update command, 1 = init, 0 = update
		int controller_ID = pEnvironment->readPayloadInt16(1); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
		int dutycycle = pEnvironment->readPayloadInt16(3); //Duty cycle of the PWM ouput of the build plate temperature control in percent
		int period = pEnvironment->readPayloadInt32(5); //Period time of the PWM signal of the build plate temperature control in milli seconds
		int maxFrequency = pEnvironment->readPayloadInt16(9); //Max frequency of the PWM signal in Hz
		int mode = pEnvironment->readPayloadInt8(11); //Mode of the PWM signal, 1 = pulse in the middle, 0 = pulse in the beginning of the PWM period

		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalUpdateHeaterControllerPwmParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "updatecontrollerpwmparameters");
			pSignalUpdateHeaterControllerPwmParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateHeaterControllerPwmParameters->setInt32Parameter ("dutycycle", dutycycle);
			pSignalUpdateHeaterControllerPwmParameters->setInt32Parameter ("period", period);
			pSignalUpdateHeaterControllerPwmParameters->setInt32Parameter ("maxFrequency", maxFrequency);
			pSignalUpdateHeaterControllerPwmParameters->setBoolParameter ("mode", mode);
			pSignalUpdateHeaterControllerPwmParameters->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalUpdateOxygenControllerPwmParameters = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "updatecontrollerpwmparameters");
			pSignalUpdateOxygenControllerPwmParameters->setBoolParameter ("isinit", isinit);
			pSignalUpdateOxygenControllerPwmParameters->setInt32Parameter ("dutycycle", dutycycle);
			pSignalUpdateOxygenControllerPwmParameters->setInt32Parameter ("period", period);
			pSignalUpdateOxygenControllerPwmParameters->setInt32Parameter ("maxFrequency", maxFrequency);
			pSignalUpdateOxygenControllerPwmParameters->setBoolParameter ("mode", mode);
			pSignalUpdateOxygenControllerPwmParameters->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}
};


class CTcpPacketHandler_AutoTuneController : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_AutoTuneController(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_AutoTuneController()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_AUTOTUNECONTROLLER;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerTunerParameters
		int controller_ID = pEnvironment->readPayloadInt16(0); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
		int stepheight = pEnvironment->readPayloadInt16(2); //Height of the step to be applied during tuning of the PID controller in degree celcius or ppm
		int maxactvalue = pEnvironment->readPayloadInt32(4); //Max value of the range of the controlled variable during training in percent, maximum is 100 percent
		int minactvalue = pEnvironment->readPayloadInt16(8); //Min value of the range of the controlled variable during training in percent, must be positive
		int systemsettlingtime = pEnvironment->readPayloadInt32(10); //Time for the system to settle at the start setpoint before the step for tuning is applied in seconds
		int maxtuningtime = pEnvironment->readPayloadInt32(14); //Maximum time for the tuning including the settling time in seconds
		


		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalAutoTuneHeaterController = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "autotunecontroller");
			pSignalAutoTuneHeaterController->setInt32Parameter ("stepheight", stepheight);
			pSignalAutoTuneHeaterController->setInt32Parameter ("maxactvalue", maxactvalue);
			pSignalAutoTuneHeaterController->setInt32Parameter ("minactvalue", minactvalue);
			pSignalAutoTuneHeaterController->setInt32Parameter ("systemsettlingtime", systemsettlingtime);
			pSignalAutoTuneHeaterController->setInt32Parameter ("maxtuningtime", maxtuningtime);
			pSignalAutoTuneHeaterController->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalAutoTuneOxygenController = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "autotunecontroller");
			pSignalAutoTuneOxygenController->setInt32Parameter ("stepheight", stepheight);
			pSignalAutoTuneOxygenController->setInt32Parameter ("maxactvalue", maxactvalue);
			pSignalAutoTuneOxygenController->setInt32Parameter ("minactvalue", minactvalue);
			pSignalAutoTuneOxygenController->setInt32Parameter ("systemsettlingtime", systemsettlingtime);
			pSignalAutoTuneOxygenController->setInt32Parameter ("maxtuningtime", maxtuningtime);
			pSignalAutoTuneOxygenController->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_UpdateControllerSetpoint : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_UpdateControllerSetpoint(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_UpdateControllerSetpoint()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_UPDATECONTROLLERSETPOINT;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerSetpoint
		bool isinit = pEnvironment->readPayloadInt8(0); //Flag if this is an init command or an update command, 1 = init, 0 = update
		int controller_ID = pEnvironment->readPayloadInt16(1); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
		int setvalue = pEnvironment->readPayloadInt32(3); //Set value of the PID controller in degree celcius or ppm
	
		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalUpdateHeaterControllerSetpoint = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "updatecontrollersetpoint");
			pSignalUpdateHeaterControllerSetpoint->setBoolParameter ("isinit", isinit);
			pSignalUpdateHeaterControllerSetpoint->setInt32Parameter ("setvalue", setvalue);
			pSignalUpdateHeaterControllerSetpoint->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalUpdateOxygenControllerSetpoint = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "updatecontrollersetpoint");
			pSignalUpdateOxygenControllerSetpoint->setBoolParameter ("isinit", isinit);
			pSignalUpdateOxygenControllerSetpoint->setInt32Parameter ("setvalue", setvalue);
			pSignalUpdateOxygenControllerSetpoint->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_AbortAutoTuningController : public CTcpPacketHandler_Buffered
{
	public:
	CTcpPacketHandler_AbortAutoTuningController(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_AbortAutoTuningController()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_ABORTAUTOTUNINGCONTROLLER;
}

	void enterExecution(CPayloadEnvironment *pEnvironment) override
	{
		// set lifetime of the TCP Packet Handler
		pEnvironment->setLifetimeInMillseconds(1000);
		
		// read values of the command UpdateControllerSetpoint
		int controller_ID = pEnvironment->readPayloadInt16(0); //ID of the controller, 1 = plate temperature control, 2 = oxygen control

	
		//chekc which controller is addressed
		if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
		{
			auto pSignalAbortAutoTuningHeaterController = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "abortautotuningcontroller");
			pSignalAbortAutoTuningHeaterController->triggerSignal();
		}
		else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
		{
			auto pSignalAbortAutoTuningOxygenController = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "abortautotuningcontroller");
			pSignalAbortAutoTuningOxygenController->triggerSignal();
		}
	}

	bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				//TODO: process singal results
				return true;
			} else {
				return false;
			} 
		}
};

class CTcpPacketHandler_DisableController : public CTcpPacketHandler_Buffered
{

	public:
		
	CTcpPacketHandler_DisableController(CTcpListHandler *pListHandler)
		: CTcpPacketHandler_Buffered(pListHandler)
	{
	}

	virtual ~CTcpPacketHandler_DisableController()
	{
	}

	virtual uint32_t getCommandID() override
	{
	return CUSTOMCOMMAND_DISABLEBUILDPLATETEMPCONTROL;
}
	
		void enterExecution(CPayloadEnvironment *pEnvironment) override
		{
			pEnvironment->setLifetimeInMillseconds (1000);
	

			// read values of the command disablecontroller
			int controller_ID = pEnvironment->readPayloadInt16(0); //ID of the controller, 1 = plate temperature control, 2 = oxygen control
	
		
			//chekc which controller is addressed
			if (controller_ID == CONTROLLERID_BUIDLPLATETEMPCONTROL)
			{
				auto pSignalDisableBuildPlateTempControl = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL, "heater", "disablecontroller");
				pSignalDisableBuildPlateTempControl->triggerSignal();
	
			}
			else if (controller_ID == CONTROLLERID_OXYGENCONTROL)
			{
				auto pSignalDisableOxygenControl = pEnvironment->prepareSignal(CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL, "oxygen", "disablecontroller");
				pSignalDisableOxygenControl->triggerSignal();
			}

		}


		bool cyclicExecution(CPayloadEnvironment *pEnvironment) override
		{
			if (pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_BUIDLPLATETEMPCONTROL) || pEnvironment->signalHasBeenProcessed (CUSTOMCOMMAND_SIGNALSLOT_OXYGENCONTROL)) {
				return true;
			} else {
				return false;
			} 
		}

	};




void registerTCPHandlers (CApplication * pApplication)
{
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_TriggerSingleAxisMovement> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_ReferenceAxis> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_AbsoluteSwitchReferencing> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_RecoaterDualAxisMovement> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_Command_OpenDoor> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_Command_LockDoor> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_Toggle_Valves> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_InitAtmosphereControl> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_StartGasFlow> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_UpdateGasFlowSetpoint> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_TurnOffGasFlow> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_InitVacuumSystem> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_StartVacuumPump> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_TurnOffVacuumPump> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_EnableController> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_UpdateControllerPidParameters> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_UpdateControllerTunerParameters> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_UpdateControllerPwmParameters> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_UpdateControllerSetpoint> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_DisableController> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_AutoTuneController> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_AbortAutoTuningController> (pApplication->getListHandler ()));
	pApplication->registerPacketHandler (std::make_shared<CTcpPacketHandler_InitAxis> (pApplication->getListHandler ()));
}

}