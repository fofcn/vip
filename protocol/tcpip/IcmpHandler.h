#ifndef VIP_ICMPHANDLER_H_
#define VIP_ICMPHANDLER_H_

#pragma once

#include "handler/PacketChannelHandler.h"

class IcmpHandler : public PacketChannelHandler
{
public:
	IcmpHandler();
	virtual void channelRead(Packet *p);
	virtual void write(Packet *p);
private:
	PacketChannelHandler *prev;
};

#endif