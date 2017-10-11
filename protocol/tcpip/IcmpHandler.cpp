#include "IcmpHandler.h"
#include "IpHandler.h"

IcmpHandler::IcmpHandler() : PacketChannelHandler("ICMP")
{
	prev = new IpHandler();
}

void IcmpHandler::channelRead(Packet *p)
{
	icmp_header *icmpHdr = p->getIcmpHeader();
	std::cout << "icmp protocol" << std::endl;
	
	if (icmpHdr->type == ECHO_REQUEST)
	{
		write(p);
	}
}

void IcmpHandler::write(Packet *p)
{
	icmp_header *icmpHdr = p->getIcmpHeader();
	icmp_header icmpReply;

	icmpReply.type = ECHO_REPLY;
	icmpReply.code = 0;
	icmpReply.check_sum = 0;
	icmpReply.id = icmpHdr->id;
	icmpReply.seq_num = icmpHdr->seq_num;

	const int bufSize = p->getCurSize();
	uchar buf[sizeof(struct icmp_hdr)];
	memcpy(buf, &icmpReply, sizeof(struct icmp_hdr));
	Packet newPacket(buf, sizeof(struct icmp_hdr), p->getDevice());
	prev->write(&newPacket);
}
