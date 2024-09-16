/* Automation Studio generated header file */
/* Do not edit ! */
/* McAxis 5.16.2 */

#ifndef _MCAXIS_
#define _MCAXIS_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _McAxis_VERSION
#define _McAxis_VERSION 5.16.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif

#ifdef _SG4
#include <McBase.h>
#endif
 
#ifdef _SG3
#include <McBase.h>
#endif
 
#ifdef _SGC
#include <McBase.h>
#endif

/* Datatypes and datatypes of function blocks */
typedef enum McDirectionEnum
{	mcDIR_POSITIVE,
	mcDIR_NEGATIVE,
	mcDIR_CURRENT,
	mcDIR_SHORTEST_WAY,
	mcDIR_EXCEED_PERIOD = 8,
	mcDIR_UNDEFINED,
	mcDIR_BOTH
} McDirectionEnum;

typedef enum McCamAutCouplingSourceEnum
{	mcCAMAUT_COUPLING_SRC_NOT_USED,
	mcCAMAUT_COUPLING_SRC_AXIS,
	mcCAMAUT_COUPLING_SRC_VARIABLE,
	mcCAMAUT_COUPLING_SRC_SYSTIME
} McCamAutCouplingSourceEnum;

typedef enum McPlcopenParEnum
{	mcPAR_COMMANDED_AX_POSITION = 1,
	mcPAR_SW_LIMIT_POSITIVE,
	mcPAR_SW_LIMIT_NEGATIVE,
	mcPAR_ENABLE_LIMIT_POSITIVE,
	mcPAR_ENABLE_LIMIT_NEGATIVE,
	mcPAR_ENABLE_POS_LAG_MONITORING,
	mcPAR_MAX_AX_POSITION_LAG,
	mcPAR_MAX_AX_VELOCITY_SYSTEM,
	mcPAR_MAX_AX_VELOCITY_APPL,
	mcPAR_ACTUAL_AX_VELOCITY,
	mcPAR_COMMANDED_AX_VELOCITY,
	mcPAR_MAX_AX_ACCELERATION_SYSTEM,
	mcPAR_MAX_AX_ACCELERATION_APPL,
	mcPAR_MAX_AX_DECELERATION_SYSTEM,
	mcPAR_MAX_AX_DECELERATION_APPL,
	mcPAR_MAX_AX_JERK,
	mcPAR_AX_PERIOD = 1008,
	mcPAR_SW_END_IGNORE = 1014,
	mcPAR_HOMING_OFFSET = 1019,
	mcPAR_AX_MEASUREMENT_RESOLUTION = 1020,
	mcPAR_REFERENCE_PULSE_DISTANCE = 1021,
	mcPAR_DISTANCE_PER_ENCODER_REV = 1022
} McPlcopenParEnum;

typedef enum McCamIplModeEnum
{	mcCAMIPL_CUBIC_SPLINE,
	mcCAMIPL_OPTIMIZED_VELOCITY,
	mcCAMIPL_OPTIMIZED_ACCELERATION,
	mcCAMIPL_BESTFIT_5TH_ORDER,
	mcCAMIPL_BESTFIT_6TH_ORDER
} McCamIplModeEnum;

typedef enum McCamTypeEnum
{	mcCAMTYPE_NON_PERIODIC,
	mcCAMTYPE_PERIODIC
} McCamTypeEnum;

typedef enum McCamSectRefPointEnum
{	mcCAMSECTREF_ABSOLUTE = 0,
	mcCAMSECTREF_RELATIVE = 1
} McCamSectRefPointEnum;

typedef enum McCamSectLawOfMotionEnum
{	mcCAMSECTLAW_LAST_POINT = 0,
	mcCAMSECTLAW_STRAIGHT_LINE = 1,
	mcCAMSECTLAW_QUADRATIC_PARABOLA = 2,
	mcCAMSECTLAW_SIMPLE_SINE_CURVE = 3,
	mcCAMSECTLAW_5TH_ORDER_POLYNOM = 4,
	mcCAMSECTLAW_INCLINED_SINE_CURVE = 5,
	mcCAMSECTLAW_MOD_ACCEL_TRAPEZOID = 6,
	mcCAMSECTLAW_MOD_SINE_CURVE = 7,
	mcCAMSECTLAW_HARMONIC_COMBI = 8
} McCamSectLawOfMotionEnum;

typedef enum McEventSrcEnum
{	mcEVENT_SRC_TRIGGER1 = 0,
	mcEVENT_SRC_TRIGGER2 = 1,
	mcEVENT_SRC_ALT_VALUE1 = 2,
	mcEVENT_SRC_ALT_VALUE2 = 3,
	mcEVENT_SRC_ALT_VALUE3 = 4,
	mcEVENT_SRC_ALT_VALUE4 = 5,
	mcEVENT_SRC_ALT_VALUE5 = 6,
	mcEVENT_SRC_ALT_VALUE6 = 7,
	mcEVENT_SRC_ALT_VALUE7 = 8,
	mcEVENT_SRC_ALT_VALUE8 = 9
} McEventSrcEnum;

typedef enum McBrTouchProbeModeEnum
{	mcTP_MODE_WITHOUT_PERIOD = 4,
	mcTP_MODE_SHIFT_FROM_RESULT = 49,
	mcTP_MODE_SHIFT_FROM_EXPECTED = 50
} McBrTouchProbeModeEnum;

typedef enum McBrTriggerInfoStatusEnum
{	mcTRG_STAT_WAITING = 0,
	mcTRG_STAT_VALID = 1,
	mcTRG_STAT_MISSED = 2
} McBrTriggerInfoStatusEnum;

typedef enum McDisableModeEnum
{	mcDISABLE_DEFAULT = 0,
	mcDISABLE_KEEP_VALUE = 1
} McDisableModeEnum;

typedef enum McEventMoveModeEnum
{	mcEVENT_ONCE = 0,
	mcEVENT_CYCLIC = 1,
	mcEVENT_CYCLIC_ALL_EVENTS = 2
} McEventMoveModeEnum;

typedef enum McMechDevCompStateEnum
{	mcMDC_STATE_NOT_ACTIVE,
	mcMDC_STATE_INIT,
	mcMDC_STATE_ACTIVE_DIR_INDEP,
	mcMDC_STATE_ACTIVE_DIR_DEP,
	mcMDC_STATE_ERROR
} McMechDevCompStateEnum;

typedef enum McShiftModeEnum
{	mcSHIFT_ABSOLUTE,
	mcSHIFT_RELATIVE,
	mcSHIFT_ABSOLUTE_NO_RESET,
	mcSHIFT_RELATIVE_NO_RESET
} McShiftModeEnum;

typedef enum McProfileBaseEnum
{	mcPROFBASE_TIME,
	mcPROFBASE_MASTER_POSITION,
	mcPROFBASE_MASTER_DISTANCE,
	mcPROFBASE_SLAVE_POSITION,
	mcPROFBASE_SLAVE_DISTANCE,
	mcPROFBASE_MASTER_ZONE,
	mcPROFBASE_SLAVE_ZONE
} McProfileBaseEnum;

typedef enum McCamAutCrossLeftBoundEnum
{	mcCAMAUT_LIMIT_HORIZONTAL,
	mcCAMAUT_EXTEND_POLY
} McCamAutCrossLeftBoundEnum;

typedef enum McCamAutCamChangeImmedEnum
{	mcCAMAUT_MASTER_DIR,
	mcCAMAUT_POSITIVE_DIR
} McCamAutCamChangeImmedEnum;

typedef enum McCamAutErrorsInStandbyEnum
{	mcCAMAUT_ERRORS_OFF,
	mcCAMAUT_ERRORS_ON
} McCamAutErrorsInStandbyEnum;

typedef enum McCamAutExceedingLimitsEnum
{	mcCAMAUT_WARNING,
	mcCAMAUT_ERROR
} McCamAutExceedingLimitsEnum;

typedef enum McCamAutGetParCmdEnum
{	mcGET_PAR_FROM_OBJECT,
	mcGET_PAR_ACTUAL,
	mcGET_PAR_DEFAULT
} McCamAutGetParCmdEnum;

typedef enum McCamAutSetParCmdEnum
{	mcSET_ALL_PAR_FROM_OBJ,
	mcSET_ALL_PAR_FROM_ADR,
	mcSET_ALL_PAR_DEFAULT,
	mcSET_UPDATE_FROM_OBJ,
	mcSET_UPDATE_FROM_ADR,
	mcSET_UPDATE_DEFAULT,
	mcSET_SYNC_UPDATE_FROM_OBJ,
	mcSET_SYNC_UPDATE_FROM_ADR,
	mcSET_SYNC_UPDATE_DEFAULT
} McCamAutSetParCmdEnum;

typedef enum McCamAutResetCmdEnum
{	mcRESET_ALL_AUTOMAT_PARAMS,
	mcRESET_COMMON_PARAMS,
	mcRESET_ALL_STATE_PARAMS,
	mcRESET_ONE_STATE_PARAMS
} McCamAutResetCmdEnum;

typedef enum McCamAutParLockCmdEnum
{	mcCAMAUT_NO_LOCK,
	mcCAMAUT_LOCK,
	mcCAMAUT_UNLOCK_NEXT_STATE,
	mcCAMAUT_UNLOCK_SYNCHRON
} McCamAutParLockCmdEnum;

typedef enum McCamAutCompModeEnum
{	mcCOMP_OFF = 0,
	mcCOMP_BETWEEN_CAMS = 30,
	mcCOMP_BETWEEN_CAMS_DIRECT = 35,
	mcCOMP_CAM_CENTER_POINTS = 31,
	mcCOMP_MA_LATCHPOS = 32,
	mcCOMP_SL_LATCHPOS = 34,
	mcCOMP_SL_ABSOLUTE = 33,
	mcCOMP_VELOCITY_S_MA = 37,
	mcCOMP_VELOCITY_S_SL = 38,
	mcCOMP_VELOCITY_A_SL = 36,
	mcCOMP_VELOCITY_A_CYC = 39,
	mcCOMP_MA_SL_ABSOLUTE = 40
} McCamAutCompModeEnum;

typedef enum McCamAutEventTypeEnum
{	mcEVENT_OFF = 0,
	mcEVENT_START_POSITION = 10,
	mcEVENT_STATE_END = 12,
	mcEVENT_STATE_END_NEGATIVE = 13,
	mcEVENT_COUNT = 11,
	mcEVENT_SIGNAL1 = 91,
	mcEVENT_SIGNAL2 = 92,
	mcEVENT_SIGNAL3 = 93,
	mcEVENT_SIGNAL4 = 94,
	mcEVENT_TRIGGER1_P_EDGE = 20,
	mcEVENT_TRIGGER1_N_EDGE = 21,
	mcEVENT_TRIGGER2_P_EDGE = 22,
	mcEVENT_TRIGGER2_N_EDGE = 23,
	mcEVENT_AND_NEXT_TWO = 15,
	mcEVENT_PARID1 = 16,
	mcEVENT_PARID2 = 17,
	mcEVENT_PARID3 = 18,
	mcEVENT_PARID4 = 19,
	mcEVENT_START_IV_POS1 = 41,
	mcEVENT_START_IV_POS2 = 42,
	mcEVENT_START_IV_POS3 = 43,
	mcEVENT_START_IV_POS4 = 44
} McCamAutEventTypeEnum;

typedef enum McCamAutMaStartPosModeEnum
{	mcCAMAUT_EVALUATE_NEW,
	mcCAMAUT_NO_NEW_EVALUATION
} McCamAutMaStartPosModeEnum;

typedef enum McCamAutEventTransitionEnum
{	mcEVENT_IMMEDIATELY = 0,
	mcEVENT_END_OF_STATE = 12
} McCamAutEventTransitionEnum;

typedef enum McCamStartModeEnum
{	mcCAM_START_DIRECT,
	mcCAM_START_ABSOLUTE,
	mcCAM_START_RELATIVE
} McCamStartModeEnum;

typedef enum McCamInStatusEnum
{	mcCAM_STATUS_PREPARING_MOVE,
	mcCAM_STATUS_MOVE_TO_START_POS,
	mcCAM_STATUS_PREPARING_CAM,
	mcCAM_STATUS_WAIT_FOR_MASTER,
	mcCAM_STATUS_IN_CAM,
	mcCAM_STATUS_END
} McCamInStatusEnum;

typedef enum McSyncModeEnum
{	mcSYNC_MODE_POSITIVE,
	mcSYNC_MODE_NEGATIVE,
	mcSYNC_MODE_SHORTEST_WAY,
	mcSYNC_MODE_WITHIN_PERIOD
} McSyncModeEnum;

typedef enum McAdvCamInModeEnum
{	mcCAM_MASTER_INTERVAL,
	mcCAM_DIRECT,
	mcCAM_MASTER_INTERVAL_LEAD_IN,
	mcCAM_MASTER_INTERVAL_LEAD_OUT,
	mcCAM_MASTER_INTERVAL_LEAD_INOUT,
	mcCAM_DIRECT_LEAD_OUT
} McAdvCamInModeEnum;

typedef enum McAxisTypeEnum
{	mcAX_TYPE_ACP_REAL,
	mcAX_TYPE_ACP_VIRT,
	mcAX_TYPE_ACP_APSM,
	mcAX_TYPE_ACP_PS_ACTIVE,
	mcAX_TYPE_ACP_PS_PASSIVE,
	mcAX_TYPE_ACP_EXT_ENC,
	mcAX_TYPE_ACP_INV,
	mcAX_TYPE_STP,
	mcAX_TYPE_PURE_VIRT,
	mcAX_TYPE_PURE_VIRT_GPAI,
	mcAX_TYPE_DS402_SERVO,
	mcAX_TYPE_DS402_INV
} McAxisTypeEnum;

typedef enum McCamAutPrepRestartModeEnum
{	mcPREP_RESTART_POSITIVE,
	mcPREP_RESTART_NEGATIVE,
	mcPREP_RESTART_SHORTEST_WAY,
	mcPREP_RESTART_POSITIVE_WINDOW,
	mcPREP_RESTART_NEGATIVE_WINDOW,
	mcPREP_RESTART_GET_POSITION
} McCamAutPrepRestartModeEnum;

typedef enum McAdvBrCamTransCamModeEnum
{	mcCAM_MODE_DISTANCE_BASED,
	mcCAM_MODE_TIME_BASED
} McAdvBrCamTransCamModeEnum;

typedef enum McAdvBrCamTransTransModeEnum
{	mcCAM_TRANS_MODE_OFF,
	mcCAM_TRANS_MODE_ON,
	mcCAM_TRANS_MODE_OFF_LEAD_IN,
	mcCAM_TRANS_MODE_OFF_LEAD_OUT,
	mcCAM_TRANS_MODE_OFF_LEAD_IN_OUT,
	mcCAM_TRANS_MODE_ON_LEAD_IN,
	mcCAM_TRANS_MODE_ON_LEAD_OUT,
	mcCAM_TRANS_MODE_ON_LEAD_IN_OUT
} McAdvBrCamTransTransModeEnum;

typedef enum McLimitLoadModeEnum
{	mcLL_WITH_FEED_FORWARD,
	mcLL_WITHOUT_FEED_FORWARD
} McLimitLoadModeEnum;

typedef enum McAcpAxAutoTuneOrientationEnum
{	mcACPAX_ORIENTATION_HORIZONTAL,
	mcACPAX_ORIENTATION_VERTICAL
} McAcpAxAutoTuneOrientationEnum;

typedef enum McAcpAxFilterTimeModeEnum
{	mcACPAX_FILTER_TIME_USE,
	mcACPAX_FILTER_TIME_TUNE_MODE1,
	mcACPAX_FILTER_TIME_TUNE_MODE2
} McAcpAxFilterTimeModeEnum;

typedef enum McAcpAxLoopFilterModeEnum
{	mcACPAX_LOOP_FILTER_IGNORE,
	mcACPAX_LOOP_FILTER_USE,
	mcACPAX_LOOP_FILTER_TUNE_NOTCH
} McAcpAxLoopFilterModeEnum;

typedef enum McMechDevCompCmdEnum
{	mcMDC_CMD_SWITCH_ON,
	mcMDC_CMD_SWITCH_OFF,
	mcMDC_CMD_CALC_COMP_DATA
} McMechDevCompCmdEnum;

typedef enum McABTEnum
{	mcABT_LIN_BD = 0,
	mcABT_LIN = 1,
	mcABT_LIN_PER = 2,
	mcABT_ROT_BD = 10,
	mcABT_ROT = 11,
	mcABT_ROT_PER = 12
} McABTEnum;

typedef enum McAMLEnum
{	mcAML_INT = 0,
	mcAML_INT_PATH_AX = 1,
	mcAML_EXT = 2
} McAMLEnum;

typedef enum McAMoveLimVelEnum
{	mcAMLV_BASIC = 0,
	mcAMLV_ADV = 1
} McAMoveLimVelEnum;

typedef enum McAMoveLimAccEnum
{	mcAMLA_BASIC = 0,
	mcAMLA_ADV = 1
} McAMoveLimAccEnum;

typedef enum McAMoveLimDecEnum
{	mcAMLD_BASIC = 0,
	mcAMLD_ADV = 1
} McAMoveLimDecEnum;

typedef enum McAFDCSTypEnum
{	mcAFDCST_ACP = 0
} McAFDCSTypEnum;

typedef enum McAFDCSTypAcpValSrcRTOAEnum
{	mcAFDCSTAVSRTOA_NOT_USE = 0,
	mcAFDCSTAVSRTOA_USE = 1
} McAFDCSTypAcpValSrcRTOAEnum;

typedef enum McAFDCSTypAcpValSrcParIDEnum
{	mcAFDCSTAVSP_NOT_USE = 1,
	mcAFDCSTAVSP_USE = 2
} McAFDCSTypAcpValSrcParIDEnum;

typedef enum McAFDCSTypAcpOutEnum
{	mcAFDCSTAO_ACP_HW = 0,
	mcAFDCSTAO_ACP_PARID = 1
} McAFDCSTypAcpOutEnum;

typedef enum McAFDCSTypAcpOutAcpHwProdFamEnum
{	mcAFDCSTAOAHPF_ACP = 0,
	mcAFDCSTAOAHPF_ACPM = 1,
	mcAFDCSTAOAHPF_ACP_P3 = 2
} McAFDCSTypAcpOutAcpHwProdFamEnum;

typedef enum McAFDCSACOPOSDigOutEnum
{	mcAFDCSACOPOSDO_SS2X111 = 0,
	mcAFDCSACOPOSDO_SS2X112 = 1,
	mcAFDCSACOPOSDO_SS2X113 = 2,
	mcAFDCSACOPOSDO_SS2X114 = 3,
	mcAFDCSACOPOSDO_SS2X115 = 4,
	mcAFDCSACOPOSDO_SS2X116 = 5,
	mcAFDCSACOPOSDO_SS2X117 = 6,
	mcAFDCSACOPOSDO_SS2X118 = 7,
	mcAFDCSACOPOSDO_SS2X119 = 8,
	mcAFDCSACOPOSDO_SS2X1110 = 9,
	mcAFDCSACOPOSDO_SS3X111 = 10,
	mcAFDCSACOPOSDO_SS3X112 = 11,
	mcAFDCSACOPOSDO_SS3X113 = 12,
	mcAFDCSACOPOSDO_SS3X114 = 13,
	mcAFDCSACOPOSDO_SS3X115 = 14,
	mcAFDCSACOPOSDO_SS3X116 = 15,
	mcAFDCSACOPOSDO_SS3X117 = 16,
	mcAFDCSACOPOSDO_SS3X118 = 17,
	mcAFDCSACOPOSDO_SS3X119 = 18,
	mcAFDCSACOPOSDO_SS3X1110 = 19,
	mcAFDCSACOPOSDO_SS4X111 = 20,
	mcAFDCSACOPOSDO_SS4X112 = 21,
	mcAFDCSACOPOSDO_SS4X113 = 22,
	mcAFDCSACOPOSDO_SS4X114 = 23,
	mcAFDCSACOPOSDO_SS4X115 = 24,
	mcAFDCSACOPOSDO_SS4X116 = 25,
	mcAFDCSACOPOSDO_SS4X117 = 26,
	mcAFDCSACOPOSDO_SS4X118 = 27,
	mcAFDCSACOPOSDO_SS4X119 = 28,
	mcAFDCSACOPOSDO_SS4X1110 = 29
} McAFDCSACOPOSDigOutEnum;

typedef enum McAFDCSACOPOSmultiDigOutEnum
{	mcAFDCSACOPOSMULTIDO_SS1X111 = 0,
	mcAFDCSACOPOSMULTIDO_SS1X113 = 1,
	mcAFDCSACOPOSMULTIDO_SS1X115 = 2,
	mcAFDCSACOPOSMULTIDO_SS1X116 = 3
} McAFDCSACOPOSmultiDigOutEnum;

typedef enum McAFDCSACOPOSP3DigOutEnum
{	mcAFDCSACOPOSP3DO_SS1X41E1 = 0,
	mcAFDCSACOPOSP3DO_SS1X41E2 = 1,
	mcAFDCSACOPOSP3DO_SS1X41E3 = 2,
	mcAFDCSACOPOSP3DO_SS1X41E4 = 3,
	mcAFDCSACOPOSP3DO_SS1X41E5 = 4,
	mcAFDCSACOPOSP3DO_SS1X41E6 = 5,
	mcAFDCSACOPOSP3DO_SS1X41E7 = 6,
	mcAFDCSACOPOSP3DO_SS1X41E8 = 7,
	mcAFDCSACOPOSP3DO_SS1X41E9 = 8,
	mcAFDCSACOPOSP3DO_SS1X41E10 = 9
} McAFDCSACOPOSP3DigOutEnum;

typedef enum McAFAVSValSrcEnum
{	mcAFAVSVS_ACP_PARID = 0
} McAFAVSValSrcEnum;

typedef enum McAFBProdFamEnum
{	mcAFBPF_ACP = 0
} McAFBProdFamEnum;

typedef enum McAFBACPCtrlModEnum
{	mcAFBACPCM_AUT = 0,
	mcAFBACPCM_EXT = 1
} McAFBACPCtrlModEnum;

typedef enum McAFBACPCtrlModExtCmdAcptEnum
{	mcAFBACPCMECA_PWR_OFF = 0,
	mcAFBACPCMECA_ANY = 1
} McAFBACPCtrlModExtCmdAcptEnum;

typedef enum McAFBACPCtrlMonEnum
{	mcAFBACPCM_USE = 0,
	mcAFBACPCM_NOT_USE = 1
} McAFBACPCtrlMonEnum;

typedef enum McAFBACPCtrlMonUseTimeEnum
{	mcAFBACPCMUT_DEF = 0,
	mcAFBACPCMUT_USR_DEF = 1
} McAFBACPCtrlMonUseTimeEnum;

typedef enum McAFBACPMoveMonEnum
{	mcAFBACPMM_USE = 0,
	mcAFBACPMM_NOT_USE = 1
} McAFBACPMoveMonEnum;

typedef enum McAFBACPBrkTstEnum
{	mcAFBACPBT_NOT_USE = 0,
	mcAFBACPBT_AUT = 1
} McAFBACPBrkTstEnum;

typedef enum McAFBACPBrkTstAutStEvntEnum
{	mcAFBACPBTASE_CTRL_ON = 0,
	mcAFBACPBTASE_CTRL_OFF = 1,
	mcAFBACPBTASE_CTRL_ON_AND_OFF = 2,
	mcAFBACPBTASE_SAFE_BRK_TEST_ACT = 3
} McAFBACPBrkTstAutStEvntEnum;

typedef enum McMDCTypeEnum
{	mcMDCT_ACP = 0
} McMDCTypeEnum;

typedef enum McMDCACalcEnum
{	mcMDCAC_NOT_USE = 0,
	mcMDCAC_USE = 1
} McMDCACalcEnum;

typedef enum McMDCAActiEnum
{	mcMDCAA_NOT_USE = 0,
	mcMDCAA_USE = 1
} McMDCAActiEnum;

typedef enum McMDCModeEnum
{	mcMDCM_DIR_DEP_CONST_BCKL = 0,
	mcMDCM_DIR_DEP_SET_POS = 1,
	mcMDCM_DIR_IND = 2,
	mcMDCM_DIR_IND_SPD = 3,
	mcMDCM_DIR_IND_W_BCKL = 4
} McMDCModeEnum;

typedef enum McMDCPosSrcEnum
{	mcMDCPS_SET_POS = 0,
	mcMDCPS_ACT_POS = 1,
	mcMDCPS_ENC_POS = 2
} McMDCPosSrcEnum;

typedef enum McMDCStEdgEnum
{	mcMDCSE_POS = 0,
	mcMDCSE_NEG = 1
} McMDCStEdgEnum;

typedef enum McMDCCompDatEnum
{	mcMDCCD_DAT_OBJ = 0,
	mcMDCCD_F_ON_F_DEV = 1,
	mcMDCCD_PROC_VAR = 2
} McMDCCompDatEnum;

typedef enum McMDCDatIntEnum
{	mcMDCDI_NOT_PER = 0,
	mcMDCDI_PER = 1
} McMDCDatIntEnum;

typedef struct McLibraryInfoType
{	plcstring Name[33];
} McLibraryInfoType;

typedef struct McDigitalInputStatusType
{	plcbit HomingSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
	plcbit DriveEnable;
} McDigitalInputStatusType;

typedef struct McAddInfoType
{	struct McDigitalInputStatusType DigitalInputStatus;
	plcbit LagWarning;
	unsigned long StartupCount;
	enum McCommunicationStateEnum CommunicationState;
	enum McAxisPLCopenStateEnum PLCopenState;
	plcbit InMotion;
	enum McMechDevCompStateEnum MechDeviationCompState;
} McAddInfoType;

typedef struct McAdvVelCtrlParType
{	float Acceleration;
	float Deceleration;
	float Jerk;
} McAdvVelCtrlParType;

typedef struct McAdvShiftDistanceParType
{	double ProfileDistance;
} McAdvShiftDistanceParType;

typedef struct McAdvShiftZoneParType
{	double StartPosition;
	double EndPosition;
	double Period;
} McAdvShiftZoneParType;

typedef struct McAdvPhasingParType
{	enum McShiftModeEnum ShiftMode;
	enum McProfileBaseEnum ProfileBase;
	float ProfileBaseMaxVelocity;
	struct McAdvShiftDistanceParType DistanceParameters;
	struct McAdvShiftZoneParType ZoneParameters;
	float Jerk;
	enum McAltValueSrcEnum ShiftAlternativeValueSource;
} McAdvPhasingParType;

typedef struct McAdvOffsetParType
{	enum McShiftModeEnum ShiftMode;
	enum McProfileBaseEnum ProfileBase;
	float ProfileBaseMaxVelocity;
	struct McAdvShiftDistanceParType DistanceParameters;
	struct McAdvShiftZoneParType ZoneParameters;
	float Jerk;
	enum McAltValueSrcEnum ShiftAlternativeValueSource;
} McAdvOffsetParType;

typedef struct McAdvGearInParType
{	float MasterMaxVelocity;
} McAdvGearInParType;

typedef struct McAdvGearInPosParType
{	float MasterMaxVelocity;
} McAdvGearInPosParType;

typedef struct McAdvCamInParType
{	plcbit Periodic;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
} McAdvCamInParType;

typedef struct McCamDefineType
{	plcstring DataObjectName[13];
	unsigned long DataAdress;
} McCamDefineType;

typedef struct McAdvCamAutSetParType
{	enum McCamAutParLockCmdEnum ParLock;
} McAdvCamAutSetParType;

typedef struct McCamAutEventParType
{	enum McCamAutEventTypeEnum Type;
	enum McCamAutEventTransitionEnum Transition;
	enum McSwitchEnum SynchronousUpdate;
	unsigned char NextState;
} McCamAutEventParType;

typedef struct McCamAutCompParType
{	double MasterCompDistance;
	double SlaveCompDistance;
	double MasterCamLeadIn;
	double MinMasterCompDistance;
	double MinSlaveCompDistance;
	double MaxSlaveCompDistance;
	float MinSlaveCompVelocity;
	float MaxSlaveCompVelocity;
	float MaxSlaveCompAccel1;
	float MaxSlaveCompAccel2;
	float SlaveCompJoltTime;
	float SlaveCompJerk;
} McCamAutCompParType;

typedef struct McCamAutMasterAxisType
{	struct McAxisType* Axis;
	enum McValueSrcEnum ValueSource;
	float MaxVelocity;
} McCamAutMasterAxisType;

typedef struct McCamAutMasterVarType
{	double* VariableAddress;
	float MaxVelocity;
} McCamAutMasterVarType;

typedef struct McCamAutAxisType
{	struct McAxisType* Axis;
	enum McValueSrcEnum ValueSource;
} McCamAutAxisType;

typedef struct McCamAutVariableType
{	double* VariableAddress;
} McCamAutVariableType;

typedef struct McCamAutAdvStateParType
{	unsigned short RepeatCounterInit;
	enum McSwitchEnum RepeatCounterSetTransfer;
	unsigned short RepeatCounterSet;
	enum McCamAutCouplingSourceEnum MasterSource;
	struct McCamAutAxisType MasterAxis;
	struct McCamAutVariableType MasterVariable;
} McCamAutAdvStateParType;

typedef struct McCamAutStateParType
{	unsigned short CamID;
	signed long MasterFactor;
	signed long SlaveFactor;
	enum McCamAutCompModeEnum CompensationMode;
	struct McCamAutCompParType CompensationParameters;
	struct McCamAutAdvStateParType AdvancedParameters;
	struct McCamAutEventParType Event[5];
} McCamAutStateParType;

typedef struct McCamAutCtrlSettingsType
{	enum McCamAutCrossLeftBoundEnum CrossLeftBoundary;
	enum McCamAutCamChangeImmedEnum CamChangeImmediately;
} McCamAutCtrlSettingsType;

typedef struct McCamAutStartStateParType
{	unsigned char StartState;
	double MasterStartRelPos;
} McCamAutStartStateParType;

typedef struct McCamAutAddAxesType
{	enum McCamAutCouplingSourceEnum AdditiveMasterSource;
	struct McCamAutAxisType AdditiveMasterAxis;
	struct McCamAutVariableType AdditiveMasterVariable;
	enum McCamAutCouplingSourceEnum AdditiveSlaveSource;
	struct McCamAutAxisType AdditiveSlaveAxis;
	struct McCamAutVariableType AdditiveSlaveVariable;
} McCamAutAddAxesType;

typedef struct McCamAutAdvParType
{	struct McCamAutStartStateParType StartStateParam;
	struct McCamAutAddAxesType AdditiveAxes;
	enum McCamAutMaStartPosModeEnum MasterStartPosMode;
	struct McCamAutCtrlSettingsType ControlSettings;
	double StartIntervalPos1;
	double StartIntervalPos2;
	double StartIntervalPos3;
	double StartIntervalPos4;
} McCamAutAdvParType;

typedef struct McCamAutMasterParType
{	enum McCamAutCouplingSourceEnum MasterSource;
	struct McCamAutMasterAxisType MasterAxis;
	struct McCamAutMasterVarType MasterVariable;
	double MasterStartPosition;
	double MasterStartInterval;
} McCamAutMasterParType;

typedef struct McCamAutCommonParType
{	struct McCamAutMasterParType Master;
	struct McCamAutAdvParType AdvancedParameters;
} McCamAutCommonParType;

typedef struct McCamAutParType
{	struct McCamAutCommonParType Common;
	struct McCamAutStateParType State[15];
} McCamAutParType;

typedef struct McCamAutDefineType
{	plcstring DataObjectName[33];
	unsigned long DataAddress;
	unsigned long DataSize;
} McCamAutDefineType;

typedef struct McPolynomialDataType
{	float A;
	float B;
	float C;
	float D;
	float E;
	float F;
	float G;
	float X;
	unsigned long Reserve;
} McPolynomialDataType;

typedef struct McCamDataType
{	signed long MasterPeriod;
	signed long SlavePeriod;
	unsigned long PolynomialNumber;
	struct McPolynomialDataType PolynomialData[128];
} McCamDataType;

typedef struct McAdvCalcCamFromPointsParType
{	enum McCamIplModeEnum InterpolationMode;
	enum McCamTypeEnum Type;
	unsigned long NumberOfPolynomials;
	signed long MasterPeriod;
	double StartSlope;
	double StartCurvature;
	double EndSlope;
	double EndCurvature;
} McAdvCalcCamFromPointsParType;

typedef struct McCamSectionType
{	float MasterPoint;
	float SlavePoint;
	float FirstDerivative;
	float SecondDerivative;
	enum McCamSectRefPointEnum Mode;
	enum McCamSectLawOfMotionEnum Type;
	float InflectionPoint;
} McCamSectionType;

typedef struct McCamSectionsType
{	struct McCamSectionType Section[130];
} McCamSectionsType;

typedef struct McAdvCamInLeadInOutParType
{	double MasterOffset;
	double MasterDistance;
	double SlaveDistance;
	unsigned short CamID;
	signed long MasterScaling;
	signed long SlaveScaling;
	float Jerk;
} McAdvCamInLeadInOutParType;

typedef struct McAdvBrCamInParType
{	enum McAdvCamInModeEnum Mode;
	struct McAdvCamInLeadInOutParType LeadIn;
	struct McAdvCamInLeadInOutParType LeadOut;
	enum McValueSrcEnum MasterValueSource;
	float MasterMaxVelocity;
	float Jerk;
	float Deceleration;
} McAdvBrCamInParType;

typedef struct McTriggerType
{	enum McValueSrcEnum ValueSource;
	enum McEventSrcEnum EventSource;
	enum McEdgeEnum Edge;
	unsigned char TouchProbeID;
} McTriggerType;

typedef struct McBrTriggerType
{	enum McValueSrcEnum ValueSource;
	enum McEventSrcEnum EventSource;
	enum McEdgeEnum Edge;
	double MinWidth;
	double MaxWidth;
	float SensorDelay;
	plcbit DisableWidthEvaluationAtStart;
} McBrTriggerType;

typedef struct McAdvBrTouchProbeParType
{	plcbit UseFirstTriggerPosition;
	plcbit UseAxisPeriod;
	plcbit UpdatePeriod;
	plcbit ReadTriggerWidth;
} McAdvBrTouchProbeParType;

typedef struct McBrTriggerInfoType
{	double Width;
	enum McBrTriggerInfoStatusEnum Status;
} McBrTriggerInfoType;

typedef struct McDigCamSwOnPositionsParType
{	double FirstOnPosition;
	double LastOnPosition;
} McDigCamSwOnPositionsParType;

typedef struct McDigCamSwDataSetParType
{	unsigned char NumberOfSwitches;
	struct McDigCamSwOnPositionsParType SwitchPositions[64];
} McDigCamSwDataSetParType;

typedef struct McDigCamSwitchOptionsParType
{	struct McDigCamSwDataSetParType DataSet[5];
	double Period;
	double StartPosition;
} McDigCamSwitchOptionsParType;

typedef struct McDigCamSwTrackOptionsParType
{	float OnCompensation;
	float OffCompensation;
	float Filter;
	float Hysteresis;
	plcbit DisableNegativeDirection;
} McDigCamSwTrackOptionsParType;

typedef struct McDigCamSwOptionsParType
{	plcstring FeatureName[251];
} McDigCamSwOptionsParType;

typedef struct McAdvCamAutPrepRestartParType
{	double ToleranceWindow;
	double RestartPositionOffset;
} McAdvCamAutPrepRestartParType;

typedef struct McAdvCyclicTorqueFFParType
{	enum McDisableModeEnum DisableMode;
} McAdvCyclicTorqueFFParType;

typedef struct McAdvBrCamTransLeadInOutParType
{	double MasterDistance;
	double SlaveDistance;
	double MasterOffset;
	float Jerk;
} McAdvBrCamTransLeadInOutParType;

typedef struct McAdvBrCamDwellParType
{	struct McAdvBrCamTransLeadInOutParType LeadIn;
	struct McAdvBrCamTransLeadInOutParType LeadOut;
	enum McValueSrcEnum MasterValueSource;
	float MasterMaxVelocity;
	float Jerk;
	float Deceleration;
} McAdvBrCamDwellParType;

typedef struct McAdvBrAutoCamDwellParType
{	struct McAdvBrCamTransLeadInOutParType LeadIn;
	struct McAdvBrCamTransLeadInOutParType LeadOut;
	enum McValueSrcEnum MasterValueSource;
	float MasterMaxVelocity;
	float Jerk;
	float Deceleration;
} McAdvBrAutoCamDwellParType;

typedef struct McAdvBrCamTransitionParType
{	struct McAdvBrCamTransLeadInOutParType LeadIn;
	struct McAdvBrCamTransLeadInOutParType LeadOut;
	enum McValueSrcEnum MasterValueSource;
	float MasterMaxVelocity;
	float CamTime;
	enum McAdvBrCamTransCamModeEnum CamMode;
	enum McAdvBrCamTransTransModeEnum TransitionMode;
	float Jerk;
	float Deceleration;
} McAdvBrCamTransitionParType;

typedef struct McBrAdvCamSaveDatObjType
{	unsigned short DataObjectVersion;
} McBrAdvCamSaveDatObjType;

typedef struct McEventType
{	enum McEventSrcEnum Event;
	enum McEdgeEnum Edge;
} McEventType;

typedef struct McAdvEventMoveParType
{	enum McEventMoveModeEnum Mode;
	enum McAltValueSrcEnum AlternativeValueSource;
} McAdvEventMoveParType;

typedef struct McDigitalInputsPvIfType
{	plcbit HomingSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
	plcbit Quickstop;
} McDigitalInputsPvIfType;

typedef struct McAdvBrTorqueControlParType
{	plcbit NoHomingCheck;
	plcbit UseVelocityLimits;
	plcbit CorrectVelocityLimits;
	plcbit UseTimeLimit;
	float TimeLimit;
} McAdvBrTorqueControlParType;

typedef struct McAdvBrLimitLoadCamParType
{	signed long PositionFactorPos;
	signed long LoadFactorPos;
	signed long PositionFactorNeg;
	signed long LoadFactorNeg;
} McAdvBrLimitLoadCamParType;

typedef struct McMechDevCompDataType
{	double Position;
	double Deviation;
} McMechDevCompDataType;

typedef struct McMechDevCompAdvParType
{	plcstring DataObjectNamePos[13];
	plcstring DataObjectNameNeg[13];
} McMechDevCompAdvParType;

typedef struct McMechDevCompAddInfoType
{	double CamStartPositionPos;
	double CamStartPositionNeg;
} McMechDevCompAddInfoType;

typedef struct McHwInfoAxisType
{	plcstring AxisName[33];
	plcstring ConfigElementLocation[251];
	enum McAxisTypeEnum AxisType;
} McHwInfoAxisType;

typedef struct McHwInfoDriveType
{	plcstring ModelNumber[20];
	plcstring ModuleID[12];
	plcstring SerialNumber[20];
	plcstring Revision[4];
	plcstring FirmwareVersion[8];
} McHwInfoDriveType;

typedef struct McHwInfoCardType
{	plcbit InfoAvailable;
	plcstring ModelNumber[20];
	plcstring SerialNumber[20];
	plcstring Revision[4];
} McHwInfoCardType;

typedef struct McHwInfoMotorType
{	plcbit InfoAvailable;
	plcstring ModelNumber[36];
	plcstring SerialNumber[20];
	plcstring Revision[4];
} McHwInfoMotorType;

typedef struct McHardwareInfoType
{	struct McHwInfoAxisType Axis;
	struct McHwInfoDriveType Drive;
	struct McHwInfoCardType Card[4];
	struct McHwInfoMotorType Motor[3];
} McHardwareInfoType;

typedef struct McABTLinBdType
{	enum McCfgLocLenUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
} McABTLinBdType;

typedef struct McABTLinType
{	enum McCfgLocLenUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
} McABTLinType;

typedef struct McABTLinPerPerSetType
{	double Period;
} McABTLinPerPerSetType;

typedef struct McABTLinPerType
{	enum McCfgLocLenUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
	struct McABTLinPerPerSetType PeriodSettings;
} McABTLinPerType;

typedef struct McABTRotBdType
{	enum McCfgLocRotUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
} McABTRotBdType;

typedef struct McABTRotType
{	enum McCfgLocRotUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
} McABTRotType;

typedef struct McABTRotPerPerSetType
{	double Period;
} McABTRotPerPerSetType;

typedef struct McABTRotPerType
{	enum McCfgLocRotUnitEnum MeasurementUnit;
	double MeasurementResolution;
	enum McCfgCntDirEnum CountDirection;
	struct McABTRotPerPerSetType PeriodSettings;
} McABTRotPerType;

typedef struct McABTType
{	enum McABTEnum Type;
	struct McABTLinBdType LinearBounded;
	struct McABTLinType Linear;
	struct McABTLinPerType LinearPeriodic;
	struct McABTRotBdType RotaryBounded;
	struct McABTRotType Rotary;
	struct McABTRotPerType RotaryPeriodic;
} McABTType;

typedef struct McAMoveLimVelType
{	enum McAMoveLimVelEnum Type;
	struct McCfgLimVelBaseType Basic;
	struct McCfgLimVelAdvType Advanced;
} McAMoveLimVelType;

typedef struct McAMoveLimAccType
{	enum McAMoveLimAccEnum Type;
	struct McCfgLimAccBaseType Basic;
	struct McCfgLimAccAdvType Advanced;
} McAMoveLimAccType;

typedef struct McAMoveLimDecType
{	enum McAMoveLimDecEnum Type;
	struct McCfgLimDecBaseType Basic;
	struct McCfgLimDecAdvType Advanced;
} McAMoveLimDecType;

typedef struct McAMLIntType
{	struct McCfgLimPosType Position;
	struct McAMoveLimVelType Velocity;
	struct McAMoveLimAccType Acceleration;
	struct McAMoveLimDecType Deceleration;
} McAMLIntType;

typedef struct McAMLIntPathAxType
{	struct McCfgLimPosType Position;
	struct McAMoveLimVelType Velocity;
	struct McAMoveLimAccType Acceleration;
	struct McAMoveLimDecType Deceleration;
	struct McCfgLimJerkType Jerk;
	struct McCfgLimTorqType Torque;
	struct McCfgLimForType Force;
} McAMLIntPathAxType;

typedef struct McAMLType
{	enum McAMLEnum Type;
	struct McAMLIntType Internal;
	struct McAMLIntPathAxType InternalPathAxis;
	struct McCfgExtLimRefType External;
} McAMLType;

typedef struct McCfgAxType
{	struct McABTType BaseType;
	struct McAMLType MovementLimits;
} McCfgAxType;

typedef struct McCfgAxBaseTypType
{	struct McABTType BaseType;
} McCfgAxBaseTypType;

typedef struct McCfgAxMoveLimType
{	struct McAMLType MovementLimits;
} McCfgAxMoveLimType;

typedef struct McAFDCSTypAcpValSrcRTOAUseType
{	struct McCfgReferenceType AxisReference;
} McAFDCSTypAcpValSrcRTOAUseType;

typedef struct McAFDCSTypAcpValSrcRTOAType
{	enum McAFDCSTypAcpValSrcRTOAEnum Type;
	struct McAFDCSTypAcpValSrcRTOAUseType Used;
} McAFDCSTypAcpValSrcRTOAType;

typedef struct McAFDCSTypAcpValSrcParIDUseType
{	unsigned short ParID;
} McAFDCSTypAcpValSrcParIDUseType;

typedef struct McAFDCSTypAcpValSrcParIDType
{	enum McAFDCSTypAcpValSrcParIDEnum Type;
	struct McAFDCSTypAcpValSrcParIDUseType Used;
} McAFDCSTypAcpValSrcParIDType;

typedef struct McAFDCSTypAcpValSrcType
{	struct McAFDCSTypAcpValSrcRTOAType ReferenceToOtherAxis;
	struct McAFDCSTypAcpValSrcParIDType ParID;
} McAFDCSTypAcpValSrcType;

typedef struct McAFDCSACOPOSDigOutType
{	enum McAFDCSACOPOSDigOutEnum Type;
} McAFDCSACOPOSDigOutType;

typedef struct McAFDCSACOPOSType
{	struct McAFDCSACOPOSDigOutType DigitalOutput;
} McAFDCSACOPOSType;

typedef struct McAFDCSACOPOSmultiDigOutType
{	enum McAFDCSACOPOSmultiDigOutEnum Type;
} McAFDCSACOPOSmultiDigOutType;

typedef struct McAFDCSACOPOSmultiType
{	struct McAFDCSACOPOSmultiDigOutType DigitalOutput;
} McAFDCSACOPOSmultiType;

typedef struct McAFDCSACOPOSP3DigOutType
{	enum McAFDCSACOPOSP3DigOutEnum Type;
} McAFDCSACOPOSP3DigOutType;

typedef struct McAFDCSACOPOSP3Type
{	struct McAFDCSACOPOSP3DigOutType DigitalOutput;
} McAFDCSACOPOSP3Type;

typedef struct McAFDCSTypAcpOutAcpHwProdFamType
{	enum McAFDCSTypAcpOutAcpHwProdFamEnum Type;
	struct McAFDCSACOPOSType ACOPOS;
	struct McAFDCSACOPOSmultiType ACOPOSmulti;
	struct McAFDCSACOPOSP3Type ACOPOSP3;
} McAFDCSTypAcpOutAcpHwProdFamType;

typedef struct McAFDCSTypAcpOutAcpHwType
{	struct McAFDCSTypAcpOutAcpHwProdFamType ProductFamily;
} McAFDCSTypAcpOutAcpHwType;

typedef struct McAFDCSTypAcpOutAcpParIDType
{	unsigned short ParID;
} McAFDCSTypAcpOutAcpParIDType;

typedef struct McAFDCSTypAcpOutType
{	enum McAFDCSTypAcpOutEnum Type;
	struct McAFDCSTypAcpOutAcpHwType ACOPOSHardware;
	struct McAFDCSTypAcpOutAcpParIDType ACOPOSParID;
} McAFDCSTypAcpOutType;

typedef struct McAFDCSTypAcpType
{	struct McAFDCSTypAcpValSrcType ValueSource;
	struct McAFDCSTypAcpOutType Output;
} McAFDCSTypAcpType;

typedef struct McAFDCSTypType
{	enum McAFDCSTypEnum Type;
	struct McAFDCSTypAcpType ACOPOS;
} McAFDCSTypType;

typedef struct McCfgAxFeatDigCamSwType
{	struct McAFDCSTypType DigitalCamSwitchType;
} McCfgAxFeatDigCamSwType;

typedef struct McAFAVSValSrcAcpParIDType
{	unsigned short ParID;
} McAFAVSValSrcAcpParIDType;

typedef struct McAFAVSValSrcType
{	enum McAFAVSValSrcEnum Type;
	struct McAFAVSValSrcAcpParIDType ACOPOSParID;
} McAFAVSValSrcType;

typedef struct McCfgAxFeatAltValSrcType
{	struct McCfgUnboundedArrayType ValueSource;
} McCfgAxFeatAltValSrcType;

typedef struct McAFBACPCtrlModExtType
{	enum McAFBACPCtrlModExtCmdAcptEnum CommandAcceptance;
} McAFBACPCtrlModExtType;

typedef struct McAFBACPCtrlModType
{	enum McAFBACPCtrlModEnum Type;
	struct McAFBACPCtrlModExtType External;
} McAFBACPCtrlModType;

typedef struct McAFBACPCtrlMonUseTimeUsrDefType
{	float FilterTime;
} McAFBACPCtrlMonUseTimeUsrDefType;

typedef struct McAFBACPCtrlMonUseTimeType
{	enum McAFBACPCtrlMonUseTimeEnum Type;
	struct McAFBACPCtrlMonUseTimeUsrDefType UserDefined;
} McAFBACPCtrlMonUseTimeType;

typedef struct McAFBACPCtrlMonUseType
{	struct McAFBACPCtrlMonUseTimeType Time;
} McAFBACPCtrlMonUseType;

typedef struct McAFBACPCtrlMonType
{	enum McAFBACPCtrlMonEnum Type;
	struct McAFBACPCtrlMonUseType Used;
} McAFBACPCtrlMonType;

typedef struct McAFBACPBrkTstAutType
{	enum McAFBACPBrkTstAutStEvntEnum StartEvent;
	float Torque;
	float TorqueSlewRate;
	float Duration;
} McAFBACPBrkTstAutType;

typedef struct McAFBACPBrkTstType
{	enum McAFBACPBrkTstEnum Type;
	struct McAFBACPBrkTstAutType Automatic;
} McAFBACPBrkTstType;

typedef struct McAFBACPMoveMonUseType
{	float PositionErrorLimit;
	struct McAFBACPBrkTstType BrakeTest;
} McAFBACPMoveMonUseType;

typedef struct McAFBACPMoveMonType
{	enum McAFBACPMoveMonEnum Type;
	struct McAFBACPMoveMonUseType Used;
} McAFBACPMoveMonType;

typedef struct McAFBACPType
{	struct McAFBACPCtrlModType ControlMode;
	struct McAFBACPCtrlMonType ControlMonitoring;
	struct McAFBACPMoveMonType MovementMonitoring;
} McAFBACPType;

typedef struct McAFBProdFamType
{	enum McAFBProdFamEnum Type;
	struct McAFBACPType ACOPOS;
} McAFBProdFamType;

typedef struct McCfgAxFeatBrkType
{	struct McAFBProdFamType ProductFamily;
} McCfgAxFeatBrkType;

typedef struct McMDCDirDepConstBcklType
{	double Backlash;
	enum McMDCPosSrcEnum PositionSource;
	enum McMDCStEdgEnum StartEdge;
	float Velocity;
	float TimeConstant;
	float NoiseLimit;
} McMDCDirDepConstBcklType;

typedef struct McMDCCompDatObjType
{	plcstring DataObjectName[13];
} McMDCCompDatObjType;

typedef struct McMDCCompDatFileType
{	plcstring FileDevice[251];
	plcstring CSVFileName[251];
} McMDCCompDatFileType;

typedef struct McMDCCompDatPVType
{	plcstring DataPoints[251];
	plcstring NumberOfDataPoints[251];
} McMDCCompDatPVType;

typedef struct McMDCCompDatType
{	enum McMDCCompDatEnum Type;
	struct McMDCCompDatObjType DataObject;
	struct McMDCCompDatFileType FileOnFileDevice;
	struct McMDCCompDatPVType ProcessVariables;
} McMDCCompDatType;

typedef struct McMDCDirDepSetPosType
{	struct McMDCCompDatType CompensationDataPositive;
	struct McMDCCompDatType CompensationDataNegative;
	enum McMDCPosSrcEnum PositionSource;
	enum McMDCDatIntEnum DataInterpretation;
	enum McMDCStEdgEnum StartEdge;
	float Velocity;
	float TimeConstant;
	float NoiseLimit;
} McMDCDirDepSetPosType;

typedef struct McMDCDirIndType
{	struct McMDCCompDatType CompensationData;
	enum McMDCPosSrcEnum PositionSource;
	enum McMDCDatIntEnum DataInterpretation;
} McMDCDirIndType;

typedef struct McMDCDirIndSpdType
{	struct McMDCCompDatType CompensationData;
	enum McMDCPosSrcEnum PositionSource;
	enum McMDCDatIntEnum DataInterpretation;
	float FilterTime;
} McMDCDirIndSpdType;

typedef struct McMDCDirIndBcklType
{	struct McMDCCompDatType CompensationDataPositive;
	double Backlash;
	enum McMDCPosSrcEnum PositionSource;
	enum McMDCDatIntEnum DataInterpretation;
	enum McMDCStEdgEnum StartEdge;
	float Velocity;
	float TimeConstant;
	float NoiseLimit;
} McMDCDirIndBcklType;

typedef struct McMDCModeType
{	enum McMDCModeEnum Type;
	struct McMDCDirDepConstBcklType DirDepConstBckl;
	struct McMDCDirDepSetPosType DirDepSetPos;
	struct McMDCDirIndType DirInd;
	struct McMDCDirIndSpdType DirIndSpd;
	struct McMDCDirIndBcklType DirIndWBckl;
} McMDCModeType;

typedef struct McMDCTypeAcpType
{	enum McMDCACalcEnum AutomaticCalculation;
	enum McMDCAActiEnum AutomaticActivation;
	struct McMDCModeType MechDevnCompMode;
} McMDCTypeAcpType;

typedef struct McMDCTypeType
{	enum McMDCTypeEnum Type;
	struct McMDCTypeAcpType ACOPOS;
} McMDCTypeType;

typedef struct McCfgAxFeatMechDevCompType
{	struct McMDCTypeType MechDevnCompType;
} McCfgAxFeatMechDevCompType;

typedef struct MC_BR_GetAxisLibraryInfo
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McLibraryInfoType Info;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit Error;
} MC_BR_GetAxisLibraryInfo_typ;

typedef struct MC_Power
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Status;
	plcbit Busy;
	plcbit Error;
} MC_Power_typ;

typedef struct MC_Home
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
	enum McHomingModeEnum HomingMode;
	enum McBufferModeEnum BufferMode;
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
	plcbit CommandAborted;
	plcbit Error;
} MC_Home_typ;

typedef struct MC_BR_BrakeOperation
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McBrakeCmdEnum Command;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	enum McBrakeStatusEnum BrakeStatus;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_BrakeOperation_typ;

typedef struct MC_Stop
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_Stop_typ;

typedef struct MC_Halt
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
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
	plcbit CommandAborted;
	plcbit Error;
} MC_Halt_typ;

typedef struct MC_BR_CamAutomatCommand
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Deceleration;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned char ActualStateIndex;
	unsigned short ActualStateCamIndex;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Start;
	plcbit Stop;
	plcbit Restart;
	plcbit EndAutomat;
	plcbit SetSignal1;
	plcbit SetSignal2;
	plcbit SetSignal3;
	plcbit SetSignal4;
	plcbit ResetSignal1;
	plcbit ResetSignal2;
	plcbit ResetSignal3;
	plcbit ResetSignal4;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit Running;
	plcbit StandBy;
	plcbit InCam;
	plcbit InCompensation;
	plcbit Ready;
} MC_BR_CamAutomatCommand_typ;

typedef struct MC_BR_CamAutomatReset
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutResetCmdEnum Command;
	unsigned char StateIndex;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamAutomatReset_typ;

typedef struct MC_BR_CamAutomatParLock
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutParLockCmdEnum Command;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamAutomatParLock_typ;

typedef struct MC_MoveAbsolute
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McDirectionEnum Direction;
	enum McBufferModeEnum BufferMode;
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
	plcbit CommandAborted;
	plcbit Error;
} MC_MoveAbsolute_typ;

typedef struct MC_MoveAdditive
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Distance;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
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
	plcbit CommandAborted;
	plcbit Error;
} MC_MoveAdditive_typ;

typedef struct MC_MoveVelocity
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McDirectionEnum Direction;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InVelocity;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_MoveVelocity_typ;

typedef struct MC_BR_MoveCyclicPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McIplModeEnum InterpolationMode;
	struct McAdvMoveCycParType AdvancedParameters;
	double CyclicPosition;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_MoveCyclicPosition_typ;

typedef struct MC_BR_MoveCyclicVelocity
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McIplModeEnum InterpolationMode;
	struct McAdvMoveCycParType AdvancedParameters;
	float CyclicVelocity;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_MoveCyclicVelocity_typ;

typedef struct MC_SetOverride
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float VelFactor;
	float AccFactor;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Enabled;
	plcbit Busy;
	plcbit Error;
} MC_SetOverride_typ;

typedef struct MC_ReadStatus
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit ErrorStop;
	plcbit Disabled;
	plcbit Stopping;
	plcbit Homing;
	plcbit StandStill;
	plcbit DiscreteMotion;
	plcbit ContinuousMotion;
	plcbit SynchronizedMotion;
} MC_ReadStatus_typ;

typedef struct MC_ReadAxisInfo
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAddInfoType AdditionalInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit Simulation;
	plcbit CommunicationReady;
	plcbit ReadyForPowerOn;
	plcbit PowerOn;
	plcbit IsHomed;
	plcbit AxisWarning;
} MC_ReadAxisInfo_typ;

typedef struct MC_ReadActualPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double Position;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_ReadActualPosition_typ;

typedef struct MC_ReadActualVelocity
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	float Velocity;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_ReadActualVelocity_typ;

typedef struct MC_ReadActualTorque
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	float Torque;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_ReadActualTorque_typ;

typedef struct MC_ReadAxisError
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	signed long AxisErrorID;
	signed long RecordID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ReadNext;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_ReadAxisError_typ;

typedef struct MC_Reset
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_Reset_typ;

typedef struct MC_BR_VelocityControl
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAdvVelCtrlParType AdvancedParameters;
	float CyclicVelocity;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_VelocityControl_typ;

typedef struct MC_BR_ReadCyclicPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McValueSrcEnum ValueSource;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double CyclicPosition;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_ReadCyclicPosition_typ;

typedef struct MC_ReadParameter
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McPlcopenParEnum ParameterNumber;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double Value;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_ReadParameter_typ;

typedef struct MC_BR_JogVelocity
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit JogPositive;
	plcbit JogNegative;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit Jogging;
} MC_BR_JogVelocity_typ;

typedef struct MC_BR_JogLimitPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double FirstPosition;
	double LastPosition;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit JogPositive;
	plcbit JogNegative;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit Jogging;
	plcbit LimitReached;
} MC_BR_JogLimitPosition_typ;

typedef struct MC_BR_JogTargetPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	double TargetPosition;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit JogToTarget;
	plcbit JogPositive;
	plcbit JogNegative;
	/* VAR_OUTPUT (digital) */
	plcbit Ready;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit Jogging;
	plcbit MovingToTarget;
	plcbit TargetReached;
} MC_BR_JogTargetPosition_typ;

typedef struct MC_TorqueControl
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Torque;
	float TorqueRamp;
	float Velocity;
	float Acceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InTorque;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit AxisLimitActive;
} MC_TorqueControl_typ;

typedef struct MC_LimitLoad
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Load;
	enum McDirectionEnum Direction;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Ready;
	plcbit Active;
	plcbit Error;
} MC_LimitLoad_typ;

typedef struct MC_BR_LoadSimulationCommand
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McSwitchEnum Command;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_LoadSimulationCommand_typ;

typedef struct MC_GearIn
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	signed long RatioNumerator;
	signed long RatioDenominator;
	enum McValueSrcEnum MasterValueSource;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	struct McAdvGearInParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InGear;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_GearIn_typ;

typedef struct MC_GearInPos
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	signed long RatioNumerator;
	signed long RatioDenominator;
	enum McValueSrcEnum MasterValueSource;
	double MasterSyncPosition;
	double SlaveSyncPosition;
	enum McSyncModeEnum SyncMode;
	double MasterStartDistance;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	struct McAdvGearInPosParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit StartSync;
	plcbit InSync;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_GearInPos_typ;

typedef struct MC_GearOut
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_GearOut_typ;

typedef struct MC_CamIn
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	double MasterOffset;
	double SlaveOffset;
	signed long MasterScaling;
	signed long SlaveScaling;
	enum McCamStartModeEnum StartMode;
	enum McValueSrcEnum MasterValueSource;
	unsigned short CamID;
	enum McBufferModeEnum BufferMode;
	struct McAdvCamInParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	enum McCamInStatusEnum Status;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InSync;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit EndOfProfile;
} MC_CamIn_typ;

typedef struct MC_BR_CamIn
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	unsigned short CamID;
	double MasterStartPosition;
	signed long MasterScaling;
	signed long SlaveScaling;
	struct McAdvBrCamInParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	plcbit EnterCam;
	plcbit ExitCam;
	plcbit Restart;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit DataInitialized;
	plcbit Running;
	plcbit StandBy;
	plcbit InLeadIn;
	plcbit InCam;
	plcbit InLeadOut;
	plcbit EndOfProfile;
	plcbit Ready;
} MC_BR_CamIn_typ;

typedef struct MC_CamOut
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Jerk;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_CamOut_typ;

typedef struct MC_BR_CamPrepare
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McCamDefineType Cam;
	unsigned short CamID;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamPrepare_typ;

typedef struct MC_BR_CamSaveDataObject
{
	/* VAR_INPUT (analog) */
	struct McCamDefineType Data;
	struct McBrAdvCamSaveDatObjType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned long DataObjectIdent;
	/* VAR (analog) */
	struct McExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamSaveDataObject_typ;

typedef struct MC_BR_CommandError
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McErrorCmdEnum Command;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CommandError_typ;

typedef struct MC_PhasingAbsolute
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	double PhaseShift;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double AbsolutePhaseShift;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_PhasingAbsolute_typ;

typedef struct MC_PhasingRelative
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	double PhaseShift;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double CoveredPhaseShift;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_PhasingRelative_typ;

typedef struct MC_BR_Phasing
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	double PhaseShift;
	float Velocity;
	float Acceleration;
	struct McAdvPhasingParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double ActualPhaseShift;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit StartShift;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit ShiftAttained;
	plcbit ShiftStarted;
} MC_BR_Phasing_typ;

typedef struct MC_BR_Offset
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	double OffsetShift;
	float Velocity;
	float Acceleration;
	struct McAdvOffsetParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double ActualOffsetShift;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit StartShift;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit ShiftAttained;
	plcbit ShiftStarted;
} MC_BR_Offset_typ;

typedef struct MC_BR_CamAutomatSetPar
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutSetParCmdEnum Command;
	struct McCamAutDefineType CamAutomat;
	struct McAdvCamAutSetParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamAutomatSetPar_typ;

typedef struct MC_BR_CamAutomatGetPar
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutGetParCmdEnum Command;
	struct McCamAutDefineType CamAutomat;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CamAutomatGetPar_typ;

typedef struct MC_BR_CalcCamFromPoints
{
	/* VAR_INPUT (analog) */
	double* MasterPointsAddress;
	double* SlavePointsAddress;
	unsigned short NumberOfPoints;
	struct McCamDataType* CamDataAddress;
	struct McAdvCalcCamFromPointsParType AdvancedParameters;
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
} MC_BR_CalcCamFromPoints_typ;

typedef struct MC_BR_CalcPointsFromCam
{
	/* VAR_INPUT (analog) */
	struct McCamDefineType Cam;
	double* MasterPointsAddress;
	double* SlavePointsAddress;
	unsigned short NumberOfPoints;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAdvCalcCamFromPointsParType AdditionalInfo;
	/* VAR (analog) */
	struct McExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CalcPointsFromCam_typ;

typedef struct MC_BR_CalcCamFromSections
{
	/* VAR_INPUT (analog) */
	struct McCamSectionsType* CamSectionsAddress;
	struct McCamDataType* CamDataAddress;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned short ErrorInSection;
	/* VAR (analog) */
	struct McExec1InternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_CalcCamFromSections_typ;

typedef struct MC_BR_CalcSectionsFromCam
{
	/* VAR_INPUT (analog) */
	struct McCamDefineType Cam;
	struct McCamSectionsType* CamSectionsAddress;
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
} MC_BR_CalcSectionsFromCam_typ;

typedef struct MC_BR_GetCamMasterPosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	struct McCamDefineType Cam;
	double MasterStartPosition;
	double SlavePosition;
	signed long MasterFactor;
	signed long SlaveFactor;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double MasterPosition;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_GetCamMasterPosition_typ;

typedef struct MC_BR_GetCamSlavePosition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	struct McCamDefineType Cam;
	double MasterPosition;
	signed long MasterFactor;
	signed long SlaveFactor;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double SlavePosition;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_GetCamSlavePosition_typ;

typedef struct MC_DigitalCamSwitch
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McDigCamSwitchOptionsParType Switches;
	struct McDigCamSwTrackOptionsParType TrackOptions;
	struct McDigCamSwOptionsParType GeneralOptions;
	enum McValueSrcEnum ValueSource;
	unsigned char DataSetSelector;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned char ActualDataSet;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitDataSet;
	plcbit ChangeDataSet;
	plcbit InitTrackOptions;
	plcbit EnableDigOut;
	plcbit ForceOutput;
	/* VAR_OUTPUT (digital) */
	plcbit InOperation;
	plcbit Busy;
	plcbit Error;
	plcbit DataSetInitialized;
	plcbit TrackOptionsInitialized;
	plcbit Value;
} MC_DigitalCamSwitch_typ;

typedef struct MC_AbortTrigger
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McTriggerType TriggerInput;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_AbortTrigger_typ;

typedef struct MC_TouchProbe
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McTriggerType TriggerInput;
	double FirstPosition;
	double LastPosition;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double RecordedPosition;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	plcbit WindowOnly;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_TouchProbe_typ;

typedef struct MC_BR_TouchProbe
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McBrTriggerType TriggerInput;
	double Period;
	double PeriodChange;
	double ExpectedValue;
	double WindowNegative;
	double WindowPositive;
	enum McBrTouchProbeModeEnum Mode;
	struct McAdvBrTouchProbeParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double RecordedPeriodicValue;
	double RecordedValue;
	double DeltaExpectedValue;
	unsigned long ValidTriggerCount;
	unsigned long MissedTriggerCount;
	struct McBrTriggerInfoType TriggerInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit InOperation;
	plcbit Busy;
	plcbit Error;
} MC_BR_TouchProbe_typ;

typedef struct MC_BR_CyclicTorqueFeedForward
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McIplModeEnum InterpolationMode;
	struct McAdvCyclicTorqueFFParType AdvancedParameters;
	float CyclicTorque;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_CyclicTorqueFeedForward_typ;

typedef struct MC_BR_CamAutomatPrepareRestart
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McCamAutPrepRestartModeEnum Mode;
	struct McAdvCamAutPrepRestartParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double RestartPosition;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_CamAutomatPrepareRestart_typ;

typedef struct MC_BR_CheckRestorePositionData
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned long DataAddress;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit DataInUse;
	plcbit DataValid;
} MC_BR_CheckRestorePositionData_typ;

typedef struct MC_BR_CamDwell
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	unsigned short CamID;
	signed long MasterScaling;
	signed long SlaveScaling;
	double MasterStartPosition;
	double MasterDwellDistance;
	struct McAdvBrCamDwellParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	plcbit LeadIn;
	plcbit LeadOut;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit DataInitialized;
	plcbit Running;
	plcbit InLeadIn;
	plcbit InCam;
	plcbit InDwell;
	plcbit InLeadOut;
} MC_BR_CamDwell_typ;

typedef struct MC_BR_AutoCamDwell
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	double MasterLength;
	double SlaveLength;
	double MasterStartPosition;
	double MasterDwellDistance;
	struct McAdvBrAutoCamDwellParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	plcbit LeadIn;
	plcbit LeadOut;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit DataInitialized;
	plcbit Running;
	plcbit InLeadIn;
	plcbit InCam;
	plcbit InDwell;
	plcbit InLeadOut;
} MC_BR_AutoCamDwell_typ;

typedef struct MC_BR_CamTransition
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Master;
	struct McAxisType* Slave;
	unsigned short CamID;
	signed long MasterScaling;
	signed long SlaveScaling;
	double MasterInterval;
	double SlaveInterval;
	double MasterStartPosition;
	struct McAdvBrCamTransitionParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	plcbit LeadIn;
	plcbit LeadOut;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit DataInitialized;
	plcbit Running;
	plcbit InLeadIn;
	plcbit InCam;
	plcbit InTransition;
	plcbit InLeadOut;
} MC_BR_CamTransition_typ;

typedef struct MC_BR_EventMoveAbsolute
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McDirectionEnum Direction;
	struct McEventType Event;
	struct McAdvEventMoveParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InPosition;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit WaitingForEvent;
} MC_BR_EventMoveAbsolute_typ;

typedef struct MC_BR_EventMoveAdditive
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Distance;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	struct McEventType Event;
	struct McAdvEventMoveParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InPosition;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit WaitingForEvent;
} MC_BR_EventMoveAdditive_typ;

typedef struct MC_BR_EventMoveVelocity
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McDirectionEnum Direction;
	struct McEventType Event;
	struct McAdvEventMoveParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InVelocity;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit WaitingForEvent;
} MC_BR_EventMoveVelocity_typ;

typedef struct MC_BR_ForceHardwareInputs
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit HomingSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit Ready;
} MC_BR_ForceHardwareInputs_typ;

typedef struct MC_BR_TorqueControl
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Torque;
	float TorqueRamp;
	float MaximumVelocity;
	float MinimumVelocity;
	float Acceleration;
	float Jerk;
	struct McAdvBrTorqueControlParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	plcbit Start;
	plcbit Stop;
	/* VAR_OUTPUT (digital) */
	plcbit InTorque;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit DataInitialized;
	plcbit Ready;
	plcbit AxisLimitActive;
} MC_BR_TorqueControl_typ;

typedef struct MC_WriteParameter
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McPlcopenParEnum ParameterNumber;
	double Value;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_WriteParameter_typ;

typedef struct MC_BR_LimitLoadCam
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned short CamIDPos;
	unsigned short CamIDNeg;
	enum McLimitLoadModeEnum Mode;
	struct McAdvBrLimitLoadCamParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit InitData;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Ready;
	plcbit Active;
	plcbit Error;
	plcbit DataInitialized;
} MC_BR_LimitLoadCam_typ;

typedef struct MC_BR_MechDeviationComp
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McMechDevCompCmdEnum Command;
	struct McMechDevCompAdvParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McMechDevCompAddInfoType AdditionalInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_MechDeviationComp_typ;

typedef struct MC_BR_GetHardwareInfo
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McHardwareInfoType HardwareInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_GetHardwareInfo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MC_BR_GetAxisLibraryInfo(struct MC_BR_GetAxisLibraryInfo* inst);
_BUR_PUBLIC void MC_Power(struct MC_Power* inst);
_BUR_PUBLIC void MC_Home(struct MC_Home* inst);
_BUR_PUBLIC void MC_BR_BrakeOperation(struct MC_BR_BrakeOperation* inst);
_BUR_PUBLIC void MC_Stop(struct MC_Stop* inst);
_BUR_PUBLIC void MC_Halt(struct MC_Halt* inst);
_BUR_PUBLIC void MC_BR_CamAutomatCommand(struct MC_BR_CamAutomatCommand* inst);
_BUR_PUBLIC void MC_BR_CamAutomatReset(struct MC_BR_CamAutomatReset* inst);
_BUR_PUBLIC void MC_BR_CamAutomatParLock(struct MC_BR_CamAutomatParLock* inst);
_BUR_PUBLIC void MC_MoveAbsolute(struct MC_MoveAbsolute* inst);
_BUR_PUBLIC void MC_MoveAdditive(struct MC_MoveAdditive* inst);
_BUR_PUBLIC void MC_MoveVelocity(struct MC_MoveVelocity* inst);
_BUR_PUBLIC void MC_BR_MoveCyclicPosition(struct MC_BR_MoveCyclicPosition* inst);
_BUR_PUBLIC void MC_BR_MoveCyclicVelocity(struct MC_BR_MoveCyclicVelocity* inst);
_BUR_PUBLIC void MC_SetOverride(struct MC_SetOverride* inst);
_BUR_PUBLIC void MC_ReadStatus(struct MC_ReadStatus* inst);
_BUR_PUBLIC void MC_ReadAxisInfo(struct MC_ReadAxisInfo* inst);
_BUR_PUBLIC void MC_ReadActualPosition(struct MC_ReadActualPosition* inst);
_BUR_PUBLIC void MC_ReadActualVelocity(struct MC_ReadActualVelocity* inst);
_BUR_PUBLIC void MC_ReadActualTorque(struct MC_ReadActualTorque* inst);
_BUR_PUBLIC void MC_ReadAxisError(struct MC_ReadAxisError* inst);
_BUR_PUBLIC void MC_Reset(struct MC_Reset* inst);
_BUR_PUBLIC void MC_BR_VelocityControl(struct MC_BR_VelocityControl* inst);
_BUR_PUBLIC void MC_BR_ReadCyclicPosition(struct MC_BR_ReadCyclicPosition* inst);
_BUR_PUBLIC void MC_ReadParameter(struct MC_ReadParameter* inst);
_BUR_PUBLIC void MC_BR_JogVelocity(struct MC_BR_JogVelocity* inst);
_BUR_PUBLIC void MC_BR_JogLimitPosition(struct MC_BR_JogLimitPosition* inst);
_BUR_PUBLIC void MC_BR_JogTargetPosition(struct MC_BR_JogTargetPosition* inst);
_BUR_PUBLIC void MC_TorqueControl(struct MC_TorqueControl* inst);
_BUR_PUBLIC void MC_LimitLoad(struct MC_LimitLoad* inst);
_BUR_PUBLIC void MC_BR_LoadSimulationCommand(struct MC_BR_LoadSimulationCommand* inst);
_BUR_PUBLIC void MC_GearIn(struct MC_GearIn* inst);
_BUR_PUBLIC void MC_GearInPos(struct MC_GearInPos* inst);
_BUR_PUBLIC void MC_GearOut(struct MC_GearOut* inst);
_BUR_PUBLIC void MC_CamIn(struct MC_CamIn* inst);
_BUR_PUBLIC void MC_BR_CamIn(struct MC_BR_CamIn* inst);
_BUR_PUBLIC void MC_CamOut(struct MC_CamOut* inst);
_BUR_PUBLIC void MC_BR_CamPrepare(struct MC_BR_CamPrepare* inst);
_BUR_PUBLIC void MC_BR_CamSaveDataObject(struct MC_BR_CamSaveDataObject* inst);
_BUR_PUBLIC void MC_BR_CommandError(struct MC_BR_CommandError* inst);
_BUR_PUBLIC void MC_PhasingAbsolute(struct MC_PhasingAbsolute* inst);
_BUR_PUBLIC void MC_PhasingRelative(struct MC_PhasingRelative* inst);
_BUR_PUBLIC void MC_BR_Phasing(struct MC_BR_Phasing* inst);
_BUR_PUBLIC void MC_BR_Offset(struct MC_BR_Offset* inst);
_BUR_PUBLIC void MC_BR_CamAutomatSetPar(struct MC_BR_CamAutomatSetPar* inst);
_BUR_PUBLIC void MC_BR_CamAutomatGetPar(struct MC_BR_CamAutomatGetPar* inst);
_BUR_PUBLIC void MC_BR_CalcCamFromPoints(struct MC_BR_CalcCamFromPoints* inst);
_BUR_PUBLIC void MC_BR_CalcPointsFromCam(struct MC_BR_CalcPointsFromCam* inst);
_BUR_PUBLIC void MC_BR_CalcCamFromSections(struct MC_BR_CalcCamFromSections* inst);
_BUR_PUBLIC void MC_BR_CalcSectionsFromCam(struct MC_BR_CalcSectionsFromCam* inst);
_BUR_PUBLIC void MC_BR_GetCamMasterPosition(struct MC_BR_GetCamMasterPosition* inst);
_BUR_PUBLIC void MC_BR_GetCamSlavePosition(struct MC_BR_GetCamSlavePosition* inst);
_BUR_PUBLIC void MC_DigitalCamSwitch(struct MC_DigitalCamSwitch* inst);
_BUR_PUBLIC void MC_AbortTrigger(struct MC_AbortTrigger* inst);
_BUR_PUBLIC void MC_TouchProbe(struct MC_TouchProbe* inst);
_BUR_PUBLIC void MC_BR_TouchProbe(struct MC_BR_TouchProbe* inst);
_BUR_PUBLIC void MC_BR_CyclicTorqueFeedForward(struct MC_BR_CyclicTorqueFeedForward* inst);
_BUR_PUBLIC void MC_BR_CamAutomatPrepareRestart(struct MC_BR_CamAutomatPrepareRestart* inst);
_BUR_PUBLIC void MC_BR_CheckRestorePositionData(struct MC_BR_CheckRestorePositionData* inst);
_BUR_PUBLIC void MC_BR_CamDwell(struct MC_BR_CamDwell* inst);
_BUR_PUBLIC void MC_BR_AutoCamDwell(struct MC_BR_AutoCamDwell* inst);
_BUR_PUBLIC void MC_BR_CamTransition(struct MC_BR_CamTransition* inst);
_BUR_PUBLIC void MC_BR_EventMoveAbsolute(struct MC_BR_EventMoveAbsolute* inst);
_BUR_PUBLIC void MC_BR_EventMoveAdditive(struct MC_BR_EventMoveAdditive* inst);
_BUR_PUBLIC void MC_BR_EventMoveVelocity(struct MC_BR_EventMoveVelocity* inst);
_BUR_PUBLIC void MC_BR_ForceHardwareInputs(struct MC_BR_ForceHardwareInputs* inst);
_BUR_PUBLIC void MC_BR_TorqueControl(struct MC_BR_TorqueControl* inst);
_BUR_PUBLIC void MC_WriteParameter(struct MC_WriteParameter* inst);
_BUR_PUBLIC void MC_BR_LimitLoadCam(struct MC_BR_LimitLoadCam* inst);
_BUR_PUBLIC void MC_BR_MechDeviationComp(struct MC_BR_MechDeviationComp* inst);
_BUR_PUBLIC void MC_BR_GetHardwareInfo(struct MC_BR_GetHardwareInfo* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MCAXIS_ */

