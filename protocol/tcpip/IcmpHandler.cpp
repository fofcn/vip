#include "IcmpHandler.h"
#include "IpHandler.h"

IcmpHandler::IcmpHandler() : PacketChannelHandler("ICMP")
{
	next = new IpHandler();
}

void IcmpHandler::channelRead(Packet *p)
{
	icmp_header *icmpHdr = p->getIcmpHeader();

}

void IcmpHandler::write(Packet p)
{
	next->write(p);
}
