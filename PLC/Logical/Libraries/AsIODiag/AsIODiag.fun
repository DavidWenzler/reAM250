                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DiagCreateInfo			(*collects information about the currently configured and/or inserted hardware modules; asynchronous execution*)
	VAR_INPUT
		enable       : BOOL; 			(*enables execution*)
		infoKind     : UDINT; 			(*type of information to be generated, e.g. asdiagPLUGGED, asdiagCONFIGURED, ..*)
	END_VAR

	VAR
        StateMan     : UINT;			(*internal variable*)
        ErrMan       : UINT;			(*internal variable*)
        Init         : UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status       : UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
        ident        : UDINT;			(*identifier of the generated information*)
        nrEntries    : UDINT;			(*number of generated information entries*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DiagDisposeInfo			(*frees up the resources taken up by DiagCreateInfo(); asynchronous execution*)
	VAR_INPUT
		enable       : BOOL; 			(*enables execution*)
        ident        : UDINT;			(*identifier of the information to be freed up*)
	END_VAR

	VAR
        StateMan     : UINT;			(*internal variable*)
        ErrMan       : UINT;			(*internal variable*)
        Init         : UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status  : UINT; 				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DiagGetNumInfo			(*queries the numeric value of a specified information entry*)
	VAR_INPUT
		enable       : BOOL; 			(*enables execution*)
        ident        : UDINT;			(*identifier returned from DiagCreateInfo()*)
        index        : UDINT;			(*index of the entry [0..nrEntries-1]*)
        infoCode     : UDINT;			(*code of the desired information, e.g. asdiagMODUL_STATE, asdiagPLUGGED_MODNO, ..*)
	END_VAR

	VAR_OUTPUT
		status  : UINT; 				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
        value   : UDINT;				(*numeric value*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DiagGetStrInfo			(*queries the string value of a specified information entry*)
	VAR_INPUT
		enable       : BOOL; 			(*enables execution*)
        ident        : UDINT;			(*identifier returned from DiagCreateInfo()*)
        index        : UDINT;			(*index of the entry [0..nrEntries-1]*)
        infoCode     : UDINT;			(*code of the desired information*)
        pBuffer      : UDINT;			(*pointer to the return buffer*)
        bufferLen    : UDINT;			(*size of the return buffer*)
	END_VAR

	VAR_OUTPUT
		status   : UINT; 				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
        stringLen: UDINT;				(*string length of the original data*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DiagCpuIsSimulated : BOOL 			(*queries if CPU is simulated *)

END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DiagCpuIsARsim : BOOL 			(*queries if CPU is ARsim *)

END_FUNCTION

