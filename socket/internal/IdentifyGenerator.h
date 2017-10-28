#ifndef VIP_IDENTIFYGENERATOR_H_
#define VIP_IDENTIFYGENERATOR_H_

#include "Types.h"

class IdentifyGenerator
{
public:
	IdentifyGenerator();
	int getAndIncrement();
private:
	static volatile int value;
};

#endif