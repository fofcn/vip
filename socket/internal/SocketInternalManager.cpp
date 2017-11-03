#include "SockInternalManager.h"

SocketInternalManager *SocketInternalManager::instance = nullptr;


SocketInternalManager::SocketInternalManager()
{

}

SocketInternalManager *SocketInternalManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SocketInternalManager();
	}
	return instance;
}

void SocketInternalManager::addConnSocketInternal(SocketInternal &skInternal)
{
	connSocketInternals.push_back(skInternal);
}

void SocketInternalManager::addListenSocketInternal(SocketInternal &skInternal)
{
	listenSocketInternals.push_back(skInternal);
}

SocketInternal *SocketInternalManager::findConnSocketInternal(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort)
{
	for (int i = 0; i < connSocketInternals.size(); i++)
	{
		if (connSocketInternals[i].getSrcIp() == srcIp && 
			connSocketInternals[i].getSrcPort() == srcPort &&
			connSocketInternals[i].getDstIp() == dstIp &&
			connSocketInternals[i].getDstPort() == dstPort)
		{
			return &connSocketInternals[i];
		}
	}

	return nullptr;
}

SocketInternal *SocketInternalManager::findListenSocketInternal(uint srcIp, ushort srcPort)
{
	for (int i = 0; i < listenSocketInternals.size(); i++)
	{
		if (listenSocketInternals[i].getSrcIp() == srcIp &&
			listenSocketInternals[i].getSrcPort() == srcPort)
		{
			return &listenSocketInternals[i];
		}
	}

	return nullptr;
}