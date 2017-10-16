#include "SkBuffer.h"

SkBuffer::SkBuffer()
{
	data = nullptr;
	head = nullptr;
	macHeader = nullptr;
	networkHeader = nullptr;
	transportHeader = nullptr;
}

SkBuffer::SkBuffer(uchar *data, unsigned int len)
{
	this->data = data;
	this->len = len;
	head = data;
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

void SkBuffer::resetMacHeader()
{
	macHeader = data;
}

uchar *SkBuffer::skMacHeader()
{
	return macHeader;
}