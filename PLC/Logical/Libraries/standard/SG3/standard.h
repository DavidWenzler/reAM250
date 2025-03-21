/* Automation Studio Generated Header File, Format Version 1.00 */
/* do not change */
#ifndef STANDARD_H_
#define STANDARD_H_
#ifdef __cplusplus
extern "C" {
#endif
                                           

#include <bur/plc.h>

#define TP_10mstyp	TP_10ms_typ
#define TOF_10mstyp	TOF_10ms_typ
#define TON_10mstyp	TON_10ms_typ
#define TPtyp		TP_typ
#define TOFtyp		TOF_typ
#define TONtyp		TON_typ
#define SEMAtyp		SEMA_typ
#define RStyp		RS_typ
#define SRtyp		SR_typ
#define R_TRIGtyp	R_TRIG_typ
#define F_TRIGtyp	F_TRIG_typ
#define CTUtyp		CTU_typ
#define CTDtyp		CTD_typ
#define CTUDtyp		CTUD_typ
#define RF_TRIGtyp	RF_TRIG_typ

/* Constants */


/* Datatypes */


/* Datatypes of function blocks */
typedef struct TP_10ms
{
	/* VAR_INPUT (analogous) */
	unsigned long PT;
	/* VAR_OUTPUT (analogous) */
	unsigned long ET;
	/* VAR (analogous) */
	unsigned long StartTime;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
} TP_10ms_typ;

typedef struct TOF_10ms
{
	/* VAR_INPUT (analogous) */
	unsigned long PT;
	/* VAR_OUTPUT (analogous) */
	unsigned long ET;
	/* VAR (analogous) */
	unsigned long StartTime;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} TOF_10ms_typ;

typedef struct TON_10ms
{
	/* VAR_INPUT (analogous) */
	unsigned long PT;
	/* VAR_OUTPUT (analogous) */
	unsigned long ET;
	/* VAR (analogous) */
	unsigned long StartTime;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} TON_10ms_typ;

typedef struct TP
{
	/* VAR_INPUT (analogous) */
	plctime PT;
	/* VAR_OUTPUT (analogous) */
	plctime ET;
	/* VAR (analogous) */
	plctime StartTime;
	unsigned long Restart;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
} TP_typ;

typedef struct TOF
{
	/* VAR_INPUT (analogous) */
	plctime PT;
	/* VAR_OUTPUT (analogous) */
	plctime ET;
	/* VAR (analogous) */
	plctime StartTime;
	unsigned long Restart;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} TOF_typ;

typedef struct TON
{
	/* VAR_INPUT (analogous) */
	plctime PT;
	/* VAR_OUTPUT (analogous) */
	plctime ET;
	/* VAR (analogous) */
	plctime StartTime;
	unsigned long Restart;
	/* VAR_INPUT (digital) */
	plcbit IN;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} TON_typ;

typedef struct SEMA
{
	/* VAR_INPUT (digital) */
	plcbit CLAIM;
	plcbit RELEASE;
	/* VAR_OUTPUT (digital) */
	plcbit BUSY;
	/* VAR (digital) */
	plcbit X;
} SEMA_typ;

typedef struct RS
{
	/* VAR_INPUT (digital) */
	plcbit SET;
	plcbit RESET1;
	/* VAR_OUTPUT (digital) */
	plcbit Q1;
} RS_typ;

typedef struct SR
{
	/* VAR_INPUT (digital) */
	plcbit SET1;
	plcbit RESET;
	/* VAR_OUTPUT (digital) */
	plcbit Q1;
} SR_typ;

typedef struct R_TRIG
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} R_TRIG_typ;

typedef struct F_TRIG
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} F_TRIG_typ;

typedef struct CTU
{
	/* VAR_INPUT (analogous) */
	unsigned short PV;
	/* VAR_OUTPUT (analogous) */
	unsigned short CV;
	/* VAR_INPUT (digital) */
	plcbit CU;
	plcbit RESET;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} CTU_typ;

typedef struct CTD
{
	/* VAR_INPUT (analogous) */
	unsigned short PV;
	/* VAR_OUTPUT (analogous) */
	unsigned short CV;
	/* VAR_INPUT (digital) */
	plcbit CD;
	plcbit LOAD;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} CTD_typ;

typedef struct CTUD
{
	/* VAR_INPUT (analogous) */
	signed short PV;
	/* VAR_OUTPUT (analogous) */
	signed short CV;
	/* VAR_INPUT (digital) */
	plcbit CU;
	plcbit CD;
	plcbit RESET;
	plcbit LOAD;
	/* VAR_OUTPUT (digital) */
	plcbit QU;
	plcbit QD;
	/* VAR (digital) */
	plcbit MU;
	plcbit MD;
} CTUD_typ;

typedef struct RF_TRIG
{
	/* VAR_INPUT (digital) */
	plcbit CLK;
	/* VAR_OUTPUT (digital) */
	plcbit Q;
	/* VAR (digital) */
	plcbit M;
} RF_TRIG_typ;



/* Prototyping of functions and function blocks */
void TP_10ms(TP_10ms_typ* inst);
void TOF_10ms(TOF_10ms_typ* inst);
void TON_10ms(TON_10ms_typ* inst);
void TP(TP_typ* inst);
void TOF(TOF_typ* inst);
void TON(TON_typ* inst);
void SEMA(SEMA_typ* inst);
void RS(RS_typ* inst);
void SR(SR_typ* inst);
void R_TRIG(R_TRIG_typ* inst);
void F_TRIG(F_TRIG_typ* inst);
void CTU(CTU_typ* inst);
void CTD(CTD_typ* inst);
void CTUD(CTUD_typ* inst);
void RF_TRIG(RF_TRIG_typ* inst);


#ifdef __cplusplus
};
#endif
#endif /* STANDARD_H_ */

