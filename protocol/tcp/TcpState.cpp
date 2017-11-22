#include "TcpState.h"

/*被动打开，转换到LISTEN状态*/
void TcpState::passiveOpen(SkBuffer *skBuffer)
{

}

/*主动打开，发送SYN，状态转换为SYN_SENT*/
void TcpState::activeOpen(SkBuffer *skBuffer)
{

}

/*收到SYN,发送SYN,ACK,状态转换为SYN_RCVD状态*/
void TcpState::recvSyn(SkBuffer *skBuffer)
{

}
	
/*发送SYN，状态转换为SYN_SENT*/
void TcpState::sendSyn(SkBuffer *skBuffer)
{

}

/*收到SYN,ACK发送ACK，状态转换为ESTABLISHED*/
void TcpState::recvSynAck(SkBuffer *skBuffer)
{

}

/*发送SYN,ACK，状态转换为SYN*/
void TcpState::sendSyncAck(SkBuffer *skBuffer)
{

}

/*发送FIN命令，状态转换为FINWAIT-1*/
void TcpState::sendFin(SkBuffer *skBuffer)
{

}

/*发送FIN,ACK，状态转换为FINWAIT-2*/
void TcpState::recvFin(SkBuffer *skBuffer)
{

}

/*收到FIN ACK，状态转换为CLOSE*/
void TcpState::recvFinAck(SkBuffer *skBuffer)
{

}

/**/
void TcpState::mslTimeout(SkBuffer *skBuffer)
{

}

/*主动关闭*/
void TcpState::close(SkBuffer *skBuffer)
{

}