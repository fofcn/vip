#ifndef VIP_TCPCLOSE_STATE_H_
#define VIP_TCPCLOSE_STATE_H_

#include "TcpState.h"

class TcpCloseState : public TcpState
{
public:
	TcpCloseState(SocketInternal *socket);

	virtual void passiveOpen(SkBuffer *skBuffer);
	virtual void activeOpen(SkBuffer *skBuffer);
};

#endif