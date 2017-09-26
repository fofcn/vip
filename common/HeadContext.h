//
// Created by error on 2017/9/26.
//

#ifndef VIP_HEADCONTEXT_H
#define VIP_HEADCONTEXT_H


#include "AbstractPacketHandlerContext.h"
#include "DefaultPacketPipeline.h"

class HeadContext : public AbstractPacketHandlerContext
{
public:
    HeadContext(DefaultPacketPipeline *pipeline);
    virtual PacketHandler *handler();
};


#endif //VIP_HEADCONTEXT_H
