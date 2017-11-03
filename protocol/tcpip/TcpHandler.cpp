
#include <WinSock2.h>

#include "TcpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "socket/internal/SocketInternal.h"
#include "socket/internal/SockInternalManager.h"

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
	skBuffer->resetTransportHeader();
	tcp_header *tcpHdr = (tcp_header *)skBuffer->skTransportHeader();
	tcpHdr->src_port = ntohs(tcpHdr->src_port);
	tcpHdr->dst_port = ntohs(tcpHdr->dst_port);

	//TODO TCP头部校验
	if (tcpHdr->syn)
	{
		std::cout << "Source port: " << (tcpHdr->src_port) << ", destination port: " << (tcpHdr->dst_port) << std::endl;

		//构造ack 回复
		SkBuffer ackResponse(skBuffer->skDevice());
		ackResponse.allocBuffer(sizeof(struct tcp_hdr) + sizeof(struct ip_hdr) + sizeof(struct ether_hdr));
		ackResponse.reserve(sizeof(struct ip_hdr) + sizeof(struct ether_hdr));
		ackResponse.put(sizeof(struct tcp_hdr));
		ackResponse.resetTransportHeader();
		tcp_header *tcpHdr = (tcp_header *)ackResponse.skTransportHeader();


	}
	//获取socket

	//首先根据端口查找socket
	ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
	//首先查找非listen socket
	SocketInternal *skInternal = SocketInternalManager::getInstance()->findConnSocketInternal(ipHdr->dst_addr, tcpHdr->dst_port, ipHdr->src_addr, tcpHdr->src_port);
	if (skInternal == nullptr)
	{
		//查找listen socket
		skInternal = SocketInternalManager::getInstance()->findListenSocketInternal(ipHdr->dst_addr, tcpHdr->dst_port);
		if (skInternal == nullptr)
		{
			//TODO 删除skBuffer
			return;
		}
	}

	//新建一个socketInternal
	SocketInternal newConn;
	newConn.setListenSocket(skInternal);
	SocketInternalManager::getInstance()->addConnSocketInternal(newConn);

	skInternal->enqueueRecvBuffer(skBuffer);
}

void TcpHandler::write(SkBuffer *skBuffer)
{
	
}
