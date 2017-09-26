//
// Created by jiquanxi on 17-9-25.
//

#ifndef VIP_PACKETHANDLER_H
#define VIP_PACKETHANDLER_H

#include <iostream>

class PacketHandler
{
public:
    virtual std::string getName() = 0;
public:
    PacketHandler *next;
    PacketHandler *prev;
};

class DefaultPacketHandler : public PacketHandler
{
public:
    DefaultPacketHandler(std::string name) : name(name) {}
public:
    virtual std::string getName() {return name;}
private:
    std::string name;
};

#endif //VIP_PACKETHANDLER_H
