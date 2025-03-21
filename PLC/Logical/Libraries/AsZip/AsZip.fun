                                                                      
{REDUND_ERROR} FUNCTION_BLOCK zipArchive (*Creates an archive (.tar, .gz or .tar.gz)*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		pArchiveDevice	: UDINT;		(*device name of the archive file given as a pointer*)
		pArchiveFile	: UDINT;		(*file name of the archive file given as a pointer*)
		pSrcDevice		: UDINT;		(*device name of the source file or folder given as a pointer*)
		pSrcFile		: UDINT;		(*source folder or file given as a pointer*)
		pOptions		: UDINT;		(*additional options given as pointer*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK zipExtract (*Extracts an archive (.tar, .gz or .tar.gz)*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		pArchiveDevice	: UDINT;		(*device name of the archive given as a pointer*)
		pArchiveFile	: UDINT;		(*file name of the archive given as a pointer*)
		pOutDevice		: UDINT;		(*device name of the destination folder of the files to extract given as pointer*)
		pOutFolder		: UDINT;		(*destination folder name of the files to extract given as pointer*)
		pOptions		: UDINT;		(*additional options given as pointer*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
