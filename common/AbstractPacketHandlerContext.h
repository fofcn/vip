//
// Created by error on 2017/9/26.
//

#ifndef VIP_ABSTRACTPACKETHANDLERCONTEXT_H
#define VIP_ABSTRACTPACKETHANDLERCONTEXT_H

#include "PacketPipeline.h"
#include "PacketHandlerContext.h"

class DefaultPacketPipeline;

class AbstractPacketHandlerContext : public PacketHandlerContext
{
public:
    AbstractPacketHandlerContext(DefaultPacketPipeline *pipeline, std::string name, bool inbound, bool outbound);

    void setInbound(bool inOrOut) {inbound = inOrOut;}
    void setOutbound(bool inOrOut) {outbound = inOrOut;}
    std::string getName() {return name;}

    virtual PacketHandlerContext *firePacketReadComplete();
//    virtual PacketHandler *handler();

    static void invokePacketReadComplete(AbstractPacketHandlerContext *next);
public:
    AbstractPacketHandlerContext *next;
    AbstractPacketHandlerContext *prev;
private:
    bool inbound;
    bool outbound;
    DefaultPacketPipeline *pipeline;
    std::string name;

    void invokeChannelReadComplete();

    AbstractPacketHandlerContext *findContextInbound();
};



#endif //VIP_ABSTRACTPACKETHANDLERCONTEXT_H
