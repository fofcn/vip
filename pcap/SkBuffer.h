
#ifndef VIP_SKBUFFER_H_
#define VIP_SKBUFFER_H_


#include "Types.h"
#include "Device.h"

class SkBuffer
{
public:
	SkBuffer(Device *dev);
	SkBuffer(uchar *data, unsigned int len, Device *dev);
	/**分配buffer*/
	inline void allocBuffer(unsigned int size)
	{
		data = new uchar(size);
		head = data;
		len = size;
	}
	/**data指针后移len长度*/
	inline void reserve(unsigned int len)
	{
		data += len;
		this->len += len;
	}

	inline void pull(unsigned int len)
	{
		this->len -= len;
		data += len;
	}

	inline void push(unsigned int len)
	{
		this->len += len;
		data -= len;
	}

	inline void resetMacHeader()
	{
		macHeader = data;
	}

	inline uchar *skMacHeader()
	{
		return macHeader;
	}

	inline void resetNetworkHeader()
	{
		networkHeader = data;
	}


	inline uchar *skNetworkHeader()
	{
		return networkHeader;
	}

	inline void resetTransportHeader()
	{
		transportHeader = data;
	}

	inline uchar *skTransportHeader()
	{
		return transportHeader;
	}

	inline unsigned int skLen()
	{
		return len;
	}

	inline uchar *skData()
	{
		return data;
	}

	inline Device *skDevice()
	{
		return dev;
	}

	inline void skAddr(uint src, uint dst)
	{
		srcAddr = src;
		dstAddr = dst;
	}

	inline uint skSrcAddr()
	{
		return srcAddr;
	}

	inline uint skDstAddr()
	{
		return dstAddr;
	}

	inline void setProtocol(ushort protocol)
	{
		this->protocol = protocol;
	}

	inline ushort skProtocol()
	{
		return protocol;
	}
	
private:
	//链路层头
	uchar *macHeader;
	//网络层头
	uchar *networkHeader;
	//传输层头
	uchar *transportHeader;

	//数据
	uchar *data;
	//数据头
	uchar *head;
	//数据大小
	unsigned int len;

	//源地址
	uint srcAddr;
	//目标地址
	uint dstAddr;

	ushort protocol;

	Device *dev;
};

#endif
