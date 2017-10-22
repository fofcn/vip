#include "IcmpHandler.h"
#include "IpHandler.h"
#include "protocol/ProtocolHeader.h"

extern PacketChannelHandler *ipHandler;

IcmpHandler::IcmpHandler() : PacketChannelHandler("ICMP")
{
	prev = ipHandler;
}

IcmpHandler::~IcmpHandler()
{
	if (prev != nullptr) {
		delete prev;
		prev = nullptr;
	}
}

bool IcmpHandler::init()
{
	return true;
}

void IcmpHandler::channelRead(SkBuffer *skBuffer)
{
	skBuffer->resetTransportHeader();
	icmp_header *icmpHdr = (icmp_header *)skBuffer->skTransportHeader();
	std::cout << "icmp protocol" << std::endl;
	
	if (icmpHdr->type == ECHO_REQUEST)
	{
		write(skBuffer);
	}
}

void IcmpHandler::write(SkBuffer *skBuffer)
{
	icmp_header *old = (icmp_header *)skBuffer->skTransportHeader();

	SkBuffer newBuffer(skBuffer->skDevice());
	newBuffer.setProtocol(ICMP);
	newBuffer.skAddr(skBuffer->skDstAddr(), skBuffer->skSrcAddr());
	int totalLen = skBuffer->skLen() + sizeof(struct icmp_hdr) + sizeof(struct ip_hdr) + ETH_ALEN;
	newBuffer.allocBuffer(totalLen);

	newBuffer.reserve(sizeof(struct ip_hdr) + ETH_ALEN);
	skBuffer->resetTransportHeader();

	icmp_header *icmpReply = (icmp_header *)skBuffer->skTransportHeader();
	icmpReply->type = ECHO_REPLY;
	icmpReply->code = 0;
	icmpReply->check_sum = 0;
	icmpReply->id = old->id;
	icmpReply->seq_num = old->seq_num;


	prev->write(&newBuffer);
}
