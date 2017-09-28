//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKETCHANNELINBOUNDINVOKER_H
#define VIP_PACKETCHANNELINBOUNDINVOKER_H


#include "../pcap/Packet.h"

class PacketChannelInboundInvoker
{
public:
    virtual PacketChannelInboundInvoker *fireChannelRead(Packet p) = 0;
};


#endif //VIP_PACKETCHANNELINBOUNDINVOKER_H
