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

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define brWINDOWS_BLUESCREEN 1U
 #define brWINDOWS_OK 0U
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
 #define brERR_NON_CYCLIC_CONTEXT 27252U
 #define brSYSCONF_SET_NON_VOLATILE 1
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned long brWINDOWS_BLUESCREEN;
 _GLOBAL_CONST unsigned long brWINDOWS_OK;
 _GLOBAL_CONST unsigned char brX2X;
 _GLOBAL_CONST unsigned char brPP;
 _GLOBAL_CONST unsigned char brCPU;
 _GLOBAL_CONST unsigned char brKEY;
 _GLOBAL_CONST unsigned long brDRAM;
 _GLOBAL_CONST unsigned char br2003;
 _GLOBAL_CONST unsigned char br2005;
 _GLOBAL_CONST unsigned char br2010;
 _GLOBAL_CONST unsigned char brC200;
 _GLOBAL_CONST unsigned char brC300;
 _GLOBAL_CONST unsigned char brADDON;
 _GLOBAL_CONST unsigned char brPANEL;
 _GLOBAL_CONST unsigned long brGLOBAL_REMANENT_PV;
 _GLOBAL_CONST unsigned long brLOCAL_REMANENT_PV;
 _GLOBAL_CONST unsigned long brUSRROM;
 _GLOBAL_CONST unsigned long brSYSROM;
 _GLOBAL_CONST unsigned long brUSRRAM;
 _GLOBAL_CONST unsigned char brACOPOS;
 _GLOBAL_CONST unsigned char brCAN_IO;
 _GLOBAL_CONST unsigned char brBASE_IO;
 _GLOBAL_CONST unsigned char brPRODUCT;
 _GLOBAL_CONST unsigned char brETHER_IO;
 _GLOBAL_CONST unsigned char brNO_FAMILY;
 _GLOBAL_CONST unsigned char brREMOTE_IO;
 _GLOBAL_CONST unsigned char brBATTERY_OK;
 _GLOBAL_CONST unsigned char brPOWERPANEL;
 _GLOBAL_CONST unsigned char brBATTERY_LOW;
 _GLOBAL_CONST unsigned char brLOGICSCANNER;
 _GLOBAL_CONST unsigned char brPLUGIN_MODULE;
 _GLOBAL_CONST unsigned char brSYSTEM_MODULE;
 _GLOBAL_CONST unsigned char brBATTERY_NOTEST;
 _GLOBAL_CONST unsigned char TARGET_BIG_ENDIAN;
 _GLOBAL_CONST unsigned char brBATTERY_MISSING;
 _GLOBAL_CONST signed char INIT_REASON_UNKNOWN;
 _GLOBAL_CONST signed char INIT_REASON_DOWNLOAD;
 _GLOBAL_CONST unsigned char TARGET_LITTLE_ENDIAN;
 _GLOBAL_CONST unsigned char brAUTOMATION_RUNTIME;
 _GLOBAL_CONST unsigned short brERR_INVALID_DEVICE;
 _GLOBAL_CONST signed char INIT_REASON_COLDSTART;
 _GLOBAL_CONST signed char INIT_REASON_WARMSTART;
 _GLOBAL_CONST plcbit brSYSCONF_SET_VOLATILE;
 _GLOBAL_CONST unsigned short brERR_INVALID_PARAMETER;
 _GLOBAL_CONST unsigned short brERR_NON_CYCLIC_CONTEXT;
 _GLOBAL_CONST plcbit brSYSCONF_SET_NON_VOLATILE;
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

typedef struct MEMxInfo
{
	/* VAR_INPUT (analog) */
	unsigned long mem_typ;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long MemSize;
	unsigned long FreeMemSize;
	unsigned long BiggestFreeBlockSize;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} MEMxInfo_typ;

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

typedef struct SysconfInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pEntry;
	unsigned long pValue;
	unsigned long value_len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SysconfInfo_typ;

typedef struct SysconfSet
{
	/* VAR_INPUT (analog) */
	unsigned long pEntry;
	unsigned long pNewValue;
	unsigned char option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SysconfSet_typ;

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

typedef struct ARwinWindowsInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long windowsStatus;
	/* VAR_INPUT (digital) */
	plcbit enable;
} ARwinWindowsInfo_typ;

typedef struct ARwinEthWinInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	plcstring IPAddr[16];
	plcstring SubnetMask[16];
	plcbyte MacAddr[6];
	/* VAR_INPUT (digital) */
	plcbit enable;
} ARwinEthWinInfo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MEMInfo(struct MEMInfo* inst);
_BUR_PUBLIC void MEMxInfo(struct MEMxInfo* inst);
_BUR_PUBLIC void SysInfo(struct SysInfo* inst);
_BUR_PUBLIC void RTInfo(struct RTInfo* inst);
_BUR_PUBLIC void TARGETInfo(struct TARGETInfo* inst);
_BUR_PUBLIC void HWInfo(struct HWInfo* inst);
_BUR_PUBLIC void SysconfInfo(struct SysconfInfo* inst);
_BUR_PUBLIC void SysconfSet(struct SysconfSet* inst);
_BUR_PUBLIC void BatteryInfo(struct BatteryInfo* inst);
_BUR_PUBLIC void EXCInfo(struct EXCInfo* inst);
_BUR_PUBLIC void ZYKVLenable(struct ZYKVLenable* inst);
_BUR_PUBLIC void PMemGet(struct PMemGet* inst);
_BUR_PUBLIC void PMemPut(struct PMemPut* inst);
_BUR_PUBLIC void PMemSize(struct PMemSize* inst);
_BUR_PUBLIC void ARwinWindowsInfo(struct ARwinWindowsInfo* inst);
_BUR_PUBLIC void ARwinEthWinInfo(struct ARwinEthWinInfo* inst);
_BUR_PUBLIC unsigned long RTTolerance(void);
_BUR_PUBLIC plcbit RTCyclic(void);
_BUR_PUBLIC plcbit RTInit(void);
_BUR_PUBLIC plcbit RTExit(void);


#ifdef __cplusplus
};
#endif
#endif /* _BRSYSTEM_ */

