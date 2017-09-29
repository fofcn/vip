//
// Created by jiquanxi on 17-9-21.
//

#ifndef VIP_PROTOCOLHEADER_H
#define VIP_PROTOCOLHEADER_H


#include "../Types.h"

struct ether_header
{
    uchar ether_dhost[6];
    uchar ether_shost[6];
    ushort ether_type;
};

typedef struct ether_header eth_header;

struct ip_hdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	uint ip_hl : 4;
	uint version : 4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	uint version : 4;
	uint ip_hl : 4;
#endif
	uchar tos;
	ushort tot_len;
	ushort id;
	ushort frag_off;

	uchar ttl;
	uchar protocol;
	ushort check_sum;

	uint saddr;
	uint daddr;
};

typedef struct ip_hdr ip_header;

#endif //VIP_PROTOCOLHEADER_H
