#include "TcpCloseState.h"

TcpCloseState::TcpCloseState(SocketInternal *socket) : TcpState(socket)
{
	state = TCP_CLOSE;
}

void TcpCloseState::passiveOpen(SkBuffer *skBuffer)
{
	socket->setTcpState();
}