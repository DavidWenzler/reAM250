/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _RUNTIME_
#define _RUNTIME_
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
 #define IEC_DATATYPE_LINT 23U
 #define IEC_DATATYPE_WSTRING 21U
 #define IEC_DATATYPE_LWORD 20U
 #define IEC_DATATYPE_DWORD 19U
 #define IEC_DATATYPE_WORD 18U
 #define IEC_DATATYPE_BYTE 17U
 #define IEC_DATATYPE_TIME_OF_DAY 16U
 #define IEC_DATATYPE_LREAL 14U
 #define IEC_DATATYPE_DATE 13U
 #define IEC_DATATYPE_TIME 12U
 #define IEC_DATATYPE_DATE_AND_TIME 11U
 #define IEC_DATATYPE_ULINT 10U
 #define IEC_DATATYPE_STRING 9U
 #define IEC_DATATYPE_REAL 8U
 #define IEC_DATATYPE_UDINT 7U
 #define IEC_DATATYPE_UINT 6U
 #define IEC_DATATYPE_USINT 5U
 #define IEC_DATATYPE_DINT 4U
 #define IEC_DATATYPE_INT 3U
 #define IEC_DATATYPE_SINT 2U
 #define IEC_DATATYPE_BOOL 1U
 #define ERR_FB_NOT_IMPLEMENTED (-1070585592)
 #define ERR_FUB_REDUNDANT 35688U
 #define ERR_FUB_BUSY 65535U
 #define ERR_FUB_ENABLE_FALSE 65534U
 #define ERR_NOTIMPLEMENTED 9999U
 #define ERR_OK 0U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short IEC_DATATYPE_LINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_WSTRING;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_LWORD;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_DWORD;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_WORD;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_BYTE;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_TIME_OF_DAY;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_LREAL;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_DATE;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_TIME;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_DATE_AND_TIME;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_ULINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_STRING;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_REAL;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_UDINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_UINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_USINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_DINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_INT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_SINT;
 _GLOBAL_CONST unsigned short IEC_DATATYPE_BOOL;
 _GLOBAL_CONST signed long ERR_FB_NOT_IMPLEMENTED;
 _GLOBAL_CONST unsigned short ERR_FUB_REDUNDANT;
 _GLOBAL_CONST unsigned short ERR_FUB_BUSY;
 _GLOBAL_CONST unsigned short ERR_FUB_ENABLE_FALSE;
 _GLOBAL_CONST unsigned short ERR_NOTIMPLEMENTED;
 _GLOBAL_CONST unsigned short ERR_OK;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct SFCActionControl
{
	/* VAR_INPUT (analog) */
	plctime T;
	/* VAR (analog) */
	unsigned char S_FF_SET;
	unsigned char S_FF_R1;
	unsigned char S_FF_Q;
	unsigned char dummy1;
	plctime L_TMR_PT;
	plctime L_TMR_ET;
	plctime L_TMR_STAR;
	unsigned char L_TMR_IN;
	unsigned char L_TMR_Q;
	unsigned char L_TMR_M;
	unsigned char dummy2;
	plctime D_TMR_PT;
	plctime D_TMR_ET;
	plctime D_TMR_STAR;
	unsigned char D_TMR_IN;
	unsigned char D_TMR_Q;
	unsigned char D_TMR_M;
	unsigned char dummy3;
	unsigned char P_TRIG_CLK;
	unsigned char P_TRIG_Q;
	unsigned char P_TRIG_M;
	unsigned char dummy4;
	plctime SD_TMR_PT;
	plctime SD_TMR_ET;
	plctime SD_TMR_STA;
	unsigned char SD_TMR_IN;
	unsigned char SD_TMR_Q;
	unsigned char SD_TMR_M;
	unsigned char dummy5;
	unsigned char SD_FF_SET;
	unsigned char SD_FF_R1;
	unsigned char SD_FF_Q;
	unsigned char DS_FF_SET;
	unsigned char DS_FF_R1;
	unsigned char DS_FF_Q;
	plctime DS_TMR_PT;
	plctime DS_TMR_ET;
	plctime DS_TMR_STA;
	unsigned char DS_TMR_IN;
	unsigned char DS_TMR_Q;
	unsigned char DS_TMR_M;
	unsigned char dummy6;
	unsigned char SL_FF_SET;
	unsigned char SL_FF_R1;
	unsigned char SL_FF_Q;
	unsigned char dummy7;
	plctime SL_TMR_PT;
	plctime SL_TMR_ET;
	plctime SL_TMR_STA;
	unsigned char SL_TMR_IN;
	unsigned char SL_TMR_Q;
	unsigned char SL_TMR_M;
	unsigned char dummy8;
	/* VAR_INPUT (digital) */
	plcbit N;
	plcbit R0;
	plcbit S0;
	plcbit L;
	plcbit D;
	plcbit P;
	plcbit SD;
	plcbit DS;
	plcbit SL;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
} SFCActionControl_typ;

typedef struct SFCActionType
{	plcbit x;
	plcbit _x;
	plctime t;
	plctime _t;
	struct SFCActionControl AC;
} SFCActionType;

typedef struct SFCAC2
{
	/* VAR_INPUT (analog) */
	plctime T;
	/* VAR (analog) */
	unsigned char S_FF_SET;
	unsigned char S_FF_R1;
	unsigned char S_FF_Q;
	plctime L_TMR_PT;
	plctime L_TMR_ET;
	plctime L_TMR_STAR;
	unsigned char L_TMR_IN;
	unsigned char L_TMR_Q;
	unsigned char L_TMR_M;
	plctime D_TMR_PT;
	plctime D_TMR_ET;
	plctime D_TMR_STAR;
	unsigned char D_TMR_IN;
	unsigned char D_TMR_Q;
	unsigned char D_TMR_M;
	plctime SD_TMR_PT;
	plctime SD_TMR_ET;
	plctime SD_TMR_STA;
	unsigned char SD_TMR_IN;
	unsigned char SD_TMR_Q;
	unsigned char SD_TMR_M;
	unsigned char SD_FF_SET;
	unsigned char SD_FF_R1;
	unsigned char SD_FF_Q1;
	unsigned char DS_FF_SET;
	unsigned char DS_FF_R1;
	unsigned char DS_FF_Q1;
	plctime DS_TMR_PT;
	plctime DS_TMR_ET;
	plctime DS_TMR_STA;
	unsigned char DS_TMR_IN;
	unsigned char DS_TMR_Q;
	unsigned char DS_TMR_M;
	unsigned char SL_FF_SET;
	unsigned char SL_FF_R1;
	unsigned char SL_FF_Q;
	plctime SL_TMR_PT;
	plctime SL_TMR_ET;
	plctime SL_TMR_STA;
	unsigned char SL_TMR_IN;
	unsigned char SL_TMR_Q;
	unsigned char SL_TMR_M;
	unsigned char P_TRIG_Q;
	unsigned char P_TRIG_M;
	unsigned char Q_TRIG_Q;
	unsigned char Q_TRIG_M;
	unsigned char P1_TRIG_Q;
	unsigned char P1_TRIG_M;
	unsigned char P0_TRIG_Q;
	unsigned char P0_TRIG_M;
	/* VAR_INPUT (digital) */
	plcbit N;
	plcbit R0;
	plcbit S0;
	plcbit L;
	plcbit D;
	plcbit P;
	plcbit P1;
	plcbit P0;
	plcbit SD;
	plcbit DS;
	plcbit SL;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	plcbit A;
} SFCAC2_typ;

typedef struct SFCActionType2
{	plcbit x;
	plcbit _x;
	struct SFCAC2 AC;
} SFCActionType2;

typedef struct SFCActionCType
{	plcbit x;
	plcbit _x;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	struct SFCActionControl AC;
} SFCActionCType;

typedef struct SFCActionCType2
{	plcbit x;
	plcbit _x;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	struct SFCAC2 AC;
} SFCActionCType2;

typedef struct TimerType
{	double ptime;
	double etime;
	double start;
	unsigned char in;
	unsigned char q;
} TimerType;

typedef struct SFCAC3
{
	/* VAR_INPUT (analog) */
	double T;
	double T_ACT;
	/* VAR (analog) */
	struct TimerType L_TMR;
	struct TimerType D_TMR;
	struct TimerType SD_TMR;
	struct TimerType DS_TMR;
	struct TimerType SL_TMR;
	unsigned char S_FF_Q1;
	unsigned char SD_FF_Q1;
	unsigned char DS_FF_Q1;
	unsigned char SL_FF_Q1;
	unsigned char P_R_TRIG_Q;
	unsigned char P_R_TRIG_M;
	unsigned char Q_F_TRIG_Q;
	unsigned char Q_F_TRIG_M;
	unsigned char P1_R_TRIG_Q;
	unsigned char P1_R_TRIG_M;
	unsigned char P0_F_TRIG_Q;
	unsigned char P0_F_TRIG_M;
	/* VAR_INPUT (digital) */
	plcbit N;
	plcbit R0;
	plcbit S0;
	plcbit L;
	plcbit D;
	plcbit P;
	plcbit P1;
	plcbit P0;
	plcbit SD;
	plcbit DS;
	plcbit SL;
	plcbit PAUSE;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	plcbit A;
} SFCAC3_typ;

typedef struct SFCActionCType3
{	double t;
	double _t;
	double tp;
	plcbit x;
	plcbit _x;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	struct SFCAC3 AC;
} SFCActionCType3;

typedef struct SFCStepType
{	plcbit x;
	plctime t;
	plcbit _x;
	plctime _t;
} SFCStepType;

typedef struct SFCStepCType
{	plctime t;
	plctime _t;
	unsigned long inactive_actions;
	unsigned long _inactive_actions;
	unsigned long error_actions;
	plcbit x;
	plcbit _x;
	plcbit x_activate;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	plcbit tip;
	plcbit tip_disable_duration;
	plcbit tip_disable_action;
} SFCStepCType;

typedef struct SFCStepCType3
{	double t;
	double _t;
	double tp;
	unsigned long inactive_actions;
	unsigned long _inactive_actions;
	unsigned long error_actions;
	plcbit x;
	plcbit _x;
	plcbit x_activate;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	plcbit tip;
	plcbit tip_disable_duration;
	plcbit tip_disable_action;
} SFCStepCType3;

typedef struct SFCSimpleStepCType
{	plctime t;
	plctime _t;
	plcbit x;
	plcbit _x;
	plcbit x_activate;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	plcbit tip;
	plcbit tip_disable_duration;
	plcbit tip_disable_action;
} SFCSimpleStepCType;

typedef struct SFCSimpleStepCType3
{	double t;
	double _t;
	double tp;
	plcbit x;
	plcbit _x;
	plcbit x_activate;
	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
	plcbit error;
	plcbit tip;
	plcbit tip_disable_duration;
	plcbit tip_disable_action;
} SFCSimpleStepCType3;

typedef struct SFCTransitionCType
{	plcbit force;
	plcbit _force;
	plcbit active;
	plcbit _active;
} SFCTransitionCType;

typedef struct ArFBStateInternalType
{	unsigned long ExecuteRef;
	unsigned long BusyRef;
	unsigned long DoneRef;
	unsigned long ErrorRef;
	unsigned long ActiveRef;
	unsigned long StatusRef;
	unsigned long FBCyclic;
	unsigned long AsyfumaState;
	unsigned long FBResetOut;
	unsigned long Argument;
	unsigned long State;
	plcbit ExecutePrev;
} ArFBStateInternalType;

typedef struct ArFBAsyFuMaInternalType
{	unsigned short State;
	signed long Result;
} ArFBAsyFuMaInternalType;

typedef struct r_trig
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} r_trig_typ;

typedef struct f_trig
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} f_trig_typ;

typedef struct rf_trig
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} rf_trig_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void r_trig(struct r_trig* inst);
_BUR_PUBLIC void f_trig(struct f_trig* inst);
_BUR_PUBLIC void rf_trig(struct rf_trig* inst);
_BUR_PUBLIC void SFCActionControl(struct SFCActionControl* inst);
_BUR_PUBLIC void SFCAC2(struct SFCAC2* inst);
_BUR_PUBLIC void SFCAC3(struct SFCAC3* inst);
_BUR_PUBLIC plctime GetTime(void);
_BUR_PUBLIC double RealTan(double x);
_BUR_PUBLIC double RealAtan(double x);
_BUR_PUBLIC double RealAsin(double x);
_BUR_PUBLIC double RealAcos(double x);
_BUR_PUBLIC double RealExp(double x);
_BUR_PUBLIC double RealLn(double x);
_BUR_PUBLIC double RealLog(double x);
_BUR_PUBLIC double RealExpt(double x, double y);
_BUR_PUBLIC double RealAbs(double x);
_BUR_PUBLIC double RealSin(double x);
_BUR_PUBLIC double RealCos(double x);
_BUR_PUBLIC double RealSqrt(double x);


#ifdef __cplusplus
};
#endif
#endif /* _RUNTIME_ */

