/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _MTTYPES_
#define _MTTYPES_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define mtGNR_WRN_DELAY_TIME_TOO_HIGH (-2131754999)
 #define mtGNR_WRN_DELAY_TIME_NEGATIVE (-2131755000)
 #define mtGNR_WRN_OUTPUT_LIMIT_INVALID (-2131755001)
 #define mtGNR_WRN_FILTER_TIME_NEGATIVE (-2131755002)
 #define mtGNR_WRN_DERIVATIVE_TIME_NEG (-2131755003)
 #define mtGNR_WRN_INTEGRATION_TIME_NEG (-2131755004)
 #define mtGNR_WRN_GAIN_NEGATIVE (-2131755005)
 #define mtGNR_WRN_MEM_ALLOC_FAILED (-2131755006)
 #define mtGNR_WRN_OTHER_FB_USES_SYSREF (-2131755007)
 #define mtGNR_ERR_DELAY_TIME_TOO_HIGH (-1058013172)
 #define mtGNR_ERR_OUTPUT_LIMIT_INVALID (-1058013173)
 #define mtGNR_ERR_DELAY_TIME_HIGH (-1058013174)
 #define mtGNR_ERR_DELAY_TIME_NEGATIVE (-1058013175)
 #define mtGNR_ERR_FILTER_TIME_NEGATIVE (-1058013176)
 #define mtGNR_ERR_DERIVATIVE_TIME_NEG (-1058013177)
 #define mtGNR_ERR_INTEGRATION_TIME_NEG (-1058013178)
 #define mtGNR_ERR_GAIN_NEGATIVE (-1058013179)
 #define mtGNR_ERR_SAMPLE_TIME_INVALID (-1058013180)
 #define mtGNR_ERR_MEM_ALLOC_FAILED (-1058013181)
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST signed long mtGNR_WRN_DELAY_TIME_TOO_HIGH;
 _GLOBAL_CONST signed long mtGNR_WRN_DELAY_TIME_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_WRN_OUTPUT_LIMIT_INVALID;
 _GLOBAL_CONST signed long mtGNR_WRN_FILTER_TIME_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_WRN_DERIVATIVE_TIME_NEG;
 _GLOBAL_CONST signed long mtGNR_WRN_INTEGRATION_TIME_NEG;
 _GLOBAL_CONST signed long mtGNR_WRN_GAIN_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_WRN_MEM_ALLOC_FAILED;
 _GLOBAL_CONST signed long mtGNR_WRN_OTHER_FB_USES_SYSREF;
 _GLOBAL_CONST signed long mtGNR_ERR_DELAY_TIME_TOO_HIGH;
 _GLOBAL_CONST signed long mtGNR_ERR_OUTPUT_LIMIT_INVALID;
 _GLOBAL_CONST signed long mtGNR_ERR_DELAY_TIME_HIGH;
 _GLOBAL_CONST signed long mtGNR_ERR_DELAY_TIME_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_ERR_FILTER_TIME_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_ERR_DERIVATIVE_TIME_NEG;
 _GLOBAL_CONST signed long mtGNR_ERR_INTEGRATION_TIME_NEG;
 _GLOBAL_CONST signed long mtGNR_ERR_GAIN_NEGATIVE;
 _GLOBAL_CONST signed long mtGNR_ERR_SAMPLE_TIME_INVALID;
 _GLOBAL_CONST signed long mtGNR_ERR_MEM_ALLOC_FAILED;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum MTPIDIntegrationEnum
{	mtINTEGRATION_FREE = 0,
	mtHOLD_INTEGRATION_POSITIVE = 1,
	mtHOLD_INTEGRATION_NEGATIVE = -1
} MTPIDIntegrationEnum;

typedef struct MTBodeType
{	float FrequencyVector[161];
	float MagnitudeVector[161];
	float PhaseVector[161];
	float MinFrequency;
	float MaxFrequency;
	float MinMagnitude;
	float MaxMagnitude;
	float MinPhase;
	float MaxPhase;
} MTBodeType;

typedef struct MTCommType
{	signed long ID;
	plcbit Valid;
	unsigned long Counter;
} MTCommType;

typedef struct MTFrequencyResponseType
{	struct MTCommType Communication;
	float Frequency[161];
	float Magnitude[161];
	float Phase[161];
	float MinFrequency;
	float MaxFrequency;
	float MinMagnitude;
	float MaxMagnitude;
	float MinPhase;
	float MaxPhase;
	signed long CheckID;
} MTFrequencyResponseType;

typedef struct MTPIDParametersType
{	float Gain;
	float IntegrationTime;
	float DerivativeTime;
	float FilterTime;
} MTPIDParametersType;

typedef struct MTStateSpaceType
{	struct MTCommType Communication;
	double* A;
	double* B;
	double* C;
	double* D;
	unsigned char NbStates;
	unsigned char NbInputs;
	unsigned char NbOutputs;
	float SampleTime;
	signed long CheckID;
} MTStateSpaceType;

typedef struct MTTransferFcnType
{	struct MTCommType Communication;
	float Numerator[6];
	float Denominator[6];
	float SampleTime;
	signed long CheckID;
} MTTransferFcnType;






#ifdef __cplusplus
};
#endif
#endif /* _MTTYPES_ */

