#include "IdentifyGenerator.h"

volatile int IdentifyGenerator::value = 1;

IdentifyGenerator::IdentifyGenerator()
{

}

int IdentifyGenerator::getAndIncrement()
{
	return value++;
}