
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

	//�½�socket
	SocketInternal newSkInternal;
	newSkInternal.setBacklog(backlog);
	newSkInternal.setSkType(SOCK_STREAM);
	newSkInternal.setPort((ushort)port);
	SocketInternalManager::getInstance()->addSocketInternal(newSkInternal);

	//�󶨶˿�

	//�����˿�


}


Socket ServerSocket::accept()
{
	Socket s;
	return s;
}

void ServerSocket::close()
{

}