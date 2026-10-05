#include "AIActionBase.h"



ActionStatus AIActionBase::PerformAction(AIBrainBlackboardBase& _context)
{

	if (action == nullptr)
	{
		std::cout << "WARNING [AIActionBase] : action funciton is not defined " << std::endl;
		return ActionStatus::ACTION_FAILURE;
	}

	return action(_context);
}

void AIActionBase::Reset()
{

}

