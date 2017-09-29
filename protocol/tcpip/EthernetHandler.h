//
// Created by error on 2017/9/28.
//

#ifndef VIP_ETHERNETHANDLER_H
#define VIP_ETHERNETHANDLER_H

#include "IpHandler.h"
#include "../../handler/PacketChannelHandler.h"

class EthernetHandler : public PacketChannelHandler
{
public:
	EthernetHandler(std::string name);
	~EthernetHandler();
	virtual std::string getName();
	virtual void channelRead(Packet *p);
	virtual void write(Packet p);

private:
	IpHandler *ipHandler;
};


#endif //VIP_ETHERNETHANDLER_H
