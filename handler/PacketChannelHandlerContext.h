//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKETCHANNELHANDLERCONTEXT_H
#define VIP_PACKETCHANNELHANDLERCONTEXT_H


#include "PacketChannelInboundInvoker.h"
#include "PacketChannelOutboundInvoker.h"

class PacketChannelHandlerContext : public PacketChannelInboundInvoker, public PacketChannelOutboundInvoker
{

};


#endif //VIP_PACKETCHANNELHANDLERCONTEXT_H
