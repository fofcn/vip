#include "TcpCloseState.h"
#include "TcpListenState.h"
#include "TcpSynSentState.h"

TcpCloseState::TcpCloseState(SocketInternal *socket) : TcpState(socket)
{
	state = TCP_CLOSE;
}

void TcpCloseState::passiveOpen(SkBuffer *skBuffer)
{
	socket->setTcpState(new TcpListenState(socket));
}

void TcpCloseState::activeOpen(SkBuffer *skBuffer) 
{
	//TODO ����SYN

	//����SYN_SENT״̬
	socket->setTcpState(new TcpSynSentState(socket));
}