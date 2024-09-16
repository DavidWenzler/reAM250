                                                                      
FUNCTION_BLOCK UaSrv_MethodOperate
	VAR_INPUT
		Execute	           		: BOOL;
		MethodName				: STRING[255];
		Action					: UaMethodOperateAction;
	END_VAR

	VAR_OUTPUT
		IsCalled      			: BOOL;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		Internal				: UaSrv_MethodOperateInternal;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK UaSrv_MethodCreate
	VAR_INPUT
		Execute	           		: BOOL;
		MethodName				: STRING[255];
		InputArguments			: ARRAY[0..9] OF UAMethodArgument;
		OutputArguments			: ARRAY[0..9] OF UAMethodArgument;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		Internal				: UaSrv_MethodCreateInternal;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK UaSrv_MethodDelete
	VAR_INPUT
		Execute	           		: BOOL;
		MethodName				: STRING[255];
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		Internal				: UaSrv_MethodDeleteInternal;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK UaSrv_GetNamespaceIndex
	VAR_INPUT
		Execute	           		: BOOL;
		NamespaceUri			: STRING[MAX_LENGTH_NAMESPACEURI];
	END_VAR

	VAR_OUTPUT
		NamespaceIndex			: UINT;
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR
		Internal				: UaSrv_GetNamespaceIndexInternal;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK UaSrv_FireEvent
	VAR_INPUT
		Execute	           		: BOOL;
		EventType				: UANodeID;
		EventFieldCount			: UINT;
	END_VAR

	VAR_OUTPUT
		Done			   		: BOOL;
		Busy               		: BOOL;
		Error              		: BOOL;
		ErrorID            		: DWORD;
	END_VAR

	VAR_IN_OUT
		EventFields				: UaSrv_FireEventFieldType;
	END_VAR

	VAR
		Internal				: UaSrv_FireEventInternal;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UaSrv_GetServerState : UAServerState

END_FUNCTION