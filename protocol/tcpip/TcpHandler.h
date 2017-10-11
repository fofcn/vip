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

	virtual void channelRead(Packet *p);
	virtual void write(Packet *p);
};

#endif