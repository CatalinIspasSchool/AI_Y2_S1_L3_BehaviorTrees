#include "AIBrain_BT.h"
#include <iostream>
#include "AIConstructor_BT.h"
#include "BT_DecoratorNode.h"
#include "BT_FallbackNode.h"
#include "BT_SequenceNode.h"

void AIBrain_BT::Update()
{
	// call the reasoner
	ActionStatus _currentTreeStatus = brainReasoner->Update();

	if (_currentTreeStatus == ActionStatus::ACTION_SUCCESS)
	{
		std::cout << "BT Log: Behaviour Tree Success, Resetting" << std::endl;
		brainReasoner->Reset();
	}
	else if (_currentTreeStatus == ActionStatus::ACTION_FAILURE)
	{
		std::cout << "BT Log : Behaviour Tree Failed, Resetting" << std::endl;
		brainReasoner->Reset();
	}
}


bool AIBrain_BT::Init(AIConstructorBase& _constructor, AIActorBase& _actorContext)
{
	brainBlackboard = std::make_unique<AIBrainBlackboard>();
	brainBlackboard->Init(_actorContext);

	AIConstructor_BT* _btConstructor = static_cast<AIConstructor_BT*>(&_constructor);

	if (_btConstructor->rootType == AIReasonerBase::NodeType::Decorator)
	{
		brainReasoner = std::make_unique<BT_DecoratorNode>();

	}
	else if (_btConstructor->rootType == AIReasonerBase::NodeType::Fallback)
	{
		brainReasoner = std::make_unique <BT_FallbackNode>();
	}
	else if (_btConstructor->rootType == AIReasonerBase::NodeType::Sequence)
	{
		brainReasoner = std::make_unique <BT_SequenceNode>();
	}


	// the reasoner must be called 'Root' is using the helper functions for construction
	brainReasoner->Init("Root", *brainBlackboard);
	brainReasoner->SetOptions(_constructor);

	return true;
}