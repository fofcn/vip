#ifndef VIP_SOCKINTERNALMANAGER_H_
#define VIP_SOCKINTERNALMANAGER_H_

#include <vector>
#include "SocketInternal.h"

class SockInternalManager 
{
public:
	SockInternalManager();
private:
	/*������socket����*/
	std::vector<SocketInternal> partialConn;
	/*���������socket����*/
	std::vector<SocketInternal> incommingConn;
	/*�ȴ�������󳤶�*/
	int backlogLimit;
};

#endif 