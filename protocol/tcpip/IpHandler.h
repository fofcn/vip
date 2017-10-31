
#ifndef VIP_IPHANDLER_H_
#define VIP_IPHANDLER_H_

#pragma once
#include "handler/PacketChannelHandler.h"

class IpHandler : public PacketChannelHandler
{
public:
	IpHandler();
	~IpHandler();

	virtual bool init();

	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);
private:
	static int identification;
};

#endif