#ifndef VIP_SOCKETINTERNAL_H_
#define VIP_SOCKETINTERNAL_H_

#include "Types.h"
#include "SocketBuffer.h"

class SocketInternal
{
public:
	SocketInternal();

	void setBacklog(int backlog);
	void setSkType(short type);
	void setPort(ushort port);
private:
	/*socket��ʶ*/
	int handle;
	/*ip��ַ*/
	int ip;
	/*�˿ں�*/
	ushort port;
	/*socket���ͣ�SOCK_STREAM��*/
	short skType;
	/*socekt ���*/
	unsigned long flags;

	/*��Ϣ���ܶ���*/
	SocketBuffer skRecvQueue;

	/*��Ϣ���Ͷ���*/
	SocketBuffer skTxQueue;

	/*������socket����*/
	std::vector<SocketInternal> partialConn;

	/*���������socket����*/
	std::vector<SocketInternal> incommingConn;

	/*�ȴ�������󳤶�*/
	int backlogLimit;
};

#endif