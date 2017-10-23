//
// Created by jiquanxi on 17-9-26.
//

#ifndef VIP_SIMPLEPACKETHANDLER_H
#define VIP_SIMPLEPACKETHANDLER_H

#include "../common/PacketHandler.h"

class SimplePacketHandler : public PacketHandler
{
public:
    SimplePacketHandler() : name("SimplePacketHandler") {}
    virtual std::string getName() {return name;}

private:
    std::string name;
};

#endif //VIP_SIMPLEPACKETHANDLER_H
