#include "ArpHoldBuffer.h"

ArpHoldBuffer::ArpHoldBuffer()
{
	ip = 0;
}

ArpHoldBuffer::ArpHoldBuffer(uint ip)
{
	this->ip = ip;
}

uint ArpHoldBuffer::holdIp()
{
	return ip;
}

void ArpHoldBuffer::enqueue(SkBuffer *skBuffer)
{
	bufferQueue.push_back(skBuffer);
}

SkBuffer *ArpHoldBuffer::pop()
{
	if (bufferQueue.empty())
	{
		return nullptr;
	}
	SkBuffer *buffer = bufferQueue.front();
	bufferQueue.erase(bufferQueue.begin());
	return buffer;
}