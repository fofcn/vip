//
// Created by error on 2017/9/26.
//

#ifndef VIP_PACKETHANDLERCONTEXT_H
#define VIP_PACKETHANDLERCONTEXT_H

#include "PacketHandler.h"
#include "PacketOutboundHandler.h"
#include "PacketInboundHandler.h"
#include "AbstractPacketHandlerContext.h"

class PacketHandlerContext
{
public:
    virtual PacketHandler *handler() = 0;
};

#endif //VIP_PACKETHANDLERCONTEXT_H
