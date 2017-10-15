#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_

#pragma once

#include "Types.h"

class SkBuffer
{
private:
	//链路层头
	uchar *macHeader;
	//网络层头
	uchar *networkHeader;
	//传输层头
	uchar *transportHeader;

	uchar *data;
};

#endif
