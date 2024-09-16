/* Automation Studio generated header file */
/* Do not edit ! */
/* McAcpAx 5.16.2 */

#ifndef _MCACPAX_
#define _MCACPAX_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _McAcpAx_VERSION
#define _McAcpAx_VERSION 5.16.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif

#ifdef _SG4
#include <McBase.h> 
#include <McAxis.h>
#endif
 
#ifdef _SG3
#include <McBase.h> 
#include <McAxis.h>
#endif
 
#ifdef _SGC
#include <McBase.h> 
#include <McAxis.h>
#endif

/* Datatypes and datatypes of function blocks */
typedef enum McAcpAxDataTypeEnum
{	mcACPAX_PARTYPE_BOOL = 1,
	mcACPAX_PARTYPE_SINT,
	mcACPAX_PARTYPE_INT,
	mcACPAX_PARTYPE_DINT,
	mcACPAX_PARTYPE_USINT,
	mcACPAX_PARTYPE_UINT,
	mcACPAX_PARTYPE_UDINT,
	mcACPAX_PARTYPE_REAL,
	mcACPAX_PARTYPE_VOID = 65535
} McAcpAxDataTypeEnum;

typedef enum McAcpAxProcessParIDModeEnum
{	mcACPAX_PARID_GET = 0,
	mcACPAX_PARID_SET,
	mcACPAX_PARID_GET_NO_NCT
} McAcpAxProcessParIDModeEnum;

typedef enum McAcpAxProcessParTabModeEnum
{	mcACPAX_PARTAB_SET = 0
} McAcpAxProcessParTabModeEnum;

typedef enum McAcpAxCycParIDModeEnum
{	mcACPAX_CYCLIC_PARID_READ = 0,
	mcACPAX_CYCLIC_PARID_WRITE
} McAcpAxCycParIDModeEnum;

typedef enum McAcpAxCycParIDRefreshModeEnum
{	mcACPAX_CYCLIC_MULTIPLEXED = 0,
	mcACPAX_CYCLIC_EVERY_RECORD
} McAcpAxCycParIDRefreshModeEnum;

typedef enum McAcpAxTriggerEnum
{	mcACPAX_TRIGGER_1,
	mcACPAX_TRIGGER_2
} McAcpAxTriggerEnum;

typedef enum McAcpAxLimitLoadModeEnum
{	mcACPAX_LL_WITH_FEED_FORWARD = 0,
	mcACPAX_LL_WITHOUT_FEED_FORWARD
} McAcpAxLimitLoadModeEnum;

typedef enum McAcpAxBrakeTestCmdEnum
{	mcACPAX_BRAKE_TEST_INIT = 0,
	mcACPAX_BRAKE_TEST_START = 1,
	mcACPAX_BRAKE_TEST_INIT_START
} McAcpAxBrakeTestCmdEnum;

typedef enum McAcpAxBrakeTestModeEnum
{	mcACPAX_BRAKE_TEST_STANDARD = 0,
	mcACPAX_BRAKE_TEST_SAFETY
} McAcpAxBrakeTestModeEnum;

typedef enum McAcpAxAxisTypeEnum
{	mcACPAX_AXIS_REAL,
	mcACPAX_AXIS_VIRTUAL,
	mcACPAX_AXIS_EXT_ENC
} McAcpAxAxisTypeEnum;

typedef enum McAcpAxProductFamilyEnum
{	mcACPAX_ACOPOS,
	mcACPAX_ACOPOS_MULTI,
	mcACPAX_ACOPOS_MICRO,
	mcACPAX_ACOPOS_REMOTE,
	mcACPAX_ACOPOS_MOTOR,
	mcACPAX_ACOPOS_P3
} McAcpAxProductFamilyEnum;

typedef enum McAcpAxModuleTypeEnum
{	mcACPAX_MODULE_INVERTER,
	mcACPAX_MODULE_ACTIVE_SUPPLY,
	mcACPAX_MODULE_PASSIVE_SUPPLY
} McAcpAxModuleTypeEnum;

typedef enum McAcpAxSimulationOnPlcEnum
{	mcACPAX_SIM_STATE_OFF,
	mcACPAX_SIM_STATE_ON,
	mcACPAX_SIM_SET_VALUE_GENERATION,
	mcACPAX_SIM_COMPLETE_CTRL_SYSTEM
} McAcpAxSimulationOnPlcEnum;

typedef enum McAcpAxCtrlModeEnum
{	mcACPAX_CTRL_POSITION = 1,
	mcACPAX_CTRL_POSITION_WITH_FF = 33
} McAcpAxCtrlModeEnum;

typedef enum McAcpAxCtrlParSelectEnum
{	mcACPAX_CTRL_SELECT_ALL_PAR,
	mcACPAX_CTRL_SELECT_POSITION,
	mcACPAX_CTRL_SELECT_SPEED,
	mcACPAX_CTRL_SELECT_FEED_FORWARD,
	mcACPAX_CTRL_SELECT_ADV_PAR_ONLY
} McAcpAxCtrlParSelectEnum;

typedef enum McAcpAxLoopFilterTypeEnum
{	mcACPAX_LOOP_FILTER_NO_TRANSFER,
	mcACPAX_LOOP_FILTER_OFF,
	mcACPAX_LOOP_FILTER_LOWPASS,
	mcACPAX_LOOP_FILTER_NOTCH,
	mcACPAX_LOOP_FILTER_Z_TRANS_FUN,
	mcACPAX_LOOP_FILTER_COMPENSATION,
	mcACPAX_LOOP_FILTER_BIQUAD,
	mcACPAX_LOOP_FILTER_LIM,
	mcACPAX_LOOP_FILTER_LIM_LINEAR,
	mcACPAX_LOOP_FILTER_LIM_R_TIME
} McAcpAxLoopFilterTypeEnum;

typedef enum McAcpAxAutoTuneExSignalEnum
{	mcACPAX_EX_SIGNAL_PRBS = 0,
	mcACPAX_EX_SIGNAL_CHIRP = 1,
	mcACPAX_EX_SIGNAL_CHIRP_TRAPEZ = 2
} McAcpAxAutoTuneExSignalEnum;

typedef enum McAcpAxAutoTuneTestModeEnum
{	mcACPAX_TEST,
	mcACPAX_TEST_POSITION,
	mcACPAX_TEST_SPEED
} McAcpAxAutoTuneTestModeEnum;

typedef enum McAcpAxIntegrationTimeModeEnum
{	mcACPAX_INTEGRATION_TIME_IGNORE,
	mcACPAX_INTEGRATION_TIME_USE,
	mcACPAX_INTEGRATION_TIME_TUNE
} McAcpAxIntegrationTimeModeEnum;

typedef enum McAcpAxAutoTuneOperatPointEnum
{	mcACPAX_OP_TUNE_STANDSTILL,
	mcACPAX_OP_TUNE_V_CONSTANT
} McAcpAxAutoTuneOperatPointEnum;

typedef enum McAcpAxAutoTuneMotorModeEnum
{	mcACPAX_ATM_IDENTIFICATION = 10,
	mcACPAX_ATM_TEST = 12
} McAcpAxAutoTuneMotorModeEnum;

typedef enum McAcpAxLoadModelIdentModeEnum
{	mcACPAX_MODEL_IDENT_CLOSED_LOOP = 0,
	mcACPAX_MODEL_IDENT_OPEN_LOOP = 1
} McAcpAxLoadModelIdentModeEnum;

typedef enum McAcpAxAutoTuneMotPhasModeEnum
{	mcACPAX_ATMP_SATURATION = 30,
	mcACPAX_ATMP_STEPPER = 31,
	mcACPAX_ATMP_DITHER = 32,
	mcACPAX_ATMP_SET_OFFSET = 34
} McAcpAxAutoTuneMotPhasModeEnum;

typedef enum McAcpAxSimulationModeEnum
{	mcACPAX_SIMULATION_1MASS_AUTO,
	mcACPAX_SIMULATION_1MASS,
	mcACPAX_SIMULATION_2MASS,
	mcACPAX_SIMULATION_SET_GEN_ONLY
} McAcpAxSimulationModeEnum;

typedef enum McAcpAxFeedbackModeEnum
{	mcACPAX_FBCTRL_MODE_STANDARD = 0,
	mcACPAX_FBCTRL_MODE_1MASS_MODEL = 4,
	mcACPAX_FBCTRL_MODE_2MASS_MODEL = 3,
	mcACPAX_FBCTRL_MODE_2ENC_SPEED = 5
} McAcpAxFeedbackModeEnum;

typedef enum McMSMotEnum
{	mcMSM_DEF = 0
} McMSMotEnum;

typedef enum McMSMotDefVLimEnum
{	mcMSMDVL_NOT_USE = 0,
	mcMSMDVL_USE = 1
} McMSMotDefVLimEnum;

typedef enum McMMDEMAngEnum
{	mcMSMDEMA_USRDEF = 0,
	mcMSMDEMA_UDEF = 1,
	mcMSMDEMA_VAL_STO_ON_ENC = 2
} McMMDEMAngEnum;

typedef enum McMMDEMAngUdefAutIdentEnum
{	mcMSMDEMAUAI_NOT_USE = 0,
	mcMSMDEMAUAI_SAT = 1,
	mcMSMDEMAUAI_DIT = 2,
	mcMSMDEMAUAI_DIT2 = 5
} McMMDEMAngUdefAutIdentEnum;

typedef enum McMMTmpSensEnum
{	mcMMTS_THERM = 0,
	mcMMTS_SW_PTC_THERM = 1,
	mcMMTS_THRMSW = 2,
	mcMMTS_NOT_USE = 3
} McMMTmpSensEnum;

typedef enum McMMTSThermTmpSensIfEnum
{	mcMMTSTTSI_MOT_CON_WRD = 0,
	mcMMTSTTSI_ENC_CON_WRD = 1,
	mcMMTSTTSI_ENC_DAT_TRAN = 2
} McMMTSThermTmpSensIfEnum;

typedef enum McMMTSSwPTCThermTmpSensIfEnum
{	mcMMTSSPTTSI_MOT_CON_WRD = 0,
	mcMMTSSPTTSI_ENC_CON_WRD = 1,
	mcMMTSSPTTSI_ENC_DAT_TRAN = 2
} McMMTSSwPTCThermTmpSensIfEnum;

typedef enum McMMTSThrmSwTmpSensIfEnum
{	mcMMTSTSTSI_MOT_CON_WRD = 0,
	mcMMTSTSTSI_ENC_CON_WRD = 1,
	mcMMTSTSTSI_ENC_DAT_TRAN = 2
} McMMTSThrmSwTmpSensIfEnum;

typedef enum McMMTSThrmSwSwStatOnOvrTmpEnum
{	mcMMTSTSSSOO_NORM_CLSD = 0,
	mcMMTSTSSSOO_NORM_OP = 1
} McMMTSThrmSwSwStatOnOvrTmpEnum;

typedef enum McMMTmpMdlEnum
{	mcMMTM_CUR_AND_SPDBASED = 0,
	mcMMTM_CURBASED = 1,
	mcMMTM_NOT_USE = 2
} McMMTmpMdlEnum;

typedef enum McMMTMCSBCalcMethEnum
{	mcMMTMCSBCM_SECORD_THRM_NETW = 0,
	mcMMTMCSBCM_FTHORD_THRM_NETW = 1,
	mcMMTMCSBCM_FTH_ORD_W_CPLG = 2
} McMMTMCSBCalcMethEnum;

typedef enum McMMTMCSBCMRefTmpEnum
{	mcMMTMCSBCMRT_MOT_TMP_SENS = 0,
	mcMMTMCSBCMRT_NOM_AMB_TMP = 1,
	mcMMTMCSBCMRT_ENC_TMP_SENS = 2
} McMMTMCSBCMRefTmpEnum;

typedef enum McMSBrkEnum
{	mcMSB_NOT_USE = 0,
	mcMSB_USE = 1
} McMSBrkEnum;

typedef enum McMSBrkUseCtrlModEnum
{	mcMSBUCM_SW = 0,
	mcMSBUCM_V_CTRL = 1
} McMSBrkUseCtrlModEnum;

typedef enum McMSBrkUseLimEnum
{	mcMSBUL_NOT_USE = 0,
	mcMSBUL_USE = 1
} McMSBrkUseLimEnum;

typedef enum McMSEncEnum
{	mcMSE_NOT_USE = 0,
	mcMSE_USE = 1
} McMSEncEnum;

typedef enum McMSEncUseTmpSensEnum
{	mcMSEUTS_NOT_USE = 0,
	mcMSEUTS_USE = 1
} McMSEncUseTmpSensEnum;

typedef enum McMSGBEnum
{	mcMSG_NOT_USE = 0,
	mcMSG_USE = 1
} McMSGBEnum;

typedef enum McMIMotEnum
{	mcMIM_PWR_RTG_PLT = 0,
	mcMIM_STAR_EQ_CIR = 1
} McMIMotEnum;

typedef enum McMIMotStarEqCirVLimEnum
{	mcMIMSECVL_NOT_USE = 0,
	mcMIMSECVL_USE = 1
} McMIMotStarEqCirVLimEnum;

typedef enum McMIBrkEnum
{	mcMIB_NOT_USE = 0,
	mcMIB_USE = 1
} McMIBrkEnum;

typedef enum McMIBrkUseCtrlModEnum
{	mcMIBUCM_SW = 0,
	mcMIBUCM_V_CTRL = 1
} McMIBrkUseCtrlModEnum;

typedef enum McMIBrkUseLimEnum
{	mcMIBUL_NOT_USE = 0,
	mcMIBUL_USE = 1
} McMIBrkUseLimEnum;

typedef enum McMIEncEnum
{	mcMIE_NOT_USE = 0,
	mcMIE_USE = 1
} McMIEncEnum;

typedef enum McMIEncUseTmpSensEnum
{	mcMIEUTS_NOT_USE = 0,
	mcMIEUTS_USE = 1
} McMIEncUseTmpSensEnum;

typedef enum McMIGBEnum
{	mcMIG_NOT_USE = 0,
	mcMIG_USE = 1
} McMIGBEnum;

typedef enum McAELEnum
{	mcAEL_ONE_ENC = 0,
	mcAEL_TWO_ENC = 1,
	mcAEL_NO_ENC = 10
} McAELEnum;

typedef enum McAELAllEncEnum
{	mcAELAE_ENC_X6A = 0,
	mcAELAE_ENC_X6B = 1,
	mcAELAE_ENC = 2,
	mcAELAE_ENC_SS1X11 = 3,
	mcAELAE_ENC_SS2X11 = 4,
	mcAELAE_ENC_X11A = 5,
	mcAELAE_ENC_SS3X11 = 6,
	mcAELAE_ENC_SS4X11 = 7,
	mcAELAE_ENC_X41 = 8,
	mcAELAE_ENC_SS1X41X = 9,
	mcAELAE_ENC_X42 = 10,
	mcAELAE_ENC_SS1X42X = 11,
	mcAELAE_ENC_X43 = 12,
	mcAELAE_ENC_SS1X43X = 13
} McAELAllEncEnum;

typedef enum McAELTwoEncPosEncCmnScCntDirEnum
{	mcAELTEPECSCD_STD = 0,
	mcAELTEPECSCD_INV = 1
} McAELTwoEncPosEncCmnScCntDirEnum;

typedef enum McACModEnum
{	mcACM_POS_CTRL = 0,
	mcACM_POS_CTRL_TORQ_FF = 1,
	mcACM_POS_CTRL_MDL_BASED = 3,
	mcACM_V_FREQ_CTRL = 2
} McACModEnum;

typedef enum McACLFSEnum
{	mcACLFS_NOT_USE = 0,
	mcACLFS_LP_2ND_ORD = 1,
	mcACLFS_NOTCH = 2,
	mcACLFS_BIQUAD = 3,
	mcACLFS_DISC_TIME_TRAN_FUN = 4,
	mcACLFS_LIM = 5,
	mcACLFS_LIN_LIM = 6,
	mcACLFS_RISE_TIME_LIM = 7,
	mcACLFS_COMP = 8
} McACLFSEnum;

typedef enum McACLFSLLimEnum
{	mcACLFSLLim_ACP_PARID = 0,
	mcACLFSLLim_FIX_VAL = 1
} McACLFSLLimEnum;

typedef enum McACMPCFFFFwdEnum
{	mcACMPCFFFF_STD = 0,
	mcACMPCFFFF_CYC_VAL_FROM_AX_GRP = 1
} McACMPCFFFFwdEnum;

typedef enum McACMPCMBCFFEnum
{	mcACMPCMBCFF_STD = 0,
	mcACMPCMBCFF_PRED_SPD = 1,
	mcACMPCMBCFF_TWO_MASS_MDL_BASED = 2
} McACMPCMBCFFEnum;

typedef enum McACMPCMBCFdbkEnum
{	mcACMPCMBCF_STD = 0,
	mcACMPCMBCF_ONE_MASS_MDL_BASED = 1,
	mcACMPCMBCF_TWO_MASS_MDL_BASED = 2,
	mcACMPCMBCF_TWO_ENC_SPD_BASED = 3
} McACMPCMBCFdbkEnum;

typedef enum McACMVFCVFTypEnum
{	mcACMVFCVFT_LIN = 129,
	mcACMVFCVFT_CONST_LD_TORQ = 131,
	mcACMVFCVFT_QUAD = 130
} McACMVFCVFTypEnum;

typedef enum McACMVFCVFAutCfgEnum
{	mcACMVFCVFAC_MOT_PAR_BASED = 1,
	mcACMVFCVFAC_NOT_USE = 0
} McACMVFCVFAutCfgEnum;

typedef enum McAHModEnum
{	mcAHM_DIR = 0,
	mcAHM_ABS_SW = 1,
	mcAHM_SW_GATE = 2,
	mcAHM_LIM_SW = 3,
	mcAHM_ABS = 4,
	mcAHM_ABS_INT = 11,
	mcAHM_ABS_CORR = 5,
	mcAHM_DIST_C_MARKS = 6,
	mcAHM_DIST_C_MARKS_CORR = 7,
	mcAHM_BLK_TORQ = 8,
	mcAHM_BLK_LAG_ERR = 9,
	mcAHM_RES_POS = 10,
	mcAHM_NOT_USE = 100
} McAHModEnum;

typedef enum McAHModDirRefPEnum
{	mcAHMDRP_NOT_USE = 0,
	mcAHMDRP_USE = 1
} McAHModDirRefPEnum;

typedef enum McAHModHomeDirEnum
{	mcAHMHD_POS = 0,
	mcAHMHD_NEG = 1
} McAHModHomeDirEnum;

typedef enum McAHModKeepDirEnum
{	mcAHMKD_NO = 0,
	mcAHMKD_YES = 1
} McAHModKeepDirEnum;

typedef enum McAHModSwEdgEnum
{	mcAHMSE_POS = 0,
	mcAHMSE_NEG = 1
} McAHModSwEdgEnum;

typedef enum McAHModRefPEnum
{	mcAHMRP_NOT_USE = 0,
	mcAHMRP_USE = 1
} McAHModRefPEnum;

typedef enum McAHModStartDirEnum
{	mcAHMSD_POS = 0,
	mcAHMSD_NEG = 1
} McAHModStartDirEnum;

typedef enum McASRQstopEnum
{	mcASRQ_DEC_LIM = 0,
	mcASRQ_DEC_LIM_W_JERK_FLTR = 1,
	mcASRQ_TORQ_LIM = 2,
	mcASRQ_INDUCT_HALT = 3
} McASRQstopEnum;

typedef enum McASRDrvErrEnum
{	mcASRDE_DEC_LIM = 0,
	mcASRDE_INDUCT_HALT = 1,
	mcASRDE_COAST_TO_STANDSTILL = 2
} McASRDrvErrEnum;

typedef enum McAMELVelErrMonEnum
{	mcAMELVEM_AUT_1 = 0,
	mcAMELVEM_AUT_2 = 1,
	mcAMELVEM_USRDEF = 2,
	mcAMELVEM_NOT_USE = 3
} McAMELVelErrMonEnum;

typedef enum McAJFEnum
{	mcAJF_NOT_USE = 0,
	mcAJF_USE = 1
} McAJFEnum;

typedef enum McADIAllSrcEnum
{	mcADIAS_NOT_USE = 0,
	mcADIAS_DIG_IN_X8TRG_1 = 1,
	mcADIAS_DIG_IN_X8TRG_2 = 2,
	mcADIAS_DIG_IN_SS1X41X1 = 3,
	mcADIAS_DIG_IN_SS1X41X2 = 4,
	mcADIAS_DIG_IN_SS1X41X3 = 5,
	mcADIAS_DIG_IN_SS1X41X4 = 6,
	mcADIAS_DIG_IN_SS1X41X5 = 7,
	mcADIAS_DIG_IN_SS1X41X6 = 8,
	mcADIAS_DIG_IN_SS1X41X7 = 9,
	mcADIAS_DIG_IN_SS1X41X8 = 10,
	mcADIAS_DIG_IN_SS1X41X9 = 11,
	mcADIAS_DIG_IN_SS1X41X10 = 12,
	mcADIAS_DIG_IN_X23ATRG_1 = 13,
	mcADIAS_DIG_IN_X23ATRG_2 = 14,
	mcADIAS_DIG_IN_X24A_TRIGGER2 = 15,
	mcADIAS_DIG_IN_X2TRG_1 = 16,
	mcADIAS_DIG_IN_X2TRG_2 = 17,
	mcADIAS_DIG_IN_X1TRG_1 = 18,
	mcADIAS_DIG_IN_X1TRG_2 = 19,
	mcADIAS_DIG_IN_X1REF_SW = 20,
	mcADIAS_DIG_IN_X1POS_HW_LIM = 21,
	mcADIAS_DIG_IN_X1NEG_HW_LIM = 22,
	mcADIAS_FOR_BY_FUN_BLK = 23,
	mcADIAS_VAR = 24
} McADIAllSrcEnum;

typedef enum McADILvlEnum
{	mcADIL_HIGH = 0,
	mcADIL_LOW = 1
} McADILvlEnum;

typedef enum McADIQstopInEnum
{	mcADIQI_TRG_2 = 0,
	mcADIQI_TRG_1 = 1,
	mcADIQI_POS_LIM_SW = 2,
	mcADIQI_NEG_LIM_SW = 3,
	mcADIQI_HOME_SW = 4,
	mcADIQI_NOT_USE = 5
} McADIQstopInEnum;

typedef enum McASPMEnum
{	mcASPM_SET_VAL_GEN = 0,
	mcASPM_COMPL = 1
} McASPMEnum;

typedef enum McASLMEnum
{	mcASLM_ONE_MASS_MOT_BASED = 0,
	mcASLM_ONE_MASS = 1,
	mcASLM_TWO_MASS = 2
} McASLMEnum;

typedef enum McASAMEnum
{	mcASAM_NOT_USE = 0,
	mcASAM_SET_VAL_GEN = 1,
	mcASAM_COMPL = 2
} McASAMEnum;

typedef enum McAPSMOutParEnum
{	mcAPSMOP_ACOPOSTRAK = 1,
	mcAPSMOP_USR_DEF = 2
} McAPSMOutParEnum;

typedef enum McAPSMOutParUsrDefCurLimEnum
{	mcAPSMOPUDCL_NOT_USE = 0,
	mcAPSMOPUDCL_USE = 1
} McAPSMOutParUsrDefCurLimEnum;

typedef enum McAPSMOutVOnEnum
{	mcAPSMOVO_NO = 0,
	mcAPSMOVO_YES = 1
} McAPSMOutVOnEnum;

typedef enum McAPSPwrSupEnum
{	mcAPSPS_AC = 0,
	mcAPSPS_DC_PWR_SUP_MOD_REF = 1,
	mcAPSPS_DC_BUS_V = 2,
	mcAPSPS_ETA_SYS_FOR_TR_ONLY = 3
} McAPSPwrSupEnum;

typedef enum McAPSPwrSupACSngPhOpEnum
{	mcAPSPSASPO_NOT_USE = 0,
	mcAPSPSASPO_USE = 1
} McAPSPwrSupACSngPhOpEnum;

typedef enum McAEEncX6AIfTypEnum
{	mcAEX6AIT_ENDAT = 0,
	mcAEX6AIT_SSI = 1,
	mcAEX6AIT_SIN = 2,
	mcAEX6AIT_INCR = 3,
	mcAEX6AIT_LINMOT = 4,
	mcAEX6AIT_RES = 5
} McAEEncX6AIfTypEnum;

typedef enum McAEX6ASSSIFrmCfgStatBit1Enum
{	mcAEX6ASSFCSB1_NOT_AVL = 0,
	mcAEX6ASSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX6ASSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX6ASSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX6ASSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX6ASSSIFrmCfgStatBit1Enum;

typedef enum McAEX6ASSSIFrmCfgStatBit2Enum
{	mcAEX6ASSFCSB2_NOT_AVL = 0,
	mcAEX6ASSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX6ASSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX6ASSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX6ASSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX6ASSSIFrmCfgStatBit2Enum;

typedef enum McAEX6ASSSIFrmCfgSSIDatCEnum
{	mcAEX6ASSFCSDC_GRAY = 0,
	mcAEX6ASSFCSDC_BIN = 1
} McAEX6ASSSIFrmCfgSSIDatCEnum;

typedef enum McAEX6ASSSIFrmCfgSSIParCkEnum
{	mcAEX6ASSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX6ASSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX6ASSFCSPC_OFF = 2
} McAEX6ASSSIFrmCfgSSIParCkEnum;

typedef enum McAEX6AIMaxExpectedOutFreqEnum
{	mcAEX6AIMEOF_MEOF_25000 = 0,
	mcAEX6AIMEOF_MEOF_50000 = 1,
	mcAEX6AIMEOF_MEOF_100000 = 2,
	mcAEX6AIMEOF_MEOF_200000 = 3
} McAEX6AIMaxExpectedOutFreqEnum;

typedef enum McAEEncX6BIfTypEnum
{	mcAEX6BIT_ENDAT = 0,
	mcAEX6BIT_SSI = 1,
	mcAEX6BIT_SIN = 2,
	mcAEX6BIT_INCR = 3,
	mcAEX6BIT_LINMOT = 4,
	mcAEX6BIT_RES = 5
} McAEEncX6BIfTypEnum;

typedef enum McAEX6BSSSIFrmCfgStatBit1Enum
{	mcAEX6BSSFCSB1_NOT_AVL = 0,
	mcAEX6BSSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX6BSSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX6BSSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX6BSSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX6BSSSIFrmCfgStatBit1Enum;

typedef enum McAEX6BSSSIFrmCfgStatBit2Enum
{	mcAEX6BSSFCSB2_NOT_AVL = 0,
	mcAEX6BSSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX6BSSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX6BSSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX6BSSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX6BSSSIFrmCfgStatBit2Enum;

typedef enum McAEX6BSSSIFrmCfgSSIDatCEnum
{	mcAEX6BSSFCSDC_GRAY = 0,
	mcAEX6BSSFCSDC_BIN = 1
} McAEX6BSSSIFrmCfgSSIDatCEnum;

typedef enum McAEX6BSSSIFrmCfgSSIParCkEnum
{	mcAEX6BSSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX6BSSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX6BSSFCSPC_OFF = 2
} McAEX6BSSSIFrmCfgSSIParCkEnum;

typedef enum McAEX6BIMaxExpectedOutFreqEnum
{	mcAEX6BIMEOF_MEOF_25000 = 0,
	mcAEX6BIMEOF_MEOF_50000 = 1,
	mcAEX6BIMEOF_MEOF_100000 = 2,
	mcAEX6BIMEOF_MEOF_200000 = 3
} McAEX6BIMaxExpectedOutFreqEnum;

typedef enum McAEEncX41IfTypEnum
{	mcAEX41IT_NOT_USE = 0,
	mcAEX41IT_BISS = 1,
	mcAEX41IT_SSI = 2,
	mcAEX41IT_ENDAT = 3,
	mcAEX41IT_HIPERFACE_DSL = 4,
	mcAEX41IT_TFMT = 5,
	mcAEX41IT_MOT_DAT_IF = 6
} McAEEncX41IfTypEnum;

typedef enum McAEX41BPwrSupEnum
{	mcAEX41BPS_EXT = 0,
	mcAEX41BPS_PS_5_V = 1,
	mcAEX41BPS_PS_12_V = 2
} McAEX41BPwrSupEnum;

typedef enum McAEX41BBiSSFrmCfgStatBit1Enum
{	mcAEX41BBFCSB1_NOT_AVL = 0,
	mcAEX41BBFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX41BBFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX41BBFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX41BBFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX41BBiSSFrmCfgStatBit1Enum;

typedef enum McAEX41BBiSSFrmCfgStatBit2Enum
{	mcAEX41BBFCSB2_NOT_AVL = 0,
	mcAEX41BBFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX41BBFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX41BBFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX41BBFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX41BBiSSFrmCfgStatBit2Enum;

typedef enum McAEX41SPwrSupEnum
{	mcAEX41SPS_EXT = 0,
	mcAEX41SPS_PS_5_V = 1,
	mcAEX41SPS_PS_12_V = 2
} McAEX41SPwrSupEnum;

typedef enum McAEX41SSSIFrmCfgStatBit1Enum
{	mcAEX41SSFCSB1_NOT_AVL = 0,
	mcAEX41SSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX41SSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX41SSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX41SSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX41SSSIFrmCfgStatBit1Enum;

typedef enum McAEX41SSSIFrmCfgStatBit2Enum
{	mcAEX41SSFCSB2_NOT_AVL = 0,
	mcAEX41SSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX41SSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX41SSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX41SSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX41SSSIFrmCfgStatBit2Enum;

typedef enum McAEX41SSSIFrmCfgSSIDatCEnum
{	mcAEX41SSFCSDC_GRAY = 0,
	mcAEX41SSFCSDC_BIN = 1
} McAEX41SSSIFrmCfgSSIDatCEnum;

typedef enum McAEX41SSSIFrmCfgSSIParCkEnum
{	mcAEX41SSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX41SSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX41SSFCSPC_OFF = 2
} McAEX41SSSIFrmCfgSSIParCkEnum;

typedef enum McAEEncX42IfTypEnum
{	mcAEX42IT_NOT_USE = 0,
	mcAEX42IT_BISS = 1,
	mcAEX42IT_SSI = 2,
	mcAEX42IT_ENDAT = 3,
	mcAEX42IT_HIPERFACE_DSL = 4,
	mcAEX42IT_TFMT = 5,
	mcAEX42IT_MOT_DAT_IF = 6
} McAEEncX42IfTypEnum;

typedef enum McAEX42BPwrSupEnum
{	mcAEX42BPS_EXT = 0,
	mcAEX42BPS_PS_5_V = 1,
	mcAEX42BPS_PS_12_V = 2
} McAEX42BPwrSupEnum;

typedef enum McAEX42BBiSSFrmCfgStatBit1Enum
{	mcAEX42BBFCSB1_NOT_AVL = 0,
	mcAEX42BBFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX42BBFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX42BBFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX42BBFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX42BBiSSFrmCfgStatBit1Enum;

typedef enum McAEX42BBiSSFrmCfgStatBit2Enum
{	mcAEX42BBFCSB2_NOT_AVL = 0,
	mcAEX42BBFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX42BBFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX42BBFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX42BBFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX42BBiSSFrmCfgStatBit2Enum;

typedef enum McAEX42SPwrSupEnum
{	mcAEX42SPS_EXT = 0,
	mcAEX42SPS_PS_5_V = 1,
	mcAEX42SPS_PS_12_V = 2
} McAEX42SPwrSupEnum;

typedef enum McAEX42SSSIFrmCfgStatBit1Enum
{	mcAEX42SSFCSB1_NOT_AVL = 0,
	mcAEX42SSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX42SSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX42SSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX42SSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX42SSSIFrmCfgStatBit1Enum;

typedef enum McAEX42SSSIFrmCfgStatBit2Enum
{	mcAEX42SSFCSB2_NOT_AVL = 0,
	mcAEX42SSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX42SSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX42SSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX42SSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX42SSSIFrmCfgStatBit2Enum;

typedef enum McAEX42SSSIFrmCfgSSIDatCEnum
{	mcAEX42SSFCSDC_GRAY = 0,
	mcAEX42SSFCSDC_BIN = 1
} McAEX42SSSIFrmCfgSSIDatCEnum;

typedef enum McAEX42SSSIFrmCfgSSIParCkEnum
{	mcAEX42SSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX42SSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX42SSFCSPC_OFF = 2
} McAEX42SSSIFrmCfgSSIParCkEnum;

typedef enum McAEEncX43IfTypEnum
{	mcAEX43IT_NOT_USE = 0,
	mcAEX43IT_BISS = 1,
	mcAEX43IT_SSI = 2,
	mcAEX43IT_ENDAT = 3,
	mcAEX43IT_HIPERFACE_DSL = 4,
	mcAEX43IT_TFMT = 5,
	mcAEX43IT_MOT_DAT_IF = 6
} McAEEncX43IfTypEnum;

typedef enum McAEX43BPwrSupEnum
{	mcAEX43BPS_EXT = 0,
	mcAEX43BPS_PS_5_V = 1,
	mcAEX43BPS_PS_12_V = 2
} McAEX43BPwrSupEnum;

typedef enum McAEX43BBiSSFrmCfgStatBit1Enum
{	mcAEX43BBFCSB1_NOT_AVL = 0,
	mcAEX43BBFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX43BBFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX43BBFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX43BBFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX43BBiSSFrmCfgStatBit1Enum;

typedef enum McAEX43BBiSSFrmCfgStatBit2Enum
{	mcAEX43BBFCSB2_NOT_AVL = 0,
	mcAEX43BBFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX43BBFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX43BBFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX43BBFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX43BBiSSFrmCfgStatBit2Enum;

typedef enum McAEX43SPwrSupEnum
{	mcAEX43SPS_EXT = 0,
	mcAEX43SPS_PS_5_V = 1,
	mcAEX43SPS_PS_12_V = 2
} McAEX43SPwrSupEnum;

typedef enum McAEX43SSSIFrmCfgStatBit1Enum
{	mcAEX43SSFCSB1_NOT_AVL = 0,
	mcAEX43SSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX43SSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX43SSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX43SSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX43SSSIFrmCfgStatBit1Enum;

typedef enum McAEX43SSSIFrmCfgStatBit2Enum
{	mcAEX43SSFCSB2_NOT_AVL = 0,
	mcAEX43SSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX43SSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX43SSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX43SSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX43SSSIFrmCfgStatBit2Enum;

typedef enum McAEX43SSSIFrmCfgSSIDatCEnum
{	mcAEX43SSFCSDC_GRAY = 0,
	mcAEX43SSFCSDC_BIN = 1
} McAEX43SSSIFrmCfgSSIDatCEnum;

typedef enum McAEX43SSSIFrmCfgSSIParCkEnum
{	mcAEX43SSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX43SSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX43SSFCSPC_OFF = 2
} McAEX43SSSIFrmCfgSSIParCkEnum;

typedef enum McAEEncX11AIfTypEnum
{	mcAEX11AIT_ENDAT = 0,
	mcAEX11AIT_SSI_SIN = 1,
	mcAEX11AIT_SSI = 2,
	mcAEX11AIT_BISS = 3,
	mcAEX11AIT_SIN = 4,
	mcAEX11AIT_SIN_W_DCM = 5,
	mcAEX11AIT_HIPERFACE = 6
} McAEEncX11AIfTypEnum;

typedef enum McAEX11ASSSSIFrmCfgStatBit1Enum
{	mcAEX11ASSFCSB1_NOT_AVL = 0,
	mcAEX11ASSFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ASSFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX11ASSFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ASSFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX11ASSSSIFrmCfgStatBit1Enum;

typedef enum McAEX11ASSSSIFrmCfgStatBit2Enum
{	mcAEX11ASSFCSB2_NOT_AVL = 0,
	mcAEX11ASSFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ASSFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX11ASSFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ASSFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX11ASSSSIFrmCfgStatBit2Enum;

typedef enum McAEX11ASSSSIFrmCfgSSIDatCEnum
{	mcAEX11ASSFCSDC_GRAY = 0,
	mcAEX11ASSFCSDC_BIN = 1
} McAEX11ASSSSIFrmCfgSSIDatCEnum;

typedef enum McAEX11ASSSSIFrmCfgSSIParCkEnum
{	mcAEX11ASSFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX11ASSFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX11ASSFCSPC_OFF = 2
} McAEX11ASSSSIFrmCfgSSIParCkEnum;

typedef enum McAEX11ASSSIFrmCfgStatBit1Enum
{	mcAEX11ASFCSB1_NOT_AVL = 0,
	mcAEX11ASFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ASFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX11ASFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ASFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX11ASSSIFrmCfgStatBit1Enum;

typedef enum McAEX11ASSSIFrmCfgStatBit2Enum
{	mcAEX11ASFCSB2_NOT_AVL = 0,
	mcAEX11ASFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ASFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX11ASFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ASFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX11ASSSIFrmCfgStatBit2Enum;

typedef enum McAEX11ASSSIFrmCfgSSIDatCEnum
{	mcAEX11ASFCSDC_GRAY = 0,
	mcAEX11ASFCSDC_BIN = 1
} McAEX11ASSSIFrmCfgSSIDatCEnum;

typedef enum McAEX11ASSSIFrmCfgSSIParCkEnum
{	mcAEX11ASFCSPC_SSI_PAR_CK_ODD = 0,
	mcAEX11ASFCSPC_SSI_PAR_CK_EVEN = 1,
	mcAEX11ASFCSPC_OFF = 2
} McAEX11ASSSIFrmCfgSSIParCkEnum;

typedef enum McAEX11ABBiSSFrmCfgStatBit1Enum
{	mcAEX11ABBFCSB1_NOT_AVL = 0,
	mcAEX11ABBFCSB1_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ABBFCSB1_ERR_BIT_ACT_LOW = 2,
	mcAEX11ABBFCSB1_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ABBFCSB1_WAR_BIT_ACT_LOW = 4
} McAEX11ABBiSSFrmCfgStatBit1Enum;

typedef enum McAEX11ABBiSSFrmCfgStatBit2Enum
{	mcAEX11ABBFCSB2_NOT_AVL = 0,
	mcAEX11ABBFCSB2_ERR_BIT_ACT_HIGH = 1,
	mcAEX11ABBFCSB2_ERR_BIT_ACT_LOW = 2,
	mcAEX11ABBFCSB2_WAR_BIT_ACT_HIGH = 3,
	mcAEX11ABBFCSB2_WAR_BIT_ACT_LOW = 4
} McAEX11ABBiSSFrmCfgStatBit2Enum;

typedef enum McAEEncIfTypEnum
{	mcAEIT_ENDAT = 0
} McAEEncIfTypEnum;

typedef enum McAVAVirtAxEnum
{	mcAVAVA_NOT_USE = 0,
	mcAVAVA_USE = 1
} McAVAVirtAxEnum;

typedef enum McAVAVirtAxUseHomeModEnum
{	mcAVAVAUHM_DIR = 0,
	mcAVAVAUHM_RES_POS = 1,
	mcAVAVAUHM_NOT_USE = 100
} McAVAVirtAxUseHomeModEnum;

typedef enum McAVHHomeModEnum
{	mcAVHHM_DIR = 0,
	mcAVHHM_RES_POS = 1,
	mcAVHHM_NOT_USE = 100
} McAVHHomeModEnum;

typedef enum McAEEAExtEncAxEnum
{	mcAEEAEEA_NOT_USE = 0,
	mcAEEAEEA_USE = 1
} McAEEAExtEncAxEnum;

typedef enum McAEEAUseEncLinkEnum
{	mcAEEAUEL_ONE_ENC = 0
} McAEEAUseEncLinkEnum;

typedef enum McAEEAUseEncLinkOneEncPosEncEnum
{	mcAEEAUELOEPE_ENC_X41 = 0,
	mcAEEAUELOEPE_ENC_SS1X41X = 1,
	mcAEEAUELOEPE_ENC_X42 = 2,
	mcAEEAUELOEPE_ENC_SS1X42X = 3,
	mcAEEAUELOEPE_ENC_X43 = 4,
	mcAEEAUELOEPE_ENC_SS1X43X = 5,
	mcAEEAUELOEPE_ENC_SS1X11 = 6,
	mcAEEAUELOEPE_ENC_SS2X11 = 7,
	mcAEEAUELOEPE_ENC_SS3X11 = 8,
	mcAEEAUELOEPE_ENC_SS4X11 = 9
} McAEEAUseEncLinkOneEncPosEncEnum;

typedef enum McAEEAUELOneEncPosFltrEnum
{	mcAEEAUELOEPF_EXTPOL_AND_DIST = 0
} McAEEAUELOneEncPosFltrEnum;

typedef enum McAEEAHModEnum
{	mcAEEAHM_DIR = 0,
	mcAEEAHM_ABS = 4,
	mcAEEAHM_RES_POS = 10,
	mcAEEAHM_NOT_USE = 100
} McAEEAHModEnum;

typedef enum McAEEAHModDirRefPEnum
{	mcAEEAHMDRP_NOT_USE = 0,
	mcAEEAHMDRP_USE = 1
} McAEEAHModDirRefPEnum;

typedef struct McAcpAxLoopFilterLowPassType
{	float CutOffFrequency;
} McAcpAxLoopFilterLowPassType;

typedef struct McAcpAxLoopFilterNotchType
{	float CenterFrequency;
	float Bandwidth;
} McAcpAxLoopFilterNotchType;

typedef struct McAcpAxLoopFilterZTransFunType
{	float A0;
	float A1;
	float B0;
	float B1;
	float B2;
} McAcpAxLoopFilterZTransFunType;

typedef struct McAcpAxLoopFilterCompType
{	unsigned short MultiplicationFactorParID;
	unsigned short AdditiveValueParID;
} McAcpAxLoopFilterCompType;

typedef struct McAcpAxLoopFilterBiquadType
{	float FrequencyNumerator;
	float DampingNumerator;
	float FrequencyDenominator;
	float DampingDenominator;
} McAcpAxLoopFilterBiquadType;

typedef struct McAcpAxLoopFilterLimType
{	float PositiveLimit;
	float NegativeLimit;
	unsigned short PositiveLimitParID;
	unsigned short NegativeLimitParID;
} McAcpAxLoopFilterLimType;

typedef struct McAcpAxLoopFilterLimLinearType
{	unsigned short InputParID;
	float InputLimit;
	float Gradient;
} McAcpAxLoopFilterLimLinearType;

typedef struct McAcpAxLoopFilterLimRiseTimeType
{	float RiseTime;
	float NormalizedLimit;
} McAcpAxLoopFilterLimRiseTimeType;

typedef struct McAcpAxLoopFilterParType
{	enum McAcpAxLoopFilterTypeEnum Type;
	struct McAcpAxLoopFilterLowPassType LowPass;
	struct McAcpAxLoopFilterNotchType Notch;
	struct McAcpAxLoopFilterZTransFunType ZTransferFunction;
	struct McAcpAxLoopFilterCompType Compensation;
	struct McAcpAxLoopFilterBiquadType Biquad;
	struct McAcpAxLoopFilterLimType Limiter;
	struct McAcpAxLoopFilterLimLinearType LimiterLinear;
	struct McAcpAxLoopFilterLimRiseTimeType LimiterRiseTime;
} McAcpAxLoopFilterParType;

typedef struct McAcpAxAdvCtrlParType
{	struct McAcpAxLoopFilterParType LoopFilter1;
	struct McAcpAxLoopFilterParType LoopFilter2;
	struct McAcpAxLoopFilterParType LoopFilter3;
} McAcpAxAdvCtrlParType;

typedef struct McAcpAxPosCtrlParType
{	float ProportionalGain;
	float IntegrationTime;
	float PredictionTime;
	float TotalDelayTime;
} McAcpAxPosCtrlParType;

typedef struct McAcpAxSpeedCtrlParType
{	float ProportionalGain;
	float IntegrationTime;
	float FilterTime;
} McAcpAxSpeedCtrlParType;

typedef struct McAcpAxFeedForwardParType
{	float TorqueLoad;
	float TorquePositive;
	float TorqueNegative;
	float SpeedTorqueFactor;
	float Inertia;
	float AccelerationFilterTime;
} McAcpAxFeedForwardParType;

typedef struct McAcpAxCtrlParType
{	enum McAcpAxCtrlModeEnum Mode;
	struct McAcpAxPosCtrlParType PositionController;
	struct McAcpAxSpeedCtrlParType SpeedController;
	struct McAcpAxFeedForwardParType FeedForward;
	enum McAcpAxCtrlParSelectEnum ParameterSelector;
} McAcpAxCtrlParType;

typedef struct McAcpAxAutoTuneFeedFwdType
{	enum McDirectionEnum Direction;
	enum McAcpAxAutoTuneOrientationEnum Orientation;
	double MaxDistance;
	double MaxPositionError;
	float Velocity;
	float Acceleration;
	float MaxCurrentPercent;
	float MaxVelocityPercent;
} McAcpAxAutoTuneFeedFwdType;

typedef struct McAcpAxAutoTuneFeedFwdOutType
{	float Quality;
	struct McAcpAxFeedForwardParType FeedForward;
} McAcpAxAutoTuneFeedFwdOutType;

typedef struct McAcpAxHomingParType
{	enum McHomingModeEnum HomingMode;
	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McDirectionEnum SwitchEdge;
	enum McDirectionEnum StartDirection;
	enum McDirectionEnum HomingDirection;
	enum McSwitchEnum ReferencePulse;
	enum McSwitchEnum KeepDirection;
	float ReferencePulseBlockingDistance;
	float TorqueLimit;
	float BlockDetectionPositionError;
	float PositionErrorStopLimit;
	unsigned long RestorePositionVariableAddress;
} McAcpAxHomingParType;

typedef struct McAcpAxProcessParIDType
{	unsigned short ParID;
	unsigned long VariableAddress;
	enum McAcpAxDataTypeEnum DataType;
} McAcpAxProcessParIDType;

typedef struct McAcpAxProcessParTabDataType
{	plcstring DataObjectName[13];
} McAcpAxProcessParTabDataType;

typedef struct McAcpAxProcessParTabAddInfoType
{	unsigned long NumberOfParameters;
} McAcpAxProcessParTabAddInfoType;

typedef struct McAcpAxCycParIDType
{	unsigned short ParID;
	unsigned long VariableAddress;
	enum McAcpAxDataTypeEnum DataType;
	enum McAcpAxCycParIDRefreshModeEnum RefreshMode;
} McAcpAxCycParIDType;

typedef struct McAcpAxTriggerStopType
{	enum McAcpAxTriggerEnum TriggerSource;
	enum McEdgeEnum TriggerEdge;
	double TriggerDistance;
	enum McSwitchEnum ForceTriggerDistance;
} McAcpAxTriggerStopType;

typedef struct McAcpAxAdvLimitLoadParType
{	unsigned short LoadPosAccelParID;
	unsigned short LoadPosDecelParID;
	unsigned short LoadNegAccelParID;
	unsigned short LoadNegDecelParID;
} McAcpAxAdvLimitLoadParType;

typedef struct McAcpAxBrakeParType
{	enum McSwitchEnum AutomaticControl;
	enum McSwitchEnum RestrictedBrakeControl;
	enum McSwitchEnum ControlMonitoring;
	enum McSwitchEnum MovementMonitoring;
	enum McSwitchEnum VoltageMonitoring;
	enum McSwitchEnum TestAtPowerOn;
	enum McSwitchEnum TestAtPowerOff;
	enum McSwitchEnum AutomaticInductionStop;
	enum McSwitchEnum EnableSBTRequestBySMC;
	float ControlMonitoringFilterTime;
} McAcpAxBrakeParType;

typedef struct McAcpAxBrakeTestParType
{	enum McAcpAxBrakeTestModeEnum Mode;
	float Torque;
	float Duration;
	double PositionLimit;
} McAcpAxBrakeTestParType;

typedef struct McAcpAxSimulationMass1Type
{	float Inertia;
	float StaticFriction;
	float ViscousFriction;
} McAcpAxSimulationMass1Type;

typedef struct McAcpAxSimulationMass2Type
{	float Inertia;
	float StaticFriction;
	float ViscousFriction;
	float Stiffness;
	float Damping;
} McAcpAxSimulationMass2Type;

typedef struct McAcpAxSimulationParType
{	enum McAcpAxSimulationModeEnum Mode;
	unsigned short AdditiveLoadParID;
	struct McAcpAxSimulationMass1Type Mass1;
	struct McAcpAxSimulationMass2Type Mass2;
} McAcpAxSimulationParType;

typedef struct McAcpAxRestorePosType
{	signed long Data[18];
} McAcpAxRestorePosType;

typedef struct McAcpAxAxisInfoType
{	enum McAcpAxAxisTypeEnum AxisType;
	unsigned long ChannelNumber;
	enum McAcpAxSimulationOnPlcEnum AcoposSimulationOnPlcMode;
} McAcpAxAxisInfoType;

typedef struct McAcpAxModuleInfoType
{	enum McAcpAxProductFamilyEnum ProductFamily;
	enum McAcpAxModuleTypeEnum ModuleType;
	enum McNetworkTypeEnum NetworkType;
	unsigned long NodeNumber;
	enum McAcpAxSimulationOnPlcEnum AcoposSimulationOnPlc;
} McAcpAxModuleInfoType;

typedef struct McAcpAxFeedbackParType
{	float SpeedMixRatio;
	float SpeedProportionalGain;
} McAcpAxFeedbackParType;

typedef struct McAcpAxAutoTuneExSignalType
{	enum McAcpAxAutoTuneExSignalEnum SignalType;
	unsigned long SignalOrder;
	float DelayTime;
	float SignalStartFrequency;
	float SignalStopFrequency;
	float SignalTime;
} McAcpAxAutoTuneExSignalType;

typedef struct McAcpAxAutoTuneParType
{	enum McAcpAxAutoTuneOrientationEnum Orientation;
	float MaxCurrentPercent;
	double MaxDistance;
	double MaxPositionError;
} McAcpAxAutoTuneParType;

typedef struct McACPCType
{	float ProportionalGain;
	float IntegrationTime;
	float PredictionTime;
	float TotalDelayTime;
} McACPCType;

typedef struct McACSCType
{	float ProportionalGain;
	float IntegrationTime;
	float FilterTime;
} McACSCType;

typedef struct McACLFSLP2ndOrdType
{	float CutOffFrequency;
} McACLFSLP2ndOrdType;

typedef struct McACLFSNotchType
{	float CenterFrequency;
	float Bandwidth;
} McACLFSNotchType;

typedef struct McACLFSBiquadType
{	float FrequencyNumerator;
	float DampingNumerator;
	float FrequencyDenominator;
	float DampingDenominator;
} McACLFSBiquadType;

typedef struct McACLFSDiscTimeTranFunType
{	float a0DenominatorPolynomial;
	float a1DenominatorPolynomial;
	float b0NumeratorPolynomial;
	float b1NumeratorPolynomial;
	float b2NumeratorPolynomial;
} McACLFSDiscTimeTranFunType;

typedef struct McACLFSLLimAcpParIDType
{	unsigned short ParID;
} McACLFSLLimAcpParIDType;

typedef struct McACLFSLLimFixValType
{	float Value;
} McACLFSLLimFixValType;

typedef struct McACLFSLLimType
{	enum McACLFSLLimEnum Type;
	struct McACLFSLLimAcpParIDType ACOPOSParID;
	struct McACLFSLLimFixValType FixedValue;
} McACLFSLLimType;

typedef struct McACLFSLimType
{	struct McACLFSLLimType PositiveLimit;
	struct McACLFSLLimType NegativeLimit;
} McACLFSLimType;

typedef struct McACLFSLinLimType
{	unsigned short InputParID;
	float InputLimit;
	float Gradient;
} McACLFSLinLimType;

typedef struct McACLFSRiseTimeLimType
{	float RiseTime;
	float NormalizedLimit;
} McACLFSRiseTimeLimType;

typedef struct McACLFSCompType
{	unsigned short MultiplicationFactorParID;
	unsigned short AdditiveValueParID;
} McACLFSCompType;

typedef struct McACLFSType
{	enum McACLFSEnum Type;
	struct McACLFSLP2ndOrdType Lowpass2ndOrder;
	struct McACLFSNotchType Notch;
	struct McACLFSBiquadType Biquad;
	struct McACLFSDiscTimeTranFunType DiscreteTimeTransferFunction;
	struct McACLFSLimType Limiter;
	struct McACLFSLinLimType LinearLimitation;
	struct McACLFSRiseTimeLimType RiseTimeLimitation;
	struct McACLFSCompType Compensation;
} McACLFSType;

typedef struct McACLFType
{	struct McACLFSType LoopFilter[3];
} McACLFType;

typedef struct McACMPCType
{	struct McACPCType Position;
	struct McACSCType Speed;
	struct McACLFType LoopFilters;
} McACMPCType;

typedef struct McACPCFFType
{	float ProportionalGain;
	float IntegrationTime;
	float TotalDelayTime;
} McACPCFFType;

typedef struct McACMPCFFFFwdStdType
{	float TorqueLoad;
	float TorquePositive;
	float TorqueNegative;
	float SpeedTorqueFactor;
	float Inertia;
	float AccelerationFilterTime;
} McACMPCFFFFwdStdType;

typedef struct McACMPCFFFFwdType
{	enum McACMPCFFFFwdEnum Type;
	struct McACMPCFFFFwdStdType Standard;
} McACMPCFFFFwdType;

typedef struct McACMPCFFType
{	struct McACPCFFType Position;
	struct McACSCType Speed;
	struct McACMPCFFFFwdType FeedForward;
	struct McACLFType LoopFilters;
} McACMPCFFType;

typedef struct McACMPCMBCPosType
{	float ProportionalGain;
	float IntegrationTime;
	float TotalDelayTime;
} McACMPCMBCPosType;

typedef struct McACMPCMBCFFStdType
{	float TorqueLoad;
	float TorquePositive;
	float TorqueNegative;
	float SpeedTorqueFactor;
	float Inertia;
	float AccelerationFilterTime;
} McACMPCMBCFFStdType;

typedef struct McACMPCMBCFFPredSpdType
{	float PredictionTime;
} McACMPCMBCFFPredSpdType;

typedef struct McACMPCMBCFFTwoMassMdlBasedType
{	float TorqueLoad;
	float TorquePositive;
	float TorqueNegative;
	float AccelerationFilterTime;
} McACMPCMBCFFTwoMassMdlBasedType;

typedef struct McACMPCMBCFFType
{	enum McACMPCMBCFFEnum Type;
	struct McACMPCMBCFFStdType Standard;
	struct McACMPCMBCFFPredSpdType PredictiveSpeed;
	struct McACMPCMBCFFTwoMassMdlBasedType TwoMassModelBased;
} McACMPCMBCFFType;

typedef struct McACMPCMBCFdbkOneMassMdlBsdType
{	float SpeedMixingFactor;
	float SpeedProportionalGain;
} McACMPCMBCFdbkOneMassMdlBsdType;

typedef struct McACMPCMBCFdbkTwoMassMdlBsdType
{	float SpeedMixingFactor;
	float SpeedProportionalGain;
} McACMPCMBCFdbkTwoMassMdlBsdType;

typedef struct McACMPCMBCFdbkTwoEncSpdBasedType
{	float SpeedMixingFactor;
	float SpeedProportionalGain;
} McACMPCMBCFdbkTwoEncSpdBasedType;

typedef struct McACMPCMBCFdbkType
{	enum McACMPCMBCFdbkEnum Type;
	struct McACMPCMBCFdbkOneMassMdlBsdType OneMassModelBased;
	struct McACMPCMBCFdbkTwoMassMdlBsdType TwoMassModelBased;
	struct McACMPCMBCFdbkTwoEncSpdBasedType TwoEncoderSpeedBased;
} McACMPCMBCFdbkType;

typedef struct McACMPCMBCMdlMass1Type
{	float Inertia;
	float ViscousFriction;
} McACMPCMBCMdlMass1Type;

typedef struct McACMPCMBCMdlMass2Type
{	float Inertia;
	float ViscousFriction;
	float Stiffness;
	float Damping;
} McACMPCMBCMdlMass2Type;

typedef struct McACMPCMBCMdlType
{	struct McACMPCMBCMdlMass1Type Mass1;
	struct McACMPCMBCMdlMass2Type Mass2;
} McACMPCMBCMdlType;

typedef struct McACMPCMBCType
{	struct McACMPCMBCPosType Position;
	struct McACSCType Speed;
	struct McACMPCMBCFFType Feedforward;
	struct McACMPCMBCFdbkType Feedback;
	struct McACMPCMBCMdlType Model;
	struct McACLFType LoopFilters;
} McACMPCMBCType;

typedef struct McACMVFCVFAutCfgNotUseType
{	float BoostVoltage;
	float RatedVoltage;
	float RatedFrequency;
} McACMVFCVFAutCfgNotUseType;

typedef struct McACMVFCVFAutCfgType
{	enum McACMVFCVFAutCfgEnum Type;
	struct McACMVFCVFAutCfgNotUseType NotUsed;
} McACMVFCVFAutCfgType;

typedef struct McACMVFCVFType
{	enum McACMVFCVFTypEnum Type;
	struct McACMVFCVFAutCfgType AutomaticConfiguration;
	float SlipCompensation;
	float TotalDelayTime;
} McACMVFCVFType;

typedef struct McACMVFCType
{	struct McACMVFCVFType VoltageFrequency;
} McACMVFCType;

typedef struct McACModType
{	enum McACModEnum Type;
	struct McACMPCType PositionController;
	struct McACMPCFFType PositionControllerTorqueFf;
	struct McACMPCMBCType PositionControllerModelBased;
	struct McACMVFCType VoltageFrequencyControl;
} McACModType;

typedef struct McACType
{	struct McACModType Mode;
} McACType;

typedef struct McCfgAcpCtrlType
{	struct McACType Controller;
} McCfgAcpCtrlType;

typedef struct McAcpAxAutoTuneSpeedCtrlOutType
{	float Quality;
	float EstimatedInertia;
	float ProportionalGain;
	float IntegrationTime;
	float FilterTime;
	struct McAcpAxLoopFilterParType LoopFilter1;
	float PhaseCrossoverFrequency;
	struct McAcpAxFeedbackParType Feedback;
	struct McCfgAcpCtrlType Parameters;
} McAcpAxAutoTuneSpeedCtrlOutType;

typedef struct McAcpAxAutoTuneLoopFilterOutType
{	float Quality;
	struct McAcpAxLoopFilterParType LoopFilter1;
	struct McAcpAxLoopFilterParType LoopFilter2;
	struct McAcpAxLoopFilterParType LoopFilter3;
	struct McCfgAcpCtrlType Parameters;
} McAcpAxAutoTuneLoopFilterOutType;

typedef struct McAcpAxAutoTunePosCtrlOutType
{	float Quality;
	float ProportionalGain;
	struct McCfgAcpCtrlType Parameters;
} McAcpAxAutoTunePosCtrlOutType;

typedef struct McAcpAxAutoTuneTestOutType
{	float Quality;
} McAcpAxAutoTuneTestOutType;

typedef struct McAcpAxAutoTuneLoopFiltersType
{	enum McAcpAxLoopFilterModeEnum LoopFilter1Mode;
	enum McAcpAxLoopFilterModeEnum LoopFilter2Mode;
	enum McAcpAxLoopFilterModeEnum LoopFilter3Mode;
} McAcpAxAutoTuneLoopFiltersType;

typedef struct McAcpAxLoadModelMass1Type
{	float Inertia;
	float ViscousFriction;
} McAcpAxLoadModelMass1Type;

typedef struct McAcpAxLoadModelMass2Type
{	float Inertia;
	float ViscousFriction;
	float Stiffness;
	float Damping;
} McAcpAxLoadModelMass2Type;

typedef struct McAcpAxLoadModelType
{	struct McAcpAxLoadModelMass1Type Mass1;
	struct McAcpAxLoadModelMass2Type Mass2;
} McAcpAxLoadModelType;

typedef struct McAcpAxAdvAutoTuneSpeedCtrlType
{	enum McAcpAxFeedbackModeEnum FeedbackMode;
	enum McAcpAxLoopFilterModeEnum LoopFilter1Mode;
	enum McAcpAxFilterTimeModeEnum FilterTimeMode;
	enum McAcpAxIntegrationTimeModeEnum IntegrationTimeMode;
	enum McAcpAxAutoTuneOperatPointEnum OperatingPoint;
	float Velocity;
	float MaxVelocityPercent;
	float Acceleration;
	float MaxProportionalGain;
	float ProportionalGainPercent;
	float ResonanceFactor;
	float InertiaEstimationLowerFrequency;
	float InertiaEstimationUpperFrequency;
	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
	struct McAcpAxLoadModelType LoadModel;
} McAcpAxAdvAutoTuneSpeedCtrlType;

typedef struct McAcpAxAdvAutoTuneLoopFilterType
{	enum McAcpAxAutoTuneOperatPointEnum OperatingPoint;
	float Velocity;
	float Acceleration;
	float ResonanceFactor;
	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
} McAcpAxAdvAutoTuneLoopFilterType;

typedef struct McAcpAxAdvAutoTunePosCtrlType
{	enum McAcpAxAutoTuneOperatPointEnum OperatingPoint;
	float Velocity;
	float Acceleration;
	float MaxProportionalGain;
	float ProportionalGainPercent;
	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
} McAcpAxAdvAutoTunePosCtrlType;

typedef struct McAcpAxAdvAutoTuneTestType
{	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
} McAcpAxAdvAutoTuneTestType;

typedef struct McAcpAxAutoTuneIndMotParType
{	float NominalVoltage;
	float NominalCurrent;
	float NominalSpeed;
	float NominalFrequency;
	float PowerFactor;
	float ThermalTrippingTime;
} McAcpAxAutoTuneIndMotParType;

typedef struct McAcpAxAdvAutoTuneIndMotType
{	unsigned char Phase;
	unsigned char NumberOfPolePairs;
	float MaximumSpeed;
	float StallTorque;
	float NominalTorque;
	float PeakTorque;
	float StallCurrent;
	float PeakCurrent;
	float MagnetizingCurrent;
	float WindingCrossSection;
	float InverterCharacteristicGain;
	float InverterCharacteristicExponent;
} McAcpAxAdvAutoTuneIndMotType;

typedef struct McMIMotPwrRtgPltOptParType
{	unsigned char NumberOfPolePairs;
	float MaximumSpeed;
	float MaximumDCBusVoltage;
	float StallCurrent;
	float PeakCurrent;
	float MagnetizingCurrent;
	float NominalPower;
	float NominalTorque;
	float StallTorque;
	float PeakTorque;
	float MomentOfInertia;
} McMIMotPwrRtgPltOptParType;

typedef struct McMMTSThermType
{	unsigned short LimitTemperature;
	enum McMMTSThermTmpSensIfEnum TemperatureSensorInterface;
	float ResistanceR0;
	float ResistanceR7;
	float TemperatureT0;
	float TemperatureT1;
	float TemperatureT2;
	float TemperatureT3;
	float TemperatureT4;
	float TemperatureT5;
	float TemperatureT6;
	float TemperatureT7;
} McMMTSThermType;

typedef struct McMMTSSwPTCThermType
{	enum McMMTSSwPTCThermTmpSensIfEnum TemperatureSensorInterface;
	float NominalResponseResistance;
	float MinimumResistance;
	float NominalResponseTemperature;
} McMMTSSwPTCThermType;

typedef struct McMMTSThrmSwType
{	enum McMMTSThrmSwTmpSensIfEnum TemperatureSensorInterface;
	float NominalResponseTemperature;
	enum McMMTSThrmSwSwStatOnOvrTmpEnum SwitchingStateOnOvertemperature;
} McMMTSThrmSwType;

typedef struct McMMTmpSensType
{	enum McMMTmpSensEnum Type;
	struct McMMTSThermType Thermistor;
	struct McMMTSSwPTCThermType SwitchingPTCThermistor;
	struct McMMTSThrmSwType Thermoswitches;
} McMMTmpSensType;

typedef struct McMMTMCSBCMRefTmpEncTmpSensType
{	float TemperatureOffset;
	float TimeConstant;
} McMMTMCSBCMRefTmpEncTmpSensType;

typedef struct McMMTMCSBCMRefTmpType
{	enum McMMTMCSBCMRefTmpEnum Type;
	struct McMMTMCSBCMRefTmpEncTmpSensType EncoderTemperatureSensor;
} McMMTMCSBCMRefTmpType;

typedef struct McMMTMCSBCMSecOrdType
{	float WindingCrossSection;
	float ThermalTrippingTime;
	float ThermalTimeConstant;
	struct McMMTMCSBCMRefTmpType ReferenceTemperature;
} McMMTMCSBCMSecOrdType;

typedef struct McMMTMCSBCMFthOrdType
{	float ThermalResistance1;
	float ThermalCapacity1;
	float ThermalResistance2;
	float ThermalCapacity2;
	float StatorThermalLoss1;
	float StatorThermalLoss2;
	struct McMMTMCSBCMRefTmpType ReferenceTemperature;
} McMMTMCSBCMFthOrdType;

typedef struct McMMTMCSBCMFthOrdWCplgType
{	float ThermalResistance1;
	float ThermalCapacity1;
	float ThermalResistance2;
	float ThermalCapacity2;
	float ThermalResistance3;
	float StatorThermalLoss1;
	float StatorThermalLoss2;
	float WindingThermalLoss1;
	float WindingThermalLoss2;
	struct McMMTMCSBCMRefTmpType ReferenceTemperature;
} McMMTMCSBCMFthOrdWCplgType;

typedef struct McMMTMCSBCalcMethType
{	enum McMMTMCSBCalcMethEnum Type;
	struct McMMTMCSBCMSecOrdType SecondOrderThermalNetwork;
	struct McMMTMCSBCMFthOrdType FourthOrderThermalNetwork;
	struct McMMTMCSBCMFthOrdWCplgType FourthOrderWithCouplings;
} McMMTMCSBCalcMethType;

typedef struct McMMTMCurSpdBsdType
{	float LimitTemperature;
	struct McMMTMCSBCalcMethType CalculationMethod;
} McMMTMCurSpdBsdType;

typedef struct McMMTMCurBsdType
{	float LimitTemperature;
	float WindingCrossSection;
	float ThermalTrippingTime;
	float ThermalTimeConstant;
} McMMTMCurBsdType;

typedef struct McMMTmpMdlType
{	enum McMMTmpMdlEnum Type;
	struct McMMTMCurSpdBsdType CurrentAndSpeedBased;
	struct McMMTMCurBsdType CurrentBased;
} McMMTmpMdlType;

typedef struct McMIMotPwrRtgPltType
{	float NominalSpeed;
	float NominalFrequency;
	float NominalVoltage;
	float NominalCurrent;
	float PowerFactor;
	float NominalAmbientTemperature;
	struct McMIMotPwrRtgPltOptParType OptionalParameter;
	struct McMMTmpSensType TemperatureSensor;
	struct McMMTmpMdlType TemperatureModel;
} McMIMotPwrRtgPltType;

typedef struct McMIMotStarEqCirVLimUseType
{	float MaximumDCBusVoltage;
} McMIMotStarEqCirVLimUseType;

typedef struct McMIMotStarEqCirVLimType
{	enum McMIMotStarEqCirVLimEnum Type;
	struct McMIMotStarEqCirVLimUseType Used;
} McMIMotStarEqCirVLimType;

typedef struct McMIMotStarEqCirType
{	unsigned char NumberOfPolePairs;
	float NominalSpeed;
	float MaximumSpeed;
	float NominalVoltage;
	float NominalCurrent;
	float StallCurrent;
	float PeakCurrent;
	float MagnetizingCurrent;
	float NominalTorque;
	float StallTorque;
	float PeakTorque;
	float StatorResistance;
	float RotorResistance;
	float StatorInductance;
	float RotorInductance;
	float MutualInductance;
	float MomentOfInertia;
	float NominalAmbientTemperature;
	struct McMIMotStarEqCirVLimType VoltageLimitation;
	struct McMMTmpSensType TemperatureSensor;
	struct McMMTmpMdlType TemperatureModel;
} McMIMotStarEqCirType;

typedef struct McMIMotType
{	enum McMIMotEnum Type;
	struct McMIMotPwrRtgPltType PowerRatingPlate;
	struct McMIMotStarEqCirType StarEquivalentCircuit;
} McMIMotType;

typedef struct McMIBrkUseCtrlModVCtrlType
{	float ReleaseVoltage;
	float HoldVoltage;
} McMIBrkUseCtrlModVCtrlType;

typedef struct McMIBrkUseCtrlModType
{	enum McMIBrkUseCtrlModEnum Type;
	struct McMIBrkUseCtrlModVCtrlType VoltageControlled;
} McMIBrkUseCtrlModType;

typedef struct McMIBrkUseLimUseType
{	float MaximumVoltage;
} McMIBrkUseLimUseType;

typedef struct McMIBrkUseLimType
{	enum McMIBrkUseLimEnum Type;
	struct McMIBrkUseLimUseType Used;
} McMIBrkUseLimType;

typedef struct McMIBrkUseType
{	float NominalCurrent;
	float NominalTorque;
	float ActivationDelay;
	float ReleaseDelay;
	float MomentOfInertia;
	struct McMIBrkUseCtrlModType ControlMode;
	struct McMIBrkUseLimType Limits;
} McMIBrkUseType;

typedef struct McMIBrkType
{	enum McMIBrkEnum Type;
	struct McMIBrkUseType Used;
} McMIBrkType;

typedef struct McMIEncUseTmpSensUseType
{	unsigned short LimitTemperature;
} McMIEncUseTmpSensUseType;

typedef struct McMIEncUseTmpSensType
{	enum McMIEncUseTmpSensEnum Type;
	struct McMIEncUseTmpSensUseType Used;
} McMIEncUseTmpSensType;

typedef struct McMIEncUseType
{	float MomentOfInertia;
	struct McMIEncUseTmpSensType TemperatureSensor;
} McMIEncUseType;

typedef struct McMIEncType
{	enum McMIEncEnum Type;
	struct McMIEncUseType Used;
} McMIEncType;

typedef struct McMIGBUseType
{	struct McCfgGearBoxType GearRatio;
	float MaximumInputSpeed;
	float NominalOutputTorque;
	float PeakOutputTorque;
	float MomentOfInertia;
} McMIGBUseType;

typedef struct McMIGBType
{	enum McMIGBEnum Type;
	struct McMIGBUseType Used;
} McMIGBType;

typedef struct McCfgMotInductType
{	struct McMIMotType Motor;
	struct McMIBrkType Brake;
	struct McMIEncType Encoder;
	struct McMIGBType Gearbox;
} McCfgMotInductType;

typedef struct McAcpAxAutoTuneIndMotOutType
{	float Quality;
	struct McCfgMotInductType Parameters;
	unsigned char NumberOfPolePairs;
	float MaximumSpeed;
	float StallTorque;
	float NominalTorque;
	float PeakTorque;
	float StallCurrent;
	float PeakCurrent;
	float WindingCrossSection;
	float StatorResistance;
	float StatorInductance;
	float RotorResistance;
	float RotorInductance;
	float MutualInductance;
	float MagnetizingCurrent;
} McAcpAxAutoTuneIndMotOutType;

typedef struct McAcpAxAutoTuneSyncMotParType
{	float NominalVoltage;
	float NominalCurrent;
	float NominalSpeed;
	float NominalTorque;
	unsigned char NumberOfPolePairs;
	float PeakCurrent;
	float PeakTorque;
	float ThermalTrippingTime;
} McAcpAxAutoTuneSyncMotParType;

typedef struct McAcpAxAdvAutoTuneSyncMotType
{	unsigned char Phase;
	float VoltageConstant;
	float MaximumSpeed;
	float StallTorque;
	float TorqueConstant;
	float StallCurrent;
	float WindingCrossSection;
	float InverterCharacteristicGain;
	float InverterCharacteristicExponent;
} McAcpAxAdvAutoTuneSyncMotType;

typedef struct McMSMotDefVLimUseType
{	float MaximumDCBusVoltage;
} McMSMotDefVLimUseType;

typedef struct McMSMotDefVLimType
{	enum McMSMotDefVLimEnum Type;
	struct McMSMotDefVLimUseType Used;
} McMSMotDefVLimType;

typedef struct McMMDEMAngUsrDefType
{	float CommutationOffset;
} McMMDEMAngUsrDefType;

typedef struct McMMDEMAngUdefAutIdentSatType
{	float PhasingCurrent;
} McMMDEMAngUdefAutIdentSatType;

typedef struct McMMDEMAngUdefAutIdentDitType
{	float PhasingCurrent;
	float PhasingTime;
} McMMDEMAngUdefAutIdentDitType;

typedef struct McMMDEMAngUdefAutIdentDit2Type
{	float PhasingCurrent;
	float PhasingTime;
} McMMDEMAngUdefAutIdentDit2Type;

typedef struct McMMDEMAngUdefAutIdentType
{	enum McMMDEMAngUdefAutIdentEnum Type;
	struct McMMDEMAngUdefAutIdentSatType Saturation;
	struct McMMDEMAngUdefAutIdentDitType Dither;
	struct McMMDEMAngUdefAutIdentDit2Type Dither2;
} McMMDEMAngUdefAutIdentType;

typedef struct McMMDEMAngUdefType
{	struct McMMDEMAngUdefAutIdentType AutomaticIdentification;
} McMMDEMAngUdefType;

typedef struct McMMDEMAngType
{	enum McMMDEMAngEnum Type;
	struct McMMDEMAngUsrDefType UserDefined;
	struct McMMDEMAngUdefType Undefined;
} McMMDEMAngType;

typedef struct McMSMotDefEncMntType
{	struct McMMDEMAngType Angle;
} McMSMotDefEncMntType;

typedef struct McMSMotDefType
{	unsigned char NumberOfPolePairs;
	float NominalSpeed;
	float MaximumSpeed;
	float NominalVoltage;
	float NominalCurrent;
	float StallCurrent;
	float PeakCurrent;
	float NominalTorque;
	float StallTorque;
	float PeakTorque;
	float VoltageConstant;
	float TorqueConstant;
	float StatorResistance;
	float StatorInductance;
	float MomentOfInertia;
	float NominalAmbientTemperature;
	struct McMSMotDefVLimType VoltageLimitation;
	struct McMSMotDefEncMntType EncoderMounting;
	struct McMMTmpSensType TemperatureSensor;
	struct McMMTmpMdlType TemperatureModel;
} McMSMotDefType;

typedef struct McMSMotType
{	enum McMSMotEnum Type;
	struct McMSMotDefType Default;
} McMSMotType;

typedef struct McMSBrkUseCtrlModVCtrlType
{	float ReleaseVoltage;
	float HoldVoltage;
} McMSBrkUseCtrlModVCtrlType;

typedef struct McMSBrkUseCtrlModType
{	enum McMSBrkUseCtrlModEnum Type;
	struct McMSBrkUseCtrlModVCtrlType VoltageControlled;
} McMSBrkUseCtrlModType;

typedef struct McMSBrkUseLimUseType
{	float MaximumVoltage;
} McMSBrkUseLimUseType;

typedef struct McMSBrkUseLimType
{	enum McMSBrkUseLimEnum Type;
	struct McMSBrkUseLimUseType Used;
} McMSBrkUseLimType;

typedef struct McMSBrkUseType
{	float NominalCurrent;
	float NominalTorque;
	float ActivationDelay;
	float ReleaseDelay;
	float MomentOfInertia;
	struct McMSBrkUseCtrlModType ControlMode;
	struct McMSBrkUseLimType Limits;
} McMSBrkUseType;

typedef struct McMSBrkType
{	enum McMSBrkEnum Type;
	struct McMSBrkUseType Used;
} McMSBrkType;

typedef struct McMSEncUseTmpSensUseType
{	unsigned short LimitTemperature;
} McMSEncUseTmpSensUseType;

typedef struct McMSEncUseTmpSensType
{	enum McMSEncUseTmpSensEnum Type;
	struct McMSEncUseTmpSensUseType Used;
} McMSEncUseTmpSensType;

typedef struct McMSEncUseType
{	float MomentOfInertia;
	struct McMSEncUseTmpSensType TemperatureSensor;
} McMSEncUseType;

typedef struct McMSEncType
{	enum McMSEncEnum Type;
	struct McMSEncUseType Used;
} McMSEncType;

typedef struct McMSGBUseType
{	struct McCfgGearBoxType GearRatio;
	float MaximumInputSpeed;
	float NominalOutputTorque;
	float PeakOutputTorque;
	float MomentOfInertia;
} McMSGBUseType;

typedef struct McMSGBType
{	enum McMSGBEnum Type;
	struct McMSGBUseType Used;
} McMSGBType;

typedef struct McCfgMotSynType
{	struct McMSMotType Motor;
	struct McMSBrkType Brake;
	struct McMSEncType Encoder;
	struct McMSGBType Gearbox;
} McCfgMotSynType;

typedef struct McAcpAxAutoTuneSyncMotOutType
{	float Quality;
	struct McCfgMotSynType Parameters;
	float VoltageConstant;
	float MaximumSpeed;
	float StallTorque;
	float TorqueConstant;
	float StallCurrent;
	float WindingCrossSection;
	float StatorResistance;
	float StatorInductance;
} McAcpAxAutoTuneSyncMotOutType;

typedef struct McAcpAxAutoTuneMotPhasParType
{	float PhasingCurrent;
	float PhasingTime;
} McAcpAxAutoTuneMotPhasParType;

typedef struct McAcpAxAdvAutoTuneMotPhasType
{	float CommutationOffset;
} McAcpAxAdvAutoTuneMotPhasType;

typedef struct McAcpAxAutoTuneMotPhasOutType
{	float Quality;
	unsigned char NumberOfPolePairs;
	float CommutationOffset;
} McAcpAxAutoTuneMotPhasOutType;

typedef struct McAcpAxAdvAutoTuneLoadModelType
{	enum McAcpAxLoadModelIdentModeEnum IdentMode;
	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
} McAcpAxAdvAutoTuneLoadModelType;

typedef struct McAcpAxAutoTuneLoadModelOutType
{	float Quality;
	struct McAcpAxLoadModelType LoadModel;
	struct McCfgAcpCtrlType Parameters;
} McAcpAxAutoTuneLoadModelOutType;

typedef struct McAcpAxAdvCamAutSetParType
{	enum McCamAutParLockCmdEnum ParLock;
} McAcpAxAdvCamAutSetParType;

typedef struct McAcpAxCamAutEventParType
{	enum McCamAutEventTypeEnum Type;
	enum McCamAutEventTransitionEnum Transition;
	enum McSwitchEnum SynchronousUpdate;
	unsigned char NextState;
} McAcpAxCamAutEventParType;

typedef struct McAcpAxCamAutCompParType
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
} McAcpAxCamAutCompParType;

typedef struct McAcpAxCamAutAdvStateParType
{	unsigned short RepeatCounterInit;
	enum McSwitchEnum RepeatCounterSetTransfer;
	unsigned short RepeatCounterSet;
	struct McAxisType* MasterAxis;
	unsigned short MasterParID;
} McAcpAxCamAutAdvStateParType;

typedef struct McAcpAxCamAutStateParType
{	unsigned short CamID;
	signed long MasterFactor;
	signed long SlaveFactor;
	enum McCamAutCompModeEnum CompensationMode;
	struct McAcpAxCamAutCompParType CompensationParameters;
	struct McAcpAxCamAutAdvStateParType AdvancedParameters;
	struct McAcpAxCamAutEventParType Event[5];
} McAcpAxCamAutStateParType;

typedef struct McAcpAxCamAutCtrlSettingsType
{	enum McCamAutCrossLeftBoundEnum CrossLeftBoundary;
	enum McCamAutCamChangeImmedEnum CamChangeImmediately;
} McAcpAxCamAutCtrlSettingsType;

typedef struct McAcpAxCamAutMsgSettingsType
{	enum McCamAutErrorsInStandbyEnum ErrorsInStandby;
	enum McCamAutExceedingLimitsEnum ExceedingLimits;
} McAcpAxCamAutMsgSettingsType;

typedef struct McAcpAxCamAutTriggerAndLatchType
{	float Trigger1Delay;
	float Trigger2Delay;
	unsigned short SlaveLatchParID;
} McAcpAxCamAutTriggerAndLatchType;

typedef struct McAcpAxCamAutStartStateParType
{	unsigned char StartState;
	double MasterStartRelPos;
} McAcpAxCamAutStartStateParType;

typedef struct McAcpAxCamAutAddAxesType
{	struct McAxisType* AdditiveMasterAxis;
	unsigned short AdditiveMasterParID;
	struct McAxisType* AdditiveSlaveAxis;
	unsigned short AdditiveSlaveParID;
} McAcpAxCamAutAddAxesType;

typedef struct McAcpAxCamAutCommonFactorsType
{	unsigned short SlaveFactorParID;
} McAcpAxCamAutCommonFactorsType;

typedef struct McAcpAxCamAutAdvParType
{	struct McAcpAxCamAutStartStateParType StartStateParam;
	struct McAcpAxCamAutAddAxesType AdditiveAxes;
	enum McCamAutMaStartPosModeEnum MasterStartPosMode;
	struct McAcpAxCamAutCtrlSettingsType ControlSettings;
	struct McAcpAxCamAutMsgSettingsType MessageSettings;
	struct McAcpAxCamAutTriggerAndLatchType TriggerAndLatch;
	unsigned short EventParID1;
	unsigned short EventParID2;
	unsigned short EventParID3;
	unsigned short EventParID4;
	double StartIntervalPos1;
	double StartIntervalPos2;
	double StartIntervalPos3;
	double StartIntervalPos4;
	struct McAcpAxCamAutCommonFactorsType Factors;
} McAcpAxCamAutAdvParType;

typedef struct McAcpAxCamAutMasterParType
{	struct McAxisType* MasterAxis;
	unsigned short MasterParID;
	double MasterStartPosition;
	double MasterStartInterval;
	float MaxMasterVelocity;
} McAcpAxCamAutMasterParType;

typedef struct McAcpAxCamAutCommonParType
{	struct McAcpAxCamAutMasterParType Master;
	struct McAcpAxCamAutAdvParType AdvancedParameters;
} McAcpAxCamAutCommonParType;

typedef struct McAcpAxCamAutParType
{	struct McAcpAxCamAutCommonParType Common;
	struct McAcpAxCamAutStateParType State[15];
} McAcpAxCamAutParType;

typedef struct McAcpAxCamAutDefineType
{	plcstring DataObjectName[33];
	unsigned long DataAddress;
} McAcpAxCamAutDefineType;

typedef struct McAcpAxAdvPhasingParType
{	unsigned short VelocityParID;
	unsigned short PosVelocityTriggerParID;
	unsigned short NegVelocityTriggerParID;
} McAcpAxAdvPhasingParType;

typedef struct McAcpAxAdvOffsetParType
{	unsigned short VelocityParID;
	unsigned short PosVelocityTriggerParID;
	unsigned short NegVelocityTriggerParID;
} McAcpAxAdvOffsetParType;

typedef struct McAcpAxAdvAutoTuneFeedFwdType
{	struct McAcpAxAutoTuneExSignalType ExcitationSignal;
} McAcpAxAdvAutoTuneFeedFwdType;

typedef struct McAcpAxLoadSimInputDataType
{	double Position;
	float Velocity;
	float Acceleration;
} McAcpAxLoadSimInputDataType;

typedef struct McAMEType
{	struct McCfgGearBoxType Gearbox;
	struct McCfgRotToLinTrfType RotaryToLinearTransformation;
} McAMEType;

typedef struct McAELOneEncMotAndPosEncType
{	enum McAELAllEncEnum Type;
} McAELOneEncMotAndPosEncType;

typedef struct McAELOneEncType
{	struct McAELOneEncMotAndPosEncType MotorAndPositionEncoder;
} McAELOneEncType;

typedef struct McAELTwoEncMotEncType
{	enum McAELAllEncEnum Type;
} McAELTwoEncMotEncType;

typedef struct McAELTwoEncPosEncCmnScType
{	struct McCfgGearBoxType Gearbox;
	struct McCfgRotToLinTrfType RotaryToLinearTransformation;
	enum McAELTwoEncPosEncCmnScCntDirEnum CountDirection;
} McAELTwoEncPosEncCmnScType;

typedef struct McAELTwoEncPosEncCmnType
{	struct McAELTwoEncPosEncCmnScType Scaling;
} McAELTwoEncPosEncCmnType;

typedef struct McAELTwoEncPosEncType
{	enum McAELAllEncEnum Type;
	struct McAELTwoEncPosEncCmnType Common;
} McAELTwoEncPosEncType;

typedef struct McAELTwoEncType
{	struct McAELTwoEncMotEncType MotorEncoder;
	struct McAELTwoEncPosEncType PositionEncoder;
	float PositionDifferenceLimit;
} McAELTwoEncType;

typedef struct McAELType
{	enum McAELEnum Type;
	struct McAELOneEncType OneEncoder;
	struct McAELTwoEncType TwoEncoders;
} McAELType;

typedef struct McAHModDirRefPUseType
{	float HomingVelocity;
	float Acceleration;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
	double ReferencePulseBlockingDistance;
} McAHModDirRefPUseType;

typedef struct McAHModDirRefPType
{	enum McAHModDirRefPEnum Type;
	struct McAHModDirRefPUseType Used;
} McAHModDirRefPType;

typedef struct McAHModDirType
{	double Position;
	struct McAHModDirRefPType ReferencePulse;
} McAHModDirType;

typedef struct McAHModRefPUseType
{	double ReferencePulseBlockingDistance;
} McAHModRefPUseType;

typedef struct McAHModRefPType
{	enum McAHModRefPEnum Type;
	struct McAHModRefPUseType Used;
} McAHModRefPType;

typedef struct McAHModAbsSwType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McAHModSwEdgEnum SwitchEdge;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
	struct McAHModRefPType ReferencePulse;
} McAHModAbsSwType;

typedef struct McAHModSwGateType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McAHModSwEdgEnum SwitchEdge;
	enum McAHModStartDirEnum StartDirection;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
	struct McAHModRefPType ReferencePulse;
} McAHModSwGateType;

typedef struct McAHModLimSwType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McAHModSwEdgEnum SwitchEdge;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
	struct McAHModRefPType ReferencePulse;
} McAHModLimSwType;

typedef struct McAHModAbsType
{	double Position;
} McAHModAbsType;

typedef struct McAHModAbsIntType
{	double Position;
} McAHModAbsIntType;

typedef struct McAHModAbsCorrType
{	double Position;
} McAHModAbsCorrType;

typedef struct McAHModDistCMarksType
{	double Position;
	float HomingVelocity;
	float Acceleration;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
} McAHModDistCMarksType;

typedef struct McAHModDistCMarksCorrType
{	double Position;
	float HomingVelocity;
	float Acceleration;
	enum McAHModHomeDirEnum HomingDirection;
	enum McAHModKeepDirEnum KeepDirection;
} McAHModDistCMarksCorrType;

typedef struct McAHModBlkRefPNotUseType
{	double MinimumReturnDistance;
} McAHModBlkRefPNotUseType;

typedef struct McAHModBlkRefPUseType
{	double ReferencePulseBlockingDistance;
} McAHModBlkRefPUseType;

typedef struct McAHModBlkRefPType
{	enum McAHModRefPEnum Type;
	struct McAHModBlkRefPNotUseType NotUsed;
	struct McAHModBlkRefPUseType Used;
} McAHModBlkRefPType;

typedef struct McAHModBlkTorqType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McAHModStartDirEnum StartDirection;
	enum McAHModHomeDirEnum HomingDirection;
	struct McAHModBlkRefPType ReferencePulse;
	float TorqueLimit;
	double PositionErrorStopLimit;
} McAHModBlkTorqType;

typedef struct McAHModBlkLagErrType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McAHModStartDirEnum StartDirection;
	enum McAHModHomeDirEnum HomingDirection;
	struct McAHModBlkRefPType ReferencePulse;
	float TorqueLimit;
	double PositionErrorStopLimit;
	double BlockDetectionPositionError;
} McAHModBlkLagErrType;

typedef struct McAHModType
{	enum McAHModEnum Type;
	struct McAHModDirType Direct;
	struct McAHModAbsSwType AbsoluteSwitch;
	struct McAHModSwGateType SwitchGate;
	struct McAHModLimSwType LimitSwitch;
	struct McAHModAbsType Absolute;
	struct McAHModAbsIntType AbsoluteInternal;
	struct McAHModAbsCorrType AbsoluteCorrection;
	struct McAHModDistCMarksType DistanceCodedMarks;
	struct McAHModDistCMarksCorrType DistanceCodedMarksCorrection;
	struct McAHModBlkTorqType BlockTorque;
	struct McAHModBlkLagErrType BlockLagError;
} McAHModType;

typedef struct McAHType
{	struct McAHModType Mode;
	plcstring RestorePositionVariable[251];
} McAHType;

typedef struct McASRQstopDecLimWJerkFltrType
{	float JerkTime;
} McASRQstopDecLimWJerkFltrType;

typedef struct McASRQstopType
{	enum McASRQstopEnum Type;
	struct McASRQstopDecLimWJerkFltrType DecelerationLimitWithJerkFilter;
} McASRQstopType;

typedef struct McASRDrvErrType
{	enum McASRDrvErrEnum Type;
} McASRDrvErrType;

typedef struct McASRType
{	struct McASRQstopType Quickstop;
	struct McASRDrvErrType DriveError;
} McASRType;

typedef struct McAMELVelErrMonUsrDefType
{	float VelocityError;
} McAMELVelErrMonUsrDefType;

typedef struct McAMELVelErrMonType
{	enum McAMELVelErrMonEnum Type;
	struct McAMELVelErrMonUsrDefType UserDefined;
} McAMELVelErrMonType;

typedef struct McAMELType
{	double PositionError;
	struct McAMELVelErrMonType VelocityErrorMonitoring;
} McAMELType;

typedef struct McAJFUseType
{	float JerkTime;
} McAJFUseType;

typedef struct McAJFType
{	enum McAJFEnum Type;
	struct McAJFUseType Used;
} McAJFType;

typedef struct McADIAllSrcVarType
{	plcstring PVMapping[251];
} McADIAllSrcVarType;

typedef struct McADIHomeSwSrcType
{	enum McADIAllSrcEnum Type;
	struct McADIAllSrcVarType Variable;
} McADIHomeSwSrcType;

typedef struct McADIHomeSwType
{	struct McADIHomeSwSrcType Source;
	enum McADILvlEnum Level;
} McADIHomeSwType;

typedef struct McADIPosLimSwSrcType
{	enum McADIAllSrcEnum Type;
	struct McADIAllSrcVarType Variable;
} McADIPosLimSwSrcType;

typedef struct McADIPosLimSwType
{	struct McADIPosLimSwSrcType Source;
	enum McADILvlEnum Level;
} McADIPosLimSwType;

typedef struct McADINegLimSwSrcType
{	enum McADIAllSrcEnum Type;
	struct McADIAllSrcVarType Variable;
} McADINegLimSwSrcType;

typedef struct McADINegLimSwType
{	struct McADINegLimSwSrcType Source;
	enum McADILvlEnum Level;
} McADINegLimSwType;

typedef struct McADITrg1SrcType
{	enum McADIAllSrcEnum Type;
	struct McADIAllSrcVarType Variable;
} McADITrg1SrcType;

typedef struct McADITrg1Type
{	struct McADITrg1SrcType Source;
	enum McADILvlEnum Level;
} McADITrg1Type;

typedef struct McADITrg2SrcType
{	enum McADIAllSrcEnum Type;
	struct McADIAllSrcVarType Variable;
} McADITrg2SrcType;

typedef struct McADITrg2Type
{	struct McADITrg2SrcType Source;
	enum McADILvlEnum Level;
} McADITrg2Type;

typedef struct McADIQstopType
{	enum McADIQstopInEnum Input;
} McADIQstopType;

typedef struct McADIType
{	struct McADIHomeSwType HomingSwitch;
	struct McADIPosLimSwType PositiveLimitSwitch;
	struct McADINegLimSwType NegativeLimitSwitch;
	struct McADITrg1Type Trigger1;
	struct McADITrg2Type Trigger2;
	struct McADIQstopType Quickstop;
} McADIType;

typedef struct McASLMOneMassMotBasedType
{	unsigned short AdditiveLoadParID;
} McASLMOneMassMotBasedType;

typedef struct McASLMOneMassType
{	float Inertia;
	float StaticFriction;
	float ViscousFriction;
	unsigned short AdditiveLoadParID;
} McASLMOneMassType;

typedef struct McASLMTwoMassMass1Type
{	float Inertia;
	float StaticFriction;
	float ViscousFriction;
} McASLMTwoMassMass1Type;

typedef struct McASLMTwoMassMass2Type
{	float Inertia;
	float StaticFriction;
	float ViscousFriction;
	float Stiffness;
	float Damping;
	unsigned short AdditiveLoadParID;
} McASLMTwoMassMass2Type;

typedef struct McASLMTwoMassType
{	struct McASLMTwoMassMass1Type Mass1;
	struct McASLMTwoMassMass2Type Mass2;
} McASLMTwoMassType;

typedef struct McASLMType
{	enum McASLMEnum Type;
	struct McASLMOneMassMotBasedType OneMassMotorBased;
	struct McASLMOneMassType OneMass;
	struct McASLMTwoMassType TwoMasses;
} McASLMType;

typedef struct McASPMComplType
{	struct McASLMType LoadModel;
} McASPMComplType;

typedef struct McASPMType
{	enum McASPMEnum Type;
	struct McASPMComplType Complete;
} McASPMType;

typedef struct McASAMComplType
{	struct McASLMType LoadModel;
} McASAMComplType;

typedef struct McASAMType
{	enum McASAMEnum Type;
	struct McASAMComplType Complete;
} McASAMType;

typedef struct McASType
{	struct McASPMType ModeOnPLC;
	struct McASAMType ModeOnACOPOS;
} McASType;

typedef struct McAAFType
{	struct McCfgUnboundedArrayType FeatureReference;
} McAAFType;

typedef struct McCfgAcpAxType
{	struct McCfgReferenceType AxisReference;
	struct McAMEType MechanicalElements;
	struct McAELType EncoderLink;
	struct McACType Controller;
	struct McAHType Homing;
	struct McASRType StopReaction;
	struct McAMELType MovementErrorLimits;
	struct McAJFType JerkFilter;
	struct McADIType DigitalInputs;
	struct McASType Simulation;
	struct McAAFType AxisFeatures;
} McCfgAcpAxType;

typedef struct McCfgAcpAxRefType
{	struct McCfgReferenceType AxisReference;
} McCfgAcpAxRefType;

typedef struct McCfgAcpMechElmType
{	struct McAMEType MechanicalElements;
} McCfgAcpMechElmType;

typedef struct McCfgAcpEncLinkType
{	struct McAELType EncoderLink;
} McCfgAcpEncLinkType;

typedef struct McCfgAcpHomeType
{	struct McAHType Homing;
} McCfgAcpHomeType;

typedef struct McCfgAcpStopReacType
{	struct McASRType StopReaction;
} McCfgAcpStopReacType;

typedef struct McCfgAcpMoveErrLimType
{	struct McAMELType MovementErrorLimits;
} McCfgAcpMoveErrLimType;

typedef struct McCfgAcpJerkFltrType
{	struct McAJFType JerkFilter;
} McCfgAcpJerkFltrType;

typedef struct McCfgAcpDigInType
{	struct McADIType DigitalInputs;
} McCfgAcpDigInType;

typedef struct McCfgAcpSimType
{	struct McASType Simulation;
} McCfgAcpSimType;

typedef struct McCfgAcpAxFeatType
{	struct McAAFType AxisFeatures;
} McCfgAcpAxFeatType;

typedef struct McAPSMOutParACOPOStrakType
{	float Voltage;
	float CurrentLimit;
	unsigned char CurrentLimitTime;
} McAPSMOutParACOPOStrakType;

typedef struct McAPSMOutParUsrDefCurLimUseType
{	float CurrentLimit;
	unsigned char CurrentLimitTime;
} McAPSMOutParUsrDefCurLimUseType;

typedef struct McAPSMOutParUsrDefCurLimType
{	enum McAPSMOutParUsrDefCurLimEnum Type;
	struct McAPSMOutParUsrDefCurLimUseType Used;
} McAPSMOutParUsrDefCurLimType;

typedef struct McAPSMOutParUsrDefType
{	float Voltage;
	struct McAPSMOutParUsrDefCurLimType CurrentLimitation;
} McAPSMOutParUsrDefType;

typedef struct McAPSMOutParType
{	enum McAPSMOutParEnum Type;
	struct McAPSMOutParACOPOStrakType ACOPOStrak;
	struct McAPSMOutParUsrDefType UserDefined;
} McAPSMOutParType;

typedef struct McAPSMOutVOnType
{	enum McAPSMOutVOnEnum Type;
} McAPSMOutVOnType;

typedef struct McCfgAcpAuxPwrSupModType
{	plcstring AxisReference[251];
	struct McAPSMOutParType OutputParameters;
	struct McAPSMOutVOnType OutputVoltageOn;
} McCfgAcpAuxPwrSupModType;

typedef struct McAPSMPSPwrSecType
{	plcstring AxisReference[251];
} McAPSMPSPwrSecType;

typedef struct McCfgAcpPSMPwrSecType
{	struct McAPSMPSPwrSecType PowerSection;
} McCfgAcpPSMPwrSecType;

typedef struct McAPSPwrSupACSngPhOpUseType
{	float SupplyVoltage;
} McAPSPwrSupACSngPhOpUseType;

typedef struct McAPSPwrSupACSngPhOpType
{	enum McAPSPwrSupACSngPhOpEnum Type;
	struct McAPSPwrSupACSngPhOpUseType Used;
} McAPSPwrSupACSngPhOpType;

typedef struct McAPSPwrSupACType
{	struct McAPSPwrSupACSngPhOpType SinglePhaseOperation;
} McAPSPwrSupACType;

typedef struct McAPSPwrSupDCPwrSupModRefType
{	plcstring PowerSupplyModuleReference[251];
} McAPSPwrSupDCPwrSupModRefType;

typedef struct McAPSPwrSupDCBusVType
{	unsigned short BusVoltage;
} McAPSPwrSupDCBusVType;

typedef struct McAPSPwrSupType
{	enum McAPSPwrSupEnum Type;
	struct McAPSPwrSupACType AC;
	struct McAPSPwrSupDCPwrSupModRefType DCPowerSupplyModuleReference;
	struct McAPSPwrSupDCBusVType DCBusVoltage;
} McAPSPwrSupType;

typedef struct McCfgAcpPwrSupType
{	struct McAPSPwrSupType PowerSupply;
} McCfgAcpPwrSupType;

typedef struct McAEX6ASSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX6ASSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX6ASSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX6ASSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX6ASSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX6ASSSIFrmCfgType;

typedef struct McAEX6ASType
{	struct McAEX6ASSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX6ASType;

typedef struct McAEX6ASinType
{	unsigned long LinesPerEncoderRevolution;
} McAEX6ASinType;

typedef struct McAEX6AIType
{	unsigned long LinesPerEncoderRevolution;
	enum McAEX6AIMaxExpectedOutFreqEnum MaxExpectedOutputFrequency;
	unsigned short IgnoreCheck;
} McAEX6AIType;

typedef struct McAEX6ALinMotType
{	unsigned long IncrementsPerEncoderRevolution;
} McAEX6ALinMotType;

typedef struct McAEX6AResType
{	unsigned char PolepairsPerEncoderRevolution;
} McAEX6AResType;

typedef struct McAEEncX6AIfTypType
{	enum McAEEncX6AIfTypEnum Type;
	struct McAEX6ASType SSI;
	struct McAEX6ASinType Sine;
	struct McAEX6AIType Incremental;
	struct McAEX6ALinMotType LinMot;
	struct McAEX6AResType Resolver;
} McAEEncX6AIfTypType;

typedef struct McAEEncX6AType
{	struct McAEEncX6AIfTypType InterfaceType;
} McAEEncX6AType;

typedef struct McAEX6BSSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX6BSSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX6BSSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX6BSSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX6BSSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX6BSSSIFrmCfgType;

typedef struct McAEX6BSType
{	struct McAEX6BSSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX6BSType;

typedef struct McAEX6BSinType
{	unsigned long LinesPerEncoderRevolution;
} McAEX6BSinType;

typedef struct McAEX6BIType
{	unsigned long LinesPerEncoderRevolution;
	enum McAEX6BIMaxExpectedOutFreqEnum MaxExpectedOutputFrequency;
	unsigned short IgnoreCheck;
} McAEX6BIType;

typedef struct McAEX6BLinMotType
{	unsigned long IncrementsPerEncoderRevolution;
} McAEX6BLinMotType;

typedef struct McAEX6BResType
{	unsigned char PolepairsPerEncoderRevolution;
} McAEX6BResType;

typedef struct McAEEncX6BIfTypType
{	enum McAEEncX6BIfTypEnum Type;
	struct McAEX6BSType SSI;
	struct McAEX6BSinType Sine;
	struct McAEX6BIType Incremental;
	struct McAEX6BLinMotType LinMot;
	struct McAEX6BResType Resolver;
} McAEEncX6BIfTypType;

typedef struct McAEEncX6BType
{	struct McAEEncX6BIfTypType InterfaceType;
} McAEEncX6BType;

typedef struct McAEX41BBiSSFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX41BBiSSFrmCfgStatBit1Enum StatusBit1;
	enum McAEX41BBiSSFrmCfgStatBit2Enum StatusBit2;
} McAEX41BBiSSFrmCfgType;

typedef struct McAEX41BType
{	enum McAEX41BPwrSupEnum PowerSupply;
	struct McAEX41BBiSSFrmCfgType BiSSFrameConfiguration;
	unsigned long CRCPolynomial;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX41BType;

typedef struct McAEX41SSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX41SSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX41SSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX41SSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX41SSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX41SSSIFrmCfgType;

typedef struct McAEX41SType
{	enum McAEX41SPwrSupEnum PowerSupply;
	struct McAEX41SSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX41SType;

typedef struct McAEEncX41IfTypType
{	enum McAEEncX41IfTypEnum Type;
	struct McAEX41BType BiSS;
	struct McAEX41SType SSI;
} McAEEncX41IfTypType;

typedef struct McAEEncX41Type
{	struct McAEEncX41IfTypType InterfaceType;
} McAEEncX41Type;

typedef struct McAEX42BBiSSFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX42BBiSSFrmCfgStatBit1Enum StatusBit1;
	enum McAEX42BBiSSFrmCfgStatBit2Enum StatusBit2;
} McAEX42BBiSSFrmCfgType;

typedef struct McAEX42BType
{	enum McAEX42BPwrSupEnum PowerSupply;
	struct McAEX42BBiSSFrmCfgType BiSSFrameConfiguration;
	unsigned long CRCPolynomial;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX42BType;

typedef struct McAEX42SSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX42SSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX42SSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX42SSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX42SSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX42SSSIFrmCfgType;

typedef struct McAEX42SType
{	enum McAEX42SPwrSupEnum PowerSupply;
	struct McAEX42SSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX42SType;

typedef struct McAEEncX42IfTypType
{	enum McAEEncX42IfTypEnum Type;
	struct McAEX42BType BiSS;
	struct McAEX42SType SSI;
} McAEEncX42IfTypType;

typedef struct McAEEncX42Type
{	struct McAEEncX42IfTypType InterfaceType;
} McAEEncX42Type;

typedef struct McAEX43BBiSSFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX43BBiSSFrmCfgStatBit1Enum StatusBit1;
	enum McAEX43BBiSSFrmCfgStatBit2Enum StatusBit2;
} McAEX43BBiSSFrmCfgType;

typedef struct McAEX43BType
{	enum McAEX43BPwrSupEnum PowerSupply;
	struct McAEX43BBiSSFrmCfgType BiSSFrameConfiguration;
	unsigned long CRCPolynomial;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX43BType;

typedef struct McAEX43SSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX43SSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX43SSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX43SSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX43SSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX43SSSIFrmCfgType;

typedef struct McAEX43SType
{	enum McAEX43SPwrSupEnum PowerSupply;
	struct McAEX43SSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX43SType;

typedef struct McAEEncX43IfTypType
{	enum McAEEncX43IfTypEnum Type;
	struct McAEX43BType BiSS;
	struct McAEX43SType SSI;
} McAEEncX43IfTypType;

typedef struct McAEEncX43Type
{	struct McAEEncX43IfTypType InterfaceType;
} McAEEncX43Type;

typedef struct McAEX11ASSSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX11ASSSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX11ASSSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX11ASSSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX11ASSSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX11ASSSSIFrmCfgType;

typedef struct McAEX11ASSType
{	struct McAEX11ASSSSIFrmCfgType SSIFrameConfiguration;
	unsigned long LinesPerEncoderRevolution;
	signed long PositionValuesEncoderRevolution;
	signed long SerialPositionPhaseShift;
	signed long BaudRate;
} McAEX11ASSType;

typedef struct McAEX11ASSSIFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX11ASSSIFrmCfgStatBit1Enum StatusBit1;
	enum McAEX11ASSSIFrmCfgStatBit2Enum StatusBit2;
	enum McAEX11ASSSIFrmCfgSSIDatCEnum SSIDataCode;
	enum McAEX11ASSSIFrmCfgSSIParCkEnum SSIParityCheck;
} McAEX11ASSSIFrmCfgType;

typedef struct McAEX11ASType
{	struct McAEX11ASSSIFrmCfgType SSIFrameConfiguration;
	unsigned long IncrementsPerEncoderRevolution;
	signed long BaudRate;
} McAEX11ASType;

typedef struct McAEX11ABBiSSFrmCfgType
{	unsigned char NumberOfLeadingZeros;
	unsigned char NumberOfPositionBits;
	unsigned char NumberOfTrailingZeros;
	enum McAEX11ABBiSSFrmCfgStatBit1Enum StatusBit1;
	enum McAEX11ABBiSSFrmCfgStatBit2Enum StatusBit2;
} McAEX11ABBiSSFrmCfgType;

typedef struct McAEX11ABType
{	struct McAEX11ABBiSSFrmCfgType BiSSFrameConfiguration;
	unsigned long CRCPolynomial;
	unsigned long IncrementsPerEncoderRevolution;
} McAEX11ABType;

typedef struct McAEX11ASinType
{	unsigned long LinesPerEncoderRevolution;
} McAEX11ASinType;

typedef struct McAEX11ASinWDCMType
{	unsigned long LinesPerEncoderRevolution;
	unsigned long DCMBasicDistance;
	signed long DCMBasicDifference;
} McAEX11ASinWDCMType;

typedef struct McAEEncX11AIfTypType
{	enum McAEEncX11AIfTypEnum Type;
	struct McAEX11ASSType SSISine;
	struct McAEX11ASType SSI;
	struct McAEX11ABType BiSS;
	struct McAEX11ASinType Sine;
	struct McAEX11ASinWDCMType SineWithDCM;
} McAEEncX11AIfTypType;

typedef struct McAEEncX11AType
{	struct McAEEncX11AIfTypType InterfaceType;
} McAEEncX11AType;

typedef struct McAEEncIfTypType
{	enum McAEEncIfTypEnum Type;
} McAEEncIfTypType;

typedef struct McAEEncType
{	struct McAEEncIfTypType InterfaceType;
} McAEEncType;

typedef struct McCfgAcpEncType
{	struct McAEEncX6AType EncoderX6A;
	struct McAEEncX6BType EncoderX6B;
	struct McAEEncX41Type EncoderX41;
	struct McAEEncX42Type EncoderX42;
	struct McAEEncX43Type EncoderX43;
	struct McAEEncX11AType EncoderX11A;
	struct McAEEncType Encoder;
} McCfgAcpEncType;

typedef struct McAVAVirtAxUseHomeModDirType
{	double Position;
} McAVAVirtAxUseHomeModDirType;

typedef struct McAVAVirtAxUseHomeModType
{	enum McAVAVirtAxUseHomeModEnum Type;
	struct McAVAVirtAxUseHomeModDirType Direct;
} McAVAVirtAxUseHomeModType;

typedef struct McAVAVirtAxUseHomeType
{	struct McAVAVirtAxUseHomeModType Mode;
	plcstring RestorePositionVariable[251];
} McAVAVirtAxUseHomeType;

typedef struct McAVAVirtAxUseType
{	struct McCfgReferenceType AxisReference;
	struct McAVAVirtAxUseHomeType Homing;
	struct McAJFType JerkFilter;
	struct McAAFType AxisFeatures;
} McAVAVirtAxUseType;

typedef struct McAVAVirtAxType
{	enum McAVAVirtAxEnum Type;
	struct McAVAVirtAxUseType Used;
} McAVAVirtAxType;

typedef struct McCfgAcpVirtAxType
{	struct McAVAVirtAxType VirtualAxis;
} McCfgAcpVirtAxType;

typedef struct McCfgAcpVirtAxRefType
{	struct McCfgReferenceType AxisReference;
} McCfgAcpVirtAxRefType;

typedef struct McAVHHomeModDirType
{	double Position;
} McAVHHomeModDirType;

typedef struct McAVHHomeModType
{	enum McAVHHomeModEnum Type;
	struct McAVHHomeModDirType Direct;
} McAVHHomeModType;

typedef struct McAVHHomeType
{	struct McAVHHomeModType Mode;
	plcstring RestorePositionVariable[251];
} McAVHHomeType;

typedef struct McCfgAcpVirtHomeType
{	struct McAVHHomeType Homing;
} McCfgAcpVirtHomeType;

typedef struct McCfgAcpVirtJerkFltrType
{	struct McAJFType JerkFilter;
} McCfgAcpVirtJerkFltrType;

typedef struct McCfgAcpVirtAxFeatType
{	struct McAAFType AxisFeatures;
} McCfgAcpVirtAxFeatType;

typedef struct McACFChFeatType
{	struct McCfgUnboundedArrayType FeatureReference;
} McACFChFeatType;

typedef struct McCfgAcpChFeatType
{	struct McACFChFeatType ChannelFeatures;
} McCfgAcpChFeatType;

typedef struct McAEEAUseEncLinkOneEncPosEncType
{	enum McAEEAUseEncLinkOneEncPosEncEnum Type;
} McAEEAUseEncLinkOneEncPosEncType;

typedef struct McAEEAUELOEPosFltrExtpolDistType
{	float PositionFilterTimeConstant;
	float ExtrapolationTime;
} McAEEAUELOEPosFltrExtpolDistType;

typedef struct McAEEAUELOneEncPosFltrType
{	enum McAEEAUELOneEncPosFltrEnum Type;
	struct McAEEAUELOEPosFltrExtpolDistType ExtrapolationAndDisturbance;
} McAEEAUELOneEncPosFltrType;

typedef struct McAEEAUseEncLinkOneEncType
{	struct McAEEAUseEncLinkOneEncPosEncType PositionEncoder;
	struct McAEEAUELOneEncPosFltrType PositionFilter;
} McAEEAUseEncLinkOneEncType;

typedef struct McAEEAUseEncLinkType
{	enum McAEEAUseEncLinkEnum Type;
	struct McAEEAUseEncLinkOneEncType OneEncoder;
} McAEEAUseEncLinkType;

typedef struct McAEEAHModDirRefPType
{	enum McAEEAHModDirRefPEnum Type;
} McAEEAHModDirRefPType;

typedef struct McAEEAHModDirType
{	double Position;
	struct McAEEAHModDirRefPType ReferencePulse;
} McAEEAHModDirType;

typedef struct McAEEAHModAbsType
{	double Position;
} McAEEAHModAbsType;

typedef struct McAEEAHModType
{	enum McAEEAHModEnum Type;
	struct McAEEAHModDirType Direct;
	struct McAEEAHModAbsType Absolute;
} McAEEAHModType;

typedef struct McAEEAHType
{	struct McAEEAHModType Mode;
	plcstring RestorePositionVariable[251];
} McAEEAHType;

typedef struct McAEEAExtEncAxUseType
{	struct McCfgReferenceType AxisReference;
	struct McAEEAUseEncLinkType EncoderLink;
	struct McAMEType MechanicalElements;
	struct McAEEAHType Homing;
} McAEEAExtEncAxUseType;

typedef struct McAEEAExtEncAxType
{	enum McAEEAExtEncAxEnum Type;
	struct McAEEAExtEncAxUseType Used;
} McAEEAExtEncAxType;

typedef struct McCfgAcpExtEncAxType
{	struct McAEEAExtEncAxType ExternalEncoderAxis;
} McCfgAcpExtEncAxType;

typedef struct McCfgAcpExtEncAxRefType
{	struct McCfgReferenceType AxisReference;
} McCfgAcpExtEncAxRefType;

typedef struct McCfgAcpExtEncAxEncLinkType
{	struct McAEEAUseEncLinkType EncoderLink;
} McCfgAcpExtEncAxEncLinkType;

typedef struct McCfgAcpExtEncAxMechElmType
{	struct McAMEType MechanicalElements;
} McCfgAcpExtEncAxMechElmType;

typedef struct McCfgAcpExtEncAxHomeType
{	struct McAEEAHType Homing;
} McCfgAcpExtEncAxHomeType;

typedef struct McCfgAxFeatAcpParTblType
{	plcstring ACOPOSParameterTableReference[251];
} McCfgAxFeatAcpParTblType;

typedef struct MC_BR_AutoTuneFeedForward_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxAutoTuneFeedFwdType Parameters;
	struct McAcpAxAdvAutoTuneFeedFwdType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneFeedFwdOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneFeedForward_AcpAx_typ;

typedef struct MC_BR_InitHome_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxHomingParType HomingParameters;
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
} MC_BR_InitHome_AcpAx_typ;

typedef struct MC_BR_ProcessParID_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned long DataAddress;
	unsigned long NumberOfParIDs;
	enum McAcpAxProcessParIDModeEnum Mode;
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
} MC_BR_ProcessParID_AcpAx_typ;

typedef struct MC_BR_ProcessParTab_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxProcessParTabDataType Data;
	enum McAcpAxProcessParTabModeEnum Mode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxProcessParTabAddInfoType AdditionalInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ProcessParTab_AcpAx_typ;

typedef struct MC_BR_CyclicProcessParID_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned long DataAddress;
	unsigned long NumberOfParIDs;
	enum McAcpAxCycParIDModeEnum Mode;
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
} MC_BR_CyclicProcessParID_AcpAx_typ;

typedef struct MC_BR_MoveAbsoluteTrgStop_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
	float Velocity;
	float Acceleration;
	float Deceleration;
	enum McDirectionEnum Direction;
	enum McBufferModeEnum BufferMode;
	struct McAcpAxTriggerStopType TriggerStopParameters;
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
	plcbit StoppedAtTargetPosition;
} MC_BR_MoveAbsoluteTrgStop_AcpAx_typ;

typedef struct MC_BR_MoveAdditiveTrgStop_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Distance;
	float Velocity;
	float Acceleration;
	float Deceleration;
	enum McBufferModeEnum BufferMode;
	struct McAcpAxTriggerStopType TriggerStopParameters;
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
	plcbit StoppedAtTargetPosition;
} MC_BR_MoveAdditiveTrgStop_AcpAx_typ;

typedef struct MC_BR_MoveVelocityTrgStop_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	enum McDirectionEnum Direction;
	enum McBufferModeEnum BufferMode;
	struct McAcpAxTriggerStopType TriggerStopParameters;
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
	plcbit InVelocity;
} MC_BR_MoveVelocityTrgStop_AcpAx_typ;

typedef struct MC_BR_LimitLoad_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float LoadPosAccel;
	float LoadPosDecel;
	float LoadNegAccel;
	float LoadNegDecel;
	enum McAcpAxLimitLoadModeEnum Mode;
	struct McAcpAxAdvLimitLoadParType AdvancedParameters;
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
} MC_BR_LimitLoad_AcpAx_typ;

typedef struct MC_BR_BrakeSetPar_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxBrakeParType Parameters;
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
} MC_BR_BrakeSetPar_AcpAx_typ;

typedef struct MC_BR_BrakeTest_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpAxBrakeTestCmdEnum Command;
	struct McAcpAxBrakeTestParType Parameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double PositionError;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_BrakeTest_AcpAx_typ;

typedef struct MC_BR_LoadSimulationSetPar_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxSimulationParType Parameters;
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
} MC_BR_LoadSimulationSetPar_AcpAx_typ;

typedef struct MC_BR_LoadSimulationGetPar_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxSimulationParType Parameters;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_LoadSimulationGetPar_AcpAx_typ;

typedef struct MC_BR_GetDriveInfo_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAxisInfoType AxisInfo;
	struct McAcpAxModuleInfoType ModuleInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_GetDriveInfo_AcpAx_typ;

typedef struct MC_BR_AutoTuneSpeedCtrl_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxAutoTuneParType Parameters;
	struct McAcpAxAdvAutoTuneSpeedCtrlType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneSpeedCtrlOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneSpeedCtrl_AcpAx_typ;

typedef struct MC_BR_AutoTuneLoopFilters_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxAutoTuneLoopFiltersType LoopFilters;
	struct McAcpAxAutoTuneParType Parameters;
	struct McAcpAxAdvAutoTuneLoopFilterType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneLoopFilterOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneLoopFilters_AcpAx_typ;

typedef struct MC_BR_AutoTunePositionCtrl_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxAutoTuneParType Parameters;
	struct McAcpAxAdvAutoTunePosCtrlType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTunePosCtrlOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTunePositionCtrl_AcpAx_typ;

typedef struct MC_BR_AutoTuneTest_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpAxAutoTuneTestModeEnum Mode;
	struct McAcpAxAutoTuneParType Parameters;
	struct McAcpAxAdvAutoTuneTestType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneTestOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneTest_AcpAx_typ;

typedef struct MC_BR_AutoTuneInductMotor_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpAxAutoTuneMotorModeEnum Mode;
	struct McAcpAxAutoTuneIndMotParType Parameters;
	struct McAcpAxAdvAutoTuneIndMotType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneIndMotOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneInductMotor_AcpAx_typ;

typedef struct MC_BR_AutoTuneSyncMotor_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpAxAutoTuneMotorModeEnum Mode;
	struct McAcpAxAutoTuneSyncMotParType Parameters;
	struct McAcpAxAdvAutoTuneSyncMotType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneSyncMotOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneSyncMotor_AcpAx_typ;

typedef struct MC_BR_AutoTuneMotorPhasing_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpAxAutoTuneMotPhasModeEnum Mode;
	struct McAcpAxAutoTuneMotPhasParType Parameters;
	struct McAcpAxAdvAutoTuneMotPhasType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneMotPhasOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneMotorPhasing_AcpAx_typ;

typedef struct MC_BR_AutoTuneLoadModel_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpAxAutoTuneParType Parameters;
	struct McAcpAxAdvAutoTuneLoadModelType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxAutoTuneLoadModelOutType Output;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AutoTuneLoadModel_AcpAx_typ;

typedef struct MC_BR_CamAutomatSetPar_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutSetParCmdEnum Command;
	struct McAcpAxCamAutDefineType CamAutomat;
	struct McAcpAxAdvCamAutSetParType AdvancedParameters;
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
} MC_BR_CamAutomatSetPar_AcpAx_typ;

typedef struct MC_BR_CamAutomatGetPar_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	enum McCamAutGetParCmdEnum Command;
	struct McAcpAxCamAutDefineType CamAutomat;
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
} MC_BR_CamAutomatGetPar_AcpAx_typ;

typedef struct MC_BR_PhasingVelocity_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Acceleration;
	struct McAcpAxAdvPhasingParType AdvancedParameters;
	float CyclicVelocity;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double ActualPhaseShift;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit VelocityAttained;
} MC_BR_PhasingVelocity_AcpAx_typ;

typedef struct MC_BR_OffsetVelocity_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Slave;
	float Acceleration;
	struct McAcpAxAdvPhasingParType AdvancedParameters;
	float CyclicVelocity;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	double ActualOffsetShift;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit VelocityAttained;
} MC_BR_OffsetVelocity_AcpAx_typ;

typedef struct MC_BR_WrLoadSimTorque_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Torque;
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
} MC_BR_WrLoadSimTorque_AcpAx_typ;

typedef struct MC_BR_RdLoadSimTorque_AcpAx
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
} MC_BR_RdLoadSimTorque_AcpAx_typ;

typedef struct MC_BR_WrLoadSimPosition_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
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
} MC_BR_WrLoadSimPosition_AcpAx_typ;

typedef struct MC_BR_WrLoadSimTwoEncPos_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double MotorPosition;
	double LoadPosition;
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
} MC_BR_WrLoadSimTwoEncPos_AcpAx_typ;

typedef struct MC_BR_RdLoadSimInputData_AcpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpAxLoadSimInputDataType LoadSimInputData;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_RdLoadSimInputData_AcpAx_typ;

typedef struct MC_BR_ApsmPowerOn_AcpAx
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
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_ApsmPowerOn_AcpAx_typ;

typedef struct MC_BR_ApsmPowerOff_AcpAx
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
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_ApsmPowerOff_AcpAx_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MC_BR_AutoTuneFeedForward_AcpAx(struct MC_BR_AutoTuneFeedForward_AcpAx* inst);
_BUR_PUBLIC void MC_BR_InitHome_AcpAx(struct MC_BR_InitHome_AcpAx* inst);
_BUR_PUBLIC void MC_BR_ProcessParID_AcpAx(struct MC_BR_ProcessParID_AcpAx* inst);
_BUR_PUBLIC void MC_BR_ProcessParTab_AcpAx(struct MC_BR_ProcessParTab_AcpAx* inst);
_BUR_PUBLIC void MC_BR_CyclicProcessParID_AcpAx(struct MC_BR_CyclicProcessParID_AcpAx* inst);
_BUR_PUBLIC void MC_BR_MoveAbsoluteTrgStop_AcpAx(struct MC_BR_MoveAbsoluteTrgStop_AcpAx* inst);
_BUR_PUBLIC void MC_BR_MoveAdditiveTrgStop_AcpAx(struct MC_BR_MoveAdditiveTrgStop_AcpAx* inst);
_BUR_PUBLIC void MC_BR_MoveVelocityTrgStop_AcpAx(struct MC_BR_MoveVelocityTrgStop_AcpAx* inst);
_BUR_PUBLIC void MC_BR_LimitLoad_AcpAx(struct MC_BR_LimitLoad_AcpAx* inst);
_BUR_PUBLIC void MC_BR_BrakeSetPar_AcpAx(struct MC_BR_BrakeSetPar_AcpAx* inst);
_BUR_PUBLIC void MC_BR_BrakeTest_AcpAx(struct MC_BR_BrakeTest_AcpAx* inst);
_BUR_PUBLIC void MC_BR_LoadSimulationSetPar_AcpAx(struct MC_BR_LoadSimulationSetPar_AcpAx* inst);
_BUR_PUBLIC void MC_BR_LoadSimulationGetPar_AcpAx(struct MC_BR_LoadSimulationGetPar_AcpAx* inst);
_BUR_PUBLIC void MC_BR_GetDriveInfo_AcpAx(struct MC_BR_GetDriveInfo_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneSpeedCtrl_AcpAx(struct MC_BR_AutoTuneSpeedCtrl_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneLoopFilters_AcpAx(struct MC_BR_AutoTuneLoopFilters_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTunePositionCtrl_AcpAx(struct MC_BR_AutoTunePositionCtrl_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneTest_AcpAx(struct MC_BR_AutoTuneTest_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneInductMotor_AcpAx(struct MC_BR_AutoTuneInductMotor_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneSyncMotor_AcpAx(struct MC_BR_AutoTuneSyncMotor_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneMotorPhasing_AcpAx(struct MC_BR_AutoTuneMotorPhasing_AcpAx* inst);
_BUR_PUBLIC void MC_BR_AutoTuneLoadModel_AcpAx(struct MC_BR_AutoTuneLoadModel_AcpAx* inst);
_BUR_PUBLIC void MC_BR_CamAutomatSetPar_AcpAx(struct MC_BR_CamAutomatSetPar_AcpAx* inst);
_BUR_PUBLIC void MC_BR_CamAutomatGetPar_AcpAx(struct MC_BR_CamAutomatGetPar_AcpAx* inst);
_BUR_PUBLIC void MC_BR_PhasingVelocity_AcpAx(struct MC_BR_PhasingVelocity_AcpAx* inst);
_BUR_PUBLIC void MC_BR_OffsetVelocity_AcpAx(struct MC_BR_OffsetVelocity_AcpAx* inst);
_BUR_PUBLIC void MC_BR_WrLoadSimTorque_AcpAx(struct MC_BR_WrLoadSimTorque_AcpAx* inst);
_BUR_PUBLIC void MC_BR_RdLoadSimTorque_AcpAx(struct MC_BR_RdLoadSimTorque_AcpAx* inst);
_BUR_PUBLIC void MC_BR_WrLoadSimPosition_AcpAx(struct MC_BR_WrLoadSimPosition_AcpAx* inst);
_BUR_PUBLIC void MC_BR_WrLoadSimTwoEncPos_AcpAx(struct MC_BR_WrLoadSimTwoEncPos_AcpAx* inst);
_BUR_PUBLIC void MC_BR_RdLoadSimInputData_AcpAx(struct MC_BR_RdLoadSimInputData_AcpAx* inst);
_BUR_PUBLIC void MC_BR_ApsmPowerOn_AcpAx(struct MC_BR_ApsmPowerOn_AcpAx* inst);
_BUR_PUBLIC void MC_BR_ApsmPowerOff_AcpAx(struct MC_BR_ApsmPowerOff_AcpAx* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MCACPAX_ */

