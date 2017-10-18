//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKETCHANNELINBOUNDHANDLER_H
#define VIP_PACKETCHANNELINBOUNDHANDLER_H


#include "PacketChannelHandler.h"

class PacketChannelInboundHandler : public PacketChannelHandler
{
public:
    virtual void read(PacketChannelHandler *handler, void *packet) = 0;
};


#endif //VIP_PACKETCHANNELINBOUNDHANDLER_H
