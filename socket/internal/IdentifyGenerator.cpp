#include "IdentifyGenerator.h"

int IdentifyGenerator::value = 1;
IdentifyGenerator *IdentifyGenerator::instance = nullptr;

IdentifyGenerator *IdentifyGenerator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new IdentifyGenerator();
	}
	return instance;
}

IdentifyGenerator::IdentifyGenerator()
{

}

int IdentifyGenerator::getAndIncrement()
{
	return value++;
}