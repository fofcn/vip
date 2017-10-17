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
	/**����buffer*/
	inline void allocBuffer(unsigned int size);
	/**dataָ�����len����*/
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

	Device *dev;
};

#endif
