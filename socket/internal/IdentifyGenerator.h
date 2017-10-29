#ifndef VIP_IDENTIFYGENERATOR_H_
#define VIP_IDENTIFYGENERATOR_H_

#include "Types.h"

class IdentifyGenerator
{
public:
	static IdentifyGenerator *getInstance();
	int getAndIncrement();
private:
	IdentifyGenerator();
private:
	static int value;
	static IdentifyGenerator *instance;
};

#endif