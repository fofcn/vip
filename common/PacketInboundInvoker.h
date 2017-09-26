//
// Created by error on 2017/9/26.
//

#ifndef VIP_PACKETINBOUNDINVOKER_H
#define VIP_PACKETINBOUNDINVOKER_H

class PacketInboundInvoker
{
public:
    /**
     * 读取到一个packet后调用
     * @return PacketInboundInvoker *
     */
    virtual PacketInboundInvoker *firePacketReadComplete() = 0;

    /**
     * 是否为inbound
     * @return true是， false不是
     */
    bool isInbound() {return true;}
};

#endif //VIP_PACKETINBOUNDINVOKER_H
