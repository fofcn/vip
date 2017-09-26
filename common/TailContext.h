//
// Created by error on 2017/9/26.
//

#ifndef VIP_TAILCONTEXT_H
#define VIP_TAILCONTEXT_H


#include "AbstractPacketHandlerContext.h"
#include "DefaultPacketPipeline.h"

class TailContext : public AbstractPacketHandlerContext
{
public:
    TailContext(DefaultPacketPipeline *pipeline);
};


#endif //VIP_TAILCONTEXT_H
