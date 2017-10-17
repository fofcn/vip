#ifndef ARPHANDLER_H_

#define ARPHANDLER_H_
#pragma once

#include "handler/PacketChannelHandler.h"
#include "EthernetHandler.h"

class ArpHandler : public PacketChannelHandler
{
public:
	ArpHandler();
	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);
};

#endif
