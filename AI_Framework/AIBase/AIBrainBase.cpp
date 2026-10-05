#include "AIBrainBase.h"


AIBrainBase::~AIBrainBase()
{

}


AIReasonerBase* AIBrainBase::GetReasoner()
{
	return brainReasoner.get();
}
AIBrainBlackboardBase* AIBrainBase::GetBrainBlackboard()
{
	return brainBlackboard.get();
}