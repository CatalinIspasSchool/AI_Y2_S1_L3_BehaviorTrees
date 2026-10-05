#include "AIOptionBase.h"


AIActionBase* AIOptionBase::GetOptionAction()
{
	return(optionAction.get());
}

void AIOptionBase::AddOptionConsideration(std::shared_ptr<AIConsiderationBase>_consideration)
{
	optionConsiderations.push_back(_consideration);
}


std::vector<std::shared_ptr<AIConsiderationBase>> AIOptionBase::GetOptionConsiderations()
{
	return optionConsiderations;
}

std::string AIOptionBase::GetOptionID()
{
	return optionID;
}

int AIOptionBase::GetPriority()
{
	return priority;
}