#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_

#pragma once

#include "Types.h"
#include "Device.h"

class SkBuffer
{
public:
	SkBuffer(Device *dev);
	SkBuffer(uchar *data, unsigned int len, Device *dev);
	/**分配buffer*/
	inline void allocBuffer(unsigned int size);
	/**data指针后移len长度*/
	inline void reserve(unsigned int len);

	inline void pull(unsigned int len);
	inline void push(unsigned int len);

	inline void resetMacHeader();
	inline uchar *skMacHeader();

	inline void resetNetworkHeader();
	inline uchar *skNetworkHeader();

	inline void resetTransportHeader();
	inline uchar *skTransportHeader();

	inline unsigned int skLen();

	inline uchar *skData();
	
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

	Device *dev;
};

#endif
