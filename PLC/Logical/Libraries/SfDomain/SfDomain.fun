
FUNCTION_BLOCK SfDomainConnect (*Establishes a connection to the defined SafeDOMAIN with given user identification*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		UserName : STRING[80]; (*Logged in user name*) (* *) (*#PAR#;*)
		Password : STRING[80]; (*Password for the user for authentication*) (* *) (*#PAR#;*)
		UDID_Acknowledge : BOOL; (*Set true to acknowledge UDID change*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*Function block is busy processing a command*) (* *) (*#PAR#;*)
		Active : BOOL; (*Command has finished and was successful.*) (* *) (*#PAR#; *)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		SafeDomainID : UINT; (*ID of SafeDOMAIN to connect to*) (* *) (*#PAR#;*)
		CurrentUser : STRING[80]; (*Logged in user name*) (* *) (*#PAR#;*)
		PermissionLevel : SfDomainPermLevelEnum; (*Defines which permission level the connected user has*) (* *) (*#CMD#OPT#;*)
		UDID_low : UDINT; (*UDID low*) (* *) (*#CMD#OPT#;*)
		UDID_high : UINT; (*UDID high*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainTransfer (*Transfers a SafeAPPLICATION and/or a SafeCOMMISSIONING file to the connected SafeDOMAIN*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeAppFilePath : STRING[260]; (*Path to the safe application file.*) (* *) (*#PAR#;*)
		SafeCommFilePath : STRING[260]; (*Path to the safe commissioning file.*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Progress : USINT; (*Progress of the file transfer*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainCompletion (*Acknowledges the data of the connected SafeDOMAIN*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		Info : SfDomainInfoType; (*Information about SafeDOMAIN*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainInfo (*Reads status information from the SafeLOGIC and its SafeAPPLICATION and SafeCOMMISSIONING*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Info : SfDomainInfoType; (*Information structure, filled with information from the SafeDOMAIN*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainExchange (*Confirms requests from the SafeLOGIC of the connected SafeDOMAIN*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		Info : SfDomainInfoType; (*Information about SafeDOMAIN*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainControl (*Performs control actions on the connected SafeLOGIC*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		ControlCommand : SfDomainCtrlCmdEnum; (*Reboot/Format Execut comands*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainTableCompletion (*Acknowledge a remote downloaded SafeTABLE by checking all table attributes*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		TableID : UINT; (*TableID of SafeTABLE which should be acknowledged*) (* *) (*#PAR#;*)
		Acknowledge : SfDomainAcknowledgeEnum; (*Acknowledge or cancel SafeTABLE attributes*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		TableType : SfDomainTableTypeEnum; (*Type of SafeTABLE*) (* *) (*#CMD#OPT#;*)
		UserName : STRING[80]; (*Name of user who locked the SafeTABLE data*) (* *) (*#PAR#;*)
		TimeStamp : UDINT; (*Timestamp when SafeTABLE data was locked*) (* *) (*#CMD#*)
		AckCrc : UDINT; (*Acknowledge CRC which identifies the SafeTABLE*) (* *) (*#CMD#*)
		AcknowledgeRequired : BOOL; (*TRUE: SafeTABLE attributes can be checked and acknowledged manualy*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionBool (*Get the value and attributes from a SafeOPTION of type Bool*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : BOOL; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainLoadSafeOptions (*Load a SafeCOMMISSIONING file with SafeOPTIONs*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeCommFilePath : STRING[260]; (*File name of the SafeCOMMISSIONING file to be loaded.*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		FileCRC : UDINT; (*FileCRC which identifies the SafeCOMMISSIONING file.*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionBool (*Set the value of a SafeOPTION of type Bool*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : BOOL; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSaveSafeOptions (*Save a SafeCOMMISSIONING file with SafeOPTIONs*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeCommFilePath : STRING[260]; (*File name of the SafeCOMMISSIONING file to be saved.*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		FileCRC : UDINT; (*FileCRC which identifies the SafeCOMMISSIONING file.*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionSint (*Get the value and attributes from a SafeOPTION of type Sint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : SINT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : SINT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : SINT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : SINT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionSint (*Set the value of a SafeOPTION of type Sint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : SINT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionUsint (*Get the value and attributes from a SafeOPTION of type Usint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : USINT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : USINT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : USINT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : USINT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionUsint (*Set the value of a SafeOPTION of type Usint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : USINT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionInt (*Get the value and attributes from a SafeOPTION of type Int*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : INT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : INT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : INT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : INT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionInt (*Set the value of a SafeOPTION of type Int*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : INT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionUint (*Get the value and attributes from a SafeOPTION of type Uint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : UINT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : UINT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : UINT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : UINT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionUint (*Set the value of a SafeOPTION of type Uint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : UINT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionDint (*Get the value and attributes from a SafeOPTION of type Dint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : DINT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : DINT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : DINT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : DINT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionDint (*Set the value of a SafeOPTION of type Dint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : DINT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionUdint (*Get the value and attributes from a SafeOPTION of type Udint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : UDINT; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MinValue : UDINT; (*Minimal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		MaxValue : UDINT; (*Maximal value of selected SafeOPTION*) (* *) (*#PAR#;*)
		Step : UDINT; (*Step value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionUdint (*Set the value of a SafeOPTION of type Udint*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : UDINT; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeOptionString (*Get the value and attributes from a SafeOPTION of type String*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : STRING[260]; (*Actual value of selected SafeOPTION*) (* *) (*#PAR#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeOptionString (*Set the value of a SafeOPTION of type String*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : STRING[260]; (*Value of SafeOPTION to be set*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainGetSafeNodeAvailability (*Get the value and attributes from a SafeOPTION of type Availability*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be read*) (* *) (*#PAR#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
		Name : STRING[80]; (*Name of SafeOPTION*) (* *) (*#PAR#;*)
		Description : STRING[260]; (*Description of SafeOPTION*) (* *) (*#PAR#;*)
		Value : SfDomainSafeNodeAvailabilityEnum; (*Actual value of selected SafeOPTION*) (* *) (*#CMD#OPT#;*)
		ReadOnly : BOOL; (*Actual state of "ReadOnly"-Flag*) (* *) (*#PAR#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK SfDomainSetSafeNodeAvailability (*Set the value of a SafeOPTION of type Availability*)
	VAR_INPUT
		SfDomain : REFERENCE TO SfDomType; (*Incoming SafeDOMAIN handle*) (* *) (*#PAR#;*)
		Execute : BOOL; (*Executes the function block*) (* *) (*#PAR#;*)
		SafeOptionID : STRING[80]; (*ID of the SafeOPTION to be set*) (* *) (*#PAR#;*)
		Value : SfDomainSafeNodeAvailabilityEnum; (*Value of SafeOPTION to be set*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Has finished and was successful.*) (* *) (*#PAR#;*)
		Busy : BOOL; (*Function block is busy processing a command.*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates an error.*) (* *) (*#CMD#OPT#;*)
		StatusID : DINT; (*Error/Status information*) (* *) (*#CMD#*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} SfDomainInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK



