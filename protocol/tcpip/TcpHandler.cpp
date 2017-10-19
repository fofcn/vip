
#include <WinSock2.h>

#include "TcpHandler.h"
#include "protocol/ProtocolHeader.h"

TcpHandler::TcpHandler() : PacketChannelHandler("TCP")
{
}


TcpHandler::~TcpHandler()
{
}

bool TcpHandler::init()
{
	return true;
}

void TcpHandler::channelRead(SkBuffer *skBuffer)
{
	tcp_header *hdr = (tcp_header *)skBuffer->skTransportHeader();
	//std::cout << "Source port: " << ntohs(hdr->src_port) << ", destination port: " << ntohs(hdr->dst_port) << std::endl;
}

void TcpHandler::write(SkBuffer *skBuffer)
{
	
}
