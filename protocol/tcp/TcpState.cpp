#include "TcpState.h"

/*�����򿪣�ת����LISTEN״̬*/
void TcpState::passiveOpen()
{

}

/*�����򿪣�����SYN��״̬ת��ΪSYN_SENT*/
void TcpState::activeOpen()
{

}

/*�յ�SYN,����SYN,ACK,״̬ת��ΪSYN_RCVD״̬*/
void TcpState::recvSyn()
{

}
	
/*����SYN��״̬ת��ΪSYN_SENT*/
void sendSyn();

/*�յ�SYN,ACK����ACK��״̬ת��ΪESTABLISHED*/
void recvSynAck();

/*����SYN,ACK��״̬ת��ΪSYN*/
void sendSyncAck();

/*����FIN���״̬ת��ΪFINWAIT-1*/
void sendFin();

/*����FIN,ACK��״̬ת��ΪFINWAIT-2*/
void recvFin();

/*�յ�FIN ACK��״̬ת��ΪCLOSE*/
void recvFinAck();

/**/
void mslTimeout();

/*�����ر�*/
void close();