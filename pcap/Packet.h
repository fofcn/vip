//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKET_H
#define VIP_PACKET_H

#include <iostream>

#include "../protocol/ProtocolHeader.h"

class Packet
{
public:
	Packet(uchar *p) : p(p) {}
    std::string content;
private:
	uchar *p;
};


#endif //VIP_PACKET_H
