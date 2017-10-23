// VipDemo.cpp : Defines the entry point for the console application.
//

#include <Winsock2.h>

#include <iostream>
#include <map>

#include "handler/DefaultPacketChannelPipeline.h"
#include "pcap.h"
#include "protocol/ProtocolHeader.h"
#include "pcap/Device.h"
#include "protocol/tcpip/EthernetHandler.h"
#include "protocol/tcpip/IpHandler.h"
#include "pcap/NetDevice.h"
#include "ip/NetworkCardPool.h"

int main(int argc, char **argv)
{
	u_long ip = ntohl(inet_addr("192.168.1.220"));
	NetworkCardPool::getInstance()->addIp(ip);
	//for home
	char *devName = "\\Device\\NPF_{4B3493A3-4AEB-49E5-839D-134946B0CED4}";

	//for outside
	//char *devName = "\\Device\\NPF_{668E95F4-C365-4BC4-A3A9-407FC352316D}";
	Device *dev = new NetDevice(devName);
	dev->startCapture();
}
