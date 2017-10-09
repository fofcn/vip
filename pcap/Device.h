//
// Created by jiquanxi on 17-9-20.
//

#ifndef VIP_DEVICE_H
#define VIP_DEVICE_H

class Device
{
public:
	/*开始抓包*/
	virtual void startCapture() = 0;
	/*停止抓包*/
	virtual void stopCapture() = 0;
	/*发送数据包*/
	virtual void send(void *p) = 0;
};

#endif //VIP_DEVICE_H
