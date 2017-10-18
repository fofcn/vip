#include "SkBuffer.h"

SkBuffer::SkBuffer(Device *dev)
{
	data = nullptr;
	head = nullptr;
	macHeader = nullptr;
	networkHeader = nullptr;
	transportHeader = nullptr;

	this->dev = dev;
}

SkBuffer::SkBuffer(uchar *data, unsigned int len, Device *dev)
{
	this->data = data;
	this->len = len;
	head = data;
	this->dev = dev;
}
