


#ifndef VIP_NETDEVICE_H_
#define VIP_NETDEVICE_H_
#pragma once

#include <iostream>
#include <pcap.h>
#include "Device.h"
#include "handler/DefaultPacketChannelPipeline.h"
#include "protocol/ProtocolHeader.h"

class NetDevice : public Device
{
public:
	NetDevice(char *name);
	~NetDevice();
	
	
	virtual void startCapture();
	virtual void stopCapture();
	virtual void send(void *arg);
	virtual char *getMac();
private:
	/*初始化设备*/
	bool init();

	/*判断接口是否存在*/
	bool exists();

	/*创建并激活网卡设备*/
	bool createAndActive();

	/*抓取到包后回调函数*/
	static void callback(u_char *arg, const struct pcap_pkthdr *pktHdr, const u_char *packet);
private:
	/*设备名称*/
	char *name;

	/*MAC 地址*/
	uchar mac[MAC_LEN];

	/*设备句柄*/
	pcap_t *pd;

	/*是否已经初始化*/
	bool initialized;

	/*是否停止抓包*/
	bool stopped;

	PacketChannelPipeline *pipeline;
};

#endif