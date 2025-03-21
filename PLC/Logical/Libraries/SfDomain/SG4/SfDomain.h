/* Automation Studio generated header file */
/* Do not edit ! */
/* SfDomain 5.16.0 */

#ifndef _SFDOMAIN_
#define _SFDOMAIN_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _SfDomain_VERSION
#define _SfDomain_VERSION 5.16.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "MpBase.h"
#endif

#ifdef _SG4
		#include "MpBase.h"
#endif

#ifdef _SGC
		#include "MpBase.h"
#endif



/* Datatypes and datatypes of function blocks */
typedef enum SfDomainSafeOSStateEnum
{	sfDOM_OS_STATE_INVALID = 0,
	sfDOM_OS_STATE_ON = 15,
	sfDOM_OS_STATE_LOADING = 51,
	sfDOM_OS_STATE_SAFE_STOP = 85,
	sfDOM_OS_STATE_SAFE_RUN = 102,
	sfDOM_OS_STATE_DEBUG_HALT = 153,
	sfDOM_OS_STATE_DEBUG_STOP = 170,
	sfDOM_OS_STATE_DEBUG_RUN = 204,
	sfDOM_OS_STATE_NO_EXECUTION = 240,
	sfDOM_OS_STATE_DEBUG_OFFLINE = 255
} SfDomainSafeOSStateEnum;

typedef enum SfDomainSafeNodesStateEnum
{	sfDOM_NODES_STATE_OK = 0,
	sfDOM_NODES_STATE_EXCHANGED = 1,
	sfDOM_NODES_STATE_MISSING = 2
} SfDomainSafeNodesStateEnum;

typedef enum SfDomainSystemStateEnum
{	sfDOM_SYSTEM_STATE_OK = 0,
	sfDOM_SYSTEM_STATE_FW_EXCHANGE = 1,
	sfDOM_SYSTEM_STATE_SK_EXCHANGE = 2
} SfDomainSystemStateEnum;

typedef enum SfDomainOperationalModeEnum
{	sfDOM_OP_MODE_OPERATIONAL = 0,
	sfDOM_OP_MODE_PREOPERATIONAL = 1,
	sfDOM_OP_MODE_FAILSAFE = 2
} SfDomainOperationalModeEnum;

typedef enum SfDomainSafeComUnusedEnum
{	sfDOM_UNUSED_NONE = 0,
	sfDOM_BOOL_AVAILABILITY = 1,
	sfDOM_NUMBERS = 2,
	sfDOM_BOOL_AVAILABILITY_NUMBERS = 3,
	sfDOM_NODE = 4,
	sfDOM_NODE_BOOL_AVAILABILITY = 5,
	sfDOM_NODE_NUMBERS = 6,
	sfDOM_BOOL_AVAIL_NUMBERS = 7
} SfDomainSafeComUnusedEnum;

typedef enum SfDomainPermLevelEnum
{	sfDOM_PERMLEVEL_APPLENGINEER = 0,
	sfDOM_PERMLEVEL_MAOPERATOR = 1
} SfDomainPermLevelEnum;

typedef enum SfDomainCtrlCmdEnum
{	sfDOM_REBOOT = 0,
	sfDOM_FORMAT_REBOOT = 1,
	sfDOM_ACT_SETUP_MODE = 2
} SfDomainCtrlCmdEnum;

typedef enum SfDomainTableTypeEnum
{	sfDOM_TableType_UNUSED = 0,
	sfDOM_TableType_A = 1,
	sfDOM_TableType_B = 2,
	sfDOM_TableType_C = 3,
	sfDOM_TableType_D = 4,
	sfDOM_TableType_E = 5,
	sfDOM_TableType_S = 19,
	sfDOM_TableType_T = 20,
	sfDOM_TableType_U = 21,
	sfDOM_TableType_V = 22,
	sfDOM_TableType_W = 23
} SfDomainTableTypeEnum;

typedef enum SfDomainAcknowledgeEnum
{	sfDOM_ACK_WAIT = 0,
	sfDOM_ACK_ACKNOWLEDGE = 1,
	sfDOM_ACK_CANCEL = 2
} SfDomainAcknowledgeEnum;

typedef enum SfDomainSafeNodeAvailabilityEnum
{	sfDOM_AV_PRESENT = 0,
	sfDOM_AV_STARTUP = 1,
	sfDOM_AV_OPTIONAL = 2,
	sfDOM_AV_NOT_PRESENT = 3
} SfDomainSafeNodeAvailabilityEnum;

typedef enum SfDomainErrorEnum
{	sfDOM_NO_ERROR = 0,
	sfDOM_ERR_CHECK_AUTH = -1073552128,
	sfDOM_ERR_CHECK_USER_ACCESS = -1073552127,
	sfDOM_ERR_EXCH_SNACK = -1073552115,
	sfDOM_ERR_EXCH_FWACK = -1073552114,
	sfDOM_ERR_EXCH_SKACK = -1073552113,
	sfDOM_ERR_TRAN_VALIDAPP = -1073552112,
	sfDOM_ERR_TRAN_VALIDCOMM = -1073552111,
	sfDOM_ERR_TRAN_DOWNAPP = -1073552110,
	sfDOM_ERR_TRAN_DOWNCOMM = -1073552109,
	sfDOM_ERR_CTRL_FORMAT = -1073552108,
	sfDOM_ERR_DISCONN_FAILED = -1073552107,
	sfDOM_ERR_CONNECT_FAILED = -1073552106,
	sfDOM_ERR_CONNECT_LOST = -1073552105,
	sfDOM_ERR_CONN_NOT_VALID = -1073552104,
	sfDOM_ERR_CTRL_REBOOT = -1073552103,
	sfDOM_ERR_COMP_ACKAPP = -1073552102,
	sfDOM_ERR_COMP_ACKCOMM = -1073552101,
	sfDOM_ERR_COMP_ACKSETUPMODE = -1073552100,
	sfDOM_ERR_CONN_CHECKINPUT = -1073552099,
	sfDOM_ERR_TRAN_PATH = -1073552098,
	sfDOM_ERR_TRAN_NOFILE = -1073552097,
	sfDOM_ERR_API_NO_SFDOMAIN = -1073552095,
	sfDOM_ERR_API_SFDOM_CHANGED = -1073552094,
	sfDOM_ERR_CTRL_COMMAND = -1073552093,
	sfDOM_ERR_CTRL_ACT_SM_FAILED = -1073552092,
	sfDOM_ERR_FB_ENABLE_FAILED = -1073552091,
	sfDOM_ERR_FB_DISABLE_FAILED = -1073552090,
	sfDOM_ERR_FB_EXECUTE_FAILED = -1073552089,
	sfDOM_ERR_CONN_EXISTS_ALREADY = -1073552088,
	sfDOM_ERR_CONN_NO_CONNECTION = -1073552087,
	sfDOM_ERR_CONN_UDID_MISMATCH = -1073552086,
	sfDOM_ERR_INFO_READ_FAILED = -1073552085,
	sfDOM_ERR_CONN_UDID_FAILED = -1073552084,
	sfDOM_ERR_WRONG_INFO_STRUCT = -1073552083,
	sfDOM_ERR_INVALID_TABLE_ID = -1073552082,
	sfDOM_ERR_GET_TABLE_LIST = -1073552081,
	sfDOM_ERR_VALID_TABLE_LIST = -1073552080,
	sfDOM_ERR_DOWNLOAD_TABLES = -1073552079,
	sfDOM_ERR_COMPLETION_TABLE = -1073552078,
	sfDOM_ERR_ACKNOWLEDGE_TABLE = -1073552077,
	sfDOM_ERR_TABLE_NOT_DOWNLOADED = -1073552076,
	sfDOM_ERR_TABLE_NOT_FOUND = -1073552075,
	sfDOM_ERR_NO_SETUPMODE = -1073552074,
	sfDOM_ERR_TABLES_NOT_FOUND = -1073552073,
	sfDOM_ERR_TABLES_NOT_ACK = -1073552072,
	sfDOM_ERR_SO_ID_EMPTY = -1073552071,
	sfDOM_ERR_SO_ID_NOTFOUND = -1073552070,
	sfDOM_ERR_SO_INVISIBLE = -1073552069,
	sfDOM_ERR_SO_CRC_INVALID = -1073552068,
	sfDOM_ERR_SO_NOT_LOADED = -1073552067,
	sfDOM_ERR_STR_TOO_LONG = -1073552066,
	sfDOM_ERR_SO_FILE_EMPTY = -1073552065,
	sfDOM_ERR_SO_FILE_CRC_INVALID = -1073552064,
	sfDOM_ERR_SO_FILE_NOTFOUND = -1073552063,
	sfDOM_ERR_SO_READONLY = -1073552062,
	sfDOM_ERR_SO_RANGE_INVALID = -1073552061,
	sfDOM_ERR_SO_STEP_INVALID = -1073552060,
	sfDOM_ERR_FILE_W_FAILED = -1073552059,
	sfDOM_INF_UDID_MISMATCH = 1073931671,
	sfDOM_INF_CONN_DISCONN = 1073931672,
	sfDOM_INF_CONN_CONNECT = 1073931673,
	sfDOM_INF_TRAN_DATA = 1073931674,
	sfDOM_INF_TRAN_VALIDAPP = 1073931675,
	sfDOM_INF_TRAN_DOWNAPP = 1073931676,
	sfDOM_INF_TRAN_VALIDCOMM = 1073931677,
	sfDOM_INF_TRAN_DOWNCOMM = 1073931678,
	sfDOM_INF_COMP_APP = 1073931679,
	sfDOM_INF_COMP_COMM = 1073931680,
	sfDOM_INF_COMP_SETUPMODE = 1073931681,
	sfDOM_INF_FB_ENABLED = 1073931682,
	sfDOM_INF_FB_DISABLED = 1073931683,
	sfDOM_INF_FB_EXECUTED = 1073931684,
	sfDOM_INF_CONN_SUCCESS = 1073931685,
	sfDOM_INF_FB_ENABLED_SUCCESS = 1073931686,
	sfDOM_INF_FB_DISABLED_SUCCESS = 1073931687,
	sfDOM_INF_FB_EXECUTED_SUCCESS = 1073931688,
	sfDOM_INF_TRAN_SFAPP_SUCCESS = 1073931689,
	sfDOM_INF_TRAN_SFOPT_SUCCESS = 1073931690,
	sfDOM_INF_COMP_SFAPP_SUCCESS = 1073931691,
	sfDOM_INF_COMP_SFOPT_SUCCESS = 1073931692,
	sfDOM_INF_COMP_SM_SUCCESS = 1073931693,
	sfDOM_INF_CTRL_REBOOT_SUCCESS = 1073931694,
	sfDOM_INF_CTRL_FORMAT_SUCCESS = 1073931695,
	sfDOM_INF_CTRL_SM_ACT_SUCCESS = 1073931696,
	sfDOM_INF_EXCH_SKACK_SUCCESS = 1073931697,
	sfDOM_INF_EXCH_SNACK_SUCCESS = 1073931698,
	sfDOM_INF_EXCH_FWACK_SUCCESS = 1073931699,
	sfDOM_INF_TABLE_COMPLETION = 1073931700,
	sfDOM_INF_TABLE_CANCEL_ACK = 1073931701,
	sfDOM_INF_TABLE_COMP_SUCCESS = 1073931702,
	sfDOM_INF_DOWN_TABS_SUCCESS = 1073931703,
	sfDOM_INF_DOWNLOAD_TABLES = 1073931704,
	sfDOM_INF_VALID_TABLES = 1073931705,
	sfDOM_INF_TABLE_ACK_REQUIRED = 1073931706,
	sfDOM_INF_SO_LOADED = 1073931707,
	sfDOM_INF_SO_SET = 1073931708,
	sfDOM_INF_SO_SAVED = 1073931709
} SfDomainErrorEnum;

typedef struct SfDomainInfoStatusType
{	enum SfDomainSafeOSStateEnum SafeOSState;
	enum SfDomainSafeNodesStateEnum SafeNodesState;
	enum SfDomainSystemStateEnum SystemState;
	enum SfDomainOperationalModeEnum OperationalModeState;
	enum SfDomainSafeComUnusedEnum SafeCommissioningUnused;
	plcbit FWExchanged;
	unsigned short NumberOfFWExchanged;
	plcbit SNExchanged;
	unsigned short NumberOfSNExchanged;
	plcbit SKExchanged;
	plcbit SetupModeActive;
} SfDomainInfoStatusType;

typedef struct SfDomainInfoFileType
{	plcbit ExistOnSafeLogic;
	plcstring Name[261];
	plcstring UserName[261];
	unsigned long TimeStamp;
	unsigned long CRC;
	plcbit Acknowledged;
} SfDomainInfoFileType;

typedef struct SfDomainTableInfoStatusType
{	unsigned short TableID;
	enum SfDomainTableTypeEnum TableType;
	plcbit Acknowledged;
} SfDomainTableInfoStatusType;

typedef struct SfDomainTableInfoType
{	unsigned char NumberOfRemoteTables;
	struct SfDomainTableInfoStatusType TableInfoStatusArray[99];
} SfDomainTableInfoType;

typedef struct SfDomainInfoType
{	unsigned short SafeDomainID;
	unsigned long UDID_low;
	unsigned short UDID_high;
	struct SfDomainInfoStatusType Status;
	struct SfDomainInfoFileType SafeApplication;
	struct SfDomainInfoFileType SafeCommissioning[1];
	struct SfDomainTableInfoType SafeTables;
} SfDomainInfoType;

typedef struct SfDomainInternalFlags
{	plcbit Toggled;
	plcbit WaitForOneCycle;
	plcbit ActiveDoneReached;
} SfDomainInternalFlags;

typedef struct SfDomInternalIfType
{	plcdword vTable;
} SfDomInternalIfType;

typedef struct SfDomType
{	struct SfDomInternalIfType* controlIf;
} SfDomType;

typedef struct SfDomainInternalDataType
{	unsigned long pObject;
	unsigned long State;
	struct SfDomainInternalFlags Flag;
	struct SfDomType* SfDomainInternal;
} SfDomainInternalDataType;

typedef struct SfDomainConnect
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring UserName[81];
	plcstring Password[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned short SafeDomainID;
	plcstring CurrentUser[81];
	enum SfDomainPermLevelEnum PermissionLevel;
	unsigned long UDID_low;
	unsigned short UDID_high;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit UDID_Acknowledge;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Active;
	plcbit Error;
} SfDomainConnect_typ;

typedef struct SfDomainTransfer
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeAppFilePath[261];
	plcstring SafeCommFilePath[261];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned char Progress;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainTransfer_typ;

typedef struct SfDomainCompletion
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	struct SfDomainInfoType Info;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainCompletion_typ;

typedef struct SfDomainInfo
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct SfDomainInfoType Info;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainInfo_typ;

typedef struct SfDomainExchange
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	struct SfDomainInfoType Info;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainExchange_typ;

typedef struct SfDomainControl
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	enum SfDomainCtrlCmdEnum ControlCommand;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainControl_typ;

typedef struct SfDomainTableCompletion
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	unsigned short TableID;
	enum SfDomainAcknowledgeEnum Acknowledge;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	enum SfDomainTableTypeEnum TableType;
	plcstring UserName[81];
	unsigned long TimeStamp;
	unsigned long AckCrc;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit AcknowledgeRequired;
} SfDomainTableCompletion_typ;

typedef struct SfDomainGetSafeOptionBool
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit Value;
	plcbit ReadOnly;
} SfDomainGetSafeOptionBool_typ;

typedef struct SfDomainLoadSafeOptions
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeCommFilePath[261];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned long FileCRC;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainLoadSafeOptions_typ;

typedef struct SfDomainSetSafeOptionBool
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	plcbit Value;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionBool_typ;

typedef struct SfDomainSaveSafeOptions
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeCommFilePath[261];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned long FileCRC;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSaveSafeOptions_typ;

typedef struct SfDomainGetSafeOptionSint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	signed char Value;
	signed char MinValue;
	signed char MaxValue;
	signed char Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionSint_typ;

typedef struct SfDomainSetSafeOptionSint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	signed char Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionSint_typ;

typedef struct SfDomainGetSafeOptionUsint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	unsigned char Value;
	unsigned char MinValue;
	unsigned char MaxValue;
	unsigned char Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionUsint_typ;

typedef struct SfDomainSetSafeOptionUsint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	unsigned char Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionUsint_typ;

typedef struct SfDomainGetSafeOptionInt
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	signed short Value;
	signed short MinValue;
	signed short MaxValue;
	signed short Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionInt_typ;

typedef struct SfDomainSetSafeOptionInt
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	signed short Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionInt_typ;

typedef struct SfDomainGetSafeOptionUint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	unsigned short Value;
	unsigned short MinValue;
	unsigned short MaxValue;
	unsigned short Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionUint_typ;

typedef struct SfDomainSetSafeOptionUint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	unsigned short Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionUint_typ;

typedef struct SfDomainGetSafeOptionDint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	signed long Value;
	signed long MinValue;
	signed long MaxValue;
	signed long Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionDint_typ;

typedef struct SfDomainSetSafeOptionDint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	signed long Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionDint_typ;

typedef struct SfDomainGetSafeOptionUdint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	unsigned long Value;
	unsigned long MinValue;
	unsigned long MaxValue;
	unsigned long Step;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionUdint_typ;

typedef struct SfDomainSetSafeOptionUdint
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	unsigned long Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionUdint_typ;

typedef struct SfDomainGetSafeOptionString
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	plcstring Value[261];
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeOptionString_typ;

typedef struct SfDomainSetSafeOptionString
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	plcstring Value[261];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeOptionString_typ;

typedef struct SfDomainGetSafeNodeAvailability
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	plcstring Name[81];
	plcstring Description[261];
	enum SfDomainSafeNodeAvailabilityEnum Value;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit ReadOnly;
} SfDomainGetSafeNodeAvailability_typ;

typedef struct SfDomainSetSafeNodeAvailability
{
	/* VAR_INPUT (analog) */
	struct SfDomType* SfDomain;
	plcstring SafeOptionID[81];
	enum SfDomainSafeNodeAvailabilityEnum Value;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	struct SfDomainInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} SfDomainSetSafeNodeAvailability_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void SfDomainConnect(struct SfDomainConnect* inst);
_BUR_PUBLIC void SfDomainTransfer(struct SfDomainTransfer* inst);
_BUR_PUBLIC void SfDomainCompletion(struct SfDomainCompletion* inst);
_BUR_PUBLIC void SfDomainInfo(struct SfDomainInfo* inst);
_BUR_PUBLIC void SfDomainExchange(struct SfDomainExchange* inst);
_BUR_PUBLIC void SfDomainControl(struct SfDomainControl* inst);
_BUR_PUBLIC void SfDomainTableCompletion(struct SfDomainTableCompletion* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionBool(struct SfDomainGetSafeOptionBool* inst);
_BUR_PUBLIC void SfDomainLoadSafeOptions(struct SfDomainLoadSafeOptions* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionBool(struct SfDomainSetSafeOptionBool* inst);
_BUR_PUBLIC void SfDomainSaveSafeOptions(struct SfDomainSaveSafeOptions* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionSint(struct SfDomainGetSafeOptionSint* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionSint(struct SfDomainSetSafeOptionSint* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionUsint(struct SfDomainGetSafeOptionUsint* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionUsint(struct SfDomainSetSafeOptionUsint* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionInt(struct SfDomainGetSafeOptionInt* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionInt(struct SfDomainSetSafeOptionInt* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionUint(struct SfDomainGetSafeOptionUint* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionUint(struct SfDomainSetSafeOptionUint* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionDint(struct SfDomainGetSafeOptionDint* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionDint(struct SfDomainSetSafeOptionDint* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionUdint(struct SfDomainGetSafeOptionUdint* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionUdint(struct SfDomainSetSafeOptionUdint* inst);
_BUR_PUBLIC void SfDomainGetSafeOptionString(struct SfDomainGetSafeOptionString* inst);
_BUR_PUBLIC void SfDomainSetSafeOptionString(struct SfDomainSetSafeOptionString* inst);
_BUR_PUBLIC void SfDomainGetSafeNodeAvailability(struct SfDomainGetSafeNodeAvailability* inst);
_BUR_PUBLIC void SfDomainSetSafeNodeAvailability(struct SfDomainSetSafeNodeAvailability* inst);


#ifdef __cplusplus
};
#endif
#endif /* _SFDOMAIN_ */

