#include "ArpTable.h"

ArpTable *ArpTable::instance = nullptr;

ArpTable::ArpTable()
{

}

ArpTable::~ArpTable()
{
	//TODO É¾³ý±íÄÚ´æ
	for (std::map<uint, arpTbl*>::const_iterator it = table.begin(); it != table.end(); it++)
	{
		arpTbl *value = it->second;
		if (value != nullptr)
		{
			free(value);
			value = nullptr;
		}
	}
}

ArpTable *ArpTable::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ArpTable();
	}

	return instance;
}

arpTbl *ArpTable::get(uint ip)
{
	std::map<uint, arpTbl*>::const_iterator it = table.find(ip);
	if (it != table.end())
	{
		return it->second;
	}
	return nullptr;
}

void ArpTable::add(uint ip, arpTbl *tbl)
{
	table.insert(std::pair<uint, arpTbl*>(ip, tbl));
}

