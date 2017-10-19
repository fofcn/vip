#ifndef VIP_TCPHANDLER_H_
#define VIP_TCPHANDLER_H_

#pragma once

#include "handler/PacketChannelHandler.h"
#include "pcap/Packet.h"

class TcpHandler : public PacketChannelHandler
{
public:
	TcpHandler();
	~TcpHandler();

	virtual bool init();
	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);
};

#endif