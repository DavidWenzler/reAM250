                                                                      
TYPE
	TIMEStructure : STRUCT			(*time structure*)
		day	: SINT ;				(*day (1-31)*)
		hour	: USINT ;			(*hours (0-23)*)
		minute	: USINT ;			(*minutes (0-59)*)
		second	: USINT ;			(*seconds (0-59)*)
		millisec	: UINT ;		(*milliseconds (0-999)*)
		microsec	: UINT ;		(*microseconds (0-999)*)
	END_STRUCT;
	DTStructure : STRUCT			(*date structure*)
		year	: UINT ;			(*year*)
		month	: USINT ;			(*month (1-12)*)
		day	: USINT ;				(*day (1-31)*)
		wday	: USINT ;			(*day of the week (0-6), e.g. 0 = Sunday, 6 = Saturday*)
		hour	: USINT ;			(*hours (0-23)*)
		minute	: USINT ;			(*minutes (0-59)*)
		second	: USINT ;			(*seconds (0-59)*)
		millisec	: UINT ;		(*milliseconds (0-999)*)
		microsec	: UINT ;		(*microseconds (0-999)*)
	END_STRUCT;
END_TYPE
