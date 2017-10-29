#ifndef VIP_SOCKINTERNALMANAGER_H_
#define VIP_SOCKINTERNALMANAGER_H_

#include <vector>
#include "SocketInternal.h"

class SocketInternalManager 
{
public:
	static SocketInternalManager *getInstance();
	void addSocketInternal(SocketInternal &skInternal);
	SocketInternal &findSocketInternal();
private:
	SocketInternalManager();
private:

	/*�Ѿ����������ڽ������ӵ�socket*/
	std::vector<SocketInternal> connSocketInternals;

	static SocketInternalManager *instance;
};

#endif 