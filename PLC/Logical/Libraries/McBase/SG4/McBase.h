/* Automation Studio generated header file */
/* Do not edit ! */
/* McBase 5.16.2 */

#ifndef _MCBASE_
#define _MCBASE_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _McBase_VERSION
#define _McBase_VERSION 5.16.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef enum McAxisPLCopenStateEnum
{	mcAXIS_DISABLED,
	mcAXIS_STANDSTILL,
	mcAXIS_HOMING,
	mcAXIS_STOPPING,
	mcAXIS_DISCRETE_MOTION,
	mcAXIS_CONTINUOUS_MOTION,
	mcAXIS_SYNCHRONIZED_MOTION,
	mcAXIS_ERRORSTOP,
	mcAXIS_STARTUP,
	mcAXIS_INVALID_CONFIGURATION
} McAxisPLCopenStateEnum;

typedef enum McGroupPLCopenStateEnum
{	mcGROUP_DISABLED,
	mcGROUP_HOMING,
	mcGROUP_STANDBY,
	mcGROUP_MOVING,
	mcGROUP_STOPPING,
	mcGROUP_ERRORSTOP,
	mcGROUP_STARTUP,
	mcGROUP_INVALID_CONFIGURATION
} McGroupPLCopenStateEnum;

typedef enum McBufferModeEnum
{	mcABORTING,
	mcBUFFERED,
	mcBLENDING_LOW,
	mcBLENDING_PREVIOUS,
	mcBLENDING_NEXT,
	mcBLENDING_HIGH
} McBufferModeEnum;

typedef enum McBrakeCmdEnum
{	mcBRAKE_CLOSE,
	mcBRAKE_OPEN,
	mcBRAKE_GET_STATUS
} McBrakeCmdEnum;

typedef enum McBrakeStatusEnum
{	mcBRAKE_STATUS_NOT_PROVIDED,
	mcBRAKE_CLOSED,
	mcBRAKE_OPENED
} McBrakeStatusEnum;

typedef enum McHomingModeEnum
{	mcHOMING_DIRECT = 0,
	mcHOMING_SWITCH_GATE,
	mcHOMING_ABSOLUTE_SWITCH,
	mcHOMING_LIMIT_SWITCH = 4,
	mcHOMING_ABSOLUTE,
	mcHOMING_DCM = 7,
	mcHOMING_BLOCK_TORQUE = 9,
	mcHOMING_BLOCK_LAG_ERROR = 10,
	mcHOMING_ABSOLUTE_INTERNAL = 11,
	mcHOMING_ABSOLUTE_CORRECTION = 133,
	mcHOMING_DCM_CORRECTION = 135,
	mcHOMING_DEFAULT = 140,
	mcHOMING_INIT,
	mcHOMING_RESTORE_POSITION
} McHomingModeEnum;

typedef enum McStopModeEnum
{	mcSTOPMODE_JERK_LIMIT,
	mcSTOPMODE_NO_JERK_LIMIT
} McStopModeEnum;

typedef enum McIplModeEnum
{	mcIPLM_DEFAULT,
	mcIPLM_OFF,
	mcIPLM_LINEAR,
	mcIPLM_QUADRATIC,
	mcIPLM_QUADRATIC_NO_OVERSHOOT
} McIplModeEnum;

typedef enum McErrorCmdEnum
{	mcWARNING_CMD = 0,
	mcERROR_CMD,
	mcERROR_STOP_CMD,
	mcERROR_STOP_CTRL_OFF_CMD,
	mcERROR_V_STOP_CTRL_OFF_CMD,
	mcERROR_COAST_TO_STANDSTILL_CMD,
	mcERROR_INDUCTION_HALT_CMD
} McErrorCmdEnum;

typedef enum McEdgeEnum
{	mcEDGE_POSITIVE,
	mcEDGE_NEGATIVE,
	mcEDGE_MIDDLE
} McEdgeEnum;

typedef enum McNetworkTypeEnum
{	mcNETWORK_POWERLINK
} McNetworkTypeEnum;

typedef enum McTransitionModeEnum
{	mcTM_NONE
} McTransitionModeEnum;

typedef enum McExecutionModeEnum
{	mcEM_IMMEDIATELY
} McExecutionModeEnum;

typedef enum McCoordinateSystemEnum
{	mcACS = 0,
	mcMCS = 1,
	mcPCS = 2,
	mcSCS1 = 3,
	mcSCS2 = 4,
	mcSCS3 = 5,
	mcSCS4 = 6,
	mcSCS5 = 7,
	mcTCS = 9,
	mcGCS = 10,
	mcJACS = 100
} McCoordinateSystemEnum;

typedef enum McValueSrcEnum
{	mcVALUE_SET,
	mcVALUE_ACTUAL,
	mcVALUE_SET_AXIS_UNITS,
	mcVALUE_ACTUAL_AXIS_UNITS,
	mcVALUE_AUTOMATIC_SELECTION,
	mcVALUE_ALT1,
	mcVALUE_ALT2,
	mcVALUE_ALT3,
	mcVALUE_ALT4,
	mcVALUE_ALT5,
	mcVALUE_ALT6,
	mcVALUE_ALT7,
	mcVALUE_ALT8
} McValueSrcEnum;

typedef enum McAltValueSrcEnum
{	mcALT_VALUE_NOT_USED = 0,
	mcALT_VALUE1 = 1,
	mcALT_VALUE2 = 2,
	mcALT_VALUE3 = 3,
	mcALT_VALUE4 = 4,
	mcALT_VALUE5 = 5,
	mcALT_VALUE6 = 6,
	mcALT_VALUE7 = 7,
	mcALT_VALUE8 = 8
} McAltValueSrcEnum;

typedef enum McSwitchEnum
{	mcSWITCH_OFF,
	mcSWITCH_ON
} McSwitchEnum;

typedef enum McProcessParamModeEnum
{	mcPPM_READ,
	mcPPM_WRITE,
	mcPPM_LOAD_FROM_CONFIG,
	mcPPM_SAVE_TO_CONFIG
} McProcessParamModeEnum;

typedef enum McProcessConfigModeEnum
{	mcPCM_LOAD,
	mcPCM_SAVE
} McProcessConfigModeEnum;

typedef enum McCommunicationStateEnum
{	mcCOMM_STATE_NOT_ACTIVE = 0,
	mcCOMM_STATE_WAITING = 100,
	mcCOMM_STATE_CONNECTED = 200,
	mcCOMM_STATE_FW_UPDATE = 300,
	mcCOMM_STATE_CONFIG = 400,
	mcCOMM_STATE_ACTIVATING = 500,
	mcCOMM_STATE_ACTIVE = 600,
	mcCOMM_STATE_INACTIVE = 700,
	mcCOMM_STATE_FAILED = 1000
} McCommunicationStateEnum;

typedef enum McCfgTypeEnum
{	mcCFG_NONE = 0,
	mcCFG_MMCFG = 10,
	mcCFG_WS = 800,
	mcCFG_TOOLTBL = 900,
	mcCFG_FRMTBL = 1000,
	mcCFG_DYNPARTBL = 1100,
	mcCFG_TOOL = 1300,
	mcCFG_LIMSET_LIN = 1411,
	mcCFG_LIMSET_ROT = 1412,
	mcCFG_PROC_PT_LST = 1600,
	mcCFG_AX = 10000,
	mcCFG_AX_BASE_TYP = 10011,
	mcCFG_AX_MOVE_LIM = 10012,
	mcCFG_AX_FEAT_CAM_AUT_CMN = 10101,
	mcCFG_AX_FEAT_PROF_GEN = 10102,
	mcCFG_AX_FEAT_DIG_CAM_SW = 10103,
	mcCFG_AX_FEAT_CAM_LST = 11102,
	mcCFG_AX_FEAT_ALT_VAL_SRC = 10104,
	mcCFG_AX_FEAT_BRK = 10105,
	mcCFG_AX_FEAT_MECH_DEV_COMP = 10106,
	mcCFG_MOT_SYN = 10500,
	mcCFG_MOT_INDUCT = 10501,
	mcCFG_IO_PL_IN_CARD = 10510,
	mcCFG_ACP_AX = 11000,
	mcCFG_ACP_AX_REF = 11011,
	mcCFG_ACP_MECH_ELM = 11012,
	mcCFG_ACP_ENC_LINK = 11013,
	mcCFG_ACP_CTRL = 11014,
	mcCFG_ACP_HOME = 11015,
	mcCFG_ACP_STOP_REAC = 11016,
	mcCFG_ACP_MOVE_ERR_LIM = 11017,
	mcCFG_ACP_JERK_FLTR = 11018,
	mcCFG_ACP_DIG_IN = 11019,
	mcCFG_ACP_SIM = 11020,
	mcCFG_ACP_AX_FEAT = 11021,
	mcCFG_ACP_AUX_PWR_SUP_MOD = 11030,
	mcCFG_ACP_PSM_PWR_SEC = 11031,
	mcCFG_ACP_PWR_SUP = 11040,
	mcCFG_ACP_ENC = 11045,
	mcCFG_ACP_VIRT_AX = 11050,
	mcCFG_ACP_VIRT_AX_REF = 11051,
	mcCFG_ACP_VIRT_HOME = 11052,
	mcCFG_ACP_VIRT_JERK_FLTR = 11053,
	mcCFG_ACP_VIRT_AX_FEAT = 11054,
	mcCFG_ACP_CH_FEAT = 11060,
	mcCFG_ACP_EXT_ENC_AX = 11070,
	mcCFG_ACP_EXT_ENC_AX_REF = 11071,
	mcCFG_ACP_EXT_ENC_AX_ENC_LINK = 11072,
	mcCFG_ACP_EXT_ENC_AX_MECH_ELM = 11073,
	mcCFG_ACP_EXT_ENC_AX_HOME = 11074,
	mcCFG_AX_FEAT_CAM_AUT_ACP = 11101,
	mcCFG_AX_FEAT_A_IN = 11103,
	mcCFG_AX_FEAT_ACP_PAR_TBL = 11104,
	mcCFG_PURE_V_AX = 12000,
	mcCFG_PURE_V_AX_REF = 12011,
	mcCFG_PURE_V_AX_HOME = 12012,
	mcCFG_PURE_V_AX_JERK_FLTR = 12013,
	mcCFG_PURE_V_AX_FEAT = 12014,
	mcCFG_PURE_V_AX_MECH_ELM = 12015,
	mcCFG_PURE_V_AX_ENC_LINK = 12016,
	mcCFG_PURE_V_AX_CTRL = 12017,
	mcCFG_PURE_V_AX_STOP_REAC = 12018,
	mcCFG_PURE_V_AX_MOVE_ERR_LIM = 12019,
	mcCFG_PURE_V_AX_DIG_IN = 12020,
	mcCFG_PURE_V_AX_STAT_IN = 12021,
	mcCFG_PURE_V_AX_CTRL_OUT = 12022,
	mcCFG_STP_AX = 13000,
	mcCFG_STP_AX_REF = 13011,
	mcCFG_STP_AX_MECH_ELM = 13012,
	mcCFG_STP_AX_MOT = 13013,
	mcCFG_STP_AX_ENC_LINK = 13014,
	mcCFG_STP_AX_CTRL = 13015,
	mcCFG_STP_AX_HOME = 13016,
	mcCFG_STP_AX_STOP_REAC = 13017,
	mcCFG_STP_AX_MOVE_ERR_LIM = 13018,
	mcCFG_STP_AX_JERK_FLTR = 13019,
	mcCFG_STP_AX_DIG_IN = 13020,
	mcCFG_STP_AX_DIG_OUT = 13021,
	mcCFG_STP_AX_FEAT = 13022,
	mcCFG_STP_ENC = 13100,
	mcCFG_DS402_AX = 13500,
	mcCFG_DS402_INV_AX = 13501,
	mcCFG_DS402_AX_REF = 13511,
	mcCFG_DS402_AX_MECH_ELM = 13512,
	mcCFG_DS402_AX_ENC_SET = 13513,
	mcCFG_DS402_AX_POS_ACT_VAL_RNG = 13514,
	mcCFG_DS402_AX_CYC_SET_VAL_MOD = 13515,
	mcCFG_DS402_AX_FEAT = 13516,
	mcCFG_ACP_INV_AX = 13600,
	mcCFG_ACP_INV_AX_REF = 13611,
	mcCFG_ACP_INV_AX_MECH_ELM = 13612,
	mcCFG_AXGRP_ADMIN = 20000,
	mcCFG_AXGRP_FEAT_HOME_ORD = 20101,
	mcCFG_AXGRP_FEAT_PWR_ON_ORD = 20102,
	mcCFG_AXGRP_FEAT_EX_SNG_AX = 20103,
	mcCFG_AXGRP_FEAT_SHR_BRK_SIG = 20104,
	mcCFG_AXGRP_PATHGEN = 21000,
	mcCFG_AXGRP_PATHGEN_BASE_SET = 21013,
	mcCFG_AXGRP_FEAT_PRG = 21101,
	mcCFG_AXGRP_FEAT_COMP = 21102,
	mcCFG_AXGRP_FEAT_CDC = 21103,
	mcCFG_AXGRP_FEAT_FF = 21104,
	mcCFG_AXGRP_FEAT_FRM_HIER_STD = 21105,
	mcCFG_AXGRP_FEAT_FRM_HIER_CUS = 21106,
	mcCFG_AXGRP_FEAT_JOG = 21107,
	mcCFG_AXGRP_FEAT_LAH = 21108,
	mcCFG_AXGRP_FEAT_MFUN = 21109,
	mcCFG_AXGRP_FEAT_MON_ELEM = 21110,
	mcCFG_AXGRP_FEAT_MP_LOG = 21111,
	mcCFG_AXGRP_FEAT_PATH_DEF = 21112,
	mcCFG_AXGRP_FEAT_PRG_SIM = 21113,
	mcCFG_AXGRP_FEAT_SPINDLES = 21114,
	mcCFG_AXGRP_FEAT_TOOL = 21115,
	mcCFG_AXGRP_FEAT_WSM = 21116,
	mcCFG_AXGRP_FEAT_EX_PATH_AX = 21117,
	mcCFG_AXGRP_FEAT_PROBE = 21118,
	mcCFG_AXGRP_FEAT_SIG = 21119,
	mcCFG_AXGRP_FEAT_2D_COMP = 21120,
	mcCFG_AXGRP_FEAT_3D_COMP = 21121,
	mcCFG_AXGRP_FEAT_PATH_PREVIEW = 21122,
	mcCFG_AXGRP_FEAT_TAN_TOOL = 21124,
	mcCFG_AXGRP_FEAT_REV_MOVE = 21125,
	mcCFG_ASM = 31000,
	mcCFG_ASM_FEAT_CPLG = 31101,
	mcCFG_ASM_FEAT_SIM_SH_DEF = 31102,
	mcCFG_ASM_FEAT_SH_TRACE = 31103,
	mcCFG_ASM_FEAT_SH_AUT_ATT = 31104,
	mcCFG_ASM_FEAT_LOC_LIM = 31105,
	mcCFG_ASM_FEAT_EX_SEG = 31106,
	mcCFG_ASM_FEAT_SH_SHP_REG = 31107,
	mcCFG_SEC_COMP = 31301,
	mcCFG_SEC_SUB = 31302,
	mcCFG_SH_STEREO_TYP = 31400,
	mcCFG_SEG = 31500,
	mcCFG_MS_CUS_STD = 50001,
	mcCFG_MS_2AX_CNC_XY = 51201,
	mcCFG_MS_2AX_CNC_XZ = 51202,
	mcCFG_MS_2AX_CNC_YZ = 51203,
	mcCFG_MS_3AX_CNC_XYZ = 51301,
	mcCFG_MS_3AX_CNC_XZC = 51302,
	mcCFG_MS_3AX_CNC_XZB = 51303,
	mcCFG_MS_4AX_CNC_XYZB = 51401,
	mcCFG_MS_4AX_CNC_XYZC = 51402,
	mcCFG_MS_5AX_CNC_XYZCA = 51504,
	mcCFG_MS_6AX_CNC_ZXYBCA = 51603,
	mcCFG_MS_4AX_SCARA_A = 52041,
	mcCFG_MS_2AX_DELTA_A = 52121,
	mcCFG_MS_3AX_DELTA_A = 52131,
	mcCFG_MS_3AX_DELTA_XZB = 52132,
	mcCFG_MS_3AX_DELTA_B = 52133,
	mcCFG_MS_4AX_DELTA_A = 52141,
	mcCFG_MS_4AX_DELTA_B = 52142,
	mcCFG_MS_4AX_DELTA_C = 52143,
	mcCFG_MS_5AX_DELTA_A = 52151,
	mcCFG_MS_3AX_ROB_A = 52301,
	mcCFG_MS_4AX_ROB_A = 52401,
	mcCFG_MS_4AX_ROB_B = 52402,
	mcCFG_MS_5AX_ROB_A = 52501,
	mcCFG_MS_5AX_ROB_B = 52502,
	mcCFG_MS_6AX_ROB_A = 52601,
	mcCFG_MS_6AX_ROB_B = 52602,
	mcCFG_MS_6AX_ROB_C = 52603
} McCfgTypeEnum;

typedef enum McMMCProcProcTskCEnum
{	mcMMCPPTC_CYC_1 = 1,
	mcMMCPPTC_CYC_2 = 2
} McMMCProcProcTskCEnum;

typedef enum McMMCLogSelEnum
{	mcMMCLS_NOT_USE = 0,
	mcMMCLS_USE = 1
} McMMCLogSelEnum;

typedef enum McCfgVisEnum
{	mcCV_VIS = 0,
	mcCV_SUP = 1
} McCfgVisEnum;

typedef enum McMMCLogSelUseAdmCmdEnum
{	mcMMCLSUAC_VIS = 0,
	mcMMCLSUAC_SUP = 1,
	mcMMCLSUAC_SEL = 2
} McMMCLogSelUseAdmCmdEnum;

typedef enum McMMCLogSelUseMoveCmdEnum
{	mcMMCLSUMC_VIS = 0,
	mcMMCLSUMC_SUP = 1,
	mcMMCLSUMC_SEL = 2
} McMMCLogSelUseMoveCmdEnum;

typedef enum McMMCLogSelUseInfoCmdEnum
{	mcMMCLSUIC_VIS = 0,
	mcMMCLSUIC_SUP = 1,
	mcMMCLSUIC_SEL = 2
} McMMCLogSelUseInfoCmdEnum;

typedef enum McMMCLogSelUseSupSubcEEnum
{	mcMMCLSUSSE_INACT = 0,
	mcMMCLSUSSE_ACT = 1
} McMMCLogSelUseSupSubcEEnum;

typedef enum McWSHalfSpcPlEnum
{	mcWSHSP_PL_XY = 0,
	mcWSHSP_PL_YZ = 1,
	mcWSHSP_PL_ZX = 2
} McWSHalfSpcPlEnum;

typedef enum McLSPosEnum
{	mcLSP_NOT_USE = 0,
	mcLSP_USE = 1
} McLSPosEnum;

typedef enum McLSVelEnum
{	mcLSV_NOT_USE = 0,
	mcLSV_BASIC = 1,
	mcLSV_ADV = 2
} McLSVelEnum;

typedef enum McLSAccEnum
{	mcLSA_NOT_USE = 0,
	mcLSA_BASIC = 1,
	mcLSA_ADV = 2
} McLSAccEnum;

typedef enum McLSDecEnum
{	mcLSD_NOT_USE = 0,
	mcLSD_BASIC = 1,
	mcLSD_ADV = 2
} McLSDecEnum;

typedef enum McCfgLimJerkEnum
{	mcCLJ_NOT_USE = 0,
	mcCLJ_BASIC = 1,
	mcCLJ_ADV = 2
} McCfgLimJerkEnum;

typedef enum McCfgLimForEnum
{	mcCLF_NOT_USE = 0,
	mcCLF_BASIC = 1,
	mcCLF_ADV = 2
} McCfgLimForEnum;

typedef enum McCfgLimTorqEnum
{	mcCLT_NOT_USE = 0,
	mcCLT_BASIC = 1,
	mcCLT_ADV = 2
} McCfgLimTorqEnum;

typedef enum McPPLPtEnum
{	mcPPLP_TRAK_PT = 0
} McPPLPtEnum;

typedef enum McPPLPtTrakPtPosRelToEnum
{	mcPPLPTPPRT_ST_OF_SEC = 0,
	mcPPLPTPPRT_END_OF_SEC = 1
} McPPLPtTrakPtPosRelToEnum;

typedef enum McPPLPtTrakPtBarrFunEnum
{	mcPPLPTPBF_OFF = 0,
	mcPPLPTPBF_ON = 1
} McPPLPtTrakPtBarrFunEnum;

typedef enum McCfgLocLenUnitEnum
{	mcCLLU_G_SET = 0,
	mcCLLU_MILL = 5066068,
	mcCLLU_M = 5067858,
	mcCLLU_INCH = 4804168,
	mcCLLU_GEN = -1
} McCfgLocLenUnitEnum;

typedef enum McCfgCntDirEnum
{	mcCCD_STD = 0,
	mcCCD_INV = 1
} McCfgCntDirEnum;

typedef enum McCfgLocRotUnitEnum
{	mcCLRU_G_SET = 0,
	mcCLRU_DEG = 17476,
	mcCLRU_GRAD = 4274481,
	mcCLRU_REV = 5059636,
	mcCLRU_GEN = -1
} McCfgLocRotUnitEnum;

typedef enum McPTCEnum
{	mcPTC_CYC_1 = 1,
	mcPTC_USE_MP_MOT_SET = 255
} McPTCEnum;

typedef enum McCfgVarDatTypEnum
{	mcCVDT_TYP_BOOL = 0,
	mcCVDT_TYP_SINT = 1,
	mcCVDT_TYP_USINT = 2,
	mcCVDT_TYP_INT = 3,
	mcCVDT_TYP_UINT = 4,
	mcCVDT_TYP_DINT = 5,
	mcCVDT_TYP_UDINT = 6,
	mcCVDT_TYP_REAL = 7,
	mcCVDT_TYP_LREAL = 8,
	mcCVDT_TYP_STRING = 9,
	mcCVDT_TYP_DER = 10
} McCfgVarDatTypEnum;

typedef struct McAdvMoveCycParType
{	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McSwitchEnum DisableJoltLimitation;
	enum McAltValueSrcEnum AlternativeValueSource;
} McAdvMoveCycParType;

typedef struct McOrientType
{	unsigned long Type;
	double Angle1;
	double Angle2;
	double Angle3;
} McOrientType;

typedef struct McPosType
{	double X;
	double Y;
	double Z;
} McPosType;

typedef struct McFrameType
{	struct McPosType Pos;
	struct McOrientType Orient;
} McFrameType;

typedef struct McInternalFubProcessingType
{	signed long states[2];
} McInternalFubProcessingType;

typedef struct McInternalControlIfType
{	plcdword vtable;
} McInternalControlIfType;

typedef struct McInternalType
{	unsigned long ID;
	unsigned long Check;
	unsigned long ParamHash;
	plcword State;
	unsigned short Error;
	struct McInternalFubProcessingType* Treating;
	unsigned long Memory[14];
	unsigned char Flags;
	struct McInternalControlIfType* ControlIf;
	signed long SeqNo;
} McInternalType;

typedef struct McInternalTwoRefType
{	struct McInternalType Internal;
	struct McInternalControlIfType* MaControlIf;
	signed long MaSeqNo;
} McInternalTwoRefType;

typedef struct McInternalMappLinkType
{	unsigned long Internal[2];
} McInternalMappLinkType;

typedef struct McInternalMotionCfgIfType
{	plcdword vtable;
} McInternalMotionCfgIfType;

typedef struct McInternalAxisIfType
{	plcdword vtable;
} McInternalAxisIfType;

typedef struct McInternalAxesGroupIfType
{	plcdword vtable;
} McInternalAxesGroupIfType;

typedef struct McInternalTrackingPathIfType
{	plcdword vtable;
} McInternalTrackingPathIfType;

typedef struct McExec1InternalType
{	unsigned short i_serno;
	unsigned short i_state;
	signed long Result;
	unsigned long pInfo;
} McExec1InternalType;

typedef struct McMotionCfgType
{	struct McInternalMotionCfgIfType* controlif;
	struct McInternalMappLinkType mappLinkInternal;
} McMotionCfgType;

typedef struct McAxisType
{	struct McInternalAxisIfType* controlif;
	struct McInternalMappLinkType mappLinkInternal;
	signed long seqNo;
} McAxisType;

typedef struct McAxesGroupType
{	struct McInternalAxesGroupIfType* controlif;
	struct McInternalMappLinkType mappLinkInternal;
} McAxesGroupType;

typedef struct McTrackingPathType
{	struct McInternalTrackingPathIfType* controlif;
	struct McInternalMappLinkType mappLinkInternal;
} McTrackingPathType;

typedef struct McGetCoordSystemIdentParType
{	struct McAxesGroupType* AxesGroup;
} McGetCoordSystemIdentParType;

typedef struct McProcessParamAdvParType
{	plcstring Name[251];
} McProcessParamAdvParType;

typedef struct McCfgUnboundedArrayType
{	unsigned long NumberOfElements;
	unsigned long DataAddress;
	unsigned long NumberOfArrayElements;
} McCfgUnboundedArrayType;

typedef struct McCfgReferenceType
{	plcstring Name[251];
	enum McCfgTypeEnum ConfigType;
} McCfgReferenceType;

typedef struct McMMCProcType
{	enum McMMCProcProcTskCEnum ProcessingTaskClass;
} McMMCProcType;

typedef struct McMMCLogSelUseAdmCmdSelType
{	enum McCfgVisEnum CallerInstance;
	enum McCfgVisEnum ComponentResponse;
	enum McCfgVisEnum AdditionalInformation;
} McMMCLogSelUseAdmCmdSelType;

typedef struct McMMCLogSelUseAdmCmdType
{	enum McMMCLogSelUseAdmCmdEnum Type;
	struct McMMCLogSelUseAdmCmdSelType Selective;
} McMMCLogSelUseAdmCmdType;

typedef struct McMMCLogSelUseMoveCmdSelType
{	enum McCfgVisEnum CallerInstance;
	enum McCfgVisEnum ComponentResponse;
	enum McCfgVisEnum AdditionalInformation;
} McMMCLogSelUseMoveCmdSelType;

typedef struct McMMCLogSelUseMoveCmdType
{	enum McMMCLogSelUseMoveCmdEnum Type;
	struct McMMCLogSelUseMoveCmdSelType Selective;
} McMMCLogSelUseMoveCmdType;

typedef struct McMMCLogSelUseInfoCmdSelType
{	enum McCfgVisEnum CallerInstance;
	enum McCfgVisEnum ComponentResponse;
	enum McCfgVisEnum AdditionalInformation;
} McMMCLogSelUseInfoCmdSelType;

typedef struct McMMCLogSelUseInfoCmdType
{	enum McMMCLogSelUseInfoCmdEnum Type;
	struct McMMCLogSelUseInfoCmdSelType Selective;
} McMMCLogSelUseInfoCmdType;

typedef struct McMMCLogSelUseType
{	enum McCfgVisEnum StateChange;
	struct McMMCLogSelUseAdmCmdType AdministrativeCommands;
	struct McMMCLogSelUseMoveCmdType MovementCommands;
	struct McMMCLogSelUseInfoCmdType InformationalCommands;
	enum McMMCLogSelUseSupSubcEEnum SuppressSubcomponentEntries;
} McMMCLogSelUseType;

typedef struct McMMCLogSelType
{	enum McMMCLogSelEnum Type;
	struct McMMCLogSelUseType Used;
} McMMCLogSelType;

typedef struct McMMCLogType
{	struct McMMCLogSelType Selective;
} McMMCLogType;

typedef struct McCfgMMCfgType
{	struct McMMCProcType Processing;
	struct McMMCLogType Logger;
} McCfgMMCfgType;

typedef struct McCfgTransXYZType
{	double X;
	double Y;
	double Z;
} McCfgTransXYZType;

typedef struct McCfgOrientType
{	double Angle1;
	double Angle2;
	double Angle3;
} McCfgOrientType;

typedef struct McWSCubeDimType
{	double X;
	double Y;
	double Z;
} McWSCubeDimType;

typedef struct McWSCubeType
{	unsigned long ID;
	struct McCfgTransXYZType Translation;
	struct McCfgOrientType Orientation;
	struct McWSCubeDimType Dimension;
} McWSCubeType;

typedef struct McWSCubesType
{	struct McCfgUnboundedArrayType Cuboid;
} McWSCubesType;

typedef struct McWSHalfSpcType
{	unsigned long ID;
	struct McCfgTransXYZType Translation;
	struct McCfgOrientType Orientation;
	enum McWSHalfSpcPlEnum Plane;
} McWSHalfSpcType;

typedef struct McWSHalfSpcsType
{	struct McCfgUnboundedArrayType HalfSpace;
} McWSHalfSpcsType;

typedef struct McWSTcConeParType
{	double BaseRadius;
	double Height;
	double TopRadius;
} McWSTcConeParType;

typedef struct McWSTcConeType
{	unsigned long ID;
	struct McCfgTransXYZType Translation;
	struct McCfgOrientType Orientation;
	struct McWSTcConeParType Parameters;
} McWSTcConeType;

typedef struct McWSTcConesType
{	struct McCfgUnboundedArrayType TruncatedCone;
} McWSTcConesType;

typedef struct McWSWorkSpaceType
{	struct McWSCubesType Cuboids;
	struct McWSHalfSpcsType HalfSpaces;
	struct McWSTcConesType TruncatedCones;
} McWSWorkSpaceType;

typedef struct McWSSafeSpaceType
{	struct McWSCubesType Cuboids;
	struct McWSHalfSpcsType HalfSpaces;
	struct McWSTcConesType TruncatedCones;
} McWSSafeSpaceType;

typedef struct McCfgWorkspaceType
{	struct McWSWorkSpaceType WorkSpace;
	struct McWSSafeSpaceType SafeSpace;
} McCfgWorkspaceType;

typedef struct McFTRowType
{	unsigned short Index;
	double X;
	double Y;
	double Z;
	double Angle1;
	double Angle2;
	double Angle3;
	plcstring Description[251];
} McFTRowType;

typedef struct McCfgFrmTblType
{	struct McCfgUnboundedArrayType Row;
} McCfgFrmTblType;

typedef struct McCfgLimPosType
{	double LowerLimit;
	double UpperLimit;
} McCfgLimPosType;

typedef struct McLSPosType
{	enum McLSPosEnum Type;
	struct McCfgLimPosType Used;
} McLSPosType;

typedef struct McCfgLimVelBaseType
{	float Velocity;
} McCfgLimVelBaseType;

typedef struct McCfgLimVelAdvType
{	float Positive;
	float Negative;
} McCfgLimVelAdvType;

typedef struct McLSVelType
{	enum McLSVelEnum Type;
	struct McCfgLimVelBaseType Basic;
	struct McCfgLimVelAdvType Advanced;
} McLSVelType;

typedef struct McCfgLimAccBaseType
{	float Acceleration;
} McCfgLimAccBaseType;

typedef struct McCfgLimAccAdvType
{	float Positive;
	float Negative;
} McCfgLimAccAdvType;

typedef struct McLSAccType
{	enum McLSAccEnum Type;
	struct McCfgLimAccBaseType Basic;
	struct McCfgLimAccAdvType Advanced;
} McLSAccType;

typedef struct McCfgLimDecBaseType
{	float Deceleration;
} McCfgLimDecBaseType;

typedef struct McCfgLimDecAdvType
{	float Positive;
	float Negative;
} McCfgLimDecAdvType;

typedef struct McLSDecType
{	enum McLSDecEnum Type;
	struct McCfgLimDecBaseType Basic;
	struct McCfgLimDecAdvType Advanced;
} McLSDecType;

typedef struct McCfgLimJerkBasicType
{	float Jerk;
} McCfgLimJerkBasicType;

typedef struct McCfgLimJerkAdvType
{	float AccelerationPositive;
	float AccelerationNegative;
	float DecelerationPositive;
	float DecelerationNegative;
} McCfgLimJerkAdvType;

typedef struct McCfgLimJerkType
{	enum McCfgLimJerkEnum Type;
	struct McCfgLimJerkBasicType Basic;
	struct McCfgLimJerkAdvType Advanced;
} McCfgLimJerkType;

typedef struct McCfgLimForBasicType
{	float Force;
} McCfgLimForBasicType;

typedef struct McCfgLimForAdvType
{	float AccelerationPositive;
	float AccelerationNegative;
	float DecelerationPositive;
	float DecelerationNegative;
} McCfgLimForAdvType;

typedef struct McCfgLimForType
{	enum McCfgLimForEnum Type;
	struct McCfgLimForBasicType Basic;
	struct McCfgLimForAdvType Advanced;
} McCfgLimForType;

typedef struct McCfgLimSetLinType
{	struct McLSPosType Position;
	struct McLSVelType Velocity;
	struct McLSAccType Acceleration;
	struct McLSDecType Deceleration;
	struct McCfgLimJerkType Jerk;
	struct McCfgLimForType Force;
} McCfgLimSetLinType;

typedef struct McCfgLimTorqBasicType
{	float Torque;
} McCfgLimTorqBasicType;

typedef struct McCfgLimTorqAdvType
{	float AccelerationPositive;
	float AccelerationNegative;
	float DecelerationPositive;
	float DecelerationNegative;
} McCfgLimTorqAdvType;

typedef struct McCfgLimTorqType
{	enum McCfgLimTorqEnum Type;
	struct McCfgLimTorqBasicType Basic;
	struct McCfgLimTorqAdvType Advanced;
} McCfgLimTorqType;

typedef struct McCfgLimSetRotType
{	struct McLSPosType Position;
	struct McLSVelType Velocity;
	struct McLSAccType Acceleration;
	struct McLSDecType Deceleration;
	struct McCfgLimJerkType Jerk;
	struct McCfgLimTorqType Torque;
} McCfgLimSetRotType;

typedef struct McPPLPtTrakPtBarrFunType
{	enum McPPLPtTrakPtBarrFunEnum Type;
} McPPLPtTrakPtBarrFunType;

typedef struct McPPLPtTrakPtType
{	plcstring Name[251];
	struct McCfgReferenceType SectorReference;
	double Position;
	enum McPPLPtTrakPtPosRelToEnum PositionRelativeTo;
	unsigned short TriggerEventBufferSize;
	struct McPPLPtTrakPtBarrFunType BarrierFunctionality;
} McPPLPtTrakPtType;

typedef struct McPPLPtType
{	enum McPPLPtEnum Type;
	struct McPPLPtTrakPtType TrakPoint;
} McPPLPtType;

typedef struct McCfgProcPtLstType
{	struct McCfgUnboundedArrayType ProcessPoints;
} McCfgProcPtLstType;

typedef struct McCfgExtLimRefType
{	struct McCfgReferenceType LimitReference;
} McCfgExtLimRefType;

typedef struct McCfgGearBoxType
{	signed long Input;
	signed long Output;
} McCfgGearBoxType;

typedef struct McCfgRotToLinTrfType
{	double ReferenceDistance;
} McCfgRotToLinTrfType;

typedef struct McCfgVarDatTypTypSTRINGType
{	unsigned long Length;
} McCfgVarDatTypTypSTRINGType;

typedef struct McCfgVarDatTypTypDerType
{	plcstring Name[251];
} McCfgVarDatTypTypDerType;

typedef struct McCfgVarDatTypType
{	enum McCfgVarDatTypEnum Type;
	struct McCfgVarDatTypTypSTRINGType TypeSTRING;
	struct McCfgVarDatTypTypDerType TypeDerived;
} McCfgVarDatTypType;

typedef struct McCfgLimJerkBaseType
{	float Jerk;
} McCfgLimJerkBaseType;

typedef struct McCfgTransXType
{	double X;
} McCfgTransXType;

typedef struct McCfgTransZType
{	double Z;
} McCfgTransZType;

typedef struct McCfgTransXZType
{	double X;
	double Z;
} McCfgTransXZType;

typedef struct McCfgTransYType
{	double Y;
} McCfgTransYType;

typedef struct MC_BR_ProcessConfig
{
	/* VAR_INPUT (analog) */
	plcstring Name[251];
	unsigned long DataType;
	unsigned long DataAddress;
	enum McProcessConfigModeEnum Mode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ProcessConfig_typ;

typedef unsigned long McComponentType;

typedef struct MC_BR_ProcessParam
{
	/* VAR_INPUT (analog) */
	McComponentType Component;
	unsigned long DataType;
	unsigned long DataAddress;
	enum McProcessParamModeEnum Mode;
	struct McProcessParamAdvParType AdvancedParameters;
	enum McExecutionModeEnum ExecutionMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit Error;
} MC_BR_ProcessParam_typ;

typedef struct MC_BR_GetCoordSystemIdent
{
	/* VAR_INPUT (analog) */
	plcstring CoordSystemName[261];
	struct McGetCoordSystemIdentParType Parameter;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned long Ident;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_GetCoordSystemIdent_typ;

typedef McAxisType McPsmAxisType;

typedef McAxisType McApsmAxisType;

typedef McAxisType McConvoyType;

typedef plcstring McCfgString250Type[251];



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MC_BR_ProcessConfig(struct MC_BR_ProcessConfig* inst);
_BUR_PUBLIC void MC_BR_ProcessParam(struct MC_BR_ProcessParam* inst);
_BUR_PUBLIC void MC_BR_GetCoordSystemIdent(struct MC_BR_GetCoordSystemIdent* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MCBASE_ */

