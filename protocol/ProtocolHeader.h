//
// Created by jiquanxi on 17-9-21.
//

#ifndef VIP_PROTOCOLHEADER_H
#define VIP_PROTOCOLHEADER_H

#include "../Types.h"

#define MAC_LEN 6

#define IPV4 (0x0800)
#define ETHERNET_ARP (0x0806)

#define TCP 6
#define UDP 17

#pragma pack(push, 1)

struct ether_hdr
{
    uchar ether_dhost[6];
    uchar ether_shost[6];
    ushort ether_type;
};

typedef struct ether_hdr ether_header;

struct ip_hdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	//头部长度
	uchar hl : 4;
	//IP版本，4
	uchar version : 4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	uint version : 4;
	uint ip_hl : 4;
#endif
	//服务类型,选择传输最优路径【rfc1349】
	uchar tos;
	//总长度，包括header+data
	ushort tot_len;
	//分片重组的标识
	ushort id;
	//see [rfc791]
	//分片控制标识
	//1位：保留位，为0
	//2位：DF 0=可能分片，1=不分片
	//3位：MF 0=最后一个分片， 1=还有更多分片
	ushort flags : 3;
	//分片偏移
	ushort frag_off : 13;//分片

	//0，丢弃包
	//
	uchar ttl;
	//下一协议
#define ICMP (1)
	uchar protocol;
	//头部校验和
	ushort check_sum;
	//源IP地址
	uint src_addr;
	//目的IP地址
	uint dst_addr;
};

typedef struct ip_hdr ip_header;

struct tcp_hdr
{
	//源端口号
	ushort src_port;
	//目的端口号
	ushort dst_port;
	//第一个数据序号
	//如果是SYN，则为ISN
	//第一个数据为ISN+1
	uint seq_num;
	//
	uint ack_num;

	ushort data_off : 4;
	ushort reserved : 6;
	ushort ctl_bit : 6;

	ushort win;

	ushort check_sum;

	ushort urg_p;
};

typedef struct tcp_hdr tcp_header;

struct arp_hdr
{
#define HW_TYPE_ETH (1)
	//设备类型
	ushort hw_type;

	//IP or? 协议类型
	ushort proto_type;
	//设备长度
	uchar hw_size;
	//协议长度
	uchar proto_size;
#define ARP_REQUEST (1)
#define ARP_REPLYL  (2)
	//操作码
	ushort op_code;
	//请求者MAC地址
	uchar sender_mac[MAC_LEN];
	//请求者IP
	uint sender_ip;
	//目标MAC op_code为请求时，为0
	uchar target_mac[MAC_LEN];
	//目标IP
	uint target_ip;
};

typedef struct arp_hdr arp_header;

struct icmp_hdr
{
#define ECHO_REQUEST (8)
#define ECHO_REPLY (0)
	//请求类型
	uchar type;

	uchar code;
	//校验和
	ushort check_sum;

	ushort id;

	ushort seq_num;

	uchar *data;
};

typedef struct icmp_hdr icmp_header;


#pragma pack()

#endif //VIP_PROTOCOLHEADER_H
