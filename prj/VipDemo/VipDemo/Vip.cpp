// VipDemo.cpp : Defines the entry point for the console application.
//

#include <Winsock2.h>

#include "handler/DefaultPacketChannelPipeline.h"
#include "pcap.h"
#include "protocol/ProtocolHeader.h"
#include "pcap/Device.h"
#include "protocol/tcpip/EthernetHandler.h"
#include "protocol/tcpip/IpHandler.h"
#include "pcap/NetDevice.h"
#include "ip/NetworkCardPool.h"

int main(int argc, char**  argv)
{
	int size = sizeof(struct arp_hdr);
	u_long ip = ntohl(inet_addr("192.168.2.220"));
	NetworkCardPool::getInstance()->addIp(ip);
	char *devName = "\\Device\\NPF_{668E95F4-C365-4BC4-A3A9-407FC352316D}";
	Device *dev = new NetDevice(devName);
	dev->startCapture();
}
