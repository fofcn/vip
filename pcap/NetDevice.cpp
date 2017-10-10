#include "NetDevice.h"
#include "protocol/tcpip/EthernetHandler.h"

NetDevice::NetDevice(char *name) : name(name), pd(nullptr), initialized(false), stopped(false)
{
	pipeline = new DefaultPacketChannelPipeline();
	
	char testMac[] = { 0x94, 0xDE, 0x80, 0xFF, 0x39, 0x74 };
	for (int i = 0; i < MAC_LEN; i++)
	{
		mac[i] = testMac[i];
	}

	PacketChannelHandler *ethernetHandler = new EthernetHandler();
	pipeline->addLast(ethernetHandler);
}

NetDevice::~NetDevice()
{
	if (pipeline != nullptr)
	{
		delete pipeline;
		pipeline = nullptr;
	}
}

void NetDevice::startCapture()
{
	int status;
	bool ret = init();
	if (!ret)
	{
		std::cout << "Device initialized failed." << std::endl;
		return;
	}

	while (!stopped)
	{
		status = pcap_dispatch(pd, 0, NetDevice::callback, (u_char *)this);
		if (status < 0)
		{
			stopped = true;
			break;
		}
		if (status != 0) 
		{
			
		}
	}
}

void NetDevice::stopCapture()
{
	stopped = true;
}

void NetDevice::send(void *arg)
{
	Packet *p = (Packet *)arg;
	int status = pcap_sendpacket(pd, (u_char *)(p->getP()), p->getSize());

}

char *NetDevice::getMac()
{
	return (char*)mac;
}

void NetDevice::callback(u_char *arg, const struct pcap_pkthdr *pktHdr, const u_char *packet)
{
	NetDevice *pThis = (NetDevice *)arg;
	Packet p((uchar *)packet, 0, pThis);
	pThis->pipeline->fireChannelRead(&p);
}

bool NetDevice::init()
{
	if (initialized)
	{
		return true;
	}

	if (!exists())
	{
		return false;
	}

	if (!createAndActive())
	{
		return false;
	}

	initialized = true;
	return true;
}

bool NetDevice::exists()
{
	pcap_if_t *devList = NULL;
	char errBuf[PCAP_ERRBUF_SIZE] = {0};
	
	if(pcap_findalldevs(&devList, errBuf) == -1)
	{
	    return false;
	}
	
	for(pcap_if_t *d = devList; d; d = d->next)
	{
	    if(strcmp(d->name, name) == 0)
	    {
	        return true;
	    }
	}

	return false;
}

bool NetDevice::createAndActive()
{
	char errBuf[PCAP_ERRBUF_SIZE] = { 0 };
	pd = pcap_create(name, errBuf);
	if (pd == nullptr)
	{
		std::cout << "Device create failed, reason:" << errBuf << std::endl;
		return false;
	}

	int status = pcap_activate(pd);
	if (status != 0)
	{
		std::cout << "Device activce failed" << std::endl;
		return false;
	}

	return true;
}