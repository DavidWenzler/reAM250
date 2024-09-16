/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASOPCUAS_
#define _ASOPCUAS_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>
#include <AsOpcUac.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define MAX_LENGTH_NAMESPACEURI 255U
 #define MAX_LENGTH_EVENTFIELDPATH 255U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short MAX_LENGTH_NAMESPACEURI;
 _GLOBAL_CONST unsigned short MAX_LENGTH_EVENTFIELDPATH;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum UaMethodOperateAction
{	UaMoa_CheckIsCalled = 0,
	UaMoa_Finished = 1
} UaMethodOperateAction;

typedef struct UaSrv_MethodOperateInternal
{	plcbit Busy;
	plcbit Execute;
	unsigned long ModuleId;
	unsigned long CallId;
	unsigned short NamespaceIndex;
	unsigned char Reserved[30];
} UaSrv_MethodOperateInternal;

typedef struct UaSrv_MethodCreateInternal
{	plcbit Busy;
	plcbit Execute;
	unsigned long ModuleId;
	unsigned char Reserved[32];
} UaSrv_MethodCreateInternal;

typedef struct UaSrv_MethodDeleteInternal
{	plcbit Busy;
	plcbit Execute;
	unsigned long ModuleId;
	unsigned char Reserved[32];
} UaSrv_MethodDeleteInternal;

typedef struct UaSrv_FireEventInternal
{	plcbit Busy;
	plcbit Execute;
	unsigned long ModuleId;
	unsigned char Reserved[32];
} UaSrv_FireEventInternal;

typedef struct UaSrv_GetNamespaceIndexInternal
{	plcbit Busy;
	plcbit Execute;
	unsigned long ModuleId;
	unsigned char Reserved[32];
} UaSrv_GetNamespaceIndexInternal;

typedef struct UaSrv_DateTimeType
{	plcdt DateTime;
	unsigned long NanoSeconds;
} UaSrv_DateTimeType;

typedef struct UaSrv_FireEventFieldType
{	plcstring BrowsePath[256];
	plcstring Variable[256];
	plcdword ErrorID;
} UaSrv_FireEventFieldType;

typedef struct UaSrv_MethodOperate
{
	/* VAR_INPUT (analog) */
	plcstring MethodName[256];
	enum UaMethodOperateAction Action;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	struct UaSrv_MethodOperateInternal Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit IsCalled;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} UaSrv_MethodOperate_typ;

typedef struct UaSrv_MethodCreate
{
	/* VAR_INPUT (analog) */
	plcstring MethodName[256];
	struct UAMethodArgument InputArguments[10];
	struct UAMethodArgument OutputArguments[10];
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	struct UaSrv_MethodCreateInternal Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} UaSrv_MethodCreate_typ;

typedef struct UaSrv_MethodDelete
{
	/* VAR_INPUT (analog) */
	plcstring MethodName[256];
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	struct UaSrv_MethodDeleteInternal Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} UaSrv_MethodDelete_typ;

typedef struct UaSrv_GetNamespaceIndex
{
	/* VAR_INPUT (analog) */
	plcstring NamespaceUri[256];
	/* VAR_OUTPUT (analog) */
	unsigned short NamespaceIndex;
	plcdword ErrorID;
	/* VAR (analog) */
	struct UaSrv_GetNamespaceIndexInternal Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} UaSrv_GetNamespaceIndex_typ;

typedef struct UaSrv_FireEvent
{
	/* VAR_INPUT (analog) */
	struct UANodeID EventType;
	unsigned short EventFieldCount;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	struct UaSrv_FireEventFieldType* EventFields;
	/* VAR (analog) */
	struct UaSrv_FireEventInternal Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} UaSrv_FireEvent_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void UaSrv_MethodOperate(struct UaSrv_MethodOperate* inst);
_BUR_PUBLIC void UaSrv_MethodCreate(struct UaSrv_MethodCreate* inst);
_BUR_PUBLIC void UaSrv_MethodDelete(struct UaSrv_MethodDelete* inst);
_BUR_PUBLIC void UaSrv_GetNamespaceIndex(struct UaSrv_GetNamespaceIndex* inst);
_BUR_PUBLIC void UaSrv_FireEvent(struct UaSrv_FireEvent* inst);
_BUR_PUBLIC UAServerState UaSrv_GetServerState(void);


#ifdef __cplusplus
};
#endif
#endif /* _ASOPCUAS_ */

