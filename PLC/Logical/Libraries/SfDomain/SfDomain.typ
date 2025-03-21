
TYPE
	SfDomainInfoStatusType : 	STRUCT  (*Status information of the SafeDOMAIN*)
		SafeOSState : SfDomainSafeOSStateEnum; (*Status of the operating system of the SafeDOMAIN*)
		SafeNodesState : SfDomainSafeNodesStateEnum; (*Status of the nodes of the SafeDOMAIN*)
		SystemState : SfDomainSystemStateEnum; (*Status of the SafeDOMAIN system*)
		OperationalModeState : SfDomainOperationalModeEnum; (*Operational status of the SafeDOMAIN*)
		SafeCommissioningUnused : SfDomainSafeComUnusedEnum; (*Indicates which file (commissioning) is used on the SafeDOMAIN.*)
		FWExchanged : BOOL; (*Indicates whether a firmware exchange was carried out*)
		NumberOfFWExchanged : UINT; (*Number of exchanged Firmwares*)
		SNExchanged : BOOL; (*Indicates whether a SafeNode exchange was carried out*)
		NumberOfSNExchanged : UINT; (*Number of exchanged SafeNodes*)
		SKExchanged : BOOL; (*Indicates whether a SafeKey exchange was carried out*)
		SetupModeActive : BOOL; (*Indicates whether the setup mode is active*)
	END_STRUCT;
	SfDomainInfoFileType : 	STRUCT  (*Common file information*)
		ExistOnSafeLogic : BOOL; (*Indicates whether the file is located on the SafeLOGIC*)
		Name : STRING[260]; (*Name of the file on the SafeLOGIC*)
		UserName : STRING[260]; (*Name of the user of the file on the SafeLOGIC*)
		TimeStamp : UDINT; (*Timestamp of the file on the SafeLOGIC*)
		CRC : UDINT; (*CRC of the file on the SafeLOGIC*)
		Acknowledged : BOOL; (*Indicates whether the file has already been confirmed on the SafeLOGIC*)
	END_STRUCT;
	SfDomainInfoType : 	STRUCT  (*Status and commissioning information of the SafeDOMAIN*)
		SafeDomainID : UINT; (*SafeDOMAIN ID*)
		UDID_low : UDINT; (*Lower 4-byte part of UDID*)
		UDID_high : UINT; (*Upper 2-byte part of UDID*)
		Status : SfDomainInfoStatusType; (*Information on the status of the SafeLOGIC*)
		SafeApplication : SfDomainInfoFileType; (*Information on safe application on the SafeLOGIC*)
		SafeCommissioning : ARRAY[0..0]OF SfDomainInfoFileType; (*Information about safe commissioning on the SafeLOGIC*)
		SafeTables : SfDomainTableInfoType; (*Informations about remote downloaded SafeTABLES*)
	END_STRUCT;
	SfDomainInternalFlags : 	STRUCT  (*Internal data*)
		Toggled : BOOL;
		WaitForOneCycle : BOOL;
		ActiveDoneReached : BOOL;
	END_STRUCT;
	SfDomainInternalDataType : 	STRUCT  (*Internal data*)
		pObject : UDINT;
		State : UDINT;
		Flag : SfDomainInternalFlags;
		SfDomainInternal : REFERENCE TO SfDomType;
	END_STRUCT;
	SfDomainSafeOSStateEnum : 
		( (*State of SafeDOMAIN*)
		sfDOM_OS_STATE_INVALID := 16#00, (*SafeDomain State Invalid*)
		sfDOM_OS_STATE_ON := 16#0F, (*SafeDomain State On*)
		sfDOM_OS_STATE_LOADING := 16#33, (*SafeDomain State Loading*)
		sfDOM_OS_STATE_SAFE_STOP := 16#55, (*SafeDomain State Safe Stop*)
		sfDOM_OS_STATE_SAFE_RUN := 16#66, (*SafeDomain State Safe Run*)
		sfDOM_OS_STATE_DEBUG_HALT := 16#99, (*SafeDomain State Debug Halt*)
		sfDOM_OS_STATE_DEBUG_STOP := 16#AA, (*SafeDomain State Debug Stop*)
		sfDOM_OS_STATE_DEBUG_RUN := 16#CC, (*SafeDomain State Debug Run*)
		sfDOM_OS_STATE_NO_EXECUTION := 16#F0, (*SafeDomain State no execution*)
		sfDOM_OS_STATE_DEBUG_OFFLINE := 16#FF (*SafeDomain State Debug offline*)
	);
	SfDomainSafeNodesStateEnum : 
		( (*State of SafeNODEs*)
		sfDOM_NODES_STATE_OK := 16#00, (*SafeDomain Node State Ok*)
		sfDOM_NODES_STATE_EXCHANGED := 16#01, (*SafeDomain Node State Exchanged*)
		sfDOM_NODES_STATE_MISSING := 16#02 (*SafeDomain Node State missing*)
	);
	SfDomainSystemStateEnum : 
		( (*System state of SafeDOMAIN*)
		sfDOM_SYSTEM_STATE_OK := 16#00, (*SafeDomain System State Ok*)
		sfDOM_SYSTEM_STATE_FW_EXCHANGE := 16#01, (*SafeDomain System State Firmware Exchange*)
		sfDOM_SYSTEM_STATE_SK_EXCHANGE := 16#02 (*SafeDomainSystem State SafeKey Exchange*)
	);
	SfDomainOperationalModeEnum : 
		( (*Operational state of SafeDOMAIN*)
		sfDOM_OP_MODE_OPERATIONAL := 16#00, (*SafeDomain Operational Mode *)
		sfDOM_OP_MODE_PREOPERATIONAL := 16#01, (*SafeDomain Pre Operational Mode *)
		sfDOM_OP_MODE_FAILSAFE := 16#02 (*SafeDomain Operational Failsafe Mode *)
	);
	SfDomainSafeComUnusedEnum : 
		( (*Commissioning status information*)
		sfDOM_UNUSED_NONE := 16#00, (*No SafeCOMMISSIONING parameter removed*)
		sfDOM_BOOL_AVAILABILITY := 16#01, (*SafeCommissioningOptionsBIT and/or SafeNODE removed*)
		sfDOM_NUMBERS := 16#02, (*SafeCommissioningOptionsINT, UINT, DINT, UDINT removed*)
		sfDOM_BOOL_AVAILABILITY_NUMBERS := 16#03, (*SafeCommissioningOptionsBIT and/or SafeNODE and SafeCommissioningOptionsINT, UINT, DINT, UDINT removed*)
		sfDOM_NODE := 16#04, (*SafeNode Commissioning Parameter removed*)
		sfDOM_NODE_BOOL_AVAILABILITY := 16#05, (*SafeNode Commissioning Parameter and SafeCommissioningOptionsBIT and/or SafeNODE removed*)
		sfDOM_NODE_NUMBERS := 16#06, (*SafeNode Commissioning Parameter and SafeCommissioningOptionsINT, UINT, DINT, UDINT removed*)
		sfDOM_BOOL_AVAIL_NUMBERS := 16#07 (*SafeNode Commissioning Parameter, SafeCommissioningOptionsBIT and/or SafeNODE and SafeCommissioningOptionsINT, UINT, DINT, UDINT removed*)
	);
	SfDomInternalIfType : 	STRUCT  (*Internal data*)
		vTable : DWORD;
	END_STRUCT;
	SfDomType : {REDUND_UNREPLICABLE} 	STRUCT 
	controlIf : REFERENCE TO SfDomInternalIfType;
	END_STRUCT;
	SfDomainPermLevelEnum : 
		( (*Permission levels*)
		sfDOM_PERMLEVEL_APPLENGINEER := 0, (*Application engineer*)
		sfDOM_PERMLEVEL_MAOPERATOR := 1 (*Machine operator*)
	);
	SfDomainCtrlCmdEnum : 
		( (*Control actions*)
		sfDOM_REBOOT := 0, (*Reboot of SafeLOGIC*)
		sfDOM_FORMAT_REBOOT := 1, (*Format and reboot of SafeLOGIC*)
		sfDOM_ACT_SETUP_MODE := 2 (*Activate Setup Mode*)
	);
	SfDomainTableTypeEnum :
		( (*Table type*)
		sfDOM_TableType_UNUSED := 0, (*Table type unused*)
		sfDOM_TableType_A := 1, (*Table type A*)
		sfDOM_TableType_B := 2, (*Table type B*)
		sfDOM_TableType_C := 3, (*Table type C*)
		sfDOM_TableType_D := 4, (*Table type D*)
		sfDOM_TableType_E := 5, (*Table type E*)
		sfDOM_TableType_S := 19, (*Table type S*)
		sfDOM_TableType_T := 20, (*Table type T*)
		sfDOM_TableType_U := 21, (*Table type U*)
		sfDOM_TableType_V := 22, (*Table type V*)
		sfDOM_TableType_W := 23 (*Table type W*)
	);
	SfDomainAcknowledgeEnum :
		( (*Acknowledge commands*)
		sfDOM_ACK_WAIT := 0, (*Wait for acknowledge*)
		sfDOM_ACK_ACKNOWLEDGE := 1, (*Set acknowledge command*)
		sfDOM_ACK_CANCEL := 2 (*Cancel acknowledge command*)
	);

	SfDomainTableInfoType : 	STRUCT (*Informations about remote downloaded SafeTABLES*)
		NumberOfRemoteTables : USINT; (*Number of remote downloaded SafeTABLES*)
		TableInfoStatusArray : ARRAY[0..98]OF SfDomainTableInfoStatusType; (* Status and information about remote SafeTABLES*)
	END_STRUCT;
	SfDomainTableInfoStatusType : 	STRUCT (*Status and information about remote downloaded SafeTABLES*)
		TableID : UINT; (*ID of SafeTABLE*)
		TableType : SfDomainTableTypeEnum; (*Type of SafeTABLE*)
		Acknowledged : BOOL; (*Indicates whether the SafeTABLE has already been acknowledged on the SafeDomain*)
	END_STRUCT;
	SfDomainSafeNodeAvailabilityEnum :
		( (*SafeNode Availability*)
		sfDOM_AV_PRESENT:= 0, (*Present*)
		sfDOM_AV_STARTUP := 1, (*Start up*)
		sfDOM_AV_OPTIONAL := 2, (*Optional*)
		sfDOM_AV_NOT_PRESENT := 3 (*Not Present*)
	);
END_TYPE
