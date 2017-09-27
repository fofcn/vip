//
// Created by jiquanxi on 17-9-27.
//

#ifndef VIP_PACKETCHANNELPIPELINE_H
#define VIP_PACKETCHANNELPIPELINE_H


#include "PacketChannelHandler.h"

class PacketChannelPipeline
{
public:
    PacketChannelPipeline();
    virtual PacketChannelPipeline *addLast(PacketChannelHandler *handler) = 0;
    virtual void print() = 0;
    virtual void fireReadComplete() = 0;
public:
    PacketChannelHandler *head;
    PacketChannelHandler *tail;
};


#endif //VIP_PACKETCHANNELPIPELINE_H
