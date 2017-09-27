//
// Created by error on 2017/9/26.
//

#include "AbstractPacketHandlerContext.h"

AbstractPacketHandlerContext::AbstractPacketHandlerContext(DefaultPacketPipeline *pipeline, std::string name,
                                                           bool inbound, bool outbound)
{
    last = false;
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
    if(next != nullptr && next->handler() != nullptr)
    {
        std::cout << next->handler()->getName().c_str() << std::endl;
    }

    next->invokeChannelReadComplete();
}


void AbstractPacketHandlerContext::invokeChannelReadComplete()
{
    invokePacketReadComplete(findContextInbound());
}

AbstractPacketHandlerContext *AbstractPacketHandlerContext::findContextInbound() {
    AbstractPacketHandlerContext *ctx = this;
    do {
        ctx = ctx->next;
        if(ctx->inbound)
            break;
    } while (!ctx->isLast());

    if(!ctx->inbound)
    {
        return nullptr;
    }

    return ctx;
}


//PacketHandler* AbstractPacketHandlerContext::handler() {return nullptr;}
