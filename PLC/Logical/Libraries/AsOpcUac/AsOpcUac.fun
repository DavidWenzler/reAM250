                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_Connect
	VAR_INPUT
		Execute	           		: BOOL;
		ServerEndpointUrl		: STRING[255];
		SessionConnectInfo 		: UASessionConnectInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		ConnectionHdl      		: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_Disconnect
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_GetNamespaceIndex
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NamespaceUri			: STRING[255];
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		NamespaceIndex			: UINT;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_TranslatePath
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		StartNodeID				: UANodeID;
		RelativePath			: STRING[255];	
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		TargetNodeID			: UANodeID;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_NodeGetHandle
	VAR_INPUT
		Execute	           	 	: BOOL;
		ConnectionHdl      	 	: DWORD;
		NodeID					: UANodeID;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		NodeHdl					: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_NodeGetHandleList
	VAR_INPUT
		Execute	           	 	: BOOL;
		ConnectionHdl      	 	: DWORD;
		NodeIDCount				: UINT;
		NodeIDs					: ARRAY[0..MAX_INDEX_NODELIST] OF UANodeID;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		NodeHdls				: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID					: DWORD;
		NodeErrorIDs           	: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_NodeReleaseHandle
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdl      	 		: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_NodeReleaseHandleList
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdlCount   	 		: UINT;
		NodeHdls				: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID					: DWORD;
		NodeErrorIDs           	: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_NodeGetInfo
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeID					: UANodeID;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		NodeInfo				: UANodeInfo;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_SubscriptionCreate
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		PublishingEnable		: BOOL;
		Priority				: BYTE;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		SubscriptionHdl			: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		PublishingInterval		: TIME;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_SubscriptionDelete
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_SubscriptionOperate
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		PublishingEnable  		: BOOL;
		Priority  				: USINT;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Published				: BOOL;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		PublishingInterval		: TIME;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemAdd
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		NodeHdl					: DWORD;
		NodeAddInfo				: UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		MonitoredItemHdl		: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		Variable	   			: STRING[255];
		MonitoringSettings		: UAMonitoringSettings;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemAddList
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		NodeHdlCount			: UINT;
		NodeHdls				: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
		NodeAddInfos			: ARRAY[0..MAX_INDEX_MONITORLIST] OF UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		NodeErrorIDs			: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
		MonitoredItemHdls		: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
	END_VAR

	VAR_IN_OUT
		Variables	   			: ARRAY[0..MAX_INDEX_MONITORLIST] OF STRING[255];
		MonitoringSettings		: ARRAY[0..MAX_INDEX_MONITORLIST] OF UAMonitoringParameters;
		ValuesChanged			: ARRAY[0..MAX_INDEX_MONITORLIST] OF BOOL;
		RemainingValueCount		: ARRAY[0..MAX_INDEX_MONITORLIST] OF UINT;
		TimeStamps				: ARRAY[0..MAX_INDEX_MONITORLIST] OF DT;
		NodeQualityIDs			: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemRemove
	VAR_INPUT
		Execute	           		: BOOL;
		MonitoredItemHdl		: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemRemoveList
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		MonitoredItemHdlCount	: UINT;
		MonitoredItemHdls		: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		NodeErrorIDs			: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemOperate
	VAR_INPUT
		Execute	           		: BOOL;
		MonitoredItemHdl		: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		ValueChanged			: BOOL;
		TimeStamp				: DT;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		MonitoringSettings 		: UAMonitoringSettings;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MonitoredItemOperateList
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		MonitoredItemHdlCount	: UINT;
		MonitoredItemHdls		: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
	END_VAR

	VAR_OUTPUT
		Published				: BOOL;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		NodeErrorIDs			: ARRAY[0..MAX_INDEX_MONITORLIST] OF DWORD;
	END_VAR	

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_EventItemAdd
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		NodeHdl					: DWORD;
		EventType				: UANodeID;
		EventFieldSelectionCount: UINT;
		EventFieldSelections	: ARRAY[0..MAX_INDEX_EVENTFIELDSELECTION] OF UARelativePath;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		EventItemHdl			: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		EventFields	   			: ARRAY[0..MAX_INDEX_EVENTFIELDSELECTION] OF STRING[MAX_LENGTH_VARIABLE];
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_EventItemRemove
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		EventItemHdl			: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_EventItemOperate
	VAR_INPUT
		Execute	           		: BOOL;
		SubscriptionHdl			: DWORD;
		EventItemHdl			: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		EventProcessed			: BOOL;
		RemainingEventCount		: INT;
		FieldErrorIDs			: ARRAY[0..MAX_INDEX_EVENTFIELDSELECTION] OF DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_Read
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdl					: DWORD;
		NodeAddInfo				: UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		TimeStamp				: DT;
	END_VAR
	
	VAR_IN_OUT
		Variable	   			: STRING[255];
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_ReadList
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdlCount			: UINT;
		NodeHdls				: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
		NodeAddInfo				: ARRAY[0..MAX_INDEX_NODELIST] OF UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		NodeErrorIDs			: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
		TimeStamps				: ARRAY[0..MAX_INDEX_NODELIST] OF DT;
	END_VAR
	
	VAR_IN_OUT
		Variables	   			: ARRAY[0..MAX_INDEX_NODELIST] OF STRING[255];
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UaClt_ReadBulk
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeIDCount				: UINT;
		NodeIDs					: UDINT;
		NodeAddInfo				: UDINT;
		Variables	   			: UDINT;
		NodeErrorIDs			: UDINT;
		TimeStamps				: UDINT;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR
	
	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_Write
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdl					: DWORD;
		NodeAddInfo				: UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		Variable	   			: STRING[255];
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_WriteList
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeHdlCount			: UINT;
		NodeHdls				: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
		NodeAddInfo				: ARRAY[0..MAX_INDEX_NODELIST] OF UANodeAdditionalInfo;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
		NodeErrorIDs			: ARRAY[0..MAX_INDEX_NODELIST] OF DWORD;
	END_VAR

	VAR_IN_OUT
		Variables   			: ARRAY[0..MAX_INDEX_NODELIST] OF STRING[255];
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UaClt_WriteBulk
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		NodeIDCount				: UINT;
		NodeIDs					: UDINT;
		NodeAddInfo				: UDINT;
		Variables	   			: UDINT;
		NodeErrorIDs			: UDINT;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MethodGetHandle
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		ObjectNodeID			: UANodeID;
		MethodNodeID			: UANodeID;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		MethodHdl				: DWORD;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MethodReleaseHandle
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		MethodHdl				: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_MethodCall
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		MethodHdl				: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		InputArguments			: ARRAY[0..MAX_INDEX_ARGUMENTS] OF UAMethodArgument;
		OutputArguments			: ARRAY[0..MAX_INDEX_ARGUMENTS] OF UAMethodArgument;
	END_VAR

	VAR
		i_busy             		: BOOL;
		i_tid					: UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UA_ConnectionGetStatus
	VAR_INPUT
		Execute	           		: BOOL;
		ConnectionHdl      		: DWORD;
		Timeout            		: TIME;
	END_VAR

	VAR_OUTPUT
		ConnectionStatus		: UAConnectionStatus;
		ServerState				: UAServerState;
		ServiceLevel			: BYTE;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		i_busy             		: BOOL;
	END_VAR
END_FUNCTION_BLOCK
