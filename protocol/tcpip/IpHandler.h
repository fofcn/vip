
#ifndef VIP_IPHANDLER_H_
#define VIP_IPHANDLER_H_

#pragma once
#include "handler/PacketChannelHandler.h"

class IpHandler : public PacketChannelHandler
{
public:
	IpHandler();
	~IpHandler();

	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);
private:
	PacketChannelHandler *tcpHandler;
	PacketChannelHandler *icmpHandler;
	PacketChannelHandler *prev;
};

#endif