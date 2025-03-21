FUNCTION_BLOCK MC_BR_ProcessConfig
	VAR_INPUT
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Name: STRING[250]; (*Name of config element*)
		DataType: UDINT; (*Datatype of the structure element*)
		DataAddress: UDINT; (*Reference to the selected data structure*)
		Mode : McProcessConfigModeEnum; (*references establishing connection between the function block and the axis group, axes etc.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ProcessParam
	VAR_INPUT
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Component: McComponentType; (*Reference to the component*)
		DataType: UDINT; (* Datatype of the structure element*)
		DataAddress: UDINT; (*Reference to the selected data structure*)
		Mode : McProcessParamModeEnum;
		AdvancedParameters :    McProcessParamAdvParType;
		ExecutionMode : McExecutionModeEnum;
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK



FUNCTION_BLOCK MC_BR_GetCoordSystemIdent
	VAR_INPUT
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		CoordSystemName : STRING[260]; (*frame name*)
		Parameter : McGetCoordSystemIdentParType; (*references establishing connection between the function block and the axis group, axes etc.*)

	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		Ident : UDINT; (*coordinate system ident*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

