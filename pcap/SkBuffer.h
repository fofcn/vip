#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_

#pragma once

#include "Types.h"

class SkBuffer
{
private:
	//��·��ͷ
	uchar *macHeader;
	//�����ͷ
	uchar *networkHeader;
	//�����ͷ
	uchar *transportHeader;

	uchar *data;
};

#endif
