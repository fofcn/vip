#ifndef VIP_ARPHOLDBUFFER_H_
#define VIP_ARPHOLDBUFFER_H_

#include <vector>
#include "pcap/SkBuffer.h"

class ArpHoldBuffer
{
public:
	ArpHoldBuffer();
	ArpHoldBuffer(uint ip);
	uint holdIp();
	void enqueue(SkBuffer *skBuffer);
private:
	std::vector<SkBuffer *> bufferQueue;
	uint ip;
};

#endif