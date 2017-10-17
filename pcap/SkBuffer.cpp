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

void SkBuffer::allocBuffer(unsigned int size)
{
	data = new uchar(size);
	head = data;
	len = size;
}

void SkBuffer::reserve(unsigned int len)
{
	data += len;
	this->len += len;
}

void SkBuffer::pull(unsigned int len)
{
	this->len -= len;

	data += len;
}

void SkBuffer::push(unsigned int len)
{
	this->len += len;
	data -= len;
}

void SkBuffer::resetMacHeader()
{
	macHeader = data;
}

uchar *SkBuffer::skMacHeader()
{
	return macHeader;
}

void SkBuffer::resetNetworkHeader()
{
	networkHeader = data;
}

uchar *SkBuffer::skNetworkHeader()
{
	return networkHeader;
}

void SkBuffer::resetTransportHeader()
{
	transportHeader = data;
}

uchar *SkBuffer::skTransportHeader()
{
	return transportHeader;
}


unsigned int SkBuffer::skLen()
{
	return len;
}

uchar *SkBuffer::skData()
{
	return data;
}