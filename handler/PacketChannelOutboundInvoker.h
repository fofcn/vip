//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKETCHANNELOUTBOUNDINVOKER_H
#define VIP_PACKETCHANNELOUTBOUNDINVOKER_H


#include "../pcap/Packet.h"

class PacketChannelOutboundInvoker
{
public:
    virtual void write(Packet p) = 0;
};


#endif //VIP_PACKETCHANNELOUTBOUNDINVOKER_H
