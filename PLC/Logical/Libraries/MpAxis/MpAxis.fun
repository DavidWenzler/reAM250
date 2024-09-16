
FUNCTION_BLOCK MpAxisBasic
	VAR_INPUT
		MpLink : REFERENCE TO McAxisType; (*The axis reference creates a link between the function block and an axis.*) (* *) (*#PAR#;*)
		Enable : BOOL; (*The function block is active as long as this input is set.*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Used to reset errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisBasicParType; (*Parameters of the function block*) (* *) (*#PAR#;*)
		Update : BOOL; (*Updates the parameters*) (* *) (*#PAR#;*)
		Power : BOOL; (*Level-sensitive command for turning an axis on/off. In the event of an error, a new rising edge is required to restart the axis.*) (* *) (*#CMD#;*)
		Home : BOOL; (*Command for homing the axis*) (* *) (*#CMD#;*)
		MoveVelocity : BOOL; (*Starts a constant movement with a defined velocity*) (* *) (*#CMD#;*)
		MoveAbsolute : BOOL; (*Starts an absolute movement*) (* *) (*#CMD#;*)
		MoveAdditive : BOOL; (*Starts a relative movement*) (* *) (*#CMD#;*)
		Stop : BOOL; (*Stops the axis*) (* *) (*#CMD#;*)
		JogPositive : BOOL; (*Movement in the positive direction. Stops automatically at the software limit position.*) (* *) (*#CMD#OPT#;*)
		JogNegative : BOOL; (*Movement in the negative direction. Stops automatically at the software limit position.*) (* *) (*#CMD#OPT#;*)
		LimitLoad : BOOL; (*Enables torque limitation*) (* *) (*#CMD#OPT#;*)
		ReleaseBrake : BOOL; (*Releases the brake (but only when the motor is switched off)*) (* *) (*#CMD#OPT#;*)
		Simulate : BOOL; (*Switch on or off simulation. This command is available from version 5.15.0 .*) (* *) (*#CMD#OPT#;*)
		AutoTune : BOOL; (*Start automatic tuning procedue. This command is available from version 5.15.0 .*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Error occurred during operation*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		Position : LREAL; (*Current position of the axis [measurement units]*) (* *) (*#CYC#;*)
		Velocity : REAL; (*Current speed of the axis [measurement units/s]*) (* *) (*#CYC#;*)
		CommandBusy : BOOL; (*Function block currently executing a command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		PowerOn : BOOL; (*Axis switched on*) (* *) (*#CMD#;*)
		IsHomed : BOOL; (*Axis referenced*) (* *) (*#CMD#;*)
		InVelocity : BOOL; (*Axis running with defined velocity*) (* *) (*#CMD#;*)
		InPosition : BOOL; (*Axis reached the desired position*) (* *) (*#CMD#;*)
		MoveActive : BOOL; (*Movement active*) (* *) (*#CMD#;*)
		MoveDone : BOOL; (*Movement complete*) (* *) (*#CMD#;*)
		Stopped : BOOL; (*Axis stopped*) (* *) (*#CMD#;*)
		LimitLoadReady : BOOL; (*Torque limitation ready*) (* *) (*#CMD#OPT#;*)
		BrakeReleased : BOOL; (*Brake released*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisBasicInfoType; (*Additional information*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisCamSequencer (*Flexibly sequence various (user-defined or predefined) cam profiles together*) (* $GROUP=mapp,$CAT=Multi Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis1.png *)
	VAR_INPUT
		MpLink : REFERENCE TO McAxisType; (*Connection to mapp, slave axis for the coupling*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisCamSequencerParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Update command for the parameters*) (* *) (*#PAR#;*)
		MpLinkMaster : REFERENCE TO McAxisType; (*Master axis for the coupling*) (* *) (*#PAR#;*)
		Signal1 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#OPT#;*)
		Signal2 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#OPT#;*)
		Signal3 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#OPT#;*)
		Signal4 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#OPT#;*)
		StartSequence : BOOL; (*Start a sequence on positive edge and stops at negative edge*) (* *) (*#CMD#;*)
		Continue : BOOL; (*Restart cam sequence*) (* *) (*#CMD#;*)
		EndSequence : BOOL; (*Ends cam sequence*) (* *) (*#CMD#;*)
		GetSequence : BOOL; (*Get cam sequence parameters*) (* *) (*#CMD#OPT#;*)
		ParLock : BOOL; (*ParLock command*) (* *) (*#CMD#OPT#;*)
		OffsetShift : BOOL; (*Starts a phase shift to the slave position (offset)
*) (* *) (*#CMD#OPT#;*)
		PhaseShift : BOOL; (*Starts a phase shift to the master position with which the slave is working (phase); the master remains unaffected
*) (* *) (*#CMD#OPT#;*)
		CamPrepare : BOOL; (*Initializes CamList*) (* *) (*#CMD#OPT#;*)
		Recovery : BOOL; (*Recover to a defined cam position after a stop*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		ActualStateIndex : USINT; (*Actual sequence state index*) (* *) (*#CYC#;*)
		ActualStateCamIndex : UINT; (*Actual state cam index*) (* *) (*#CYC#;*)
		Running : BOOL; (*Cam sequence running*) (* *) (*#CYC#;;*)
		Standby : BOOL; (*Cam sequence standby*) (* *) (*#CYC#OPT#;*)
		InCompensation : BOOL; (*Axis currently performing a compensating movement*) (* *) (*#CYC#OPT#;*)
		InCam : BOOL; (*Slave synchronous with the master*) (* *) (*#CYC#OPT#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		GetSequenceDone : BOOL; (*Get parameters done*) (* *) (*#CMD#OPT#;*)
		ParLockDone : BOOL; (*ParLock command done*) (* *) (*#CMD#OPT#;*)
		OffsetDone : BOOL; (*Shift to slave position performed successfully*) (* *) (*#CMD#OPT#;*)
		PhasingDone : BOOL; (*Shift to the master position with which the slave is following performed successfully*) (* *) (*#CMD#OPT#;*)
		CamPrepareDone : BOOL; (*CamPrepare executed successfully*) (* *) (*#CMD#OPT#;*)
		RecoveryDone : BOOL; (*Rocvery executed successfully*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisCamSequencerInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisCoupling (*Flexibly sequence various (user-defined or predefined) cam profiles together*) (* $GROUP=mapp,$CAT=Multi Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis1.png *)
	VAR_INPUT
		MpLink : REFERENCE TO McAxisType; (*Connection to mapp, slave axis for the coupling*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisCouplingParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Update command for the parameters*) (* *) (*#PAR#;*)
		MpLinkMaster : REFERENCE TO McAxisType; (*Master axis for the coupling*) (* *) (*#PAR#;*)
		Gear : BOOL; (*Starts a Gear command*) (* *) (*#CMD#;*)
		Cam : BOOL; (*Starts a Cam command*) (* *) (*#CMD#;*)
		GearInPos : BOOL; (*Starts a Gear command*) (* *) (*#CMD#;*)
		OffsetShift : BOOL; (*Starts a phase shift to the slave position (offset)
*) (* *) (*#CMD#OPT#;*)
		PhaseShift : BOOL; (*Starts a phase shift to the master position with which the slave is working (phase); the master remains unaffected
*) (* *) (*#CMD#OPT#;*)
		GetCamPosition : BOOL; (*Get position of master or slave axis based on defined cam*) (* *) (*#CMD#OPT#;*)
		CamPrepare : BOOL; (*Initializes CamList*) (* *) (*#CMD#OPT#;*)
		Recovery : BOOL; (*Recover to a defined cam position after a stop*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		InCompensation : BOOL; (*Axis currently performing a compensating movement*) (* *) (*#CMD#;*)
		InSync : BOOL; (*Slave synchronous with the master*) (* *) (*#CMD#;*)
		OffsetDone : BOOL; (*Shift to slave position performed successfully*) (* *) (*#CMD#OPT#;*)
		PhasingDone : BOOL; (*Shift to the master position with which the slave is following performed successfully*) (* *) (*#CMD#OPT#;*)
		RecoveryDone : BOOL; (*Rocvery executed successfully*) (* *) (*#CMD#OPT#;*)
		GetCamPositionDone : BOOL; (*GetCamPosition executed successfully*) (* *) (*#CMD#OPT#;*)
		CamPrepareDone : BOOL; (*CamPrepare executed successfully*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisCouplingInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK
