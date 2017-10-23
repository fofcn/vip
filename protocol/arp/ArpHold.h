#ifndef VIP_ARPHOLD_H_
#define VIP_ARPHOLD_H_

#include <iostream>
#include <map>
#include "Types.h"
#include "ArpHoldBuffer.h"

class ArpHold
{
public:
	~ArpHold();

	static ArpHold *getInstance();

	/*���Ҵ����͵�buffer�б�*/
	ArpHoldBuffer *lookup(uint ip);
	/*��δȷ�ϵ�buffer���浽�б�*/
	void hold(uint ip, SkBuffer *skBuffer);
private:
	ArpHold();
private:
	std::vector<ArpHoldBuffer> holds;
	static ArpHold *instance;
};

#endif