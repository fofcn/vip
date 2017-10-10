
#ifndef VIP_IPHANDLER_H_
#define VIP_IPHANDLER_H_

#pragma once
#include "handler/PacketChannelHandler.h"

class IpHandler : public PacketChannelHandler
{
public:
	IpHandler();
	~IpHandler();

	virtual void channelRead(Packet *p);
	virtual void write(Packet p);
private:
	PacketChannelHandler *tcpHandler;
	PacketChannelHandler *icmpHandler;
	PacketChannelHandler *prev;
};

#endif