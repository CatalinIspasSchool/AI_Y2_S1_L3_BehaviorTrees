#include "AIBrainBlackboard.h"

bool AIBrainBlackboard::Init(AIActorBase& _context)
{
	actorContext = &_context;
	return true;
}