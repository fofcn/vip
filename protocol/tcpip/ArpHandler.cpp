
#include <WinSock2.h>
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "ip/NetworkCardPool.h"

extern void print_ip(int ip);

ArpHandler::ArpHandler() : PacketChannelHandler("ARP")
{
}

void ArpHandler::channelRead(Packet *p)
{
	p->moveToIpStart();

	arp_header *arpHdr = (arp_header *)p->getP();
	//std::cout << "arp operation code: " << ntohs(arpHdr->op_code) << std::endl;
	//不是以太网类型放弃
	if (ntohs(arpHdr->hw_type) != HW_TYPE_ETH)
	{
		return;
	}

	if (ntohs(arpHdr->proto_type) != IPV4)
	{
		return;
	}
	//ARP请求时，判断是否存在该IP
	if (ntohs(arpHdr->op_code) == ARP_REQUEST)
	{
		print_ip(ntohl(arpHdr->target_ip));
		if (NetworkCardPool::getInstance()->contains(ntohl(arpHdr->target_ip)))
		{
			//构造ARP响应
			arp_header arp;
			arp.hw_type = htons(HW_TYPE_ETH);
			arp.hw_size = MAC_LEN;
			arp.proto_type = htons(IPV4);
			arp.proto_size = 4;
			arp.op_code = htons(ARP_REPLYL);
			arp.sender_ip = arpHdr->target_ip;
			strcpy((char *)arp.sender_mac, "");//TODO MAC地址
			arp.target_ip = arpHdr->target_ip;
			strcpy((char *)arp.target_mac, (char *)arpHdr->target_mac);

			ether_header eth;
			strcpy((char *)eth.ether_dhost, (char *)arpHdr->target_mac);
			strcpy((char *)eth.ether_shost, (char *)arpHdr->target_mac);
			eth.ether_type = htons(ETHERNET_ARP);

			uchar pt[sizeof(struct arp_hdr) + sizeof(struct ether_hdr)];

			memcpy(pt, &eth, sizeof(struct ether_hdr));

			uchar *pp = pt;
			pp += sizeof(struct ether_hdr);
			memcpy(pp, &arp, sizeof(arp_hdr));

			Packet newPacket((uchar *)pt, p->getDevice());
			newPacket.write();
		}
	}
	else//ARP响应
	{
		//查看是否存在路由
	}

}

void ArpHandler::write(Packet p)
{

}