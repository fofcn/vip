#ifndef VIP_ICMPHANDLER_H_
#define VIP_ICMPHANDLER_H_

#pragma once

#include "handler/PacketChannelHandler.h"

class IcmpHandler : public PacketChannelHandler
{
public:
	IcmpHandler();
	~IcmpHandler();

	virtual bool init();
	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);

	static ushort checksum(ushort *buffer, int size);
private:
	PacketChannelHandler *prev;
};

#endif