/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASTCP_
#define _ASTCP_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define tcpINVALID_IDENT 0U
 #define tcpSHUT_WR 2U
 #define tcpSHUT_RD 1U
 #define tcpOPT_REUSEADDR 1U
 #define tcpMSG_DONTROUTE 4U
 #define tcpMSG_PEEK 2U
 #define tcpMSG_OOB 1U
 #define tcpID_MAX_GET 3002U
 #define tcpID_LIST_GET 3001U
 #define tcpTCP_KEEPINTVL_GET 2008U
 #define tcpTCP_KEEPINTVL_SET 2007U
 #define tcpTCP_KEEPIDLE_GET 2006U
 #define tcpTCP_KEEPIDLE_SET 2005U
 #define tcpTCP_KEEPCNT_GET 2004U
 #define tcpTCP_KEEPCNT_SET 2003U
 #define tcpTCP_NODELAY_GET 2002U
 #define tcpTCP_NODELAY_SET 2001U
 #define tcpSO_NOWAITING_GET 1013U
 #define tcpSO_NOWAITING_SET 1012U
 #define tcpSO_ADDRESS_GET 1011U
 #define tcpSO_OOBINLINE_GET 1010U
 #define tcpSO_OOBINLINE_SET 1009U
 #define tcpSO_RCVBUF_GET 1008U
 #define tcpSO_RCVBUF_SET 1007U
 #define tcpSO_SNDBUF_GET 1006U
 #define tcpSO_SNDBUF_SET 1005U
 #define tcpSO_KEEPALIVE_GET 1004U
 #define tcpSO_KEEPALIVE_SET 1003U
 #define tcpSO_LINGER_GET 1002U
 #define tcpSO_LINGER_SET 1001U
 #define tcpERR_SYSTEM 32699U
 #define tcpERR_SSL_HANDSHAKE_FAILED 32698U
 #define tcpERR_INVALID_SSL_CONFIG 32697U
 #define tcpERR_SOCKET_ACCEPT 32653U
 #define tcpERR_SOCKET_LISTEN 32652U
 #define tcpERR_SOCKET_BIND 32651U
 #define tcpERR_SOCKET_CREATE 32650U
 #define tcpERR_NOCLIENT 32613U
 #define tcpERR_INTERFACE 32612U
 #define tcpERR_NO_OOBDATA 32611U
 #define tcpERR_ALREADY_CONNECTED 32610U
 #define tcpERR_NOT_CONNECTED 32609U
 #define tcpERR_INVALID 32608U
 #define tcpERR_WOULDBLOCK 32607U
 #define tcpERR_SENTLEN 32606U
 #define tcpERR_NO_DATA 32605U
 #define tcpERR_INVALID_IOCTL 32604U
 #define tcpERR_PARAMETER 32603U
 #define tcpERR_ALREADY_EXIST 32602U
 #define tcpERR_NOMORE_IDENTS 32601U
 #define tcpERR_INVALID_IDENT 32600U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned long tcpINVALID_IDENT;
 _GLOBAL_CONST unsigned long tcpSHUT_WR;
 _GLOBAL_CONST unsigned long tcpSHUT_RD;
 _GLOBAL_CONST unsigned long tcpOPT_REUSEADDR;
 _GLOBAL_CONST unsigned long tcpMSG_DONTROUTE;
 _GLOBAL_CONST unsigned long tcpMSG_PEEK;
 _GLOBAL_CONST unsigned long tcpMSG_OOB;
 _GLOBAL_CONST unsigned long tcpID_MAX_GET;
 _GLOBAL_CONST unsigned long tcpID_LIST_GET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPINTVL_GET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPINTVL_SET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPIDLE_GET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPIDLE_SET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPCNT_GET;
 _GLOBAL_CONST unsigned long tcpTCP_KEEPCNT_SET;
 _GLOBAL_CONST unsigned long tcpTCP_NODELAY_GET;
 _GLOBAL_CONST unsigned long tcpTCP_NODELAY_SET;
 _GLOBAL_CONST unsigned long tcpSO_NOWAITING_GET;
 _GLOBAL_CONST unsigned long tcpSO_NOWAITING_SET;
 _GLOBAL_CONST unsigned long tcpSO_ADDRESS_GET;
 _GLOBAL_CONST unsigned long tcpSO_OOBINLINE_GET;
 _GLOBAL_CONST unsigned long tcpSO_OOBINLINE_SET;
 _GLOBAL_CONST unsigned long tcpSO_RCVBUF_GET;
 _GLOBAL_CONST unsigned long tcpSO_RCVBUF_SET;
 _GLOBAL_CONST unsigned long tcpSO_SNDBUF_GET;
 _GLOBAL_CONST unsigned long tcpSO_SNDBUF_SET;
 _GLOBAL_CONST unsigned long tcpSO_KEEPALIVE_GET;
 _GLOBAL_CONST unsigned long tcpSO_KEEPALIVE_SET;
 _GLOBAL_CONST unsigned long tcpSO_LINGER_GET;
 _GLOBAL_CONST unsigned long tcpSO_LINGER_SET;
 _GLOBAL_CONST unsigned short tcpERR_SYSTEM;
 _GLOBAL_CONST unsigned short tcpERR_SSL_HANDSHAKE_FAILED;
 _GLOBAL_CONST unsigned short tcpERR_INVALID_SSL_CONFIG;
 _GLOBAL_CONST unsigned short tcpERR_SOCKET_ACCEPT;
 _GLOBAL_CONST unsigned short tcpERR_SOCKET_LISTEN;
 _GLOBAL_CONST unsigned short tcpERR_SOCKET_BIND;
 _GLOBAL_CONST unsigned short tcpERR_SOCKET_CREATE;
 _GLOBAL_CONST unsigned short tcpERR_NOCLIENT;
 _GLOBAL_CONST unsigned short tcpERR_INTERFACE;
 _GLOBAL_CONST unsigned short tcpERR_NO_OOBDATA;
 _GLOBAL_CONST unsigned short tcpERR_ALREADY_CONNECTED;
 _GLOBAL_CONST unsigned short tcpERR_NOT_CONNECTED;
 _GLOBAL_CONST unsigned short tcpERR_INVALID;
 _GLOBAL_CONST unsigned short tcpERR_WOULDBLOCK;
 _GLOBAL_CONST unsigned short tcpERR_SENTLEN;
 _GLOBAL_CONST unsigned short tcpERR_NO_DATA;
 _GLOBAL_CONST unsigned short tcpERR_INVALID_IOCTL;
 _GLOBAL_CONST unsigned short tcpERR_PARAMETER;
 _GLOBAL_CONST unsigned short tcpERR_ALREADY_EXIST;
 _GLOBAL_CONST unsigned short tcpERR_NOMORE_IDENTS;
 _GLOBAL_CONST unsigned short tcpERR_INVALID_IDENT;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct tcpLINGER_typ
{	unsigned long lOnOff;
	unsigned long lLinger;
} tcpLINGER_typ;

typedef struct tcpSO_ADDRESS_typ
{	unsigned long pPort;
	unsigned long pIpAddr;
} tcpSO_ADDRESS_typ;

typedef struct TcpOpen
{
	/* VAR_INPUT (analog) */
	unsigned long pIfAddr;
	unsigned short port;
	unsigned long options;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpOpen_typ;

typedef struct TcpOpenSsl
{
	/* VAR_INPUT (analog) */
	unsigned long pIfAddr;
	unsigned short port;
	unsigned long sslCfgIdent;
	unsigned long options;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpOpenSsl_typ;

typedef struct TcpServer
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long backlog;
	unsigned long pIpAddr;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long identclnt;
	unsigned short portclnt;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpServer_typ;

typedef struct TcpClient
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pServer;
	unsigned short portserv;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpClient_typ;

typedef struct TcpClose
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long how;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpClose_typ;

typedef struct TcpSend
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pData;
	unsigned long datalen;
	unsigned long flags;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long sentlen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpSend_typ;

typedef struct TcpRecv
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pData;
	unsigned long datamax;
	unsigned long flags;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long recvlen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpRecv_typ;

typedef struct TcpIoctl
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long ioctl;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long outlen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TcpIoctl_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void TcpOpen(struct TcpOpen* inst);
_BUR_PUBLIC void TcpOpenSsl(struct TcpOpenSsl* inst);
_BUR_PUBLIC void TcpServer(struct TcpServer* inst);
_BUR_PUBLIC void TcpClient(struct TcpClient* inst);
_BUR_PUBLIC void TcpClose(struct TcpClose* inst);
_BUR_PUBLIC void TcpSend(struct TcpSend* inst);
_BUR_PUBLIC void TcpRecv(struct TcpRecv* inst);
_BUR_PUBLIC void TcpIoctl(struct TcpIoctl* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASTCP_ */

