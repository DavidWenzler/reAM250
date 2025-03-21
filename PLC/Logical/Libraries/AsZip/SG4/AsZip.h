/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASZIP_
#define _ASZIP_
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
 #define zipERR_FILE_WRITE_ERROR 38066U
 #define zipERR_FILE_NOT_FOUND 38065U
 #define zipERR_SPACE 38064U
 #define zipERR_INTERNAL_ERROR 38063U
 #define zipERR_UNSUPPORTED_EXTENSION 38062U
 #define zipERR_INVALID_DEVICE 38061U
 #define zipERR_NULLPOINTER 38060U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short zipERR_FILE_WRITE_ERROR;
 _GLOBAL_CONST unsigned short zipERR_FILE_NOT_FOUND;
 _GLOBAL_CONST unsigned short zipERR_SPACE;
 _GLOBAL_CONST unsigned short zipERR_INTERNAL_ERROR;
 _GLOBAL_CONST unsigned short zipERR_UNSUPPORTED_EXTENSION;
 _GLOBAL_CONST unsigned short zipERR_INVALID_DEVICE;
 _GLOBAL_CONST unsigned short zipERR_NULLPOINTER;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct zipArchive
{
	/* VAR_INPUT (analog) */
	unsigned long pArchiveDevice;
	unsigned long pArchiveFile;
	unsigned long pSrcDevice;
	unsigned long pSrcFile;
	unsigned long pOptions;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} zipArchive_typ;

typedef struct zipExtract
{
	/* VAR_INPUT (analog) */
	unsigned long pArchiveDevice;
	unsigned long pArchiveFile;
	unsigned long pOutDevice;
	unsigned long pOutFolder;
	unsigned long pOptions;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} zipExtract_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void zipArchive(struct zipArchive* inst);
_BUR_PUBLIC void zipExtract(struct zipExtract* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASZIP_ */

