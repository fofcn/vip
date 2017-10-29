#ifndef VIP_SERVERSOCKET_H_
#define VIP_SERVERSOCKET_H_

#include <iostream>
#include "Socket.h"

class ServerSocket
{
public:
	ServerSocket(std::string &ip, int port);
	ServerSocket(std::string &ip, int port, int backlog);

	Socket accept();

	void close();
private:
	int port;
	int backlog;
	std::string ip;
	int handle;
};

#endif