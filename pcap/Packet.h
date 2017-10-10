//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKET_H
#define VIP_PACKET_H

#pragma once

#include <iostream>

#include "protocol/ProtocolHeader.h"
#include "pcap/Device.h"

union header
{
	tcp_header *tcp;
	icmp_header *icmp;
	ip_header *ip;
};


class Packet
{
public:
	Packet(uchar *p, int size, Device *dev);
	uchar *getP();
	Device *getDevice();
	void moveEthLen();
	void moveToTcpStart();
	void write();
	ip_header *getIpHeader();
	icmp_header *getIcmpHeader();
	int getSize();
private:
	uchar *p;
	uchar *start;
	Device *device;
	int size;
	union header *h;
	ip_header *ipHeader;
};


#endif //VIP_PACKET_H
