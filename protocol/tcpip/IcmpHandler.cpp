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
		skBuffer->pull(sizeof(struct icmp_hdr));
		write(skBuffer);
	}
}

void IcmpHandler::write(SkBuffer *oldSkBuffer)
{
	icmp_header *old = (icmp_header *)oldSkBuffer->skTransportHeader();

	SkBuffer *newBuffer = new SkBuffer(oldSkBuffer->skDevice());
	newBuffer->setProtocol(ICMP);
	newBuffer->skAddr(oldSkBuffer->skDstAddr(), oldSkBuffer->skSrcAddr());
	int totalLen = oldSkBuffer->skDataLen() + sizeof(struct icmp_hdr) + sizeof(struct ip_hdr) + ETH_ALEN;
	newBuffer->allocBuffer(totalLen);

	newBuffer->reserve(sizeof(struct ip_hdr) + ETH_ALEN);
	newBuffer->put(totalLen - (sizeof(struct ip_hdr) + ETH_ALEN));
	newBuffer->resetTransportHeader();

	icmp_header *icmpReply = (icmp_header *)newBuffer->skTransportHeader();
	icmpReply->type = ECHO_REPLY;
	icmpReply->code = 0;
	icmpReply->check_sum = 0;
	icmpReply->id = old->id;
	icmpReply->seq_num = old->seq_num;
	icmpReply->check_sum = checksum((ushort *)icmpReply, totalLen - (sizeof(struct ip_hdr) + ETH_ALEN));

	//增加数据
	//memcpy(icmpReply + sizeof(struct icmp_hdr), old + sizeof(icmp_hdr), oldSkBuffer->skDataLen());
	prev->write(newBuffer);
}

ushort IcmpHandler::checksum(ushort *buffer, int size)
{
	register int nleft = size;
	register ushort *w = buffer;
	register int sum = 0;
	ushort answer = 0;

	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}

	if (nleft == 1) {
		*(uchar *)(&answer) = *(uchar *)w;
		sum += answer;
	}

	/* add back carry outs from top 16 bits to low 16 bits */
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);			/* add carry */
	answer = ~sum;
	return answer;
}
