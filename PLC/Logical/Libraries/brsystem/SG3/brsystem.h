/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BRSYSTEM_
#define _BRSYSTEM_
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
 #define brX2X 10U
 #define brPP 255U
 #define brCPU 1U
 #define brKEY 8U
 #define brDRAM 0U
 #define br2003 2U
 #define br2005 1U
 #define br2010 0U
 #define brC200 9U
 #define brC300 8U
 #define brADDON 7U
 #define brPANEL 6U
 #define brGLOBAL_REMANENT_PV 5U
 #define brLOCAL_REMANENT_PV 4U
 #define brUSRROM 3U
 #define brSYSROM 2U
 #define brUSRRAM 1U
 #define brACOPOS 7U
 #define brCAN_IO 5U
 #define brBASE_IO 3U
 #define brPRODUCT 0U
 #define brETHER_IO 6U
 #define brNO_FAMILY 255U
 #define brREMOTE_IO 4U
 #define brBATTERY_OK 1U
 #define brPOWERPANEL 5U
 #define brBATTERY_LOW 0U
 #define brLOGICSCANNER 3U
 #define brPLUGIN_MODULE 10U
 #define brSYSTEM_MODULE 2U
 #define brBATTERY_NOTEST 2U
 #define TARGET_BIG_ENDIAN 2U
 #define brBATTERY_MISSING 3U
 #define INIT_REASON_UNKNOWN (-1)
 #define INIT_REASON_DOWNLOAD 3
 #define TARGET_LITTLE_ENDIAN 1U
 #define brAUTOMATION_RUNTIME 4U
 #define brERR_INVALID_DEVICE 27250U
 #define INIT_REASON_COLDSTART 2
 #define INIT_REASON_WARMSTART 1
 #define brSYSCONF_SET_VOLATILE 0
 #define brERR_INVALID_PARAMETER 27251U
 #define brSYSCONF_SET_NON_VOLATILE 1
#else
 _IEC_CONST unsigned char brX2X = 10U;
 _IEC_CONST unsigned char brPP = 255U;
 _IEC_CONST unsigned char brCPU = 1U;
 _IEC_CONST unsigned char brKEY = 8U;
 _IEC_CONST unsigned long brDRAM = 0U;
 _IEC_CONST unsigned char br2003 = 2U;
 _IEC_CONST unsigned char br2005 = 1U;
 _IEC_CONST unsigned char br2010 = 0U;
 _IEC_CONST unsigned char brC200 = 9U;
 _IEC_CONST unsigned char brC300 = 8U;
 _IEC_CONST unsigned char brADDON = 7U;
 _IEC_CONST unsigned char brPANEL = 6U;
 _IEC_CONST unsigned long brGLOBAL_REMANENT_PV = 5U;
 _IEC_CONST unsigned long brLOCAL_REMANENT_PV = 4U;
 _IEC_CONST unsigned long brUSRROM = 3U;
 _IEC_CONST unsigned long brSYSROM = 2U;
 _IEC_CONST unsigned long brUSRRAM = 1U;
 _IEC_CONST unsigned char brACOPOS = 7U;
 _IEC_CONST unsigned char brCAN_IO = 5U;
 _IEC_CONST unsigned char brBASE_IO = 3U;
 _IEC_CONST unsigned char brPRODUCT = 0U;
 _IEC_CONST unsigned char brETHER_IO = 6U;
 _IEC_CONST unsigned char brNO_FAMILY = 255U;
 _IEC_CONST unsigned char brREMOTE_IO = 4U;
 _IEC_CONST unsigned char brBATTERY_OK = 1U;
 _IEC_CONST unsigned char brPOWERPANEL = 5U;
 _IEC_CONST unsigned char brBATTERY_LOW = 0U;
 _IEC_CONST unsigned char brLOGICSCANNER = 3U;
 _IEC_CONST unsigned char brPLUGIN_MODULE = 10U;
 _IEC_CONST unsigned char brSYSTEM_MODULE = 2U;
 _IEC_CONST unsigned char brBATTERY_NOTEST = 2U;
 _IEC_CONST unsigned char TARGET_BIG_ENDIAN = 2U;
 _IEC_CONST unsigned char brBATTERY_MISSING = 3U;
 _IEC_CONST signed char INIT_REASON_UNKNOWN = -1;
 _IEC_CONST signed char INIT_REASON_DOWNLOAD = 3;
 _IEC_CONST unsigned char TARGET_LITTLE_ENDIAN = 1U;
 _IEC_CONST unsigned char brAUTOMATION_RUNTIME = 4U;
 _IEC_CONST unsigned short brERR_INVALID_DEVICE = 27250U;
 _IEC_CONST signed char INIT_REASON_COLDSTART = 2;
 _IEC_CONST signed char INIT_REASON_WARMSTART = 1;
 _IEC_CONST plcbit brSYSCONF_SET_VOLATILE = 0;
 _IEC_CONST unsigned short brERR_INVALID_PARAMETER = 27251U;
 _IEC_CONST plcbit brSYSCONF_SET_NON_VOLATILE = 1;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct MEMInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long FreeUSR_Ram;
	unsigned long FreeSYSTEM;
	unsigned long FreeUSR_Prom;
	unsigned long FreeSYS_Prom;
	unsigned long FreeFIX_Ram;
	unsigned long FreeTMP_Ram;
	unsigned long FreeMEMCARD;
	/* VAR_INPUT (digital) */
	plcbit enable;
} MEMInfo_typ;

typedef struct SysInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned char init_reason;
	unsigned char init_count;
	unsigned long tick_count;
	unsigned long version;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SysInfo_typ;

typedef struct RTInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long cycle_time;
	signed char init_reason;
	signed char task_class;
	/* VAR_INPUT (digital) */
	plcbit enable;
} RTInfo_typ;

typedef struct TARGETInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pOSVersion;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char DataFormat;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TARGETInfo_typ;

typedef struct HWInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char family;
	unsigned char usetype;
	unsigned long module_typ;
	unsigned char master_no;
	unsigned char slave_no;
	unsigned char module_adr;
	unsigned char slot_no;
	/* VAR (analog) */
	unsigned long next_vw_p;
	unsigned long last_modul_p;
	unsigned long next_entry_p;
	unsigned char next_entry_ix;
	unsigned char next_slot_ix;
	unsigned char last_rio_master;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit first;
} HWInfo_typ;

typedef struct BatteryInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char state;
	/* VAR_INPUT (digital) */
	plcbit enable;
} BatteryInfo_typ;

typedef struct EXCInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long task_class;
	unsigned long task_ident;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EXCInfo_typ;

typedef struct ZYKVLenable
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit mode;
} ZYKVLenable_typ;

typedef struct PMemGet
{
	/* VAR_INPUT (analog) */
	unsigned long offset;
	unsigned long len;
	unsigned long adress;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PMemGet_typ;

typedef struct PMemPut
{
	/* VAR_INPUT (analog) */
	unsigned long offset;
	unsigned long len;
	unsigned long adress;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PMemPut_typ;

typedef struct PMemSize
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long size;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PMemSize_typ;



/* Prototyping of functions and function blocks */
void MEMInfo(struct MEMInfo* inst);
void SysInfo(struct SysInfo* inst);
void RTInfo(struct RTInfo* inst);
void TARGETInfo(struct TARGETInfo* inst);
void HWInfo(struct HWInfo* inst);
void BatteryInfo(struct BatteryInfo* inst);
void EXCInfo(struct EXCInfo* inst);
void ZYKVLenable(struct ZYKVLenable* inst);
void PMemGet(struct PMemGet* inst);
void PMemPut(struct PMemPut* inst);
void PMemSize(struct PMemSize* inst);


#ifdef __cplusplus
};
#endif
#endif /* _BRSYSTEM_ */

                                                           
