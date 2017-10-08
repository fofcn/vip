#pragma once

#ifndef VIP_IP_H_
#define VIP_IP_H_

#include "protocol/ProtocolHeader.h"

class NetworkCard
{
public:
	NetworkCard(uint ip) : ip(ip) {};
	bool equals(uint i) { return i == ip; }
private:
	uint ip;
	uchar mac[MAC_LEN];
};

#endif