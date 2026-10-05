#include "AIAction.h"



bool AIAction::Init(std::string _id, std::function<ActionStatus(AIBrainBlackboardBase&)> _action)
{
	actionID = _id;
	action = _action;
	return true;
}