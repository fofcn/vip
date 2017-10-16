#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_

#pragma once

#include "Types.h"

class SkBuffer
{
public:
	SkBuffer();
	SkBuffer(uchar *data, unsigned int len);
	/**����buffer*/
	void allocBuffer(unsigned int size);
	/**dataָ�����len����*/
	void reserve(unsigned int len);

	void pull(unsigned int len);

	void resetMacHeader();

	uchar *skMacHeader();
private:
	//��·��ͷ
	uchar *macHeader;
	//�����ͷ
	uchar *networkHeader;
	//�����ͷ
	uchar *transportHeader;

	//����
	uchar *data;
	//����ͷ
	uchar *head;
	//���ݴ�С
	unsigned int len;
};

#endif
