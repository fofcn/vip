#ifndef VIP_SERVERSOCKET_H_
#define VIP_SERVERSOCKET_H_

#include "Socket.h"

class ServerSocket
{
public:
	ServerSocket(int port);
	ServerSocket(int port, int backlog);
	ServerSocket(int port, int backlog, int ip);

	Socket accept();

	void close();
private:
	int port;
	int backlog;
};

#endif