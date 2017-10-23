#ifndef VIP_ARPHOLD_H_
#define VIP_ARPHOLD_H_

#include <iostream>
#include <map>
#include "Types.h"
#include "ArpHoldBuffer.h"

class ArpHold
{
public:
	~ArpHold();

	static ArpHold *getInstance();

	/*查找待发送的buffer列表*/
	ArpHoldBuffer *lookup(uint ip);
	/*将未确认的buffer保存到列表*/
	void hold(uint ip, SkBuffer *skBuffer);
private:
	ArpHold();
private:
	std::vector<ArpHoldBuffer> holds;
	static ArpHold *instance;
};

#endif