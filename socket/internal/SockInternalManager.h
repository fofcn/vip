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

	/*已经建立或正在建立连接的socket*/
	std::vector<SocketInternal> connSocketInternals;

	static SocketInternalManager *instance;
};

#endif 