#include "IpHandler.h"
#include "../ProtocolHeader.h"


IpHandler::IpHandler(std::string name)
{
	this->name = name;
}


IpHandler::~IpHandler()
{
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
	ip_hdr *ipHdr = (ip_hdr *)p->getP();


	std::cout << "Source Address: " << ipHdr->saddr << ", Destination Address: " << ipHdr->daddr << std::endl;
	print_ip(ipHdr->saddr);
	print_ip(ipHdr->daddr);
}



void IpHandler::write(Packet p)
{

}
