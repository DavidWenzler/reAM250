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

//include required hardware modules
#include "Modules/IOModule_X20DI6371.hpp"
#include "Modules/IOModule_X20DO6322.hpp"
#include "Modules/IOModule_X20AO4622.hpp"
#include "Modules/IOModule_X20AI4622.hpp"




namespace BuRCPP {
	class CStateGasCirculation_Init : public CState {
		public:

		std::string getName () 
		{
			return "init";
		}
	
		void Execute (CEnvironment * pEnvironment) 
		{
			// access io modules
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_1(pEnvironment, "114KF28"); // enable pump
			ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_2(pEnvironment, "114KF25"); // set valves
			ioModuleAccess<CIOModule_X20AO4622> pAnalogOutputModule(pEnvironment, "112KF12"); // setpoint pump
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pump ventilation error
			ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
			
			pDigitalOutputModule_1->setOutput(1, false); // disable pump
			pAnalogOutputModule->setOutputVoltageInVolt (1, 0.0); // set setpoint to 0.0 V
			
			pDigitalOutputModule_2->setOutput(1, false); // close circulation valves
			pDigitalOutputModule_2->setOutput(2, false);
			
			// Signal from PC
			auto pSignalInitAtmosphereControl = pEnvironment->checkSignal ("initatmospherecontrol");
			
			if (pSignalInitAtmosphereControl)
			{
				int circulation_on_threshold = pSignalInitAtmosphereControl->getInt32Parameter("o2thresholdcirculationoninppm");
				int circulation_off_threshold = pSignalInitAtmosphereControl->getInt32Parameter("o2thresholdcirculationoffinppm");
				pEnvironment->setIntegerValue(JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_ON_IN_PPM, circulation_on_threshold);
				pEnvironment->setIntegerValue(JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_OFF_IN_PPM, circulation_off_threshold);
				pEnvironment->setNextState("idle");
				pSignalInitAtmosphereControl->finishProcessing ();
			}
			else 
			{
				pEnvironment->setNextState("init");
			}
			
			if (pDigitalInputModule_1->getInput(3)==1 || pDigitalInputModule_2->getInput(3)==0)
			{
				pEnvironment->setNextState("error");
			}
		}
	};
	
	
class CStateGasCirculation_error : public CState {
	public:

	std::string getName () 
	{
		return "error";
	}

	void Execute (CEnvironment * pEnvironment) 
	{
		// access io modules
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pump ventilation error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
				
		if (pDigitalInputModule_1->getInput(3)==1 || pDigitalInputModule_2->getInput(3)==0)
		{
			pEnvironment->setNextState("error");
		}
		else
		{
			pEnvironment->setNextState("init");
		}
	}
	
};
		
class CStateGasCirculation_idle : public CState {
	public:

	std::string getName () 
	{
		return "idle";
	}

	void Execute (CEnvironment * pEnvironment) 
	{
		// access io modules
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pump ventilation error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_3(pEnvironment, "113KF17");// get circulation valves status
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_4(pEnvironment, "113KF21");// get vacuum valves status
		ioModuleAccess<CIOModule_X20AO4622> pAnalogOutputModule(pEnvironment, "112KF12"); // setpoint pump
		ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule(pEnvironment, "114KF25"); // set valves
			
		// Signal from PC
		auto pSignalStartGasFlow = pEnvironment->checkSignal ("startgasflow");
		auto pSignalUpdateGasFlowSetpoint = pEnvironment->checkSignal ("updategasflowsetpoint");
		auto pSignalToggleValves = pEnvironment->checkSignal ("togglevalves");
			
		if (pSignalToggleValves) // toggle gas flow valves
		{
			bool toggle_heat_exchanger_gas_flow_circuit_valve = pSignalToggleValves->getBoolParameter("toggle_lower_gas_flow_circuit_valve");
			bool toggle_chamber_gas_flow_circuit_valve = pSignalToggleValves->getBoolParameter("toggle_upper_gas_flow_circuit_valve");
				
			pDigitalOutputModule->setOutput(1, toggle_chamber_gas_flow_circuit_valve);
			pDigitalOutputModule->setOutput(2, toggle_heat_exchanger_gas_flow_circuit_valve);
				
			pSignalToggleValves->finishProcessing ();
		}	
			
		if (pSignalUpdateGasFlowSetpoint)
		{
			int setpointinpercent = pSignalUpdateGasFlowSetpoint->getInt32Parameter("setpointinpercent");
			pEnvironment->setIntegerValue(JOURNALVARIABLE_PUMPSETPOINTINPERCENT, setpointinpercent); //set journalvariable for setpoint
			pSignalUpdateGasFlowSetpoint->finishProcessing ();
		}
				
		if (pSignalStartGasFlow && pDigitalInputModule_3->getInput(1)==1 && pDigitalInputModule_3->getInput(3)==1 && pDigitalInputModule_4->getInput(2)==1 && pDigitalInputModule_4->getInput(4)==1)
		{
			int setpointinpercent = pSignalStartGasFlow->getInt32Parameter("setpointinpercent");
			pEnvironment->setIntegerValue(JOURNALVARIABLE_PUMPSETPOINTINPERCENT, setpointinpercent); //set journalvariable for setpoint
			pEnvironment->setNextState("wait_for_oxygenlevel");
			pSignalStartGasFlow->finishProcessing ();
		}
		else
		{
			pEnvironment->setNextState("idle");
		}
			
		if (pDigitalInputModule_1->getInput(3)==1 || pDigitalInputModule_2->getInput(3)==0)
		{
			pEnvironment->setNextState("error");
		}
	}
	
};
	
class CStateGasCirculation_wait_for_oxygenlevel : public CState {
	public:

	std::string getName () 
	{
		return "wait_for_oxygenlevel";
	}

	void Execute (CEnvironment * pEnvironment) 
	{
		// access io modules
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19"); //pump ventilation error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18"); //pump error
		ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			
		// Signal from PC
		auto pSignalTurnOffGasFlow = pEnvironment->checkSignal ("turnoffgasflow");
		auto pSignalUpdateGasFlowSetpoint = pEnvironment->checkSignal ("updategasflowsetpoint");
				
		if (pSignalUpdateGasFlowSetpoint)
		{
			int setpointinpercent = pSignalUpdateGasFlowSetpoint->getInt32Parameter("setpointinpercent");
			pEnvironment->setIntegerValue(JOURNALVARIABLE_PUMPSETPOINTINPERCENT, setpointinpercent); //set journalvariable for setpoint
			pSignalUpdateGasFlowSetpoint->finishProcessing ();
		}
			
		double o2inpercent_filter = (pAnalogInputModule->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT;;
		auto circulation_on_o2thresholdinppm = pEnvironment->getInt32Value(JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_ON_IN_PPM);
			
		if (o2inpercent_filter*FACTOR_PERCENT_TO_PPM < circulation_on_o2thresholdinppm)
		{
			pEnvironment->setNextState("gas_flow_on");
		}
		else
		{
			pEnvironment->setNextState("wait_for_oxygenlevel");
		}
				
		if (pSignalTurnOffGasFlow)
		{		
			pEnvironment->setNextState("idle");
			pSignalTurnOffGasFlow->finishProcessing ();
		}
				
		if (pDigitalInputModule_1->getInput(3)==1 || pDigitalInputModule_2->getInput(3)==0)
		{	
			pEnvironment->setNextState("error");
		}
	}
		
};
			
class CStateGasCirculation_gas_flow_on : public CState {
	public:
	
	std::string getName () 
	{
		return "gas_flow_on";
	}
	
	void Execute (CEnvironment * pEnvironment) 
	{
		// access io modules
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_1(pEnvironment, "113KF19");// pump ventilation error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_2(pEnvironment, "113KF18");// pump error
		ioModuleAccess<CIOModule_X20DI6371> pDigitalInputModule_3(pEnvironment, "113KF17"); //feedback from circulation valves
		ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_1(pEnvironment, "114KF28"); // enable pump
		ioModuleAccess<CIOModule_X20DO6322> pDigitalOutputModule_2(pEnvironment, "114KF25"); //output vacuum valves	
		ioModuleAccess<CIOModule_X20AO4622> pAnalogOutputModule(pEnvironment, "112KF12"); // setpoint pump
		ioModuleAccess<CIOModule_X20AI4622>pAnalogInputModule(pEnvironment, "112KF14"); // oxygen content value module
			
		// Signal from PC
		auto pSignalTurnOffGasFlow = pEnvironment->checkSignal ("turnoffgasflow");
		auto pSignalUpdateGasFlowSetpoint = pEnvironment->checkSignal ("updategasflowsetpoint");
			
		if (pSignalUpdateGasFlowSetpoint)
		{
			int setpointinpercent = pSignalUpdateGasFlowSetpoint->getInt32Parameter("setpointinpercent");
			pEnvironment->setIntegerValue(JOURNALVARIABLE_PUMPSETPOINTINPERCENT, setpointinpercent); //set journalvariable for setpoint
			pSignalUpdateGasFlowSetpoint->finishProcessing ();
		}
						
		pDigitalOutputModule_1->setOutput(1, true); // enable pump
		auto setpointinpercent = pEnvironment->getInt32Value(JOURNALVARIABLE_PUMPSETPOINTINPERCENT);
		auto setpointinvolt = setpointinpercent/10;
		pAnalogOutputModule->setOutputVoltageInVolt (1, setpointinvolt); // set setpoint in V (0 - 10 V)
				
		double o2inpercent_filter = (pAnalogInputModule->getInputCurrentInAmpere(1)-0.004)*((O2SENSORFILTER_RANGE_UPPER_INPERCENT-O2SENSORFILTER_RANGE_LOWER_INPERCENT)/0.016)+O2SENSORFILTER_RANGE_LOWER_INPERCENT;;
		auto circulation_off_o2thresholdinppm = pEnvironment->getInt32Value(JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_OFF_IN_PPM);
		
		if (o2inpercent_filter*FACTOR_PERCENT_TO_PPM < circulation_off_o2thresholdinppm)
		{
			pEnvironment->setNextState("gas_flow_on");
		}
		else
		{
			pDigitalOutputModule_1->setOutput(1, false); // disable pump
			pAnalogOutputModule->setOutputVoltageInVolt (1, 0.0); // set setpoint to 0.0 V	
			pEnvironment->setNextState("wait_for_oxygenlevel");
		}
					
		if (pSignalTurnOffGasFlow)
		{
			pDigitalOutputModule_1->setOutput(1, false); // disable pump
			pAnalogOutputModule->setOutputVoltageInVolt (1, 0.0); // set setpoint to 0.0 V	
							
			pEnvironment->setNextState("idle");
			pSignalTurnOffGasFlow->finishProcessing ();
		}
					
		if (pDigitalInputModule_1->getInput(3)==1 || pDigitalInputModule_2->getInput(3)==0 || pDigitalInputModule_3->getInput(1)==0 || pDigitalInputModule_3->getInput(3)==0 || pDigitalOutputModule_2->getOutput(4)==1 || pDigitalOutputModule_2->getOutput(5)==1)
		{
			pDigitalOutputModule_1->setOutput(1, false); // disable pump
			pAnalogOutputModule->setOutputVoltageInVolt (1, 0.0); // set setpoint to 0.0 V
					
			pEnvironment->setNextState("error");
		}
	}
		
};		
	
class CStateHandlerGasCirculation : public CStateHandler {
	public:

	CStateHandlerGasCirculation (CApplication* pApplication)
		// retrieve the journal group variable for this template state machine
		: CStateHandler (pApplication->getJournal (), "gascirculation", pApplication->getModuleHandler (), JOURNALGROUP_GAS_CIRCULATION)
	{
		// register all states of this state machine here
		addState (std::make_shared<CStateGasCirculation_Init> ());
		addState (std::make_shared<CStateGasCirculation_idle> ());
		addState (std::make_shared<CStateGasCirculation_wait_for_oxygenlevel> ());
		addState (std::make_shared<CStateGasCirculation_gas_flow_on> ());
		addState (std::make_shared<CStateGasCirculation_error> ());
		
		//register signal
		auto pSignalInitAtmosphereControl = registerSignal ("initatmospherecontrol", 4, 1000);
		pSignalInitAtmosphereControl->addInt32Parameter ("o2thresholdcirculationoninppm", 0);
		pSignalInitAtmosphereControl->addInt32Parameter ("o2thresholdcirculationoffinppm", 0);
		pSignalInitAtmosphereControl->addBoolResult ("success", false);
			
		auto pSignalToggleValves = registerSignal ("togglevalves", 4, 1000);
		pSignalToggleValves->addBoolParameter ("toggle_lower_gas_flow_circuit_valve", false);
		pSignalToggleValves->addBoolParameter ("toggle_upper_gas_flow_circuit_valve", false);
		pSignalToggleValves->addBoolParameter ("toggle_shielding_gas_valve", false);
		pSignalToggleValves->addBoolParameter ("toggle_chamber_vacuum_valve", false);
		pSignalToggleValves->addBoolParameter ("toggle_zAxis_vacuum_valve", false);
		pSignalToggleValves->addBoolResult ("success", false);
			
		auto pSignalStartGasFlow = registerSignal ("startgasflow", 4, 1000);
		pSignalStartGasFlow->addInt32Parameter ("setpointinpercent", 0);
		pSignalStartGasFlow->addBoolResult ("success", false);
			
		auto pSignalUpdateGasFlowSetpoint = registerSignal ("updategasflowsetpoint", 4, 1000);
		pSignalUpdateGasFlowSetpoint->addInt32Parameter ("setpointinpercent", 0);
		pSignalUpdateGasFlowSetpoint->addBoolResult ("success", false);
			
		auto pSignalTurnOffGasFlow = registerSignal ("turnoffgasflow", 4, 1000);
		pSignalTurnOffGasFlow->addBoolResult ("success", false);	
				
		// register journal variables
		registerIntegerValue("pumpsetpointinpercent", JOURNALVARIABLE_PUMPSETPOINTINPERCENT, 0, 100);
		registerIntegerValue("o2thresholdcirculationoninppm", JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_ON_IN_PPM, 0, 250000);
		registerIntegerValue("o2thresholdcirculationoffinppm", JOURNALVARIABLE_O2_THRESHOLD_CIRCULATION_OFF_IN_PPM, 0, 250000);
		
	}
	
	virtual ~CStateHandlerGasCirculation ()		
	{
	}
			

	
};

void registerGasCirculationStateHandler (CApplication * pApplication)
{
	auto pGasCirculationStateHandler = std::make_shared<CStateHandlerGasCirculation> (pApplication);
	//pMainStateHandler->setCycleTime (20);
	pGasCirculationStateHandler->setDebugVariables (CURRENT_STATE_GAS_CIRCULATION, 80);
	pApplication->registerStateHandler (pGasCirculationStateHandler);
}

}


