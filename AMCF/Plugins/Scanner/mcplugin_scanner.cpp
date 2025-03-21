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
#include "libmcdriver_scanlab_dynamic.hpp"
#include "libmcdriver_raylase_dynamic.hpp"
#include "libmcdriver_spinnaker_dynamic.hpp"

/*************************************************************************************************************************
  Driver import definition
**************************************************************************************************************************/
LIBMC_IMPORTDRIVERCLASSES(ScanLab, ScanLab_RTC6)
LIBMC_IMPORTDRIVERCLASSES(Raylase, Raylase)
LIBMC_IMPORTDRIVERCLASSES(Spinnaker, Spinnaker)

__BEGINDRIVERIMPORT
__IMPORTDRIVER(ScanLab_RTC6, "scanlab");
__IMPORTDRIVER(Raylase, "raylase");
__IMPORTDRIVER(Spinnaker, "spinnaker");
__ENDDRIVERIMPORT

void InitialiseScanlabDriver(LibMCEnv::PStateEnvironment pStateEnvironment, PDriver_ScanLab_RTC6 pDriver)
{
	pStateEnvironment->LogMessage("Initialising Scanlab Driver");

	if (pStateEnvironment->GetBoolParameter("cardconfig", "simulatelaser")) {
		pStateEnvironment->LogMessage("Laser Simulation enabled!...");
		pDriver->SetToSimulationMode();
	}

	if (!pDriver->IsSimulationMode()) {
		pDriver->LoadSDK("rtc6dllx64");
		//pDriver->LoadSDK("rtcsimdll");
	}

	auto sIP = pStateEnvironment->GetStringParameter("cardconfig", "ipaddress");
	auto sNetmask = pStateEnvironment->GetStringParameter("cardconfig", "netmask");
	auto nTimeout = pStateEnvironment->GetIntegerParameter("cardconfig", "timeout");
	auto nSerial = pStateEnvironment->GetIntegerParameter("cardconfig", "serial");
	auto dMaxLaserPower = pStateEnvironment->GetDoubleParameter("cardconfig", "maxlaserpower");
	auto dLaserOnDelay = pStateEnvironment->GetDoubleParameter("cardconfig", "laserondelay");
	auto dLaserOffDelay = pStateEnvironment->GetDoubleParameter("cardconfig", "laseroffdelay");
	auto dMarkDelay = pStateEnvironment->GetDoubleParameter("cardconfig", "markdelay");
	auto dJumpDelay = pStateEnvironment->GetDoubleParameter("cardconfig", "jumpdelay");
	auto dPolygonDelay = pStateEnvironment->GetDoubleParameter("cardconfig", "polygondelay");

	auto sCorrectionResourceName = pStateEnvironment->GetStringParameter("correction", "resourcename");
	auto nTableIndex = (uint32_t)pStateEnvironment->GetIntegerParameter("correction", "tableindex");
	auto nDimension = (uint32_t)pStateEnvironment->GetIntegerParameter("correction", "dimension");
	auto nTableNumberHeadA = (uint32_t)pStateEnvironment->GetIntegerParameter("correction", "tablenumbera");
	auto nTableNumberHeadB = (uint32_t)pStateEnvironment->GetIntegerParameter("correction", "tablenumberb");

	pStateEnvironment->LogMessage("Acquiring ScanLab card #" + std::to_string(nSerial));
	pDriver->Initialise(sIP, sNetmask, (uint32_t)nTimeout, (uint32_t)nSerial);

	std::string sFirmwareResource;
	if (sIP.empty()) {
		pStateEnvironment->LogMessage("Loading RTC PCI firmware...");
		sFirmwareResource = "rtc6out";
	}
	else {
		pStateEnvironment->LogMessage("Loading RTC Ethernet firmware...");
		sFirmwareResource = "rtc6eth";
	}

	pDriver->LoadFirmware(sFirmwareResource, "rtc6rbf", "rtc6dat");

	if (!pDriver->IsSimulationMode()) {
		std::vector<uint8_t> CorrectionFileBuffer;
		pStateEnvironment->LogMessage("Loading correction file...");
		pStateEnvironment->LoadResourceData(sCorrectionResourceName, CorrectionFileBuffer);

		pDriver->SetCorrectionFile(CorrectionFileBuffer, nTableIndex, nDimension, nTableNumberHeadA, nTableNumberHeadB);
	}


	pStateEnvironment->LogMessage("Configuring laser...");
	pDriver->ConfigureLaserMode(LibMCDriver_ScanLab::eLaserMode::YAG1, LibMCDriver_ScanLab::eLaserPort::Port12BitAnalog1, dMaxLaserPower, false, false, false, false, false, false);

	pStateEnvironment->LogMessage("Configuring delays...");
	pDriver->ConfigureDelays(dLaserOnDelay, dLaserOffDelay, dMarkDelay, dJumpDelay, dPolygonDelay);
	pStateEnvironment->LogMessage("Initialising done..");


}


void InitialiseRaylaseDriver(LibMCEnv::PStateEnvironment pStateEnvironment, PDriver_Raylase pDriver)
{
	pStateEnvironment->LogMessage("Initialising Raylase Driver");

	if (pStateEnvironment->GetBoolParameter("cardconfig", "simulatelaser")) {
		pStateEnvironment->LogMessage("Laser Simulation enabled!...");
		pDriver->SetToSimulationMode();
	}

	if (!pDriver->IsSimulationMode()) {
		pDriver->LoadSDK();
	}

	auto sIP = pStateEnvironment->GetStringParameter("cardconfig", "ipaddress");
	auto nPort = pStateEnvironment->GetIntegerParameter("cardconfig", "port");
	auto dMaxLaserPower = pStateEnvironment->GetDoubleParameter("cardconfig", "maxlaserpower");
	auto bUsePilot = pStateEnvironment->GetDoubleParameter("cardconfig", "pilotprofile");

	pStateEnvironment->LogMessage("Connecting to Raylase card " + sIP + ":" + std::to_string(nPort));
	auto pCard = pDriver->ConnectByIP("card1", sIP, (uint32_t)nPort, dMaxLaserPower);
	pCard->ResetToSystemDefaults();
	if (bUsePilot) {
		pCard->EnablePilot(true);
		pCard->ArmLaser(false);
	}
	else {
		pCard->EnablePilot(false);
		pCard->ArmLaser(true);
	}


}




/*************************************************************************************************************************
  State definitions
**************************************************************************************************************************/
__BEGINSTATEDEFINITIONS

__DECLARESTATE(init)
{
	std::string sCardType = pStateEnvironment->GetStringParameter("cardconfig", "cardtype");
	if (sCardType == "scanlab")
	{
		InitialiseScanlabDriver(pStateEnvironment, __acquireDriver(ScanLab_RTC6));
	}
	else if (sCardType == "raylase") {
		InitialiseRaylaseDriver(pStateEnvironment, __acquireDriver(Raylase));
	}
	else
		throw std::runtime_error("invalid scanner card type: " + sCardType);

	pStateEnvironment->SetNextState("updatescannerparameters");
}

__DECLARESTATE(updatescannerparameters)
{

	pStateEnvironment->SetNextState("idle");

}


__DECLARESTATE(idle) 
{
	std::string sCardType = pStateEnvironment->GetStringParameter("cardconfig", "cardtype");
	if (sCardType == "scanlab")
	{
		auto pDriver = __acquireDriver(ScanLab_RTC6);
		pDriver->QueryParameters();
	}
	else if (sCardType == "raylase") {
		auto pDriver = __acquireDriver(Raylase);
		pDriver->QueryParameters();
	}
	

	LibMCEnv::PSignalHandler pHandlerInstance;
	if (pStateEnvironment->WaitForSignal("signal_exposure", 0, pHandlerInstance)) {
		pStateEnvironment->StoreSignal("exposuresignal", pHandlerInstance);

		pStateEnvironment->SetNextState("exposelayer");

	}
	else if (pStateEnvironment->WaitForSignal("signal_init_flir", 0, pHandlerInstance))
	{
		int nWaitingTime = pHandlerInstance->GetInteger("waiting_time_interval_in_ms");
		int nArmingTime = pHandlerInstance->GetInteger("arming_time_in_ms");
		int nRecordingTime = pHandlerInstance->GetInteger("recording_time_in_ms");
		int nSavingTime = pHandlerInstance->GetInteger("saving_time_in_ms");
		std::string sFilename = pHandlerInstance->GetString("footage_filename");
		int nFilterChangeTime = pHandlerInstance->GetInteger("filter_change_time_in_ms");
		int nWidth = pHandlerInstance->GetInteger("width_in_pixel");
		int nHeight = pHandlerInstance->GetInteger("height_in_pixel");
		int nOffsetX = pHandlerInstance->GetInteger("offset_x_in_pixel");
		int nOffsetY = pHandlerInstance->GetInteger("offset_y_in_pixel");
		int nNumberOfFrames = pHandlerInstance->GetInteger("frames");
		int nNumberOfPretriggerFrames = pHandlerInstance->GetInteger("pretrigger_frames");
		std::string sCorrectionName = pHandlerInstance->GetString("correction_name");
		std::string sCalibrationTag = pHandlerInstance->GetString("calibration_tag");
		int nIntermediateFilterIndex = pHandlerInstance->GetInteger("intermediate_filter_index");
		int nDesiredFilterIndex = pHandlerInstance->GetInteger("desired_filter_index");

		pStateEnvironment->SetIntegerParameter("flir_camera", "waiting_time_interval_in_ms", nWaitingTime);
		pStateEnvironment->SetIntegerParameter("flir_camera", "arming_time_in_ms", nArmingTime);
		pStateEnvironment->SetIntegerParameter("flir_camera", "recording_time_in_ms", nRecordingTime);
		pStateEnvironment->SetIntegerParameter("flir_camera", "saving_time_in_ms", nSavingTime);
		pStateEnvironment->SetStringParameter("flir_camera", "footage_filename", sFilename);
		pStateEnvironment->SetIntegerParameter("flir_camera", "filter_change_time_in_ms", nFilterChangeTime);
		pStateEnvironment->SetIntegerParameter("flir_camera", "width_in_pixel", nWidth);
		pStateEnvironment->SetIntegerParameter("flir_camera", "height_in_pixel", nHeight);
		pStateEnvironment->SetIntegerParameter("flir_camera", "offset_x_in_pixel", nOffsetX);
		pStateEnvironment->SetIntegerParameter("flir_camera", "offset_y_in_pixel", nOffsetY);
		pStateEnvironment->SetIntegerParameter("flir_camera", "frames", nNumberOfFrames);
		pStateEnvironment->SetIntegerParameter("flir_camera", "pretrigger_frames", nNumberOfPretriggerFrames);
		pStateEnvironment->SetStringParameter("flir_camera", "correction_name", sCorrectionName);
		pStateEnvironment->SetStringParameter("flir_camera", "calibration_tag", sCalibrationTag);
		pStateEnvironment->SetIntegerParameter("flir_camera", "intermediate_filter_index", nIntermediateFilterIndex);
		pStateEnvironment->SetIntegerParameter("flir_camera", "desired_filter_index", nDesiredFilterIndex);

		// By setting the isinitflag true the FLIR is used within the exposelayer state
		pStateEnvironment->SetBoolParameter("flir_camera", "isinitflag", true);

		pHandlerInstance->SetBoolResult("success", true);
		pHandlerInstance->SignalHandled();
		pStateEnvironment->SetNextState("idle");
	}
	else {
		pStateEnvironment->SetNextState("idle");
	}

}

__DECLARESTATE(exposelayer)
{
	auto pSignalHandler = pStateEnvironment->RetrieveSignal("exposuresignal");

	pStateEnvironment->LogMessage("Exposure...");
	auto pBuildJob = pStateEnvironment->GetBuildJob(pSignalHandler->GetString("jobuuid"));
	auto nLayerIndex = (uint32_t)pSignalHandler->GetInteger("layerindex");
	std::string sCardType = pStateEnvironment->GetStringParameter("cardconfig", "cardtype");

	// aquire the spinnaker driver
	PDriver_Spinnaker pDriver_ThermoCamera = __acquireDriver(Spinnaker);
	bool bFlirCameraIsInitFlag = pStateEnvironment->GetBoolParameter("flir_camera", "isinitflag");
	if (bFlirCameraIsInitFlag) // check if the thermography camera is supposed to be active in this sequence
	{
		int nWaitingTime = pStateEnvironment->GetIntegerParameter("flir_camera", "waiting_time_interval_in_ms");
		int nArmingTime = pStateEnvironment->GetIntegerParameter("flir_camera", "arming_time_in_ms");
		int nRecordingTime = pStateEnvironment->GetIntegerParameter("flir_camera", "recording_time_in_ms");
		int nSavingTime = pStateEnvironment->GetIntegerParameter("flir_camera", "saving_time_in_ms");
		std::string sFilename = pStateEnvironment->GetStringParameter("flir_camera", "footage_filename");
		int nFilterChangeTime = pStateEnvironment->GetIntegerParameter("flir_camera", "filter_change_time_in_ms");
		int nWidth = pStateEnvironment->GetIntegerParameter("flir_camera", "width_in_pixel");
		int nHeight = pStateEnvironment->GetIntegerParameter("flir_camera", "height_in_pixel");
		int nOffsetX = pStateEnvironment->GetIntegerParameter("flir_camera", "offset_x_in_pixel");
		int nOffsetY = pStateEnvironment->GetIntegerParameter("flir_camera", "offset_y_in_pixel");
		int nNumberOfFrames = pStateEnvironment->GetIntegerParameter("flir_camera", "frames");
		int nNumberOfPretriggerFrames = pStateEnvironment->GetIntegerParameter("flir_camera", "pretrigger_frames");
		std::string sCorrectionName = pStateEnvironment->GetStringParameter("flir_camera", "correction_name");
		std::string sCalibrationTag = pStateEnvironment->GetStringParameter("flir_camera", "calibration_tag");
		int nIntermediateFilterIndex = pStateEnvironment->GetIntegerParameter("flir_camera", "intermediate_filter_index");
		int nDesiredFilterIndex = pStateEnvironment->GetIntegerParameter("flir_camera", "desired_filter_index");

		// initialize the flir camera
		bool bInitSpinnakerSuccess = pDriver_ThermoCamera->InitSpinnaker(nWaitingTime, nArmingTime, nRecordingTime, nSavingTime, nFilterChangeTime, nWidth, nHeight, nOffsetX, nOffsetY, nNumberOfFrames, nNumberOfPretriggerFrames, sCorrectionName, sCalibrationTag, nIntermediateFilterIndex, nDesiredFilterIndex);
		if (bInitSpinnakerSuccess)
		{
			// set the filename of the footage of the flir camera
			bool bSetFilenameSpinnakerSuccess = pDriver_ThermoCamera->SetFilenameSpinnaker(sFilename, nLayerIndex);
			if (bSetFilenameSpinnakerSuccess)
			{
				// connect to the flir camera

				bool bConnectToFlirSuccess = pDriver_ThermoCamera->ConnectToFlir(0); // index of the port within the camera list instance
				if (bConnectToFlirSuccess)
				{
					pStateEnvironment->LogMessage("Flir camera is connected!");
					// arm the flir camera
					bool bArmFlirSuccess = pDriver_ThermoCamera->ArmFlir();
					if (bArmFlirSuccess)
					{
						// start recording with the flir camera
						bool bStartRecordingFlirSuccess = pDriver_ThermoCamera->StartRecordingFlir();
						if (bStartRecordingFlirSuccess)
						{
							pStateEnvironment->LogMessage("Starting to record with the flir camera..");
						}
						else
						{
							pStateEnvironment->LogMessage("Starting to record with the flir camera was not successful..");
							pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
						}
					}
					else
					{
						pStateEnvironment->LogMessage("Arming the flir camera was not successful..");
						pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
					}
				}
				else
				{
					pStateEnvironment->LogMessage("Connecting to the flir camera was not successful..");
					pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
				}
			}
			else
			{
				pStateEnvironment->LogMessage("Setting the filename within the spinnaker driver was not successful..");
				pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
			}
		}
		else
		{
			pStateEnvironment->LogMessage("Initializing the spinnaker driver was not successful..");
			pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
		}
	}

	if (sCardType == "scanlab")
	{
		auto pDriver = __acquireDriver(ScanLab_RTC6);

		if (pDriver->IsSimulationMode()) {
			pStateEnvironment->LogMessage("Simulation mode delay of 2 seconds..");
			pStateEnvironment->Sleep(2000);
		}

		auto pContext = pDriver->GetContext();
		auto pRecording = pContext->PrepareRecording(true);

		pRecording->AddChannel("x", LibMCDriver_ScanLab::eRTCChannelType::ChannelTargetXBacktransformed);
		pRecording->AddChannel("y", LibMCDriver_ScanLab::eRTCChannelType::ChannelTargetYBacktransformed);
		pRecording->AddChannel("power", LibMCDriver_ScanLab::eRTCChannelType::ChannelAnalogOut1);

		pContext->SetStartList(1, 0);
		pRecording->EnableRecording(LibMCDriver_ScanLab::eRTCRecordingFrequency::Record100kHz);

		auto pAccessor = pBuildJob->CreateToolpathAccessor();
		auto pLayer = pAccessor->LoadLayer(nLayerIndex);
		pContext->AddLayerToList(pLayer, false);

		pRecording->DisableRecording();

		pStateEnvironment->LogMessage("Starting Execution...");

		pRecording->ExecuteListWithRecording();

		pStateEnvironment->LogMessage("Execution finished");

		auto pDataTable = pStateEnvironment->CreateDataTable();
		pRecording->AddRecordsToDataTable("x", pDataTable, "x", "X");
		pRecording->AddRecordsToDataTable("y", pDataTable, "y", "Y");
		pRecording->AddRecordsToDataTable("power", pDataTable, "power", "Power");

		auto pTempStream = pStateEnvironment->CreateTemporaryStream("layer_" + std::to_string(nLayerIndex), "text/csv");
		pDataTable->WriteCSVToStream(pTempStream, nullptr);
		pTempStream->Finish();

		//pDriver->DrawLayer(pBuildJob->GetStorageUUID(), nLayerIndex);
	}
	else if (sCardType == "raylase") {
		auto pDriver = __acquireDriver(Raylase);

		if (pDriver->IsSimulationMode()) {
			pStateEnvironment->LogMessage("Simulation mode delay of 2 seconds..");
			pStateEnvironment->Sleep(2000);
		}

		pStateEnvironment->LogMessage("Get Connected Card...");
		auto pCard = pDriver->GetConnectedCard("card1");
		pStateEnvironment->LogMessage("Drawing Layer...");
		pCard->DrawLayer(pBuildJob->GetStorageUUID(), nLayerIndex, 300000);
		pStateEnvironment->LogMessage("Drawing Layer successful...");
	}

	pSignalHandler->SetBoolResult("success", true);
	pSignalHandler->SignalHandled();

	bool bFlirCameraIsErrorFlag = pStateEnvironment->GetBoolParameter("flir_camera", "iserrorflag");
	if ((bFlirCameraIsErrorFlag == false) && (bFlirCameraIsInitFlag == true)) // if an error occured in the first thermography-camera-related sequence, this sequence is unnecessary
	{
		// wait for the recording to stop and then save the footage on the SSD of the flir camera
		bool bWaitForRecordAndSaveFlirSuccess = pDriver_ThermoCamera->WaitForRecordAndSaveFlir();
		if (bWaitForRecordAndSaveFlirSuccess)
		{
			pStateEnvironment->LogMessage("The recording with the FLIR camera is finished and the footage was saved!");
			// disconnect from the flir camera
			bool bDisconnectFlirSuccess = pDriver_ThermoCamera->DisconnectFlir();
			if (bDisconnectFlirSuccess)
			{
				pStateEnvironment->LogMessage("Successfuly disconnected from the FLIR camera");
			}
			else
			{
				pStateEnvironment->LogMessage("Disconnecting from the FLIR camera was not successful..");
				pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
			}
		}
		else
		{
			pStateEnvironment->LogMessage("Either saving or recording with the FLIR camera was not successful..");
			pStateEnvironment->SetBoolParameter("flir_camera", "iserrorflag", true);
		}
	}

	pStateEnvironment->SetNextState("idle");
}


__DECLARESTATE(fatalerror) 
{
	pStateEnvironment->SetNextState("fatalerror");
}



__ENDSTATEDEFINITIONS