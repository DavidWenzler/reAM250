                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileCreate				(*creates a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pFile		: UDINT;			(*pointer to the file name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident		: UDINT;			(*identifier of the created file*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileOpen					(*opens a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pFile		: UDINT;			(*pointer to the file name*)
		mode		: USINT;			(*access mode (FILE_R, FILE_W, FILE_RW)*) 
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident		: UDINT;			(*identifier of the created file*)
		filelen		: UDINT;			(*file length*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileClose				(*closes an open file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the created file*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileRead					(*reads from an open file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the created file*)
		offset		: UDINT;			(*offset*)
		pDest		: UDINT;			(*pointer to the read buffer*)
		len			: UDINT;			(*length of bytes to read*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileReadEx				(*reads from an open file and returns the number of actually read bytes; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the created file*)
		offset		: UDINT;			(*offset*)
		pDest		: UDINT;			(*pointer to the read buffer*)
		len			: UDINT;			(*number of bytes to read*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		bytesread	: UDINT;			(*number of bytes read*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileWrite				(*writes to a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the created file*)
		offset		: UDINT;			(*offset*)
		pSrc		: UDINT;			(*pointer to the write buffer*)
		len			: UDINT;			(*number of bytes to write*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileWriteEx				(*writes to a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the created file*)
		offset		: UDINT;			(*offset*)
		pSrc		: UDINT;			(*pointer to the write buffer*)
		len			: UDINT;			(*number of bytes to write*)
		option		: UDINT;			(*options*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileRename				(*renames files; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the file name*)
		pNewName	: UDINT;			(*pointer to the new file name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileCopy					(*copies a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pSrcDev		: UDINT;			(*pointer to the source file device name*)
		pSrc		: UDINT;			(*pointer to the existing file name*)
		pDestDev	: UDINT;			(*pointer to the destination file device name*)
		pDest		: UDINT;			(*pointer to the copy file name*)
		option		: USINT;			(*copy option*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileDelete				(*deletes a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the file name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileInfo					(*gets information about a file; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*file name given as pointer*)
		pInfo		: UDINT;			(*file information (fiFILE_INFO) structure given as pointer*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FileTruncate				(*truncates a file's length; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*file name given as pointer*)
		newLength	: UDINT;			(*new length*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirCreate				(*creates a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the directory name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirOpen					(*opens a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the directory name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident		: UDINT;			(*identifier of the directory*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirClose					(*closes a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the directory*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirRead					(*reads the individual file names in a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pPath		: UDINT;			(*pointer to the path string*)
		entry		: UDINT;			(*specifies which entry should be read*)
		option		: USINT;			(*specifies whether directory names or filenames should be read*)
		pData		: UDINT;			(*pointer to the memory area where the information is copied*)
		data_len	: UDINT;			(*length of the provided data area*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirReadEx				(*reads the individual file or directory names in a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		ident		: UDINT;			(*identifier of the directory*)
		pData		: UDINT;			(*pointer to the memory area where the information is copied*)
		data_len	: UDINT;			(*length of the available data area*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirInfo					(*gets information about a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pPath		: UDINT;			(*pointer to the path (directory name)*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dirnum		: UDINT;			(*number of subdirectories in this directory*)
		filenum		: UDINT;			(*number of files in this directory*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirRename				(*renames directories; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the directory name*)
		pNewName	: UDINT;			(*pointer to the new directory name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirCopy					(*copies a directory*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pSrcDev		: UDINT;			(*pointer to the source file device name*)
		pSrcDir		: UDINT;			(*pointer to the source directory name*)
		pDestDev	: UDINT;			(*pointer to the destination file device name*)
		pDestDir	: UDINT;			(*pointer to the destination directory name*)
		option		: USINT;			(*copy option*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirDelete				(*deletes a directory; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the directory name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DirDeleteEx				(*deletes a directory (all files and subdirectories); asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pName		: UDINT;			(*pointer to the directory name*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SetAttributes			(*sets attributes; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pPath		: UDINT;			(*pointer to the path name (file or directory)*)
		attributes	: USINT;			(*attributes*)
		option		: USINT;			(*set options*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK GetAttributes			(*reads attributes; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pPath		: UDINT;			(*pointer to the path name (file or directory)*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		attributes	: USINT;			(*attributes*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DevMemInfo				(*determines a file device's memory information; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		freemem		: UDINT;			(*available disk space*)
		memsize		: UDINT;			(*total disk space*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DevLink					(*creates the file device; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*new device name given as a pointer*)
		pParam		: UDINT;			(*pointer to the link parameter*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		handle		: UDINT;			(*file device handle*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DevUnlink				(*unlinks the device; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		handle		: UDINT;			(*file device handle*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK GetVolumeLabel			(*reads volume label; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
		pLabel		: UDINT;			(*buffer for volume label given as pointer*)
		labelMax	: UDINT;			(*size of buffer for volume label*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		labelLen	: UDINT;			(*length of volume label*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK GetVolumeSerialNo		(*reads volume serial nummer; asynchronous execution*)
	VAR_INPUT
		enable		: BOOL;				(*enables execution*)
		pDevice		: UDINT;			(*device name given as a pointer*)
	END_VAR

	VAR
        i_state		: UINT;				(*internal variable*)
		i_result	: UINT;				(*internal variable*)
        i_tmp		: UDINT;			(*internal variable*)
	END_VAR

	VAR_OUTPUT
		status		: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		serialNo	: UDINT;			(*volume serialNo*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION FileIoGetSysError	: UINT		(*reads system errors*)
END_FUNCTION
