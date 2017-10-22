#include "ArpTable.h"

ArpTable *ArpTable::instance = nullptr;

ArpTable::ArpTable()
{

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
	return table.find(ip)->second;
}
void ArpTable::add(uint ip, arpTbl *tbl)
{
	table.insert(std::pair<uint, arpTbl*>(ip, tbl));
}