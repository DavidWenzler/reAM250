                                                                      
 TYPE
	UASecurityMsgMode :
	(												(* Message security modes *)
    	UASecurityMsgMode_BestAvailable 	:= 0,	(* Detects best available mode the server provides (may result in no security) 	*)
	  	UASecurityMsgMode_None          	:= 1,	(* No secure communication 														*)
	  	UASecurityMsgMode_Sign          	:= 2,	(* Messages are signed to verify peer authenticity 								*)
	  	UASecurityMsgMode_SignEncrypt   	:= 3	(* Messages are signed and encrypted 											*)
	);
	
  	UASecurityPolicy :
  	(												(* Security policies *)
    	UASecurityPolicy_BestAvailable  	:= 0,	(* Detects best available policy the server provides (may result in no security)	*)
    	UASecurityPolicy_None           	:= 1,	(* No secure communication (Allowed only for security mode = none)					*)
    	UASecurityPolicy_Basic128Rsa15  	:= 2,	(* RSA-PKCS-#1-V1.5-SHA1/RSA-PKCS-#1-V1.5/128-512 bit, HMAC-SHA1/AES-128-CBC/16bit	*)
    	UASecurityPolicy_Basic256       	:= 3,	(* RSA-PKCS-#1-OAEP-SHA1/RSA-OAEP/128-512 bit, HMAC-SHA1/AES-256-CBC/32bit			*)
    	UASecurityPolicy_Basic256Sha256   	:= 4	(* RSA-PKCS-#1-OAEP-SHA1/RSA-OAEP/256-512 bit, HMAC-SHA1/AES-256-CBC/32bit			*)
  	);
  	
  	UATransportProfile :
  	(  												(* Transport profiles to select encoding and protocol *)
    	UATP_UATcp             				:= 1,	(* UA Binary over TCP								*)
    	UATP_WSHttpBinary      				:= 2,	(* Binary over HTTP			Not supported by B&R	*)
    	UATP_WSHttpXmlOrBinary 				:= 3,	(* XML/Binary over HTTP		Not supported by B&R	*)
    	UATP_WSHttpXml         				:= 4	(* XML over HTTP			Not supported by B&R	*)
  	);
  	
 	UAUserIdentityTokenTtype :
 	(  												(* Authentication token type provided for logon *)
 		UAUITT_Anonymous					:= 0,	(* Logon anonymously					*)
 		UAUITT_Username						:= 1,	(* Logon with user name and password 	*)
 		UAUITT_x509							:= 2	(* Logon with user certificate			*)
 	);
	 
	UAIdentifierType :
	(												(* Node identifier type *)
		UAIdentifierType_String 			:= 1,	(* String			*)
		UAIdentifierType_Numeric 			:= 2,	(* Numeric value	*)
		UAIdentifierType_GUID 				:= 3,	(* GUID				*)
		UAIdentifierType_Opaque				:= 4	(* ByteString		*)
	);
	
	UADeadbandType :
	(												(* Deadband type for monitored item sampling *)
		UADeadbandType_None 				:= 0,	(* No deadband, each value change is sampled						*)
		UADeadbandType_Absolute 			:= 1,	(* Absolute value to exceed from last sample to make new sample		*)
		UADeadbandType_Percent				:= 2	(* Percent of EURange to exceed from last sample to make new sample	*)
	);
	
	UANodeClass :
	(												(* Node classes defined through the OPC-UA standard *)
		UANodeClass_None 					:= 0,
		UANodeClass_Object					:= 1,
		UANodeClass_Variable 				:= 2,
		UANodeClass_Method					:= 4,
		UANodeClass_ObjectType				:= 8,
		UANodeClass_VariableType			:= 16,
		UANodeClass_ReferenceType			:= 32,
		UANodeClass_DataType				:= 64,
		UANodeClass_View					:= 128,
		UANodeClass_All						:= 255	
	);
	
	UAAttributeId :
	(												(* Attributes defined through the OPC-UA standard *)
	  	UAAI_Default						:= 0,
		UAAI_NodeId							:= 1,
		UAAI_NodeClass						:= 2,
		UAAI_BrowseName						:= 3,
		UAAI_DisplayName					:= 4,
		UAAI_Description					:= 5,
		UAAI_WriteMask						:= 6,
		UAAI_UserWriteMask					:= 7,
		UAAI_IsAbstract						:= 8,
		UAAI_Symmetric						:= 9,
		UAAI_InverseName					:= 10,
		UAAI_ContainsNoLoops				:= 11,
		UAAI_EventNotifier					:= 12,
		UAAI_Value							:= 13,
		UAAI_DataType						:= 14,
		UAAI_ValueRank						:= 15,
		UAAI_ArrayDimensions				:= 16,
		UAAI_AccessLevel					:= 17,
		UAAI_UserAccessLevel				:= 18,
		UAAI_MinimumSamplingInterval		:= 19,
		UAAI_Historizing					:= 20,
		UAAI_Executable						:= 21,
		UAAI_UserExecutable					:= 22
	);
	  
	UAConnectionStatus :
	(												(* Status of the underlying connection		*)
		UACS_Connected						:= 0,
		UACS_ConnectionError				:= 1,
		UACS_Shutdown						:= 2
	);
	  
	UAServerState :
	(												(* State of the server *)
		UASS_Running						:= 0,	(* The server has successfully completed the start-up and can be used *)
		UASS_Failed							:= 1,	(* An error occurred during server start-up. The Server is no longer functioning *)
		UASS_NoConfiguration				:= 2,	(* The Server is running but has no configuration information loaded and therefore does not transfer data *)
		UASS_Suspended						:= 3,	(* The Server has been temporarily suspended and is not receiving or sending data *)
		UASS_Shutdown						:= 4,	(* The server has not yet completed the start-up or has been shut down *)
		UASS_Test							:= 5,	(* The Server is in test mode *)
		UASS_CommunicationFault				:= 6,	(* The Server is running properly, but is having difficulty accessing data from its data sources *)
		UASS_Unknown              			:= 7	(* The Server does not know the state of underlying system *)
	);

	UAVariantType :				
	(												(* Kind of the variant data *)
		UAVariantType_Null					:= 0,	(* No data *)
		UAVariantType_Boolean				:= 1,	(* Data in element Boolean *)
		UAVariantType_SByte					:= 2,	(* Data in element SByte *)
		UAVariantType_Byte					:= 3,	(* Data in element Byte *)
		UAVariantType_Int16					:= 4,	(* Data in element Int16 *)
		UAVariantType_UInt16				:= 5,	(* Data in element UInt16 *)
		UAVariantType_Int32					:= 6,	(* Data in element Int32 *)
		UAVariantType_UInt32				:= 7,	(* Data in element UInt32 *)
		UAVariantType_Int64					:= 8,	(* Data in element Int64 *)
		UAVariantType_UInt64				:= 9,	(* Data in element UInt64 *)
		UAVariantType_Float					:= 10,	(* Data in element Float *)
		UAVariantType_Double				:= 11,	(* Data in element Double *)
		UAVariantType_String				:= 12,	(* Data in element String *)
		UAVariantType_DateTime				:= 13,	(* Data in element DateTime *)
		UAVariantType_Guid					:= 14,	(* Guid data in element String *)
		UAVariantType_ByteString			:= 15,	(* Byte string in element String *)
		UAVariantType_XmlElement			:= 16,	(* XML data in element String *)
		UAVariantType_NodeId				:= 17,	(* Data in element NodeId *)
		UAVariantType_ExpandedNodeId		:= 18,	(* Data in element ExpandedNodeId *)
		UAVariantType_StatusCode			:= 19,	(* Status code in element UInt32 *)
		UAVariantType_QualifiedName			:= 20,	(* Data in element QualifiedName *)
		UAVariantType_LocalizedText			:= 21	(* Data in element LocalizedText *)
	);
	
	UAArrayLength : DINT;							(* Arraylength of value attribute in AttributeRead and AttributeWrite services *)

	UANoOfElements : DINT;							(* Number of elements for arrays nested in structures *)

   	UAUserIdentityToken : STRUCT 					(* Identity token for authentication on an OPC-UA server *)
		UserIdentityTokenType	: UAUserIdentityTokenTtype;	
		TokenParam1 			: STRING[255];
		TokenParam2				: STRING[255];
	END_STRUCT;
 
 	UASessionConnectInfo : STRUCT 					(* Session information and parameters *)
 	  	SessionName   			: STRING[255];
 	  	ApplicationName   		: STRING[255];
 	  	SecurityMsgMode   		: UASecurityMsgMode;
    	SecurityPolicy   		: UASecurityPolicy;
		CertificateStore		: STRING[255];
		ClientCertificateName	: STRING[255];
		ServerUri				: STRING[255];
		CheckServerCertificate	: BOOL;
    	TransportProfile 		: UATransportProfile;
    	UserIdentityToken		: UAUserIdentityToken;
		VendorSpecificParameter	: STRING[255];
    	SessionTimeout   		: TIME;
    	MonitorConnection		: TIME;
    	LocaleIDs				: ARRAY[0..4] OF STRING[6];
	END_STRUCT;
	
  	UANodeID : STRUCT 											(* Node identifier used to address nodes on the server		*)
		NamespaceIndex			: UINT;							(* Index of the namespace which contains the node			*)
		Identifier 				: STRING[255];					(* Node identifier according to the identifier types format *)	
		IdentifierType			: UAIdentifierType; 			(* String, Numeric, GUID, ByteString						*)
	END_STRUCT;

	UAMonitoringSettings : STRUCT								(* Settings for data item monitoring						*) 
		SamplingInterval		: TIME;							(* Time in ms 												*)
		DeadbandType			: UADeadbandType; 				(* Deadband type which applies to deadband value			*)
		Deadband				: REAL; 						(* Deadband value, semantics depending on DeadbandType 		*)
	END_STRUCT;
	
	UAMonitoringParameters : STRUCT								(* Settings for data item monitoring								*)
		SamplingInterval		: TIME;							(* Time in ms 														*)
		QueueSize				: UINT;							(* Size of the server sided queue to collect value changes			*)
		DiscardOldest			: BOOL;							(* True to discard oldest on queue overflow or newest otherwise		*)
		DeadbandType			: UADeadbandType; 				(* Deadband type which applies to deadband value					*)
		Deadband				: REAL; 						(* Deadband value, semantics depending on DeadbandType 				*)
	END_STRUCT;
	
	UALocalizedText : STRUCT									(* Localized text with locale identifer and text		*)
		Locale					: STRING[6];
		Text					: STRING[255];
	END_STRUCT;
	
	UANodeInfo : STRUCT											(* Node attribute values		*)
		AccessLevel 			: BYTE;
		ArrayDimension			: ARRAY[0..MAX_INDEX_ARRAYDIMENSION] OF UDINT;
		BrowseName				: STRING[255];
		ContainsNoLoops 		: BOOL; 
		DataType				: UANodeID;
		Description				: UALocalizedText;
		DisplayName				: UALocalizedText;
		EventNotifier			: BYTE;
		Executable				: BOOL;
		Historizing				: BOOL;
		InverseName				: STRING[255];
		IsAbstract				: BOOL; 
		MinimumSamplingInterval	: TIME;
		NodeClass				: UANodeClass;
		NodeID					: UANodeID;
		Symmetric				: BOOL;
		UserAccessLevel			: BYTE;
		UserExecutable			: BOOL; 
		UserWriteMask			: UDINT;
		ValueRank				: DINT; 
		WriteMask				: UDINT;	
	END_STRUCT;	
	
	UAIndexRange : STRUCT										(* Index range used for indexed access on arrays	*)
		StartIndex				: UINT;	
		EndIndex 				: UINT;	
	END_STRUCT;
	
	UANodeAdditionalInfo : STRUCT								(* Additional info for reading and writing node attributes	*)
		AttributeId				: UAAttributeId;
		IndexRangeCount			: UINT;
		IndexRange 				: ARRAY[0..MAX_INDEX_INDEXRANGE] OF UAIndexRange;
	END_STRUCT;
	
	UAMethodArgument : STRUCT						(* Method argument used to supply the input and receive the output argument values for method calls *)
		Name					: STRING[64];		(* Name of the method argument																		*)
		Value					: STRING[255];		(* Source/Destination variable name for the argument value											*)
	END_STRUCT;

	UAByteString : STRUCT							(* Byte string containing length and data	*)
		Length					: DINT;
		Data					: ARRAY[0..MAX_INDEX_BYTESTRING] OF USINT;
	END_STRUCT;

	UAExpandedNodeID : STRUCT 						(* Expanded node identfier type *) 
		NodeId					: UANodeID;
		NamespaceUri			: STRING[255];
		ServerIndex				: UDINT;
	END_STRUCT;

	UAQualifiedName : STRUCT						(* Qualified name type *) 
		NamespaceIndex			: UINT;
		Name					: STRING[255];
	END_STRUCT;
	
	UARelativePathElement : STRUCT					(* Relative path element used to build a relative path	*)
	    ReferenceTypeId			: UANodeID;
		IsInverse				: BOOL;
		IncludeSubTypes			: BOOL;
		TargetName				: UAQualifiedName;
	END_STRUCT;
	
	UARelativePath : STRUCT							(* Relative path used to translate and browse nodes	*)
	    NoOfElements			: DWORD;
		Elements				: ARRAY[0..MAX_INDEX_RELATIVEPATH] OF UARelativePathElement;
	END_STRUCT;

	UADataValue : STRUCT							(* Additional informations about data value *) 
		Valid 					: BOOL;
		Reserved				: ARRAY[0..2]OF USINT; 
		StatusCode				: UDINT;
		SourceTimestamp			: DATE_AND_TIME;
		ServerTimestamp			: DATE_AND_TIME;
	END_STRUCT;

	UAVariantData : STRUCT							(* Standard type for variant data *) 
		VariantType				: UAVariantType;
		Boolean					: BOOL;
		SByte					: SINT;
		Byte					: USINT;
		Int16					: INT;
		UInt16					: UINT;
		Int32					: DINT;
		UInt32					: UDINT;
		Float					: REAL;
		Double					: LREAL;
		DateTime				: DATE_AND_TIME;
		String					: STRING[255];
		NodeId					: UANodeID;
		ExpandedNodeId			: UAExpandedNodeID;
		QualifiedName			: UAQualifiedName;
		LocalizedText			: UALocalizedText;
		DataValue				: UADataValue;
	END_STRUCT;

	UARange : STRUCT								(* Range for a value *)
		Low						: LREAL;
		High					: LREAL;
	END_STRUCT;

	UAEUInformation : STRUCT 						(* Information about the engineering units *)
		NamespaceUri			: STRING[255];
		UnitId					: DINT;
		DisplayName				: UALocalizedText;
		Description				: UALocalizedText;
	END_STRUCT;

	UATimeZoneData : STRUCT							(* Information about time zone	*)
		TimeOffset				: INT;				(* Offset in minutes from UTC	*)
		DaylightSaving			: BOOL;				(* Offset includes the DST		*)
	END_STRUCT;

	BrUaNodeId					: UANodeID;
	BrUaQualifiedName			: UAQualifiedName;
	BrUaLocalizedText			: UALocalizedText;
	BrUaByteString				: UAByteString;
	BrUaGuidString				: STRING[36];

	BrUaXmlElement : STRUCT
		Length					: DINT;
		Data					: STRING[65535];
	END_STRUCT;

	BrUaImageBMP : STRUCT
		Length					: DINT;
		Data					: ARRAY[0..6291455] OF USINT;
	END_STRUCT;
	BrUaImageGIF : STRUCT
		Length					: DINT;
		Data					: ARRAY[0..524287] OF USINT;
	END_STRUCT;
	BrUaImageJPG : STRUCT
		Length					: DINT;
		Data					: ARRAY[0..1048575] OF USINT;
	END_STRUCT;
	BrUaImagePNG : STRUCT
		Length					: DINT;
		Data					: ARRAY[0..2621439] OF USINT;
	END_STRUCT;

	BrUaDuration				: LREAL;
	BrUaLocaleIdString			: STRING[6];

	BrUaTimeZoneDataType		: UATimeZoneData;

END_TYPE
