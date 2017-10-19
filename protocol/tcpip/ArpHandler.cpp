
#include <WinSock2.h>
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "ip/NetworkCardPool.h"

extern void print_ip(int ip);

PacketChannelHandler *ethHandler = new EthernetHandler();

ArpHandler::ArpHandler() : PacketChannelHandler("ARP")
{
	prev = ethHandler;
}

bool ArpHandler::init()
{
	return true;
}

void ArpHandler::channelRead(SkBuffer *skBuffer)
{
	skBuffer->resetNetworkHeader();

	arp_header *arpHdr = (arp_header *)skBuffer->skNetworkHeader();
	std::cout << "arp operation code: " << ntohs(arpHdr->op_code) << std::endl;
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
			SkBuffer newBuffer(skBuffer->skDevice());
			newBuffer.allocBuffer(ETH_ALEN + sizeof(struct arp_hdr));
			newBuffer.reserve(ETH_ALEN);
			newBuffer.resetNetworkHeader();
			arp_header *arp = (arp_header *)newBuffer.skNetworkHeader();

			//构造ARP响应
			arp->hw_type = htons(HW_TYPE_ETH);
			arp->hw_size = MAC_LEN;
			arp->proto_type = htons(IPV4);
			arp->proto_size = 4;
			arp->op_code = htons(ARP_REPLYL);
			arp->sender_ip = arpHdr->target_ip;
			memcpy(arp->sender_mac, skBuffer->skDevice()->getMac(), MAC_LEN);
			arp->target_ip = arpHdr->target_ip;
			memcpy(arp->target_mac, arpHdr->sender_mac, MAC_LEN);

			write(&newBuffer);
		}
	}
	else//ARP响应
	{
		//查看是否存在路由
	}

}

void ArpHandler::write(SkBuffer *skBuffer)
{
	prev->write(skBuffer);
}