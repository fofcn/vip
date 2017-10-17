//
// Created by jiquanxi on 17-9-27.
//

#ifndef VIP_DEFAULTPACKETCHANNELPIPELINE_H
#define VIP_DEFAULTPACKETCHANNELPIPELINE_H

#include "PacketChannelPipeline.h"

class DefaultPacketChannelPipeline : public PacketChannelPipeline
{
public:
    virtual PacketChannelPipeline *addLast(PacketChannelHandler *handler);
    virtual void print();
    virtual void fireChannelRead(SkBuffer *skBuffer);
private:
    void invokeChannelRead(PacketChannelHandler *next, SkBuffer *skBuffer);
};



#endif //VIP_DEFAULTPACKETCHANNELPIPELINE_H
