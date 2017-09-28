//
// Created by jiquanxi on 17-9-27.
//

#include "DefaultPacketChannelPipeline.h"


PacketChannelPipeline* DefaultPacketChannelPipeline::addLast(PacketChannelHandler *handler)
{
    PacketChannelHandler *prev = tail->prev;
    prev->next = handler;
    handler->prev = prev;
    handler->next= tail;
    tail->prev = handler;
    return this;
}

void DefaultPacketChannelPipeline::print()
{
    PacketChannelHandler *cur = head;
    while(cur)
    {
        std::cout << cur->getName().c_str() << std::endl;
        cur = cur->next;
    }
}


void DefaultPacketChannelPipeline::fireChannelRead(Packet *p)
{
    invokeChannelRead(head, p);
}

void DefaultPacketChannelPipeline::invokeChannelRead(PacketChannelHandler *next, Packet *p)
{
    if(next != nullptr)
    {
        next->channelRead(p);
        invokeChannelRead(next->next, p);
    }
}