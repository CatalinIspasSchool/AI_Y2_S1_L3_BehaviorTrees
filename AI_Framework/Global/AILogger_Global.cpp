#include "AILogger_Global.h"
#include <iostream>

AILogger_Global* AILogger_Global::instancePointer = nullptr;

AILogger_Global* AILogger_Global::getInstance()
{

	if (instancePointer == nullptr)
	{
		instancePointer = new AILogger_Global();
	}

	return(instancePointer);
}

void AILogger_Global::LogError(std::string _logText)
{
	std::cout << "*** AI ERROR *** : " << _logText << std::endl;
}

void AILogger_Global::LogWarning(std::string _logText)
{
	std::cout << "* AI WARNING * : " << _logText << std::endl;
}

void AILogger_Global::LogMessage(std::string _logText)
{
	std::cout << "* AI LOG MESSAGE * : " << _logText << std::endl;
}