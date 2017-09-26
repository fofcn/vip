//
// Created by error on 2017/9/26.
//

#ifndef VIP_PACKETHANDLERCONTEXT_H
#define VIP_PACKETHANDLERCONTEXT_H

#include "PacketHandler.h"

class PacketHandlerContext
{
public:
    virtual PacketHandlerContext *firePacketReadComplete() = 0;
    virtual PacketHandler *handler() = 0;
};

#endif //VIP_PACKETHANDLERCONTEXT_H
