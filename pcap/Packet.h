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
	ip_header *getOldIpHeader();
	icmp_header *getIcmpHeader();
	int getSize();
	int getCurSize();

	void setOldP(uchar *p);
private:
	uchar *p;
	uchar *old;
	uchar *start;
	//�����豸
	Device *device;
	//�����ܳ���
	int size;
	//��ǰЭ�����ݴ�С
	int curSize;
	//Э��ͷ
	union header *h;
	//ipͷ
	ip_header *ipHeader;

	ether_header *ethHeader;
};


#endif //VIP_PACKET_H
