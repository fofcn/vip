#include "ServerSocket.h"

ServerSocket::ServerSocket(int port)
{
	ServerSocket(port, 0);
}

ServerSocket::ServerSocket(int port, int backlog)
{
	ServerSocket(port, backlog, 0);
}

ServerSocket::ServerSocket(int port, int backlog, int ip) : port(port), backlog(backlog)
{

}

Socket ServerSocket::accept()
{
	Socket s;
	return s;
}

void ServerSocket::close()
{

}