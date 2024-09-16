                                                                      
TYPE
    fiDIR_READ_DATA		: STRUCT						(*directory read structure*)
        Filename		: ARRAY[0..259] OF USINT;		(*file name*)
        Date			: DATE_AND_TIME;				(*date and time*)
        Filelength		: UDINT;						(*file length*)
	END_STRUCT;

    fiDIR_READ_EX_DATA	: STRUCT						(*directory read extended structure*)
        Filename		: ARRAY[0..259] OF USINT;		(*file name*)
        Date			: DATE_AND_TIME;				(*date and time*)
        Filelength		: UDINT;						(*file length*)
        Mode			: UINT;							(*mode*)
	END_STRUCT;

	fiFILE_INFO			: STRUCT						(*file information structure*)
		size			: UDINT;						(*size of file [bytes]*)
		linkCnt			: UDINT;						(*link count*)
		accTime			: DATE_AND_TIME;				(*time of last access*)
		modTime			: DATE_AND_TIME;				(*time of last data modification*)
		chgTime			: DATE_AND_TIME;				(*time of last file status change*)
		reserved		: ARRAY[0..20] OF UDINT;		(*reserved for future use*)
	END_STRUCT;
END_TYPE
