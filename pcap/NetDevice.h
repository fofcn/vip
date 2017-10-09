#pragma once

#ifndef VIP_NETDEVICE_H_
#define VIP_NETDEVICE_H_

#include <iostream>
#include <pcap.h>
#include "Device.h"
#include "handler/DefaultPacketChannelPipeline.h"

class NetDevice : public Device
{
public:
	NetDevice(char *name);
	~NetDevice();
	
	
	virtual virtual void startCapture();
	virtual void stopCapture();
	virtual void send(void *arg);
private:
	/*��ʼ���豸*/
	bool init();

	/*�жϽӿ��Ƿ����*/
	bool exists();

	/*���������������豸*/
	bool createAndActive();

	/*ץȡ������ص�����*/
	static void callback(u_char *arg, const struct pcap_pkthdr *pktHdr, const u_char *packet);
private:
	/*�豸����*/
	char *name;

	/*�豸���*/
	pcap_t *pd;

	/*�Ƿ��Ѿ���ʼ��*/
	bool initialized;

	/*�Ƿ�ֹͣץ��*/
	bool stopped;

	/*��pipeline*/
	PacketChannelPipeline *pipeline;
};

#endif