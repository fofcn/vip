//
// Created by error on 2017/9/28.
//

#ifndef VIP_ETHERNETHANDLER_H
#define VIP_ETHERNETHANDLER_H

#include "../../handler/PacketChannelHandler.h"

class EthernetHandler : public PacketChannelHandler
{
public:
	EthernetHandler();
	~EthernetHandler();
	virtual std::string getName();
	virtual void channelRead(SkBuffer *skBuffer);
	virtual void write(SkBuffer *skBuffer);

private:
	PacketChannelHandler *ipHandler;
	PacketChannelHandler *arpHandler;
};


#endif //VIP_ETHERNETHANDLER_H
