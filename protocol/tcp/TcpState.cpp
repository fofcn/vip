#include "TcpState.h"

/*被动打开，转换到LISTEN状态*/
void TcpState::passiveOpen()
{

}

/*主动打开，发送SYN，状态转换为SYN_SENT*/
void TcpState::activeOpen()
{

}

/*收到SYN,发送SYN,ACK,状态转换为SYN_RCVD状态*/
void TcpState::recvSyn()
{

}
	
/*发送SYN，状态转换为SYN_SENT*/
void sendSyn();

/*收到SYN,ACK发送ACK，状态转换为ESTABLISHED*/
void recvSynAck();

/*发送SYN,ACK，状态转换为SYN*/
void sendSyncAck();

/*发送FIN命令，状态转换为FINWAIT-1*/
void sendFin();

/*发送FIN,ACK，状态转换为FINWAIT-2*/
void recvFin();

/*收到FIN ACK，状态转换为CLOSE*/
void recvFinAck();

/**/
void mslTimeout();

/*主动关闭*/
void close();