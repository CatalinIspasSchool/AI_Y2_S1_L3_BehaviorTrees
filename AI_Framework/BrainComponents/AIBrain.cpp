#include "AIBrain.h"

#include "AIBrainBlackboard.h"


bool AIBrain::Init(AIConstructorBase* _constructor, AIActorBase* _actorContext)
{

	//brainReasoner = new AIReasoner();
	//brainBlackboard = _bb;

	brainBlackboard = new AIBrainBlackboard();
	brainBlackboard->Init(_actorContext);
	return true;
}

void AIBrain::Update()
{
	// call the reasoner
	brainReasoner->Update();

}