#include <WinSock2.h>

#include "IpHandler.h"
#include "TcpHandler.h"
#include "../ProtocolHeader.h"


IpHandler::IpHandler() : PacketChannelHandler("IP")
{
	tcpHandler = new TcpHandler();
}


IpHandler::~IpHandler()
{
	if (tcpHandler != nullptr)
	{
		delete tcpHandler;
		tcpHandler = nullptr;
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

void IpHandler::channelRead(Packet *p)
{
	std::cout << "Internet Protocol!" << std::endl;

	p->moveToIpStart();
	ip_header *ipHdr = (ip_header *)p->getP();
	switch(ipHdr->protocol)
	{
	case TCP:
		std::cout << "TCP protocol" << std::endl;
		this->next = tcpHandler;
		break;
	case ICMP:
		std::cout << "ICMP protocol" << std::endl;
		break;
	case UDP:
		std::cout << "UDP protocol" << std::endl;
		break;
	}


	print_ip(ntohl(ipHdr->src_addr));
	print_ip(ntohl(ipHdr->dst_addr));

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



void IpHandler::write(Packet p)
{

}
