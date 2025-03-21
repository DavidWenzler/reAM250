
TYPE
	MpComFacilitiesEnum : 
		(
		mpCOM_FAC_UNDEFINED := -1, (*No active error*)
		mpCOM_FAC_ARCORE := 0, (*Facility for legacy error code from AR libraries in UINT format*)
		mpCOM_FAC_SAFETY1 := 1, (*Safety facility*)
		mpCOM_FAC_SAFETY2 := 2, (*Safety facility*)
		mpCOM_FAC_GMC1 := 96, (*GMC facility*)
		mpCOM_FAC_GMC2 := 97, (*GMC facility*)
		mpCOM_FAC_GMCAXIS := 98, (*GMC Axis facility*)
		mpCOM_FAC_GMCAXESGROUP := 99, (*GMC Axes group facility*)
		mpCOM_FAC_GMCARNCGROUP := 103, (*GMC Arnc group facility*)
		mpCOM_FAC_TRF := 105, (*TRF facility*)
		mpCOM_FAC_MAPP_INTERNAL := 144, (*mapp Internal Facility*)
		mpCOM_FAC_MAPP_CORE := 145, (*mapp Core Facility*)
		mpCOM_FAC_MAPP_INFRASTRUCTURE := 146, (*mapp Infrastructure Facility*)
		mpCOM_FAC_MAPP_MECHATRONIC := 147, (*mapp Mechatronics Facility*)
		mpCOM_FAC_MAPP_INDUSTRY := 148 (*mapp Industry Facility*)
		);
	MpComSeveritiesEnum : 
		(
		mpCOM_SEV_SUCCESS := 0, (*Success - no error*)
		mpCOM_SEV_INFORMATIONAL := 1, (*Severity: Informational*)
		mpCOM_SEV_WARNING := 2, (*Severity: Warning*)
		mpCOM_SEV_ERROR := 3 (*Severity: Error*)
		);
	MpComIdentType : {REDUND_UNREPLICABLE} 	STRUCT 
		Internal : {REDUND_UNREPLICABLE} ARRAY[0..1]OF UDINT; (*For internal use only*)
	END_STRUCT;
	MpComInternalDataType : {REDUND_UNREPLICABLE} 	STRUCT 
		pObject : {REDUND_UNREPLICABLE} UDINT;
		State : {REDUND_UNREPLICABLE} UDINT;
	END_STRUCT;
	MpComConfigInternalType : {REDUND_UNREPLICABLE} 	STRUCT 
		pObject : {REDUND_UNREPLICABLE} UDINT;
		State : {REDUND_UNREPLICABLE} DINT;
	END_STRUCT;
	MpComInternalIDType : 	STRUCT 
		ID : DINT; (*Status ID*)
		Severity : MpComSeveritiesEnum; (*Status severity*)
		Facility : MpComFacilitiesEnum; (*Status facility*)
		Code : UINT; (*Status / Error code*)
	END_STRUCT;
END_TYPE
