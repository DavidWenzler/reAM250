                                                                      
{REDUND_OK} FUNCTION SIZEOF : UDINT 		(*determines the size of a variable in bytes*)
	VAR_INPUT
		in	:ANY;				(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ADR : UDINT 			(*determines the address of a data point*)
	VAR_INPUT
		in	:ANY;				(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ADRINST : UDINT 		(*determines the address of a fub instance*)
END_FUNCTION
{REDUND_OK} FUNCTION SHR : ANY 				(*shifts bitwise to the right*)
	VAR_INPUT
		IN	:ANY;				(*input value*)
		N	:SINT;				(*number of bits to be shifted*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ROR : ANY 				(*rotates bitwise to the right*)
	VAR_INPUT
		IN	:ANY;				(*input value*)
		N	:SINT;				(*number of bits to be rotated*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ROL : ANY 				(*rotates bitwise to the left*)
	VAR_INPUT
		IN	:ANY;				(*input value*)
		N	:SINT;				(*number of bits to be rotated*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION SHL : ANY 				(*shifts bitwise to the left*)
	VAR_INPUT
		IN	:ANY;				(*input value*)
		N	:SINT;				(*number of bits to be shifted*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION AND : ANY 				(*makes a bitwise AND relation for 2 or more variables*)
	VAR_INPUT
		INx	:ANY;				(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION XOR : ANY 				(*makes a bitwise XOR relation for 2 or more variables*)
	VAR_INPUT
		INx	:ANY;				(*input values*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION OR : ANY 				(*makes a bitwise OR relation for 2 or more variables*)
	VAR_INPUT
		INx	:ANY;				(*input values*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION NOT : ANY 				(*makes a bitwise inversion of variables*)
	VAR_INPUT
		IN	:ANY;				(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ADD : ANY 				(*adds 2 or more variables*)
	VAR_INPUT
		INx	:ANY;				(*input values*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MUL : ANY_NUM 			(*multiplies 2 or more variables*)
	VAR_INPUT
		INx	:ANY_NUM;			(*input values*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION SUB : ANY 				(*subtracts one or more variables from another variable*)
	VAR_INPUT
		IN1	:ANY;				(*value 1*)
		IN2	:ANY;				(*value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION DIV : ANY_NUM 			(*divides a variable by one or more variables*)
	VAR_INPUT
		IN1	:ANY_NUM;			(*dividend*)
		IN2	:ANY_NUM;			(*divisor*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MOD : ANY_INT 			(*makes a remainder when dividing a variable by another variable*)
	VAR_INPUT
		IN1	:ANY_INT;			(*dividend*)
		IN2	:ANY_INT;			(*divisor*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MOVE : ANY 			(*copies the contents of the input variables to the corresponding output variables*)
	VAR_INPUT
		IN	:ANY;				(*input variable*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MAX : ANY 				(*determines the maximum value of two or more values*)
	VAR_INPUT
		IN1	:ANY;				(*input value 1*)
		IN2	:ANY;				(*input value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MIN : ANY 				(*determines the lowest value of two or more values*)
	VAR_INPUT
		IN1	:ANY;				(*input value 1*)
		IN2	:ANY;				(*input value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION LIMIT : ANY 			(*limits a value to within maximum and minimum boundaries*)
	VAR_INPUT
		MN	:ANY;				(*minimum value*)
		IN	:ANY;				(*input value*)
		MX	:ANY;				(*maximum value*)
	END_VAR		
END_FUNCTION
{REDUND_OK} FUNCTION SEL : ANY 				(*selects one value from two values*)
	VAR_INPUT
		G	:BOOL;				(*selection variable*)
		IN0	:ANY;				(*input value for FALSE*)
		IN1	:ANY;				(*input value for TRUE*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION MUX : ANY 				(*selects a value from several values*)
	VAR_INPUT
		K	:SINT;				(*selection variable*)
		INx	:ANY;				(*input values*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION GE : BOOL 				(*checks if the input values are in decreasing order*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION EQ : BOOL 				(*compares two or more values whether they are equal*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION GT : BOOL 				(*checks if the input values are in decreasing order*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION LE : BOOL 				(*checks if the input values are in increasing order*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION LT : BOOL 				(*checks if the input values are in increasing order*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION NE : BOOL 				(*compares two values whether they are not equal*)
	VAR_INPUT
		IN1	:ANY;				(*comparison value 1*)
		IN2	:ANY;				(*comparison value 2*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ABS : ANY_NUM 			(*returns the absolute value of a number*)
	VAR_INPUT
		IN	:ANY_NUM;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION SQRT : ANY_REAL 		(*returns the square root of a number*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION LN : ANY_REAL 			(*returns the result of a natural logarithm*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION LOG : ANY_REAL 		(*returns the result of a base 10 logarithm*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION EXP : ANY_REAL 		(*returns the result of a natural exponential function*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION SIN : ANY_REAL 		(*returns the sine of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value in radian*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION COS : ANY_REAL 		(*returns the cosine of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value in radian*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION TAN : ANY_REAL 		(*returns the tangent of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value in radian*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ASIN : ANY_REAL 		(*returns the arc sine (inverse function of sine) of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ACOS : ANY_REAL 		(*returns the arc cosine (inverse function of cosine) of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION ATAN : ANY_REAL 		(*returns the arc tangent (inverse function of tangent) of a number (calculated in radian)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION EXPT : REAL 			(*raises one variable to the power of another*)
	VAR_INPUT
		IN1	:REAL;				(*base*)
		IN2	:ANY_NUM;			(*exponent*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION TRUNC : INT 			(*converts from type REAL to type INT (number is always rounded down)*)
	VAR_INPUT
		IN	:ANY_REAL;			(*input value*)
	END_VAR
END_FUNCTION
