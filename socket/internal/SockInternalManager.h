#ifndef VIP_SOCKINTERNALMANAGER_H_
#define VIP_SOCKINTERNALMANAGER_H_

#include <vector>
#include "SocketInternal.h"

class SocketInternalManager 
{
public:
	static SocketInternalManager *getInstance();
	void addConnSocketInternal(SocketInternal &skInternal);
	void addListenSocketInternal(SocketInternal &skInternal);
	SocketInternal *findConnSocketInternal(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort);
	SocketInternal *findListenSocketInternal(uint srcIp, ushort srcPort);
private:
	SocketInternalManager();
private:

	/*已经建立或正在建立连接的socket*/
	std::vector<SocketInternal> connSocketInternals;
	/*正在监听的socket*/
	std::vector<SocketInternal> listenSocketInternals;

	static SocketInternalManager *instance;
};

#endif 