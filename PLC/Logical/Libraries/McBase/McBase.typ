TYPE
	(*Enum types*)
	McAxisPLCopenStateEnum :
	(
		mcAXIS_DISABLED, (*Power output stage is off*)
		mcAXIS_STANDSTILL, (*Power output stage on; Axis not moving*)
		mcAXIS_HOMING, (*Axis is executing a homing procedure*)
		mcAXIS_STOPPING, (*Axis currently stopping or "Execute" is still set for "MC_Stop"*)
		mcAXIS_DISCRETE_MOTION, (*Movement with defined end position active*)
		mcAXIS_CONTINUOUS_MOTION, (*Movement without defined end position active until aborted by other command*)
		mcAXIS_SYNCHRONIZED_MOTION, (*Axis is coupled to another axis (master-slave coupling)*)
		mcAXIS_ERRORSTOP, (*Axis stopped due to drive error*)
		mcAXIS_STARTUP, (*Axis is in startup phase*)
		mcAXIS_INVALID_CONFIGURATION (*An error in the configuration of the axis occured*)
	);

	McGroupPLCopenStateEnum :
	(
		mcGROUP_DISABLED, (*Axis group disabled*)
		mcGROUP_HOMING, (*Axis group is executing a homing procedure*)
		mcGROUP_STANDBY, (*Axis group has been stopped*)
		mcGROUP_MOVING, (*Axis group is performing a movement*)
		mcGROUP_STOPPING, (*Axis group currently stopping or "Execute" is still set for "MC_GroupStop"*)
		mcGROUP_ERRORSTOP, (*Axis group stopped due to an error*)
		mcGROUP_STARTUP, (*Axis group is in startup phase*)
		mcGROUP_INVALID_CONFIGURATION (*An error in the configuration of the axis group occured*)
	);

	McBufferModeEnum :
	(
		mcABORTING, (*Default mode without buffering. The function block aborts an active movement. The buffer is cleared*)
		mcBUFFERED, (*The movement is started as soon as the previous movement is completed. No smoothing is applied*)
		mcBLENDING_LOW, (*The velocity is blended with the lowest velocity of both FBs*)
		mcBLENDING_PREVIOUS, (*The velocity is blended with the velocity of the first FB*)
		mcBLENDING_NEXT, (*The velocity is blended with velocity of the second FB*)
		mcBLENDING_HIGH	(*The velocity is blended with highest velocity of both FBs*)
	);

	McBrakeCmdEnum :
	(
		mcBRAKE_CLOSE,					 (*Engages the brake*)
		mcBRAKE_OPEN,					 (*Releases the brake*)
		mcBRAKE_GET_STATUS				 (*Reads out the current brake status*)
	);

	McBrakeStatusEnum :
	(
		mcBRAKE_STATUS_NOT_PROVIDED,	 (*Commands was not *)
		mcBRAKE_CLOSED,					 (*Holding brake engaged*)
		mcBRAKE_OPENED					 (*Holding brake released*)
	);

	McHomingModeEnum :
	(
		mcHOMING_DIRECT := 0,			 (*Direct homing. "Position" is used directly as the new axis position*)
		mcHOMING_SWITCH_GATE,			 (*Homing with reference gate*)
		mcHOMING_ABSOLUTE_SWITCH,		 (*Performs homing with absolute reference switch*)
		mcHOMING_LIMIT_SWITCH := 4,	     (*Homing with hardware limit switch*)
		mcHOMING_ABSOLUTE,				 (*Homing by setting the "Position" homing offset for an absolute encoder*)
		mcHOMING_DCM := 7,				 (*Homing using interval-encoded reference marks*)
		mcHOMING_BLOCK_TORQUE := 9,	     (*Performs homing to mechanical limit, torque as criteria*)
		mcHOMING_BLOCK_LAG_ERROR := 10,	 (*Performs homing to mechanical limit, lag error as criteria*)
		mcHOMING_ABSOLUTE_INTERNAL := 11,(*Performs homing with homing offset, which is determined by drive*)
		mcHOMING_ABSOLUTE_CORRECTION := 133,  (*Homing by setting the "Position" homing offset for an absolute encoder with counter range correction. This mode must be used if the overflow of the absolute encoder is within the axis range of movement*)
		mcHOMING_DCM_CORRECTION := 135,	 (*Homing using distance-coded reference marks with counting range correction*)
		mcHOMING_DEFAULT := 140,		 (*All parameters, including "Position", are taken from the initial configuration for the axis*)
		mcHOMING_INIT,					 (*All parameters, including "Position", are taken from an earlier initialization made using function block MC_BR_InitHome*)
		mcHOMING_RESTORE_POSITION		 (*Restores position from a remanent variable*)
	);

	McStopModeEnum :
	(
		mcSTOPMODE_JERK_LIMIT,			 (*Takes into account the jerk limit value while stopping*)
		mcSTOPMODE_NO_JERK_LIMIT		 (*Ignores the jerk limit value while stopping*)
	);

	McIplModeEnum :
	(
		mcIPLM_DEFAULT,					 (*The most suitable available interpolation is used*)
		mcIPLM_OFF,						 (*Interpolation off*)
		mcIPLM_LINEAR,					(*linear interpolation*)
		mcIPLM_QUADRATIC,				(*quadratic interpolation*)
		mcIPLM_QUADRATIC_NO_OVERSHOOT	(*quadratic interpolation without overshoot*)
	);

	McErrorCmdEnum :
	(
		mcWARNING_CMD := 0,  (*A warning is generated *)
		mcERROR_CMD,  (*An error is entered*)
		mcERROR_STOP_CMD,  (*Generates an error and ends an active movement*)
		mcERROR_STOP_CTRL_OFF_CMD,  (*Generates an error, ends any active movements and switches off the controller*)
		mcERROR_V_STOP_CTRL_OFF_CMD,  (*Generates an error, ends any active movements with a speed-controlled ramp and switches off the controller*)
		mcERROR_COAST_TO_STANDSTILL_CMD,  (*Generates an error, any active movements coast to a stop when controller switched off*)
		mcERROR_INDUCTION_HALT_CMD  (*Generates an axis error on the drive, movements are stopped with an induction stop of the controller*)
	);

	McEdgeEnum :
	(
		mcEDGE_POSITIVE, (*Selection for the rising edge*)
		mcEDGE_NEGATIVE, (*Selection for the falling edge*)
		mcEDGE_MIDDLE (* Middle position between positive and negative edge*)
	);

	McNetworkTypeEnum :
	(
		mcNETWORK_POWERLINK	 (*POWERLINK protocol*)
	);

	McTransitionModeEnum :
		( (*FB internals*)
		mcTM_NONE (*No transition is added*)
		);

	McExecutionModeEnum:
	(
	mcEM_IMMEDIATELY
	);

	McCoordinateSystemEnum :
	(
		mcACS := 0,	 (*Axis coordinate system*)
		mcMCS := 1,	 (*Machine coordinate system*)
		mcPCS := 2,	 (*Product coordinate system*)
		mcSCS1 := 3,	 (*System coordinate system 1*)
		mcSCS2 := 4,	 (*System coordinate system 2*)
		mcSCS3 := 5,	 (*System coordinate system 3*)
		mcSCS4 := 6,	 (*System coordinate system 4*)
		mcSCS5 := 7,	 (*System coordinate system 5*)
		mcTCS := 9,	 (*Tool coordinate system*)
		mcGCS := 10,	 (*Global coordinate system*)
		mcJACS := 100	 (*Joint axes coordinate system*)
	);

	McValueSrcEnum :
	(
		mcVALUE_SET, 					(*Position setpoint value [Measurement units]*)
		mcVALUE_ACTUAL,					(*Actual position value [Measurement units]*)
		mcVALUE_SET_AXIS_UNITS,			(*Position setpoint value [axis units]*)
		mcVALUE_ACTUAL_AXIS_UNITS,		(*Actual value for position [axis units]*)
		mcVALUE_AUTOMATIC_SELECTION,	(*The value for the source is selected automatically in relation to the active controller mode*)
		mcVALUE_ALT1,					(*"Value source 1" of the feature "Alternative value source" is used*)
		mcVALUE_ALT2,					(*"Value source 2" of the feature "Alternative value source" is used*)
		mcVALUE_ALT3,					(*"Value source 3" of the feature "Alternative value source" is used*)
		mcVALUE_ALT4,					(*"Value source 4" of the feature "Alternative value source" is used*)
		mcVALUE_ALT5,					(*"Value source 5" of the feature "Alternative value source" is used*)
		mcVALUE_ALT6,					(*"Value source 6" of the feature "Alternative value source" is used*)
		mcVALUE_ALT7,					(*"Value source 7" of the feature "Alternative value source" is used*)
		mcVALUE_ALT8					(*"Value source 8" of the feature "Alternative value source" is used*)
	);

	McAltValueSrcEnum :
	(
		mcALT_VALUE_NOT_USED := 0,	(*No alternative value source is used*)
		mcALT_VALUE1 := 1,			(*"Value source 1" of the feature "Alternative value source" is used*)
		mcALT_VALUE2 := 2,			(*"Value source 2" of the feature "Alternative value source" is used*)
		mcALT_VALUE3 := 3,			(*"Value source 3" of the feature "Alternative value source" is used*)
		mcALT_VALUE4 := 4,			(*"Value source 4" of the feature "Alternative value source" is used*)
		mcALT_VALUE5 := 5,			(*"Value source 5" of the feature "Alternative value source" is used*)
		mcALT_VALUE6 := 6,			(*"Value source 6" of the feature "Alternative value source" is used*)
		mcALT_VALUE7 := 7,			(*"Value source 7" of the feature "Alternative value source" is used*)
		mcALT_VALUE8 := 8			(*"Value source 8" of the feature "Alternative value source" is used*)
	);

	McSwitchEnum :
	(
		mcSWITCH_OFF,		 (*State/Behavior selection switched off*)
		mcSWITCH_ON			 (*State/Behavior selection switched on*)
	);

	McProcessParamModeEnum:
	(
		mcPPM_READ,		 			(*Reads Parameterization*)
		mcPPM_WRITE,	 			(*Write Parameterization*)
		mcPPM_LOAD_FROM_CONFIG,		(*Load P from Config*)
		mcPPM_SAVE_TO_CONFIG		(*Save P to Config*)
	);

	McProcessConfigModeEnum:
	(
		mcPCM_LOAD,	 (*Load from Config*)
		mcPCM_SAVE	 (*Save to Config*)
	);

	McCommunicationStateEnum :
	(
		mcCOMM_STATE_NOT_ACTIVE	:= 0,	(*The communication is not active*)
		mcCOMM_STATE_WAITING	:= 100,	(*Waiting for connection*)
		mcCOMM_STATE_CONNECTED	:= 200,	(*The connection is established*)
		mcCOMM_STATE_FW_UPDATE	:= 300,	(*A firmware update is in progress*)
		mcCOMM_STATE_CONFIG	:= 400,	(*The network configuration is transferred*)
		mcCOMM_STATE_ACTIVATING	:= 500,	(*The communication is activated*)
		mcCOMM_STATE_ACTIVE	:= 600,	(*The communication is active*)
		mcCOMM_STATE_INACTIVE	:= 700,	(*The communication is no longer active*)
		mcCOMM_STATE_FAILED	:= 1000	(*Initialization of the communication has failed*)
	);

	(*Structure types*)

	McAdvMoveCycParType : STRUCT
		Velocity : REAL; (*Maximum velocity [Measurement units/s]*)
		Acceleration : REAL; (*Maximum acceleration [Measurement units/s]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units/s]*)
		Jerk : REAL; (*Maximum jerk [measurement units / s³]*)
		DisableJoltLimitation : McSwitchEnum; (*Disable jolt limitation on the drive*)
		AlternativeValueSource : McAltValueSrcEnum; (*If used, defines the alternative source of cyclic: position for MC_BR_MoveCyclicPosition, velocity for MC_BR_MoveCyclicVelocity [axis Units]*)
	END_STRUCT;

	McOrientType : STRUCT
		Type : UDINT; (*Description of rotation*)
		Angle1 : LREAL; (*Angle of rotation 1 for describing the orientation*)
		Angle2 : LREAL; (*Angle of rotation 2 for describing the orientation*)
		Angle3 : LREAL; (*Angle of rotation 3 for describing the orientation*)
	END_STRUCT;

	McPosType : STRUCT
		X : LREAL; (*Offset in the direction of the x-axis*)
		Y : LREAL; (*Offset in the direction of the y-axis*)
		Z : LREAL; (*Offset in the direction of the z-axis*)
	END_STRUCT;

	McFrameType : STRUCT
		Pos : McPosType; (*Position in the coordinate system*)
		Orient : McOrientType; (*Orientation in the coordinate system*)
	END_STRUCT;

	(*FB internals*)

	McInternalType : STRUCT (*internal variable*)
		ID : UDINT; (**)
		Check : UDINT; (**)
		ParamHash : UDINT; (**)
		State : WORD; (**)
		Error : UINT; (**)
		Treating : REFERENCE TO McInternalFubProcessingType; (**)
		Memory : ARRAY[0..13] OF UDINT; (**)
		Flags : USINT; (**)
		ControlIf : REFERENCE TO McInternalControlIfType; (**)
		SeqNo : DINT; (**)
	END_STRUCT;

	McInternalFubProcessingType : 	STRUCT  (*Partial struct type (C only)*)
		states : ARRAY[0..1]OF DINT; (**)
	END_STRUCT;

	McInternalControlIfType : 	STRUCT  (*Partial interface type (C only)*)
		vtable : DWORD; (**)
	END_STRUCT;

	McInternalTwoRefType : 	STRUCT  (*internal variable*)
		Internal : McInternalType; (**)
		MaControlIf : REFERENCE TO McInternalControlIfType; (**)
		MaSeqNo : DINT; (**)
	END_STRUCT;

	McInternalMappLinkType : 	STRUCT  (*internal variable*)
		Internal : ARRAY[0..1]OF UDINT; (*Internal data*)
	END_STRUCT;

	McInternalMotionCfgIfType : 	STRUCT  (*Partial interface type (C only)*)
		vtable : DWORD; (**)
	END_STRUCT;

	McInternalAxisIfType : 	STRUCT  (*Partial interface type (C only)*)
		vtable : DWORD; (**)
	END_STRUCT;

	McInternalAxesGroupIfType : 	STRUCT  (*Partial interface type (C only)*)
		vtable : DWORD; (**)
	END_STRUCT;

	McInternalTrackingPathIfType : 	STRUCT  (*Partial interface type (C only)*)
		vtable : DWORD; (**)
	END_STRUCT;

	McExec1InternalType : STRUCT (*Internal structure-types for FB-processing*)
		i_serno : UINT;
		i_state : UINT;
		Result	: DINT;
		pInfo   : UDINT;
	END_STRUCT;

	(*Component References*)
	McMotionCfgType : 	STRUCT
		controlif : REFERENCE TO McInternalMotionCfgIfType; (**)
		mappLinkInternal : McInternalMappLinkType; (**)
	END_STRUCT;

	McAxisType : 	STRUCT
		controlif : REFERENCE TO McInternalAxisIfType; (**)
		mappLinkInternal : McInternalMappLinkType; (**)
		seqNo : DINT; (**)
	END_STRUCT;

	McPsmAxisType : McAxisType; (**)

	McApsmAxisType : McAxisType; (**)

	McConvoyType : McAxisType; (**)

	McAxesGroupType : 	STRUCT
		controlif : REFERENCE TO McInternalAxesGroupIfType; (**)
		mappLinkInternal : McInternalMappLinkType; (**)
	END_STRUCT;

	McTrackingPathType : 	STRUCT
		controlif : REFERENCE TO McInternalTrackingPathIfType; (**)
		mappLinkInternal : McInternalMappLinkType; (**)
	END_STRUCT;

	McGetCoordSystemIdentParType : STRUCT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
	END_STRUCT;

	McComponentType : UDINT;

	 McProcessParamAdvParType : STRUCT
		Name : STRING[250]; (*Name of the reference within the component which should be manipulated.*)
	END_STRUCT;

END_TYPE
