//
// Created by error on 2017/9/26.
//

#ifndef VIP_ABSTRACTPACKETHANDLERCONTEXT_H
#define VIP_ABSTRACTPACKETHANDLERCONTEXT_H

#include "PacketPipeline.h"
#include "PacketHandlerContext.h"
#include "DefaultPacketPipeline.h"

class DefaultPacketPipeline;

class AbstractPacketHandlerContext
{
public:
    AbstractPacketHandlerContext(DefaultPacketPipeline *pipeline, std::string name, bool inbound, bool outbound);

    void setInbound(bool inOrOut) {inbound = inOrOut;}
    void setOutbound(bool inOrOut) {outbound = inOrOut;}
    void setLast(bool isLast) {last = isLast;};
    bool isLast() {return last;}
    std::string getName() {return name;}

    virtual PacketHandler *handler() {return nullptr;};

    static void invokePacketReadComplete(AbstractPacketHandlerContext *next);
public:
    AbstractPacketHandlerContext *next;
    AbstractPacketHandlerContext *prev;
private:
    bool last;
    bool inbound;
    bool outbound;
    DefaultPacketPipeline *pipeline;
    std::string name;

    void invokeChannelReadComplete();

    AbstractPacketHandlerContext *findContextInbound();
};



#endif //VIP_ABSTRACTPACKETHANDLERCONTEXT_H
