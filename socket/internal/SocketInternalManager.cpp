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

void SocketInternalManager::addSocketInternal(SocketInternal &skInternal)
{
	connSocketInternals.push_back(skInternal);
}

SocketInternal *SocketInternalManager::findSocketInternalByPort(ushort port)
{
	for (int i = 0; i < connSocketInternals.size(); i++)
	{
		if (connSocketInternals[i].getPort() == port)
		{
			return &connSocketInternals[i];
		}
	}

	return nullptr;
}