#ifndef VIP_SOCKETBUFFER_H_
#define VIP_SOCKETBUFFER_H_

#include <vector>
#include "pcap/SkBuffer.h"

class SocketBuffer
{
public:
	
private:
	std::vector<SkBuffer> sockBuff;
};

#endif