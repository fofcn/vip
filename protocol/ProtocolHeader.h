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
	//ͷ������
	uchar hl : 4;
	//IP�汾��4
	uchar version : 4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	uint version : 4;
	uint ip_hl : 4;
#endif
	//��������,ѡ��������·����rfc1349��
	uchar tos;
	//�ܳ��ȣ�����header+data
	ushort tot_len;
	//��Ƭ����ı�ʶ
	ushort id;
	//see [rfc791]
	//��Ƭ���Ʊ�ʶ
	//1λ������λ��Ϊ0
	//2λ��DF 0=���ܷ�Ƭ��1=����Ƭ
	//3λ��MF 0=���һ����Ƭ�� 1=���и����Ƭ
	ushort flags : 3;
	//��Ƭƫ��
	ushort frag_off : 13;//��Ƭ

	//0��������
	//
	uchar ttl;
	//��һЭ��
#define ICMP (1)
	uchar protocol;
	//ͷ��У���
	ushort check_sum;
	//ԴIP��ַ
	uint src_addr;
	//Ŀ��IP��ַ
	uint dst_addr;
};

typedef struct ip_hdr ip_header;

struct tcp_hdr
{
	//Դ�˿ں�
	ushort src_port;
	//Ŀ�Ķ˿ں�
	ushort dst_port;
	//��һ���������
	//�����SYN����ΪISN
	//��һ������ΪISN+1
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
	//�豸����
	ushort hw_type;

	//IP or? Э������
	ushort proto_type;
	//�豸����
	uchar hw_size;
	//Э�鳤��
	uchar proto_size;
#define ARP_REQUEST (1)
#define ARP_REPLYL  (2)
	//������
	ushort op_code;
	//������MAC��ַ
	uchar sender_mac[MAC_LEN];
	//������IP
	uint sender_ip;
	//Ŀ��MAC op_codeΪ����ʱ��Ϊ0
	uchar target_mac[MAC_LEN];
	//Ŀ��IP
	uint target_ip;
};

typedef struct arp_hdr arp_header;

struct icmp_hdr
{
#define ECHO_REQUEST (8)
#define ECHO_REPLY (0)
	//��������
	uchar type;

	uchar code;
	//У���
	ushort check_sum;

	ushort id;

	ushort seq_num;

	uchar *data;
};

typedef struct icmp_hdr icmp_header;


#pragma pack()

#endif //VIP_PROTOCOLHEADER_H
