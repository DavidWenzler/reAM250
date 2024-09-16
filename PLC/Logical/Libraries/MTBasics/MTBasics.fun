
{REDUND_OK} FUNCTION_BLOCK MTBasicsDT1 (*First-order derivative action element.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Gain : REAL; (*Gain factor.*)
		TimeConstant : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsDT1InternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsDT2 (*Second-order derivative action element.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Gain : REAL; (*Gain factor.*)
		TimeConstant1 : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant1 >= 0.*)
		TimeConstant2 : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant2 >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsDT2InternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsIntegrator (*Integrator.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Gain : REAL; (*Gain factor. Valid value range: Gain >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
		OutPresetValue : REAL; (*Preset value for Out output.*)
		SetOut : BOOL; (*Sets Out to OutPresetValue on rising edge.*)
		HoldOut : BOOL; (*Freezes the function block.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsIntegratorInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsLevelController (*Level controller.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Parameter : MTBasicsLevelCtrlParType; (*3-step controller parameters.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
	END_VAR
	VAR
		Internal : MTBasicsLevelCtrlInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsLimiter (*Limiter.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		MinOut : REAL; (*Lower output variable limit. Valid value range: MinOut < MaxOut.*)
		MaxOut : REAL; (*Upper output variable limit. Valid value range: MaxOut > MinOut.*)
		MaxPosSlewRate : REAL; (*Maximum output variable ramp for ramp-up. Unit: [1/s]. Valid value range: MaxPosSlewRate >= 0.*)
		MaxNegSlewRate : REAL; (*Maximum output variable ramp for the ramp-down. Unit: [1/s]. Valid value range: MaxNegSlewRate >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
		OutPresetValue : REAL; (*Preset value for Out output.*)
		SetOut : BOOL; (*Sets Out to OutPresetValue on rising edge.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
	END_VAR
	VAR
		Internal : MTBasicsLimiterInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsOscillationTuning (*Oscillation tuning for PID.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		SetValue : REAL; (*Reference variable (setpoint).*)
		MinOut : REAL; (*Lower manipulated variable limit. Valid value range: MinOut < MaxOut.*)
		MaxOut : REAL; (*Upper manipulated variable limit. Valid value range: MaxOut > MinOut.*)
		Invert : BOOL; (*Inverts the direction of the controller.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		ActValue : REAL; (*Actual measured value.*)
		Start : BOOL; (*Starts the tuning (on positive edge).*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value (manipulated variable). Value range: MinOut <= Out <= MaxOut.*)
		TuningActive : BOOL; (*Tuning is active.*)
		TuningDone : BOOL; (*Tuning completed.*)
		Quality : REAL; (*Quality of the oscillation tuning. Unit: [%]. Value range: 0 (low) ... 100 (high).*)
		PIDParameters : MTPIDParametersType; (*PID parameters.*)
	END_VAR
	VAR
		Internal : MTBasicsOscTuningInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsPFM (*Pulse frequency modulator.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		PulseWidth : REAL; (*Pulse width at the output. Unit: [s]. Valid value range: PulseWidth >= task cycle time.*)
		MinPause : REAL; (*Minimum pause between the pulses at the output. Unit: [s]. Valid value range: MinPause >= task cycle time.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		DutyCycle : REAL; (*Input value.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : BOOL; (*Output value.*)
	END_VAR
	VAR
		Internal : MTBasicsPFMInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsPID (*PID controller.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		PIDParameters : MTPIDParametersType; (*PID parameters.*)
		MinOut : REAL; (*Lower manipulated variable limit (lower modulation limit of the subsequent actuator).*)
		MaxOut : REAL; (*Upper manipulated variable limit (upper modulation limit of the subsequent actuator).*)
		Invert : BOOL; (*Reverses the effective direction of the controller.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		SetValue : REAL; (*Set value (reference variable).*)
		ActValue : REAL; (*Actual value (controlled variable).*)
		IntegrationPartPresetValue : REAL; (*Preset value for the integral component IntegrationPart.*)
		SetIntegrationPart : BOOL; (*A positive edge on SetIntegrationPart sets the integral component IntegrationPart of the PID controller to IntegrationPartPresetValue.*)
		HoldOut : BOOL; (*Freezes the function block.*)
		TrackingValue : REAL; (*Manipulated variable for manual mode.*)
		EnableTracking : BOOL; (*Enables manual mode.*)
		HoldIntegration : MTPIDIntegrationEnum; (*The integral component is kept depending on the direction.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Controller output. Value range: MinOut <= Out <= MaxOut.*)
		ControlError : REAL; (*Control error.*)
		ProportionalPart : REAL; (*Proportional component.*)
		IntegrationPart : REAL; (*Integral component.*)
		DerivativePart : REAL; (*Derivative component.*)
		TrackingActive : BOOL; (*Tracking is active.*)
		IntegrationStatus : MTPIDIntegrationEnum; (*Information about the current state of the integral component.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsPIDInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsPT1 (*First-order delay element.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Gain : REAL; (*Gain factor.*)
		TimeConstant : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
		OutPresetValue : REAL; (*Preset value for Out output.*)
		SetOut : BOOL; (*Sets Out to OutPresetValue on rising edge.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsPT1InternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsPT2 (*Second-order delay element.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Gain : REAL; (*Gain.*)
		TimeConstant1 : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant1 >= 0.*)
		TimeConstant2 : REAL; (*Time constant. Unit: [s]. Valid value range: TimeConstant2 >= 0.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		In : REAL; (*Input value.*)
		OutPresetValue : REAL; (*Preset value for Out output.*)
		SetOut : BOOL; (*Sets Out to OutPresetValue on rising edge.*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value.*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*)
	END_VAR
	VAR
		Internal : MTBasicsPT2InternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsPWM (*Pulse width modulator.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Mode : MTBasicsPWMModeEnum; (*Pulse mode.*)
		MinPulseWidth : REAL; (*Minimum duration of the output actuator pulses and pauses. Unit: [s]. Valid value range: MinPulseWidth < Period.*)
		Period : REAL; (*Period for the output actuator pulses. Unit: [s]. Valid value range: Period > task cycle time.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		DutyCycle : REAL; (*Input value. Unit: [%]. Valid value range: 0 <= DutyCycle <= 100.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : BOOL; (*Output value.*)
	END_VAR
	VAR
		Internal : MTBasicsPWMInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} FUNCTION_BLOCK MTBasicsPWMSchedule (*Multiple pulse width modulator.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		Period : REAL; (*Period for the output actuator pulses. Unit: [s]. Permitted range of values: Period > Task cycle time.*)
		MinPulseWidth : REAL; (*Minimum duration of the pulses. Unit: [s]. Permitted range of values: Task cycle time <= MinPulseWidth < Period.*)
		MinPause : REAL; (*Minimum duration of the pauses. Unit: [s]. Permitted range of values: Task cycle time <= MinPause < Period.*)
		Mode : MTBasicsPWMScheduleModeEnum; (*Pulse mode.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		NumberOfInputs : UINT; (*Number of input signals. Permitted range of values: 0 < NumberOfInputs <= 500.*)
		DutyCycle : {REDUND_UNREPLICABLE} UDINT; (*Address of an array of data type REAL with the duty cycles. Unit of the values of the array: [%]. Permitted range of values for the values of the assigned array: 0 <= DutyCycle[i] <= 100.*)
		ZonePower : {REDUND_UNREPLICABLE} UDINT; (*Address of an array of data type REAL with the power of the zones. Unit of the values of the array: [kW]. Permitted range of values for the values of the assigned array: ZonePower[i] > 0.*)
		MaxAveragePower : REAL; (*Maximum allowed average power of all zones per period. Unit: [kW]. Permitted range of values: MaxAveragePower > 0.*)
		EnablePowerLimitation : BOOL; (*The power limitation is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		PulseWave : {REDUND_UNREPLICABLE} UDINT; (*Address of an array of data type BOOL with the pulses.*)
		LimitedDutyCycle : {REDUND_UNREPLICABLE} UDINT; (*Address of an array of data type REAL with the limited duty cycles. Unit of the values of the array: [%].*)
		OutputPower : REAL; (*Average power of all zones per period. Unit: [kW].*)
		RequiredPower : REAL; (*Required power of all zones per period. Unit: [kW].*)
		PowerLimitationActive : BOOL; (*The power limitation is active.*)
		InLimitation : BOOL; (*The power of each zone is limited.*)
	END_VAR
	VAR
		Internal : MTBasicsPWMScheduleInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsStepTuning (*Step tuning for PID.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		SystemSettlingTime : REAL; (*System settling time.*)
		MaxTuningTime : REAL; (*Maximum tuning time*)
		MinActValue : REAL; (*Minimum value of the controlled variable.*)
		MaxActValue : REAL; (*Maximum value of the controlled variable.*)
		Update : BOOL; (*Updates the parameters listed above on a rising edge.*)
		ActValue : REAL; (*Actual measured value.*)
		StepHeight : REAL; (*Height of step to be applied.*)
		Start : BOOL; (*Starts the tuning (on positive edge).*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		UpdateDone : BOOL; (*Update is done.*)
		Out : REAL; (*Output value (manipulated variable). Value range: MinOut <= Out <= MaxOut.*)
		TuningActive : BOOL; (*Tuning is active.*)
		TuningDone : BOOL; (*Tuning completed.*)
		PIDParameters : MTPIDParametersType; (*PID parameters.*)
		Quality : REAL; (*Quality of the step tuning. Unit: [%]. Value range: 0 (low) ... 100 (high).*)
		TuningState : MTBasicsStepTuningStateEnum; (*Current state of the tuning procedure.*)
	END_VAR
	VAR
		Internal : MTBasicsStepTuningInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} FUNCTION_BLOCK MTBasicsTimeDelay (*Delay element.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enables/Disables the function block.*)
		DelayTime : REAL; (*Delay time. Unit: [s]. Valid value range: 0 <= DelayTime <= "10000 · task cycle time".*)
		In : REAL; (*Input value.*)
		InitialValue : REAL; (*Initial value for Out output.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Indicates an error.*)
		StatusID : DINT; (*Status information.*)
		Out : REAL; (*Output value.*)
	END_VAR
	VAR
		Internal : MTBasicsTimeDelayInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK MTBasicsTransferFcn (*This function block implements a general continuous transfer function G(s). Optional it is possible to implement a discrete transfer function G(z) with DiscreteSampleTime > 0.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enable function block.*) (* *) (*#PAR#*)
		Numerator : ARRAY[0..5] OF REAL; (*Coefficients of numerator [b0, b1, b2, ... bn].*) (* *) (*#PAR#*)
		Denominator : ARRAY[0..5] OF REAL; (*Coefficients of denominator [a0, a1, a2, ... an].*) (* *) (*#PAR#*)
		Mode : MTBasicsTransferFcnModeEnum; (*Mode for transfer function: mtBASICS_CONTINUOUS_TRANSFER_FCN ... continuous transfer fcn; mtBASICS_DISCRETE_TRANSFER_FCN ... discrete transfer function.*) (* *) (*#PAR#OPT#*)
		Update : BOOL; (*Parameters update trigger.*) (* *) (*#PAR#*)
		In : REAL; (*Input variable.*) (* *) (*#CYC#*)
		OutPresetValue : REAL; (*Preset value for Out.*) (* *) (*#CMD#OPT#*)
		SetOut : BOOL; (*Sets Out to OutPresetValue on rising edge.*) (* *) (*#CMD#OPT#*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is working.*) (* *) (*#PAR#*)
		Active : BOOL; (*Function block is active.*) (* *) (*#PAR#*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#PAR#*)
		StatusID : DINT; (*Status information.*) (* *) (*#PAR#*)
		UpdateDone : BOOL; (*Update is sucessful.*) (* *) (*#PAR#*)
		Out : REAL; (*Output variable.*) (* *) (*#CYC#*)
		SystemReference : {REDUND_UNREPLICABLE} UDINT; (*System reference.*) (* *) (*#CMD#OPT#*)
	END_VAR
	VAR
		Internal : MTBasicsTransferFcnInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK
