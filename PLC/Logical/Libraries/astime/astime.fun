                                                                      
{REDUND_OK} FUNCTION_BLOCK DTExSetTime					(*sets the current time using the DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*date and time to be written*)
		Option	:USINT;						(*additional option: timEXSETTIME_NO_OPTION, timEXSETTIME_NO_LOGENTRY*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK DTSetTime					(*sets current time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*date and time to be written*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK DTGetTime					(*reads the current time in the DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		DT1	:DATE_AND_TIME;					(*date and time read*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION clock_ms : TIME					(*provides a continuous millisecond counter in the TIME data type*)
END_FUNCTION

{REDUND_OK} FUNCTION_BLOCK UtcDTGetTime					(*reads the current UTC-time in the DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		DT1	:DATE_AND_TIME;					(*UTC date and time read*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTSetTime					(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*UTC date and time to be written*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTExSetTime				(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*UTC date and time to be written*)
		Option	:USINT;						(*additional option: timEXSETTIME_NO_OPTION, timEXSETTIME_NO_LOGENTRY*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DTStructureGetTime			(*reads the current time in the calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)		
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DTStructureSetTime			(*sets current time in calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)	
	END_VAR		
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DTStructureExSetTime			(*sets current time in calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
		Option	:USINT;						(*additional option: timEXSETTIME_NO_OPTION, timEXSETTIME_NO_LOGENTRY*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)	
	END_VAR		
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTStructureGetTime		(*reads the UTC time in the calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)		
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTStructureSetTime		(*sets UTC time in calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTStructureExSetTime		(*sets UTC time in calendar structure*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
		Option	:USINT;						(*additional option: timEXSETTIME_NO_OPTION, timEXSETTIME_NO_LOGENTRY*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDT_TO_LocalDTStructure	(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*UTC date and time*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR	
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR	
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK LocalDT_TO_UtcDTStructure	(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		DT1	:DATE_AND_TIME;					(*Local date and time*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UtcDTStructure_TO_LocalDT	(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		DT1	:DATE_AND_TIME;					(*Local date and time*)
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR	
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR	
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK LocalDTStructure_TO_UtcDT	(*sets current UTC-time in DATE_AND_TIME data type*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
	VAR_OUTPUT		
		DT1	:DATE_AND_TIME;					(*UTC date and time*)
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ascTIMEStructure : UDINT			(*converts a "time" structure to a character string in the format "15:14:13\0"*)
	VAR_INPUT
		pTIMEStructure	:UDINT;				(*address of the time structure*)
		pStr	:UDINT;						(*address of the character field*)
		len	:UDINT;							(*length of the character field *)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ascDTStructure : UDINT				(*converts a "date" structure to a character string in the format "Sun Jan 3 15:14:13 1988\0"*)
	VAR_INPUT
		pDTStructure	:UDINT;				(*address of the calendar structure *)
		pStr	:UDINT;						(*address of the character field*)
		len	:UDINT;							(*length of the character field*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ascTIME : UDINT					(*converts the TIME data type to a character string in the format "15:14:13\0"*)
	VAR_INPUT
		TIME1	:TIME;						(*time*)
		pStr	:UDINT;						(*address of the character field*)
		len	:UDINT;							(*length of the character field*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ascDT : UDINT						(*converts the DATE_AND_TIME data type to character string in the format "Sun Jan 3 15:14:13 1988\0"*)
	VAR_INPUT
		DT1	:DATE_AND_TIME;					(*date and time*)
		pStr	:UDINT;						(*address of the character field*)
		len	:UDINT;							(*length of the character field*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TIMEStructure_TO_TIME : TIME		(*converts a "time" structure to the TIME data type*)
	VAR_INPUT
		pTIMEStructure	:UDINT;				(*address of the time structure*)
	END_VAR	
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_TIMEStructure : UDINT		(*converts the TIME data type to a "time" structure*)
	VAR_INPUT
		TIME1	:TIME;						(*time*)
		pTIMEStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION DTStructure_TO_DT : DATE_AND_TIME	(*converts a "date" structure to the DATE_AND_TIME data type*)
	VAR_INPUT	
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION DT_TO_DTStructure : UDINT			(*converts the DATE_AND_TIME data type to a "date" structure*)
	VAR_INPUT
		DT1	:DATE_AND_TIME;					(*date and time*)
		pDTStructure	:UDINT;				(*address of the calendar structure*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION DiffT : UDINT						(*shows the difference between two times (TIME data type) expressed in milliseconds*)
	VAR_INPUT
		TIME2	:TIME;						(*time 2*)
		TIME1	:TIME;						(*time 1*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION DiffDT : UDINT						(*shows the difference between two times (DATE_AND_TIME data type) expressed in seconds*)
	VAR_INPUT
		DT2	:DATE_AND_TIME;					(*date and time 2*)
		DT1	:DATE_AND_TIME;					(*date and time 1*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TimeDeviceGetInfo		(*read information about time device*)
	VAR_INPUT
		enable			:BOOL;			(*enables execution*)
		pServer			:UDINT;			(*Pointer to string*)
		len				:USINT;			(*length of pServer*)
	END_VAR
	VAR_OUTPUT
		timeDevice		:USINT;			(*sntpREAL_TIME_CLOCK or sntpTIME_SERVER*)		
		avgDeviation	:REAL;			(*average deviation between software time and time device*)	
		status			:UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			:UINT;			(*internal variable*)
		i_result		:UINT;			(*internal variable*)
        i_tmp			:UDINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DstGetInfo				(*read information about time device*)
	VAR_INPUT
		enable			:BOOL;			(*enables execution*)
		pDTStructure	:UDINT;			(*Pointer to DTStructure*)
	END_VAR
	VAR_OUTPUT
		dstState		:USINT;			(*timDAYLIGHT_SAVING_TIME, timNORMAL_TIME or timNO_DST*)			
		status			:UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			:UINT;			(*internal variable*)
		i_result		:UINT;			(*internal variable*)
        i_tmp			:UDINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DstGetInfoDT				(*read information about time device*)
	VAR_INPUT
		enable			:BOOL;			(*enables execution*)
		DT1				:DATE_AND_TIME;	(*date and time in UTC*)
	END_VAR
	VAR_OUTPUT
		dstState		:USINT;			(*timDAYLIGHT_SAVING_TIME, timNORMAL_TIME or timNO_DST*)			
		status			:UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)	
	END_VAR		
	VAR
        i_state			:UINT;			(*internal variable*)
		i_result		:UINT;			(*internal variable*)
        i_tmp			:UDINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
