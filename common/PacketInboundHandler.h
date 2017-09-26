//
// Created by error on 2017/9/26.
//

#ifndef VIP_PACKETINBOUNDHANDLER_H
#define VIP_PACKETINBOUNDHANDLER_H

#include "PacketHandler.h"
#include "PacketHandlerContext.h"

class PacketInboundHandler : public PacketHandler
{
public:
    virtual void packetReadComplete(PacketHandlerContext *ctx) = 0;
};

#endif //VIP_PACKETINBOUNDHANDLER_H
