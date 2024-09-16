
TYPE
    MpAxisErrorEnum : 
        ( (* Error numbers of library MpAxis *)
        mcAXIS_NO_ERROR := 0, (* No error *)
        mcAXIS_ERR_PLC_OPEN := -1067278080, (* PLCopen error: {1:ErrorCode} Message: {2:ErrorMessage} [Error: 41216, 0xc062a100] *)
        mcAXIS_WRN_PLC_OPEN := -2141019903, (* PLCopen warning: {1:ErrorCode} Message: {2:ErrorMessage} [Warning: 41217, 0x8062a101] *)
        mcAXIS_WRN_MULTIPLE_COMMAND := -2141019902, (* Multiple commands enabled simultaneously [Warning: 41218, 0x8062a102] *)
        mcAXIS_ERR_RECOVERY_NOT_ALLOWED := -1067278072, (* Recovery not allowed for current coupling parametrization [Error: 41224, 0xC062A108] *)
        mcAXIS_ERR_ACTIVATION := -1064239103, (* Could not create component [Error: 1, 0xc0910001] *)
        mcAXIS_ERR_MPLINK_NULL := -1064239102, (* MpLink is NULL pointer [Error: 2, 0xc0910002] *)
        mcAXIS_ERR_MPLINK_INVALID := -1064239101, (* MpLink connection not allowed [Error: 3, 0xc0910003] *)
        mcAXIS_ERR_MPLINK_CHANGED := -1064239100, (* MpLink modified [Error: 4, 0xc0910004] *)
        mcAXIS_ERR_MPLINK_CORRUPT := -1064239099, (* Invalid MpLink contents [Error: 5, 0xc0910005] *)
        mcAXIS_ERR_MPLINK_IN_USE := -1064239098, (* MpLink already in use [Error: 6, 0xc0910006] *)
        mcAXIS_ERR_PAR_NULL := -1064239097 (* Parameters structure is a null pointer [Error: 7, 0xc0910007] *)
        );
END_TYPE
