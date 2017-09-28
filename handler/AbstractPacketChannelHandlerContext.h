//
// Created by error on 2017/9/28.
//

#ifndef VIP_ABSTRACTPACKETCHANNELHANDLERCONTEXT_H
#define VIP_ABSTRACTPACKETCHANNELHANDLERCONTEXT_H


#include "../common/PacketHandlerContext.h"
#include "PacketChannelHandlerContext.h"
#include "../pcap/Packet.h"

class AbstractPacketChannelHandlerContext : public PacketChannelHandlerContext
{
public:
    virtual PacketChannelHandlerContext *fireChannelRead(Packet p);

protected:
    AbstractPacketChannelHandlerContext *next;
    AbstractPacketChannelHandlerContext *prev;
};


class DefaultPacketChannelHanderContext : public AbstractPacketChannelHandlerContext
{
public:
    virtual PacketChannelHandlerContext *fireChannelRead(Packet p);
};

#endif //VIP_ABSTRACTPACKETCHANNELHANDLERCONTEXT_H
