#pragma once

#include "../../../protocol/tcpip/EthernetHandler.h"

class EthernetHandler : public PacketChannelHandler
{
public:
	EthernetHandler();
	~EthernetHandler();

	virtual std::string getName() { return name; }
	virtual void channelRead(Packet *p);
	virtual void write(Packet p);
private:
	std::string name;
};

