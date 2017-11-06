#include <WinSock2.h>

#include "IpHandler.h"
#include "TcpHandler.h"
#include "EthernetHandler.h"
#include "IcmpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "ip/NetworkCardPool.h"
#include "protocol/arp/ArpTable.h"

PacketChannelHandler *tcpHandler = new TcpHandler();
PacketChannelHandler *icmpHandler = new IcmpHandler();

extern PacketChannelHandler *ethHandler;

int IpHandler::identification = 1;

IpHandler::IpHandler() : PacketChannelHandler("IP")
{
	prev = ethHandler;
}


IpHandler::~IpHandler()
{
	if (tcpHandler != nullptr)
	{
		delete tcpHandler;
		tcpHandler = nullptr;
	}

	if (icmpHandler != nullptr)
	{
		delete icmpHandler;
		icmpHandler = nullptr;
	}

	if (prev != nullptr)
	{
		delete prev;
		prev = nullptr;
	}
}

bool IpHandler::init()
{
	return true;
}

void print_ip(int ip)
{
	unsigned char bytes[4];
	bytes[0] = ip & 0xFF;
	bytes[1] = (ip >> 8) & 0xFF;
	bytes[2] = (ip >> 16) & 0xFF;
	bytes[3] = (ip >> 24) & 0xFF;
	printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);
}

void IpHandler::channelRead(SkBuffer *skBuffer)
{
	skBuffer->resetNetworkHeader();
	ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
	skBuffer->pull(ipHdr->hl * 4);

	skBuffer->skAddr(ipHdr->src_addr, ipHdr->dst_addr);

	ipHdr->dst_addr = ntohl(ipHdr->dst_addr);
	ipHdr->src_addr = ntohl(ipHdr->src_addr);

	//过滤非IP池数据包
	if (!NetworkCardPool::getInstance()->contains(ipHdr->dst_addr))
	{
		next = nullptr;
		return;
	}

	//将MAC地址添加到路由表
	if (ArpTable::getInstance()->get(ipHdr->src_addr))
	{
		ether_header *ethHdr = (ether_header *)skBuffer->skMacHeader();
		arpTbl *newTbl = (arp_tbl *)malloc(sizeof(struct arp_tbl));
		memcpy(newTbl->mac, ethHdr->ether_shost, MAC_LEN);
		ArpTable::getInstance()->add(ipHdr->src_addr, newTbl);
	}

	switch(ipHdr->protocol)
	{
	case TCP_V4:
		this->next = tcpHandler;
		break;
	case ICMP:
		this->next = icmpHandler;
		break;
	case UDP:
		break;
	}


	//print_ip(ntohl(ipHdr->src_addr));
	//print_ip(ntohl(ipHdr->dst_addr));

	uchar protocol = ipHdr->protocol;

	int len = ntohs(ipHdr->tot_len);
	if (ipHdr->hl < 5)
	{
		fprintf(stdout, "bad-hlen %d \n", ipHdr->hl);
	}
	
	if (ipHdr->version != 4)
	{
		fprintf(stdout, "Unknown version %d\n", ipHdr->version);
		return;
	}

	//检查是否是第一个分片
	uint off = ntohs(ipHdr->frag_off);
	if ((off & 0x1fff) == 0)
	{
		/*fprintf(stdout, "IP: ");
		print_ip(ipHdr->src_addr);

		fprintf(stdout, "%d %d %d %d ",
			ipHdr->hl, ipHdr->version, len, off);
		print_ip(ipHdr->dst_addr);
		*/
	}
}

void IpHandler::write(SkBuffer *skBuffer)
{
	skBuffer->resetNetworkHeader();
	ip_header *newIpHdr = (ip_header *)skBuffer->skNetworkHeader();
	
	newIpHdr->version = 4;
	newIpHdr->hl = sizeof(struct ip_hdr) >> 2;
	newIpHdr->tot_len = htons(skBuffer->skDataLen());
	newIpHdr->tos = 0;
	newIpHdr->id = identification ++;
	newIpHdr->flags = 0;
	newIpHdr->frag_off = 0;
	newIpHdr->ttl = 64;
	newIpHdr->protocol = skBuffer->skProtocol();
	newIpHdr->check_sum = 0;
	newIpHdr->src_addr = skBuffer->skSrcAddr();
	newIpHdr->dst_addr = skBuffer->skDstAddr();

	newIpHdr->check_sum = IcmpHandler::checksum((ushort *)newIpHdr, newIpHdr->hl);
	skBuffer->setProtocol(IPV4);

	prev->write(skBuffer);
}
