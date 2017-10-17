#include <WinSock2.h>

#include "IpHandler.h"
#include "TcpHandler.h"
#include "EthernetHandler.h"
#include "IcmpHandler.h"
#include "protocol/ProtocolHeader.h"

IpHandler::IpHandler() : PacketChannelHandler("IP")
{
	tcpHandler = new TcpHandler();
	icmpHandler = new IcmpHandler();
	prev = new EthernetHandler();
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
	//std::cout << "Internet Protocol!" << std::endl;

	skBuffer->resetNetworkHeader();
	ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
	skBuffer->pull(ipHdr->hl);

	switch(ipHdr->protocol)
	{
	case TCP:
		//std::cout << "TCP protocol" << std::endl;
		this->next = tcpHandler;
		break;
	case ICMP:
		//std::cout << "ICMP protocol" << std::endl;
		break;
	case UDP:
		//std::cout << "UDP protocol" << std::endl;
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
	ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
	
	ip_header newIpHdr;
	newIpHdr.version = 4;
	newIpHdr.hl = sizeof(newIpHdr);
	newIpHdr.tot_len = skBuffer->skLen();
	newIpHdr.tos = 0;
	newIpHdr.id = 1024;
	newIpHdr.flags = 0;
	newIpHdr.frag_off = 0;
	newIpHdr.ttl = 64;
	newIpHdr.protocol = ipHdr->protocol;
	newIpHdr.check_sum = 0;
	newIpHdr.src_addr = ipHdr->dst_addr;
	newIpHdr.dst_addr = ipHdr->src_addr;

	uchar *buf = (uchar *)malloc(p->getSize() + sizeof(struct ip_hdr));
	memcpy(buf, &newIpHdr, sizeof(ip_hdr));
	memcpy(buf + sizeof(ip_hdr), p->getP(), p->getSize());

	Packet newPacket(buf, sizeof(struct ip_hdr) + sizeof(icmp_hdr), p->getDevice());

	prev->write(&newPacket);
}
