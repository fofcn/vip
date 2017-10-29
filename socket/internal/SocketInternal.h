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
	/*socket标识*/
	int handle;
	/*ip地址*/
	int ip;
	/*端口号*/
	ushort port;
	/*socket类型，SOCK_STREAM等*/
	short skType;
	/*socekt 标记*/
	unsigned long flags;

	/*消息接受队列*/
	SocketBuffer skRecvQueue;

	/*消息发送队列*/
	SocketBuffer skTxQueue;

	/*半连接socket队列*/
	std::vector<SocketInternal> partialConn;

	/*已完成连接socket队列*/
	std::vector<SocketInternal> incommingConn;

	/*等待队列最大长度*/
	int backlogLimit;
};

#endif