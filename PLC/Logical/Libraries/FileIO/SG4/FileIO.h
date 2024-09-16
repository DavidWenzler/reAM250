/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _FILEIO_
#define _FILEIO_
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
 #define SET_RECURSIVE 1U
 #define FILE_RW 2U
 #define FILE_W 1U
 #define FILE_R 0U
 #define FILE_OW_ONCE 3U
 #define FILE_OW_DETMEM 2U
 #define FILE_DETMEM 1U
 #define FILE_ONCE 0U
 #define FILE_FILE 0U
 #define FILE_DIR 1U
 #define FILE_ALL 2U
 #define DIR_OW 1U
 #define ATTR_VOL_LABEL 8U
 #define ATTR_SYSTEM 4U
 #define ATTR_RDONLY 1U
 #define ATTR_HIDDEN 2U
 #define ATTR_DIRECTORY 16U
 #define ATTR_ARCHIVE 32U
 #define fiERR_SYSTEM 20799U
 #define fiERR_DEVICE_MANAGER 20798U
 #define fiERR_DEVICE_DRIVER 20797U
 #define fiERR_INIT 20796U
 #define fiERR_NETIO_PARAMETERS 20736U
 #define fiERR_INVALID_NBYTES 20735U
 #define fiERR_NETIO_USER 20734U
 #define fiERR_NETIO_PORT 20733U
 #define fiERR_NETIO_IP_UNEQUAL 20732U
 #define fiERR_DEVICE_INVALID_HANDLE 20731U
 #define fiERR_DEVICE_ALREADY_EXIST 20730U
 #define fiERR_PARAMETER 20729U
 #define fiERR_DIR_INVALID_HANDLE 20728U
 #define fiERR_NOT_ENOUGH_FREEMEM 20727U
 #define fiERR_DETMEMINFO 20726U
 #define fiERR_DIR_ALREADY_EXIST 20725U
 #define fiERR_DIR_NOT_EMPTY 20724U
 #define fiERR_DIR_NOT_EXIST 20723U
 #define fiERR_INVALID_DIRECTORY 20722U
 #define fiERR_FILE_NOT_OPENED 20721U
 #define fiERR_ASYNC_MANAGER 20720U
 #define fiERR_DATA 20719U
 #define fiERR_COM_FILE_IOCTL 20718U
 #define fiERR_COM_FILE_WRITE 20717U
 #define fiERR_COM_FILE_READ 20716U
 #define fiERR_COM_FILE_CLOSE 20715U
 #define fiERR_COM_FILE_OPEN 20714U
 #define fiERR_LESS_VIRTUAL_MEMORY 20713U
 #define fiERR_FILE 20712U
 #define fiERR_SEEK 20711U
 #define fiERR_SPACE 20710U
 #define fiERR_FILE_DEVICE 20709U
 #define fiERR_FILE_NOT_FOUND 20708U
 #define fiERR_MODE 20707U
 #define fiERR_ACCESS 20706U
 #define fiERR_EXIST 20705U
 #define fiERR_INVALID_TYP 20704U
 #define fiERR_NOT_SUPPORTED 20703U
 #define fiERR_NO_MORE_ENTRIES 20702U
 #define fiERR_DATA_SIZE 20701U
 #define fiERR_INVALID_PATH 20700U
 #define fiTruncate 1U
 #define fiBOTH 2U
 #define fiDIRECTORY 1U
 #define fiFILE 0U
 #define fiREAD_WRITE 2U
 #define fiWRITE_ONLY 1U
 #define fiREAD_ONLY 0U
 #define fiOVERWRITE 2U
 #define fiRECURSIVE 1U
 #define fiATTR_VOL_LABEL 8U
 #define fiATTR_SYSTEM 4U
 #define fiATTR_RDONLY 1U
 #define fiATTR_HIDDEN 2U
 #define fiATTR_DIRECTORY 16U
 #define fiATTR_ARCHIVE 32U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned char SET_RECURSIVE;
 _GLOBAL_CONST unsigned char FILE_RW;
 _GLOBAL_CONST unsigned char FILE_W;
 _GLOBAL_CONST unsigned char FILE_R;
 _GLOBAL_CONST unsigned char FILE_OW_ONCE;
 _GLOBAL_CONST unsigned char FILE_OW_DETMEM;
 _GLOBAL_CONST unsigned char FILE_DETMEM;
 _GLOBAL_CONST unsigned char FILE_ONCE;
 _GLOBAL_CONST unsigned char FILE_FILE;
 _GLOBAL_CONST unsigned char FILE_DIR;
 _GLOBAL_CONST unsigned char FILE_ALL;
 _GLOBAL_CONST unsigned char DIR_OW;
 _GLOBAL_CONST unsigned char ATTR_VOL_LABEL;
 _GLOBAL_CONST unsigned char ATTR_SYSTEM;
 _GLOBAL_CONST unsigned char ATTR_RDONLY;
 _GLOBAL_CONST unsigned char ATTR_HIDDEN;
 _GLOBAL_CONST unsigned char ATTR_DIRECTORY;
 _GLOBAL_CONST unsigned char ATTR_ARCHIVE;
 _GLOBAL_CONST unsigned short fiERR_SYSTEM;
 _GLOBAL_CONST unsigned short fiERR_DEVICE_MANAGER;
 _GLOBAL_CONST unsigned short fiERR_DEVICE_DRIVER;
 _GLOBAL_CONST unsigned short fiERR_INIT;
 _GLOBAL_CONST unsigned short fiERR_NETIO_PARAMETERS;
 _GLOBAL_CONST unsigned short fiERR_INVALID_NBYTES;
 _GLOBAL_CONST unsigned short fiERR_NETIO_USER;
 _GLOBAL_CONST unsigned short fiERR_NETIO_PORT;
 _GLOBAL_CONST unsigned short fiERR_NETIO_IP_UNEQUAL;
 _GLOBAL_CONST unsigned short fiERR_DEVICE_INVALID_HANDLE;
 _GLOBAL_CONST unsigned short fiERR_DEVICE_ALREADY_EXIST;
 _GLOBAL_CONST unsigned short fiERR_PARAMETER;
 _GLOBAL_CONST unsigned short fiERR_DIR_INVALID_HANDLE;
 _GLOBAL_CONST unsigned short fiERR_NOT_ENOUGH_FREEMEM;
 _GLOBAL_CONST unsigned short fiERR_DETMEMINFO;
 _GLOBAL_CONST unsigned short fiERR_DIR_ALREADY_EXIST;
 _GLOBAL_CONST unsigned short fiERR_DIR_NOT_EMPTY;
 _GLOBAL_CONST unsigned short fiERR_DIR_NOT_EXIST;
 _GLOBAL_CONST unsigned short fiERR_INVALID_DIRECTORY;
 _GLOBAL_CONST unsigned short fiERR_FILE_NOT_OPENED;
 _GLOBAL_CONST unsigned short fiERR_ASYNC_MANAGER;
 _GLOBAL_CONST unsigned short fiERR_DATA;
 _GLOBAL_CONST unsigned short fiERR_COM_FILE_IOCTL;
 _GLOBAL_CONST unsigned short fiERR_COM_FILE_WRITE;
 _GLOBAL_CONST unsigned short fiERR_COM_FILE_READ;
 _GLOBAL_CONST unsigned short fiERR_COM_FILE_CLOSE;
 _GLOBAL_CONST unsigned short fiERR_COM_FILE_OPEN;
 _GLOBAL_CONST unsigned short fiERR_LESS_VIRTUAL_MEMORY;
 _GLOBAL_CONST unsigned short fiERR_FILE;
 _GLOBAL_CONST unsigned short fiERR_SEEK;
 _GLOBAL_CONST unsigned short fiERR_SPACE;
 _GLOBAL_CONST unsigned short fiERR_FILE_DEVICE;
 _GLOBAL_CONST unsigned short fiERR_FILE_NOT_FOUND;
 _GLOBAL_CONST unsigned short fiERR_MODE;
 _GLOBAL_CONST unsigned short fiERR_ACCESS;
 _GLOBAL_CONST unsigned short fiERR_EXIST;
 _GLOBAL_CONST unsigned short fiERR_INVALID_TYP;
 _GLOBAL_CONST unsigned short fiERR_NOT_SUPPORTED;
 _GLOBAL_CONST unsigned short fiERR_NO_MORE_ENTRIES;
 _GLOBAL_CONST unsigned short fiERR_DATA_SIZE;
 _GLOBAL_CONST unsigned short fiERR_INVALID_PATH;
 _GLOBAL_CONST unsigned long fiTruncate;
 _GLOBAL_CONST unsigned char fiBOTH;
 _GLOBAL_CONST unsigned char fiDIRECTORY;
 _GLOBAL_CONST unsigned char fiFILE;
 _GLOBAL_CONST unsigned char fiREAD_WRITE;
 _GLOBAL_CONST unsigned char fiWRITE_ONLY;
 _GLOBAL_CONST unsigned char fiREAD_ONLY;
 _GLOBAL_CONST unsigned char fiOVERWRITE;
 _GLOBAL_CONST unsigned char fiRECURSIVE;
 _GLOBAL_CONST unsigned char fiATTR_VOL_LABEL;
 _GLOBAL_CONST unsigned char fiATTR_SYSTEM;
 _GLOBAL_CONST unsigned char fiATTR_RDONLY;
 _GLOBAL_CONST unsigned char fiATTR_HIDDEN;
 _GLOBAL_CONST unsigned char fiATTR_DIRECTORY;
 _GLOBAL_CONST unsigned char fiATTR_ARCHIVE;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct fiDIR_READ_DATA
{	unsigned char Filename[260];
	plcdt Date;
	unsigned long Filelength;
} fiDIR_READ_DATA;

typedef struct fiDIR_READ_EX_DATA
{	unsigned char Filename[260];
	plcdt Date;
	unsigned long Filelength;
	unsigned short Mode;
} fiDIR_READ_EX_DATA;

typedef struct fiFILE_INFO
{	unsigned long size;
	unsigned long linkCnt;
	plcdt accTime;
	plcdt modTime;
	plcdt chgTime;
	unsigned long reserved[21];
} fiFILE_INFO;

typedef struct FileCreate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pFile;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileCreate_typ;

typedef struct FileOpen
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pFile;
	unsigned char mode;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	unsigned long filelen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileOpen_typ;

typedef struct FileClose
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileClose_typ;

typedef struct FileRead
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long offset;
	unsigned long pDest;
	unsigned long len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileRead_typ;

typedef struct FileReadEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long offset;
	unsigned long pDest;
	unsigned long len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long bytesread;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileReadEx_typ;

typedef struct FileWrite
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long offset;
	unsigned long pSrc;
	unsigned long len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileWrite_typ;

typedef struct FileWriteEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long offset;
	unsigned long pSrc;
	unsigned long len;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileWriteEx_typ;

typedef struct FileRename
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	unsigned long pNewName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileRename_typ;

typedef struct FileCopy
{
	/* VAR_INPUT (analog) */
	unsigned long pSrcDev;
	unsigned long pSrc;
	unsigned long pDestDev;
	unsigned long pDest;
	unsigned char option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileCopy_typ;

typedef struct FileDelete
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileDelete_typ;

typedef struct FileInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	unsigned long pInfo;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileInfo_typ;

typedef struct FileTruncate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	unsigned long newLength;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} FileTruncate_typ;

typedef struct DirCreate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirCreate_typ;

typedef struct DirOpen
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirOpen_typ;

typedef struct DirClose
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirClose_typ;

typedef struct DirRead
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pPath;
	unsigned long entry;
	unsigned char option;
	unsigned long pData;
	unsigned long data_len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirRead_typ;

typedef struct DirReadEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pData;
	unsigned long data_len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirReadEx_typ;

typedef struct DirInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pPath;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long dirnum;
	unsigned long filenum;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirInfo_typ;

typedef struct DirRename
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	unsigned long pNewName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirRename_typ;

typedef struct DirCopy
{
	/* VAR_INPUT (analog) */
	unsigned long pSrcDev;
	unsigned long pSrcDir;
	unsigned long pDestDev;
	unsigned long pDestDir;
	unsigned char option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirCopy_typ;

typedef struct DirDelete
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirDelete_typ;

typedef struct DirDeleteEx
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DirDeleteEx_typ;

typedef struct SetAttributes
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pPath;
	unsigned char attributes;
	unsigned char option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SetAttributes_typ;

typedef struct GetAttributes
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pPath;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char attributes;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} GetAttributes_typ;

typedef struct DevMemInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long freemem;
	unsigned long memsize;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DevMemInfo_typ;

typedef struct DevLink
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pParam;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long handle;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DevLink_typ;

typedef struct DevUnlink
{
	/* VAR_INPUT (analog) */
	unsigned long handle;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DevUnlink_typ;

typedef struct GetVolumeLabel
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pLabel;
	unsigned long labelMax;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long labelLen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} GetVolumeLabel_typ;

typedef struct GetVolumeSerialNo
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long serialNo;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} GetVolumeSerialNo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FileCreate(struct FileCreate* inst);
_BUR_PUBLIC void FileOpen(struct FileOpen* inst);
_BUR_PUBLIC void FileClose(struct FileClose* inst);
_BUR_PUBLIC void FileRead(struct FileRead* inst);
_BUR_PUBLIC void FileReadEx(struct FileReadEx* inst);
_BUR_PUBLIC void FileWrite(struct FileWrite* inst);
_BUR_PUBLIC void FileWriteEx(struct FileWriteEx* inst);
_BUR_PUBLIC void FileRename(struct FileRename* inst);
_BUR_PUBLIC void FileCopy(struct FileCopy* inst);
_BUR_PUBLIC void FileDelete(struct FileDelete* inst);
_BUR_PUBLIC void FileInfo(struct FileInfo* inst);
_BUR_PUBLIC void FileTruncate(struct FileTruncate* inst);
_BUR_PUBLIC void DirCreate(struct DirCreate* inst);
_BUR_PUBLIC void DirOpen(struct DirOpen* inst);
_BUR_PUBLIC void DirClose(struct DirClose* inst);
_BUR_PUBLIC void DirRead(struct DirRead* inst);
_BUR_PUBLIC void DirReadEx(struct DirReadEx* inst);
_BUR_PUBLIC void DirInfo(struct DirInfo* inst);
_BUR_PUBLIC void DirRename(struct DirRename* inst);
_BUR_PUBLIC void DirCopy(struct DirCopy* inst);
_BUR_PUBLIC void DirDelete(struct DirDelete* inst);
_BUR_PUBLIC void DirDeleteEx(struct DirDeleteEx* inst);
_BUR_PUBLIC void SetAttributes(struct SetAttributes* inst);
_BUR_PUBLIC void GetAttributes(struct GetAttributes* inst);
_BUR_PUBLIC void DevMemInfo(struct DevMemInfo* inst);
_BUR_PUBLIC void DevLink(struct DevLink* inst);
_BUR_PUBLIC void DevUnlink(struct DevUnlink* inst);
_BUR_PUBLIC void GetVolumeLabel(struct GetVolumeLabel* inst);
_BUR_PUBLIC void GetVolumeSerialNo(struct GetVolumeSerialNo* inst);
_BUR_PUBLIC unsigned short FileIoGetSysError(void);


#ifdef __cplusplus
};
#endif
#endif /* _FILEIO_ */

