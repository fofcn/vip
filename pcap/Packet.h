//
// Created by error on 2017/9/28.
//

#ifndef VIP_PACKET_H
#define VIP_PACKET_H

#pragma once

#include <iostream>

#include "protocol/ProtocolHeader.h"
#include "pcap/Device.h"

class Packet
{
public:
	Packet(uchar *p, Device *dev);
	uchar *getP();
	Device *getDevice();
	void moveToIpStart();
	void moveToTcpStart();
	void write();
	int getSize();
private:
	uchar *p;
	uchar *start;
	Device *device;
	int size;
};


#endif //VIP_PACKET_H
