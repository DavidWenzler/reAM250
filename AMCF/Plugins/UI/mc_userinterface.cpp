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

#include "libmcui_interfaceexception.hpp"
#include "libmcui_eventhandler.hpp"
#include "libmcui_event.hpp"

using namespace LibMCUI::Impl;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#endif

#define CONTROLLER_ID_HEATER 1
#define CONTROLLER_ID_SHIELDINGGAS 2

/*************************************************************************************************************************
 Class declaration of CEvent_Logout
**************************************************************************************************************************/

class CEvent_Logout : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_logout";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Clicked on Logout");
		pUIEnvironment->LogOut();

	}

};


class CEvent_ReleaseDoorClick : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_releasedoorclick";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Clicked on release door");
		auto pSignal = pUIEnvironment->PrepareSignal("plc", "signal_releasedoor");
		pSignal->Trigger();

	}

};

class CEvent_OnUploadFinished : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_onuploadfinished";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		pUIEnvironment->LogMessage("Uploaded success from " + sSender);

		auto sBuildUUID = pUIEnvironment->GetUIPropertyAsUUID(sSender, "uploaduuid");
		pUIEnvironment->LogMessage("Build job ID " + sBuildUUID);


		pUIEnvironment->SetUIProperty("importbuildjob.preview", "builduuid", sBuildUUID);
		pUIEnvironment->SetUIPropertyAsInteger("importbuildjob.preview", "currentlayer", 3);

		pUIEnvironment->ActivatePage("importbuildjob");
	}

};


class CEvent_OnSelectBuild : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_onselectbuild";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		pUIEnvironment->LogMessage("Build item selected from " + sSender);

		auto nLayer = pUIEnvironment->GetUIPropertyAsInteger("importbuildjob.layerinfo.layerinfoform.currentlayer", "value");

		auto sBuildUUID = pUIEnvironment->GetUIPropertyAsUUID(sSender, "selecteduuid");
		pUIEnvironment->LogMessage("Build job ID " + sBuildUUID);
		pUIEnvironment->SetUIProperty("importbuildjob.preview", "builduuid", sBuildUUID);
		pUIEnvironment->SetUIPropertyAsInteger("importbuildjob.preview", "currentlayer", nLayer);

		pUIEnvironment->ActivatePage("importbuildjob");

	}

};

class CEvent_OnImportLayerChange : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_onimportlayerchange";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		auto nLayer = pUIEnvironment->GetUIPropertyAsInteger("importbuildjob.layerinfo.layerinfoform.currentlayer", "value");

		if (nLayer < 0) {
		nLayer = 0;
		}

		if (sSender == "importbuildjob.layerinfo.buttongroup.changelayer")
		{
			pUIEnvironment->LogMessage("Changed layer, layer index = " + std::to_string(nLayer));

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_changelayer");
			pSignal->SetInteger("layer", nLayer);
			pSignal->Trigger();

			pUIEnvironment->SetUIPropertyAsInteger("importbuildjob.preview", "currentlayer", nLayer);
		}

	}

};

class CEvent_StartBuild : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_startbuild";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Clicked on StartBuild Button");

		auto sBuildUUID = pUIEnvironment->GetUIPropertyAsUUID("importbuildjob.preview", "builduuid");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_startbuild");
		pSignal->SetString("jobuuid", sBuildUUID);
		pSignal->Trigger();

		pUIEnvironment->ActivatePage("buildstatus");

	}

};

class CEvent_CancelBuild : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_cancelbuild";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Clicked on CancelBuild Button");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_cancelbuild");
		pSignal->Trigger();
	}

};

class CEvent_SingleAxisMovement : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_singleaxismovement";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		auto sSender = pUIEnvironment->RetrieveEventSender();

		if (sSender == "dialog_manualmovement.manual_movement_platform.buttongroup_manual_movement_platform.move_absolute")
		{
			pUIEnvironment->LogMessage("Starting absolute manual movement of the build platform axis");
			
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 1);
			pSignal->SetInteger("absoluterelative", 1);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.position_or_distance_platform", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.velocity_platform", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.acceleration_platform", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_powderreservoir.buttongroup_manual_movement_powderreservoir.move_absolute")
		{
			pUIEnvironment->LogMessage("Starting absolute manual movement of the powder reservoir axis");
			
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 2);
			pSignal->SetInteger("absoluterelative", 1);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.position_or_distance_powderreservoir", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.velocity_powderreservoir", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.acceleration_powderreservoir", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_recoater_powder.buttongroup_manual_movement_recoater_powder.move_absolute")
		{
			pUIEnvironment->LogMessage("Starting absolute manual movement of the recoater powder axis");
			
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 3);
			pSignal->SetInteger("absoluterelative", 1);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.position_or_distance_recoater_powder", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.velocity_recoater_powder", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.acceleration_recoater_powder", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_recoater_linear.buttongroup_manual_movement_recoater_linear.move_absolute")
		{
			pUIEnvironment->LogMessage("Starting absolute manual movement of the recoater linear axis");
			
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 4);
			pSignal->SetInteger("absoluterelative", 1);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.position_or_distance_recoater_linear", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.velocity_recoater_linear", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.acceleration_recoater_linear", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_platform.buttongroup_manual_movement_platform.move_relative")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the build platform axis");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 1);
			pSignal->SetInteger("absoluterelative", 2);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.position_or_distance_platform", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.velocity_platform", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_manual_movement_platform.acceleration_platform", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_powderreservoir.buttongroup_manual_movement_powderreservoir.move_relative")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the powder reservoir axis");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 2);
			pSignal->SetInteger("absoluterelative", 2);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.position_or_distance_powderreservoir", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.velocity_powderreservoir", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_powderreservoir.form_manual_movement_powderreservoir.acceleration_powderreservoir", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_recoater_powder.buttongroup_manual_movement_recoater_powder.move_relative")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the recoater powder axis");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 3);
			pSignal->SetInteger("absoluterelative", 2);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.position_or_distance_recoater_powder", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.velocity_recoater_powder", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_powder.form_manual_movement_recoater_powder.acceleration_recoater_powder", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_recoater_linear.buttongroup_manual_movement_recoater_linear.move_relative")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the recoater linear axis");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement");
			pSignal->SetInteger("axis_ID", 4);
			pSignal->SetInteger("absoluterelative", 2);
			pSignal->SetDouble("target", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.position_or_distance_recoater_linear", "value"));
			pSignal->SetDouble("speed", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.velocity_recoater_linear", "value"));
			pSignal->SetDouble("acceleration", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoater_linear.form_manual_movement_recoater_linear.acceleration_recoater_linear", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_powderreservoir.buttongroup_powder_dosing.button_powder_dosing")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the powder reservoir axis to dose the powder");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manual_powder_dosing");
			pSignal->SetInteger("dosing_notches", pUIEnvironment->GetUIPropertyAsInteger("dialog_manualmovement.manual_movement_powderreservoir.form_powder_dosing.dosing_units", "value"));
			pSignal->Trigger();
		}
		if (sSender == "dialog_manualmovement.manual_movement_platform.buttongroup_change_layer.button_change_layer")
		{
			pUIEnvironment->LogMessage("Starting relative manual movement of the build platform axis to change the layer");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_singleaxismovement_change_layer");
			pSignal->SetDouble("layer_height_manual", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_platform.form_change_layer.layer_height", "value"));
			pSignal->Trigger();
		}

	}

};

class CEvent_ManualMovementControl_Enter : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualmovementcontrol_enter";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Entering manual movement control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualmovementcontrol_enter");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {

			pUIEnvironment->ActivateModalDialog("dialog_manualmovement");
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Movement", "Could not enter manual movement mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};


class CEvent_ManualMovementControl_Leave : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualmovementcontrol_leave";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Leaving manual control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualmovementcontrol_leave");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {


			pUIEnvironment->CloseModalDialog();
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Movement", "Could not leave manual control mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};


class CEvent_ManualControl_ReferenceAxis : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualcontrol_referenceaxis";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		auto sSender = pUIEnvironment->RetrieveEventSender();

		pUIEnvironment->LogMessage("Manual Control Reference axis");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_referenceaxis");
		pSignal->SetBool("reference_platform", (sSender == "dialog_manualmovement.manual_movement_platform.buttongroup_manual_movement_platform.reference_axis"));
		pSignal->SetBool("reference_platform_absolute_switch", (sSender == "dialog_manualmovement.manual_movement_platform.buttongroup_manual_movement_platform.reference_axis_absolute_switch"));
		pSignal->SetBool("reference_powderreservoir", (sSender == "dialog_manualmovement.manual_movement_powderreservoir.buttongroup_manual_movement_powderreservoir.reference_axis"));
		pSignal->SetBool("reference_recoateraxis_powder", (sSender == "dialog_manualmovement.manual_movement_recoater_powder.buttongroup_manual_movement_recoater_powder.reference_axis"));
		pSignal->SetBool("reference_recoateraxis_linear", (sSender == "dialog_manualmovement.manual_movement_recoater_linear.buttongroup_manual_movement_recoater_linear.reference_axis"));
		pSignal->Trigger();


	}

};

class CEvent_ManualMovementControl_RecoatLayer : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualmovementcontrol_recoat_layer";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		auto sSender = pUIEnvironment->RetrieveEventSender();

		pUIEnvironment->LogMessage("Manual Movement Control Recoat Layer");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualmovementcontrol_recoat_layer");
		pSignal->SetDouble("dosing_factor_manual", pUIEnvironment->GetUIPropertyAsDouble("dialog_manualmovement.manual_movement_recoat_layer_form.form_recoat_layer.recoat_layer_dosing_factor", "value"));
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {
			return;
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Movement Control", "Could not recoat layer", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_ManualAtmosphereControl_Enter : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_enter";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Entering manual atmosphere control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_enter");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {

			pUIEnvironment->ActivateModalDialog("dialog_manualatmospherecontrol");
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not enter manual atmosphere control mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_ManualAtmosphereControl_Leave : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_leave";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Leaving manual atmosphere control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_leave");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {


			pUIEnvironment->CloseModalDialog();
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not leave manual atmosphere control mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_ToggleValves : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_togglevalves";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual toggle valves");

		auto sSender = pUIEnvironment->RetrieveEventSender();
		int nValve_ID = 0;

		if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_valves.button_toggle_lower_gas_flow_circuit_valve")
		{
			nValve_ID = 1;
		}else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_valves.button_toggle_upper_gas_flow_circuit_valve")
		{
			nValve_ID = 2;
		}else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_valves.button_toggle_shielding_gas_valve")
		{
			nValve_ID = 3;
		}else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_valves.button_toggle_chamber_vacuum_valve")
		{
			nValve_ID = 4;
		}else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_valves.button_toggle_zAxis_vacuum_valve")
		{
			nValve_ID = 5;
		}

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualtogglevalves");
		pSignal->SetInteger("valve_ID", nValve_ID);
		pSignal->Trigger();

	}

};

class CEvent_ManualAtmosphereControl_Init : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_init";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual atmosphere control init");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_init");
		pSignal->Trigger();

	}

};

class CEvent_ManualAtmosphereControlUpdateGasFlowSetpoint : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_update_gas_flow_setpoint";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual atmosphere control update gas flow setpoint");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_update_gas_flow_setpoint");
		pSignal->Trigger();

	}

};

class CEvent_ManualAtmosphereControleventStartGasFlow : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_start_gas_flow";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual atmosphere control start gas flow");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_start_gas_flow");
		pSignal->Trigger();

	}

};

class CEvent_ManualAtmosphereControlTurnOffGasFlow : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_turn_off_gas_flow";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual atmosphere control turn off gas flow");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_turn_off_gas_flow");
		pSignal->Trigger();

	}

};

class CEvent_ManualAtmosphereControlSave : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualatmospherecontrol_save";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual atmosphere control save");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_navigation.button_save")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualatmospherecontrol_save");
			pSignal->SetInteger("setpointinpercent", pUIEnvironment->GetUIPropertyAsInteger("dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.form_gas_flow_control.setpoint", "value"));
			pSignal->Trigger();
		}

	}

};

class CEvent_ManualVacuumControl_Init : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualvacuumcontrol_init";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual vacuum control init");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualvacuumcontrol_init");
		pSignal->Trigger();

	}

};

class CEvent_ManualVacuumControlStartVacuumPump : public virtual CEvent{

public:

	static std::string getEventName()
	{
		return "event_manualvacuumcontrol_start_vacuum_pump";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual vacuum control start vacuum pump");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualvacuumcontrol_start_vacuum_pump");
		pSignal->Trigger();

	}

};

class CEvent_ManualVacuumControlTurnOffVacuumPump : public virtual CEvent{

public:

	static std::string getEventName()
	{
		return "event_manualvacuumcontrol_turn_off_vacuum_pump";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Manual vacuum control turn off vacuum pump");

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualvacuumcontrol_turn_off_vacuum_pump");
		pSignal->Trigger();

	}

};

class CEvent_ManualHeaterControl_Enter : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualheatercontrol_enter";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Entering manual heater control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualheatercontrol_enter");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {

			pUIEnvironment->ActivateModalDialog("dialog_manualheatercontrol");
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not enter manual heater control mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_ControllerParameterList_Enter : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_controllerparameterlist_enter";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_change_controller_parameters")
		{
			pUIEnvironment->LogMessage("Opening heater controller parameter list");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_heaterparameterlist");
		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_change_controller_parameters")
		{
			pUIEnvironment->LogMessage("Opening oxygen controller parameter list");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_oxygenparameterlist");
		}

	}

};

class CEvent_ControllerParameterList_Leave : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_controllerparameterlist_leave";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_heaterparameterlist.infobox.buttongroup_navigation.button_cancel")
		{
			pUIEnvironment->LogMessage("Closing heater controller parameter list");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_manualheatercontrol");
		}
		else if (sSender == "dialog_oxygenparameterlist.infobox.buttongroup_navigation.button_cancel")
		{
			pUIEnvironment->LogMessage("Closing oxygen controller parameter list");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_manualatmospherecontrol");
		}
	}

};

class CEvent_ManualHeaterControl_Leave : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_manualheatercontrol_leave";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Leaving manual heater control mode");

		// TODO: Check if in Idle or Manualmovement!

		auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manualheatercontrol_leave");
		pSignal->Trigger();

		if (pSignal->WaitForHandling(1000)) {
			bool bIsAutotuning = pSignal->GetBoolResult("istuning");

			if (bIsAutotuning) {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not leave manual heater control mode, auto tuning is in progress", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");;
			}
			else {
				pUIEnvironment->CloseModalDialog();
			}
			
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not leave manual heater control mode", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_ControllerParameterList_Save : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_controllerparameterlist_save";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_heaterparameterlist.infobox.buttongroup_navigation.button_save")
		{
			try
			{
				pUIEnvironment->LogMessage("Saving heater controller parameters");
				auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_controllerparameters_save");
				pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
				pSignal->SetDouble("derivativetime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.derivativetime", "value"));
				pSignal->SetDouble("integrationtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.integrationtime", "value"));
				pSignal->SetDouble("gain", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.gain", "value"));
				pSignal->SetDouble("filtertime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.filtertime", "value"));
				pSignal->SetInteger("maxout", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.maxout", "value"));
				pSignal->SetInteger("minout", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.minout", "value"));
				pSignal->SetInteger("dutycycle", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.dutycycle", "value"));
				pSignal->SetDouble("periodTime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.periodTime", "value"));
				pSignal->SetInteger("maxFrequency", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.maxFrequency", "value"));
				pSignal->SetBool("mode", pUIEnvironment->GetUIPropertyAsBool("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.mode", "value"));
				pSignal->SetInteger("stepheight", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.stepheight", "value"));
				pSignal->SetInteger("maxactvalue", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.maxactvalue", "value"));
				pSignal->SetInteger("minactvalue", pUIEnvironment->GetUIPropertyAsInteger("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.minactvalue", "value"));
				pSignal->SetDouble("systemsettlingtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.systemsettlingtime", "value"));
				pSignal->SetDouble("maxtuningtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_heaterparameterlist.infobox.form_heater_controller_parameters.maxtuningtime", "value"));
				pSignal->Trigger();

				if (pSignal->WaitForHandling(1000)) {
					return;
				}
				else {
					pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not save heater controller parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				}
			}
			catch (const std::exception& e)
			{
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", e.what(), LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				pUIEnvironment->LogMessage(e.what());
			}
		}
		else if (sSender == "dialog_oxygenparameterlist.infobox.buttongroup_navigation.button_save")
		{
			try
			{
				pUIEnvironment->LogMessage("Saving oxygen controller parameters");
				auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_controllerparameters_save");
				pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
				pSignal->SetDouble("derivativetime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.derivativetime", "value"));
				pSignal->SetDouble("integrationtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.integrationtime", "value"));
				pSignal->SetDouble("gain", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.gain", "value"));
				pSignal->SetDouble("filtertime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.filtertime", "value"));
				pSignal->SetInteger("maxout", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.maxout", "value"));
				pSignal->SetInteger("minout", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.minout", "value"));
				pSignal->SetInteger("dutycycle", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.dutycycle", "value"));
				pSignal->SetDouble("periodTime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.periodTime", "value"));
				pSignal->SetInteger("maxFrequency", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.maxFrequency", "value"));
				pSignal->SetBool("mode", pUIEnvironment->GetUIPropertyAsBool("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.mode", "value"));
				pSignal->SetInteger("stepheight", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.stepheight", "value"));
				pSignal->SetInteger("maxactvalue", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.maxactvalue", "value"));
				pSignal->SetInteger("minactvalue", pUIEnvironment->GetUIPropertyAsInteger("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.minactvalue", "value"));
				pSignal->SetDouble("systemsettlingtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.systemsettlingtime", "value"));
				pSignal->SetDouble("maxtuningtime", pUIEnvironment->GetUIPropertyAsDouble("dialog_oxygenparameterlist.infobox.form_oxygen_controller_parameters.maxtuningtime", "value"));
				pSignal->Trigger();

				if (pSignal->WaitForHandling(1000)) {
					return;
				}
				else {
					pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not save oxygen controller parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				}
			}
			catch (const std::exception& e)
			{
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", e.what(), LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				pUIEnvironment->LogMessage(e.what());
			}

		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not save controller parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_StartAutoTuneController : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_startautotunecontroller";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_start_autotune")
		{

			pUIEnvironment->LogMessage("Starting heater auto tuning");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_heaterautotuning");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manual_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
			pSignal->Trigger();
		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_start_autotune")
		{
			pUIEnvironment->LogMessage("Starting oxygen controller auto tuning");
			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_oxygenautotuning");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_manual_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
			pSignal->Trigger();
		}

	}

};

class CEvent_AbortTuning : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_aborttuning";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_heaterautotuning.infobox.buttongroup_navigation.button_cancel")
		{
			pUIEnvironment->LogMessage("Aborting heater auto tuning");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_abort_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_HEATER);
			pSignal->Trigger();

			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_manualheatercontrol");
		}
		else if (sSender == "dialog_oxygenautotuning.infobox.buttongroup_navigation.button_cancel")
		{
			pUIEnvironment->LogMessage("Aborting oxygen controller auto tuning");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_abort_controllertuning");
			pSignal->SetInteger("controller_ID", CONTROLLER_ID_SHIELDINGGAS);
			pSignal->Trigger();

			pUIEnvironment->CloseModalDialog();
			pUIEnvironment->ActivateModalDialog("dialog_manualatmospherecontrol");
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not abort controller tuning", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}
		

	}

};

class CEvent_EnableController : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_enablecontroller";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_enable_heatercontrol")
		{
			pUIEnvironment->LogMessage("Enabling heater controller ...");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_enableheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not enable heater control", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_enable_oxygencontrol")
		{
			pUIEnvironment->LogMessage("Enabling oxygen controller ...");

			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_enableoxygencontroller");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not enable oxygen controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not enable controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}


	}

};

class CEvent_ManualHeaterSetpoint_Save : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_heatersetpoint_save";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Save manual heater control parameters");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_navigation.button_save")
		{
			try
			{
				auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_heatercontrolsetpoint_save");
				pSignal->SetInteger("setpoint", pUIEnvironment->GetUIPropertyAsInteger("dialog_manualheatercontrol.infobox_manualheatercontrol.form_heater_setpoint.setpoint", "value"));
				pSignal->Trigger();

				if (pSignal->WaitForHandling(1000)) {
					return;
				}
				else {
					pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not save heater setpoint", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				}
			}
			catch (const std::exception& e)
			{
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", e.what(), LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
				pUIEnvironment->LogMessage(e.what());
			}
			
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not save heater setpoint", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_UpdateControllerPid : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_updatecontrollerPID";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_update_PID_parameters")
		{	
			pUIEnvironment->LogMessage("Update heater control PID parameters");
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatePIDheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else 
			{
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not update heater control PID parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_update_PID_parameters")
		{
			pUIEnvironment->LogMessage("Update oxygen controller PID parameters");
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatePIDoxygencontroller");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else 
			{
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not update oxygen controller PID parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not update PID controller parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_UpdateControllerPwm: public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_updatecontrollerPWM";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_update_PWM_parameters")
		{
			pUIEnvironment->LogMessage("Update heater control PWM parameters");
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatePWMheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not update heater control PWM parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_update_PWM_parameters")
		{
			pUIEnvironment->LogMessage("Update oxygen controller PWM parameters");
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatePWMoxygencontroller");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else
			{
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not update oxygen controller PWM parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not update controller PWM parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_UpdateControllerTuner : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_updatecontrollertuner";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Update heater control tuner parameters");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_update_tuner_parameters")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatetunerheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not update heater control tuner parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_update_tuner_parameters")
		{
			pUIEnvironment->LogMessage("Update oxygen controller tuner parameters");
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updatetuneroxygencontroller");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else
			{
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not update oxygen controller tuner parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}
		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not update controller tuner parameters", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

}; 

class CEvent_InitController : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_initcontroller";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Init heater controller");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_init_heatercontrol")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_initheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not initialize heater controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_init_oxygencontrol")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_initoxygen");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not initialize oxygen controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not initialize controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_DisableController : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_disablecontroller";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Disabe heater controller");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_disable_heatercontrol")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_disableheater");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not disable heater controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_disable_oxygencontrol")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_disableoxygencontroller");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not disable oxygen controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not disable controller", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};

class CEvent_UpdateControllerSetpoint : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_updatecontrollersetpoint";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Update heater setpoint");
		auto sSender = pUIEnvironment->RetrieveEventSender();
		if (sSender == "dialog_manualheatercontrol.infobox_manualheatercontrol.buttongroup_controller.button_update_heatersetpoint")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updateheatersetpoint");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Heater Control", "Could not update heater setpoint", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else if (sSender == "dialog_manualatmospherecontrol.infobox_manualatmospherecontrol.buttongroup_oxygen_controller.button_update_oxygensetpoint")
		{
			auto pSignal = pUIEnvironment->PrepareSignal("main", "signal_updateoxygensetpoint");
			pSignal->Trigger();

			if (pSignal->WaitForHandling(1000)) {
				return;
			}
			else {
				pUIEnvironment->ShowMessageDlg("Manual Atmosphere Control", "Could not update oxygen setpoint", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
			}

		}
		else {
			pUIEnvironment->ShowMessageDlg("Manual Control", "Could not update controller setpoint", LibMCEnv::eMessageDialogType::DialogOK, "", "", "");
		}

	}

};


class CEvent_CancelPreview : public virtual CEvent {

public:

	static std::string getEventName()
	{
		return "event_cancelpreview";
	}

	void Handle(LibMCEnv::PUIEnvironment pUIEnvironment) override
	{

		pUIEnvironment->LogMessage("Clicked on CancelPreview Button");
		pUIEnvironment->SetUIProperty("importbuildjob.preview", "builduuid", "");
		pUIEnvironment->SetUIPropertyAsInteger("importbuildjob.preview", "currentlayer", 3);

		pUIEnvironment->ActivatePage("main");


	}

};


IEvent* CEventHandler::CreateEvent(const std::string& sEventName, LibMCEnv::PUIEnvironment pUIEnvironment)
{
	IEvent* pEventInstance = nullptr;
	if (createEventInstanceByName<CEvent_Logout>(sEventName, pEventInstance))
		return pEventInstance;	
	if (createEventInstanceByName<CEvent_OnSelectBuild>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_OnUploadFinished>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_StartBuild>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_CancelBuild>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_OnImportLayerChange>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_CancelPreview>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_SingleAxisMovement>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualMovementControl_Enter>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualMovementControl_Leave>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualControl_ReferenceAxis>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ReleaseDoorClick>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControl_Enter>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControl_Leave>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ToggleValves>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControl_Init>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControlUpdateGasFlowSetpoint>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControleventStartGasFlow>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControlTurnOffGasFlow>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualAtmosphereControlSave>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualVacuumControl_Init>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualVacuumControlStartVacuumPump>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualVacuumControlTurnOffVacuumPump>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualHeaterControl_Enter>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualHeaterControl_Leave>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_StartAutoTuneController>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_AbortTuning>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_EnableController>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualHeaterSetpoint_Save>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_UpdateControllerPid>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_UpdateControllerPwm>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_UpdateControllerTuner>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_InitController>(sEventName, pEventInstance))
		return pEventInstance; 
	if (createEventInstanceByName<CEvent_DisableController>(sEventName, pEventInstance))
		return pEventInstance; 
	if (createEventInstanceByName<CEvent_UpdateControllerSetpoint>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ControllerParameterList_Enter>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ControllerParameterList_Leave>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ControllerParameterList_Save>(sEventName, pEventInstance))
		return pEventInstance;
	if (createEventInstanceByName<CEvent_ManualMovementControl_RecoatLayer>(sEventName, pEventInstance))
		return pEventInstance;
	
	
	throw ELibMCUIInterfaceException(LIBMCUI_ERROR_INVALIDEVENTNAME, "invalid event name: " + sEventName);
}




#ifdef _MSC_VER
#pragma warning(pop)
#endif
