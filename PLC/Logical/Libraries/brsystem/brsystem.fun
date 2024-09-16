                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK MEMInfo				(*returns information about the memory areas available on the system*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		FreeUSR_Ram	:UDINT;			(*SG3: free memory in USER RAM SG4: free memory in SRAM (Userram)*)
		FreeSYSTEM	:UDINT;			(*SG3: free system memory SG4: not used, always 0*)
		FreeUSR_Prom	:UDINT;		(*SG3: free memory in USER PROM SG4: free memory of HD where RPSHD is located*)
		FreeSYS_Prom	:UDINT;		(*SG3: free memory in system PROM SG4: free memory of HD where RPSHD is located*)
		FreeFIX_Ram	:UDINT;			(*SG3: free memory in FIX RAM SG4: not used, always 0*)
		FreeTMP_Ram	:UDINT;			(*SG3: free temporary memory in RAM SG4: free memory in DRAM*)
		FreeMEMCARD	:UDINT;			(*SG3: free memory on MEMCARD SG4: not used, always 0*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK MEMxInfo				(*returns information about the memory areas available in the system; asynchronous execution*)
	VAR_INPUT
		enable	:BOOL;   			(*enables execution*)
		mem_typ	:UDINT;				(*memory type: brDRAM, brUSRRAM, brSYSROM, brUSRROM*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		MemSize	:UDINT;				(*total memory size in bytes*)
		FreeMemSize	:UDINT;			(*size of available memory in bytes*)
		BiggestFreeBlockSize	:UDINT;	(*size of the largest available block in memory in bytes*)
	END_VAR
	VAR
		i_state	:UINT;				(*internal variable*)
		i_result	:UINT;			(*internal variable*)
		i_tmp	:UDINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SysInfo				(*returns information about the target system*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		init_reason	:USINT;			(*reason for initialization*)
		init_count	:USINT;			(*SG3: the value is increased by every INIT (warm restart) SG4: not used, always 0*)
		tick_count	:UDINT;			(*tick count*)
		version	:UDINT;				(*operating system version of the target system*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK RTInfo				(*returns runtime information about the program*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		cycle_time	:UDINT;			(*cycle time in microsec*)
		init_reason	:SINT;			(*reason for initialization*)
		task_class	:SINT;			(*task class (SG3: #1 - #4 SG4: #1 - #8)*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TARGETInfo			(*returns information about the target system used*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		pOSVersion	:UDINT;			(*string given as a pointer (min. 7 char), where the os version is written*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		DataFormat	:USINT;			(*wether "big endian" or "little endian" ("TARGET_BIG_ENDIAN"/"TARGET_LITTLE_ENDIAN")*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK HWInfo				(*returns information about the hardware configuration*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		first	:BOOL;				(*determines the hardware module on which the FUB is used 0/1 next/first*)
		pName	:UDINT;				(*string given as a pointer, where the name of the module is written*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		family	:USINT;				(*family designation*)
		usetype	:USINT;				(*hardware type*)
		module_typ	:UDINT;			(*module type*)
		master_no	:USINT;			(*logical number of the IO master, RIO master, CAN bus with CANIO*)
		slave_no	:USINT;			(*slave number*)
		module_adr	:USINT;			(*hardware module address (decimal)*)
		slot_no	:USINT;				(*slot of the first submodule found (decimal)*)
	END_VAR
	VAR
		next_vw_p	:UDINT;			(*internal variable*)
		last_modul_p	:UDINT;		(*internal variable*)
		next_entry_p	:UDINT;		(*internal variable*)
		next_entry_ix	:USINT;		(*internal variable*)
		next_slot_ix	:USINT;		(*internal variable*)
		last_rio_master	:USINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SysconfInfo			(*returns the parameters for a sysconf entry*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		pEntry	:UDINT;				(*string given as a pointer, where the name of the entry is written*)
		pValue	:UDINT;				(*string given as a pointer, where the value of the entry is copied*)
		value_len	:UDINT;			(*length of the "value-string"*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK SysconfSet			(*sets the parameters for a sysconf entry*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		pEntry	:UDINT;				(*string given as a pointer, where the name of the entry is written*)
		pNewValue	:UDINT;			(*string given as a pointer, where the new value of the entry is written*)
		option	:USINT;				(*sets the parameter volatile/permanent ("brSYSCONF_SET_VOLATILE"/"brSYSCONF_SET_NON_VOLATILE")*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK BatteryInfo			(*returns the state of the battery*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		pDevice	:UDINT;				(*device name given as a pointer*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		state	:USINT;				(*state of the battery*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK EXCInfo				(*returns information about the program that triggered the exception*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		task_class	:UDINT;			(*task class in which the exception was triggered*)
		task_ident	:UDINT;			(*ID number of the program that triggered the exception*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK ZYKVLenable			(*enables/disables the cycle time monitoring of programs*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		mode	:BOOL;				(*0/1 monitoring off/on*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK PMemGet				(*reads data of len byte from the permanent memeory area beginning at offset*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		offset	:UDINT;				(*offset within the permanent memory area*)
		len	 :UDINT;				(*length of data area to be read*)
		adress	:UDINT;				(*address where the read data is copied*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK PMemPut				(*writes len bytes to the permanent memory area beginning at offset*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		offset	:UDINT;				(*offset within the permanent memory area*)
		len	 :UDINT;				(*length of data area to be written*)
		adress	:UDINT;				(*address of the data to be written to the permanent memory area*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK PMemSize				(*determines the size of permanent memory area in its existing configuration*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		size	:UDINT;				(*size of permanent memory area*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK ARwinWindowsInfo				(*get status of windows system*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, 0xXXXX = see help*)
		windowsStatus	:UDINT;		(*windows system status: brWINDOWS_BLUESCREEN, brWINDOWS_OK*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK ARwinEthWinInfo				(*get ETH info windows interface*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, 0xXXXX = see help*)
		IPAddr	:STRING[15];		(*IP-address of virtual windows IF*)
		SubnetMask	:STRING[15];	(*netmask of virtual windows IF*)
		MacAddr	:ARRAY[0..5] OF BYTE;	(*MAC-address of virtual windows IF*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION RTTolerance : UDINT (*returns the tolerance [microsec] of the programs task class*)
END_FUNCTION

{REDUND_OK} FUNCTION RTCyclic : BOOL (*returns true, if function is called in the cyclic part of the program, false otherwise*)
END_FUNCTION

{REDUND_OK} FUNCTION RTInit : BOOL (*returns true, if function is called in the init part of the program, false otherwise*)
END_FUNCTION

{REDUND_OK} FUNCTION RTExit : BOOL (*returns true, if function is called in the exit part of the program, false otherwise*)
END_FUNCTION
