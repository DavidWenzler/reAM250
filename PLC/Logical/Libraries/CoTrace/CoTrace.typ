(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG
 ********************************************************************
 * Library: CoTrace
 * File:	CoTrace.typ
 ********************************************************************
 * Declaration of data-types of library CoTrace
 ********************************************************************)

TYPE
	CoTraceConfigIdentType	: UDINT; (*This type represents a trace-configuration*)
	CoTraceDataIdentType	: UDINT; (*This type represents recorded trace-data*)

	CoTraceTriggerConditionEnum :
	(
		coTRACE_IN_WINDOW_EVENT 		:= 20,	(*The trigger event occurs if the value of the DataPoint meets the following conditions:
"value DNE(&ge;)DNE threshold + window" and
"value DNE(&le;)DNE threshold - window"
DNE(<img src="IN_WINDOW.png">)DNE*)
		coTRACE_OUT_OF_WINDOW_EVENT 	:= 30, (*The trigger event occurs if the value of the DataPoint meets the following conditions:
"value DNE(&gt;)DNE threshold + window" or
"value DNE(&lt;)DNE threshold - window"
DNE(<img src="OUT_WINDOW.png">)DNE*)
		coTRACE_ABOVE_THRESHOLD_EVENT	:= 40, (*The trigger event occurs if the value of the DataPoint meets the following condition:
"value DNE(&gt;)DNE threshold + window"
DNE(<img src="ABOVE_WINDOW.png">)DNE*)
		coTRACE_BELOW_THRESHOLD_EVENT	:= 50, (*The trigger event occurs if the value of the DataPoint meets the following condition:
"value DNE(&lt;)DNE threshold - window"
DNE(<img src="BELOW_WINDOW.png">)DNE*)
		coTRACE_ENTER_WINDOW_EVENT		:= 24, (*The trigger event occurs if the value for the DataPoint
goes below the upper window limit "threshold + window" or
goes above the lower window limit "threshold - window"
(after being outside the window before) and is then within the window. If the value of the value of the DataPoint is already within the window during trace activation, the trace is not yet started.
DNE(<img src="IN_WINDOW_ENTRY.png">)DNE*)
		coTRACE_LEAVE_WINDOW_EVENT		:= 34, (*The trigger event occurs if the value for the DataPoint
goes above the upper window limit "threshold + window" or
goes below the lower window limit "threshold - window"
(after being inside the window before) and is then outside the window. If the value of the DataPoint is already outside the window during trace activation, the trace is not yet started.
DNE(<img src="OUT_WINDOW_ENTRY.png">)DNE*)
		coTRACE_GOES_ABOVE_WINDOW_EVENT := 44, (*The trigger event occurs if the value of the DataPoint goes above the upper window limit "threshold + window".
If, during trace activation, the value of the trigger parameter is already above the window, the trace is not yet started.
DNE(<img src="ABOVE_WINDOW_ENTRY.png">)DNE*)
		coTRACE_GOES_BELOW_WINDOW_EVENT := 54 (*The trigger event occurs if the value of the DataPoint goes below the lower window limit "threshold - window".
If, during trace activation, the value of the trigger parameter is already below the window, the trace is not yet started.
DNE(<img src="BELOW_WINDOW_ENTRY.png">)DNE*)
	);
	(*Enumeration of trigger conditions*)

	CoTraceRecorderStateEnum :
	(
		coTRACE_DISABLED_STATE				:=  1,	(* The FB is invalid or disabled *)
		coTRACE_NOT_CONFIGURED_STATE		:=  2,	(* The trace configuration is empty; no DataPoint has been added yet.*)
		coTRACE_READY_TO_APPLY_STATE		:=  3,	(* The trace configuration contains one or more DataPoint(s) and may be ready to be applied. *)
		coTRACE_CONFIG_PROCESSING_STATE		:= 10,	(* The trace configuration is being installed. *)
		coTRACE_CONFIG_APPLIED_STATE		:= 11,	(* The applied trace configuration is active. *)
		coTRACE_WAIT_START_TRIGGER_STATE	:= 20,	(* Recording is in progress. Waiting for start trigger. *)
		coTRACE_WAIT_STOP_EVENT_STATE		:= 21, 	(* Recording is in progress. Waiting for stop event. *)
		coTRACE_PROCESS_DATA_STATE			:= 22,	(* Recording is completed. The recorded data is gathered. *)
		coTRACE_DATA_AVAILABLE_STATE		:= 23,	(* Recording is completed. All recorded data is available for reading. *)
		coTRACE_CONFIGURE_FAILED_STATE		:= 80,	(* The trace configuration could not be applied.
		Error state: Please disable the FB for at least one cycle.*)
		coTRACE_RECORD_ABORTED_STATE		:= 81,	(* Reading of trace records was aborted due to unknown reason.
		Error state: Please disable the FB for at least one cycle.*)
		coTRACE_RECORD_FAILURE_STATE		:= 82	(* A failure during applying or processing a trace-configuration occurred.
		Error state: Please disable the FB for at least one cycle.*)
	);
	(*Enumeration of trace-processing states.*)

	CoTraceConfigParamEnum :
	(
		coTRACE_PARAM_PV_TASK_CLASS 	:=   1, (* This parameter can be used to set the desired task-class for PV-traces. The value is of the data-type REAL, but an integer number must be supplied (e.g. a value of 1.0 refers to TaskClass Cyclic #1, a value of 1.1 is invalid and would result in an error). *)
		coTRACE_PARAM_TOTAL_RECORD_TIME :=   2, (* This parameter can be used to configure the total recording time over all involved data-sources. The value defines the sample time in [seconds].*)
		coTRACE_PARAM_TRIG_OFFSET_TIME	:=   3, (* This parameter can be used to set a time of record data to be hold before (negative value) or after (positive value) a trigger-event occurred.*)
		coTRACE_PARAM_ACP_BUFFER_SIZE	:=  10, (* This parameter represents the actual ACOPOS trace-buffer size in kilobyte (1 kilobyte is 1024 byte). This optional parameter should be set, if the ACOPOS trace-buffer size was manipulated by setting the respective ParId.
		The default value of the ACOPOS trace-buffer size is (32.0 KB = 32768 byte).
		The value is of the data-type REAL, but an integer number must be supplied (e.g. a value of 64.0 refers to 64KB, a value of 64.1 is invalid and would result in an error).*)
		coTRACE_PARAM_ACP_SAMPLE_TIME	:=  11, (* This parameter can be used to set the sample time of an ACOPOS trace. The value defines the time in [seconds].
		The defined sample time has a higher priority than the TotalRecordingTime. Defining a small sample time (leading to a high frequency) can have the effect that the recording is stopped as soon as the trace-buffer is full (prior to reaching the "TotalRecordingTime").*)
		coTRACE_PARAM_PLC_SAMPLE_TIME	:=   5	(* This parameter defines a preferred PLC sample-interval in [seconds]. This optional parameter is used to calculate a clock-divider; I.e., that recording occurs as multiple of the monoton clock of the configured task-class.
		The default value of 0.0 specifies, that PLC-values are recorded on every cycle. Each other (positive) value will be used as hint to do recording close to this configured interval. *)
	);
	(*Enumeration of trace-parameters, to setup or specify optional values to an CoTrace-configuration.*)

	CoTraceDataRecordType : STRUCT (*This structure-type represents a single data record*)
		DataPointName	: STRING[767]; (*string-pointer to full identifier string of this DataPoint (read-only)*)
		DataType		: UINT; (*type of data-value; e.g. IEC_DATATYPE_UDINT IEC 61131-3 data types:
1	IEC_DATATYPE_BOOL		8 Bit containing a boolean value FALSE=0 oder TRUE=1
2	IEC_DATATYPE_SINT		8 Bit signed integer
3	IEC_DATATYPE_INT		16 Bit signed integer
4	IEC_DATATYPE_DINT		32 Bit signed integer
5	IEC_DATATYPE_USINT		8 Bit unsigned integer
6	IEC_DATATYPE_UINT		16 Bit unsigned integer
7	IEC_DATATYPE_UDINT		32 Bit unsigned integer
8	IEC_DATATYPE_REAL		32 Bit floating point number
9	IEC_DATATYPE_STRING		Variable-length single-byte character string
10	IEC_DATATYPE_ULINT		64 Bit unsigned integer (not yet fully supported as IEC data type)
11	IEC_DATATYPE_DATE_AND_TIME	32 Bit of Date in Seconds since 01.01.1970 00:00:00 UTC
12	IEC_DATATYPE_TIME		32 Bit of Time in ms
13	IEC_DATATYPE_DATE		32 Bit of Date (only)
14	IEC_DATATYPE_LREAL		64 Bit floating point number
16	IEC_DATATYPE_TIME_OF_DAY	UINT	32 Bit Time of day (only)
17	IEC_DATATYPE_BYTE		Bit string of length 8
18	IEC_DATATYPE_WORD		Bit string of length 16
19	IEC_DATATYPE_DWORD		Bit string of length 32
20	IEC_DATATYPE_LWORD		Bit string of length 64
21	IEC_DATATYPE_WSTRING		Variable-length double-byte character string
23	IEC_DATATYPE_LINT		64 Bit signed integer (not yet fully supported as IEC data type)*)
		DataPointer 	: UDINT; (*pointer (read-only) to data-value*)
	END_STRUCT;

	CoTraceExec1InternalType : STRUCT (*Internal structure-types for FB-processing*)
		i_serno : UINT;
		i_state : UINT;
		Result	: DINT;
	END_STRUCT;

	CoTraceMemCtxInternalType : STRUCT (*Internal structure-types for FB-processing*)
		i_base	: CoTraceExec1InternalType;
		m_ctx	: UDINT; (*internal reference; e.g. memory-pointer*)
	END_STRUCT;

END_TYPE
