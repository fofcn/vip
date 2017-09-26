//
// Created by error on 2017/9/26.
//

#include "AbstractPacketHandlerContext.h"

AbstractPacketHandlerContext::AbstractPacketHandlerContext(DefaultPacketPipeline *pipeline, std::string name,
                                                           bool inbound, bool outbound)
{
    this->pipeline = pipeline;
    this->name = name;
    this->inbound = inbound;
    this->outbound = outbound;
    next = NULL;
    prev = NULL;
}

PacketHandlerContext *AbstractPacketHandlerContext::firePacketReadComplete()
{
    invokePacketReadComplete(findContextInbound());
    return this;
}

void AbstractPacketHandlerContext::invokePacketReadComplete(AbstractPacketHandlerContext *next)
{
    next->invokeChannelReadComplete();
}


void AbstractPacketHandlerContext::invokeChannelReadComplete()
{
    std::cout << getName().c_str() <<std::endl;
}

AbstractPacketHandlerContext *AbstractPacketHandlerContext::findContextInbound() {
    AbstractPacketHandlerContext *ctx = this;
    do {
        ctx = ctx->prev;
    } while (!ctx->outbound);
    return ctx;
}

