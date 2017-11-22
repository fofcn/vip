#include "SocketInternal.h"
#include "IdentifyGenerator.h"
#include "protocol/ProtocolHeader.h"

SocketInternal::SocketInternal()
{
	handle = IdentifyGenerator::getInstance()->getAndIncrement();
	listenSocket = nullptr;
}

void SocketInternal::setBacklog(int backlog)
{
	this->backlogLimit = backlog;
}

void SocketInternal::setSkType(short skType)
{
	this->skType = skType;
}

void SocketInternal::setSrcPort(ushort port)
{
	this->srcPort = port;
}

void SocketInternal::enqueueRecvBuffer(SkBuffer *skBuffer)
{
	skRecvQueue.push_back(skBuffer);
}


void SocketInternal::processTcpState(SkBuffer *skBuffer)
{
	tcp_header *tcpHdr = (tcp_header *)skBuffer->skTransportHeader();
	if (tcpHdr->syn)
	{
		tcpState->recvSyn(skBuffer);
	}
}