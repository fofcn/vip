//
// Created by jiquanxi on 17-9-27.
//

#include "PacketChannelPipeline.h"

PacketChannelPipeline::PacketChannelPipeline()
{
    head = new DefaultChannelHandler("");
    tail = new DefaultChannelHandler("");
    head->next = tail;
    tail->prev = head;
}


