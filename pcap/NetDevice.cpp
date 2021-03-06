#include "NetDevice.h"
#include "protocol/tcpip/EthernetHandler.h"
#include "pcap/SkBuffer.h"

extern PacketChannelHandler *ethHandler;

NetDevice::NetDevice(char *name) : name(name), pd(nullptr), initialized(false), stopped(false)
{
	pipeline = new DefaultPacketChannelPipeline();
	
	//for home
	//char testMac[] = { 0x94, 0xDE, 0x80, 0xFF, 0x39, 0x74 };

	//for outside
	char testMac[] = { 0x94, 0xDE, 0x80, 0xFF, 0x39, 0x74 };

	//for virtual card
	//char testMac[] = { 0x0A, 0x00, 0x27, 0x00, 0x00, 0x04 };
	for (int i = 0; i < MAC_LEN; i++)
	{
		mac[i] = testMac[i];
	}
}

NetDevice::~NetDevice()
{
	if (pipeline != nullptr)
	{
		delete pipeline;
		pipeline = nullptr;
	}
}

extern uchar etherBroadcastAddr[];
uchar routerMacAddr[] = { 0xb0, 0x95, 0x8e, 0xb0, 0x1a, 0xcb };
void NetDevice::startCapture()
{
	int status;
	bool ret = init();
	if (!ret)
	{
		std::cout << "Device initialized failed." << std::endl;
		return;
	}

	u_long ip = ntohl(inet_addr("192.168.2.220"));
	u_long routerIp = ntohl(inet_addr("192.168.2.1"));
	Arp arp;
	SkBuffer buf = arp.response(routerIp, ip, this, this->mac, routerMacAddr);
	buf.push(ETH_ALEN);
	buf.resetMacHeader();
	ether_header *eth = (ether_header *)buf.skMacHeader();
	memcpy(eth->ether_dhost, routerMacAddr, MAC_LEN);
	memcpy(eth->ether_shost, this->mac, MAC_LEN);
	eth->ether_type = htons(ETHERNET_ARP);
	this->send(&buf);
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
	SkBuffer *skBuffer = (SkBuffer *)arg;
	int status = pcap_sendpacket(pd, (u_char *)(skBuffer->skData()), skBuffer->skDataLen());

}

uchar *NetDevice::getMac()
{
	return mac;
}

void NetDevice::callback(u_char *arg, const struct pcap_pkthdr *pktHdr, const u_char *packet)
{
	NetDevice *pThis = (NetDevice *)arg;
	SkBuffer skBuffer((uchar *)packet, pktHdr->len, pThis);
	/*skBuffer.resetMacHeader();
	skBuffer.pull(ETH_ALEN);
	ether_header *ethHdr = (ether_header *)skBuffer.skMacHeader();
	ushort type = ntohs(ethHdr->ether_type);

	switch (type)
	{
	case IPV4:
		std::cout << "ip" << std::endl;
		break;
	case ETHERNET_ARP:
		std::cout << "arp" << std::endl;
		break;
	defaut:
		std::cout << "Sorry, we will support this protocol soon." << std::endl;
	}
	*/

	pThis->pipeline->fireChannelRead(&skBuffer);
}

bool NetDevice::init()
{
	if (initialized)
	{
		return true;
	}

	pipeline->addLast(ethHandler);

	if (!exists())
	{
		//return false;
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
	
	if(pcap_findalldevs(&devList, errBuf) != 0)
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