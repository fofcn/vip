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
	/*socket标识*/
	int handle;

	/*ip地址*/
	uint srcIp;

	/*端口号*/
	ushort srcPort;

	/*目的IP*/
	uint dstIp;

	/*目的端口*/
	ushort dstPort;

	/*socket类型，SOCK_STREAM等*/
	short skType;

	/*socekt 标记*/
	unsigned long flags;

	/*消息接受队列*/
	std::vector<SkBuffer *> skRecvQueue;

	/*消息发送队列*/
	std::vector<SkBuffer *> skTxQueue;

	/*半连接socket队列*/
	std::vector<SocketInternal> partialConn;

	/*已完成连接socket队列*/
	std::vector<SocketInternal> incommingConn;

	/*等待队列最大长度*/
	int backlogLimit;

	/*监听socket*/
	SocketInternal *listenSocket;

	/*tcp 当前状态*/
	int skState;

	TcpState *tcpState;
};

#endif