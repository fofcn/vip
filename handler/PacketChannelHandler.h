//
// Created by jiquanxi on 17-9-27.
//

#ifndef VIP_PACKETCHANNELHANDLER_H
#define VIP_PACKETCHANNELHANDLER_H

#include <iostream>
#include "pcap/SkBuffer.h"

class PacketChannelHandler
{
public:
	PacketChannelHandler() {}
	PacketChannelHandler(std::string name) : name(name), next(nullptr), prev(nullptr) {}
	virtual std::string getName() { return name; };
    virtual void channelRead(SkBuffer *skBuffer) = 0;
    virtual void write(SkBuffer *skBuffer) = 0;
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
    virtual void channelRead(SkBuffer *skBuffer) {}
    virtual void write(SkBuffer *skBufferp) {}
};


#endif //VIP_PACKETCHANNELHANDLER_H
