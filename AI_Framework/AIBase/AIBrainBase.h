#pragma once
#ifndef AI_BRAIN_BASE_H
#define AI_BRAIN_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/

#include <memory>
#include "AIReasonerBase.h"
#include "AIBrainBlackboardBase.h"
#include "AIConstructorBase.h"

//forward reference
class AIActorBase;

/*
AIBrainBase represents an the brain of an Action, containing the information needed to make decisions (brainBlackboard) and the logic for making a decision (brainReasoner). 
*/
class AIBrainBase
{
public:
	virtual ~AIBrainBase();
	virtual bool Init(AIConstructorBase& _constructor, AIActorBase& _actorContext) = 0;
	virtual void Update() = 0;

	AIReasonerBase* GetReasoner();
	AIBrainBlackboardBase* GetBrainBlackboard();
protected:
	// brain owns a reasoner
	std::unique_ptr<AIReasonerBase> brainReasoner;
	
	//brain owns a blackboard
	std::unique_ptr<AIBrainBlackboardBase> brainBlackboard;
};

#endif // !AI_BRAIN_BASE_H