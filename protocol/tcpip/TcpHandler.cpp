
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

	//TODO TCPͷ��У��
	if (tcpHdr->syn)
	{
		std::cout << "Source port: " << (tcpHdr->src_port) << ", destination port: " << (tcpHdr->dst_port) << std::endl;

		//����ack �ظ�
		SkBuffer ackResponse(skBuffer->skDevice());
		ackResponse.allocBuffer(sizeof(struct tcp_hdr) + sizeof(struct ip_hdr) + sizeof(struct ether_hdr));
		ackResponse.reserve(sizeof(struct ip_hdr) + sizeof(struct ether_hdr));
		ackResponse.put(sizeof(struct tcp_hdr));
		ackResponse.resetTransportHeader();
		tcp_header *tcpHdr = (tcp_header *)ackResponse.skTransportHeader();


	}
	//��ȡsocket
	SocketInternal *skInternal = SocketInternalManager::getInstance()->findSocketInternalByPort(tcpHdr->dst_port);
	if (skInternal == nullptr)
	{
		return;//�����ڣ�������
	}

	skInternal->enqueueRecvBuffer(skBuffer);
}

void TcpHandler::write(SkBuffer *skBuffer)
{
	
}
