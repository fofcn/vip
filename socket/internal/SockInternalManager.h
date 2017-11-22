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
	SocketInternal *findEstablishedSocket(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort);
	SocketInternal *findTimewaitSocket(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort);
	SocketInternal *findListenSocketInternal(uint srcIp, ushort srcPort);
private:
	SocketInternalManager();
private:

	/*�Ѿ����������ڽ������ӵ�socket*/
	std::vector<SocketInternal> establishedSockets;
	/*����timewait״̬��socket*/
	std::vector<SocketInternal> timewaitSockets;
	/*���ڼ�����socket*/
	std::vector<SocketInternal> listenSocketInternals;

	static SocketInternalManager *instance;
};

#endif 