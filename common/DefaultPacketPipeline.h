//
// Created by error on 2017/9/26.
//

#ifndef VIP_DEFAULTPACKETPIPELINE_H
#define VIP_DEFAULTPACKETPIPELINE_H

#include "PacketPipeline.h"
#include "PacketInboundInvoker.h"

class DefaultPacketPipeline : public PacketPipeline, public PacketInboundInvoker
{
public:
    DefaultPacketPipeline();
public:
    virtual PacketPipeline *addLast(PacketHandler *handler, bool inbound);
    virtual PacketPipeline *addLast(std::string name, PacketHandler *handler, bool inbound);
    virtual void print();

    virtual PacketInboundInvoker *firePacketReadComplete();

private:
    PacketHandler *findNextInbound();

private:
    AbstractPacketHandlerContext *head;
    AbstractPacketHandlerContext *tail;
};

#endif //VIP_DEFAULTPACKETPIPELINE_H
