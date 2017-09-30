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
	Packet(uchar *p) : p(p), start(p) {}
	uchar *getP() { return p; }
	void moveToIpStart() { p = p + sizeof(struct ether_header); }
	void moveToTcpStart() { p = p + sizeof(struct ip_hdr); }
    std::string content;
private:
	uchar *p;
	uchar *start;
};


#endif //VIP_PACKET_H
