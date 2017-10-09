
#include <WinSock2.h>
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "ip/NetworkCardPool.h"

ArpHandler::ArpHandler() : PacketChannelHandler("ARP")
{
}

void ArpHandler::channelRead(Packet *p)
{
	p->moveToIpStart();

	arp_header *arpHdr = (arp_header *)p->getP();
	std::cout << "arp operation code: " << ntohs(arpHdr->op_code) << std::endl;
	//������̫�����ͷ���
	if (ntohs(arpHdr->hw_type) != HW_TYPE_ETH)
	{
		return;
	}

	//ARP����ʱ���ж��Ƿ���ڸ�IP
	if (ntohs(arpHdr->proto_type) == ARP_REQUEST)
	{
		if (NetworkCardPool::getInstance()->contains(ntohl(arpHdr->target_ip)))
		{
			//����ARP��Ӧ
			arp_header arp;
			arp.hw_type = htons(HW_TYPE_ETH);
			arp.hw_size = MAC_LEN;
			arp.proto_type = htons(IPV4);
			arp.proto_size = 4;
			arp.op_code = htons(ARP_REPLYL);
			arp.sender_ip = arpHdr->target_ip;
			strcpy((char *)arp.sender_mac, "");//TODO MAC��ַ
			arp.target_ip = arpHdr->target_ip;
			strcpy((char *)arp.target_mac, (char *)arpHdr->target_mac);

			ether_header eth;
			strcpy((char *)eth.ether_dhost, (char *)arpHdr->target_mac);
			strcpy((char *)eth.ether_shost, (char *)arpHdr->target_mac);
			eth.ether_type = htons(ETHERNET_ARP);

			char pt[sizeof(struct arp_hdr) + sizeof(struct ether_hdr)];

			memcpy(pt, &eth, sizeof(struct ether_hdr));

			char *pp = pt;
			pp += sizeof(struct ether_hdr);
			memcpy(pp, &arp, sizeof(arp_hdr));

			//p->write();
		}
	}
	else//ARP��Ӧ
	{
		//�鿴�Ƿ����·��
	}

}

void ArpHandler::write(Packet p)
{

}