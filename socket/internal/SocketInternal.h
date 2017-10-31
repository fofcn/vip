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
	inline ushort getPort()
	{
		return port;
	}
	void enqueueRecvBuffer(SkBuffer *skBuffer);
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
	std::vector<SkBuffer *> skRecvQueue;

	/*��Ϣ���Ͷ���*/
	std::vector<SkBuffer *> skTxQueue;

	/*������socket����*/
	std::vector<SocketInternal> partialConn;

	/*���������socket����*/
	std::vector<SocketInternal> incommingConn;

	/*�ȴ�������󳤶�*/
	int backlogLimit;
};

#endif