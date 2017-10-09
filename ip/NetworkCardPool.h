#pragma once

#ifndef VIP_NETWORKPOOL_H_
#define VIP_NETWORKPOOL_H_

#include <vector>

#include "NetworkCard.h"

class NetworkCardPool
{
public:
	static NetworkCardPool *getInstance();

	bool contains(int ip);

	void addIp(int ip);
private:
	NetworkCardPool();
	~NetworkCardPool();
private:
	static NetworkCardPool *instance;
	std::vector<NetworkCard> ipList;
};

#endif