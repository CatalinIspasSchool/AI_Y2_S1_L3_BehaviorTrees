#include "AIOption.h"

bool AIOption::Init(std::string _id, std::shared_ptr<AIActionBase>_action, int _priority )
{
	optionID = _id;
	optionAction = _action;
	priority = _priority;
	return true;
}

