#ifndef VIP_SOCKINTERNALMANAGER_H_
#define VIP_SOCKINTERNALMANAGER_H_

#include <vector>
#include "SocketInternal.h"

class SockInternalManager 
{
public:
	SockInternalManager();
private:
	/*半连接socket队列*/
	std::vector<SocketInternal> partialConn;
	/*已完成连接socket队列*/
	std::vector<SocketInternal> incommingConn;
	/*等待队列最大长度*/
	int backlogLimit;
};

#endif 