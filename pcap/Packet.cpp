//
// Created by error on 2017/9/28.
//

#include "Packet.h"

Packet::Packet(uchar *p, Device *dev) : p(p), start(p), size(0),device(dev) 
{
}

uchar *Packet::getP() 
{ 
	return p; 
}

Device *Packet::getDevice() 
{
	return device;
}

void Packet::moveToIpStart() 
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
int Packet::getSize() { return size; }