#include "AIRandom_Global.h"
#include <stdlib.h>


AIRandom_Global* AIRandom_Global::instancePointer = nullptr;

AIRandom_Global* AIRandom_Global::getInstance()
{

	if (instancePointer == nullptr)
	{
		instancePointer = new AIRandom_Global();
	}

	return(instancePointer);
}



double AIRandom_Global::GetRandom01()
{
	return ((double)rand()) / RAND_MAX;
}

int AIRandom_Global::GetRandomValue(int _range)
{
	return rand() % _range;
}
double AIRandom_Global::GetRandomValue(float _range)
{
	return GetRandom01() * _range;
}