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