//
// Created by jiquanxi on 17-9-25.
//

#ifndef VIP_PACKETPIPELINE_H
#define VIP_PACKETPIPELINE_H

#include "PacketHandler.h"

class PacketPipeline
{
public:
    virtual PacketPipeline *addLast(PacketHandler *handler) = 0;
    virtual void print() = 0;
public:
    PacketHandler *head;
    PacketHandler *tail;
};

class DefaultPacketPipeline : public PacketPipeline
{
public:
    DefaultPacketPipeline();
public:
    virtual PacketPipeline *addLast(PacketHandler *handler);
    virtual void print();
};

#endif //VIP_PACKETPIPELINE_H
