#ifndef VIP_ARP_H_
#define VIP_ARP_H_

#include "pcap/SkBuffer.h"
#include "pcap/Device.h"
#include "protocol/ProtocolHeader.h"

class Arp
{
public:
	SkBuffer create(int type, uint dstIp, uint srcIp, Device *dev, uchar *dstMac);
};

#endif
