//
// Created by jiquanxi on 17-9-21.
//

#ifndef VIP_PROTOCOLHEADER_H
#define VIP_PROTOCOLHEADER_H


#include "../Types.h"

#define ETHERTYPE_PUP 0x0200 
#define ETHERTYPE_IP 0x0800#define ETHERTYPE_ARP 0x0806
#define ETHERTYPE_REVARP 0x8035

struct ether_header
{
    uchar ether_dhost[6];
    uchar ether_shost[6];
    ushort ether_type;
};

typedef struct ether_header eth_header;

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN __LITTLE_ENDIAN
# endif
# ifndef BIG_ENDIAN
#  define BIG_ENDIAN    __BIG_ENDIAN
# endif
# ifndef PDP_ENDIAN
#  define PDP_ENDIAN    __PDP_ENDIAN
# endif
# ifndef BYTE_ORDER
#  define BYTE_ORDER    __BYTE_ORDER
# endif

struct ip_hdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	uint ip_hl : 4;
	uint version : 4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	uint version : 4;
	uint ip_hl : 4;
#else 
#error "Plase fix <bits/endian.h>"
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
