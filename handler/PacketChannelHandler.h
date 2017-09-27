//
// Created by jiquanxi on 17-9-27.
//

#ifndef VIP_PACKETCHANNELHANDLER_H
#define VIP_PACKETCHANNELHANDLER_H

#include <iostream>

class PacketChannelHandler
{
public:
    virtual std::string getName() = 0;
    virtual void fireReadComplete() = 0;
public:
    PacketChannelHandler *next;
    PacketChannelHandler *prev;
};

class DefaultChannelHandler : public PacketChannelHandler
{
public:
    DefaultChannelHandler(std::string name) : name(name) {}
    virtual std::string getName() {return name;}
    virtual void fireReadComplete() {std::cout<< name.c_str()<<std::endl;}
private:
    std::string name;
};


#endif //VIP_PACKETCHANNELHANDLER_H
