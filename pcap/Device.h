//
// Created by jiquanxi on 17-9-20.
//

#ifndef VIP_DEVICE_H
#define VIP_DEVICE_H

#include "Types.h"

class Device
{
public:
	/*��ʼץ��*/
	virtual void startCapture() = 0;
	/*ֹͣץ��*/
	virtual void stopCapture() = 0;
	/*�������ݰ�*/
	virtual void send(void *p) = 0;
	/*��ȡMAC��ַ*/
	virtual uchar *getMac() = 0;
};

#endif //VIP_DEVICE_H
