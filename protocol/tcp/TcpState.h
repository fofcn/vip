#ifndef VIP_TCPSTATE_H_
#define VIP_TCPSTATE_H_

#include "protocol/enums/TcpStateDef.h"
#include "socket/internal/SocketInternal.h"
#include "pcap/SkBuffer.h"

class TcpState
{
public:
	TcpState(SocketInternal *socketInternal);
	virtual ~TcpState();
	/*被动打开，转换到LISTEN状态*/
	virtual void passiveOpen(SkBuffer *skBuffer);

	/*主动打开，发送SYN，状态转换为SYN_SENT*/
	virtual void activeOpen(SkBuffer *skBuffer);

	/*收到SYN,发送SYN,ACK,状态转换为SYN_RCVD状态*/
	virtual void recvSyn(SkBuffer *skBuffer);
	
	/*发送SYN，状态转换为SYN_SENT*/
	virtual void sendSyn(SkBuffer *skBuffer);

	/*收到SYN,ACK发送ACK，状态转换为ESTABLISHED*/
	virtual void recvSynAck(SkBuffer *skBuffer);

	/*发送SYN,ACK，状态转换为SYN*/
	virtual void sendSyncAck(SkBuffer *skBuffer);

	/*发送FIN命令，状态转换为FINWAIT-1*/
	virtual void sendFin(SkBuffer *skBuffer);

	/*发送FIN,ACK，状态转换为FINWAIT-2*/
	virtual void recvFin(SkBuffer *skBuffer);

	/*收到FIN ACK，状态转换为CLOSE*/
	virtual void recvFinAck(SkBuffer *skBuffer);

	/**/
	virtual void mslTimeout(SkBuffer *skBuffer);

	/*主动关闭*/
	virtual void close(SkBuffer *skBuffer);

protected:
	int state;
	SocketInternal *socket;
};

#endif