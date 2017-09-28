//
// Created by jiquanxi on 17-9-27.
//

#include "PacketChannelPipeline.h"

PacketChannelPipeline::PacketChannelPipeline()
{
    head = new DefaultChannelHandler("");
    tail = new DefaultChannelHandler("");
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

PacketChannelPipeline::~PacketChannelPipeline()
{
    if(head != nullptr)
    {
        delete head;
        head = nullptr;
    }

    if(tail != nullptr)
    {
        delete tail;
        tail = nullptr;
    }

}


