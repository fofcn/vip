
#include <WinSock2.h>

#include "TcpHandler.h"
#include "protocol/ProtocolHeader.h"

TcpHandler::TcpHandler() : PacketChannelHandler("TCP")
{
}


TcpHandler::~TcpHandler()
{
}


void TcpHandler::channelRead(Packet *p)
{
	p->moveToTcpStart();

	tcp_header *hdr = (tcp_header *)p->getP();
	//std::cout << "Source port: " << ntohs(hdr->src_port) << ", destination port: " << ntohs(hdr->dst_port) << std::endl;
}

void TcpHandler::write(Packet *p)
{

}
