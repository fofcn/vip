//
// Created by jiquanxi on 17-9-25.
//

#include "PacketPipeline.h"

DefaultPacketPipeline::DefaultPacketPipeline()
{
    head = NULL;
    tail = NULL;
}

PacketPipeline *DefaultPacketPipeline::addLast(PacketHandler *handler)
{
    if(head == NULL)
    {
        head = handler;
        tail = handler;
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    else
    {
        PacketHandler *prev = tail->prev;
        prev->next = handler;
        handler->prev = prev;
        handler->next = tail;
        tail->prev = handler;
    }
}

void DefaultPacketPipeline::print()
{
    PacketHandler *cur = head;
    while(cur)
    {
        std::cout << cur->getName().c_str() << std::endl;
        if(cur->next == tail)
        {
             break;
        }
        cur = cur->next;
    }
}
