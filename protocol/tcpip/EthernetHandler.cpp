//
// Created by error on 2017/9/28.
//
#include <WinSock2.h>
#include "EthernetHandler.h"
#include "IpHandler.h"
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "protocol/arp/ArpTable.h"
#include "protocol/arp/ArpHold.h"

PacketChannelHandler *ipHandler = new IpHandler();
PacketChannelHandler *arpHandler = new ArpHandler();

extern uchar etherBroadcastAddr[];

EthernetHandler::EthernetHandler() : PacketChannelHandler("Ethernet")
{
}

EthernetHandler::~EthernetHandler()
{
	if (ipHandler != nullptr)
	{
		delete ipHandler;
		ipHandler = nullptr;
	}

	if (arpHandler != nullptr)
	{
		delete arpHandler;
		arpHandler = nullptr;
	}
}

bool EthernetHandler::init()
{
	return true;
}

void EthernetHandler::channelRead(SkBuffer *skBuffer)
{
	skBuffer->resetMacHeader();
	skBuffer->pull(ETH_ALEN);

	ether_header *ethHdr = (ether_header *)skBuffer->skMacHeader();
	ushort type = ntohs(ethHdr->ether_type);
	switch (type)
	{
	case IPV4:
		//std::cout << "ip" << std::endl;
		next = ipHandler;
		break;
	case ETHERNET_ARP:
		std::cout << "arp" << std::endl;
		next = arpHandler;
		break;
	defaut:
		std::cout << "Sorry, we will support this protocol soon." << std::endl;
	}

	//printf("ethernet type: 0x%04x\n", type);
}

void EthernetHandler::write(SkBuffer *skBuffer)
{
	SkBuffer *readySendSkBuffer = nullptr;
	uchar *targetMac = nullptr;
	uint targetIp = 0;
	uint srcIp = 0;
	if (skBuffer->skProtocol() == IPV4)
	{
		ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
		targetIp = ntohl(ipHdr->dst_addr);
		srcIp = ntohl(ipHdr->src_addr);
	}
	else if (skBuffer->skProtocol() == ETHERNET_ARP)
	{
		arp_header *arpHdr = (arp_header *)skBuffer->skNetworkHeader();
		targetIp = ntohl(arpHdr->target_ip);
		srcIp = ntohl(arpHdr->sender_ip);
	}
	
	//获取IP的MAC地址
	arpTbl *tbl = ArpTable::getInstance()->get(targetIp);
	if (tbl == nullptr)
	{
		//将SkBuffer添加到待发送队列
		ArpHold::getInstance()->hold(targetIp, skBuffer);
		//发送arp请求
		SkBuffer arpReq = arp.request(targetIp, srcIp, skBuffer->skDevice(), skBuffer->skDevice()->getMac(), nullptr);

		//skBuffer->skDevice()->send(&arpReq);
		readySendSkBuffer = &arpReq;
		targetMac = etherBroadcastAddr;
	}
	else
	{
		readySendSkBuffer = skBuffer;
		targetMac = tbl->mac;
	}
	
	readySendSkBuffer->push(ETH_ALEN);
	readySendSkBuffer->resetMacHeader();
	ether_header *eth = (ether_header *)readySendSkBuffer->skMacHeader();
	memcpy(eth->ether_dhost, targetMac, MAC_LEN);
	memcpy(eth->ether_shost, readySendSkBuffer->skDevice()->getMac(), MAC_LEN);
	eth->ether_type = htons(readySendSkBuffer->skProtocol());
	readySendSkBuffer->skDevice()->send(readySendSkBuffer);
	
}