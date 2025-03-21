/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASOPCUAC_
#define _ASOPCUAC_
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
 #define MAX_INDEX_BYTESTRING 1023U
 #define MAX_INDEX_RELATIVEPATH 15U
 #define MAX_INDEX_EVENTFIELDSELECTION 63U
 #define MAX_INDEX_ARGUMENTS 9U
 #define MAX_INDEX_MONITORLIST 63U
 #define MAX_INDEX_NODELIST 63U
 #define MAX_INDEX_INDEXRANGE 7U
 #define MAX_INDEX_ARRAYDIMENSION 6U
 #define MAX_ELEMENTS_RELATIVEPATH 16U
 #define MAX_ELEMENTS_EVENTFIELDSELECTION 64U
 #define MAX_ELEMENTS_ARGUMENTS 10U
 #define MAX_ELEMENTS_MONITORLIST 64U
 #define MAX_ELEMENTS_NODELIST 64U
 #define MAX_ELEMENTS_INDEXRANGE 8U
 #define MAX_ELEMENTS_ARRAYDIMENSION 7U
 #define MAX_LENGTH_BYTESTRING 1024U
 #define MAX_LENGTH_VARIABLE 255U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short MAX_INDEX_BYTESTRING;
 _GLOBAL_CONST unsigned short MAX_INDEX_RELATIVEPATH;
 _GLOBAL_CONST unsigned short MAX_INDEX_EVENTFIELDSELECTION;
 _GLOBAL_CONST unsigned short MAX_INDEX_ARGUMENTS;
 _GLOBAL_CONST unsigned short MAX_INDEX_MONITORLIST;
 _GLOBAL_CONST unsigned short MAX_INDEX_NODELIST;
 _GLOBAL_CONST unsigned short MAX_INDEX_INDEXRANGE;
 _GLOBAL_CONST unsigned short MAX_INDEX_ARRAYDIMENSION;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_RELATIVEPATH;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_EVENTFIELDSELECTION;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_ARGUMENTS;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_MONITORLIST;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_NODELIST;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_INDEXRANGE;
 _GLOBAL_CONST unsigned short MAX_ELEMENTS_ARRAYDIMENSION;
 _GLOBAL_CONST unsigned short MAX_LENGTH_BYTESTRING;
 _GLOBAL_CONST unsigned short MAX_LENGTH_VARIABLE;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum UASecurityMsgMode
{	UASecurityMsgMode_BestAvailable = 0,
	UASecurityMsgMode_None = 1,
	UASecurityMsgMode_Sign = 2,
	UASecurityMsgMode_SignEncrypt = 3
} UASecurityMsgMode;

typedef enum UASecurityPolicy
{	UASecurityPolicy_BestAvailable = 0,
	UASecurityPolicy_None = 1,
	UASecurityPolicy_Basic128Rsa15 = 2,
	UASecurityPolicy_Basic256 = 3,
	UASecurityPolicy_Basic256Sha256 = 4
} UASecurityPolicy;

typedef enum UATransportProfile
{	UATP_UATcp = 1,
	UATP_WSHttpBinary = 2,
	UATP_WSHttpXmlOrBinary = 3,
	UATP_WSHttpXml = 4
} UATransportProfile;

typedef enum UAUserIdentityTokenTtype
{	UAUITT_Anonymous = 0,
	UAUITT_Username = 1,
	UAUITT_x509 = 2
} UAUserIdentityTokenTtype;

typedef enum UAIdentifierType
{	UAIdentifierType_String = 1,
	UAIdentifierType_Numeric = 2,
	UAIdentifierType_GUID = 3,
	UAIdentifierType_Opaque = 4
} UAIdentifierType;

typedef enum UADeadbandType
{	UADeadbandType_None = 0,
	UADeadbandType_Absolute = 1,
	UADeadbandType_Percent = 2
} UADeadbandType;

typedef enum UANodeClass
{	UANodeClass_None = 0,
	UANodeClass_Object = 1,
	UANodeClass_Variable = 2,
	UANodeClass_Method = 4,
	UANodeClass_ObjectType = 8,
	UANodeClass_VariableType = 16,
	UANodeClass_ReferenceType = 32,
	UANodeClass_DataType = 64,
	UANodeClass_View = 128,
	UANodeClass_All = 255
} UANodeClass;

typedef enum UAAttributeId
{	UAAI_Default = 0,
	UAAI_NodeId = 1,
	UAAI_NodeClass = 2,
	UAAI_BrowseName = 3,
	UAAI_DisplayName = 4,
	UAAI_Description = 5,
	UAAI_WriteMask = 6,
	UAAI_UserWriteMask = 7,
	UAAI_IsAbstract = 8,
	UAAI_Symmetric = 9,
	UAAI_InverseName = 10,
	UAAI_ContainsNoLoops = 11,
	UAAI_EventNotifier = 12,
	UAAI_Value = 13,
	UAAI_DataType = 14,
	UAAI_ValueRank = 15,
	UAAI_ArrayDimensions = 16,
	UAAI_AccessLevel = 17,
	UAAI_UserAccessLevel = 18,
	UAAI_MinimumSamplingInterval = 19,
	UAAI_Historizing = 20,
	UAAI_Executable = 21,
	UAAI_UserExecutable = 22
} UAAttributeId;

typedef enum UAConnectionStatus
{	UACS_Connected = 0,
	UACS_ConnectionError = 1,
	UACS_Shutdown = 2
} UAConnectionStatus;

typedef enum UAServerState
{	UASS_Running = 0,
	UASS_Failed = 1,
	UASS_NoConfiguration = 2,
	UASS_Suspended = 3,
	UASS_Shutdown = 4,
	UASS_Test = 5,
	UASS_CommunicationFault = 6,
	UASS_Unknown = 7
} UAServerState;

typedef enum UAVariantType
{	UAVariantType_Null = 0,
	UAVariantType_Boolean = 1,
	UAVariantType_SByte = 2,
	UAVariantType_Byte = 3,
	UAVariantType_Int16 = 4,
	UAVariantType_UInt16 = 5,
	UAVariantType_Int32 = 6,
	UAVariantType_UInt32 = 7,
	UAVariantType_Int64 = 8,
	UAVariantType_UInt64 = 9,
	UAVariantType_Float = 10,
	UAVariantType_Double = 11,
	UAVariantType_String = 12,
	UAVariantType_DateTime = 13,
	UAVariantType_Guid = 14,
	UAVariantType_ByteString = 15,
	UAVariantType_XmlElement = 16,
	UAVariantType_NodeId = 17,
	UAVariantType_ExpandedNodeId = 18,
	UAVariantType_StatusCode = 19,
	UAVariantType_QualifiedName = 20,
	UAVariantType_LocalizedText = 21
} UAVariantType;

typedef struct UAUserIdentityToken
{	enum UAUserIdentityTokenTtype UserIdentityTokenType;
	plcstring TokenParam1[256];
	plcstring TokenParam2[256];
} UAUserIdentityToken;

typedef struct UASessionConnectInfo
{	plcstring SessionName[256];
	plcstring ApplicationName[256];
	enum UASecurityMsgMode SecurityMsgMode;
	enum UASecurityPolicy SecurityPolicy;
	plcstring CertificateStore[256];
	plcstring ClientCertificateName[256];
	plcstring ServerUri[256];
	plcbit CheckServerCertificate;
	enum UATransportProfile TransportProfile;
	struct UAUserIdentityToken UserIdentityToken;
	plcstring VendorSpecificParameter[256];
	plctime SessionTimeout;
	plctime MonitorConnection;
	plcstring LocaleIDs[5][7];
} UASessionConnectInfo;

typedef struct UANodeID
{	unsigned short NamespaceIndex;
	plcstring Identifier[256];
	enum UAIdentifierType IdentifierType;
} UANodeID;

typedef struct UAMonitoringSettings
{	plctime SamplingInterval;
	enum UADeadbandType DeadbandType;
	float Deadband;
} UAMonitoringSettings;

typedef struct UAMonitoringParameters
{	plctime SamplingInterval;
	unsigned short QueueSize;
	plcbit DiscardOldest;
	enum UADeadbandType DeadbandType;
	float Deadband;
} UAMonitoringParameters;

typedef struct UALocalizedText
{	plcstring Locale[7];
	plcstring Text[256];
} UALocalizedText;

typedef struct UANodeInfo
{	plcbyte AccessLevel;
	unsigned long ArrayDimension[7];
	plcstring BrowseName[256];
	plcbit ContainsNoLoops;
	struct UANodeID DataType;
	struct UALocalizedText Description;
	struct UALocalizedText DisplayName;
	plcbyte EventNotifier;
	plcbit Executable;
	plcbit Historizing;
	plcstring InverseName[256];
	plcbit IsAbstract;
	plctime MinimumSamplingInterval;
	enum UANodeClass NodeClass;
	struct UANodeID NodeID;
	plcbit Symmetric;
	plcbyte UserAccessLevel;
	plcbit UserExecutable;
	unsigned long UserWriteMask;
	signed long ValueRank;
	unsigned long WriteMask;
} UANodeInfo;

typedef struct UAIndexRange
{	unsigned short StartIndex;
	unsigned short EndIndex;
} UAIndexRange;

typedef struct UANodeAdditionalInfo
{	enum UAAttributeId AttributeId;
	unsigned short IndexRangeCount;
	struct UAIndexRange IndexRange[8];
} UANodeAdditionalInfo;

typedef struct UAMethodArgument
{	plcstring Name[65];
	plcstring Value[256];
} UAMethodArgument;

typedef struct UAByteString
{	signed long Length;
	unsigned char Data[1024];
} UAByteString;

typedef struct UAExpandedNodeID
{	struct UANodeID NodeId;
	plcstring NamespaceUri[256];
	unsigned long ServerIndex;
} UAExpandedNodeID;

typedef struct UAQualifiedName
{	unsigned short NamespaceIndex;
	plcstring Name[256];
} UAQualifiedName;

typedef struct UARelativePathElement
{	struct UANodeID ReferenceTypeId;
	plcbit IsInverse;
	plcbit IncludeSubTypes;
	struct UAQualifiedName TargetName;
} UARelativePathElement;

typedef struct UARelativePath
{	plcdword NoOfElements;
	struct UARelativePathElement Elements[16];
} UARelativePath;

typedef struct UADataValue
{	plcbit Valid;
	unsigned char Reserved[3];
	unsigned long StatusCode;
	plcdt SourceTimestamp;
	plcdt ServerTimestamp;
} UADataValue;

typedef struct UAVariantData
{	enum UAVariantType VariantType;
	plcbit Boolean;
	signed char SByte;
	unsigned char Byte;
	signed short Int16;
	unsigned short UInt16;
	signed long Int32;
	unsigned long UInt32;
	float Float;
	double Double;
	plcdt DateTime;
	plcstring String[256];
	struct UANodeID NodeId;
	struct UAExpandedNodeID ExpandedNodeId;
	struct UAQualifiedName QualifiedName;
	struct UALocalizedText LocalizedText;
	struct UADataValue DataValue;
} UAVariantData;

typedef struct UARange
{	double Low;
	double High;
} UARange;

typedef struct UAEUInformation
{	plcstring NamespaceUri[256];
	signed long UnitId;
	struct UALocalizedText DisplayName;
	struct UALocalizedText Description;
} UAEUInformation;

typedef struct UATimeZoneData
{	signed short TimeOffset;
	plcbit DaylightSaving;
} UATimeZoneData;

typedef struct BrUaXmlElement
{	signed long Length;
	plcstring Data[65536];
} BrUaXmlElement;

typedef struct BrUaImageBMP
{	signed long Length;
	unsigned char Data[6291456];
} BrUaImageBMP;

typedef struct BrUaImageGIF
{	signed long Length;
	unsigned char Data[524288];
} BrUaImageGIF;

typedef struct BrUaImageJPG
{	signed long Length;
	unsigned char Data[1048576];
} BrUaImageJPG;

typedef struct BrUaImagePNG
{	signed long Length;
	unsigned char Data[2621440];
} BrUaImagePNG;

typedef struct UA_Connect
{
	/* VAR_INPUT (analog) */
	plcstring ServerEndpointUrl[256];
	struct UASessionConnectInfo SessionConnectInfo;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ConnectionHdl;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_Connect_typ;

typedef struct UA_Disconnect
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_Disconnect_typ;

typedef struct UA_GetNamespaceIndex
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcstring NamespaceUri[256];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	unsigned short NamespaceIndex;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_GetNamespaceIndex_typ;

typedef struct UA_TranslatePath
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	struct UANodeID StartNodeID;
	plcstring RelativePath[256];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	struct UANodeID TargetNodeID;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_TranslatePath_typ;

typedef struct UA_NodeGetHandle
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	struct UANodeID NodeID;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword NodeHdl;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_NodeGetHandle_typ;

typedef struct UA_NodeGetHandleList
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeIDCount;
	struct UANodeID NodeIDs[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword NodeHdls[64];
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_NodeGetHandleList_typ;

typedef struct UA_NodeReleaseHandle
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcdword NodeHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_NodeReleaseHandle_typ;

typedef struct UA_NodeReleaseHandleList
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_NodeReleaseHandleList_typ;

typedef struct UA_NodeGetInfo
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	struct UANodeID NodeID;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	struct UANodeInfo NodeInfo;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_NodeGetInfo_typ;

typedef struct UA_SubscriptionCreate
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcbyte Priority;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword SubscriptionHdl;
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	plctime* PublishingInterval;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	plcbit PublishingEnable;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_SubscriptionCreate_typ;

typedef struct UA_SubscriptionDelete
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_SubscriptionDelete_typ;

typedef struct UA_SubscriptionOperate
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	unsigned char Priority;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	plctime* PublishingInterval;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	plcbit PublishingEnable;
	/* VAR_OUTPUT (digital) */
	plcbit Published;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_SubscriptionOperate_typ;

typedef struct UA_MonitoredItemAdd
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	plcdword NodeHdl;
	struct UANodeAdditionalInfo NodeAddInfo;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword MonitoredItemHdl;
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variable);
	struct UAMonitoringSettings* MonitoringSettings;
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemAdd_typ;

typedef struct UA_MonitoredItemAddList
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfos[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcdword MonitoredItemHdls[64];
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variables)[64][256];
	struct UAMonitoringParameters (*MonitoringSettings)[64];
	plcbit (*ValuesChanged)[64];
	unsigned short (*RemainingValueCount)[64];
	plcdt (*TimeStamps)[64];
	plcdword (*NodeQualityIDs)[64];
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemAddList_typ;

typedef struct UA_MonitoredItemRemove
{
	/* VAR_INPUT (analog) */
	plcdword MonitoredItemHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemRemove_typ;

typedef struct UA_MonitoredItemRemoveList
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	unsigned short MonitoredItemHdlCount;
	plcdword MonitoredItemHdls[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemRemoveList_typ;

typedef struct UA_MonitoredItemOperate
{
	/* VAR_INPUT (analog) */
	plcdword MonitoredItemHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdt TimeStamp;
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	struct UAMonitoringSettings* MonitoringSettings;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit ValueChanged;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemOperate_typ;

typedef struct UA_MonitoredItemOperateList
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	unsigned short MonitoredItemHdlCount;
	plcdword MonitoredItemHdls[64];
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Published;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MonitoredItemOperateList_typ;

typedef struct UA_EventItemAdd
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	plcdword NodeHdl;
	struct UANodeID EventType;
	unsigned short EventFieldSelectionCount;
	struct UARelativePath EventFieldSelections[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword EventItemHdl;
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*EventFields)[64][256];
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_EventItemAdd_typ;

typedef struct UA_EventItemRemove
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	plcdword EventItemHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_EventItemRemove_typ;

typedef struct UA_EventItemOperate
{
	/* VAR_INPUT (analog) */
	plcdword SubscriptionHdl;
	plcdword EventItemHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	signed short RemainingEventCount;
	plcdword FieldErrorIDs[64];
	plcdword ErrorID;
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit EventProcessed;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_EventItemOperate_typ;

typedef struct UA_Read
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcdword NodeHdl;
	struct UANodeAdditionalInfo NodeAddInfo;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdt TimeStamp;
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variable);
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_Read_typ;

typedef struct UA_ReadList
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfo[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	plcdt TimeStamps[64];
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variables)[64][256];
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_ReadList_typ;

typedef struct UaClt_ReadBulk
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeIDCount;
	unsigned long NodeIDs;
	unsigned long NodeAddInfo;
	unsigned long Variables;
	unsigned long NodeErrorIDs;
	unsigned long TimeStamps;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UaClt_ReadBulk_typ;

typedef struct UA_Write
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcdword NodeHdl;
	struct UANodeAdditionalInfo NodeAddInfo;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variable);
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_Write_typ;

typedef struct UA_WriteList
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeHdlCount;
	plcdword NodeHdls[64];
	struct UANodeAdditionalInfo NodeAddInfo[64];
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	plcdword NodeErrorIDs[64];
	/* VAR_IN_OUT (analog and digital) */
	plcstring (*Variables)[64][256];
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_WriteList_typ;

typedef struct UaClt_WriteBulk
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	unsigned short NodeIDCount;
	unsigned long NodeIDs;
	unsigned long NodeAddInfo;
	unsigned long Variables;
	unsigned long NodeErrorIDs;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UaClt_WriteBulk_typ;

typedef struct UA_MethodGetHandle
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	struct UANodeID ObjectNodeID;
	struct UANodeID MethodNodeID;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword MethodHdl;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MethodGetHandle_typ;

typedef struct UA_MethodReleaseHandle
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcdword MethodHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MethodReleaseHandle_typ;

typedef struct UA_MethodCall
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plcdword MethodHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	plcdword ErrorID;
	/* VAR_IN_OUT (analog and digital) */
	struct UAMethodArgument (*InputArguments)[10];
	struct UAMethodArgument (*OutputArguments)[10];
	/* VAR (analog) */
	unsigned long i_tid;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_MethodCall_typ;

typedef struct UA_ConnectionGetStatus
{
	/* VAR_INPUT (analog) */
	plcdword ConnectionHdl;
	plctime Timeout;
	/* VAR_OUTPUT (analog) */
	enum UAConnectionStatus ConnectionStatus;
	enum UAServerState ServerState;
	plcbyte ServiceLevel;
	plcdword ErrorID;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_busy;
} UA_ConnectionGetStatus_typ;

typedef signed long UAArrayLength;

typedef signed long UANoOfElements;

typedef UANodeID BrUaNodeId;

typedef UAQualifiedName BrUaQualifiedName;

typedef UALocalizedText BrUaLocalizedText;

typedef UAByteString BrUaByteString;

typedef plcstring BrUaGuidString[37];

typedef double BrUaDuration;

typedef plcstring BrUaLocaleIdString[7];

typedef UATimeZoneData BrUaTimeZoneDataType;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void UA_Connect(struct UA_Connect* inst);
_BUR_PUBLIC void UA_Disconnect(struct UA_Disconnect* inst);
_BUR_PUBLIC void UA_GetNamespaceIndex(struct UA_GetNamespaceIndex* inst);
_BUR_PUBLIC void UA_TranslatePath(struct UA_TranslatePath* inst);
_BUR_PUBLIC void UA_NodeGetHandle(struct UA_NodeGetHandle* inst);
_BUR_PUBLIC void UA_NodeGetHandleList(struct UA_NodeGetHandleList* inst);
_BUR_PUBLIC void UA_NodeReleaseHandle(struct UA_NodeReleaseHandle* inst);
_BUR_PUBLIC void UA_NodeReleaseHandleList(struct UA_NodeReleaseHandleList* inst);
_BUR_PUBLIC void UA_NodeGetInfo(struct UA_NodeGetInfo* inst);
_BUR_PUBLIC void UA_SubscriptionCreate(struct UA_SubscriptionCreate* inst);
_BUR_PUBLIC void UA_SubscriptionDelete(struct UA_SubscriptionDelete* inst);
_BUR_PUBLIC void UA_SubscriptionOperate(struct UA_SubscriptionOperate* inst);
_BUR_PUBLIC void UA_MonitoredItemAdd(struct UA_MonitoredItemAdd* inst);
_BUR_PUBLIC void UA_MonitoredItemAddList(struct UA_MonitoredItemAddList* inst);
_BUR_PUBLIC void UA_MonitoredItemRemove(struct UA_MonitoredItemRemove* inst);
_BUR_PUBLIC void UA_MonitoredItemRemoveList(struct UA_MonitoredItemRemoveList* inst);
_BUR_PUBLIC void UA_MonitoredItemOperate(struct UA_MonitoredItemOperate* inst);
_BUR_PUBLIC void UA_MonitoredItemOperateList(struct UA_MonitoredItemOperateList* inst);
_BUR_PUBLIC void UA_EventItemAdd(struct UA_EventItemAdd* inst);
_BUR_PUBLIC void UA_EventItemRemove(struct UA_EventItemRemove* inst);
_BUR_PUBLIC void UA_EventItemOperate(struct UA_EventItemOperate* inst);
_BUR_PUBLIC void UA_Read(struct UA_Read* inst);
_BUR_PUBLIC void UA_ReadList(struct UA_ReadList* inst);
_BUR_PUBLIC void UaClt_ReadBulk(struct UaClt_ReadBulk* inst);
_BUR_PUBLIC void UA_Write(struct UA_Write* inst);
_BUR_PUBLIC void UA_WriteList(struct UA_WriteList* inst);
_BUR_PUBLIC void UaClt_WriteBulk(struct UaClt_WriteBulk* inst);
_BUR_PUBLIC void UA_MethodGetHandle(struct UA_MethodGetHandle* inst);
_BUR_PUBLIC void UA_MethodReleaseHandle(struct UA_MethodReleaseHandle* inst);
_BUR_PUBLIC void UA_MethodCall(struct UA_MethodCall* inst);
_BUR_PUBLIC void UA_ConnectionGetStatus(struct UA_ConnectionGetStatus* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASOPCUAC_ */

