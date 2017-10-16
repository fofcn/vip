#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_

#pragma once

#include "Types.h"

class SkBuffer
{
public:
	SkBuffer();
	SkBuffer(uchar *data, unsigned int len);
	/**分配buffer*/
	void allocBuffer(unsigned int size);
	/**data指针后移len长度*/
	void reserve(unsigned int len);

	void pull(unsigned int len);

	void resetMacHeader();

	uchar *skMacHeader();
private:
	//链路层头
	uchar *macHeader;
	//网络层头
	uchar *networkHeader;
	//传输层头
	uchar *transportHeader;

	//数据
	uchar *data;
	//数据头
	uchar *head;
	//数据大小
	unsigned int len;
};

#endif
