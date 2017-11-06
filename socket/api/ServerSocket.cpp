
#include <winsock2.h>
#include "ServerSocket.h"
#include "protocol/ProtocolHeader.h"
#include "socket/internal/SocketInternal.h"
#include "socket/internal/SockInternalManager.h"

ServerSocket::ServerSocket(std::string &ip,  int port)
{
	ServerSocket(ip, port, 0);
}

ServerSocket::ServerSocket(std::string &ip, int port, int backlog) : ip(ip), port(port)
{
	if (backlog <= 1)
	{
		backlog = 50;
	}

	int srcIp = ntohl(inet_addr(ip.c_str()));
	//新建socket
	SocketInternal newSkInternal;
	newSkInternal.setBacklog(backlog);
	newSkInternal.setSkType(SOCK_STREAM);
	newSkInternal.setSrcPort((ushort)port);
	newSkInternal.setSrcIp(srcIp);
	SocketInternalManager::getInstance()->addListenSocketInternal(newSkInternal);

	//绑定端口

	//监听端口


}


Socket ServerSocket::accept()
{
	Socket s;
	return s;
}

void ServerSocket::close()
{

}