//
// Created by error on 2017/9/26.
//

#include "DefaultPacketPipeline.h"
#include "DefaultPacketHandlerContext.h"
#include "HeadContext.h"
#include "TailContext.h"

DefaultPacketPipeline::DefaultPacketPipeline()
{
    head = new HeadContext(this);
    tail = new TailContext(this);

    head->next = tail;
    head->prev = tail;
    tail->prev = head;
    tail->next = head;
}

PacketPipeline *DefaultPacketPipeline::addLast(PacketHandler *handler, bool inbound)
{
    addLast(handler->getName(), handler, inbound);
}

PacketPipeline *DefaultPacketPipeline::addLast(std::string name, PacketHandler *handler, bool inbound)
{
    AbstractPacketHandlerContext *newCtx = new DefaultPacketHandlerContext(this, name, handler, inbound);

    AbstractPacketHandlerContext *prev = tail->prev;
    prev->next = newCtx;
    newCtx->prev = prev;
    newCtx->next = tail;
    tail->prev = newCtx;
}

void DefaultPacketPipeline::print()
{
    AbstractPacketHandlerContext *cur = head->next;
    while(cur != tail)
    {
        std::cout << cur->getName().c_str() << std::endl;
        cur = cur->next;
    }
}

PacketInboundInvoker *DefaultPacketPipeline::firePacketReadComplete()
{
//    //查找inbound
//    next = head;
//    std::cout << next->getName().c_str() << std::endl;
    AbstractPacketHandlerContext::invokePacketReadComplete(head);
    return this;
}