
#include <WinSock2.h>
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"

ArpHandler::ArpHandler() : PacketChannelHandler("ARP")
{

}

void ArpHandler::channelRead(Packet *p)
{
	p->moveToIpStart();

	arp_header *arpHdr = (arp_header *)p->getP();
	std::cout << "arp operation code: " << ntohs(arpHdr->op_code) << std::endl;
}

void ArpHandler::write(Packet p)
{

}