#ifndef VIP_SOCKETINTERNAL_H_
#define VIP_SOCKETINTERNAL_H_

#include "Types.h"
#include "SocketBuffer.h"
#include "protocol/tcp/TcpState.h"

class SocketInternal
{
public:
	SocketInternal();

	void setBacklog(int backlog);
	void setSkType(short type);
	void setSrcPort(ushort port);
	inline ushort getSrcPort()
	{
		return srcPort;
	}
	inline void setSrcIp(uint srcIp)
	{
		this->srcIp = srcIp;
	}
	inline uint getSrcIp()
	{
		return srcIp;
	}
	inline void setDstPort(ushort dstPort)
	{
		this->dstPort = dstPort;
	}
	inline ushort getDstPort()
	{
		return dstPort;
	}
	inline void setDstIp(uint dstIp)
	{
		this->dstIp = dstIp;
	}
	inline uint getDstIp()
	{
		return dstIp;
	}
	inline void setListenSocket(SocketInternal *listenSocket)
	{
		this->listenSocket = listenSocket;
	}
	inline void setSkState(int state)
	{
		this->skState = state;
	}
	inline int getSkState()
	{
		return skState;
	}
	inline void addParitialConn(SocketInternal paritialSocket)
	{
		partialConn.push_back(paritialSocket);
	}

	inline void setTcpState(TcpState *state)
	{
		tcpState = state;
	}
	void enqueueRecvBuffer(SkBuffer *skBuffer);
	
	void processTcpState(SkBuffer *skBuffer);
private:
	/*socket��ʶ*/
	int handle;

	/*ip��ַ*/
	uint srcIp;

	/*�˿ں�*/
	ushort srcPort;

	/*Ŀ��IP*/
	uint dstIp;

	/*Ŀ�Ķ˿�*/
	ushort dstPort;

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

	/*����socket*/
	SocketInternal *listenSocket;

	/*tcp ��ǰ״̬*/
	int skState;

	TcpState *tcpState;
};

#endif