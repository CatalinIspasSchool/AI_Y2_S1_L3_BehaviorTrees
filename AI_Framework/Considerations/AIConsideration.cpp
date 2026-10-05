#include "AIConsideration.h"

bool AIConsideration::Init(std::string _id, std::function<bool(AIBrainBlackboardBase&)> _rule)
{
	considerationID = _id;
	rule = _rule;

	return true;
}