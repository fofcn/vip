//
// Created by error on 2017/9/28.
//
#include <WinSock2.h>
#include "EthernetHandler.h"
#include "IpHandler.h"
#include "ArpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "protocol/arp/ArpTable.h"
#include "protocol/arp/Arp.h"

PacketChannelHandler *ipHandler = new IpHandler();
PacketChannelHandler *arpHandler = new ArpHandler();

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
	skBuffer->push(ETH_ALEN);
	skBuffer->resetMacHeader();
	ether_header *eth = (ether_header *)skBuffer->skMacHeader();

	arp_header *arpHdr = (arp_header *)skBuffer->skNetworkHeader();

	uchar dstMac[MAC_LEN] = {0x00, 0xC2, 0xC6, 0x17, 0x63, 0x80};

	//获取IP的MAC地址
	arpTbl *tbl = ArpTable::getInstance()->get(arpHdr->target_ip);
	if (tbl == nullptr)
	{
		//发送arp请求
		Arp arp;
		//arp.request();
	}

	memcpy(eth->ether_dhost, dstMac, MAC_LEN);
	memcpy(eth->ether_shost, skBuffer->skDevice()->getMac(), MAC_LEN);
	eth->ether_type = htons(ETHERNET_ARP);

	skBuffer->skDevice()->send(skBuffer);
}