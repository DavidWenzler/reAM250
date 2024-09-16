                                                                      
TYPE
	UaMethodOperateAction :
	(															(* Actions for UaSrv_MethodOperate		*)
    	UaMoa_CheckIsCalled 	:= 0,							(* Check if a method call is pending 	*)
	  	UaMoa_Finished         	:= 1							(* Finish method call					*)
	);
	UaSrv_MethodOperateInternal : STRUCT
		Busy					: BOOL;
		Execute					: BOOL;
		ModuleId				: UDINT;
		CallId					: UDINT;
		NamespaceIndex			: UINT;
		Reserved				: ARRAY[0..29] OF USINT;
	END_STRUCT;
	UaSrv_MethodCreateInternal : STRUCT
		Busy					: BOOL;
		Execute					: BOOL;
		ModuleId				: UDINT;
		Reserved				: ARRAY[0..31] OF USINT;
	END_STRUCT;
	UaSrv_MethodDeleteInternal : STRUCT
		Busy					: BOOL;
		Execute					: BOOL;
		ModuleId				: UDINT;
		Reserved				: ARRAY[0..31] OF USINT;
	END_STRUCT;
	UaSrv_FireEventInternal : STRUCT
		Busy					: BOOL;
		Execute					: BOOL;
		ModuleId				: UDINT;
		Reserved				: ARRAY[0..31] OF USINT;
	END_STRUCT;
	UaSrv_GetNamespaceIndexInternal : STRUCT
		Busy					: BOOL;
		Execute					: BOOL;
		ModuleId				: UDINT;
		Reserved				: ARRAY[0..31] OF USINT;
	END_STRUCT;
	UaSrv_DateTimeType : STRUCT
		DateTime				: DATE_AND_TIME;
		NanoSeconds				: UDINT;
	END_STRUCT;
	UaSrv_FireEventFieldType : STRUCT
		BrowsePath				: STRING[MAX_LENGTH_EVENTFIELDPATH];
		Variable				: STRING[MAX_LENGTH_VARIABLE];
		ErrorID					: DWORD;
	END_STRUCT;
END_TYPE
