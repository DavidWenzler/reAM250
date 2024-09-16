                                                                       
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapDT : DATE_AND_TIME        (*swaps the byte order of a DATE_AND_TIME value*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapTIME : TIME               (*swaps the byte order of a TIME value*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapDATE : DATE               (*swaps the byte order of a DATE value*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapTOD : TOD                 (*swaps the byte order of a TOD value*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapREAL : REAL               (*swaps the byte order of a REAL value*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapLREAL : LREAL             (*swaps the byte order of a LREAL value*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapUDINT : UDINT             (*swaps the byte order of an UDINT value*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapDINT : DINT               (*swaps the byte order of a DINT value*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapUINT : UINT               (*swaps the byte order of an UINT value*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapINT : INT                 (*swaps the byte order of an INT value*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapWORD : WORD               (*swaps the byte order of a WORD value*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION swapDWORD : DWORD             (*swaps the byte order of a DWORD value*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HDT : DATE_AND_TIME      (*converts a DATE_AND_TIME value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HTIME : TIME             (*converts a TIME value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HDATE : DATE             (*converts a DATE value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HTOD : TOD               (*converts a TOD value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HREAL : REAL             (*converts a REAL value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HLREAL : LREAL           (*converts a LREAL value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HUDINT : UDINT           (*converts a UDINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HDINT : DINT             (*converts a DINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HUINT : UINT             (*converts a UINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION N_TO_HINT : INT               (*converts an INT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NDT : DATE_AND_TIME      (*converts a DATE_AND_TIME value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NTIME : TIME             (*converts a TIME value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NDATE : DATE             (*converts a DATE value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NTOD : TOD               (*converts a TOD value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NREAL : REAL             (*converts a REAL value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NLREAL : LREAL           (*converts a LREAL value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NUDINT : UDINT           (*converts a UDINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NDINT : DINT             (*converts a DINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NUINT : UINT             (*converts a UINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION H_TO_NINT : INT               (*converts an INT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION

(*BOOL_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_BYTE : BYTE           (*converts a BOOL value (1 bit) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_WORD : WORD           (*converts a BOOL value (1 bit) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_DWORD : DWORD         (*converts a BOOL value (1 bit) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_SINT : SINT           (*converts a BOOL value (1 bit) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_INT : INT             (*converts a BOOL value (1 bit) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_DINT : DINT           (*converts a BOOL value (1 bit) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_USINT : USINT         (*converts a BOOL value (1 bit) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_UINT : UINT           (*converts a BOOL value (1 bit) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_UDINT : UDINT         (*converts a BOOL value (1 bit) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_TIME : TIME           (*converts a BOOL value (1 bit) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_DT : DATE_AND_TIME    (*converts a BOOL value (1 bit) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_DATE : DATE           (*converts a BOOL value (1 bit) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_TOD : TOD             (*converts a BOOL value (1 bit) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_REAL : REAL           (*converts a BOOL value (1 bit) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_LREAL : LREAL         (*converts a BOOL value (1 bit) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_STRING : STRING[80]   (*converts a BOOL value (1 bit) to a STRING value with variable length*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BOOL_TO_WSTRING : WSTRING[80] (*converts a BOOL value (1 bit) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION

(*BYTE_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_BOOL : BOOL           (*converts a BYTE value (8 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_WORD : WORD           (*converts a BYTE value (8 bits unsigned) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_DWORD : DWORD         (*converts a BYTE value (8 bits unsigned) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_SINT : SINT           (*converts a BYTE value (8 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_INT : INT             (*converts a BYTE value (8 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_DINT : DINT           (*converts a BYTE value (8 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_USINT : USINT         (*converts a BYTE value (8 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_UINT : UINT           (*converts a BYTE value (8 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_UDINT : UDINT         (*converts a BYTE value (8 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_TIME : TIME           (*converts a BYTE value (8 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_DT : DT               (*converts a BYTE value (8 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_DATE : DATE           (*converts a BYTE value (8 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_TOD : TOD             (*converts a BYTE value (8 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_REAL : REAL           (*converts a BYTE value (8 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_LREAL : LREAL         (*converts a BYTE value (8 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_STRING : STRING[80]   (*converts a BYTE value (8 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION BYTE_TO_WSTRING : WSTRING[80] (*converts a BYTE value (8 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:BYTE;                     (*input value*)
	END_VAR
END_FUNCTION

(*WORD_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_BOOL : BOOL           (*converts a WORD value (16 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_BYTE : BYTE           (*converts a WORD value (16 bits unsigned) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_DWORD : DWORD         (*converts a WORD value (16 bits unsigned) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_SINT : SINT           (*converts a WORD value (16 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_INT : INT             (*converts a WORD value (16 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_DINT : DINT           (*converts a WORD value (16 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_USINT : USINT         (*converts a WORD value (16 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_UINT : UINT           (*converts a WORD value (16 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_UDINT : UDINT         (*converts a WORD value (16 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_TIME : TIME           (*converts a WORD value (16 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_DT : DT               (*converts a WORD value (16 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_DATE : DATE           (*converts a WORD value (16 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_TOD : TOD             (*converts a WORD value (16 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_REAL : REAL           (*converts a WORD value (16 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_LREAL : LREAL         (*converts a WORD value (16 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_STRING : STRING[80]   (*converts a WORD value (16 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WORD_TO_WSTRING : WSTRING[80] (*converts a WORD value (16 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:WORD;                     (*input value*)
	END_VAR
END_FUNCTION

(*DWORD_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_BOOL : BOOL          (*converts a DWORD value (32 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_BYTE : BYTE          (*converts a DWORD value (32 bits unsigned) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_WORD : WORD          (*converts a DWORD value (32 bits unsigned) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_SINT : SINT          (*converts a DWORD value (32 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_INT : INT            (*converts a DWORD value (32 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_DINT : DINT          (*converts a DWORD value (32 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_USINT : USINT        (*converts a DWORD value (32 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_UINT : UINT          (*converts a DWORD value (32 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_UDINT : UDINT        (*converts a DWORD value (32 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_TIME : TIME          (*converts a DWORD value (32 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_DT : DT              (*converts a DWORD value (32 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_DATE : DATE          (*converts a DWORD value (32 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_TOD : TOD            (*converts a DWORD value (32 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_REAL : REAL          (*converts a DWORD value (32 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_LREAL : LREAL        (*converts a DWORD value (32 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_STRING : STRING[80]  (*converts a DWORD value (32 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DWORD_TO_WSTRING : WSTRING[80] (*converts a DWORD value (32 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:DWORD;                    (*input value*)
	END_VAR
END_FUNCTION

(*SINT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_BOOL : BOOL           (*converts a SINT value (8 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_BYTE : BYTE           (*converts a SINT value (8 bits signed) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_WORD : WORD           (*converts a SINT value (8 bits signed) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_DWORD : DWORD         (*converts a SINT value (8 bits signed) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_INT : INT             (*converts a SINT value (8 bits signed) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_DINT : DINT           (*converts a SINT value (8 bits signed) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_USINT : USINT         (*converts a SINT value (8 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_UINT : UINT           (*converts a SINT value (8 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_UDINT : UDINT         (*converts a SINT value (8 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_TIME : TIME           (*converts a SINT value (8 bits signed) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_DT : DT               (*converts a SINT value (8 bits signed) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_DATE : DATE           (*converts a SINT value (8 bits signed) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_TOD : TOD             (*converts a SINT value (8 bits signed) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_REAL : REAL           (*converts a SINT value (8 bits signed) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_LREAL : LREAL         (*converts a SINT value (8 bits signed) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_STRING : STRING[80]   (*converts a SINT value (8 bits signed) to a STRING value with variable length*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SINT_TO_WSTRING : WSTRING[80] (*converts a SINT value (8 bits signed) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION

(*INT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_BOOL : BOOL            (*converts an INT value (16 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_BYTE : BYTE            (*converts an INT value (16 bits signed) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_WORD : WORD            (*converts an INT value (16 bits signed) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_DWORD : DWORD          (*converts an INT value (16 bits signed) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_SINT : SINT            (*converts an INT value (16 bits signed) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_DINT : DINT            (*converts an INT value (16 bits signed) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_USINT : USINT          (*converts an INT value (16 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_UINT : UINT            (*converts an INT value (16 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_UDINT : UDINT          (*converts an INT value (16 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_TIME : TIME            (*converts an INT value (16 bits signed) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_DT : DT                (*converts an INT value (16 bits signed) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_DATE : DATE            (*converts an INT value (16 bits signed) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_TOD : TOD              (*converts an INT value (16 bits signed) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_REAL : REAL            (*converts an INT value (16 bits signed) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_LREAL : LREAL          (*converts an INT value (16 bits signed) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_STRING : STRING[80]    (*converts an INT value (16 bits signed) to a STRING value with variable length*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INT_TO_WSTRING : WSTRING[80]  (*converts an INT value (16 bits signed) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION

(*DINT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_BOOL : BOOL           (*converts a DINT value (32 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_BYTE : BYTE           (*converts a DINT value (32 bits signed) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_WORD : WORD           (*converts a DINT value (32 bits signed) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_DWORD : DWORD         (*converts a DINT value (32 bits signed) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_SINT : SINT           (*converts a DINT value (32 bits signed) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_INT : INT             (*converts a DINT value (32 bits signed) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_USINT : USINT         (*converts a DINT value (32 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_UINT : UINT           (*converts a DINT value (32 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_UDINT : UDINT         (*converts a DINT value (32 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_TIME : TIME           (*converts a DINT value (32 bits signed) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_DT : DT               (*converts a DINT value (32 bits signed) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_DATE : DATE           (*converts a DINT value (32 bits signed) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_TOD : TOD             (*converts a DINT value (32 bits signed) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_REAL : REAL           (*converts a DINT value (32 bits signed) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_LREAL : LREAL         (*converts a DINT value (32 bits signed) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_STRING : STRING[80]   (*converts a DINT value (32 bits signed) to a STRING value with variable length*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DINT_TO_WSTRING : WSTRING[80] (*converts a DINT value (32 bits signed) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION

(*USINT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_BOOL : BOOL          (*converts a USINT value (8 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_BYTE : BYTE          (*converts a USINT value (8 bits unsigned) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_WORD : WORD          (*converts a USINT value (8 bits unsigned) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_DWORD : DWORD        (*converts a USINT value (8 bits unsigned) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_SINT : SINT          (*converts a USINT value (8 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_INT : INT            (*converts a USINT value (8 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_DINT : DINT          (*converts a USINT value (8 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_UINT : UINT          (*converts a USINT value (8 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_UDINT : UDINT        (*converts a USINT value (8 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_TIME : TIME          (*converts a USINT value (8 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_DT : DT              (*converts a USINT value (8 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_DATE : DATE          (*converts a USINT value (8 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_TOD : TOD            (*converts a USINT value (8 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_REAL : REAL          (*converts a USINT value (8 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_LREAL : LREAL        (*converts a USINT value (8 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_STRING : STRING[80]  (*converts a USINT value (8 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION USINT_TO_WSTRING : WSTRING[80] (*converts a USINT value (8 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION

(*UINT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_BOOL : BOOL           (*converts a UINT value (16 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_BYTE : BYTE           (*converts a UINT value (16 bits unsigned) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_WORD : WORD           (*converts a UINT value (16 bits unsigned) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_DWORD : DWORD         (*converts a UINT value (16 bits unsigned) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_SINT : SINT           (*converts a UINT value (16 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_INT : INT             (*converts a UINT value (16 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_DINT : DINT           (*converts a UINT value (16 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_USINT : USINT         (*converts a UINT value (16 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_UDINT : UDINT         (*converts a UINT value (16 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_TIME : TIME           (*converts a UINT value (16 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_DT : DT               (*converts a UINT value (16 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_DATE : DATE           (*converts a UINT value (16 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_TOD : TOD             (*converts a UINT value (16 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_REAL : REAL           (*converts a UINT value (16 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_LREAL : LREAL         (*converts a UINT value (16 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_STRING : STRING[80]   (*converts a UINT value (16 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UINT_TO_WSTRING : WSTRING[80] (*converts a UINT value (16 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION

(*UDINT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_BOOL : BOOL          (*converts a UDINT value (32 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_BYTE : BYTE          (*converts a UDINT value (32 bits unsigned) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_WORD : WORD          (*converts a UDINT value (32 bits unsigned) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_DWORD : DWORD        (*converts a UDINT value (32 bits unsigned) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_SINT : SINT          (*converts a UDINT value (32 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_INT : INT            (*converts a UDINT value (32 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_DINT : DINT          (*converts a UDINT value (32 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_USINT : USINT        (*converts a UDINT value (32 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_UINT : UINT          (*converts a UDINT value (32 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_TIME : TIME          (*converts a UDINT value (32 bits unsigned) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_DT : DT              (*converts a UDINT value (32 bits unsigned) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_DATE : DATE          (*converts a UDINT value (32 bits unsigned) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_TOD : TOD            (*converts a UDINT value (32 bits unsigned) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_REAL : REAL          (*converts a UDINT value (32 bits unsigned) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_LREAL : LREAL        (*converts a UDINT value (32 bits unsigned) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_STRING : STRING[80]  (*converts a UDINT value (32 bits unsigned) to a STRING value with variable length*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION UDINT_TO_WSTRING : WSTRING[80] (*converts a UDINT value (32 bits unsigned) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION

(*TIME_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_BOOL : BOOL           (*converts a TIME value (32 bits time in milliseconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_BYTE : BYTE           (*converts a TIME value (32 bits time in milliseconds) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_WORD : WORD           (*converts a TIME value (32 bits time in milliseconds) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_DWORD : DWORD         (*converts a TIME value (32 bits time in milliseconds) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_SINT : SINT           (*converts a TIME value (32 bits time in milliseconds) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_INT : INT             (*converts a TIME value (32 bits time in milliseconds) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_DINT : DINT           (*converts a TIME value (32 bits time in milliseconds) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_USINT : USINT         (*converts a TIME value (32 bits time in milliseconds) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_UINT : UINT           (*converts a TIME value (32 bits time in milliseconds) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_UDINT : UDINT         (*converts a TIME value (32 bits time in milliseconds) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_DT : DT               (*converts a TIME value (32 bits time in milliseconds) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_DATE : DATE           (*converts a TIME value (32 bits time in milliseconds) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_TOD : TOD             (*converts a TIME value (32 bits time in milliseconds) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_REAL : REAL           (*converts a TIME value (32 bits time in milliseconds) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_LREAL : LREAL         (*converts a TIME value (32 bits time in milliseconds) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_STRING : STRING[80]   (*converts a TIME value (32 bits time in milliseconds) to a STRING value with variable length*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIME_TO_WSTRING : WSTRING[80] (*converts a TIME value (32 bits time in milliseconds) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION

(*DT_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_BOOL : BOOL             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_BYTE : BYTE             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_WORD : WORD             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_DWORD : DWORD           (*converts a DATE_AND_TIME value (32 bits date in seconds) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_SINT : SINT             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_INT : INT               (*converts a DATE_AND_TIME value (32 bits date in seconds) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_DINT : DINT             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_USINT : USINT           (*converts a DATE_AND_TIME value (32 bits date in seconds) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_UINT : UINT             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_UDINT : UDINT           (*converts a DATE_AND_TIME value (32 bits date in seconds) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_TIME : TIME             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_DATE : DATE             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_TOD : TOD               (*converts a DATE_AND_TIME value (32 bits date in seconds) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_REAL : REAL             (*converts a DATE_AND_TIME value (32 bits date in seconds) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_LREAL : LREAL           (*converts a DATE_AND_TIME value (32 bits date in seconds) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:DT;                       (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_STRING : STRING[80]   (*converts a DATE_AND_TIME value (32 bits date in seconds) to a STRING value with variable length*)
	VAR_INPUT
		IN	:DT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DT_TO_WSTRING : WSTRING[80] (*converts a DATE_AND_TIME value (32 bits date in seconds) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:DT;                     (*input value*)
	END_VAR
END_FUNCTION

(*DATE_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_BOOL : BOOL           (*converts a DATE value (32 bits date in seconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_BYTE : BYTE           (*converts a DATE value (32 bits date in seconds) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_WORD : WORD           (*converts a DATE value (32 bits date in seconds) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_DWORD : DWORD         (*converts a DATE value (32 bits date in seconds) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_SINT : SINT           (*converts a DATE value (32 bits date in seconds) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_INT : INT             (*converts a DATE value (32 bits date in seconds) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_DINT : DINT           (*converts a DATE value (32 bits date in seconds) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_USINT : USINT         (*converts a DATE value (32 bits date in seconds) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_UINT : UINT           (*converts a DATE value (32 bits date in seconds) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_UDINT : UDINT         (*converts a DATE value (32 bits date in seconds) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_TIME : TIME           (*converts a DATE value (32 bits date in seconds) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_DT : DT               (*converts a DATE value (32 bits date in seconds) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_TOD : TOD             (*converts a DATE value (32 bits date in seconds) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_REAL : REAL           (*converts a DATE value (32 bits date in seconds) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_LREAL : LREAL         (*converts a DATE value (32 bits date in seconds) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_STRING : STRING[80]   (*converts a DATE value (32 bits date in seconds) to a STRING value with variable length*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DATE_TO_WSTRING : WSTRING[80] (*converts a DATE value (32 bits date in seconds) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:DATE;                     (*input value*)
	END_VAR
END_FUNCTION

(*TOD_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_BOOL : BOOL            (*converts a TOD value (32 bits time of day in milliseconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_BYTE : BYTE            (*converts a TOD value (32 bits time of day in milliseconds) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_WORD : WORD            (*converts a TOD value (32 bits time of day in milliseconds) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_DWORD : DWORD          (*converts a TOD value (32 bits time of day in milliseconds) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_SINT : SINT            (*converts a TOD value (32 bits time of day in milliseconds) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_INT : INT              (*converts a TOD value (32 bits time of day in milliseconds) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_DINT : DINT            (*converts a TOD value (32 bits time of day in milliseconds) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_USINT : USINT          (*converts a TOD value (32 bits time of day in milliseconds) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_UINT : UINT            (*converts a TOD value (32 bits time of day in milliseconds) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_UDINT : UDINT          (*converts a TOD value (32 bits time of day in milliseconds) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_TIME : TIME            (*converts a TOD value (32 bits time of day in milliseconds) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_DT : DT                (*converts a TOD value (32 bits time of day in milliseconds) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_DATE : DATE            (*converts a TOD value (32 bits time of day in milliseconds) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_REAL : REAL            (*converts a TOD value (32 bits time of day in milliseconds) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_LREAL : LREAL          (*converts a TOD value (32 bits time of day in milliseconds) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:TOD;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_STRING : STRING[80]   (*converts a TOD value (32 bits time of day in milliseconds) to a STRING value with variable length*)
	VAR_INPUT
		IN	:TOD;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TOD_TO_WSTRING : WSTRING[80] (*converts a TOD value (32 bits time of day in milliseconds) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:TOD;                     (*input value*)
	END_VAR
END_FUNCTION

(*REAL_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_BOOL : BOOL           (*converts a REAL value (32 bits floating point number) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_BYTE : BYTE           (*converts a REAL value (32 bits floating point number) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_WORD : WORD           (*converts a REAL value (32 bits floating point number) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_DWORD : DWORD         (*converts a REAL value (32 bits floating point number) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_SINT : SINT           (*converts a REAL value (32 bits floating point number) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_INT : INT             (*converts a REAL value (32 bits floating point number) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_DINT : DINT           (*converts a REAL value (32 bits floating point number) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_USINT : USINT         (*converts a REAL value (32 bits floating point number) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_UINT : UINT           (*converts a REAL value (32 bits floating point number) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_UDINT : UDINT         (*converts a REAL value (32 bits floating point number) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_TIME : TIME           (*converts a REAL value (32 bits floating point number) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_DT : DT               (*converts a REAL value (32 bits floating point number) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_DATE : DATE           (*converts a REAL value (32 bits floating point number) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_TOD : TOD             (*converts a REAL value (32 bits floating point number) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_LREAL : LREAL         (*converts a REAL value (32 bits floating point number) to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_STRING : STRING[80]   (*converts a REAL value (32 bits floating point number) to a STRING value with variable length*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REAL_TO_WSTRING : WSTRING[80] (*converts a REAL value (32 bits floating point number) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION

(*LREAL_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_BOOL : BOOL          (*converts a LREAL value (64 bits floating point number) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_BYTE : BYTE          (*converts a LREAL value (64 bits floating point number) to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_WORD : WORD          (*converts a LREAL value (64 bits floating point number) to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_DWORD : DWORD        (*converts a LREAL value (64 bits floating point number) to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_SINT : SINT          (*converts a LREAL value (64 bits floating point number) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_INT : INT            (*converts a LREAL value (64 bits floating point number) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_DINT : DINT          (*converts a LREAL value (64 bits floating point number) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_USINT : USINT        (*converts a LREAL value (64 bits floating point number) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_UINT : UINT          (*converts a LREAL value (64 bits floating point number) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_UDINT : UDINT        (*converts a LREAL value (64 bits floating point number) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_TIME : TIME          (*converts a LREAL value (64 bits floating point number) to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_DT : DT              (*converts a LREAL value (64 bits floating point number) to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_DATE : DATE          (*converts a LREAL value (64 bits floating point number) to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_TOD : TOD            (*converts a LREAL value (64 bits floating point number) to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_REAL : REAL          (*converts a LREAL value (64 bits floating point number) to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_STRING : STRING[80]   (*converts a LREAL value (64 bits floating point number) to a STRING value with variable length*)
	VAR_INPUT
		IN	:LREAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LREAL_TO_WSTRING : WSTRING[80] (*converts a LREAL value (64 bits floating point number) to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:LREAL;                     (*input value*)
	END_VAR
END_FUNCTION

(*STRING_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_BOOL : BOOL         (*converts a STRING value with variable length to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_BYTE : BYTE         (*converts a STRING value with variable length to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_WORD : WORD         (*converts a STRING value with variable length to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_DWORD : DWORD       (*converts a STRING value with variable length to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_SINT : SINT         (*converts a STRING value with variable length to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_INT : INT           (*converts a STRING value with variable length to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_DINT : DINT         (*converts a STRING value with variable length to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_USINT : USINT       (*converts a STRING value with variable length to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_UINT : UINT         (*converts a STRING value with variable length to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_UDINT : UDINT       (*converts a STRING value with variable length to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_TIME : TIME         (*converts a STRING value with variable length to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_DT : DT             (*converts a STRING value with variable length to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_DATE : DATE         (*converts a STRING value with variable length to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_TOD : TOD           (*converts a STRING value with variable length to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_REAL : REAL         (*converts a STRING value with variable length to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_LREAL : LREAL       (*converts a STRING value with variable length to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION STRING_TO_WSTRING : WSTRING   (*converts a STRING value with variable length to a WSTRING value with variable length*)
	VAR_INPUT
		IN	:STRING[80];               (*input value*)
	END_VAR
END_FUNCTION

(*WSTRING_TO_ functions*)
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_BOOL : BOOL        (*converts a WSTRING value with variable length to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_BYTE : BYTE        (*converts a WSTRING value with variable length to a BYTE value (8 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_WORD : WORD        (*converts a WSTRING value with variable length to a WORD value (16 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_DWORD : DWORD      (*converts a WSTRING value with variable length to a DWORD value (32 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_SINT : SINT        (*converts a WSTRING value with variable length to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_INT : INT          (*converts a WSTRING value with variable length to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_DINT : DINT        (*converts a WSTRING value with variable length to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_USINT : USINT      (*converts a WSTRING value with variable length to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_UINT : UINT        (*converts a WSTRING value with variable length to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_UDINT : UDINT      (*converts a WSTRING value with variable length to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_TIME : TIME        (*converts a WSTRING value with variable length to a TIME value (32 bits time in milliseconds)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_DT : DT            (*converts a WSTRING value with variable length to a DATE_AND_TIME value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_DATE : DATE        (*converts a WSTRING value with variable length to a DATE value (32 bits date in seconds)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_TOD : TOD          (*converts a WSTRING value with variable length to a TOD value (32 bits time of day in milliseconds)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_REAL : REAL        (*converts a WSTRING value with variable length to a REAL value (32 bits floating point number)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_LREAL : LREAL      (*converts a WSTRING value with variable length to a LREAL value (64 bits floating point number)*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION WSTRING_TO_STRING : STRING[80] (*converts a WSTRING value with variable length to a STRING value with variable length*)
	VAR_INPUT
		IN	:WSTRING[80];              (*input value*)
	END_VAR
END_FUNCTION
