                                                                      
{REDUND_OK} FUNCTION_BLOCK RF_TRIG 				(*recognizes both edges of BOOL values*)
	VAR_INPUT
		CLK	:BOOL;					(*input signal of the edge to be recognized*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*TRUE if the input signal was FALSE on the last call and is now TRUE*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK CTUD 				(*counts upward or downward*)
	VAR_INPUT
		CU	:BOOL;					(*counter CV is increased by 1 by CU when the edge is rising*)
		CD	:BOOL;					(*counter CV is reduced by 1 by CD when the edge is rising*)
		RESET	:BOOL;				(*counter CV is set to 0 if RESET is TRUE*)
		LOAD	:BOOL;				(*if LOAD is TRUE, then counter CV is initialized with the starting value PV*)
		PV	:INT;					(*start value*)
	END_VAR
	VAR_OUTPUT
		QU	:BOOL;					(*is TRUE if CV is greater than or equal to PV*)
		QD	:BOOL;					(*is TRUE if CV equals 0*)
		CV	:INT;					(*counter*)
	END_VAR
	VAR
		MU	:BOOL;					(*internal variable*)
		MD	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK CTD 					(*counts downward*)
	VAR_INPUT
		CD	:BOOL;					(*counter CV is reduced by 1 by CD when the edge is rising*)
		LOAD	:BOOL;				(*if LOAD is TRUE, then counter CV is initialized with the starting value PV*)
		PV	:UINT;					(*start value*)
	END_VAR
	VAR_OUTPUT	
		Q	:BOOL;					(*is TRUE if CV equals 0*)
		CV	:UINT;					(*counter*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK CTU 					(*counts upward*)
	VAR_INPUT
		CU	:BOOL;					(*counter CV is increased by 1 by CU when the edge is rising*)
		RESET	:BOOL;				(*counter CV is set to 0 if RESET is TRUE*)
		PV	:UINT;					(*comparison variable*)
	END_VAR	
	VAR_OUTPUT
		Q	:BOOL;					(*is TRUE if counter CV is greater than or equal to the PV comparison variable*)
		CV	:UINT;					(*counter*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK F_TRIG 				(*recognizes falling edges from BOOL values*)
	VAR_INPUT
		CLK	:BOOL;					(*input signal whose edge should be detected*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*is set to TRUE if the input signal was TRUE during the last call and is now FALSE*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK R_TRIG 				(*recognizes rising edges from BOOL values*)
	VAR_INPUT
		CLK	:BOOL;					(*input signal whose edge should be detected*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*is set to TRUE if the input signal was FALSE during the last call and is now TRUE*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK SR 					(*sets or resets the output (set has priority)*)
	VAR_INPUT
		SET1	:BOOL;				(*sets output Q1 (priority)*)
		RESET	:BOOL;				(*resets output Q1*)
	END_VAR
	VAR_OUTPUT
		Q1	:BOOL;					(*output value *)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK RS 					(*sets or resets the output (reset has priority)*)
	VAR_INPUT
		SET	:BOOL;					(*sets output Q1*)
		RESET1	:BOOL;				(*resets output Q1 (priority)*)
	END_VAR
	VAR_OUTPUT
		Q1	:BOOL;					(*output value*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK SEMA 				(*blocks access within the same task class (simple semaphore)*)
	VAR_INPUT
		CLAIM	:BOOL;				(*locks semaphore*)
		RELEASE	:BOOL;				(*releases semaphore*)
	END_VAR
	VAR_OUTPUT
		BUSY	:BOOL;				(*TRUE if the semaphore was already locked*)
	END_VAR
	VAR
		X	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TON 					(*implements a switch on delay*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:TIME;					(*delay time*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*rising edge of the input signal is delayed by PT*)
		ET	:TIME;					(*elapsed time*)
	END_VAR
	VAR
		StartTime	:TIME;			(*internal variable*)
		M	:BOOL;					(*internal variable*)
		Restart	: {REDUND_UNREPLICABLE} UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TOF 					(*implements a switch off delay*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:TIME;					(*delay time*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*falling edge of the input signal is delayed by PT*)
		ET	:TIME;					(*elapsed time*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
		StartTime	:TIME;			(*internal variable*)
		Restart	: {REDUND_UNREPLICABLE} UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TP 					(*implements a pulse generator*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:TIME;					(*pulse time*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*output signal*)
		ET	:TIME;					(*elapsed time*)
	END_VAR
	VAR
		StartTime	:TIME;			(*internal variable*)
		Restart	: {REDUND_UNREPLICABLE} UDINT; (*internal variable*)
	END_VAR	
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TON_10ms 			(*implements a switch on delay based on 10 ms steps*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:UDINT;					(*delay time in 10 ms steps*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*output signal, the rising edge of the input signal is delayed by PT*)
		ET	:UDINT;					(*elapsed time in 10 ms increments*)
	END_VAR
	VAR
		StartTime	:UDINT;			(*internal variable*)
		M	:BOOL;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TOF_10ms 			(*implements a switch off delay based on 10 ms steps*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:UDINT;					(*delay time in 10 ms steps*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*output signal, the falling edge of the input signal is delayed by PT*)
		ET	:UDINT;					(*elapsed time in 10 ms increments*)
	END_VAR
	VAR
		M	:BOOL;					(*internal variable*)
		StartTime	:UDINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} FUNCTION_BLOCK TP_10ms 				(*implements a pulse using 10 ms steps*)
	VAR_INPUT
		IN	:BOOL;					(*input signal*)
		PT	:UDINT;					(*pulse time in 10 ms steps*)
	END_VAR
	VAR_OUTPUT
		Q	:BOOL;					(*output signal*)
		ET	:UDINT;					(*elapsed time in 10 ms increments*)
	END_VAR	
	VAR
		StartTime	:UDINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LEN : INT 					(*calculates the length of a string*)
	VAR_INPUT
		IN	:STRING[32767];			(*input string*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION LEFT : STRING[255] 		(*extracts a certain amount (L) of leftmost characters from a string*)
	VAR_INPUT
		IN	:STRING[32767];			(*input string*)
		L	:INT;					(*number of characters*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION RIGHT : STRING[255] 		(*extracts a certain amount (L) of rightmost characters from a string*)
	VAR_INPUT
		IN	:STRING[32767];			(*input string*)
		L	:INT;					(*number of characters*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION MID : STRING[255] 			(*extracts L number of characters out of string beginning with position P*)
	VAR_INPUT
		IN	:STRING[32767];			(*string which should be extracted from*)
		L	:INT;					(*number of characters*)
		P	:INT;					(*position of the first character which should be extracted*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION CONCAT : STRING[255] 		(*attaches strings to one another*)
	VAR_INPUT
		IN1	:STRING[32767];			(*first input string*)
		IN2	:STRING[32767];			(*second input string*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION INSERT : STRING[255] 		(*inserts a string into a string*)
	VAR_INPUT
		IN1	:STRING[32767];			(*string which should be inserted into*)
		IN2	:STRING[32767];			(*string which should be inserted*)
		P	:INT;					(*position where insertion should take place*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION DELETE : STRING[255] 		(*deletes L number of characters from the IN string beginning with the Pth character position*)
	VAR_INPUT
		IN	:STRING[32767];			(*input string*)
		L	:INT;					(*number of characters to be deleted*)
		P	:INT;					(*starting position of characters to be deleted*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION REPLACE : STRING[255] 		(*replaces characters in a string*)
	VAR_INPUT
		IN1	:STRING[32767];			(*string which should have characters replaced*)
		IN2	:STRING[32767];			(*string used for the replacement*)
		L	:INT;					(*length of the area to be replaced*)
		P	:INT;					(*starting position of replacement*)
	END_VAR
END_FUNCTION
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION FIND : INT 				(*determines the position of a string inside a string*)
	VAR_INPUT
		IN1	:STRING[32767];			(*string which should be looked through*)
		IN2	:STRING[32767];			(*string which should be looked for*)
	END_VAR
END_FUNCTION
