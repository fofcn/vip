#include "NetworkCardPool.h"

NetworkCardPool *NetworkCardPool::instance = 0;

NetworkCardPool::NetworkCardPool()
{
}

NetworkCardPool::~NetworkCardPool()
{
	if (NetworkCardPool::instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

NetworkCardPool *NetworkCardPool::getInstance()
{
	if (instance == nullptr)
	{
		instance = new NetworkCardPool();
	}

	return instance;
}

bool NetworkCardPool::contains(int ip)
{
	for (int i = 0; i < ipList.size(); i++)
	{
		if (ipList[i].equals(ip))
		{
			return true;
		}
	}

	return false;
}

void NetworkCardPool::addIp(int ip)
{
	NetworkCard networkCard(ip);
	ipList.push_back(networkCard);
}