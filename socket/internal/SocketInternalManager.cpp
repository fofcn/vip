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
	establishedSockets.push_back(skInternal);
}

void SocketInternalManager::addListenSocketInternal(SocketInternal &skInternal)
{
	listenSocketInternals.push_back(skInternal);
}

SocketInternal *SocketInternalManager::findEstablishedSocket(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort)
{
	for (int i = 0; i < establishedSockets.size(); i++)
	{
		if (establishedSockets[i].getSrcIp() == srcIp && 
			establishedSockets[i].getSrcPort() == srcPort &&
			establishedSockets[i].getDstIp() == dstIp &&
			establishedSockets[i].getDstPort() == dstPort)
		{
			return &establishedSockets[i];
		}
	}

	return nullptr;
}

SocketInternal *SocketInternalManager::findTimewaitSocket(uint srcIp, ushort srcPort, uint dstIp, ushort dstPort)
{
	for (int i = 0; i < timewaitSockets.size(); i++)
	{
		if (timewaitSockets[i].getSrcIp() == srcIp &&
			timewaitSockets[i].getSrcPort() == srcPort &&
			timewaitSockets[i].getDstIp() == dstIp &&
			timewaitSockets[i].getDstPort() == dstPort)
		{
			return &timewaitSockets[i];
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