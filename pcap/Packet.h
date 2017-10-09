//
// Created by error on 2017/9/28.
//
#pragma once

#ifndef VIP_PACKET_H
#define VIP_PACKET_H

#include <iostream>

#include "protocol/ProtocolHeader.h"
#include "pcap/NetDevice.h"

class Packet
{
public:
	Packet(uchar *p);
	uchar *getP();
	void moveToIpStart();
	void moveToTcpStart();
	void write();
	int getSize();
private:
	uchar *p;
	uchar *start;
	NetDevice *device;
	int size;
};


#endif //VIP_PACKET_H
