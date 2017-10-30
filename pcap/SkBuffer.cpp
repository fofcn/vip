#include "SkBuffer.h"

SkBuffer::SkBuffer(Device *dev) : SkBuffer(nullptr, 0, dev)
{
	
}

SkBuffer::SkBuffer(uchar *data, unsigned int len, Device *dev) : dev(dev)
{
	this->data = data;
	this->len = len;
	dataLen = len;
	head = data;
	macHeader = nullptr;
	networkHeader = nullptr;
	transportHeader = nullptr;
}
