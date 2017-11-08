
#include <WinSock2.h>

#include "TcpHandler.h"
#include "protocol/ProtocolHeader.h"
#include "socket/internal/SocketInternal.h"
#include "socket/internal/SockInternalManager.h"
#include "protocol/enums/TcpState.h"

extern PacketChannelHandler *ipHandler;

TcpHandler::TcpHandler() : PacketChannelHandler("TCP")
{
	prev = ipHandler;
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

	
	//测试发送reset
	skInternal = nullptr;
	if(skInternal == nullptr)
	{
		//发送TCP reset
		return sendReset(skBuffer);
	}

	if (skInternal->getSkState() == TCP_ESTABLISHED)
	{
		//处理established状态的数据包
		//tcpRecvEstablished();
		return;
	}

	if (skInternal->getSkState() == TCP_LISTEN)
	{

	}
	
	if (tcpHdr->syn)
	{
		//新建一个socketInternal，放入半连接队列
		SocketInternal paritialSocket;
		paritialSocket.setSkState(TCP_SYN_RECV);
		paritialSocket.setListenSocket(skInternal);
		skInternal->addParitialConn(paritialSocket);
	}

	

	skInternal->enqueueRecvBuffer(skBuffer);
}

int tcpRevcStateProcess(SkBuffer *skBuffer, SocketInternal *skInternal)
{
	switch (skInternal->getSkState())
	{
	case TCP_CLOSE:
		//TODO释放数据包

		break;
	case TCP_LISTEN:
		break;
		default:
	}
}

//TODO 释放skbuffer空间
void TcpHandler::sendReset(SkBuffer *skBuffer)
{
	tcp_header *tcpHdr = (tcp_header *)skBuffer->skTransportHeader();

	if (tcpHdr->doff < sizeof(struct tcp_hdr))
	{
		return;
	}
	
	//如果当前为重置
	if (tcpHdr->rst)
	{
		return;
	}

	SkBuffer *newBuffer = new SkBuffer(skBuffer->skDevice());
	newBuffer->setProtocol(TCP_V4);
	newBuffer->allocBuffer(sizeof(struct tcp_hdr));
	newBuffer->reserve(sizeof(struct ether_hdr) + sizeof(struct ip_hdr));
	newBuffer->push(sizeof(struct ether_hdr) + sizeof(struct ip_hdr));
	newBuffer->resetTransportHeader();
	tcp_header *newTcpHdr = (tcp_header *)newBuffer->skTransportHeader();
	newTcpHdr->src_port = tcpHdr->dst_port;
	newTcpHdr->dst_port = tcpHdr->src_port;
	newTcpHdr->doff = sizeof(struct tcp_hdr) / 4;
	newTcpHdr->check_sum = 0;
	newTcpHdr->rst = 1;
	if (tcpHdr->ack)
	{
		newTcpHdr->seq_num = tcpHdr->ack_num;
	} 
	else
	{
		newTcpHdr->ack = 1;
		newTcpHdr->ack_num = htonl(ntohl(tcpHdr->seq_num) + tcpHdr->syn + 
		tcpHdr->fin + skBuffer->skDataLen() - (tcpHdr->doff << 2));
	}

	newBuffer->push(sizeof(struct ip_hdr));
	newBuffer->resetNetworkHeader();
	ip_header *newIpHdr = (ip_header *)newBuffer->skNetworkHeader();

	//设置ip头源地址和目的地址
	ip_header *ipHdr = (ip_header *)skBuffer->skNetworkHeader();
	newIpHdr->src_addr = htonl(ipHdr->dst_addr);
	newIpHdr->dst_addr = htonl(ipHdr->src_addr);

	prev->write(newBuffer);
}

void TcpHandler::write(SkBuffer *skBuffer)
{
	
}
