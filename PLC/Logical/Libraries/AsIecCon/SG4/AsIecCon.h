/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASIECCON_
#define _ASIECCON_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif



/* Prototyping of functions and function blocks */
_BUR_PUBLIC signed short H_TO_NINT(signed short IN);
_BUR_PUBLIC unsigned short H_TO_NUINT(unsigned short IN);
_BUR_PUBLIC signed long H_TO_NDINT(signed long IN);
_BUR_PUBLIC unsigned long H_TO_NUDINT(unsigned long IN);
_BUR_PUBLIC float H_TO_NREAL(float IN);
_BUR_PUBLIC double H_TO_NLREAL(double IN);
_BUR_PUBLIC plctime H_TO_NTIME(plctime IN);
_BUR_PUBLIC DATE_AND_TIME H_TO_NDT(DATE_AND_TIME IN);
_BUR_PUBLIC DATE H_TO_NDATE(DATE IN);
_BUR_PUBLIC TOD H_TO_NTOD(TOD IN);
_BUR_PUBLIC signed short N_TO_HINT(signed short IN);
_BUR_PUBLIC unsigned short N_TO_HUINT(unsigned short IN);
_BUR_PUBLIC signed long N_TO_HDINT(signed long IN);
_BUR_PUBLIC unsigned long N_TO_HUDINT(unsigned long IN);
_BUR_PUBLIC float N_TO_HREAL(float IN);
_BUR_PUBLIC double N_TO_HLREAL(double IN);
_BUR_PUBLIC plctime N_TO_HTIME(plctime IN);
_BUR_PUBLIC DATE_AND_TIME N_TO_HDT(DATE_AND_TIME IN);
_BUR_PUBLIC DATE N_TO_HDATE(DATE IN);
_BUR_PUBLIC TOD N_TO_HTOD(TOD IN);
_BUR_PUBLIC signed short swapINT(signed short IN);
_BUR_PUBLIC unsigned short swapUINT(unsigned short IN);
_BUR_PUBLIC WORD swapWORD(WORD IN);
_BUR_PUBLIC signed long swapDINT(signed long IN);
_BUR_PUBLIC unsigned long swapUDINT(unsigned long IN);
_BUR_PUBLIC DWORD swapDWORD(DWORD IN);
_BUR_PUBLIC TIME swapTIME(TIME IN);
_BUR_PUBLIC DATE_AND_TIME swapDT(DATE_AND_TIME IN);
_BUR_PUBLIC DATE swapDATE(DATE IN);
_BUR_PUBLIC TOD swapTOD(TOD IN);
_BUR_PUBLIC float swapREAL(float IN);
_BUR_PUBLIC double swapLREAL(double IN);

/* The interface declarations of the AsIecCon functions are not included here
 * because they are inline in IEC languages. The x_TO_STRING and the
 * STRING_TO_x functions are not available for C programms. */

#ifdef __cplusplus
};
#endif
#endif /* _ASIECCON_ */

