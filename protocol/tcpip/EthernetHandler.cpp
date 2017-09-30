//
// Created by error on 2017/9/28.
//
#include <WinSock2.h>
#include "EthernetHandler.h"
#include "IpHandler.h"
#include "ArpHandler.h"

EthernetHandler::EthernetHandler(std::string name)
{
	this->name = name;
	ipHandler = new IpHandler();
	arpHandler = new ArpHandler();
}

EthernetHandler::~EthernetHandler()
{
	if (ipHandler != nullptr)
	{
		delete ipHandler;
		ipHandler = nullptr;
	}
}

void EthernetHandler::channelRead(Packet *p)
{
	std::cout << "ethernet handler" << std::endl;
	ether_header *eth = (ether_header *)p->getP();

	ushort type = ntohs(eth->ether_type);

	switch (type)
	{
	case 0x0800:
		std::cout << "ip" << std::endl;
		this->next = ipHandler;
		break;
	case 0x0806:
		std::cout << "arp" << std::endl;
		break;
	defaut:
		std::cout << "Sorry, we will support this protocol soon." << std::endl;
	}

	printf("ethernet type: 0x%04x\n", type);
}

std::string EthernetHandler::getName()
{
	return name;
}

void EthernetHandler::write(Packet p)
{

}