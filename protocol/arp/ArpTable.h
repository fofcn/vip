#ifndef VIP_ARPTABLE_H_
#define VIP_ARPTABLE_H_

#include <iostream>
#include <map>
#include "Types.h"
#include "protocol/ProtocolHeader.h"

struct arp_tbl
{
	uchar mac[MAC_LEN];
};

typedef struct arp_tbl arpTbl;

class ArpTable
{
public:
	static ArpTable *getInstance();

	arpTbl *get(uint ip);
	void add(uint ip, arpTbl *tbl);
private:
	ArpTable();
private:
	std::map<uint, arpTbl*> table;
	static ArpTable *instance;
};

#endif
