//
// Created by error on 2017/9/28.
//

#ifndef VIP_ETHERNETHANDLER_H
#define VIP_ETHERNETHANDLER_H

#include "handler/PacketChannelHandler.h"
#include "protocol/arp/Arp.h"

class EthernetHandler : public PacketChannelHandler
{
public:
	EthernetHandler();
	~EthernetHandler();

	virtual bool init();
	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);
private:
	Arp arp;
};


#endif //VIP_ETHERNETHANDLER_H
