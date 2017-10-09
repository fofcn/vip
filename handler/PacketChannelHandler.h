//
// Created by jiquanxi on 17-9-27.
//

#ifndef VIP_PACKETCHANNELHANDLER_H
#define VIP_PACKETCHANNELHANDLER_H

#include <iostream>
#include "pcap/Packet.h"

class PacketChannelHandler
{
public:
	PacketChannelHandler() {}
	PacketChannelHandler(std::string name) : name(name), next(nullptr), prev(nullptr) {}
	virtual std::string getName() { return name; };
    virtual void channelRead(Packet *p) = 0;
    virtual void write(Packet p) = 0;
protected:
    bool inbound;
    bool outbound;
	std::string name;
public:
    PacketChannelHandler *next;
    PacketChannelHandler *prev;
};

class DefaultChannelHandler : public PacketChannelHandler
{
public:
	DefaultChannelHandler(std::string name) : PacketChannelHandler(name){inbound = false; outbound = false; this->name = name; }
    virtual std::string getName() {return name;}
    virtual void channelRead(Packet *p) {}
    virtual void write(Packet p) {}
};


#endif //VIP_PACKETCHANNELHANDLER_H
