(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG
 ********************************************************************
 * Library: CoTrace
 * File:	CoTrace.fun
 ********************************************************************
 * Declaration of IEC-FBs of library CoTrace
 ********************************************************************)


{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigCreate (*This function is used to create a new blank trace configuration, which then can be configured using the following CoTraceConfig function blocks: CoTraceConfigSetTiming, CoTraceConfigAddDatapoint, CoTraceConfigAddStartTrigger, and CoTraceConfigOptionalParameter.
This function block is mandatory for obtaining a valid trace configuration.
By disabling this function block the configuration is being deleted and cannot be accessed any longer.
A specific configIdent can only be used for a single recordings of data. Thus, even if the settings should stay the same,
CoTraceConfigCreate and all CoTraceConfig function blocks have to be disabled and enabled again when rerunning a trace recording.

The following figure shows a connection scheme of CoTrace function blocks using the two types of idents, ConfigIdent and DataIdent.
DNE(<img src="CoTraceConfigCreate\IdentVerschaltungsSchema.png">)DNE *)
	VAR_INPUT
		Enable			: BOOL; (*Enabling this function block creates a new empty trace configuration.
Configuration settings are defined using the function blocks CoTraceConfigSetTiming, CoTraceConfigAddDatapoint, CoTraceConfigAddStartTrigger, and CoTraceConfigOptionalParameter.*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Active			: BOOL; (*The function block's output ConfigIdent can be used.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*This ident can be used by other function blocks of this library to define the trace configuration.*) (* *) (*#CMD*)
	END_VAR
	VAR
		Internal : CoTraceMemCtxInternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigLoad (*This function block is used to create a trace configuration by loading a (via AutomationStudio) pre-configured and transferred trace configuration. The loaded configuration can be manipulated using the FBs CoTraceConfigSetTiming, CoTraceConfigAddDataPoint, CoTraceConfigAddStart-Trigger and CoTraceConfigOptionalParameter.
This function block is an alternative to CoTraceConfigCreate to setup a valid trace configuration.

The following figure shows a connection scheme of CoTrace function blocks using the two types of idents, ConfigIdent and DataIdent.
DNE(<img src="CoTraceConfigCreate\IdentVerschaltungsSchema.png">)DNE *)
	VAR_INPUT
		Enable			: BOOL; (*Enabling this function block loads an existing trace configuration*) (* *) (*#PAR*)
		Name			: STRING[32]; (*Name of the trace configuration to be loaded*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Active			: BOOL; (*The function block's output ConfigIdent can be used.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*This ident can be used by a trace recorder function block and by other function blocks of this library to modify the trace configuration.*) (* *) (*#CMD*)
	END_VAR
	VAR
		Internal : CoTraceMemCtxInternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigSetTiming (*This function block allows to set the timing parameters of a trace configuration.
For a successful execution of this function block a CoTraceConfigCreate function block needs to be enabled and to provide a valid ConfigIdent as input.
This function block is required to obtain a valid trace configuration for recording.
This function block is executed synchronously.*)
	VAR_INPUT
		Execute 		: BOOL; (*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*The output "ConfigIdent" of an CoTraceConfigCreate function block has to be provided on the input.*) (* *) (*#PAR*)
		TotalRecordingTime : REAL; (*Overall record time span in seconds.*) (* *) (*#PAR*)
		TriggerOffsetTime : REAL; (*Offset-time between start of recording and trigger-event. Using a negative value for the TriggerOffsetTime allows to record values before a start trigger is detected.
 DNE(<img src="CoTraceConfigSetTiming\CoTraceSetTiming.png">)DNE
1... First start trigger is detected*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; (*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigOptionalParameter (*This function block allows to set optional trace configuration parameters for fine tuning.
For a successful execution of this function block a CoTraceConfigCreate function block needs to be enabled and to provide a valid ConfigIdent as input.
It is possible to add several parameter values to a trace configuration by executing this function block multiple times.
This function block is an optional part of a trace configuration.
This function block is executed synchronously.*)
	VAR_INPUT
		Execute 		: BOOL; (*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*The output "ConfigIdent" of an CoTraceConfigCreate function block has to be provided on the input.*) (* *) (*#PAR*)
		Parameter		: CoTraceConfigParamEnum; (*This input is used to select the parameter, that should be set.*) (* *) (*#PAR*)
		Value			: REAL; (*This input defines the value of the parameter.*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; (*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigAddDataPoint (*This function block allows to add a DataPoint to a trace configuration.
For a successful execution of this function block a CoTraceConfigCreate function block needs to be enabled and to provide a valid ConfigIdent as input.
It is possible to add several DataPoints to a trace configuration by executing this function block multiple times.
At least one DataPoint has to be added in order to obtain a valid trace configuration.

Limitations:
- A maximum of 10 DataPoints per ACOPOS channel/axis may be added.*)
	VAR_INPUT
		Execute 		: BOOL; (*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*The output "ConfigIdent" of an CoTraceConfigCreate function block has to be provided on the input.*) (* *) (*#PAR*)
		DataPointName	: STRING[767]; (*Fully qualified identification of the DataPoint that is to  be recorded.
For global variables on the PLC: "<variable name>"
For local variables on the PLC: "<program name>:<variable name>"

For DataPoints on ACOPOS drives: "*ACP:<network node/address>_Axis<channel number>:<parid number>" example: "*ACP:IF3.ST2_Axis1:355"

For global variables on the PLC in application modules: "<application module>::<variable name>"
For local variables on the PLC in application modules: "<application module>::<program name>:<variable name>" *) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; (*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT;	(*Status information*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceConfigAddStartTrigger (*This function block allows to add a start trigger to a trace configuration.
For a successful execution of this function block a CoTraceConfigCreate function block needs to be enabled and to provide a valid ConfigIdent as input.
This function block is an optional part of a trace configuration.
The start trigger can also be actuated manually using the "ForceStartTrigger" input of an CoTraceRecorder function block.

Limitations:
- Only one StartTrigger per ACOPOS channel/axis can be applied.*)
	VAR_INPUT
		Execute 		: BOOL; (*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*The output "ConfigIdent" of an CoTraceConfigCreate function block has to be provided on the input.*) (* *) (*#PAR*)
		DataPointName	: STRING[767]; (*Fully qualified identification of the DataPoint that is to  be recorded.
For global variables on the PLC: "<variable name>"
For local variables on the PLC: "<program name>:<variable name>"

For DataPoints on ACOPOS drives: "*ACP:<network node/address>_Axis<channel number>:<parid number>" example: "*ACP:IF3.ST2_Axis1:355"

For global variables on the PLC in application modules: "<application module>::<variable name>"
For local variables on the PLC in application modules: "<application module>::<program name>:<variable name>" *) (* *) (*#PAR*)
		Condition		: CoTraceTriggerConditionEnum; (*Defines the start trigger condition.*) (* *) (*#PAR*)
		Threshold		: REAL; (*Threshold, further information: DNE(<a xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg" href="Data types and constants\Enumerators\CoTraceTriggerConditionEnum.html">CoTraceTriggerConditionEnum</a>)DNE*) (* *) (*#PAR*)
		Window			: REAL; (*Window, further information: DNE(<a xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg" href="Data types and constants\Enumerators\CoTraceTriggerConditionEnum.html">CoTraceTriggerConditionEnum</a>)DNE*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; (*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceRecorder (*This function block records data according to the applied trace configuration.
When the recording is finished and the data is available the DataIdent is used as reference for the read-out by the function blocks CoTraceDataReadRecords or CoTraceDataSaveCsv.

Limitations:
- Only one instance of this function block can be recording at a certain time. As soon as DataAvailable is true, the usage of further instances associated with different ConfigIdents is possible.
- Only one instance of this function block can be enabled using a certain ConfigIdent and therefore being connected to a certain CoTraceConfigCreate function block.*)
	VAR_INPUT
		Enable			: BOOL; (*Once this function block is enabled, the trace configuration provided on the ConfigIdent input is installed automatically.
TraceRecords can only be read as long as this function block is enabled.
All recorded trace data, are deleted if this function block is disabled.*) (* *) (*#PAR*)
		ConfigIdent 	: CoTraceConfigIdentType; (*The output "ConfigIdent" of an CoTraceConfigCreate function block has to be provided on the input.*) (* *) (*#PAR*)
		ForceStartTrigger : BOOL; (*This level sensitive input can be used as a manual start trigger.
The configured "TriggerOffsetTime" is still active and may delay the start.
The output "WaitStartTrigger" needs to be TRUE for this input to have an effect.*) (* *) (*#CMD*)
		ForceStop		: BOOL; (*This level sensitive input forces the trace to stop the recording process immediately.
The output "WaitStopTrigger" needs to be TRUE for this input to have an effect.*) (* *) (*#CMD#OPT*)
	END_VAR
	VAR_OUTPUT
		Active			: BOOL; (*The function block is running.*) (* *) (*#PAR*)
		Busy			: BOOL; (*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; (*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; (*Status information*) (* *) (*#PAR*)
		DataIdent		: CoTraceDataIdentType; (*This ident can be used by other function blocks of this library to read or save the recorded data.*) (* *) (*#CMD*)
		ProcessingConfig : BOOL; (*The trace configuration is being applied at the moment.*) (* *) (*#CMD#OPT*)
		WaitsOnStartTrigger : BOOL; (*The configuration is applied and the recorder is waiting for a start trigger.*) (* *) (*#CMD#OPT*)
		WaitsOnStopEvent : BOOL; (*Signals, that recording is currently in progress. Stop events include: total recording time reached, memory full, ForceStop. *) (* *) (*#CMD#OPT*)
		ProcessingData	: BOOL; (*Indicates, that recorded data is gathered and processed.*) (* *) (*#CMD#OPT*)
		DataAvailable	: BOOL; (*All recorded data is available to be read or saved.*) (* *) (*#PAR*)
		TraceStatus 	: CoTraceRecorderStateEnum; (*Provides additional information about the internal state of the recorder.
It is possible that multiple states are run through during one execution cycle, in order to increase execution speed.*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceMemCtxInternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceDataReadRecords (*This function block can be used to read the recorded data.
For a successful execution of this function block a CoTraceRecorder function block needs to be enabled. In addition, a valid DataIdent needs to be provided on the DataIdent input.
The records are read in blocks. One block comprises either the data sampled on the PLC or the data sampled on one ACOPOS channel/axis.
Within each block, the records are sorted by recording time.

This function block can be executed multiple times during one task class cycle. This allows to reduce the overall reading time.*)
	VAR_INPUT
		Execute 		: BOOL; 			(*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		DataIdent		: CoTraceDataIdentType; (*The output "DataIdent" of an CoTraceRecorder function block has to be provided on the input.
		The output "DataAvailable" of the CoTraceRecorder function block has to be TRUE when executing this function block.*) (* *) (*#PAR*)
		First			: BOOL; 			(*The read process is started from the first element, if this input is set to true*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; 			(*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; 			(*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; 			(*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; 			(*Status information*)(* *) (*#PAR*)
		RelativeTime	: LREAL;			(*Recording-time in seconds relative to starting trigger-event.*)(* *) (*#PAR*)
		SiosTimeUsec	: UDINT;			(*Time in microseconds-ticks, when the records were sampled.*)(* *) (*#CMD#OPT*)
		UtcEpochTime	: DATE_AND_TIME;	(*Absolute recording-time of these data as UTC-value.*)(* *) (*#PAR*)
		NanoSecTimeOffset : UDINT;			(*Fraction-part of absolute recording-time (UtcEpochTime) as offset in nanoseconds.*)(* *) (*#PAR*)
		Records 		: ARRAY[0..9] OF CoTraceDataRecordType;	(*Array of recorded data. All data in the array was recorded at the same time.*) (* *) (*#PAR*)
		Last			: BOOL; 			(*Is true, if the record currently being read is the last of the sampled records.*) (* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceMemCtxInternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK CoTraceDataSaveCsv (*This function block can be used to save the recorded data to comma-separated values (CSV) file(s).
For a successful execution of this function block a CoTraceRecorder function block needs to be enabled and to provide a valid DataIdent as input until the data is saved.
The FileDevice must be configured in the CPU's configuration, see also the functional description of this function block.
Each data block comprising either all data sampled on the PLC or the data sampled on one ACOPOS channel/axis will lead to an separate CSV file.
The FileName is the base name used for the naming scheme of the produced output files.
The naming of the CSV files follows the scheme <FileName> + 3 digit counting integer + ".csv".
In an additional DAT file information on the content of all CSV files is provided.
The files can then be accessed via FTP. A DNE(<a href="../../projectmanagement/systemconfiguration/sg4/cpu/projectorganisation_systemconfiguration_sg4_cpu_ftpserv.html">FTP server</a>)DNE including users can be configured in the CPU's configuration.
It might be appropriate to use a DNE(<a href="../../automationruntime/enhancedtransfer/handling/et_settingsbeforebuild.html">user partition</a>)DNE as FileDevice.
*)
	VAR_INPUT
		Execute 		: BOOL; 		(*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		DataIdent		: CoTraceDataIdentType; (*The output "DataIdent" of an CoTraceRecorder function block has to be provided on the input.
		The CoTraceRecorder needs to be enabled and the output DataAvailable TRUE, until the data is saved.*) (* *) (*#PAR*)
		FileDevice		: STRING[128];	(*Name of the file device as specified in the DNE(<a href="../../projectmanagement/systemconfiguration/sg4/cpu/projectorganisation_systemconfiguration_sg4_cpu_files.html">CPU configuration file</a>)DNE similar as in the case of the DNE(<a href="../../libraries/fileio/gen/filedevice.html">FileIO library</a>)DNE*) (* *) (*#PAR*)
		FileName		: STRING[128];	(*base name of the CSV file(s)*) (* *) (*#PAR*)
		ColumnSeparator : STRING[1];	(*Character to be used as an separator between the columns in the CSV file (typical english setting is ",", typical german setting is ";")*) (* *) (*#PAR*)
		DecimalMark 	: STRING[1];	(*Character for the decimal mark (typical default setting is ".", german setting is sometimes ",")*) (* *) (*#PAR*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL; 			(*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL; 			(*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL; 			(*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		StatusID		: DINT; 			(*Status information*)(* *) (*#PAR*)
	END_VAR
	VAR
		Internal : CoTraceExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

