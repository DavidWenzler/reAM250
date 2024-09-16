                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpOpen					(*opens a TCP socket; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		pIfAddr			: UDINT;		(*pointer to the interface address*)
		port			: UINT;			(*port number of the socket*)
		options			: UDINT;		(*options that can be set during opening*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*identifier for use with TcpServer, TcpClient, TcpSend, TcpRecv, TcpClose and TcpIoctl*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpOpenSsl					(*opens a TCP socket using SSL; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		pIfAddr			: UDINT;		(*pointer to the interface address*)
		port			: UINT;			(*port number of the socket*)
		sslCfgIdent  	: UDINT;		(*identifier of the SSL configuration*)
		options			: UDINT;		(*options that can be set during opening*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*identifier for use with TcpServer, TcpClient, TcpSend, TcpRecv, TcpClose and TcpIoctl*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpServer				(*starts a TCP server; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		backlog			: UDINT;		(*number of connections to queue*)
		pIpAddr			: UDINT;		(*pointer where to store the ip address of the connected client*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		identclnt		: UDINT;		(*identifier for use with fub TcpClose, TcpSend, and TcpRecv*)
		portclnt		: UINT;			(*port number of connected client*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpClient				(*establishs a connection to a TCP server; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		pServer			: UDINT;		(*pointer to the ip address of server to connect to*)
		portserv		: UINT;			(*port number of server to connect to*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpClose					(*closes a TCP socket and frees up all required resources; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		how				: UDINT;		(*shutdown behavior*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpSend					(*sends data (byte stream); asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		pData			: UDINT;		(*pointer to the data to be sent*)
		datalen			: UDINT;		(*length of byte stream*)
		flags			: UDINT;		(*send flags (e.g. "out of band" data)*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		sentlen			: UDINT;		(*number of actually sent bytes*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpRecv					(*receives TCP byte stream; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		pData			: UDINT;		(*pointer to the buffer where to store byte stream data*)
		datamax			: UDINT;		(*max. length of data in bytes*)
		flags			: UDINT;		(*receive flags*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		recvlen			: UDINT;		(*length of the bytes received*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TcpIoctl					(*changes or retrieves settings; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from TcpOpen()*)
		ioctl			: UDINT;		(*I/O control code*)
		pData			: UDINT;		(*pointer to the I/O control data buffer*)
		datalen			: UDINT;		(*lentgh of I/O control input data*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		outlen			: UDINT;		(*output data length*)
	END_VAR

	VAR
		i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
		i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
