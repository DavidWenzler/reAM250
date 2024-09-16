/* Automation Studio generated header file */
/* Do not edit ! */
/* McStpAx 5.16.2 */

#ifndef _MCSTPAX_
#define _MCSTPAX_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _McStpAx_VERSION
#define _McStpAx_VERSION 5.16.2
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
typedef enum McSAELEnum
{	mcSAEL_NO_ENC = 0,
	mcSAEL_ONE_ENC = 1
} McSAELEnum;

typedef enum McSAELOEPosEncEnum
{	mcSAELOEPE_STEP_CNT = 0,
	mcSAELOEPE_ENC = 1,
	mcSAELOEPE_ENC_X6 = 2,
	mcSAELOEPE_ENC_X6A = 3,
	mcSAELOEPE_ENC_X6B = 4,
	mcSAELOEPE_ENC_X3 = 5,
	mcSAELOEPE_ENC_X4 = 6,
	mcSAELOEPE_EXT = 10
} McSAELOEPosEncEnum;

typedef enum McSAELOEPosEncStepCntRefPSrcEnum
{	mcSAELOEPESCRPS_DIG_IN_1 = 0,
	mcSAELOEPESCRPS_DIG_IN_2 = 1,
	mcSAELOEPESCRPS_DIG_IN_3 = 2,
	mcSAELOEPESCRPS_DIG_IN_5 = 3,
	mcSAELOEPESCRPS_DIG_IN_6 = 4,
	mcSAELOEPESCRPS_R_IN_OF_X6A = 5,
	mcSAELOEPESCRPS_R_IN_OF_X6B = 6
} McSAELOEPosEncStepCntRefPSrcEnum;

typedef enum McSAELOEPosEncStepCntRefPEdgEnum
{	mcSAELOEPESCRPE_POS_EDG = 0,
	mcSAELOEPESCRPE_NEG_EDG = 1
} McSAELOEPosEncStepCntRefPEdgEnum;

typedef enum McSAELOEExtPosTypEnum
{	mcSAELOEEPT_ABS = 0,
	mcSAELOEEPT_INCR = 1
} McSAELOEExtPosTypEnum;

typedef enum McSAELOEExtPosSrcEnum
{	mcSAELOEEPS_IO_CH_DINT = 0,
	mcSAELOEEPS_IO_CH_UDINT = 1,
	mcSAELOEEPS_IO_CH_INT = 2,
	mcSAELOEEPS_IO_CH_UINT = 3,
	mcSAELOEEPS_VAR_DINT = 4,
	mcSAELOEEPS_VAR_UDINT = 5,
	mcSAELOEEPS_VAR_INT = 6,
	mcSAELOEEPS_VAR_UINT = 7
} McSAELOEExtPosSrcEnum;

typedef enum McSAELOEExtValCkModOkEnum
{	mcSAELOEEVCMO_POS_SRC_DEV = 0,
	mcSAELOEEVCMO_IO_CH = 1,
	mcSAELOEEVCMO_VAR = 2,
	mcSAELOEEVCMO_NOT_USE = 3
} McSAELOEExtValCkModOkEnum;

typedef enum McSAELOEExtValCkStDatEnum
{	mcSAELOEEVCSD_POS_SRC_DEV = 0,
	mcSAELOEEVCSD_IO_CH = 1,
	mcSAELOEEVCSD_VAR = 2,
	mcSAELOEEVCSD_NOT_USE = 3
} McSAELOEExtValCkStDatEnum;

typedef enum McSAELOEExtValCkNetTimeEnum
{	mcSAELOEEVCNT_NOT_USE = 0,
	mcSAELOEEVCNT_IO_CH = 1,
	mcSAELOEEVCNT_VAR = 2
} McSAELOEExtValCkNetTimeEnum;

typedef enum McSAELOEExtValCkEncOkEnum
{	mcSAELOEEVCEO_NOT_USE = 0,
	mcSAELOEEVCEO_IO_CH = 1,
	mcSAELOEEVCEO_VAR = 2
} McSAELOEExtValCkEncOkEnum;

typedef enum McSAELOEExtRefPEnum
{	mcSAELOEERP_NOT_USE = 0,
	mcSAELOEERP_IO_CH = 1,
	mcSAELOEERP_VAR = 2
} McSAELOEExtRefPEnum;

typedef enum McSAELOEEPosFltrEnum
{	mcSAELOEEPF_EXTPOL_AND_DIST = 0
} McSAELOEEPosFltrEnum;

typedef enum McSACModEnum
{	mcSACM_CUR_CTRL = 0,
	mcSACM_POS_AND_CUR_CTRL = 1
} McSACModEnum;

typedef enum McSACCurEnum
{	mcSACC_STD = 0,
	mcSACC_SMART_CUR_CTRL = 1
} McSACCurEnum;

typedef enum McSACCSCCSCCActEnum
{	mcSACCSCCSCCA_CONST_SPD = 0,
	mcSACCSCCSCCA_PERM = 1
} McSACCSCCSCCActEnum;

typedef enum McSACCSCCSCCCurRedEnum
{	mcSACCSCCSCCCR_RED_50 = 0,
	mcSACCSCCSCCCR_RED_25 = 1
} McSACCSCCSCCCurRedEnum;

typedef enum McSACCSCCSCCRedActLvlEnum
{	mcSACCSCCSCCRAL_GT_992 = 0,
	mcSACCSCCSCCRAL_GT_960 = 1,
	mcSACCSCCSCCRAL_GT_928 = 2,
	mcSACCSCCSCCRAL_GT_896 = 3,
	mcSACCSCCSCCRAL_GT_864 = 4,
	mcSACCSCCSCCRAL_GT_832 = 5,
	mcSACCSCCSCCRAL_GT_800 = 6,
	mcSACCSCCSCCRAL_GT_768 = 7,
	mcSACCSCCSCCRAL_GT_736 = 8,
	mcSACCSCCSCCRAL_GT_704 = 9,
	mcSACCSCCSCCRAL_GT_672 = 10,
	mcSACCSCCSCCRAL_GT_640 = 11,
	mcSACCSCCSCCRAL_GT_608 = 12,
	mcSACCSCCSCCRAL_GT_576 = 13,
	mcSACCSCCSCCRAL_GT_544 = 14,
	mcSACCSCCSCCRAL_GT_512 = 15,
	mcSACCSCCSCCRAL_GT_480 = 16,
	mcSACCSCCSCCRAL_GT_448 = 17,
	mcSACCSCCSCCRAL_GT_416 = 18,
	mcSACCSCCSCCRAL_GT_384 = 19,
	mcSACCSCCSCCRAL_GT_352 = 20,
	mcSACCSCCSCCRAL_GT_320 = 21,
	mcSACCSCCSCCRAL_GT_288 = 22,
	mcSACCSCCSCCRAL_GT_256 = 23,
	mcSACCSCCSCCRAL_GT_224 = 24,
	mcSACCSCCSCCRAL_GT_192 = 25,
	mcSACCSCCSCCRAL_GT_160 = 26,
	mcSACCSCCSCCRAL_GT_128 = 27,
	mcSACCSCCSCCRAL_GT_96 = 28,
	mcSACCSCCSCCRAL_GT_64 = 29
} McSACCSCCSCCRedActLvlEnum;

typedef enum McSACCSCCSCCRedActDlyEnum
{	mcSACCSCCSCCRAD_VAL_8 = 0,
	mcSACCSCCSCCRAD_VAL_1 = 1,
	mcSACCSCCSCCRAD_VAL_2 = 2,
	mcSACCSCCSCCRAD_VAL_32 = 3
} McSACCSCCSCCRedActDlyEnum;

typedef enum McSACCSCCSCCRedRstLvlEnum
{	mcSACCSCCSCCRRL_LT_32 = 0,
	mcSACCSCCSCCRRL_LT_64 = 1,
	mcSACCSCCSCCRRL_LT_96 = 2,
	mcSACCSCCSCCRRL_LT_128 = 3,
	mcSACCSCCSCCRRL_LT_160 = 4,
	mcSACCSCCSCCRRL_LT_192 = 5,
	mcSACCSCCSCCRRL_LT_224 = 6,
	mcSACCSCCSCCRRL_LT_256 = 7,
	mcSACCSCCSCCRRL_LT_288 = 8,
	mcSACCSCCSCCRRL_LT_320 = 9,
	mcSACCSCCSCCRRL_LT_352 = 10,
	mcSACCSCCSCCRRL_LT_384 = 11,
	mcSACCSCCSCCRRL_LT_416 = 12,
	mcSACCSCCSCCRRL_LT_448 = 13,
	mcSACCSCCSCCRRL_LT_480 = 14
} McSACCSCCSCCRedRstLvlEnum;

typedef enum McSACCSCCSCCRedRstDlyEnum
{	mcSACCSCCSCCRRD_VAL_2 = 0,
	mcSACCSCCSCCRRD_VAL_1 = 1,
	mcSACCSCCSCCRRD_VAL_4 = 2,
	mcSACCSCCSCCRRD_VAL_8 = 3
} McSACCSCCSCCRedRstDlyEnum;

typedef enum McSAHModEnum
{	mcSAHM_DIR = 0,
	mcSAHM_ABS_SW = 1,
	mcSAHM_SW_GATE = 2,
	mcSAHM_LIM_SW = 3,
	mcSAHM_ABS = 4,
	mcSAHM_ABS_CORR = 5,
	mcSAHM_BLK_LAG_ERR = 9,
	mcSAHM_RES_POS = 10,
	mcSAHM_NOT_USE = 100
} McSAHModEnum;

typedef enum McSAHModDirRefPEnum
{	mcSAHMDRP_NOT_USE = 0,
	mcSAHMDRP_USE = 1
} McSAHModDirRefPEnum;

typedef enum McSAHModHomeDirEnum
{	mcSAHMHD_POS = 0,
	mcSAHMHD_NEG = 1
} McSAHModHomeDirEnum;

typedef enum McSAHModKeepDirEnum
{	mcSAHMKD_NO = 0,
	mcSAHMKD_YES = 1
} McSAHModKeepDirEnum;

typedef enum McSAHModSwEdgEnum
{	mcSAHMSE_POS = 0,
	mcSAHMSE_NEG = 1
} McSAHModSwEdgEnum;

typedef enum McSAHModRefPEnum
{	mcSAHMRP_NOT_USE = 0,
	mcSAHMRP_USE = 1
} McSAHModRefPEnum;

typedef enum McSAHModStartDirEnum
{	mcSAHMSD_POS = 0,
	mcSAHMSD_NEG = 1
} McSAHModStartDirEnum;

typedef enum McSASRDEEnum
{	mcSASRDE_DEC_LIM = 0,
	mcSASRDE_COAST_TO_STANDSTILL = 1
} McSASRDEEnum;

typedef enum McSAMELStallDetectCfgEnum
{	mcSAMELSDC_NOT_USE = 0,
	mcSAMELSDC_USE = 1
} McSAMELStallDetectCfgEnum;

typedef enum McSAMELStallDetectCfgUseReacEnum
{	mcSAMELSDCUR_ERRORSTOP = 0,
	mcSAMELSDCUR_WARNING = 1
} McSAMELStallDetectCfgUseReacEnum;

typedef enum McSAMELStallguardCfgEnum
{	mcSAMELSC_NOT_USE = 0,
	mcSAMELSC_USE = 1
} McSAMELStallguardCfgEnum;

typedef enum McSAMELStallguardCfgUseReacEnum
{	mcSAMELSCUR_ERRORSTOP = 0,
	mcSAMELSCUR_WARNING = 1
} McSAMELStallguardCfgUseReacEnum;

typedef enum McSAJFEnum
{	mcSAJF_NOT_USE = 0,
	mcSAJF_USE = 1,
	mcSAJF_JERK_LIM = 2
} McSAJFEnum;

typedef enum McSADIAllSrcEnum
{	mcSADIAS_NOT_USE = 0,
	mcSADIAS_VAR = 1,
	mcSADIAS_DIG_IN_TRG_1 = 2,
	mcSADIAS_DIG_IN_TRG_2 = 3,
	mcSADIAS_DIG_IN_1 = 4,
	mcSADIAS_DIG_IN_2 = 5,
	mcSADIAS_DIG_IN_3 = 6,
	mcSADIAS_DIG_IN_4 = 7,
	mcSADIAS_DIG_IN_5 = 8,
	mcSADIAS_DIG_IN_6 = 9,
	mcSADIAS_IO_CH = 10
} McSADIAllSrcEnum;

typedef enum McSADIAllSrcVarTSEnum
{	mcSADIAllSVTS_NOT_USE = 0,
	mcSADIAllSVTS_USE = 1,
	mcSADIAllSVTS_RIS_AND_FALL_EDG = 2
} McSADIAllSrcVarTSEnum;

typedef enum McSADIAllSrcIOChTSEnum
{	mcSADIAllSIOCTS_NOT_USE = 0,
	mcSADIAllSIOCTS_USE = 1,
	mcSADIAllSIOCTS_RIS_AND_FALL_EDG = 2
} McSADIAllSrcIOChTSEnum;

typedef enum McSADIHomeSwLvlEnum
{	mcSADIHSL_LOW = 0,
	mcSADIHSL_HIGH = 1
} McSADIHomeSwLvlEnum;

typedef enum McSADIPosLimSwLvlEnum
{	mcSADIPLSL_LOW = 0,
	mcSADIPLSL_HIGH = 1
} McSADIPosLimSwLvlEnum;

typedef enum McSADINegLimSwLvlEnum
{	mcSADINLSL_LOW = 0,
	mcSADINLSL_HIGH = 1
} McSADINegLimSwLvlEnum;

typedef enum McSADITrg1LvlEnum
{	mcSADIT1L_LOW = 0,
	mcSADIT1L_HIGH = 1
} McSADITrg1LvlEnum;

typedef enum McSADITrg2LvlEnum
{	mcSADIT2L_LOW = 0,
	mcSADIT2L_HIGH = 1
} McSADITrg2LvlEnum;

typedef enum McSADIQstopInEnum
{	mcSADIQI_NOT_USE = 0,
	mcSADIQI_TRG_1 = 1,
	mcSADIQI_TRG_2 = 2,
	mcSADIQI_POS_LIM_SW = 3,
	mcSADIQI_NEG_LIM_SW = 4,
	mcSADIQI_HOME_SW = 5,
	mcSADIQI_VAR = 6,
	mcSADIQI_IO_CH = 7
} McSADIQstopInEnum;

typedef enum McSADOBCEnum
{	mcSADOBC_NOT_USE = 0,
	mcSADOBC_USE = 1
} McSADOBCEnum;

typedef enum McSADOBCUseDestEnum
{	mcSADOBCUD_VAR = 0,
	mcSADOBCUD_X224_VDC_BRK_OUT = 1
} McSADOBCUseDestEnum;

typedef enum McSEEncIfTypEnum
{	mcSEIT_NOT_USE = 0,
	mcSEIT_INCR = 1
} McSEEncIfTypEnum;

typedef enum McSEIRefPSrcEnum
{	mcSEIRPS_R_IN_ABR_ENC = 0,
	mcSEIRPS_DIG_IN_3 = 1
} McSEIRefPSrcEnum;

typedef enum McSEIRefPEdgEnum
{	mcSEIRPE_POS_EDG = 0,
	mcSEIRPE_NEG_EDG = 1
} McSEIRefPEdgEnum;

typedef enum McSEX6IfTypEnum
{	mcSEX6IT_NOT_USE = 0,
	mcSEX6IT_INCR = 1
} McSEX6IfTypEnum;

typedef enum McSEX6IRefPSrcEnum
{	mcSEX6IRPS_R_IN_ABR_ENC = 0,
	mcSEX6IRPS_DIG_IN_1 = 1,
	mcSEX6IRPS_DIG_IN_2 = 2
} McSEX6IRefPSrcEnum;

typedef enum McSEX6IRefPEdgEnum
{	mcSEX6IRPE_POS_EDG = 0,
	mcSEX6IRPE_NEG_EDG = 1,
	mcSEX6IRPE_POS_AND_NEG_EDG = 2
} McSEX6IRefPEdgEnum;

typedef enum McSEX6IBkWDetectEnum
{	mcSEX6IBWD_A_B = 0,
	mcSEX6IBWD_A_B_R = 1,
	mcSEX6IBWD_NOT_USE = 2
} McSEX6IBkWDetectEnum;

typedef enum McSEX6AIfTypEnum
{	mcSEX6AIT_NOT_USE = 0,
	mcSEX6AIT_INCR = 1,
	mcSEX6AIT_HF = 2,
	mcSEX6AIT_SSI = 3
} McSEX6AIfTypEnum;

typedef enum McSEX6AIRefPSrcEnum
{	mcSEX6AIRPS_R_IN_ABR_ENC = 0,
	mcSEX6AIRPS_DIG_IN_1 = 1,
	mcSEX6AIRPS_DIG_IN_2 = 2
} McSEX6AIRefPSrcEnum;

typedef enum McSEX6AIRefPEdgEnum
{	mcSEX6AIRPE_POS_EDG = 0,
	mcSEX6AIRPE_NEG_EDG = 1,
	mcSEX6AIRPE_POS_AND_NEG_EDG = 2
} McSEX6AIRefPEdgEnum;

typedef enum McSEX6AIBkWDetectEnum
{	mcSEX6AIBWD_A_B = 0,
	mcSEX6AIBWD_A_B_R = 1,
	mcSEX6AIBWD_NOT_USE = 2
} McSEX6AIBkWDetectEnum;

typedef enum McSEX6AHHfBdRateEnum
{	mcSEX6AHHBR_BD_RATE_1_200 = 0,
	mcSEX6AHHBR_BD_RATE_2_400 = 1,
	mcSEX6AHHBR_BD_RATE_4_800 = 2,
	mcSEX6AHHBR_BD_RATE_9_600 = 3,
	mcSEX6AHHBR_BD_RATE_19_200 = 4,
	mcSEX6AHHBR_BD_RATE_38_400 = 5
} McSEX6AHHfBdRateEnum;

typedef enum McSEX6AHHfParEnum
{	mcSEX6AHHP_NONE = 0,
	mcSEX6AHHP_EVEN = 1,
	mcSEX6AHHP_ODD = 2
} McSEX6AHHfParEnum;

typedef enum McSEX6ASClkRateEnum
{	mcSEX6ASCR_CLK_RATE_1_MHZ = 0,
	mcSEX6ASCR_CLK_RATE_800_KHZ = 1,
	mcSEX6ASCR_CLK_RATE_400_KHZ = 2,
	mcSEX6ASCR_CLK_RATE_200_KHZ = 3,
	mcSEX6ASCR_CLK_RATE_100_KHZ = 4
} McSEX6ASClkRateEnum;

typedef enum McSEX6ASEnc01TypEnum
{	mcSEX6ASE0T_BUR_SSI = 0,
	mcSEX6ASE0T_SSI_3P = 1
} McSEX6ASEnc01TypEnum;

typedef enum McSEX6ASEnc01TypSSI3PDatFmtEnum
{	mcSEX6ASE0TS3PDF_BIN = 0,
	mcSEX6ASE0TS3PDF_GRAY = 1
} McSEX6ASEnc01TypSSI3PDatFmtEnum;

typedef enum McSEX6ASEnc01TypSSI3PParBitEnum
{	mcSEX6ASE0TS3PPB_OFF = 0,
	mcSEX6ASE0TS3PPB_EVEN = 1,
	mcSEX6ASE0TS3PPB_ODD = 2,
	mcSEX6ASE0TS3PPB_IGN = 3
} McSEX6ASEnc01TypSSI3PParBitEnum;

typedef enum McSEX6ASEnc01TypSSI3PMCkEnum
{	mcSEX6ASE0TS3PMC_OFF = 0,
	mcSEX6ASE0TS3PMC_LOW = 1,
	mcSEX6ASE0TS3PMC_HIGH = 2
} McSEX6ASEnc01TypSSI3PMCkEnum;

typedef enum McSEX6BIfTypEnum
{	mcSEX6BIT_NOT_USE = 0,
	mcSEX6BIT_INCR = 1,
	mcSEX6BIT_HF = 2,
	mcSEX6BIT_SSI = 3
} McSEX6BIfTypEnum;

typedef enum McSEX6BIRefPSrcEnum
{	mcSEX6BIRPS_R_IN_ABR_ENC = 0,
	mcSEX6BIRPS_DIG_IN_1 = 1,
	mcSEX6BIRPS_DIG_IN_2 = 2
} McSEX6BIRefPSrcEnum;

typedef enum McSEX6BIRefPEdgEnum
{	mcSEX6BIRPE_POS_EDG = 0,
	mcSEX6BIRPE_NEG_EDG = 1,
	mcSEX6BIRPE_POS_AND_NEG_EDG = 2
} McSEX6BIRefPEdgEnum;

typedef enum McSEX6BIBkWDetectEnum
{	mcSEX6BIBWD_A_B = 0,
	mcSEX6BIBWD_A_B_R = 1,
	mcSEX6BIBWD_NOT_USE = 2
} McSEX6BIBkWDetectEnum;

typedef enum McSEX6BHHfBdRateEnum
{	mcSEX6BHHBR_BD_RATE_1_200 = 0,
	mcSEX6BHHBR_BD_RATE_2_400 = 1,
	mcSEX6BHHBR_BD_RATE_4_800 = 2,
	mcSEX6BHHBR_BD_RATE_9_600 = 3,
	mcSEX6BHHBR_BD_RATE_19_200 = 4,
	mcSEX6BHHBR_BD_RATE_38_400 = 5
} McSEX6BHHfBdRateEnum;

typedef enum McSEX6BHHfParEnum
{	mcSEX6BHHP_NONE = 0,
	mcSEX6BHHP_EVEN = 1,
	mcSEX6BHHP_ODD = 2
} McSEX6BHHfParEnum;

typedef enum McSEX6BSClkRateEnum
{	mcSEX6BSCR_CLK_RATE_1_MHZ = 0,
	mcSEX6BSCR_CLK_RATE_800_KHZ = 1,
	mcSEX6BSCR_CLK_RATE_400_KHZ = 2,
	mcSEX6BSCR_CLK_RATE_200_KHZ = 3,
	mcSEX6BSCR_CLK_RATE_100_KHZ = 4
} McSEX6BSClkRateEnum;

typedef enum McSEX6BSEnc01TypEnum
{	mcSEX6BSE0T_BUR_SSI = 0,
	mcSEX6BSE0T_SSI_3P = 1
} McSEX6BSEnc01TypEnum;

typedef enum McSEX6BSEnc01TypSSI3PDatFmtEnum
{	mcSEX6BSE0TS3PDF_BIN = 0,
	mcSEX6BSE0TS3PDF_GRAY = 1
} McSEX6BSEnc01TypSSI3PDatFmtEnum;

typedef enum McSEX6BSEnc01TypSSI3PParBitEnum
{	mcSEX6BSE0TS3PPB_OFF = 0,
	mcSEX6BSE0TS3PPB_EVEN = 1,
	mcSEX6BSE0TS3PPB_ODD = 2,
	mcSEX6BSE0TS3PPB_IGN = 3
} McSEX6BSEnc01TypSSI3PParBitEnum;

typedef enum McSEX6BSEnc01TypSSI3PMCkEnum
{	mcSEX6BSE0TS3PMC_OFF = 0,
	mcSEX6BSE0TS3PMC_LOW = 1,
	mcSEX6BSE0TS3PMC_HIGH = 2
} McSEX6BSEnc01TypSSI3PMCkEnum;

typedef enum McSEX3IfTypEnum
{	mcSEX3IT_NOT_USE = 0,
	mcSEX3IT_INCR = 1
} McSEX3IfTypEnum;

typedef enum McSEX3IRefPSrcEnum
{	mcSEX3IRPS_R_IN_ABR_ENC = 0
} McSEX3IRefPSrcEnum;

typedef enum McSEX3IRefPEdgEnum
{	mcSEX3IRPE_POS_EDG = 0,
	mcSEX3IRPE_NEG_EDG = 1
} McSEX3IRefPEdgEnum;

typedef enum McSEX4IfTypEnum
{	mcSEX4IT_NOT_USE = 0,
	mcSEX4IT_INCR = 1
} McSEX4IfTypEnum;

typedef enum McSEX4IRefPSrcEnum
{	mcSEX4IRPS_R_IN_ABR_ENC = 0
} McSEX4IRefPSrcEnum;

typedef enum McSEX4IRefPEdgEnum
{	mcSEX4IRPE_POS_EDG = 0,
	mcSEX4IRPE_NEG_EDG = 1
} McSEX4IRefPEdgEnum;

typedef struct McStpAxHomingParType
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
	unsigned long RestorePositionVariableAddress;
	float BlockDetectionPositionError;
	float PositionErrorStopLimit;
} McStpAxHomingParType;

typedef struct McStpAxRestorePosType
{	signed long Data[18];
} McStpAxRestorePosType;

typedef struct McSAMEType
{	struct McCfgGearBoxType Gearbox;
	struct McCfgRotToLinTrfType RotaryToLinearTransformation;
} McSAMEType;

typedef struct McSAMType
{	float SteppingAngle;
} McSAMType;

typedef struct McSAELOEPosEncStepCntType
{	enum McSAELOEPosEncStepCntRefPSrcEnum ReferencePulseSource;
	enum McSAELOEPosEncStepCntRefPEdgEnum ReferencePulseEdge;
} McSAELOEPosEncStepCntType;

typedef struct McSAELOEExtPosTypAbsPosRngType
{	signed long LowerLimit;
	unsigned long UpperLimit;
} McSAELOEExtPosTypAbsPosRngType;

typedef struct McSAELOEExtPosTypAbsType
{	struct McSAELOEExtPosTypAbsPosRngType PositionRange;
} McSAELOEExtPosTypAbsType;

typedef struct McSAELOEExtPosTypType
{	enum McSAELOEExtPosTypEnum Type;
	struct McSAELOEExtPosTypAbsType Absolute;
} McSAELOEExtPosTypType;

typedef struct McSAELOEExtPosSrcIOChDINTType
{	plcstring ChannelMapping[251];
} McSAELOEExtPosSrcIOChDINTType;

typedef struct McSAELOEExtPosSrcIOChUDINTType
{	plcstring ChannelMapping[251];
} McSAELOEExtPosSrcIOChUDINTType;

typedef struct McSAELOEExtPosSrcIOChINTType
{	plcstring ChannelMapping[251];
} McSAELOEExtPosSrcIOChINTType;

typedef struct McSAELOEExtPosSrcIOChUINTType
{	plcstring ChannelMapping[251];
} McSAELOEExtPosSrcIOChUINTType;

typedef struct McSAELOEExtPosSrcVarDINTType
{	plcstring PVMapping[251];
} McSAELOEExtPosSrcVarDINTType;

typedef struct McSAELOEExtPosSrcVarUDINTType
{	plcstring PVMapping[251];
} McSAELOEExtPosSrcVarUDINTType;

typedef struct McSAELOEExtPosSrcVarINTType
{	plcstring PVMapping[251];
} McSAELOEExtPosSrcVarINTType;

typedef struct McSAELOEExtPosSrcVarUINTType
{	plcstring PVMapping[251];
} McSAELOEExtPosSrcVarUINTType;

typedef struct McSAELOEExtPosSrcType
{	enum McSAELOEExtPosSrcEnum Type;
	struct McSAELOEExtPosSrcIOChDINTType IOChannelDINT;
	struct McSAELOEExtPosSrcIOChUDINTType IOChannelUDINT;
	struct McSAELOEExtPosSrcIOChINTType IOChannelINT;
	struct McSAELOEExtPosSrcIOChUINTType IOChannelUINT;
	struct McSAELOEExtPosSrcVarDINTType VariableDINT;
	struct McSAELOEExtPosSrcVarUDINTType VariableUDINT;
	struct McSAELOEExtPosSrcVarINTType VariableINT;
	struct McSAELOEExtPosSrcVarUINTType VariableUINT;
} McSAELOEExtPosSrcType;

typedef struct McSAELOEExtValCkModOkIOChType
{	plcstring ChannelMapping[251];
} McSAELOEExtValCkModOkIOChType;

typedef struct McSAELOEExtValCkModOkVarType
{	plcstring PVMapping[251];
} McSAELOEExtValCkModOkVarType;

typedef struct McSAELOEExtValCkModOkType
{	enum McSAELOEExtValCkModOkEnum Type;
	struct McSAELOEExtValCkModOkIOChType IOChannel;
	struct McSAELOEExtValCkModOkVarType Variable;
} McSAELOEExtValCkModOkType;

typedef struct McSAELOEExtValCkStDatIOChType
{	plcstring ChannelMapping[251];
} McSAELOEExtValCkStDatIOChType;

typedef struct McSAELOEExtValCkStDatVarType
{	plcstring PVMapping[251];
} McSAELOEExtValCkStDatVarType;

typedef struct McSAELOEExtValCkStDatType
{	enum McSAELOEExtValCkStDatEnum Type;
	struct McSAELOEExtValCkStDatIOChType IOChannel;
	struct McSAELOEExtValCkStDatVarType Variable;
} McSAELOEExtValCkStDatType;

typedef struct McSAELOEExtValCkNetTimeIOChType
{	plcstring ChannelMapping[251];
} McSAELOEExtValCkNetTimeIOChType;

typedef struct McSAELOEExtValCkNetTimeVarType
{	plcstring PVMapping[251];
} McSAELOEExtValCkNetTimeVarType;

typedef struct McSAELOEExtValCkNetTimeType
{	enum McSAELOEExtValCkNetTimeEnum Type;
	struct McSAELOEExtValCkNetTimeIOChType IOChannel;
	struct McSAELOEExtValCkNetTimeVarType Variable;
} McSAELOEExtValCkNetTimeType;

typedef struct McSAELOEExtValCkEncOkIOChType
{	plcstring ChannelMapping[251];
} McSAELOEExtValCkEncOkIOChType;

typedef struct McSAELOEExtValCkEncOkVarType
{	plcstring PVMapping[251];
} McSAELOEExtValCkEncOkVarType;

typedef struct McSAELOEExtValCkEncOkType
{	enum McSAELOEExtValCkEncOkEnum Type;
	struct McSAELOEExtValCkEncOkIOChType IOChannel;
	struct McSAELOEExtValCkEncOkVarType Variable;
} McSAELOEExtValCkEncOkType;

typedef struct McSAELOEExtValCkType
{	struct McSAELOEExtValCkModOkType ModuleOk;
	struct McSAELOEExtValCkStDatType StaleData;
	struct McSAELOEExtValCkNetTimeType NetTime;
	struct McSAELOEExtValCkEncOkType EncoderOk;
} McSAELOEExtValCkType;

typedef struct McSAELOEExtRefPIOChPosType
{	plcstring ChannelMapping[251];
} McSAELOEExtRefPIOChPosType;

typedef struct McSAELOEExtRefPIOChCntType
{	plcstring ChannelMapping[251];
} McSAELOEExtRefPIOChCntType;

typedef struct McSAELOEExtRefPIOChType
{	struct McSAELOEExtRefPIOChPosType Position;
	struct McSAELOEExtRefPIOChCntType Count;
} McSAELOEExtRefPIOChType;

typedef struct McSAELOEExtRefPVarPosType
{	plcstring PVMapping[251];
} McSAELOEExtRefPVarPosType;

typedef struct McSAELOEExtRefPVarCntType
{	plcstring PVMapping[251];
} McSAELOEExtRefPVarCntType;

typedef struct McSAELOEExtRefPVarType
{	struct McSAELOEExtRefPVarPosType Position;
	struct McSAELOEExtRefPVarCntType Count;
} McSAELOEExtRefPVarType;

typedef struct McSAELOEExtRefPType
{	enum McSAELOEExtRefPEnum Type;
	struct McSAELOEExtRefPIOChType IOChannel;
	struct McSAELOEExtRefPVarType Variable;
} McSAELOEExtRefPType;

typedef struct McSAELOEEPosFltrExtpolDistType
{	float PositionFilterTimeConstant;
	float ExtrapolationTime;
} McSAELOEEPosFltrExtpolDistType;

typedef struct McSAELOEEPosFltrType
{	enum McSAELOEEPosFltrEnum Type;
	struct McSAELOEEPosFltrExtpolDistType ExtrapolationAndDisturbance;
} McSAELOEEPosFltrType;

typedef struct McSAELOEPosEncExtType
{	unsigned long LinesPerEncoderRevolution;
	struct McSAELOEExtPosTypType PositionType;
	struct McSAELOEExtPosSrcType PositionSource;
	struct McSAELOEExtValCkType ValidityCheck;
	struct McSAELOEExtRefPType ReferencePulse;
	struct McSAELOEEPosFltrType PositionFilter;
} McSAELOEPosEncExtType;

typedef struct McSAELOEPosEncType
{	enum McSAELOEPosEncEnum Type;
	struct McSAELOEPosEncStepCntType StepCounter;
	struct McSAELOEPosEncExtType External;
} McSAELOEPosEncType;

typedef struct McSAELOEType
{	struct McSAELOEPosEncType PositionEncoder;
} McSAELOEType;

typedef struct McSAELType
{	enum McSAELEnum Type;
	struct McSAELOEType OneEncoder;
} McSAELType;

typedef struct McSACCStdType
{	float StandstillCurrent;
	float ConstantSpeedCurrent;
	float SpeedChangeCurrent;
	float FullStepThreshold;
	float MotorSettlingTime;
	float DelayedCurrentSwitchOff;
} McSACCStdType;

typedef struct McSACCSCCSCCType
{	enum McSACCSCCSCCActEnum Active;
	enum McSACCSCCSCCCurRedEnum CurrentReduction;
	enum McSACCSCCSCCRedActLvlEnum ReductionActivationLevel;
	enum McSACCSCCSCCRedActDlyEnum ReductionActivationDelay;
	enum McSACCSCCSCCRedRstLvlEnum ReductionResetLevel;
	enum McSACCSCCSCCRedRstDlyEnum ReductionResetDelay;
} McSACCSCCSCCType;

typedef struct McSACCSCCType
{	float StandstillCurrent;
	float ConstantSpeedCurrent;
	float SpeedChangeCurrent;
	float FullStepThreshold;
	float MotorSettlingTime;
	float DelayedCurrentSwitchOff;
	struct McSACCSCCSCCType SmartCurrentControl;
} McSACCSCCType;

typedef struct McSACCurType
{	enum McSACCurEnum Type;
	struct McSACCStdType Standard;
	struct McSACCSCCType SmartCurrentControl;
} McSACCurType;

typedef struct McSACModCurCtrlType
{	struct McSACCurType Current;
} McSACModCurCtrlType;

typedef struct McSACModPosAndCurCtrlPosType
{	float ProportionalGain;
	float MaximumProportionalAction;
	float PredictionTime;
	float TotalDelayTime;
} McSACModPosAndCurCtrlPosType;

typedef struct McSACModPosAndCurCtrlType
{	struct McSACCurType Current;
	struct McSACModPosAndCurCtrlPosType Position;
} McSACModPosAndCurCtrlType;

typedef struct McSACModType
{	enum McSACModEnum Type;
	struct McSACModCurCtrlType CurrentController;
	struct McSACModPosAndCurCtrlType PositionAndCurrentController;
} McSACModType;

typedef struct McSACType
{	struct McSACModType Mode;
} McSACType;

typedef struct McSAHModDirRefPUseType
{	float HomingVelocity;
	float Acceleration;
	enum McSAHModHomeDirEnum HomingDirection;
	enum McSAHModKeepDirEnum KeepDirection;
	double ReferencePulseBlockingDistance;
} McSAHModDirRefPUseType;

typedef struct McSAHModDirRefPType
{	enum McSAHModDirRefPEnum Type;
	struct McSAHModDirRefPUseType Used;
} McSAHModDirRefPType;

typedef struct McSAHModDirType
{	double Position;
	struct McSAHModDirRefPType ReferencePulse;
} McSAHModDirType;

typedef struct McSAHModRefPUseType
{	double ReferencePulseBlockingDistance;
} McSAHModRefPUseType;

typedef struct McSAHModRefPType
{	enum McSAHModRefPEnum Type;
	struct McSAHModRefPUseType Used;
} McSAHModRefPType;

typedef struct McSAHModAbsSwType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McSAHModSwEdgEnum SwitchEdge;
	enum McSAHModHomeDirEnum HomingDirection;
	enum McSAHModKeepDirEnum KeepDirection;
	struct McSAHModRefPType ReferencePulse;
} McSAHModAbsSwType;

typedef struct McSAHModSwGateType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McSAHModSwEdgEnum SwitchEdge;
	enum McSAHModStartDirEnum StartDirection;
	enum McSAHModHomeDirEnum HomingDirection;
	enum McSAHModKeepDirEnum KeepDirection;
	struct McSAHModRefPType ReferencePulse;
} McSAHModSwGateType;

typedef struct McSAHModLimSwType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McSAHModSwEdgEnum SwitchEdge;
	enum McSAHModHomeDirEnum HomingDirection;
	enum McSAHModKeepDirEnum KeepDirection;
	struct McSAHModRefPType ReferencePulse;
} McSAHModLimSwType;

typedef struct McSAHModAbsType
{	double Position;
} McSAHModAbsType;

typedef struct McSAHModAbsCorrType
{	double Position;
} McSAHModAbsCorrType;

typedef struct McSAHModBlkRefPNotUseType
{	double MinimumReturnDistance;
} McSAHModBlkRefPNotUseType;

typedef struct McSAHModBlkRefPUseType
{	double ReferencePulseBlockingDistance;
} McSAHModBlkRefPUseType;

typedef struct McSAHModBlkRefPType
{	enum McSAHModRefPEnum Type;
	struct McSAHModBlkRefPNotUseType NotUsed;
	struct McSAHModBlkRefPUseType Used;
} McSAHModBlkRefPType;

typedef struct McSAHModBlkLagErrType
{	double Position;
	float StartVelocity;
	float HomingVelocity;
	float Acceleration;
	enum McSAHModStartDirEnum StartDirection;
	enum McSAHModHomeDirEnum HomingDirection;
	struct McSAHModBlkRefPType ReferencePulse;
	double PositionErrorStopLimit;
	double BlockDetectionPositionError;
} McSAHModBlkLagErrType;

typedef struct McSAHModType
{	enum McSAHModEnum Type;
	struct McSAHModDirType Direct;
	struct McSAHModAbsSwType AbsoluteSwitch;
	struct McSAHModSwGateType SwitchGate;
	struct McSAHModLimSwType LimitSwitch;
	struct McSAHModAbsType Absolute;
	struct McSAHModAbsCorrType AbsoluteCorrection;
	struct McSAHModBlkLagErrType BlockLagError;
} McSAHModType;

typedef struct McSAHType
{	struct McSAHModType Mode;
	plcstring RestorePositionVariable[251];
} McSAHType;

typedef struct McSASRDEType
{	enum McSASRDEEnum Type;
} McSASRDEType;

typedef struct McSASRType
{	struct McSASRDEType DriveError;
} McSASRType;

typedef struct McSAMELStallDetectCfgUseType
{	enum McSAMELStallDetectCfgUseReacEnum Reaction;
	unsigned char StallDetectionThreshold;
	float StallDetectionMinimumSpeed;
	unsigned char MixedDecayThreshold;
} McSAMELStallDetectCfgUseType;

typedef struct McSAMELStallDetectCfgType
{	enum McSAMELStallDetectCfgEnum Type;
	struct McSAMELStallDetectCfgUseType Used;
} McSAMELStallDetectCfgType;

typedef struct McSAMELStallguardCfgUseType
{	enum McSAMELStallguardCfgUseReacEnum Reaction;
	float StallDetectionMinimumSpeed;
	float StallDetectionSpeedA;
	signed char StallDetectionValueA;
	float StallDetectionSpeedB;
	signed char StallDetectionValueB;
} McSAMELStallguardCfgUseType;

typedef struct McSAMELStallguardCfgType
{	enum McSAMELStallguardCfgEnum Type;
	struct McSAMELStallguardCfgUseType Used;
} McSAMELStallguardCfgType;

typedef struct McSAMELType
{	double PositionError;
	struct McSAMELStallDetectCfgType StallDetectionConfiguration;
	struct McSAMELStallguardCfgType StallguardConfiguration;
} McSAMELType;

typedef struct McSAJFUseType
{	float MaximumJerkTime;
	float JerkTime;
} McSAJFUseType;

typedef struct McSAJFJerkLimType
{	float JerkLimit;
} McSAJFJerkLimType;

typedef struct McSAJFType
{	enum McSAJFEnum Type;
	struct McSAJFUseType Used;
	struct McSAJFJerkLimType JerkLimited;
} McSAJFType;

typedef struct McSADIAllSrcVarTSUseType
{	plcstring PVMapping[251];
} McSADIAllSrcVarTSUseType;

typedef struct McSADIASVTSRAFERECntType
{	plcstring PVMapping[251];
} McSADIASVTSRAFERECntType;

typedef struct McSADIASVTSRAFERETimStmpType
{	plcstring PVMapping[251];
} McSADIASVTSRAFERETimStmpType;

typedef struct McSADIASVTSRAFERisEdgType
{	struct McSADIASVTSRAFERECntType Count;
	struct McSADIASVTSRAFERETimStmpType TimeStamp;
} McSADIASVTSRAFERisEdgType;

typedef struct McSADIASVTSRAFEFECntType
{	plcstring PVMapping[251];
} McSADIASVTSRAFEFECntType;

typedef struct McSADIASVTSRAFEFETimStmpType
{	plcstring PVMapping[251];
} McSADIASVTSRAFEFETimStmpType;

typedef struct McSADIASVTSRAFEFallEdgType
{	struct McSADIASVTSRAFEFECntType Count;
	struct McSADIASVTSRAFEFETimStmpType TimeStamp;
} McSADIASVTSRAFEFallEdgType;

typedef struct McSADIASVTSRisAndFallEdgType
{	struct McSADIASVTSRAFERisEdgType RisingEdge;
	struct McSADIASVTSRAFEFallEdgType FallingEdge;
} McSADIASVTSRisAndFallEdgType;

typedef struct McSADIAllSrcVarTSType
{	enum McSADIAllSrcVarTSEnum Type;
	struct McSADIAllSrcVarTSUseType Used;
	struct McSADIASVTSRisAndFallEdgType RisingAndFallingEdge;
} McSADIAllSrcVarTSType;

typedef struct McSADIAllSrcVarType
{	plcstring PVMapping[251];
	struct McSADIAllSrcVarTSType TimeStamp;
} McSADIAllSrcVarType;

typedef struct McSADIAllSrcIOChTSUseType
{	plcstring ChannelMapping[251];
} McSADIAllSrcIOChTSUseType;

typedef struct McSADIASIOCTSRAFERECntType
{	plcstring ChannelMapping[251];
} McSADIASIOCTSRAFERECntType;

typedef struct McSADIASIOCTSRAFERETimStmpType
{	plcstring ChannelMapping[251];
} McSADIASIOCTSRAFERETimStmpType;

typedef struct McSADIASIOCTSRAFERisEdgType
{	struct McSADIASIOCTSRAFERECntType Count;
	struct McSADIASIOCTSRAFERETimStmpType TimeStamp;
} McSADIASIOCTSRAFERisEdgType;

typedef struct McSADIASIOCTSRAFEFECntType
{	plcstring ChannelMapping[251];
} McSADIASIOCTSRAFEFECntType;

typedef struct McSADIASIOCTSRAFEFETimStmpType
{	plcstring ChannelMapping[251];
} McSADIASIOCTSRAFEFETimStmpType;

typedef struct McSADIASIOCTSRAFEFallEdgType
{	struct McSADIASIOCTSRAFEFECntType Count;
	struct McSADIASIOCTSRAFEFETimStmpType TimeStamp;
} McSADIASIOCTSRAFEFallEdgType;

typedef struct McSADIASIOCTSRisAndFallEdgType
{	struct McSADIASIOCTSRAFERisEdgType RisingEdge;
	struct McSADIASIOCTSRAFEFallEdgType FallingEdge;
} McSADIASIOCTSRisAndFallEdgType;

typedef struct McSADIAllSrcIOChTSType
{	enum McSADIAllSrcIOChTSEnum Type;
	struct McSADIAllSrcIOChTSUseType Used;
	struct McSADIASIOCTSRisAndFallEdgType RisingAndFallingEdge;
} McSADIAllSrcIOChTSType;

typedef struct McSADIAllSrcIOChType
{	plcstring ChannelMapping[251];
	struct McSADIAllSrcIOChTSType TimeStamp;
} McSADIAllSrcIOChType;

typedef struct McSADIAllSrcType
{	enum McSADIAllSrcEnum Type;
	struct McSADIAllSrcVarType Variable;
	struct McSADIAllSrcIOChType IOChannel;
} McSADIAllSrcType;

typedef struct McSADIHomeSwType
{	struct McSADIAllSrcType Source;
	enum McSADIHomeSwLvlEnum Level;
} McSADIHomeSwType;

typedef struct McSADIPosLimSwType
{	struct McSADIAllSrcType Source;
	enum McSADIPosLimSwLvlEnum Level;
} McSADIPosLimSwType;

typedef struct McSADINegLimSwType
{	struct McSADIAllSrcType Source;
	enum McSADINegLimSwLvlEnum Level;
} McSADINegLimSwType;

typedef struct McSADITrg1Type
{	struct McSADIAllSrcType Source;
	enum McSADITrg1LvlEnum Level;
} McSADITrg1Type;

typedef struct McSADITrg2Type
{	struct McSADIAllSrcType Source;
	enum McSADITrg2LvlEnum Level;
} McSADITrg2Type;

typedef struct McSADIQstopInVarType
{	plcstring PVMapping[251];
} McSADIQstopInVarType;

typedef struct McSADIQstopInIOChType
{	plcstring ChannelMapping[251];
} McSADIQstopInIOChType;

typedef struct McSADIQstopInType
{	enum McSADIQstopInEnum Type;
	struct McSADIQstopInVarType Variable;
	struct McSADIQstopInIOChType IOChannel;
} McSADIQstopInType;

typedef struct McSADIQstopType
{	struct McSADIQstopInType Input;
} McSADIQstopType;

typedef struct McSADIType
{	struct McSADIHomeSwType HomingSwitch;
	struct McSADIPosLimSwType PositiveLimitSwitch;
	struct McSADINegLimSwType NegativeLimitSwitch;
	struct McSADITrg1Type Trigger1;
	struct McSADITrg2Type Trigger2;
	struct McSADIQstopType Quickstop;
} McSADIType;

typedef struct McSADOBCUseDestVarType
{	plcstring PVMapping[251];
} McSADOBCUseDestVarType;

typedef struct McSADOBCUseDestType
{	enum McSADOBCUseDestEnum Type;
	struct McSADOBCUseDestVarType Variable;
} McSADOBCUseDestType;

typedef struct McSADOBCUseType
{	struct McSADOBCUseDestType Destination;
	float ActivationDelay;
	float ReleaseDelay;
} McSADOBCUseType;

typedef struct McSADOBCType
{	enum McSADOBCEnum Type;
	struct McSADOBCUseType Used;
} McSADOBCType;

typedef struct McSADOType
{	struct McSADOBCType BrakeControl;
} McSADOType;

typedef struct McSAAFType
{	struct McCfgUnboundedArrayType FeatureReference;
} McSAAFType;

typedef struct McCfgStpAxType
{	struct McCfgReferenceType AxisReference;
	struct McSAMEType MechanicalElements;
	struct McSAMType Motor;
	struct McSAELType EncoderLink;
	struct McSACType Controller;
	struct McSAHType Homing;
	struct McSASRType StopReaction;
	struct McSAMELType MovementErrorLimits;
	struct McSAJFType JerkFilter;
	struct McSADIType DigitalInputs;
	struct McSADOType DigitalOutputs;
	struct McSAAFType AxisFeatures;
} McCfgStpAxType;

typedef struct McCfgStpAxRefType
{	struct McCfgReferenceType AxisReference;
} McCfgStpAxRefType;

typedef struct McCfgStpAxMechElmType
{	struct McSAMEType MechanicalElements;
} McCfgStpAxMechElmType;

typedef struct McCfgStpAxMotType
{	struct McSAMType Motor;
} McCfgStpAxMotType;

typedef struct McCfgStpAxEncLinkType
{	struct McSAELType EncoderLink;
} McCfgStpAxEncLinkType;

typedef struct McCfgStpAxCtrlType
{	struct McSACType Controller;
} McCfgStpAxCtrlType;

typedef struct McCfgStpAxHomeType
{	struct McSAHType Homing;
} McCfgStpAxHomeType;

typedef struct McCfgStpAxStopReacType
{	struct McSASRType StopReaction;
} McCfgStpAxStopReacType;

typedef struct McCfgStpAxMoveErrLimType
{	struct McSAMELType MovementErrorLimits;
} McCfgStpAxMoveErrLimType;

typedef struct McCfgStpAxJerkFltrType
{	struct McSAJFType JerkFilter;
} McCfgStpAxJerkFltrType;

typedef struct McCfgStpAxDigInType
{	struct McSADIType DigitalInputs;
} McCfgStpAxDigInType;

typedef struct McCfgStpAxDigOutType
{	struct McSADOType DigitalOutputs;
} McCfgStpAxDigOutType;

typedef struct McCfgStpAxFeatType
{	struct McSAAFType AxisFeatures;
} McCfgStpAxFeatType;

typedef struct McSEIType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEIRefPSrcEnum ReferencePulseSource;
	enum McSEIRefPEdgEnum ReferencePulseEdge;
} McSEIType;

typedef struct McSEEncIfTypType
{	enum McSEEncIfTypEnum Type;
	struct McSEIType Incremental;
} McSEEncIfTypType;

typedef struct McSEEncType
{	struct McSEEncIfTypType InterfaceType;
} McSEEncType;

typedef struct McSEX6IType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEX6IRefPSrcEnum ReferencePulseSource;
	enum McSEX6IRefPEdgEnum ReferencePulseEdge;
	enum McSEX6IBkWDetectEnum BrokenWireDetection;
} McSEX6IType;

typedef struct McSEX6IfTypType
{	enum McSEX6IfTypEnum Type;
	struct McSEX6IType Incremental;
} McSEX6IfTypType;

typedef struct McSEX6Type
{	struct McSEX6IfTypType InterfaceType;
} McSEX6Type;

typedef struct McSEX6AIType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEX6AIRefPSrcEnum ReferencePulseSource;
	enum McSEX6AIRefPEdgEnum ReferencePulseEdge;
	enum McSEX6AIBkWDetectEnum BrokenWireDetection;
} McSEX6AIType;

typedef struct McSEX6AHPosRngType
{	signed long LowerLimit;
	unsigned long UpperLimit;
} McSEX6AHPosRngType;

typedef struct McSEX6AHSinCosTrkType
{	unsigned short VssMaximum;
	unsigned short VssMinimum;
	unsigned long VssQuittTime;
} McSEX6AHSinCosTrkType;

typedef struct McSEX6AHHfType
{	enum McSEX6AHHfBdRateEnum BaudRate;
	enum McSEX6AHHfParEnum Parity;
	unsigned char ReceiveIdleTime;
	unsigned char ReferenceStationAdress;
	unsigned char ReferencePositionWidth;
} McSEX6AHHfType;

typedef struct McSEX6AHType
{	unsigned long LinesPerEncoderRevolution;
	struct McSEX6AHPosRngType PositionRange;
	struct McSEX6AHSinCosTrkType SineCosineTrack;
	struct McSEX6AHHfType Hiperface;
} McSEX6AHType;

typedef struct McSEX6ASPosRngType
{	signed long LowerLimit;
	unsigned long UpperLimit;
} McSEX6ASPosRngType;

typedef struct McSEX6ASEnc01TypSSI3PType
{	enum McSEX6ASEnc01TypSSI3PDatFmtEnum DataFormat;
	unsigned char ValidSSIBitLength;
	unsigned char TotalSSIBitLength;
	enum McSEX6ASEnc01TypSSI3PParBitEnum ParityBit;
	enum McSEX6ASEnc01TypSSI3PMCkEnum MonoflopCheck;
} McSEX6ASEnc01TypSSI3PType;

typedef struct McSEX6ASEnc01TypType
{	enum McSEX6ASEnc01TypEnum Type;
	struct McSEX6ASEnc01TypSSI3PType SSI3rdParty;
} McSEX6ASEnc01TypType;

typedef struct McSEX6ASType
{	unsigned long LinesPerEncoderRevolution;
	struct McSEX6ASPosRngType PositionRange;
	enum McSEX6ASClkRateEnum ClockRate;
	unsigned short CyclePrescaler;
	struct McSEX6ASEnc01TypType Encoder01Type;
} McSEX6ASType;

typedef struct McSEX6AIfTypType
{	enum McSEX6AIfTypEnum Type;
	struct McSEX6AIType Incremental;
	struct McSEX6AHType Hiperface;
	struct McSEX6ASType SSI;
} McSEX6AIfTypType;

typedef struct McSEX6AType
{	struct McSEX6AIfTypType InterfaceType;
} McSEX6AType;

typedef struct McSEX6BIType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEX6BIRefPSrcEnum ReferencePulseSource;
	enum McSEX6BIRefPEdgEnum ReferencePulseEdge;
	enum McSEX6BIBkWDetectEnum BrokenWireDetection;
} McSEX6BIType;

typedef struct McSEX6BHPosRngType
{	signed long LowerLimit;
	unsigned long UpperLimit;
} McSEX6BHPosRngType;

typedef struct McSEX6BHSinCosTrkType
{	unsigned short VssMaximum;
	unsigned short VssMinimum;
	unsigned long VssQuittTime;
} McSEX6BHSinCosTrkType;

typedef struct McSEX6BHHfType
{	enum McSEX6BHHfBdRateEnum BaudRate;
	enum McSEX6BHHfParEnum Parity;
	unsigned char ReceiveIdleTime;
	unsigned char ReferenceStationAdress;
	unsigned char ReferencePositionWidth;
} McSEX6BHHfType;

typedef struct McSEX6BHType
{	unsigned long LinesPerEncoderRevolution;
	struct McSEX6BHPosRngType PositionRange;
	struct McSEX6BHSinCosTrkType SineCosineTrack;
	struct McSEX6BHHfType Hiperface;
} McSEX6BHType;

typedef struct McSEX6BSPosRngType
{	signed long LowerLimit;
	unsigned long UpperLimit;
} McSEX6BSPosRngType;

typedef struct McSEX6BSEnc01TypSSI3PType
{	enum McSEX6BSEnc01TypSSI3PDatFmtEnum DataFormat;
	unsigned char ValidSSIBitLength;
	unsigned char TotalSSIBitLength;
	enum McSEX6BSEnc01TypSSI3PParBitEnum ParityBit;
	enum McSEX6BSEnc01TypSSI3PMCkEnum MonoflopCheck;
} McSEX6BSEnc01TypSSI3PType;

typedef struct McSEX6BSEnc01TypType
{	enum McSEX6BSEnc01TypEnum Type;
	struct McSEX6BSEnc01TypSSI3PType SSI3rdParty;
} McSEX6BSEnc01TypType;

typedef struct McSEX6BSType
{	unsigned long LinesPerEncoderRevolution;
	struct McSEX6BSPosRngType PositionRange;
	enum McSEX6BSClkRateEnum ClockRate;
	unsigned short CyclePrescaler;
	struct McSEX6BSEnc01TypType Encoder01Type;
} McSEX6BSType;

typedef struct McSEX6BIfTypType
{	enum McSEX6BIfTypEnum Type;
	struct McSEX6BIType Incremental;
	struct McSEX6BHType Hiperface;
	struct McSEX6BSType SSI;
} McSEX6BIfTypType;

typedef struct McSEX6BType
{	struct McSEX6BIfTypType InterfaceType;
} McSEX6BType;

typedef struct McSEX3IType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEX3IRefPSrcEnum ReferencePulseSource;
	enum McSEX3IRefPEdgEnum ReferencePulseEdge;
} McSEX3IType;

typedef struct McSEX3IfTypType
{	enum McSEX3IfTypEnum Type;
	struct McSEX3IType Incremental;
} McSEX3IfTypType;

typedef struct McSEX3Type
{	struct McSEX3IfTypType InterfaceType;
} McSEX3Type;

typedef struct McSEX4IType
{	unsigned long LinesPerEncoderRevolution;
	enum McSEX4IRefPSrcEnum ReferencePulseSource;
	enum McSEX4IRefPEdgEnum ReferencePulseEdge;
} McSEX4IType;

typedef struct McSEX4IfTypType
{	enum McSEX4IfTypEnum Type;
	struct McSEX4IType Incremental;
} McSEX4IfTypType;

typedef struct McSEX4Type
{	struct McSEX4IfTypType InterfaceType;
} McSEX4Type;

typedef struct McCfgStpEncType
{	struct McSEEncType Encoder;
	struct McSEX6Type X6;
	struct McSEX6AType X6A;
	struct McSEX6BType X6B;
	struct McSEX3Type X3;
	struct McSEX4Type X4;
} McCfgStpEncType;

typedef struct MC_BR_InitHome_StpAx
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McStpAxHomingParType HomingParameters;
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
} MC_BR_InitHome_StpAx_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MC_BR_InitHome_StpAx(struct MC_BR_InitHome_StpAx* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MCSTPAX_ */

