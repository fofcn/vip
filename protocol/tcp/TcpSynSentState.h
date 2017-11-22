#ifndef VIP_TCPSYNSENTSTATE_H_
#define VIP_TCPSYNSENTSTATE_H_

#include "TcpState.h"

class TcpSynSentState : public TcpState
{
public:
	TcpSynSentState(SocketInternal *socket);
};

#endif
