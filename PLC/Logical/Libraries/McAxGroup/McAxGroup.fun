
FUNCTION_BLOCK MC_BR_ConditionalStop
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		Identifier : UDINT; (*Conditional stop identifier*)
		Deactivate : BOOL; (*Disables a conditional stop / Resumes a program interrupted by a conditional stop*)
		Reactivate : BOOL; (*Re-enables a conditional stop*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Programmed : BOOL; (*Conditional stop programmed*)
		Activated : BOOL; (*Conditional stop set to interrupt the program*)
		Interrupting : BOOL; (*Conditional stop interrupting the program*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupCommandError
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Command : McErrorCmdEnum; (*Error command*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupHome_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Position : ARRAY[0..14] OF LREAL; (*Array of positions in ACS coordinate system order.*)
		HomingMode : ARRAY[0..14] OF McHomingModeEnum; (*Array of homing modes in ACS coordinate system order.*)
		AdvancedParameters : McAdvGroupHome_15_Type; (*Additional parameters.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupBrakeOperation
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of this function block is started on rising edge of the input*)
		Command : McBrakeCmdEnum; (*Brake command input*)
		SelectMode : McBrakeSelectModeEnum; (*Mode for selecting the brake*)
		Identifier : UDINT; (*Identifier for the brake*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		BrakeStatus : McBrakeStatusEnum; (*shows the brake status*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupJogAbsolute_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		JogPosition : ARRAY[0..14] OF LREAL; (*Target position for the movement [Measurement units]*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		Jog : BOOL; (*Movement being performed*)
	END_VAR
	VAR_OUTPUT
		Ready : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		JogStatus : McJogStatusEnum; (*Jog state*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupJogRelative_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		JogDistance : ARRAY[0..14] OF LREAL; (*Traverse path for the movement [Measurement units]*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		Jog : BOOL; (*Movement being performed*)
	END_VAR
	VAR_OUTPUT
		Ready : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		JogStatus : McJogStatusEnum; (*Jog state*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupJogVelocity_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		JogVelocity : ARRAY[0..14] OF REAL; (*Velocity of the movement [Measurement units/s]*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		Jog : BOOL; (*Movement being performed*)
	END_VAR
	VAR_OUTPUT
		Ready : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		JogStatus : McJogStatusEnum; (*JogStatus*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupMoveCyclicPosition_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		CoordSystem : UDINT; (*Coordinate system*)
		DisableAxis : ARRAY[0..14] OF BOOL; (*Individual axes can be excluded from the movement*)
		InterpolationMode : McIplModeEnum; (*Defines the type of interpolation*)
		AdvancedParameters : ARRAY[0..14] OF McAdvMoveCycParType; (*Made up of velocity, acceleration, deceleration and the enabling of single axes.*)
		CyclicPosition : ARRAY[0..14] OF LREAL; (*Array [0..14] for the cyclic positions in the selected coordinate system*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupPower
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*Turns drive power stages on/off*)
	END_VAR
	VAR_OUTPUT
		Status : BOOL; (*Indicates whether all axes in the group are on*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupReadCyclicPosition_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		CoordSystem : UDINT; (*Coordinate system*)
		ValueSource : McValueSrcEnum; (*selection which position should be read*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		CyclicPosition : ARRAY[0..14] OF LREAL; (*Current positions in the specified coordinate system.*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupReadInfo
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		CommunicationReady : BOOL; (*"Network" is initialized and ready for communication*)
		ReadyForPowerOn : BOOL; (*Controllers for all axes in the group are ready to be switched on*)
		PowerOn : BOOL; (*Controllers for all axes in the group are switched on*)
		IsHomed : BOOL; (*All axes in the group are homed*)
		AdditionalInfo : McAddGroupReadInfoType; (*Additional information*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GroupSetOverride
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		Type : McOverrideEnum; (*Effect of override*)
		Factor : REAL; (*Override factor*)
	END_VAR
	VAR_OUTPUT
		Enabled : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MFunction
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		MFunction : UDINT; (*M-function of the function*)
		Reset : BOOL; (*Resets the M-function*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Value : BOOL; (*Current value of the M-function*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveBlock
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Block : STRING[260]; (*Single instruction*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveProgram
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Name : STRING[260]; (*Program name*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
		AdvancedParameters : McPrgAdvParType; (*Additional parameters for starting the program and repositioning the axes*)
		Continue : BOOL; (*Execution of the function block continues on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Phase : McPrgPhaseEnum; (*Indicates the current phase of the program.*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_PathInfo
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		PathInfo : McPathInfoType; (*Path information*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ProgramInfo
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		ProgramInfo : McPrgInfoType; (*Program information*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SingleStep
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		AdvancedParameters : McSingleStepAdvParType; (*Additional parameters.*)
		Continue : BOOL; (*An interrupted motor chain module is continued.*)
	END_VAR
	VAR_OUTPUT
		Enabled : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Interrupted : BOOL; (*The motion chain module is interrupted.*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_OptionalStop
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		Continue : BOOL; (*Resumes a program that was interrupted by an optional stop.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Programmed : BOOL; (*Optional stop is programmed.*)
		Interrupting : BOOL; (*The program is currently interrupted due to an optional stop.*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_OnlinePathInfluence_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		CoordSystem : UDINT; (*Coordinate system*)
		PositionOffset : ARRAY[0..14] OF LREAL; (*Position offset*)
	END_VAR
	VAR_OUTPUT
		Enabled : BOOL; (*Function block has been enabled and is active.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupContinue
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupDisable
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupEnable
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupInterrupt
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupReadActualPosition_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		CoordSystem : UDINT; (*Coordinate system*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Position : ARRAY[0..14] OF LREAL; (*Current position in the specified coordinate system.*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupReadError
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		ReadNext : BOOL; (*Reads the next pending error*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		GroupErrorID : DINT; (*Group error number*)
		RecordID : UDINT; (*Error ID in the event logger*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupReadStatus
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		GroupMoving : BOOL; (*State of the group (see *)
		GroupHoming : BOOL; (*State of the group (see *)
		GroupErrorStop : BOOL; (*State of the group (see *)
		GroupStandby : BOOL; (*State of the group (see *)
		GroupStopping : BOOL; (*State of the group (see *)
		GroupDisabled : BOOL; (*State of the group (see *)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupReset
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GroupStop
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		StopMode : McStopModeEnum :=1; (*Stop mode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetToolPar
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		ToolParameters : McToolParType; (*Geometric parameters for tools to set*)
		ExecutionMode : McExecutionModeEnum; (*Execution Mode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetToolTable
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Name : STRING[250]; (*Name of tool table*)
		ToolIdentifier : STRING[250]; (*Identifier of initial tool to be activated*)
		ExecutionMode : McExecutionModeEnum; (*Error command*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetFrameTableFrame
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		CoordSystem : UDINT; (*Coordinate system*)
		Name : STRING[250]; (*Name of frame table*)
		Index : UINT; (*Frame index*)
		ExecutionMode : McExecutionModeEnum; (*Error command*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetStandardFrame
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		CoordSystem : UDINT; (*Coordinate system*)
		Frame : McFrameType; (*Frame*)
		ExecutionMode : McExecutionModeEnum; (*Error command*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveDirectAbsolute_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Position : ARRAY[0..14] OF LREAL; (*Array[0..N-1] of absolute end positions in every dimension of the selected coordinate system.*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveDirectRelative_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Distance : ARRAY[0..14] OF LREAL; (*Array[0..N-1] of relative distances in every dimension of the selected coordinate system.*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveLinearAbsolute_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Position : ARRAY[0..14] OF LREAL; (*Array[0..N-1] of absolute end positions in every dimension of the selected coordinate system.*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK


FUNCTION_BLOCK MC_MoveLinearRelative_15
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Distance : ARRAY[0..14] OF LREAL; (*Array[0..N-1] of relative distances in every dimension of the selected coordinate system.*)
		Velocity : REAL; (*Maximum path velocity [application units/s]*)
		Acceleration : REAL; (*Maximum path acceleration [application units/s²]*)
		Deceleration : REAL; (*Maximum path deceleration [application units/s²]*)
		Jerk : REAL; (*Maximum path jerk [application units/s³]*)
		CoordSystem : UDINT; (*Coordinate system*)
		BufferMode : McBufferModeEnum; (*Defines the chronological order of the function block and the preceding function block.*)
		TransitionMode : McTransitionModeEnum; (*Defines the transition from the preceding function block.*)
		TransitionParameter : LREAL; (*Additional parameter for TransitionMode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis group.*)
		CommandAborted : BOOL; (*Command aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_UnloadProgram
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Name : STRING[260]; (*Program name*)
		Mode : McUnloadProgramModeEnum; (*Defines which programs should be unloaded.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LoadProgram
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Name : STRING[260]; (*Program name*)
		Mode : McLoadProgramModeEnum; (*Defines behavior of loaded program.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_VelLimitMonPoints
	VAR_INPUT
		AxesGroup : REFERENCE TO McAxesGroupType; (*The axis group reference establishes the connection between the function block and the axis group.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
		Parameter : McLimitMonPointsParType; (*Limitation parameters*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		LimitInfo : McLimitMonPointsInfoType; (*Info about current Limitation*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

