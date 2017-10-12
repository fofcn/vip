//
// Created by error on 2017/9/28.
//

#include "Packet.h"

Packet::Packet(uchar *p, int size, Device *dev) : p(p), start(p), size(size),device(dev) 
{
	h = (union header *)p;
}

uchar *Packet::getP() 
{ 
	return p; 
}

Device *Packet::getDevice() 
{
	return device;
}

ip_header *Packet::getIpHeader()
{
	ip_header *ipHeader = h->ip;
	p += ipHeader->hl;
	return ipHeader;
}

ip_header *Packet::getOldIpHeader()
{
	return ipHeader;
}

icmp_header *Packet::getIcmpHeader()
{
	curSize = ipHeader->tot_len - ipHeader->hl;
	return h->icmp;
}

void Packet::moveEthLen() 
{ 
	p = p + sizeof(struct ether_hdr); 
}

void Packet::moveToTcpStart() 
{ 
	p = p + sizeof(struct ip_hdr); 
}

void Packet::write() 
{ 
	device->send(this); 
}

int Packet::getSize() 
{ 
	return size; 
}

int Packet::getCurSize()
{
	return curSize;
}

void Packet::setOldP(uchar *p)
{
	this->p = p;
}