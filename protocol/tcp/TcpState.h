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
	/*�����򿪣�ת����LISTEN״̬*/
	virtual void passiveOpen(SkBuffer *skBuffer);

	/*�����򿪣�����SYN��״̬ת��ΪSYN_SENT*/
	virtual void activeOpen(SkBuffer *skBuffer);

	/*�յ�SYN,����SYN,ACK,״̬ת��ΪSYN_RCVD״̬*/
	virtual void recvSyn(SkBuffer *skBuffer);
	
	/*����SYN��״̬ת��ΪSYN_SENT*/
	virtual void sendSyn(SkBuffer *skBuffer);

	/*�յ�SYN,ACK����ACK��״̬ת��ΪESTABLISHED*/
	virtual void recvSynAck(SkBuffer *skBuffer);

	/*����SYN,ACK��״̬ת��ΪSYN*/
	virtual void sendSyncAck(SkBuffer *skBuffer);

	/*����FIN���״̬ת��ΪFINWAIT-1*/
	virtual void sendFin(SkBuffer *skBuffer);

	/*����FIN,ACK��״̬ת��ΪFINWAIT-2*/
	virtual void recvFin(SkBuffer *skBuffer);

	/*�յ�FIN ACK��״̬ת��ΪCLOSE*/
	virtual void recvFinAck(SkBuffer *skBuffer);

	/**/
	virtual void mslTimeout(SkBuffer *skBuffer);

	/*�����ر�*/
	virtual void close(SkBuffer *skBuffer);

protected:
	int state;
	SocketInternal *socket;
};

#endif