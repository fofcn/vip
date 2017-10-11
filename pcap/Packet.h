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
	int getCurSize();
private:
	uchar *p;
	uchar *start;
	//网络设备
	Device *device;
	//数据总长度
	int size;
	//当前协议数据大小
	int curSize;
	//协议头
	union header *h;
	//ip头
	ip_header *ipHeader;
};


#endif //VIP_PACKET_H
