#include <WinSock2.h>
#include <string.h>
#include "Arp.h"

SkBuffer Arp::request(uint dstIp, uint srcIp, Device *dev, uchar *srcMac, uchar *dstMac)
{
	return create(ECHO_REQUEST, dstIp, srcIp, dev, srcMac, dstMac);
}

SkBuffer Arp::response(uint dstIp, uint srcIp, Device *dev, uchar *srcMac, uchar *dstMac)
{
	return create(ECHO_REPLY, dstIp, srcIp, dev, srcMac, dstMac);
}

SkBuffer Arp::create(int type, uint dstIp, uint srcIp, Device *dev, uchar *srcMac, uchar *dstMac)
{
	SkBuffer skBuffer(dev);
	skBuffer.allocBuffer(sizeof(struct arp_hdr) + sizeof(struct ether_hdr));
	skBuffer.reserve(sizeof(struct ether_hdr));
	skBuffer.resetNetworkHeader();
	
	arp_header *arpHdr = (arp_header *)skBuffer.skData();
	//¹¹ÔìARPÏìÓ¦
	arpHdr->hw_type = htons(HW_TYPE_ETH);
	arpHdr->hw_size = MAC_LEN;
	arpHdr->proto_type = htons(IPV4);
	arpHdr->proto_size = 4;
	arpHdr->op_code = htons(ARP_REPLY);
	arpHdr->sender_ip = srcIp;
	memcpy(arpHdr->sender_mac, srcMac, MAC_LEN);
	arpHdr->target_ip = dstIp;
	if (dstMac != nullptr)
	{
		memcpy(arpHdr->target_mac, arpHdr->sender_mac, MAC_LEN);
	}
	

	return skBuffer;
}