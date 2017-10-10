
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
	p->moveEthLen();

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
		printf("Srouce Ip: ");
		print_ip(ntohl(arpHdr->sender_ip));
		printf("Target Ip:");
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
			memcpy((char *)(arp.sender_mac), (char *)(p->getDevice()->getMac()), MAC_LEN);
			arp.target_ip = arpHdr->target_ip;
			memcpy((char *)arp.target_mac, (char *)arpHdr->sender_mac, MAC_LEN);

			ether_header eth;
			memcpy((char *)eth.ether_dhost, (char *)arpHdr->sender_mac, MAC_LEN);
			memcpy((char *)eth.ether_shost, (char *)p->getDevice()->getMac(), MAC_LEN);
			eth.ether_type = htons(ETHERNET_ARP);

			uchar pt[sizeof(struct arp_hdr) + sizeof(struct ether_hdr)] = {0};

			memcpy(pt, &eth, sizeof(struct ether_hdr));

			uchar *pp = pt;
			pp += sizeof(struct ether_hdr);
			memcpy(pp, &arp, sizeof(arp_hdr));

			Packet newPacket((uchar *)pt, sizeof(struct arp_hdr) + sizeof(struct ether_hdr), p->getDevice());
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