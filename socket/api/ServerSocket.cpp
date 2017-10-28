#include "ServerSocket.h"

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


}


Socket ServerSocket::accept()
{
	Socket s;
	return s;
}

void ServerSocket::close()
{

}