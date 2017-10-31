#include "SocketInternal.h"
#include "IdentifyGenerator.h"

SocketInternal::SocketInternal()
{
	handle = IdentifyGenerator::getInstance()->getAndIncrement();
}

void SocketInternal::setBacklog(int backlog)
{
	this->backlogLimit = backlog;
}

void SocketInternal::setSkType(short skType)
{
	this->skType = skType;
}

void SocketInternal::setPort(ushort port)
{
	this->port = port;
}

void SocketInternal::enqueueRecvBuffer(SkBuffer *skBuffer)
{
	skRecvQueue.push_back(skBuffer);
}