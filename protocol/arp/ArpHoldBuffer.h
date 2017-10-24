#ifndef VIP_ARPHOLDBUFFER_H_
#define VIP_ARPHOLDBUFFER_H_

#include <queue>
#include "pcap/SkBuffer.h"

class ArpHoldBuffer
{
public:
	ArpHoldBuffer();
	ArpHoldBuffer(uint ip);
	uint holdIp();
	void enqueue(SkBuffer *skBuffer);
	SkBuffer *pop();
private:
	std::queue<SkBuffer *> bufferQueue;
	uint ip;
};

#endif