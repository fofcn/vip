#ifndef VIP_TCPLISTENSTATE_H_
#define VIP_TCPLISTENSTATE_H_

#include "TcpState.h"

class TcpListenState : public TcpState
{
public:
	TcpListenState(SocketInternal *socket);
};

#endif