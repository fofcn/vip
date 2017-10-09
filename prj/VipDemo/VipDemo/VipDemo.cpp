// VipDemo.cpp : Defines the entry point for the console application.
//

#include <Winsock2.h>

#include "handler/DefaultPacketChannelPipeline.h"
#include "pcap.h"
#include "protocol/ProtocolHeader.h"
#include "pcap/Device.h"
#include "protocol/tcpip/EthernetHandler.h"
#include "protocol/tcpip/IpHandler.h"

DefaultPacketChannelPipeline ethIpTcpPipeline;
DefaultPacketChannelPipeline ethArpTcpPipeline;

static void countme(u_char *user, const struct pcap_pkthdr *h, const u_char *packet);
extern void print_ip(int ip);


int main(int argc, char**  argv)
{
	EthernetHandler ethernetHandler;
	ethIpTcpPipeline.addLast(&ethernetHandler);

	pcap_if_t *alldevs;
	pcap_if_t *d;
	int exit_status = 0;
	char errbuf[PCAP_ERRBUF_SIZE + 1];

	int ret = pcap_findalldevs(&alldevs, errbuf);
	if (ret == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	int i = 0;
	for (d = alldevs; d; d = d->next, i++)
	{
		printf("%s    %s\n", d->name, d->description);
		if (i == 1)
		{
			//break;
		}
	}

	//笔记本测试机设备名
	//std::string devName = "\\Device\\NPF_{4B3493A3-4AEB-49E5-839D-134946B0CED4}";
	//台式测试机设备名
	std::string devName = "\\Device\\NPF_{668E95F4-C365-4BC4-A3A9-407FC352316D}";
	pcap_t *pd = pcap_create(devName.c_str(), errbuf);
	if (pd == nullptr)
	{
		printf("%s", errbuf);
		return -1;
	}
	int status;
	bpf_u_int32 localnet, netmask;
	if (pcap_lookupnet(devName.c_str(), &localnet, &netmask, errbuf) < 0) {
		localnet = 0;
		netmask = 0;
		printf("%s\n", errbuf);
	}

	print_ip(netmask);
	netmask = ntohl(netmask);
	
	status = pcap_activate(pd);

	/*if (pcap_compile(pd, &fcode, "ip host 192.168.2.138", 1, netmask) != 0)
		printf("%s\n", pcap_geterr(pd));

	if (pcap_setfilter(pd, &fcode) != 0)
		printf("%s", pcap_geterr(pd));
		*/

	int packet_count;
	for (;;)
	{
		packet_count = 0;
		status = pcap_dispatch(pd, -1, countme,
			(u_char *)&packet_count);
		if (status < 0)
			break;
		if (status != 0) {
			printf("%d packets seen, %d packets counted after pcap_dispatch returns\n",
				status, packet_count);
		}
	}
    return 0;
}

static void countme(u_char *user, const struct pcap_pkthdr *h, const u_char *packet)
{
	/*
	ether_header *eth = (ether_header *)packet;

	ushort type = ntohs(eth->ether_type);

	switch (type)
	{
	case 0x0800:
		break;
	case 0x0806:
		break;
	defaut:
		printf("Sorry, we will support this protocol soon.");
	}
	printf("ethernet type: 0x%04x\n", type);
	*/
	Packet p((uchar *)packet);
	ethIpTcpPipeline.fireChannelRead(&p);

	int *counterp = (int *)user;
	(*counterp)++;
}