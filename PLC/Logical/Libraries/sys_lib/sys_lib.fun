                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK Byte2Bit 				(*converts a byte array into a bit array*)
	VAR_INPUT
		byteadr	:UDINT;					(*byte array address*)
		length	:UINT;					(*byte array length (1 through 16)*)
	END_VAR
	VAR_OUTPUT
		bitadr	:UDINT;					(*bit array address*)
	END_VAR
	VAR
		bmem000	:BOOL;					(*internal variable*)
		static_val	:ARRAY[0..138] OF USINT;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK Bit2Byte 				(*converts a bit array into a byte array where every bit of data corresponds to an element in the bit array*)
	VAR_INPUT
		bitadr	:UDINT;					(*BIT array address*)
		length	:UINT;					(*BIT array length (1 through 128)*)
	END_VAR
	VAR_OUTPUT
		byteadr	:UDINT;					(*BYTE array address*)
	END_VAR	
	VAR
		byte_00	:USINT;					(*internal variable*)
		byte_01	:USINT;					(*internal variable*)
		byte_02	:USINT;					(*internal variable*)
		byte_03	:USINT;					(*internal variable*)
		byte_04	:USINT;					(*internal variable*)
		byte_05	:USINT;					(*internal variable*)
		byte_06	:USINT;					(*internal variable*)
		byte_07	:USINT;					(*internal variable*)
		byte_08	:USINT;					(*internal variable*)
		byte_09	:USINT;					(*internal variable*)
		byte_10	:USINT;					(*internal variable*)
		byte_11	:USINT;					(*internal variable*)
		byte_12	:USINT;					(*internal variable*)
		byte_13	:USINT;					(*internal variable*)
		byte_14	:USINT;					(*internal variable*)
		byte_15	:USINT;					(*internal variable*)
		bmem000	:BOOL;					(*internal variable*)
		static_val	:ARRAY[0..138] OF USINT;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION KEY_read : UINT 				(*reads the status of the keys on the CPU*)
	VAR_INPUT
		keys	:UDINT;					(*array variable for storing key states*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION KEY_enadis : UINT 				(*disables key handling by the operating system (operating mode 0)*)
	VAR_INPUT
		mode	:BOOL;					(*operating mode: 0 ... key handling by the operating system, 1 ... key handling by an application program*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_fix : UINT 					(*transfers a data object to the FIXRAM*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_info : UINT 				(*provides information about the data object*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
		moduldata_adr	:UDINT;			(*data address in the data object*)
		moduldata_len	:UDINT;			(*pointer to length of the data (in bytes)*)
		memorytype	:UDINT;				(*pointer to memory type*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_copy : UINT 				(*copies a data object into the specified memory (RAM, User ROM, MEMCARD or FIXRAM) under the name new_name*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
		new_name	:UDINT;				(*pointer to name of the new data object*)
		mem_typ	:USINT;					(*memory type, e.g. 1...RAM, 2...User ROM, ..*)
		da_ident	:UDINT;				(*pointer to ID number of the copied data object*)
		daten_p	:UDINT;					(*data address in the new data object*)
		daten_len	:UDINT;				(*pointer to data length in the new data object (in bytes)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_store : UINT 				(*saves a data object in the specified memory (RAM, UserROM, MEMCARD or FIXRAM)*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
		mem_typ	:USINT;					(*memory type, e.g. 1...RAM, 2...User ROM, ..*)
		daten_p	:UDINT;					(*data address in the new data object*)
		daten_len	:UDINT;				(*pointer to data length in the new data object (in bytes)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_burn : UINT 				(*transfers a data object to UserROM*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_delete : UINT 				(*deletes a data object from the memory (RAM, User ROM, MEMCARD or FIXRAM)*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_ident : UINT 				(*provides the ID number of an existing data object*)
	VAR_INPUT
		name_p	:UDINT;					(*pointer to name of the data object*)
		grp	:USINT;						(*group number (standard = 0)*)
		mo_ident	:UDINT;				(*pointer to ID number of the data object*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_read : UINT 				(*reads data from a module in the RAM or FIXRAM*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
		data_p	:UDINT;					(*pointer to data range*)
		data_len	:UDINT;				(*length of the data (in bytes)*)
		mo_data_offset	:UDINT;			(*offset in the data area of the module*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_write : UINT 				(*writes data to a data object in RAM or FIXRAM*)
	VAR_INPUT
		mo_ident	:UDINT;				(*ID number from DA_create() or DA_ident()*)
		data_p	:UDINT;					(*pointer to data range*)
		data_len	:UDINT;				(*length of the data (in bytes)*)
		mo_data_offset	:UDINT;			(*offset in the data area of the module*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DA_create : UINT 				(*generates a data object with corresponding parameter in the RAM*)
	VAR_INPUT
		name_p	:UDINT;					(*pointer to name of the data object*)
		grp	:USINT;						(*group Number (standard = 0)*)
		spooladr	:UINT;				(*spool address (standard = 0)*)
		data_len	:UDINT;				(*length of the data (in bytes)*)
		data_p	:UDINT;					(*pointer to data which is written in the data object*)
		mo_data_p	:UDINT;				(*data address in the data object*)
		mo_ident	:UDINT;				(*pointer to ID number of the data object*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DIS_clr : UINT 				(*clears the CPU status display (B&R 2010 system only)*)
	VAR_INPUT
		dummy_input	:USINT;				(*required for operation in ladder diagram*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DIS_chr : UINT 				(*writes a ASCII character to the CPU status display*)
	VAR_INPUT
		row	:UDINT;						(*row number (0 or 1) where the ASCII character is to be output*)
		col	:UDINT;						(*column number (0 through 7) where the ASCII character is to be output*)
		character	:SINT;				(*ASCII character that is to be output on the status display*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION DIS_str : UINT 				(*writes a character string to the CPU status display*)
	VAR_INPUT
		row	:UDINT;						(*row number (0 or 1) where the string is to be output*)
		col	:UDINT;						(*column number (0 through 7) from where the string is to be output*)
		string	:UDINT;					(*pointer to string (ending in zero) that is to be output on the status display*)
	END_VAR		
END_FUNCTION

{REDUND_ERROR} FUNCTION ERRxfatal : UINT 				(*makes an log book entry in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
		errorstring	:UDINT;				(*pointer to string, ending in zero (32 characters maximum)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERR_read : UINT 				(*reads an entry from the error log book and writes the information in a structure (ERR_typ_struct)*)
	VAR_INPUT
		entry_nr	:UINT;				(*number of the log book entry that is to be read*)
		ERR_typ_struct	:UDINT;			(*pointer to structure in which information about the log book entry is written*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERRxread : UINT 				(*reads an entry from the error log book and writes the information in a structure (ERR_typ_struct)*)
	VAR_INPUT
		entry_nr	:UINT;				(*number of the log book entry that is to be read*)
		ERR_xtyp_struct	:UDINT;			(*pointer to structure in which information about the log book entry is written*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERR_fatal : UINT 				(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERR_warning : UINT 			(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERRxwarning : UINT 			(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
		errorstring	:UDINT;				(*string ending in zero (32 characters maximum)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SM_release : UINT 				(*releases the semaphore with the specified ID number*)
	VAR_INPUT
		sm_ident	:UDINT;				(*semaphore ID number from SM_create() or SM_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SM_attach : UINT 				(*requests the use of a semaphore*)
	VAR_INPUT
		sm_ident	:UDINT;				(*semaphore ID number from SM_create() or SM_ident()*)
		timeout	:UDINT;					(*timeout time in units of 10 ms (0 = unlimited timeout time)*)
		flags	:UDINT;					(*0 ... wait for timeout time to elapse, 1 ... do not wait for timeout time to elapse*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SM_delete : UINT 				(*deletes the semaphore with the specified ID number*)
	VAR_INPUT
		sm_ident	:UDINT;				(*semaphore ID number from SM_create() or SM_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SM_ident : UINT 				(*provides the ID number of an existing semaphore*)
	VAR_INPUT
		sm_name	:UDINT;					(*pointer to semaphore name*)
		sm_ident	:UDINT;				(*pointer to ID number of the semaphore*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SM_create : UINT 				(*generates a semaphore using the specified parameter and provides the ID number of the semaphore*)
	VAR_INPUT
		sm_name	:UDINT;					(*semaphore name, given as a string*)
		sm_count	:USINT;				(*number of permitted instances of simultaneous access using the semaphore*)
		sm_ident	:UDINT;				(*ID number of the semaphore*)
	END_VAR
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIM_ticks : UINT 				(*provides the number of ticks (1 tick = 10 ms) in the current second*)
(* The dummy_input parameter is obsolete.
	VAR_INPUT
		dummy_input	:USINT;				required for operation in ladder diagram
	END_VAR *)
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIM_musec : UINT 				(*provides the (approximate) number of microseconds in the current tick (1 tick = 10 ms)*)
(* The dummy_input parameter is obsolete. 
	VAR_INPUT
		dummy_input	:USINT;				required for operation in ladder diagram
	END_VAR *)
END_FUNCTION

{REDUND_ERROR} FUNCTION SW_settime : UINT 				(*sets the software clock to the desired time (RTCtime_struct structure)*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure which contains the time and date*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SW_gettime : UINT 				(*reads the time and date from the software clock and writes this information in a RTCtime_struct structure*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure where the time and date are stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION RTC_settime : UINT 			(*sets the real-time clock to the desired time (RTCtime_struct structure)*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure which contains the time and date*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION RTC_gettime : UINT 			(*reads time and date from the real-time clock and writes this information in a RTCtime_struct structure*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure where the time and date are stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TMP_free : UINT 				(*releases a memory area, which has been allocated using TMP_alloc()*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the memory area to be released in bytes*)
		memptr	:UDINT;					(*address for the memory area to be released*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TMP_alloc : UINT 				(*allocates memory in the temporary memory area (system RAM only)*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the allocated memory area in bytes*)
		memptr	:UDINT;					(*pointer to requested memory area*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION MEM_free : UINT 				(*releases a memory area, which has been allocated using MEM_alloc()*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the memory area to be released in bytes*)
		memptr	:UDINT;					(*address for the memory area to be released*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION MEM_alloc : UINT 				(*allocates memory in the user memory area (user RAM only)*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the allocated memory area in bytes*)
		memptr	:UDINT;					(*pointer to requested memory area*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION AVT_info : UINT 				(*determines how many links there are to the AVT entry with the specified AVT ID number*)
	VAR_INPUT
		av_ident	:UDINT;				(*AVT ID number from AVT_create() or AVT_ident()*)
		av_linkcount	:UDINT;			(*link count (number of access to this AVT entry)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION AVT_release : UINT 			(*releases the AVT entry with the specified AVT ID number*)
	VAR_INPUT
		av_ident	:UDINT;				(*AVT ID number from AVT_create() or AVT_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION AVT_attach : UINT 				(*attachs information to an AVT entry*)
	VAR_INPUT
		av_ident	:UDINT;				(*AVT ID number from AVT_create() or AVT_ident()*)
		av_info	:UDINT;					(*pointer to AVT info (e.g.: data address)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION AVT_ident : UINT 				(*provides the AVT ID number for an existing AVT entry*)
	VAR_INPUT
		av_name	:UDINT;					(*pointer to name of AVT entry*)
		av_grp	:USINT;					(*group number (standard = 0)*)
		av_ident	:UDINT;				(*pointer to AVT ident number*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION AVT_cancel : UINT 				(*deletes the entry with the specified AVT ID number from the AVT*)
	VAR_INPUT
		av_ident	:UDINT;				(*AVT ID number from AVT_create() or AVT_ident()*)
	END_VAR
END_FUNCTION	

{REDUND_ERROR} FUNCTION AVT_create : UINT 				(*generates an AVT entry with the specified name and provides an ID number*)
	VAR_INPUT
		av_name	:UDINT;					(*pointer to name of AVT entry*)
		av_grp	:USINT;					(*group number (standard = 0)*)
		av_info	:UDINT;					(*AVT info (e.g.: data address)*)
		av_ident	:UDINT;				(*pointer to AVT ident number*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_sleep : UINT 				(*stops the idle time object for a set period of time*)
	VAR_INPUT
		tickcount	:UDINT;				(*number of ticks (1 tick = 10 ms) for which an idle time object is stopped*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_exit : UINT 				(*exits an idle time object*)
	VAR_INPUT
		exitinfo	:UDINT;				(*exit information (standard = 0)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_freemsg : UINT 				(*releases the memory which was taken up by a received message*)
	VAR_INPUT
		msglng	:UDINT;					(*size of the memory to be released (in bytes)*)
		msg	:UDINT;						(*pointer to memory to be released*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_recmsg : UINT 				(*receives a message sent using the UT_sendmsg() function*)
	VAR_INPUT
		ut_ident	:UDINT;				(*pointer to ID number of the object to which the message was sent*)
		msg	:UDINT;						(*address at which the received message should be saved*)
		msglng	:UDINT;					(*pointer to length of the received data in bytes*)
		flags	:UDINT;					(*Bit 1 = 1: do not wait for UT_sendmsg()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_sendmsg : UINT 				(*sends a message to another object (including cyclic objects)*)
	VAR_INPUT
		ut_ident	:UDINT;				(*ID number of the object to which the message is to be sent (from UT_ident())*)
		msg	:UDINT;						(*pointer to message to be sent*)
		msglng	:UDINT;					(*length of the message to be sent (in bytes)*)
		flags	:UDINT;					(*Bit 1 = 1: do not wait for UT_recmsg()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_resume : UINT 				(*restarts a stopped idle time object*)
	VAR_INPUT
		ut_ident	:UDINT;				(*ID number from UT_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_suspend : UINT 				(*stops the idle time object with the specified ID number*)
	VAR_INPUT
		ut_ident	:UDINT;				(*ID number from UT_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION UT_ident : UINT 				(*provides the ID number of an idle time object*)
	VAR_INPUT
		ut_name	:UDINT;					(*pointer to name of the idle time object*)
		ut_grp	:USINT;					(*group number (standard = 0)*)
		ut_proc	:USINT;					(*processor number (standard: 0 = current processor)*)
		ut_sps_p	:UDINT;				(*pointer to name of the target system*)
		ut_ident	:UDINT;				(*pointer to ID number of the idle time object*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_name : UINT 				(*provides the name and group number for the object with the relevant ID number*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = the object itself)*)
		st_name_p	:UDINT;				(*pointer to name of the object*)
		st_grp	:UDINT;					(*pointer to group number for the object (standard = 0)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_info : UINT 				(*provides information about the object with the relevant ID number*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = the object itself)*)
		state	:UDINT;					(*pointer to status of the object: 1 ... Object installed, 2 ... Object running, ..*)
		tknr	:UDINT;					(*pointer to resource information: 1 through 8 ... Cyclic resource, -8 ... Exception resource, ..*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_allsuspend : UINT 			(*suspends all cyclic software objects*)
	VAR_INPUT
		dummy_input	:USINT;				(*required for operation in ladder diagram*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_tmp_resume : UINT 			(*activates a previously stopped (cyclic) software object*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the software object from ST_ident()*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_tmp_suspend : UINT 			(*suspends a cyclic object temporarily*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = object suspends itself)*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION ST_resume : UINT 				(*activates a previously stopped (cyclic) software object*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the software object from ST_ident()*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION ST_suspend : UINT 				(*suspends a cyclic object permanently*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident()(0 = object suspends itself)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_ident : UINT 				(*provides the ID number for a software object*)
	VAR_INPUT
		st_name	:UDINT;					(*pointer to name of the software object*)
		st_grp	:USINT;					(*group number for the object (standard = 0)*)
		st_ident	:UDINT;				(*pointer to ID number of the object*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION FORCE_info : UINT 				(*determines whether or not a variable is forced in the objects of the specified resource (tk_nr)*)
	VAR_INPUT
		tknr	:USINT;					(*resource that is to be checked: 1 through 4 ... cyclic resource, -9 ... Interrupt resource, ..*)
		force	:UDINT;					(*given as a pointer: 1 ... force function is active, 0 ... force function is inactive*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION MO_ver : UINT					(*reads the version and the date of a B&R module*)
	VAR_INPUT
		pName	:UDINT;					(*pointer to name of the B&R module*)
		grp	:USINT;						(*group number for the object (standard = 0)*)
		pMoVerStruc	:UDINT;				(*pointer to the structure where the module version of the located B&R module is stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION MO_list : UINT 				(*browses all the B&R modules on the target system*)
	VAR_INPUT
		prev_index	:UINT;				(*index of the B&R module where the search is being started*)
		index	:UDINT;					(*pointer to index of the found B&R module*)
		MO_List_struct	:UDINT;			(*pointer to structure where the module information is stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK MO_info	 				(*reads information of a B&R module on the target system*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		pName	:UDINT;					(*pointer to name of the B&R module*)
		grp		:USINT;					(*group number for the object (standard = 0)*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		type	:USINT;					(*B&R module type*)
		state   :USINT;					(*B&R module status*)
		memType :UDINT;					(*memory of the B&R module*)
		address :UDINT;					(*physical address of the B&R module*)
		size    :UDINT;					(*size of the B&R module*)
		version :ARRAY[0..9] OF USINT;	(*B&R module version*)
		date    :RTCtime_typ;			(*B&R module date*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION SYS_battery : USINT 			(*indicates the status of the standard/rechargeable battery in the CPU and the battery in the APM*)
	VAR_INPUT
		dummy_input	:USINT;				(*required for operation in ladder diagram*)
	END_VAR				
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SYSreset : UINT 				(*initiates a boot procedure on the target system in the specified mode (WARM or COLD START)*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		mode	:USINT;					(*boot mode: 0x01 .. WARM START (with Restart), 0x02 .. COLD START (with Restart), ..*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SYSxinfo : UINT 				(*reads the additional system information and writes this information into a SYSxinfo_struct structure*)
	VAR_INPUT
		SYSxinfo_struct	:UDINT;			(*pointer to structure where the additional system information is stored, given as a pointer*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION SYS_info : UINT 				(*provides information about the system*)
	VAR_INPUT
		init_count	:UDINT;				(*pointer to number of previously executed warm restarts*)
		init_descr	:UDINT;				(*pointer to mode of last start-up: 1 ... WARM RESTART, 2 ... COLD RESTART, ..*)
		tick_count	:UDINT;				(*pointer to tick counter*)
		version	:UDINT;					(*pointer to operating system version number*)
		ov_version	:UDINT;				(*pointer to object directory version number*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_xlist : UINT 				(*browse all the variables*)
	VAR_INPUT
		prev_index	:UINT;				(*index of the PV where the search is being started*)
		index	:UDINT;					(*pointer to index of the located PV*)
		PV_xList_struct	:UDINT;			(*pointer to structure which contains PV information about the located PV*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_ninfo : UINT 				(*reads data from a process variable of a complex data type (array or structure variable)*)
	VAR_INPUT
		pv_name	:UDINT;					(*pointer to name of the process variable*)
		data_typ_p	:UDINT;				(*pointer to data type of the PV*)
		data_len_p	:UDINT;				(*pointer to length of the PV in bytes*)
		dimension_p	:UDINT;				(*pointer to number of array or structure elements*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_item : UINT 				(*determines the names of structure elements*)
	VAR_INPUT
		pv_name	:UDINT;					(*pointer to name of the process variable*)
		index	:UINT;					(*structure element index*)
		itemname	:UDINT;				(*pointer to name of the structure element*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_ident : UINT 				(*provides the ID number of a process variable (PV)*)
	VAR_INPUT
		pv_name	:UDINT;					(*pointer to name of the process variable*)
		pv_tknr	:USINT;					(*process variable resource*)
		pv_grp	:USINT;					(*group number *)
		pv_ident	:UDINT;				(*pointer to PV ID number*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_list : UINT 				(*browses all variables*)
	VAR_INPUT
		prev_index	:UINT;				(*index of the PV where the search is being started*)
		index	:UDINT;					(*pointer to index of the located PV*)
		PVList_struct	:UDINT;			(*pointer to structure which contains PV information about the located PV*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_info : UINT 				(*reads data from a process variable of a complex data type (array or structure variable)*)
	VAR_INPUT
		pv_ident	:UDINT;				(*ID number of the process variable from PV_ident()*)
		data_typ	:UDINT;				(*pointer to data type of the PV*)
		data_len	:UDINT;				(*pointer to length of the PV in bytes*)
		dimension	:UDINT;				(*pointer to number of array or structure elements*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_xgetval : UINT 				(*reads data from a process variable of a complex data type (array or structure variable)*)
	VAR_INPUT
		pv_ident	:UDINT;				(*ID number of the process variable from PV_ident()*)
		subindex	:UINT;				(*element index: 0 ... Entire array/structure, 1 ... 1st element of the array/structure, ..*)
		data_p	:UDINT;					(*pointer to data read*)
		data_len	:USINT;				(*length of the data to be read in bytes*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_xsetval : UINT 				(*sets a particular value for a process variable of a complex data type (array variable or structure variable)*)
	VAR_INPUT
		pv_ident	:UDINT;				(*ID number of the process variable from PV_ident()*)
		subindex	:UINT;				(*element index: 0 ... Entire array/structure, 1 ... 1st element of the array/structure, ..*)
		data_p	:UDINT;					(*pointer to data assigned to the PV*)
		data_len	:USINT;				(*length of the data in bytes*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_xgetadr : UINT 				(*provides the address and length of a variable*)
	VAR_INPUT
		pv_name_p	:UDINT;				(*pointer to name of the process variable*)
		pv_adresse	:UDINT;				(*PV address for dynamic access*)
		data_len	:UDINT;				(*pointer to length of the process variable in bytes*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_getadr : UINT 				(*provides the address of a process variable*)
	VAR_INPUT
		pv_name_p	:UDINT;				(*pointer to name of the process variable*)
		pv_tknr	:USINT;					(*process variable resource: 1 ... Cyclic #1, timer #1-4, 2 ... Cyclic resource cyclic #2, ..*)
		pv_grpnr	:USINT;				(*group number (standard = 0)*)
		pv_adresse	:UDINT;				(*PV address for dynamic access*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_getval : UINT 				(*reads the value of a process variable*)
	VAR_INPUT
		pv_ident	:UDINT;				(*ID number of the process variable from PV_ident()*)
		value	:UDINT;					(*pointer to determined value of the PV*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION PV_setval : UINT 				(*sets a particular value for a process variable*)
	VAR_INPUT
		pv_ident	:UDINT;				(*ID number of the process variable from PV_ident()*)
		value	:UDINT;					(*value assigned to the PV*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK slMoList	 				(*browses the B&R modules on the target system*)
	VAR_INPUT
		enable			:BOOL;			(*enables execution*)
		first			:BOOL;			(*starting point for browsing*)
		filter			:BOOL;			(*filter for browsing in own application module*)
		pMoName			:UDINT;			(*name of the B&R module given as a pointer*)
		sizeMoName		:UDINT;			(*length of the string (pMoName) -> ideally, sizeMoName = 11*)
		pAppMoName		:UDINT;			(*name of the application module given as a pointer*)
		sizeAppMoName	:UDINT;			(*length of the string (pAppMoName) -> ideally, sizeAppMoName = 21*)
	END_VAR
	VAR_OUTPUT
		status			:UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		moSize			:UDINT;			(*size of the B&R module*)
		moType			:USINT;			(*type of the B&R module*)
		memType			:USINT;			(*memory type of the B&R module*)
	END_VAR
	VAR
		i_hMo			:UDINT;			(*internal variable*)		
	END_VAR
END_FUNCTION_BLOCK
