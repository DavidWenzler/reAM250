/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _COTRACE_
#define _COTRACE_
#ifdef __cplusplus
extern "C" {
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#if defined(_REPLACE_CONST) || defined(BUILD_COTRACE)
#define coTRACE_ERR_FILEIO_FAILED (-2124414950) 	/*!< File-I/O operation failed*/
#define coTRACE_ERR_END_REACHED (-2124414951)		/*!< no further suitable entry found*/
#define coTRACE_ERR_NOT_EXISTS (-2124414952)		/*!< record not found; doesn't exist*/
#define coTRACE_ERR_REF_NOT_FOUND (-2124414953) 	/*!< Reference resource not found/configured*/
#define coTRACE_ERR_INCOMPLETE_CONFIG (-2124414954) /*!< aborted due incomplete configuration*/
#define coTRACE_ERR_UNSUPPORTED_TYPE (-2124414955)	/*!< unsupported variable-type or -size*/
#define coTRACE_INF_ALREADY_DONE 1096810516 		/*!< execution/task already performed*/
#define coTRACE_ERR_NOT_AVAILABLE (-2124414957) 	/*!< resource (provider) not available*/
#define coTRACE_ERR_INVALID_DP_NAME (-2124414958)	/*!< invalid or unrecognized DP-name*/
#define coTRACE_ERR_UNKNOWN_PROVIDER (-2124414959)	/*!< data-provider is not supported*/
#define coTRACE_ERR_NOT_POSSIBLE (-2124414960)		/*!< action not (yet) possible; wrong state*/
#define coTRACE_ERR_INVALID_IDENT (-2124414971) 	/*!< Invalid Ident-argument detected*/
#define coTRACE_ERR_ACCESS_DENIED (-2124414972) 	/*!< Resource-access denied*/
#define coTRACE_ERR_FAILED (-1050673149)			/*!< Internal processing failure*/
#define coTRACE_ERR_INVALID_ARG (-2124414974)		/*!< One or more arguments are invalid*/
#define coTRACE_ERR_OUT_OF_MEMORY (-1050673151) 	/*!< Failed to allocate necessary memory*/
#else
#ifndef _GLOBAL_CONST
#define _GLOBAL_CONST _WEAK const
#endif
_GLOBAL_CONST signed long coTRACE_ERR_FILEIO_FAILED;
_GLOBAL_CONST signed long coTRACE_ERR_END_REACHED;
_GLOBAL_CONST signed long coTRACE_ERR_NOT_EXISTS;
_GLOBAL_CONST signed long coTRACE_ERR_REF_NOT_FOUND;
_GLOBAL_CONST signed long coTRACE_ERR_INCOMPLETE_CONFIG;
_GLOBAL_CONST signed long coTRACE_ERR_UNSUPPORTED_TYPE;
_GLOBAL_CONST signed long coTRACE_INF_ALREADY_DONE;
_GLOBAL_CONST signed long coTRACE_ERR_NOT_AVAILABLE;
_GLOBAL_CONST signed long coTRACE_ERR_INVALID_DP_NAME;
_GLOBAL_CONST signed long coTRACE_ERR_UNKNOWN_PROVIDER;
_GLOBAL_CONST signed long coTRACE_ERR_NOT_POSSIBLE;
_GLOBAL_CONST signed long coTRACE_ERR_INVALID_IDENT;
_GLOBAL_CONST signed long coTRACE_ERR_ACCESS_DENIED;
_GLOBAL_CONST signed long coTRACE_ERR_FAILED;
_GLOBAL_CONST signed long coTRACE_ERR_INVALID_ARG;
_GLOBAL_CONST signed long coTRACE_ERR_OUT_OF_MEMORY;
#endif

/* Datatypes and datatypes of function blocks */
typedef enum CoTraceTriggerConditionEnum
{
	coTRACE_IN_WINDOW_EVENT = 20,
	coTRACE_OUT_OF_WINDOW_EVENT = 30,
	coTRACE_ABOVE_THRESHOLD_EVENT = 40,
	coTRACE_BELOW_THRESHOLD_EVENT = 50,
	coTRACE_ENTER_WINDOW_EVENT = 24,
	coTRACE_LEAVE_WINDOW_EVENT = 34,
	coTRACE_GOES_ABOVE_WINDOW_EVENT = 44,
	coTRACE_GOES_BELOW_WINDOW_EVENT = 54
} CoTraceTriggerConditionEnum;

typedef enum CoTraceRecorderStateEnum
{
	coTRACE_DISABLED_STATE = 1,
	coTRACE_NOT_CONFIGURED_STATE = 2,
	coTRACE_READY_TO_APPLY_STATE = 3,
	coTRACE_CONFIG_PROCESSING_STATE = 10,
	coTRACE_CONFIG_APPLIED_STATE = 11,
	coTRACE_WAIT_START_TRIGGER_STATE = 20,
	coTRACE_WAIT_STOP_EVENT_STATE = 21,
	coTRACE_PROCESS_DATA_STATE = 22,
	coTRACE_DATA_AVAILABLE_STATE = 23,
	coTRACE_CONFIGURE_FAILED_STATE = 80,
	coTRACE_RECORD_ABORTED_STATE = 81,
	coTRACE_RECORD_FAILURE_STATE = 82
} CoTraceRecorderStateEnum;

typedef enum CoTraceConfigParamEnum
{
	coTRACE_PARAM_PV_TASK_CLASS = 1,
	coTRACE_PARAM_TOTAL_RECORD_TIME = 2,
	coTRACE_PARAM_TRIG_OFFSET_TIME = 3,
	coTRACE_PARAM_ACP_BUFFER_SIZE = 10,
	coTRACE_PARAM_ACP_SAMPLE_TIME = 11,
	coTRACE_PARAM_PLC_SAMPLE_TIME = 5
} CoTraceConfigParamEnum;

typedef struct CoTraceDataRecordType
{
	plcstring DataPointName[768];
	unsigned short DataType;
	unsigned long DataPointer;
} CoTraceDataRecordType;

typedef struct CoTraceExec1InternalType
{
	unsigned short i_serno;
	unsigned short i_state;
	signed long Result;
} CoTraceExec1InternalType;

typedef struct CoTraceMemCtxInternalType
{
	struct CoTraceExec1InternalType i_base;
	unsigned long m_ctx;
} CoTraceMemCtxInternalType;

typedef unsigned long CoTraceConfigIdentType;
typedef unsigned long CoTraceDataIdentType;

typedef struct CoTraceConfigCreate
{
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	CoTraceConfigIdentType ConfigIdent;
	/* VAR (analog) */
	struct CoTraceMemCtxInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigCreate_typ;

typedef struct CoTraceConfigLoad
{
	/* VAR_INPUT (analog) */
	plcstring Name[33];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	CoTraceConfigIdentType ConfigIdent;
	/* VAR (analog) */
	struct CoTraceMemCtxInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigLoad_typ;

typedef struct CoTraceConfigSetTiming
{
	/* VAR_INPUT (analog) */
	CoTraceConfigIdentType ConfigIdent;
	float TotalRecordingTime;
	float TriggerOffsetTime;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct CoTraceExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigSetTiming_typ;

typedef struct CoTraceConfigOptionalParameter
{
	/* VAR_INPUT (analog) */
	CoTraceConfigIdentType ConfigIdent;
	enum CoTraceConfigParamEnum Parameter;
	float Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct CoTraceExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigOptionalParameter_typ;

typedef struct CoTraceConfigAddDataPoint
{
	/* VAR_INPUT (analog) */
	CoTraceConfigIdentType ConfigIdent;
	plcstring DataPointName[768];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct CoTraceExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigAddDataPoint_typ;

typedef struct CoTraceConfigAddStartTrigger
{
	/* VAR_INPUT (analog) */
	CoTraceConfigIdentType ConfigIdent;
	plcstring DataPointName[768];
	enum CoTraceTriggerConditionEnum Condition;
	float Threshold;
	float Window;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct CoTraceExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} CoTraceConfigAddStartTrigger_typ;

typedef struct CoTraceRecorder
{
	/* VAR_INPUT (analog) */
	CoTraceConfigIdentType ConfigIdent;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	CoTraceDataIdentType DataIdent;
	enum CoTraceRecorderStateEnum TraceStatus;
	/* VAR (analog) */
	struct CoTraceMemCtxInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ForceStartTrigger;
	plcbit ForceStop;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Busy;
	plcbit Error;
	plcbit ProcessingConfig;
	plcbit WaitsOnStartTrigger;
	plcbit WaitsOnStopEvent;
	plcbit ProcessingData;
	plcbit DataAvailable;
} CoTraceRecorder_typ;

typedef struct CoTraceDataReadRecords
{
	/* VAR_INPUT (analog) */
	CoTraceDataIdentType DataIdent;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	double RelativeTime;
	unsigned long SiosTimeUsec;
	plcdt UtcEpochTime;
	unsigned long NanoSecTimeOffset;
	struct CoTraceDataRecordType Records[10];
	/* VAR (analog) */
	struct CoTraceMemCtxInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	plcbit First;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit Last;
} CoTraceDataReadRecords_typ;

typedef struct CoTraceDataSaveCsv
{
	/* VAR_INPUT (analog) */
	CoTraceDataIdentType DataIdent;
	plcstring FileDevice[129];
	plcstring FileName[129];
	plcstring ColumnSeparator[2];
	plcstring DecimalMark[2];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct CoTraceExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} CoTraceDataSaveCsv_typ;

/* Prototyping of functions and function blocks */
_BUR_PUBLIC void CoTraceConfigCreate(struct CoTraceConfigCreate* inst);
_BUR_PUBLIC void CoTraceConfigLoad(struct CoTraceConfigLoad* inst);
_BUR_PUBLIC void CoTraceConfigSetTiming(struct CoTraceConfigSetTiming* inst);
_BUR_PUBLIC void CoTraceConfigOptionalParameter(struct CoTraceConfigOptionalParameter* inst);
_BUR_PUBLIC void CoTraceConfigAddDataPoint(struct CoTraceConfigAddDataPoint* inst);
_BUR_PUBLIC void CoTraceConfigAddStartTrigger(struct CoTraceConfigAddStartTrigger* inst);
_BUR_PUBLIC void CoTraceRecorder(struct CoTraceRecorder* inst);
_BUR_PUBLIC void CoTraceDataReadRecords(struct CoTraceDataReadRecords* inst);
_BUR_PUBLIC void CoTraceDataSaveCsv(struct CoTraceDataSaveCsv* inst);

#ifdef __cplusplus
} // End of C-Linkage
#endif
#endif /* _COTRACE_ */

