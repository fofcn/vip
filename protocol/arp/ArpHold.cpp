#include "ArpHold.h"

ArpHold *ArpHold::instance = nullptr;

ArpHold::ArpHold()
{
}

ArpHold::~ArpHold()
{

}

ArpHold *ArpHold::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ArpHold();
	}
	return instance;
}

ArpHoldBuffer *ArpHold::lookup(uint ip)
{
	for (int i = 0; i < holds.size(); i++)
	{
		ArpHoldBuffer holdBuffer = holds[i];
		if (holdBuffer.holdIp() == ip)
		{
			return &holdBuffer;
		}
	}

	return nullptr;
}

void ArpHold::hold(uint ip, SkBuffer *skBuffer)
{
	ArpHoldBuffer *holdBuffer = lookup(ip);
	if (holdBuffer == nullptr)
	{
		ArpHoldBuffer newHoldBuffer;
		newHoldBuffer.enqueue(skBuffer);
		holds.push_back(newHoldBuffer);
	}
	else
	{
		holdBuffer->enqueue(skBuffer);
	}
}