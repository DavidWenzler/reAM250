/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Autodesk Inc. nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "libmcplugin_impl.hpp"
#include "libmcdriver_bur_dynamic.hpp"

#include <cmath>


#define CONTROLLER_ID_HEATER 1
#define CONTROLLER_ID_SHIELDINGGAS 2

#define AXISID_BUILDPLATFORM 1
#define AXISID_POWDERRESERVOIR 2
#define AXISID_RECOATERPOWDERBELT 3
#define AXISID_RECOATELINEAR 4
#define ABSOLUTE_FLAG 1
#define RELATIVE_FLAG 2

// Define error codes
#define ERROR_INVALID_VALVE_ID 100
#define ERROR_RECOATINGTIMEOUT 101


/*************************************************************************************************************************
 Import functionality for Driver into current plugin
**************************************************************************************************************************/
LIBMC_IMPORTDRIVERCLASSES(BuR, BuR)

__BEGINDRIVERIMPORT
__IMPORTDRIVER(BuR, "bur");
__ENDDRIVERIMPORT


/*************************************************************************************************************************
  State definitions
**************************************************************************************************************************/
__BEGINSTATEDEFINITIONS

__DECLARESTATE(init)
{
	pStateEnvironment->LogMessage("Initializing...");
	
	std::string sIPAddress = pStateEnvironment->GetStringParameter("configuration", "ipaddress");
	auto nPort = pStateEnvironment->GetIntegerParameter("configuration", "port");
	auto nConnectionTimeout = pStateEnvironment->GetIntegerParameter("configuration", "connectiontimeout");

	auto pDriver = __acquireDriver(BuR);

	bool bIsSimulation = pStateEnvironment->GetBoolParameter("simulation", "plc_is_simulated");
	if (bIsSimulation) {
		pStateEnvironment->LogMessage("PLC is in SIMULATION MODE.");
		pDriver->SetToSimulationMode();
	}

	pStateEnvironment->LogMessage("Connecting to PLC...");
	
	pDriver->Connect(sIPAddress, (uint32_t)nPort, (uint32_t)nConnectionTimeout);
	pStateEnvironment->LogMessage("successful...");
	pStateEnvironment->LogMessage("Initializing machine..");
	//pDriver->ReinitializeMachine();
	pStateEnvironment->LogMessage("Successfully Initialized machine..");

	pStateEnvironment->SetNextState("idle");
}


__DECLARESTATE(idle) 
{

	bool bIsSimulation = pStateEnvironment->GetBoolParameter("simulation", "plc_is_simulated");

	// Get Timeouts
	uint32_t nResponseTimeout = pStateEnvironment->GetDoubleParameter("timeouts", "responsetimeout");
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");
	uint32_t nVacuumInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "vacuuminittimeout");
	uint32_t nAtmosphereInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "atmosphereinittimeout");
	uint32_t nControllerUpdateTimeout = pStateEnvironment->GetDoubleParameter("timeouts", "controllerupdatetimeout");
	uint32_t nToggleValvesTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "togglevalvestimeout");
	uint32_t nStartStopPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "startstoppumptimeout");
	uint32_t nAxesInitTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "axesinittimeout");
	
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	LibMCEnv::PSignalHandler pSignalHandler;
	if (pStateEnvironment->WaitForSignal("signal_checkemergencycircuit", 0, pSignalHandler)) {
		if (bIsSimulation) {
			// In simulation mode, just return values from config parameter group
			bool bCircuitIsClosed = pStateEnvironment->GetBoolParameter("simulation", "plcsimulation_circuitisclosed");
			pSignalHandler->SetBoolResult ("circuitisclosed", bCircuitIsClosed);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			// Retrieve actual values from PLC
			pBuRDriver->QueryParameters();
			bool bCircuitIsClosed = (!pStateEnvironment->GetBoolParameter("plcstate", "115kf51_safeinput05"));// && !pStateEnvironment->GetBoolParameter("plcstate", "115kf51_safeinput06"));
			pSignalHandler->SetBoolResult("circuitisclosed", bCircuitIsClosed);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_initaxes", 0, pSignalHandler)) {
		pBuRDriver->QueryParameters();
		pStateEnvironment->LogMessage("Triggering axes initialization...");

		auto pPLCPlatformInitCommandList = pBuRDriver->CreateCommandList();
		auto pPlatformInitCommand = pBuRDriver->CreateCommand("initaxes");
		pPlatformInitCommand->SetIntegerParameter("axis_ID", AXISID_BUILDPLATFORM);
		pPLCPlatformInitCommandList->AddCommand(pPlatformInitCommand);
		pPLCPlatformInitCommandList->FinishList();
		pPLCPlatformInitCommandList->ExecuteList();

		auto pPLCReservoirInitCommandList = pBuRDriver->CreateCommandList();
		auto pReservoirInitCommand = pBuRDriver->CreateCommand("initaxes");
		pReservoirInitCommand->SetIntegerParameter("axis_ID", AXISID_POWDERRESERVOIR);
		pPLCReservoirInitCommandList->AddCommand(pReservoirInitCommand);
		pPLCReservoirInitCommandList->FinishList();
		pPLCReservoirInitCommandList->ExecuteList();

		auto pPLCRecoaterPowderInitCommandList = pBuRDriver->CreateCommandList();
		auto pRecoaterPowderInitCommand = pBuRDriver->CreateCommand("initaxes");
		pRecoaterPowderInitCommand->SetIntegerParameter("axis_ID", AXISID_RECOATERPOWDERBELT);
		pPLCRecoaterPowderInitCommandList->AddCommand(pRecoaterPowderInitCommand);
		pPLCRecoaterPowderInitCommandList->FinishList();
		pPLCRecoaterPowderInitCommandList->ExecuteList();

		auto pPLCRecoaterLinearInitCommandList = pBuRDriver->CreateCommandList();
		auto pRecoaterLinearInitCommand = pBuRDriver->CreateCommand("initaxes");
		pRecoaterLinearInitCommand->SetIntegerParameter("axis_ID", AXISID_RECOATELINEAR);
		pPLCRecoaterLinearInitCommandList->AddCommand(pRecoaterLinearInitCommand);
		pPLCRecoaterLinearInitCommandList->FinishList();
		pPLCRecoaterLinearInitCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nGeneralCommandTimeout);
		if (true)//pPLCPlatformInitCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout) && pPLCReservoirInitCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout) && pPLCRecoaterPowderInitCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout) && pPLCRecoaterLinearInitCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pStateEnvironment->LogMessage("Init axes signal received ...");
			pStateEnvironment->SetNextState("waitforreferencing");
			pStateEnvironment->StoreSignal("signal_initaxes", pSignalHandler);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("connectionlost");
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_releasedoor", 0, pSignalHandler)) {
		pBuRDriver->QueryParameters();
		pStateEnvironment->LogMessage("Releasing door....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pCommand = pBuRDriver->CreateCommand("releasedoor");
		pPLCCommandList->AddCommand(pCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nGeneralCommandTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			//TODO: get current state of door pBuRDriver->QueryParameters();
			pSignalHandler->SetBoolResult("success", true);
			pStateEnvironment->SetNextState("idle");
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_lockdoor", 0, pSignalHandler)) {
		
		bool bLockDoor = pSignalHandler->GetBool("lockdoor");

		if (bLockDoor) {
			pStateEnvironment->LogMessage("Locking door....");
		}
		else {
			pStateEnvironment->LogMessage("Unlocking door....");
		}
		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pCommand = pBuRDriver->CreateCommand("lockunlockdoor");
		pCommand->SetBoolParameter("lockdoor", bLockDoor);
		pPLCCommandList->AddCommand(pCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nGeneralCommandTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			//TODO: get current state of door pBuRDriver->QueryParameters();
			pSignalHandler->SetBoolResult("doorlockstate", bLockDoor);
			pSignalHandler->SetBoolResult("success", true);
			pStateEnvironment->SetNextState("idle");
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_togglevalve", 0, pSignalHandler)) {
		pBuRDriver->QueryParameters();

		pStateEnvironment->LogMessage("Toggling valve....");
		// Retrieve state of the valves controlling digital ouputs from the PLC
		bool bState_upper_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "114kf25_output01");
		bool bState_lower_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "114kf25_output02");
		bool bState_shielding_gas_valve = pStateEnvironment->GetBoolParameter("plcstate", "114kf25_output03");
		bool bState_chamber_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "114kf25_output04");
		bool bState_zAxis_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "114kf25_output05");

		// get ID of the valve to toggle
		int nValve_ID = pSignalHandler->GetInteger("valve_ID");

		if (nValve_ID == 1)
		{
			bState_upper_gas_flow_circuit_valve = !bState_upper_gas_flow_circuit_valve;
		}
		else if (nValve_ID == 2)
		{
			bState_lower_gas_flow_circuit_valve = !bState_lower_gas_flow_circuit_valve;
		}
		else if (nValve_ID == 3)
		{
			bState_shielding_gas_valve = !bState_shielding_gas_valve;
		}
		else if (nValve_ID == 4)
		{
			bState_chamber_vacuum_valve = !bState_chamber_vacuum_valve;
		}
		else if (nValve_ID == 5)
		{
			bState_zAxis_vacuum_valve = !bState_zAxis_vacuum_valve;
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SetIntegerResult("errorcode", ERROR_INVALID_VALVE_ID);
			pStateEnvironment->LogMessage("Error: invalid valve ID #" + std::to_string(ERROR_INVALID_VALVE_ID));
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
			return;
		}

		
		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pToggleValvesCommand = pBuRDriver->CreateCommand("togglevalves");
		pToggleValvesCommand->SetBoolParameter("toggle_upper_gas_flow_circuit_valve", bState_upper_gas_flow_circuit_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_lower_gas_flow_circuit_valve", bState_lower_gas_flow_circuit_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_shielding_gas_valve", bState_shielding_gas_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_chamber_vacuum_valve", bState_chamber_vacuum_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_zAxis_vacuum_valve", bState_zAxis_vacuum_valve);
		pPLCCommandList->AddCommand(pToggleValvesCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nToggleValvesTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nToggleValvesTimeout))
		{
			pSignalHandler->SetBoolResult("success", true);
			pStateEnvironment->SetNextState("idle");
		}
		else
			{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
			}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_switchvalves", 0, pSignalHandler)) {
		pBuRDriver->QueryParameters();

		pStateEnvironment->LogMessage("Switching multiple valves....");

		// Retrieve desired state of the valves from the main state machine
		bool bSet_upper_gas_flow_circuit_valve = pSignalHandler->GetBool("toggle_upper_gas_flow_circuit_valve");
		bool bSet_lower_gas_flow_circuit_valve = pSignalHandler->GetBool("toggle_lower_gas_flow_circuit_valve");
		bool bSet_shielding_gas_valve = pSignalHandler->GetBool("toggle_shielding_gas_valve");
		bool bSet_chamber_vacuum_valve = pSignalHandler->GetBool("toggle_chamber_vacuum_valve");
		bool bSet_zAxis_vacuum_valve = pSignalHandler->GetBool("toggle_zAxis_vacuum_valve");

		// Check if the desired state equals the actual state
		bool bIs_set_upper_gas_flow_circuit_valve;
		bool bIs_set_lower_gas_flow_circuit_valve;
		bool bIs_set_chamber_vacuum_valve;
		bool bIs_set_zAxis_vacuum_valve;

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pToggleValvesCommand = pBuRDriver->CreateCommand("togglevalves");
		pToggleValvesCommand->SetBoolParameter("toggle_upper_gas_flow_circuit_valve", bSet_upper_gas_flow_circuit_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_lower_gas_flow_circuit_valve", bSet_lower_gas_flow_circuit_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_shielding_gas_valve", bSet_shielding_gas_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_chamber_vacuum_valve", bSet_chamber_vacuum_valve);
		pToggleValvesCommand->SetBoolParameter("toggle_zAxis_vacuum_valve", bSet_zAxis_vacuum_valve);
		pPLCCommandList->AddCommand(pToggleValvesCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();
		
		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nToggleValvesTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nToggleValvesTimeout))
		{
			pBuRDriver->QueryParameters();

			// Retrieve actual state of the valves from the PLC
			bool bIs_opened_upper_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf17_input01");
			bool bIs_closed_upper_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf17_input02");
			bool bIs_opened_lower_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf17_input03");
			bool bIs_closed_lower_gas_flow_circuit_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf17_input04");

			bool bIs_opened_chamber_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf21_input01");
			bool bIs_closed_chamber_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf21_input02");
			bool bIs_opened_zAxis_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf21_input03");
			bool bIs_closed_zAxis_vacuum_valve = pStateEnvironment->GetBoolParameter("plcstate", "113kf21_input04");

			if (bSet_upper_gas_flow_circuit_valve)
			{
				bIs_set_upper_gas_flow_circuit_valve = bIs_opened_upper_gas_flow_circuit_valve;
			}
			else
			{
				bIs_set_upper_gas_flow_circuit_valve = bIs_closed_upper_gas_flow_circuit_valve;
			}

			if (bSet_lower_gas_flow_circuit_valve)
			{
				bIs_set_lower_gas_flow_circuit_valve = bIs_opened_lower_gas_flow_circuit_valve;
			}
			else
			{
				bIs_set_lower_gas_flow_circuit_valve = bIs_closed_lower_gas_flow_circuit_valve;
			}

			if (bSet_chamber_vacuum_valve)
			{
				bIs_set_chamber_vacuum_valve = bIs_opened_chamber_vacuum_valve;
			}
			else
			{
				bIs_set_chamber_vacuum_valve = bIs_closed_chamber_vacuum_valve;
			}

			if (bSet_zAxis_vacuum_valve)
			{
				bIs_set_zAxis_vacuum_valve = bIs_opened_zAxis_vacuum_valve;
			}
			else
			{
				bIs_set_zAxis_vacuum_valve = bIs_closed_zAxis_vacuum_valve;
			}

			if (bIs_set_upper_gas_flow_circuit_valve && bIs_set_lower_gas_flow_circuit_valve && bIs_set_chamber_vacuum_valve && bIs_set_zAxis_vacuum_valve)
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("idle");
			}
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_atmospherecontrol_init", 0, pSignalHandler)) {
		pStateEnvironment->LogMessage("Initializing atmosphere control....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pAtmosphereControlInitCommand = pBuRDriver->CreateCommand("initatmospherecontrol");
		pAtmosphereControlInitCommand->SetIntegerParameter("o2_threshold_circulation_on_in_ppm", pSignalHandler->GetInteger("o2_threshold_circulation_on_in_ppm"));
		pAtmosphereControlInitCommand->SetIntegerParameter("o2_threshold_circulation_off_in_ppm", pSignalHandler->GetInteger("o2_threshold_circulation_off_in_ppm"));
		pPLCCommandList->AddCommand(pAtmosphereControlInitCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nAtmosphereInitTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nAtmosphereInitTimeout))
		{
			pSignalHandler->SetBoolResult("success", true);
			pStateEnvironment->SetNextState("idle");
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_atmospherecontrol_update_gas_flow_setpoint", 0, pSignalHandler)) {
		pStateEnvironment->LogMessage("Updating gas flow setpoint for atmosphere control....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pAtmosphereControlUpdateGasFlowSetpointCommand = pBuRDriver->CreateCommand("updategasflowsetpoint");
		pAtmosphereControlUpdateGasFlowSetpointCommand->SetIntegerParameter("setpoint_in_percent", pSignalHandler->GetInteger("setpoint_in_percent"));
		pPLCCommandList->AddCommand(pAtmosphereControlUpdateGasFlowSetpointCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
	
	else if (pStateEnvironment->WaitForSignal("signal_atmospherecontrol_start_gas_flow", 0, pSignalHandler)) {

			pStateEnvironment->LogMessage("Start circulation pump signal received ...");
			pStateEnvironment->SetNextState("startgasflow");
			pStateEnvironment->StoreSignal("signal_atmospherecontrol_start_gas_flow", pSignalHandler);
	}
	
	else if (pStateEnvironment->WaitForSignal("signal_atmospherecontrol_turn_off_gas_flow", 0, pSignalHandler)) {
		pStateEnvironment->LogMessage("Turning off gas flow for atmosphere control....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pAtmosphereControlTurnOffGasFlowCommand = pBuRDriver->CreateCommand("turnoffgasflow");
		pPLCCommandList->AddCommand(pAtmosphereControlTurnOffGasFlowCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nStartStopPumpTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bCirculationPumpIsTurnedOn = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input02");
			if (bCirculationPumpIsTurnedOn == false)
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();

	}

	else if (pStateEnvironment->WaitForSignal("signal_vacuumcontrol_init", 0, pSignalHandler)) {

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pVacuumControlInitCommand = pBuRDriver->CreateCommand("initvacuumsystem");
		pVacuumControlInitCommand->SetIntegerParameter("pressure_threshold_vacuum_off_in_mbar", pSignalHandler->GetInteger("pressure_threshold_vacuum_off_in_mbar"));
		pPLCCommandList->AddCommand(pVacuumControlInitCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nVacuumInitTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nVacuumInitTimeout))
		{
			pSignalHandler->SetBoolResult("success", true);
			pStateEnvironment->SetNextState("idle");
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_vacuumcontrol_start_vacuum_pump", 0, pSignalHandler)) {
		
		// Get desired absolute pressure in the PLC
		int nPressureThresholdPLC = pStateEnvironment->GetIntegerParameter("plcstate", "pressure_threshold_vacuum_off_in_mbar");
		
		// Get desired absolute pressure in the AMCF
		int nPressureThresholdAMCF = pSignalHandler->GetInteger("pressure_threshold_vacuum_off_in_mbar");

		if (nPressureThresholdAMCF == nPressureThresholdPLC) // Check if both thresholds are identical and the initialization was done properly
		{
			pStateEnvironment->LogMessage("Start vacuum pump signal received ...");
			pStateEnvironment->SetNextState("evacuatebuildchamber");
			pStateEnvironment->StoreSignal("signal_vacuumcontrol_start_vacuum_pump", pSignalHandler);
		}
		else
		{
			pStateEnvironment->LogMessage("Initialization error of the vacuum system: Thresholds are not identical in the PLC and the AMCF ...");
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
	}

	else if (pStateEnvironment->WaitForSignal("signal_vacuumcontrol_turn_off_vacuum_pump", 0, pSignalHandler)) {
		pStateEnvironment->LogMessage("Turning off the vacuum pump....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pVacuumControlTurnOffPumpCommand = pBuRDriver->CreateCommand("turnoffvacuumpump");
		pPLCCommandList->AddCommand(pVacuumControlTurnOffPumpCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nStartStopPumpTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bVacuumPumpIsTurnedOn = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input04");
			if (bVacuumPumpIsTurnedOn == false)
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("idle");
			}
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}

		pSignalHandler->SignalHandled();
	}

	else if (pStateEnvironment->WaitForSignal("signal_checkpowderavailability", 0, pSignalHandler)) {
		if (bIsSimulation) {
			// In simulation mode, just return values from config parameter group
			double dFillLevel = pStateEnvironment->GetDoubleParameter("simulation", "plcsimulation_filllevel");
			pSignalHandler->SetDoubleResult("filllevel", dFillLevel);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			// TODO: Retrieve actual values from PLC
			double dFillLevel = pStateEnvironment->GetDoubleParameter("simulation", "plcsimulation_filllevel");
			pSignalHandler->SetDoubleResult("filllevel", dFillLevel);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}

	}


	else if (pStateEnvironment->WaitForSignal("signal_reference", 0, pSignalHandler)) {
		
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE axis referencing...");
			pStateEnvironment->Sleep(3000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			auto pCommandList = pBuRDriver->CreateCommandList();

			pStateEnvironment->LogMessage("Manually axis referencing");

			if (pSignalHandler->GetBool("reference_platform_absolute_switch") == true) {
				auto pReferenceAbsoluteSwitchCommand = pBuRDriver->CreateCommand("absoluteswitchreferencing");
				pCommandList->AddCommand(pReferenceAbsoluteSwitchCommand);
			}
			else {
				auto pReferenceCommand = pBuRDriver->CreateCommand("referenceaxes");
				pReferenceCommand->SetBoolParameter("reference_recoateraxis_linear", pSignalHandler->GetBool("reference_recoateraxis_linear"));
				pReferenceCommand->SetBoolParameter("reference_recoateraxis_powder", pSignalHandler->GetBool("reference_recoateraxis_powder"));
				pReferenceCommand->SetBoolParameter("reference_platform", pSignalHandler->GetBool("reference_platform"));
				pReferenceCommand->SetBoolParameter("reference_powderreservoir", pSignalHandler->GetBool("reference_powderreservoir"));
				pCommandList->AddCommand(pReferenceCommand);
			}

			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nAxesInitTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nAxesInitTimeout))
			{ 
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();

		}

	}
	
	else if (pStateEnvironment->WaitForSignal("signal_singleaxismovement", 0, pSignalHandler)) {
		if (bIsSimulation) 
		{

			pStateEnvironment->LogMessage("SIMULATE single axis movement...");
			pStateEnvironment->Sleep(3000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else 
		{
			auto nAxisID = pSignalHandler->GetInteger("axis_ID");


			if (nAxisID == AXISID_BUILDPLATFORM) {
				pStateEnvironment->LogMessage("Move build platform axis signal received ...");
				pStateEnvironment->SetNextState("moveplatform");
			}
			else if (nAxisID == AXISID_POWDERRESERVOIR) {
				pStateEnvironment->LogMessage("Move powder reservoir axis signal received ...");
				pStateEnvironment->SetNextState("movepowderreservoir");
			}
			else if (nAxisID == AXISID_RECOATERPOWDERBELT) {
				pStateEnvironment->LogMessage("Move recoater powder belt axis signal received ...");
				pStateEnvironment->SetNextState("moverecoaterpowderbelt");
			}
			else if (nAxisID == AXISID_RECOATELINEAR) {
				pStateEnvironment->LogMessage("Move recoater linear axis signal received ...");
				pStateEnvironment->SetNextState("moverecoaterlinear");
			}

			pStateEnvironment->StoreSignal("signal_singleaxismovement", pSignalHandler);
		}
	}


	else if (pStateEnvironment->WaitForSignal("signal_checkaxisstate", 0, pSignalHandler)) {

		if (bIsSimulation) {
			// In simulation mode, just return values from config parameter group
			bool bRecoaterAxisLinearReady = pStateEnvironment->GetBoolParameter("simulation", "plcsimulation_recoateraxis_linear_ready");
			bool bRecoaterAxisPowderReady = pStateEnvironment->GetBoolParameter("simulation", "plcsimulation_recoateraxis_powder_ready");
			bool bPowderReservoirAxisReady = pStateEnvironment->GetBoolParameter("simulation", "plcsimulation_powderreservoiraxis_ready");
			bool bPlatformAxisReady = pStateEnvironment->GetBoolParameter("simulation", "plcsimulation_platformaxis_ready");
			pSignalHandler->SetBoolResult("recoateraxis_linear_ready", bRecoaterAxisLinearReady);
			pSignalHandler->SetBoolResult("recoateraxis_powder_ready", bRecoaterAxisPowderReady);
			pSignalHandler->SetBoolResult("powderreservoiraxis_ready", bPowderReservoirAxisReady);
			pSignalHandler->SetBoolResult("platformaxis_ready", bPlatformAxisReady);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");

		}
		else {
			// Retrieve actual values from PLC
			pBuRDriver->QueryParameters();
			bool bRecoaterAxisLinearReady = (pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_isreferenced"));
			bool bRecoaterAxisPowderReady = (pStateEnvironment->GetBoolParameter("plcstate", "axRecoaterPowderBelt_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axRecoaterPowderBelt_isreferenced"));
			bool bPowderReservoirAxisReady = (pStateEnvironment->GetBoolParameter("plcstate", "axPowderReservoir_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axPowderReservoir_isreferenced"));
			bool bPlatformAxisReady = (pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_isreferenced"));
			pSignalHandler->SetBoolResult("recoateraxis_linear_ready", bRecoaterAxisLinearReady);
			pSignalHandler->SetBoolResult("recoateraxis_powder_ready", bRecoaterAxisPowderReady);
			pSignalHandler->SetBoolResult("powderreservoiraxis_ready", bPowderReservoirAxisReady);
			pSignalHandler->SetBoolResult("platformaxis_ready", bPlatformAxisReady);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");

		}

	}

	else if (pStateEnvironment->WaitForSignal("signal_recoatlayer", 0, pSignalHandler)) {

		pStateEnvironment->LogMessage("Recoat layer signal received ...");

		pStateEnvironment->SetNextState("moveplatformclear");

		pStateEnvironment->StoreSignal("signal_recoatlayer", pSignalHandler);


	}

	else if (pStateEnvironment->WaitForSignal("signal_enablecontroller", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE enabling controller...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {

			int nController_ID = pSignalHandler->GetInteger("controller_ID");

			if (nController_ID == CONTROLLER_ID_HEATER)
			{
				pStateEnvironment->LogMessage("Enable heater controller signal received");
				pStateEnvironment->SetNextState("updatebuildplatetemperature");
				pStateEnvironment->StoreSignal("signal_enablecontroller", pSignalHandler);
			}
			else if (nController_ID == CONTROLLER_ID_SHIELDINGGAS)
			{
				pStateEnvironment->LogMessage("Enable shielding gas controller signal received");
				pStateEnvironment->SetNextState("shieldinggasflooding");
				pStateEnvironment->StoreSignal("signal_enablecontroller", pSignalHandler);
			}
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_disablecontroller", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE disabling controller...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {

			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto pCommandList = pBuRDriver->CreateCommandList();

			pStateEnvironment->LogMessage("Turn off controller");

			auto pDisableControllerCommand = pBuRDriver->CreateCommand("disablecontroller");
			pDisableControllerCommand->SetIntegerParameter("controller_ID", nController_ID);
			pCommandList->AddCommand(pDisableControllerCommand);

			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nGeneralCommandTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
			{
				pBuRDriver->QueryParameters();

				bool bControllerIsEnabled = false;

				if (nController_ID == CONTROLLER_ID_HEATER)
				{
					bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "heater_PID_isenabled");
				}
				else if (nController_ID == CONTROLLER_ID_SHIELDINGGAS)
				{
					bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "oxygencontrol_PID_isenabled");
				}

				if (bControllerIsEnabled == false)
				{
					pSignalHandler->SetBoolResult("success", true);
				}
				else
				{
					pSignalHandler->SetBoolResult("success", false);
				}
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();

		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_updatecontrollersetpoint", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE controller setpoint update...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {

			auto bIsinit = pSignalHandler->GetBool("isinit");
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto nSetpoint = pSignalHandler->GetInteger("setpoint");
		
			auto pCommandList = pBuRDriver->CreateCommandList();

			pStateEnvironment->LogMessage("Update controller setpoint");

			auto pUpdateControllerSetpointCommand = pBuRDriver->CreateCommand("updatecontrollersetpoint");
			pUpdateControllerSetpointCommand->SetBoolParameter("isinit", bIsinit);
			pUpdateControllerSetpointCommand->SetIntegerParameter("controller_ID", nController_ID);
			pUpdateControllerSetpointCommand->SetIntegerParameter("setvalue", nSetpoint);
			pCommandList->AddCommand(pUpdateControllerSetpointCommand);

			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nControllerUpdateTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nControllerUpdateTimeout))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_updatecontrollerPID", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE controller PID parameter update...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			
			auto pCommandList = pBuRDriver->CreateCommandList();

			// retrieve PID parameters from signal
			//retrieve PID parameters from the parameter group
			auto bIsinit = pSignalHandler->GetBool("isinit");
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto dDerivativetime = pSignalHandler->GetDouble("derivativetime");
			auto dIntegrationtime = pSignalHandler->GetDouble("integrationtime");
			auto dGain = pSignalHandler->GetDouble("gain");
			auto dFiltertime = pSignalHandler->GetDouble("filtertime");
			auto nMaxout = pSignalHandler->GetInteger("maxout");
			auto nMinout = pSignalHandler->GetInteger("minout");

			auto pControllerPidUpdateCommand = pBuRDriver->CreateCommand("updatecontrollerPIDparameters");
			pControllerPidUpdateCommand->SetBoolParameter("isinit", bIsinit);
			pControllerPidUpdateCommand->SetIntegerParameter("controller_ID", nController_ID);
			pControllerPidUpdateCommand->SetIntegerParameter("derivativetime", (int32_t)round(dDerivativetime * 1000.0));
			pControllerPidUpdateCommand->SetIntegerParameter("integrationtime", (int32_t)round(dIntegrationtime * 1000.0));
			pControllerPidUpdateCommand->SetIntegerParameter("gain", (int32_t)round(dGain * 1000.0));
			pControllerPidUpdateCommand->SetIntegerParameter("filtertime", (int32_t)round(dFiltertime * 1000.0));
			pControllerPidUpdateCommand->SetIntegerParameter("maxout", nMaxout);
			pControllerPidUpdateCommand->SetIntegerParameter("minout", nMinout);
			pCommandList->AddCommand(pControllerPidUpdateCommand);


			pStateEnvironment->LogMessage("Trigger PID parameter update");
			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nControllerUpdateTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nControllerUpdateTimeout))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_updatecontrollerPWM", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE controller PWM parameter update...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			auto pCommandList = pBuRDriver->CreateCommandList();

			// retrieve PWM parameters from signal
			//retrieve PWM parameters from the parameter group
			auto bIsinit = pSignalHandler->GetBool("isinit");
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto nDutycycle = pSignalHandler->GetInteger("dutycycle");
			auto dPeriodTime = pSignalHandler->GetDouble("periodTime");
			auto nMaxFrequency = pSignalHandler->GetInteger("maxFrequency");
			auto bMode = pSignalHandler->GetBool("mode");
	
			auto pControllerPwmUpdateCommand = pBuRDriver->CreateCommand("updatecontrollerPWMparameters");
			pControllerPwmUpdateCommand->SetBoolParameter("isinit", bIsinit);
			pControllerPwmUpdateCommand->SetIntegerParameter("controller_ID", nController_ID);
			pControllerPwmUpdateCommand->SetIntegerParameter("dutycycle", nDutycycle);
			pControllerPwmUpdateCommand->SetIntegerParameter("periodTime", (int32_t)round(dPeriodTime*1000));
			pControllerPwmUpdateCommand->SetIntegerParameter("maxFrequency", nMaxFrequency);
			pControllerPwmUpdateCommand->SetBoolParameter("mode", bMode);
			pCommandList->AddCommand(pControllerPwmUpdateCommand);

			pStateEnvironment->LogMessage("Trigger PWM parameter update");
			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nControllerUpdateTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nControllerUpdateTimeout))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_updatecontrollertuner", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE controller tuner parameter update...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			auto pCommandList = pBuRDriver->CreateCommandList();

			// retrieve tuning parameters from signal
			//retrieve tuning parameters from the parameter group
			auto bIsinit = pSignalHandler->GetBool("isinit");
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto nStepheight = pSignalHandler->GetInteger("stepheight");
			auto nMaxactvalue = pSignalHandler->GetInteger("maxactvalue");
			auto nMinactvalue = pSignalHandler->GetInteger("minactvalue");
			auto dSystemsettlingtime = pSignalHandler->GetDouble("systemsettlingtime");
			auto dMaxtuningtime = pSignalHandler->GetDouble("maxtuningtime");

			auto pControllerTunerUpdateCommand = pBuRDriver->CreateCommand("updatecontrollertunerparameters");
			pControllerTunerUpdateCommand->SetBoolParameter("isinit", bIsinit);
			pControllerTunerUpdateCommand->SetIntegerParameter("controller_ID", nController_ID);
			pControllerTunerUpdateCommand->SetIntegerParameter("stepheight", nStepheight);
			pControllerTunerUpdateCommand->SetIntegerParameter("maxactvalue", nMaxactvalue);
			pControllerTunerUpdateCommand->SetIntegerParameter("minactvalue", nMinactvalue);
			pControllerTunerUpdateCommand->SetIntegerParameter("systemsettlingtime", (int32_t)round(dSystemsettlingtime * 1000.0));
			pControllerTunerUpdateCommand->SetIntegerParameter("maxtuningtime", (int32_t)round(dMaxtuningtime * 1000.0));
			pCommandList->AddCommand(pControllerTunerUpdateCommand);
			
			pStateEnvironment->LogMessage("Trigger tuner parameter update");
			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nControllerUpdateTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nControllerUpdateTimeout))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_controllertuning", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE controller tuning...");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			auto pCommandList = pBuRDriver->CreateCommandList();

			// retrieve tuning parameters from signal
			//retrieve tuning parameters from the parameter group
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			auto nStepheight = pSignalHandler->GetInteger("stepheight");
			auto nMaxactvalue = pSignalHandler->GetInteger("maxactvalue");
			auto nMinactvalue = pSignalHandler->GetInteger("minactvalue");
			auto dSystemsettlingtime = pSignalHandler->GetDouble("systemsettlingtime");
			auto dMaxtuningtime = pSignalHandler->GetDouble("maxtuningtime");

			auto pAutoTuneControllerCommand = pBuRDriver->CreateCommand("autotunecontroller");
			pAutoTuneControllerCommand->SetIntegerParameter("controller_ID", nController_ID);
			pAutoTuneControllerCommand->SetIntegerParameter("stepheight", nStepheight);
			pAutoTuneControllerCommand->SetIntegerParameter("maxactvalue", nMaxactvalue);
			pAutoTuneControllerCommand->SetIntegerParameter("minactvalue", nMinactvalue);
			pAutoTuneControllerCommand->SetIntegerParameter("systemsettlingtime", (int32_t)round(dSystemsettlingtime * 1000.0));
			pAutoTuneControllerCommand->SetIntegerParameter("maxtuningtime", (int32_t)round(dMaxtuningtime * 1000.0));
			pCommandList->AddCommand(pAutoTuneControllerCommand);

			pStateEnvironment->LogMessage("Trigger controller auto tuning");
			pCommandList->FinishList();
			pCommandList->ExecuteList();
			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep((int32_t)round(dMaxtuningtime * 1000.0));
			if (true)//pCommandList->WaitForList(300, (int32_t)round(dMaxtuningtime * 1000.0)))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_abortcontrollertuning", 0, pSignalHandler)) {
		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE aborting controller tuning...");
			pStateEnvironment->Sleep(1000);
			pSignalHandler->SetBoolResult("success", true);
			pSignalHandler->SignalHandled();
			pStateEnvironment->SetNextState("idle");
		}
		else {
			auto pCommandList = pBuRDriver->CreateCommandList();

			// retrieve controller ID from signal
			auto nController_ID = pSignalHandler->GetInteger("controller_ID");
			

			auto pAbortAutoTuneControllerCommand = pBuRDriver->CreateCommand("abortautotuningcontroller");
			pAbortAutoTuneControllerCommand->SetIntegerParameter("controller_ID", nController_ID);
			pCommandList->AddCommand(pAbortAutoTuneControllerCommand);

			pStateEnvironment->LogMessage("Trigger abort controller auto tuning");
			pCommandList->FinishList();
			pCommandList->ExecuteList();

			//TODO: delete sleep and repair PLC responce
			pStateEnvironment->Sleep(nGeneralCommandTimeout);
			if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
			{
				pSignalHandler->SetBoolResult("success", true);
				pStateEnvironment->SetNextState("idle");
			}
			else
			{
				pSignalHandler->SetBoolResult("success", false);
				pStateEnvironment->SetNextState("connectionlost");
			}

			pSignalHandler->SignalHandled();
		}

	}
	else if (pStateEnvironment->WaitForSignal("signal_check_heater", 0, pSignalHandler)) {

		pStateEnvironment->SetNextState("idle");

		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE heater check");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("heater_controller_enabled_setpoint_reached", true);
			pSignalHandler->SignalHandled();
		}
		else {
			pBuRDriver->QueryParameters();

			// Get actual temperature of the build plate heater
			int nBuildPlateTemperatureInDegreeCelsius = (int)(20 * pStateEnvironment->GetDoubleParameter("plcstate", "112kf15_voltage02"));
			// Get desired temperature of the build plate heater
			int nHeaterSetpointInDegreeCelsius = pStateEnvironment->GetIntegerParameter("plcstate", "heater_PID_setvalue");
			// Get the tolerance from the signal
			int nToleranceInDegreeCelsius = pSignalHandler->GetInteger("heater_controller_tolerance_degree_celsius");
			// Check if the heater controller is enabled
			bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "heater_PID_isenabled");

			if ((nBuildPlateTemperatureInDegreeCelsius > nHeaterSetpointInDegreeCelsius - nToleranceInDegreeCelsius) && (nBuildPlateTemperatureInDegreeCelsius < nHeaterSetpointInDegreeCelsius + nToleranceInDegreeCelsius) && bControllerIsEnabled)
			{
				pSignalHandler->SetBoolResult("heater_controller_enabled_setpoint_reached", true);
			}
			else
			{
				pSignalHandler->SetBoolResult("heater_controller_enabled_setpoint_reached", false);
			}

			pSignalHandler->SignalHandled();
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_check_atmosphere", 0, pSignalHandler)) {

		pStateEnvironment->SetNextState("idle");

		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE atmosphere check");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("atmosphere_controller_enabled_setpoint_reached", true);
			pSignalHandler->SignalHandled();
		}
		else {
			pBuRDriver->QueryParameters();

			// Get actual oxygen value in the filter
			int nO2FilterInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_filter_ppm");
			// Get desired oxygen value to turn on the circulation pump
			int nO2ThresholdCirculationOnInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_threshold_circulation_on_in_ppm");
			// Get the tolerance from the signal
			int nToleranceInPPM = pSignalHandler->GetInteger("atmosphere_controller_tolerance_ppm");
			// Check if the shielding gas controller is enabled
			bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "oxygencontrol_PID_isenabled");

			if ((nO2FilterInPPM < nO2ThresholdCirculationOnInPPM - nToleranceInPPM) && bControllerIsEnabled)
			{
				pSignalHandler->SetBoolResult("atmosphere_controller_enabled_setpoint_reached", true);
			}
			else
			{
				pSignalHandler->SetBoolResult("atmosphere_controller_enabled_setpoint_reached", false);
			}

			pSignalHandler->SignalHandled();
		}
	}
	else if (pStateEnvironment->WaitForSignal("signal_check_gas_flow", 0, pSignalHandler)) {

		pStateEnvironment->SetNextState("idle");

		if (bIsSimulation) {

			pStateEnvironment->LogMessage("SIMULATE gas flow check");
			pStateEnvironment->Sleep(1000);

			pSignalHandler->SetBoolResult("circulation_pump_started_setpoint_reached", true);
			pSignalHandler->SignalHandled();
		}
		else {
			pBuRDriver->QueryParameters();

			// Get actual oxygen value in the chamber
			int nO2ChamberInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_chamber_ppm");
			// Get desired oxygen value to start the process
			int nO2SetpointInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "oxygencontrol_PID_setvalue");
			// Get the tolerance from the signal
			int nToleranceInPPM = pSignalHandler->GetInteger("atmosphere_controller_tolerance_ppm");
			// Check if circulation pump is running
			bool bIsOnCirculationPump = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input02");

			if ((nO2ChamberInPPM > nO2SetpointInPPM - nToleranceInPPM) && (nO2ChamberInPPM < nO2SetpointInPPM + nToleranceInPPM) && bIsOnCirculationPump)
			{
				pSignalHandler->SetBoolResult("circulation_pump_started_setpoint_reached", true);
			}
			else
			{
				pSignalHandler->SetBoolResult("circulation_pump_started_setpoint_reached", false);
			}

			pSignalHandler->SignalHandled();
		}
	}
	else {
		pStateEnvironment->SetNextState("idle");
	}
	
}

__DECLARESTATE(waitforreferencing)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	pStateEnvironment->SetNextState("waitforreferencing");

	auto pSignalHandlerInitAxes = pStateEnvironment->RetrieveSignal("signal_initaxes");
	LibMCEnv::PSignalHandler pSignalHandlerLeaveWaitforreferencing;

	bool bRecoaterAxisLinearReady = (pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_isreferenced"));
	bool bRecoaterAxisPowderReady = (pStateEnvironment->GetBoolParameter("plcstate", "axRecoaterPowderBelt_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axRecoaterPowderBelt_isreferenced"));
	bool bPowderReservoirAxisReady = (pStateEnvironment->GetBoolParameter("plcstate", "axPowderReservoir_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axPowderReservoir_isreferenced"));
	bool bPlatformAxisReady = (pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_ispowered") && pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_isreferenced"));
	
	if (bPlatformAxisReady && bPowderReservoirAxisReady && bRecoaterAxisPowderReady && bRecoaterAxisLinearReady)
	{
		pSignalHandlerInitAxes->SetBoolResult("platformaxis_initialized", bPlatformAxisReady);
		pSignalHandlerInitAxes->SetBoolResult("powderreservoiraxis_initialized", bPowderReservoirAxisReady);
		pSignalHandlerInitAxes->SetBoolResult("recoateraxis_powder_initialized", bRecoaterAxisPowderReady);
		pSignalHandlerInitAxes->SetBoolResult("recoateraxis_linear_initialized", bRecoaterAxisLinearReady);
		pSignalHandlerInitAxes->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}

	if (pStateEnvironment->WaitForSignal("signal_leavewaitforreferencing", 0, pSignalHandlerLeaveWaitforreferencing))
	{
		pSignalHandlerInitAxes->SetBoolResult("platformaxis_initialized", bPlatformAxisReady);
		pSignalHandlerInitAxes->SetBoolResult("powderreservoiraxis_initialized", bPowderReservoirAxisReady);
		pSignalHandlerInitAxes->SetBoolResult("recoateraxis_powder_initialized", bRecoaterAxisPowderReady);
		pSignalHandlerInitAxes->SetBoolResult("recoateraxis_linear_initialized", bRecoaterAxisLinearReady);
		pSignalHandlerInitAxes->SignalHandled();

		pSignalHandlerLeaveWaitforreferencing->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
}

__DECLARESTATE(moveplatformclear)
{
	pStateEnvironment->LogMessage("Moving platform to a save position ...");
	// Retrieve the recoat layer signal and the relevant parameters
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dPlatformAxisClearanceInMM = pSignalHandler->GetDouble("platformaxis_clearance");
	double dPlatformAxisSpeedInMMPerSecond = pSignalHandler->GetDouble("platformaxis_speed");
	double dPlatformAxisAccelerationInMMPerSecondSqaured = pSignalHandler->GetDouble("platformaxis_acceleration");

	// aquire the BuR driver
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_platform", pStateEnvironment->GetDoubleParameter("plcstate", "axBuildPlatform_actualposition"));

	//create a comand list with the recoating cycle
	auto pCommandList = pBuRDriver->CreateCommandList();

	// First command, drive the build plate to a save position to avoi collisions
	auto pPlatformAxisClearanceCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pPlatformAxisClearanceCommand->SetIntegerParameter("axis_ID", 1); // axis ID 1 = build platform
	pPlatformAxisClearanceCommand->SetIntegerParameter("absoluterelative", 2); // 2 = relative movement
	pPlatformAxisClearanceCommand->SetIntegerParameter("target", (int32_t)round(dPlatformAxisClearanceInMM * 1000.0 * -1.0));
	pPlatformAxisClearanceCommand->SetIntegerParameter("speed", (int32_t)round(dPlatformAxisSpeedInMMPerSecond * 1000.0));
	pPlatformAxisClearanceCommand->SetIntegerParameter("acceleration", (int32_t)round(dPlatformAxisAccelerationInMMPerSecondSqaured * 1000.0));
	pCommandList->AddCommand(pPlatformAxisClearanceCommand);
	pCommandList->FinishList();
	pCommandList->ExecuteList();
	pStateEnvironment->SetNextState("waitforclearplatform");
	pStateEnvironment->LogMessage("Waiting for platform to be clear ...");
}

__DECLARESTATE(waitforclearplatform)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	pStateEnvironment->SetNextState("waitforclearplatform");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dPlatformAxisClearanceInMM = pSignalHandler->GetDouble("platformaxis_clearance");
	double dTargetPosition = std::round((pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_platform") - dPlatformAxisClearanceInMM) * 1000.0) / 1000.0;
	double dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axBuildPlatform_actualposition")*1000.0)/1000.0;
	// wait for the platform to be inposition
	if (pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_isinposition") && dActualPosition == dTargetPosition)
	{
		pStateEnvironment->SetNextState("recoatertostartposition");
		pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_platform", dTargetPosition);
	}

}

__DECLARESTATE(recoatertostartposition)
{
	pStateEnvironment->LogMessage("Moving recoater to the recoat start position ...");
	// Retrieve the recoat layer signal and the relevant parameters
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dRecoaterLinearAxisSpeedInMMPerSecond = pSignalHandler->GetDouble("recoater_linear_speed_travel");
	double dRecoaterAxesLinearAccelerationInMMPerSecondSqaured = pSignalHandler->GetDouble("recoater_axes_linear_acceleration_travel");
	double dRecoatingStartPositionInMM = pSignalHandler->GetDouble("recoating_start_position");

	// aquire the BuR driver
	auto pBuRDriver = __acquireDriver(BuR);
	pStateEnvironment->LogMessage("create a comand list with the recoating cycle ...");
	//create a comand list with the recoating cycle
	auto pCommandList = pBuRDriver->CreateCommandList();

	// Second command, drive the linear recoater axis to the recoating start position
	auto pRecoatingStartPositionCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pRecoatingStartPositionCommand->SetIntegerParameter("axis_ID", 4); // axis ID 4 = recoater linear axis
	pRecoatingStartPositionCommand->SetIntegerParameter("absoluterelative", 1); // 1 = absolute movement
	pRecoatingStartPositionCommand->SetIntegerParameter("target", (int32_t)round(dRecoatingStartPositionInMM * 1000.0));
	pRecoatingStartPositionCommand->SetIntegerParameter("speed", (int32_t)round(dRecoaterLinearAxisSpeedInMMPerSecond * 1000.0));
	pRecoatingStartPositionCommand->SetIntegerParameter("acceleration", (int32_t)round(dRecoaterAxesLinearAccelerationInMMPerSecondSqaured * 1000.0));
	pCommandList->AddCommand(pRecoatingStartPositionCommand);
	pCommandList->FinishList();
	pCommandList->ExecuteList();
	pStateEnvironment->SetNextState("waitforrecoaterinstartposition");
	pStateEnvironment->LogMessage("Waiting for the recaoter to reach the start position ...");
}

__DECLARESTATE(waitforrecoaterinstartposition)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	pStateEnvironment->SetNextState("waitforrecoaterinstartposition");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dRecoatingStartPositionInMM = pSignalHandler->GetDouble("recoating_start_position");
	double dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoater_actualposition") * 1000.0) / 1000.0;
	double dTargetPosition = dRecoatingStartPositionInMM;
	//wait for the recoater to be inposition
	if (pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_isinposition") && dActualPosition == dTargetPosition)
	{
		pStateEnvironment->SetNextState("platformtolayer");
	}

}

__DECLARESTATE(platformtolayer)
{
	pStateEnvironment->LogMessage("Moving the platfrom to reach the current layer height ...");
	// Retrieve the recoat layer signal and the relevant parameters
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dPlatformAxisClearanceInMM = pSignalHandler->GetDouble("platformaxis_clearance");
	double dPlatformAxisSpeedInMMPerSecond = pSignalHandler->GetDouble("platformaxis_speed");
	double dPlatformAxisAccelerationInMMPerSecondSqaured = pSignalHandler->GetDouble("platformaxis_acceleration");
	double dLayerHeightInMM = pSignalHandler->GetDouble("layer_height");

	// aquire the BuR driver
	auto pBuRDriver = __acquireDriver(BuR);
	//create a comand list with the recoating cycle
	auto pCommandList = pBuRDriver->CreateCommandList();

	// Third command, lift the build plate higher than the target heigth
	auto pPlatformAxisRaisedPositionCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pPlatformAxisRaisedPositionCommand->SetIntegerParameter("axis_ID", 1); // axis ID 1 = build platform
	pPlatformAxisRaisedPositionCommand->SetIntegerParameter("absoluterelative", 2); // 2 = relative movement
	pPlatformAxisRaisedPositionCommand->SetIntegerParameter("target", (int32_t)round((dPlatformAxisClearanceInMM - dLayerHeightInMM) * 1000.0));
	pPlatformAxisRaisedPositionCommand->SetIntegerParameter("speed", (int32_t)round(dPlatformAxisSpeedInMMPerSecond * 1000.0));
	pPlatformAxisRaisedPositionCommand->SetIntegerParameter("acceleration", (int32_t)round(dPlatformAxisAccelerationInMMPerSecondSqaured * 1000.0));
	pCommandList->AddCommand(pPlatformAxisRaisedPositionCommand);

	pCommandList->FinishList();
	pCommandList->ExecuteList();
	pStateEnvironment->SetNextState("waitforplatformtolayer");
	pStateEnvironment->LogMessage("Waiting for the platfrom to reach the current layer height ...");
}

__DECLARESTATE(waitforplatformtolayer)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	pStateEnvironment->SetNextState("waitforplatformtolayer");
	// wait for the platform to be inposition
	
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dPlatformAxisClearanceInMM = pSignalHandler->GetDouble("platformaxis_clearance");
	double dLayerHeight = pSignalHandler->GetDouble("layer_height");
	double dTargetPosition = std::round((pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_platform") + dPlatformAxisClearanceInMM - dLayerHeight) * 1000.0) / 1000.0;;
	double dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axBuildPlatform_actualposition") * 1000.0) / 1000.0;
	// wait for the platform to be inposition
	if (pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_isinposition") && dActualPosition == dTargetPosition)
	{
		pStateEnvironment->SetNextState("recoatlayer");
		pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_platform", dTargetPosition);
	}

}

__DECLARESTATE(recoatlayer)
{	
	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	pStateEnvironment->LogMessage("Recoating ...");
	// Retrieve the recoat layer signal and its parameters

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dRecoaterLinearAxisSpeedInMMPerSecond = pSignalHandler->GetDouble("recoater_linear_speed_recoating");
	double dRecoaterAxesLinearAccelerationInMMPerSecondSqaured = pSignalHandler->GetDouble("recoater_axes_linear_acceleration_recoating");
	double dRecoaterDosingFactor = pSignalHandler->GetDouble("recoater_axes_dosing_factor");
	double dRecoaterRefillPositionInMM = pSignalHandler->GetDouble("recoater_refill_position");
	double dRecoatingStartPositionInMM = pSignalHandler->GetDouble("recoating_start_position");

	double dRecoaterPowderbeltAxisSpeedInMMPerSecond = dRecoaterLinearAxisSpeedInMMPerSecond * dRecoaterDosingFactor;
	double dRecoaterAxesPowderAccelerationInMMPerSecondSqaured = dRecoaterAxesLinearAccelerationInMMPerSecondSqaured * dRecoaterDosingFactor;

	// aquire the BuR driver
	auto pBuRDriver = __acquireDriver(BuR);
	//create a comand list with the recoating cycle
	auto pCommandList = pBuRDriver->CreateCommandList();

	// Fifth command, recoat the powder layer
	auto pRecoatingCommand = pBuRDriver->CreateCommand("recoaterdualaxismovement");
	pRecoatingCommand->SetIntegerParameter("recoateraxis_linear_start_position", (int32_t)round(dRecoatingStartPositionInMM * 1000.0));
	pRecoatingCommand->SetIntegerParameter("recoateraxis_linear_target_position", (int32_t)round(dRecoaterRefillPositionInMM * 1000.0));
	pRecoatingCommand->SetIntegerParameter("recoateraxis_linear_speed", (int32_t)round(dRecoaterLinearAxisSpeedInMMPerSecond * 1000.0));
	pRecoatingCommand->SetIntegerParameter("recoateraxis_powder_speed", (int32_t)round(dRecoaterPowderbeltAxisSpeedInMMPerSecond * 1000.0));
	pRecoatingCommand->SetIntegerParameter("recoater_axes_linear_acceleration", (int32_t)round(dRecoaterAxesLinearAccelerationInMMPerSecondSqaured * 1000.0));
	pRecoatingCommand->SetIntegerParameter("recoater_axes_powder_acceleration", (int32_t)round(dRecoaterAxesPowderAccelerationInMMPerSecondSqaured * 1000.0));
	pCommandList->AddCommand(pRecoatingCommand);

	// Finish command list and send it to the PLC

	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pStateEnvironment->SetNextState("waitforrecoatlayer");
	}
	else
	{	
		pStateEnvironment->LogMessage("Timeout while recoating!");
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
	
	/*
	bool bReady = false;
	for (uint32_t nIndex = 0; nIndex < 1000; nIndex++) {
		pDriver->QueryParameters();

		if (pCommandList->WaitForList(300, 100)) {
			bReady = true;
			break;
		}
	}


	if (bReady) {
		pStateEnvironment->LogMessage("Recoating finished");

		pSignalHandler->SetBoolResult("success", true);
		pSignalHandler->SignalHandled();
	}
	else {
		pStateEnvironment->LogMessage("Timeout while recoating!");

		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();

	}*/

	

}

__DECLARESTATE(waitforrecoatlayer)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	pStateEnvironment->SetNextState("waitforrecoatlayer");
	//wait for the recoater to be inposition
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_recoatlayer");
	double dRecoaterRefillPositionInMM = pSignalHandler->GetDouble("recoater_refill_position");
	double dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoater_actualposition") * 1000.0) / 1000.0;
	double dTargetPosition = dRecoaterRefillPositionInMM;
	if (pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_isinposition") && dActualPosition == dTargetPosition)
	{
		pStateEnvironment->LogMessage("Recoating finished");
		pSignalHandler->SetBoolResult("success", true);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}

}

__DECLARESTATE(moverecoaterpowderbelt)
{
	auto pBuRDriver = __acquireDriver(BuR);

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pCommandList = pBuRDriver->CreateCommandList();

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_singleaxismovement");
	auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");
	auto dTargetInMM = pSignalHandler->GetDouble("target");
	auto dSpeedInMMPerSecond = pSignalHandler->GetDouble("speed");
	auto dAccelerationInMMPerSecondSquared = pSignalHandler->GetDouble("acceleration");

	// chache the position prior to the movement
	auto dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoaterPowderBelt_actualposition") * 1000.0) / 1000.0;
	pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_recoateraxis_powder", dActualPosition);

	auto pSingleAxisMovementCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pSingleAxisMovementCommand->SetIntegerParameter("axis_ID", AXISID_RECOATERPOWDERBELT);
	pSingleAxisMovementCommand->SetIntegerParameter("absoluterelative", nAbsoluteRelative);
	pSingleAxisMovementCommand->SetIntegerParameter("target", (int32_t)round(dTargetInMM * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("speed", (int32_t)round(dSpeedInMMPerSecond * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("acceleration", (int32_t)round(dAccelerationInMMPerSecondSquared * 1000.0));
	pCommandList->AddCommand(pSingleAxisMovementCommand);

	pStateEnvironment->LogMessage("Trigger single axis movement");
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pStateEnvironment->SetNextState("waitforaxismovement");
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("connectionlost");
	}

}

__DECLARESTATE(moverecoaterlinear)
{
	auto pBuRDriver = __acquireDriver(BuR);

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pCommandList = pBuRDriver->CreateCommandList();

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_singleaxismovement");
	auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");
	auto dTargetInMM = pSignalHandler->GetDouble("target");
	auto dSpeedInMMPerSecond = pSignalHandler->GetDouble("speed");
	auto dAccelerationInMMPerSecondSquared = pSignalHandler->GetDouble("acceleration");

	// chache the position prior to the movement
	auto dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoater_actualposition") * 1000.0) / 1000.0;
	pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_recoateraxis_linear", dActualPosition);

	auto pSingleAxisMovementCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pSingleAxisMovementCommand->SetIntegerParameter("axis_ID", AXISID_RECOATELINEAR);
	pSingleAxisMovementCommand->SetIntegerParameter("absoluterelative", nAbsoluteRelative);
	pSingleAxisMovementCommand->SetIntegerParameter("target", (int32_t)round(dTargetInMM * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("speed", (int32_t)round(dSpeedInMMPerSecond * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("acceleration", (int32_t)round(dAccelerationInMMPerSecondSquared * 1000.0));
	pCommandList->AddCommand(pSingleAxisMovementCommand);

	pStateEnvironment->LogMessage("Trigger single axis movement");
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pStateEnvironment->SetNextState("waitforaxismovement");
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("connectionlost");
	}

}

__DECLARESTATE(movepowderreservoir)
{
	auto pBuRDriver = __acquireDriver(BuR);

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pCommandList = pBuRDriver->CreateCommandList();

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_singleaxismovement");
	auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");
	auto dTargetInDegree = pSignalHandler->GetDouble("target");
	auto dSpeedInDegreePerSecond = pSignalHandler->GetDouble("speed");
	auto dAccelerationInDegreePerSecondSquared = pSignalHandler->GetDouble("acceleration");

	// chache the position prior to the movement
	auto dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axPowderReservoir_actualposition") * 1000.0) / 1000.0;
	pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_powderreservoir", dActualPosition);

	auto pSingleAxisMovementCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pSingleAxisMovementCommand->SetIntegerParameter("axis_ID", AXISID_POWDERRESERVOIR);
	pSingleAxisMovementCommand->SetIntegerParameter("absoluterelative", nAbsoluteRelative);
	pSingleAxisMovementCommand->SetIntegerParameter("target", (int32_t)round(dTargetInDegree * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("speed", (int32_t)round(dSpeedInDegreePerSecond * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("acceleration", (int32_t)round(dAccelerationInDegreePerSecondSquared * 1000.0));
	pCommandList->AddCommand(pSingleAxisMovementCommand);

	pStateEnvironment->LogMessage("Trigger single axis movement");
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pStateEnvironment->SetNextState("waitforaxismovement");
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("connectionlost");
	}

}


__DECLARESTATE(moveplatform)
{
	auto pBuRDriver = __acquireDriver(BuR);

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pCommandList = pBuRDriver->CreateCommandList();

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_singleaxismovement");
	auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");
	auto dTargetInMM = pSignalHandler->GetDouble("target");
	auto dSpeedInMMPerSecond = pSignalHandler->GetDouble("speed");
	auto dAccelerationInMMPerSecondSquared = pSignalHandler->GetDouble("acceleration");

	// chache the position prior to the movement
	auto dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axBuildPlatform_actualposition") * 1000.0) / 1000.0;
	pStateEnvironment->SetDoubleParameter("cacheplcstate", "cache_position_platform", dActualPosition);

	auto pSingleAxisMovementCommand = pBuRDriver->CreateCommand("triggersingleaxismovement");
	pSingleAxisMovementCommand->SetIntegerParameter("axis_ID", AXISID_BUILDPLATFORM);
	pSingleAxisMovementCommand->SetIntegerParameter("absoluterelative", nAbsoluteRelative);
	pSingleAxisMovementCommand->SetIntegerParameter("target", (int32_t)round(dTargetInMM * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("speed", (int32_t)round(dSpeedInMMPerSecond * 1000.0));
	pSingleAxisMovementCommand->SetIntegerParameter("acceleration", (int32_t)round(dAccelerationInMMPerSecondSquared * 1000.0));
	pCommandList->AddCommand(pSingleAxisMovementCommand);

	pStateEnvironment->LogMessage("Trigger single axis movement");
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pStateEnvironment->SetNextState("waitforaxismovement");
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("connectionlost");
	}
}

__DECLARESTATE(waitforaxismovement)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_singleaxismovement");
	auto nAxisID = pSignalHandler->GetInteger("axis_ID");
	auto dTarget = pSignalHandler->GetDouble("target");
	auto nAbsoluteRelative = pSignalHandler->GetInteger("absoluterelative");

	// Check if the actual position equals the target position
	double dActualPosition = 0.0;
	double dCachePosition = 0.0;
	bool bIsInPosition = false;

	if (nAxisID == AXISID_BUILDPLATFORM) {
		dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axBuildPlatform_actualposition") * 1000.0) / 1000.0;
		dCachePosition = pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_platform");
		bIsInPosition = pStateEnvironment->GetBoolParameter("plcstate", "axBuildPlatform_isinposition");
	}
	else if (nAxisID == AXISID_POWDERRESERVOIR) {
		dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axPowderReservoir_actualposition") * 1000.0) / 1000.0;
		dCachePosition = pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_powderreservoir");
		bIsInPosition = pStateEnvironment->GetBoolParameter("plcstate", "axPowderReservoir_isinposition");
	}
	else if (nAxisID == AXISID_RECOATERPOWDERBELT) {
		dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoaterPowderBelt_actualposition") * 1000.0) / 1000.0;
		dCachePosition = pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_recoateraxis_powder");
		bIsInPosition = pStateEnvironment->GetBoolParameter("plcstate", "axRecoaterPowderBelt_isinposition");
	}
	else if (nAxisID == AXISID_RECOATELINEAR) {
		dActualPosition = std::round(pStateEnvironment->GetDoubleParameter("plcstate", "axRecoater_actualposition") * 1000.0) / 1000.0;
		dCachePosition = pStateEnvironment->GetDoubleParameter("cacheplcstate", "cache_position_recoateraxis_linear");
		bIsInPosition = pStateEnvironment->GetBoolParameter("plcstate", "axRecoater_isinposition");
	}

	// in case of a relative movement, correct the target position by the cached position
	if (nAbsoluteRelative == RELATIVE_FLAG) {
		dTarget = dTarget + dCachePosition;
	}
	// check if the target position was reached
	if (bIsInPosition && dActualPosition == dTarget)
	{
		pSignalHandler->SetBoolResult("success", true);
		pSignalHandler->SignalHandled();
		pStateEnvironment->SetNextState("idle");
		return;
	}
	pStateEnvironment->SetNextState("waitforaxismovement");
}

__DECLARESTATE(connectionlost)
{

	pStateEnvironment->SetNextState("idle");

}

__DECLARESTATE(connectionerror)
{

	pStateEnvironment->SetNextState("idle");

}

__DECLARESTATE(emergencyofferror)
{

	pStateEnvironment->SetNextState("idle");

}

__DECLARESTATE(shieldinggasflooding)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();
	
	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_enablecontroller");
	auto pCommandList = pBuRDriver->CreateCommandList();

	pStateEnvironment->LogMessage("Turn on shielding gas controller...");

	auto pEnableOxygenControllerCommand = pBuRDriver->CreateCommand("enablecontroller");
	pEnableOxygenControllerCommand->SetIntegerParameter("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
	pCommandList->AddCommand(pEnableOxygenControllerCommand);
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pBuRDriver->QueryParameters();

		bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "oxygencontrol_PID_isenabled");

		if (bControllerIsEnabled == true)
		{
			pStateEnvironment->LogMessage("The shielding gas controller was enabled....");
			pStateEnvironment->SetNextState("waitforoxygen");
		}
		else
		{
			pStateEnvironment->LogMessage("The shielding gas controller was not enabled....");
			pStateEnvironment->SetNextState("idle");
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SignalHandled();
		}
}
	else
	{
		pStateEnvironment->LogMessage("PLC has not responded....");
		pStateEnvironment->SetNextState("idle");
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
	}
}

__DECLARESTATE(waitforoxygen)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	// Get actual oxygen value in the filter
	int nO2FilterInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_filter_ppm");

	// Get desired oxygen value to turn on the circulation pump
	int nO2ThresholdCirculationOnInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_threshold_circulation_on_in_ppm");

	auto pSignalHandlerEnableController = pStateEnvironment->RetrieveSignal("signal_enablecontroller");
	LibMCEnv::PSignalHandler pSignalHandlerDisableController;

	if (nO2FilterInPPM < nO2ThresholdCirculationOnInPPM)
	{
		pStateEnvironment->SetNextState("idle");
		pSignalHandlerEnableController->SetBoolResult("success", true);
		pSignalHandlerEnableController->SignalHandled();
	}
	else {
		pStateEnvironment->SetNextState("waitforoxygen");
	}

	if (pStateEnvironment->WaitForSignal("signal_disablecontroller", 0, pSignalHandlerDisableController))
	{
		pSignalHandlerEnableController->SetBoolResult("success", false);
		pSignalHandlerEnableController->SignalHandled();

		pStateEnvironment->LogMessage("Disabling the shielding gas controller....");
		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pDisableControllerCommand = pBuRDriver->CreateCommand("disablecontroller");
		pDisableControllerCommand->SetIntegerParameter("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pPLCCommandList->AddCommand(pDisableControllerCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nGeneralCommandTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "oxygencontrol_PID_isenabled");

			if (bControllerIsEnabled == false)
			{
				pSignalHandlerDisableController->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandlerDisableController->SetBoolResult("success", false);
			}
		}
		else
		{
			pSignalHandlerDisableController->SetBoolResult("success", false);
		}
		pSignalHandlerDisableController->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}

}

__DECLARESTATE(startgasflow)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nStartStopPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "startstoppumptimeout");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_atmospherecontrol_start_gas_flow");

	pStateEnvironment->LogMessage("Starting gas flow for atmosphere control....");
	auto pPLCCommandList = pBuRDriver->CreateCommandList();
	auto pAtmosphereControlStartGasFlowCommand = pBuRDriver->CreateCommand("startgasflow");
	pAtmosphereControlStartGasFlowCommand->SetIntegerParameter("setpoint_in_percent", pSignalHandler->GetInteger("setpoint_in_percent"));
	pPLCCommandList->AddCommand(pAtmosphereControlStartGasFlowCommand);
	pPLCCommandList->FinishList();
	pPLCCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nStartStopPumpTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pBuRDriver->QueryParameters();
		// Check if circulation pump was started
		bool bIsOnCirculationPump = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input02");

		if (bIsOnCirculationPump == true)
		{
			pStateEnvironment->LogMessage("The circulation pump was started....");
			pStateEnvironment->SetNextState("waitforgasflow");
		}
		else
		{
			pStateEnvironment->LogMessage("The circulation pump was not started....");
			pStateEnvironment->SetNextState("idle");
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SignalHandled();
		}
	}
	else
	{
		pStateEnvironment->LogMessage("PLC has not responded....");
		pStateEnvironment->SetNextState("idle");
		pSignalHandler->SetBoolResult("success", false);
		pSignalHandler->SignalHandled();
	}
}

__DECLARESTATE(waitforgasflow)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nStartStopPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "startstoppumptimeout");

	// Get actual oxygen value in the chamber
	int nO2ChamberInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "o2_chamber_ppm");

	// Get desired oxygen value to start the process
	int nO2SetpointInPPM = pStateEnvironment->GetIntegerParameter("plcstate", "oxygencontrol_PID_setvalue");

	auto pSignalHandlerStartPump = pStateEnvironment->RetrieveSignal("signal_atmospherecontrol_start_gas_flow");
	LibMCEnv::PSignalHandler pSignalHandlerTurnOffPump;

	if (nO2ChamberInPPM < nO2SetpointInPPM)
	{
		pStateEnvironment->SetNextState("idle");
		pSignalHandlerStartPump->SetBoolResult("success", true);
		pSignalHandlerStartPump->SignalHandled();
	}
	else if (pStateEnvironment->WaitForSignal("signal_atmospherecontrol_turn_off_gas_flow", 0, pSignalHandlerTurnOffPump))
	{
		pSignalHandlerStartPump->SetBoolResult("success", false);
		pSignalHandlerStartPump->SignalHandled();

		auto pPLCCommandList = pBuRDriver->CreateCommandList();

		pStateEnvironment->LogMessage("Turning off the circulation pump....");
		auto pTurnOffPumpCommand = pBuRDriver->CreateCommand("turnoffgasflow");
		pPLCCommandList->AddCommand(pTurnOffPumpCommand);
		
		pStateEnvironment->LogMessage("Disabling the oxygen controller....");
		auto pDisableControllerCommand = pBuRDriver->CreateCommand("disablecontroller");
		pDisableControllerCommand->SetIntegerParameter("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
		pPLCCommandList->AddCommand(pDisableControllerCommand);

		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nStartStopPumpTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bCirculationPumpIsTurnedOn = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input02");
			bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "oxygencontrol_PID_isenabled");

			if ((bCirculationPumpIsTurnedOn == false) && (bControllerIsEnabled == false))
			{
				pSignalHandlerTurnOffPump->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandlerTurnOffPump->SetBoolResult("success", false);
			}
		}
		else
		{
			pSignalHandlerTurnOffPump->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("connectionlost");
		}
		pSignalHandlerTurnOffPump->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
	else {
		pStateEnvironment->SetNextState("waitforgasflow");
	}
}

__DECLARESTATE(updatebuildplatetemperature)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	auto pCommandList = pBuRDriver->CreateCommandList();

	pStateEnvironment->LogMessage("Turn on heater controller");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_enablecontroller");

	auto pEnableHeaterCommand = pBuRDriver->CreateCommand("enablecontroller");
	pEnableHeaterCommand->SetIntegerParameter("controller_ID", CONTROLLER_ID_HEATER);
	pCommandList->AddCommand(pEnableHeaterCommand);
	pCommandList->FinishList();
	pCommandList->ExecuteList();

	//TODO: delete sleep and repair PLC responce
	pStateEnvironment->Sleep(nGeneralCommandTimeout);
	if (true)//pCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
	{
		pBuRDriver->QueryParameters();

		bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "heater_PID_isenabled");

		if (bControllerIsEnabled == true)
		{
			pStateEnvironment->LogMessage("The heater controller was enabled....");
			pStateEnvironment->SetNextState("waitforbuildplatetemperature");
			pSignalHandler->SetBoolResult("success", true);
		}
		else
		{
			pSignalHandler->SetBoolResult("success", false);
			pStateEnvironment->SetNextState("idle");
			pSignalHandler->SignalHandled();
		}
	}
	else
	{
		pSignalHandler->SetBoolResult("success", false);
		pStateEnvironment->SetNextState("idle");
		pSignalHandler->SignalHandled();
	}
}

__DECLARESTATE(waitforbuildplatetemperature)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nGeneralCommandTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "generalplctimeout");

	// Get actual temperature of the build plate heater
	int nBuildPlateTemperatureInDegreeCelsius = (int) (20 * pStateEnvironment->GetDoubleParameter("plcstate", "112kf15_voltage02"));

	// Get desired temperature of the build plate heater
	int nHeaterSetpointInDegreeCelsius = pStateEnvironment->GetIntegerParameter("plcstate", "heater_PID_setvalue");

	auto pSignalHandlerEnableController = pStateEnvironment->RetrieveSignal("signal_enablecontroller");
	LibMCEnv::PSignalHandler pSignalHandlerDisableController;

	if (nBuildPlateTemperatureInDegreeCelsius > nHeaterSetpointInDegreeCelsius)
	{
		pStateEnvironment->SetNextState("idle");
		pSignalHandlerEnableController->SetBoolResult("success", true);
		pSignalHandlerEnableController->SignalHandled();
	}
	else
	{
		pStateEnvironment->SetNextState("waitforbuildplatetemperature");
	}

	if (pStateEnvironment->WaitForSignal("signal_disablecontroller", 0, pSignalHandlerDisableController))
	{
		pSignalHandlerEnableController->SetBoolResult("success", false);
		pSignalHandlerEnableController->SignalHandled();

		pStateEnvironment->LogMessage("Disabling the heater controller....");
		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pDisableControllerCommand = pBuRDriver->CreateCommand("disablecontroller");
		pDisableControllerCommand->SetIntegerParameter("controller_ID", CONTROLLER_ID_HEATER);
		pPLCCommandList->AddCommand(pDisableControllerCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nGeneralCommandTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bControllerIsEnabled = pStateEnvironment->GetBoolParameter("plcstate", "heater_PID_isenabled");

			if (bControllerIsEnabled == false)
			{
				pSignalHandlerDisableController->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandlerDisableController->SetBoolResult("success", false);
			}
		}
		else
		{
			pSignalHandlerDisableController->SetBoolResult("success", false);
		}
		pSignalHandlerDisableController->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
}

__DECLARESTATE(evacuatebuildchamber)
{

	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nStartStopPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "startstoppumptimeout");

	auto pSignalHandler = pStateEnvironment->RetrieveSignal("signal_vacuumcontrol_start_vacuum_pump");

	// Get absolute pressure
	int nPressure = pStateEnvironment->GetIntegerParameter("plcstate", "pressure_in_mbar");

	// Get desired absolute pressure
	int nPressureThreshold = pSignalHandler->GetInteger("pressure_threshold_vacuum_off_in_mbar");

	if (nPressure >= nPressureThreshold) //Check if turning on the vacuum pump is necessary
	{
		pStateEnvironment->LogMessage("Starting the vacuum pump....");

		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pVacuumControlStartPumpCommand = pBuRDriver->CreateCommand("startvacuumpump");
		pPLCCommandList->AddCommand(pVacuumControlStartPumpCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nStartStopPumpTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout,nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			// Check if vacuum pump is switched on
			bool bIsOnVacuumPump = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input04");

			if (bIsOnVacuumPump == true)
			{
				pStateEnvironment->SetNextState("waitforvaccuum");
			}
			else
			{
				pStateEnvironment->LogMessage("The vacuum pump was not started....");
				pStateEnvironment->SetNextState("idle");
				pSignalHandler->SetBoolResult("success", false);
				pSignalHandler->SignalHandled();
			}
		}
		else
		{
			pStateEnvironment->LogMessage("PLC has not responded....");
			pStateEnvironment->SetNextState("idle");
			pSignalHandler->SetBoolResult("success", false);
			pSignalHandler->SignalHandled();
		}
	}
	else
	{
		pStateEnvironment->LogMessage("The desired pressure is already reached....");
		pStateEnvironment->SetNextState("idle");
		pSignalHandler->SetBoolResult("success", true);
		pSignalHandler->SignalHandled();
	}
}

__DECLARESTATE(waitforvaccuum)
{
	auto pBuRDriver = __acquireDriver(BuR);
	pBuRDriver->QueryParameters();

	// Get Timeouts
	uint32_t nStartStopPumpTimeout = pStateEnvironment->GetIntegerParameter("timeouts", "startstoppumptimeout");

	auto pSignalHandlerStartPump = pStateEnvironment->RetrieveSignal("signal_vacuumcontrol_start_vacuum_pump");
	LibMCEnv::PSignalHandler pSignalHandlerStopPump;

	// Get absolute pressure
	int nPressure = pStateEnvironment->GetIntegerParameter("plcstate", "pressure_in_mbar");

	// Get desired absolute pressure
	int nPressureThreshold = pSignalHandlerStartPump->GetInteger("pressure_threshold_vacuum_off_in_mbar");

	if (nPressure < nPressureThreshold)
	{
		pStateEnvironment->SetNextState("idle");
		pSignalHandlerStartPump->SetBoolResult("success", true);
		pSignalHandlerStartPump->SignalHandled();
	}
	else {
		pStateEnvironment->SetNextState("waitforvaccuum"); 
	}
		
	if (pStateEnvironment->WaitForSignal("signal_vacuumcontrol_turn_off_vacuum_pump", 0, pSignalHandlerStopPump))
	{
		pSignalHandlerStartPump->SetBoolResult("success", false);
		pSignalHandlerStartPump->SignalHandled();
		
		pStateEnvironment->LogMessage("Turning off the vacuum pump....");
		auto pPLCCommandList = pBuRDriver->CreateCommandList();
		auto pVacuumControlTurnOffPumpCommand = pBuRDriver->CreateCommand("turnoffvacuumpump");
		pPLCCommandList->AddCommand(pVacuumControlTurnOffPumpCommand);
		pPLCCommandList->FinishList();
		pPLCCommandList->ExecuteList();

		//TODO: delete sleep and repair PLC responce
		pStateEnvironment->Sleep(nStartStopPumpTimeout);
		if (true)//pPLCCommandList->WaitForList(nResponseTimeout, nGeneralCommandTimeout))
		{
			pBuRDriver->QueryParameters();

			bool bVacuumPumpIsTurnedOn = pStateEnvironment->GetBoolParameter("plcstate", "113kf18_input04");
			if (bVacuumPumpIsTurnedOn == false)
			{
				pSignalHandlerStopPump->SetBoolResult("success", true);
			}
			else
			{
				pSignalHandlerStopPump->SetBoolResult("success", false);
			}
		}
		else
		{
			pSignalHandlerStopPump->SetBoolResult("success", false);
		}
		pSignalHandlerStopPump->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
}

__DECLARESTATE(fatalerror) 
{
	pStateEnvironment->SetNextState("fatalerror");
}



__ENDSTATEDEFINITIONS