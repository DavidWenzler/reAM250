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

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define timERR_AR 33213U
 #define timERR_INVALID_DTSTRUCTURE 33212U
 #define timERR_INVALID_LEN 33211U
 #define timERR_INVALID_PARAMETER 33210U
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
 _IEC_CONST unsigned short timERR_AR = 33213U;
 _IEC_CONST unsigned short timERR_INVALID_DTSTRUCTURE = 33212U;
 _IEC_CONST unsigned short timERR_INVALID_LEN = 33211U;
 _IEC_CONST unsigned short timERR_INVALID_PARAMETER = 33210U;
 _IEC_CONST unsigned char timTIME_SERVER = 2U;
 _IEC_CONST unsigned char timREAL_TIME_CLOCK = 1U;
 _IEC_CONST unsigned char timNO_DST = 3U;
 _IEC_CONST unsigned char timDAYLIGHT_SAVING_TIME = 2U;
 _IEC_CONST unsigned char timNORMAL_TIME = 1U;
 _IEC_CONST signed long TIME_MAX = 2073600000;
 _IEC_CONST signed long TIME_MIN = -2073600000;
 _IEC_CONST unsigned long DATE_AND_TIME_MAX = 4102444799U;
 _IEC_CONST unsigned char timEXSETTIME_NO_OPTION = 0U;
 _IEC_CONST unsigned char timEXSETTIME_NO_LOGENTRY = 1U;
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



/* Prototyping of functions and function blocks */
void DTExSetTime(struct DTExSetTime* inst);
void DTSetTime(struct DTSetTime* inst);
void DTGetTime(struct DTGetTime* inst);
unsigned long ascTIMEStructure(unsigned long pTIMEStructure, unsigned long pStr, unsigned long len);
unsigned long ascDTStructure(unsigned long pDTStructure, unsigned long pStr, unsigned long len);
unsigned long ascTIME(plctime TIME1, unsigned long pStr, unsigned long len);
unsigned long ascDT(plcdt DT1, unsigned long pStr, unsigned long len);
plctime TIMEStructure_TO_TIME(unsigned long pTIMEStructure);
unsigned long TIME_TO_TIMEStructure(plctime TIME1, unsigned long pTIMEStructure);
plcdt DTStructure_TO_DT(unsigned long pDTStructure);
unsigned long DT_TO_DTStructure(plcdt DT1, unsigned long pDTStructure);
unsigned long DiffT(plctime TIME2, plctime TIME1);
unsigned long DiffDT(plcdt DT2, plcdt DT1);


#ifdef __cplusplus
};
#endif
#endif /* _ASTIME_ */

                                                           
