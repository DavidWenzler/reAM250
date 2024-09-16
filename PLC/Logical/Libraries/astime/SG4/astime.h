/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASTIME_
#define _ASTIME_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define timERR_AR 33213U
 #define timERR_INVALID_DTSTRUCTURE 33212U
 #define timERR_INVALID_LEN 33211U
 #define timERR_INVALID_PARAMETER 33210U
 #define timREDUND_INTERFACE 3U
 #define timTIME_SERVER 2U
 #define timREAL_TIME_CLOCK 1U
 #define timNO_DST 3U
 #define timDAYLIGHT_SAVING_TIME 2U
 #define timNORMAL_TIME 1U
 #define TIME_MAX 2073600000
 #define TIME_MIN (-2073600000)
 #define DATE_AND_TIME_MAX 4102444799U
 #define timEXSETTIME_NO_OPTION 0U
 #define timEXSETTIME_NO_LOGENTRY 1U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short timERR_AR;
 _GLOBAL_CONST unsigned short timERR_INVALID_DTSTRUCTURE;
 _GLOBAL_CONST unsigned short timERR_INVALID_LEN;
 _GLOBAL_CONST unsigned short timERR_INVALID_PARAMETER;
 _GLOBAL_CONST unsigned char timREDUND_INTERFACE;
 _GLOBAL_CONST unsigned char timTIME_SERVER;
 _GLOBAL_CONST unsigned char timREAL_TIME_CLOCK;
 _GLOBAL_CONST unsigned char timNO_DST;
 _GLOBAL_CONST unsigned char timDAYLIGHT_SAVING_TIME;
 _GLOBAL_CONST unsigned char timNORMAL_TIME;
 _GLOBAL_CONST signed long TIME_MAX;
 _GLOBAL_CONST signed long TIME_MIN;
 _GLOBAL_CONST unsigned long DATE_AND_TIME_MAX;
 _GLOBAL_CONST unsigned char timEXSETTIME_NO_OPTION;
 _GLOBAL_CONST unsigned char timEXSETTIME_NO_LOGENTRY;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct TIMEStructure
{	signed char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned short millisec;
	unsigned short microsec;
} TIMEStructure;

typedef struct DTStructure
{	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char wday;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned short millisec;
	unsigned short microsec;
} DTStructure;

typedef struct DTExSetTime
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	unsigned char Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTExSetTime_typ;

typedef struct DTSetTime
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTSetTime_typ;

typedef struct DTGetTime
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	plcdt DT1;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTGetTime_typ;

typedef struct UtcDTGetTime
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	plcdt DT1;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTGetTime_typ;

typedef struct UtcDTSetTime
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTSetTime_typ;

typedef struct UtcDTExSetTime
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	unsigned char Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTExSetTime_typ;

typedef struct DTStructureGetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTStructureGetTime_typ;

typedef struct DTStructureSetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTStructureSetTime_typ;

typedef struct DTStructureExSetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	unsigned char Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DTStructureExSetTime_typ;

typedef struct UtcDTStructureGetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTStructureGetTime_typ;

typedef struct UtcDTStructureSetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTStructureSetTime_typ;

typedef struct UtcDTStructureExSetTime
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	unsigned char Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTStructureExSetTime_typ;

typedef struct UtcDT_TO_LocalDTStructure
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDT_TO_LocalDTStructure_typ;

typedef struct LocalDT_TO_UtcDTStructure
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LocalDT_TO_UtcDTStructure_typ;

typedef struct UtcDTStructure_TO_LocalDT
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	plcdt DT1;
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UtcDTStructure_TO_LocalDT_typ;

typedef struct LocalDTStructure_TO_UtcDT
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	plcdt DT1;
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LocalDTStructure_TO_UtcDT_typ;

typedef struct TimeDeviceGetInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pServer;
	unsigned char len;
	/* VAR_OUTPUT (analog) */
	unsigned char timeDevice;
	float avgDeviation;
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TimeDeviceGetInfo_typ;

typedef struct DstGetInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pDTStructure;
	/* VAR_OUTPUT (analog) */
	unsigned char dstState;
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DstGetInfo_typ;

typedef struct DstGetInfoDT
{
	/* VAR_INPUT (analog) */
	plcdt DT1;
	/* VAR_OUTPUT (analog) */
	unsigned char dstState;
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DstGetInfoDT_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void DTExSetTime(struct DTExSetTime* inst);
_BUR_PUBLIC void DTSetTime(struct DTSetTime* inst);
_BUR_PUBLIC void DTGetTime(struct DTGetTime* inst);
_BUR_PUBLIC void UtcDTGetTime(struct UtcDTGetTime* inst);
_BUR_PUBLIC void UtcDTSetTime(struct UtcDTSetTime* inst);
_BUR_PUBLIC void UtcDTExSetTime(struct UtcDTExSetTime* inst);
_BUR_PUBLIC void DTStructureGetTime(struct DTStructureGetTime* inst);
_BUR_PUBLIC void DTStructureSetTime(struct DTStructureSetTime* inst);
_BUR_PUBLIC void DTStructureExSetTime(struct DTStructureExSetTime* inst);
_BUR_PUBLIC void UtcDTStructureGetTime(struct UtcDTStructureGetTime* inst);
_BUR_PUBLIC void UtcDTStructureSetTime(struct UtcDTStructureSetTime* inst);
_BUR_PUBLIC void UtcDTStructureExSetTime(struct UtcDTStructureExSetTime* inst);
_BUR_PUBLIC void UtcDT_TO_LocalDTStructure(struct UtcDT_TO_LocalDTStructure* inst);
_BUR_PUBLIC void LocalDT_TO_UtcDTStructure(struct LocalDT_TO_UtcDTStructure* inst);
_BUR_PUBLIC void UtcDTStructure_TO_LocalDT(struct UtcDTStructure_TO_LocalDT* inst);
_BUR_PUBLIC void LocalDTStructure_TO_UtcDT(struct LocalDTStructure_TO_UtcDT* inst);
_BUR_PUBLIC void TimeDeviceGetInfo(struct TimeDeviceGetInfo* inst);
_BUR_PUBLIC void DstGetInfo(struct DstGetInfo* inst);
_BUR_PUBLIC void DstGetInfoDT(struct DstGetInfoDT* inst);
_BUR_PUBLIC plctime clock_ms(void);
_BUR_PUBLIC unsigned long ascTIMEStructure(unsigned long pTIMEStructure, unsigned long pStr, unsigned long len);
_BUR_PUBLIC unsigned long ascDTStructure(unsigned long pDTStructure, unsigned long pStr, unsigned long len);
_BUR_PUBLIC unsigned long ascTIME(plctime TIME1, unsigned long pStr, unsigned long len);
_BUR_PUBLIC unsigned long ascDT(plcdt DT1, unsigned long pStr, unsigned long len);
_BUR_PUBLIC plctime TIMEStructure_TO_TIME(unsigned long pTIMEStructure);
_BUR_PUBLIC unsigned long TIME_TO_TIMEStructure(plctime TIME1, unsigned long pTIMEStructure);
_BUR_PUBLIC plcdt DTStructure_TO_DT(unsigned long pDTStructure);
_BUR_PUBLIC unsigned long DT_TO_DTStructure(plcdt DT1, unsigned long pDTStructure);
_BUR_PUBLIC unsigned long DiffT(plctime TIME2, plctime TIME1);
_BUR_PUBLIC unsigned long DiffDT(plcdt DT2, plcdt DT1);


#ifdef __cplusplus
};
#endif
#endif /* _ASTIME_ */

