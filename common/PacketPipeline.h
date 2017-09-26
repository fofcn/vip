//
// Created by jiquanxi on 17-9-25.
//

#ifndef VIP_PACKETPIPELINE_H
#define VIP_PACKETPIPELINE_H

#include "PacketHandler.h"
#include "PacketInboundInvoker.h"
#include "AbstractPacketHandlerContext.h"
#include "PacketOutboundHandler.h"
#include "PacketInboundHandler.h"

class AbstractPacketHandlerContext;

class PacketPipeline
{
public:
    /**
     * 添加一个Handler到末尾
     * @param handler
     * @param inbound
     * @return
     */
    virtual PacketPipeline *addLast(PacketHandler *handler, bool inbound) = 0;

    /**
     * 添加一个handler到末尾
     * @param name
     * @param handler
     * @param inbound
     * @return
     */
    virtual PacketPipeline *addLast(std::string name, PacketHandler *handler, bool inbound) = 0;

    /**
     * 打印所有handler名称
     */
    virtual void print() = 0;
};

#endif //VIP_PACKETPIPELINE_H
