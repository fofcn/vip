#include "TcpState.h"

/*�����򿪣�ת����LISTEN״̬*/
void TcpState::passiveOpen(SkBuffer *skBuffer)
{

}

/*�����򿪣�����SYN��״̬ת��ΪSYN_SENT*/
void TcpState::activeOpen(SkBuffer *skBuffer)
{

}

/*�յ�SYN,����SYN,ACK,״̬ת��ΪSYN_RCVD״̬*/
void TcpState::recvSyn(SkBuffer *skBuffer)
{

}
	
/*����SYN��״̬ת��ΪSYN_SENT*/
void TcpState::sendSyn(SkBuffer *skBuffer)
{

}

/*�յ�SYN,ACK����ACK��״̬ת��ΪESTABLISHED*/
void TcpState::recvSynAck(SkBuffer *skBuffer)
{

}

/*����SYN,ACK��״̬ת��ΪSYN*/
void TcpState::sendSyncAck(SkBuffer *skBuffer)
{

}

/*����FIN���״̬ת��ΪFINWAIT-1*/
void TcpState::sendFin(SkBuffer *skBuffer)
{

}

/*����FIN,ACK��״̬ת��ΪFINWAIT-2*/
void TcpState::recvFin(SkBuffer *skBuffer)
{

}

/*�յ�FIN ACK��״̬ת��ΪCLOSE*/
void TcpState::recvFinAck(SkBuffer *skBuffer)
{

}

/**/
void TcpState::mslTimeout(SkBuffer *skBuffer)
{

}

/*�����ر�*/
void TcpState::close(SkBuffer *skBuffer)
{

}