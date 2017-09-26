//
// Created by error on 2017/9/26.
//

#ifndef VIP_DEFAULTPACKETHANDLERCONTEXT_H
#define VIP_DEFAULTPACKETHANDLERCONTEXT_H

#include "AbstractPacketHandlerContext.h"
#include "PacketHandler.h"

class DefaultPacketHandlerContext : public AbstractPacketHandlerContext
{
public:
    DefaultPacketHandlerContext(DefaultPacketPipeline *pipeline, const std::string &name, PacketHandler *handler) :
            AbstractPacketHandlerContext(pipeline, name, false, false)
    {
        this->_handler = handler;
    }

    virtual PacketHandler *handler() {return _handler;};
private:
    PacketHandler *_handler;
};

#endif //VIP_DEFAULTPACKETHANDLERCONTEXT_H
