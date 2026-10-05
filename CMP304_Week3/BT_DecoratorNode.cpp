#include "BT_DecoratorNode.h"
#include "AIConstructor_BT.h"

#include "BT_FallbackNode.h"
#include "BT_SequenceNode.h"
#include <iostream>



void BT_DecoratorNode::Think()
{
	ActionStatus _currentStatus = GetStatus();
	if (_currentStatus == ActionStatus::ACTION_IDLE)
	{
		Start();

	
		
	}
	else if (_currentStatus == ActionStatus::ACTION_RUNNING)
	{
		
	}


	bool conditionsMet = true;
	for (AIConsiderationBase* c : nodeConsiderations)
	{
		bool ruleResult = c->Calculate(*actorBlackboard);

		if (!ruleResult)
		{
			conditionsMet = false;
		}
	}

	if (conditionsMet)
	{
		std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Decorator " << reasonerID << " Conditions met, returning SUCCESS " << std::endl;

		SetStatus(ActionStatus::ACTION_SUCCESS);
	}
	else
	{
		std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Decorator " << reasonerID << " Conditions NOT met, returning FAILURE " << std::endl;
		SetStatus(ActionStatus::ACTION_FAILURE);
	}

}


ActionStatus BT_DecoratorNode::Act()
{


	return GetStatus();
}

void BT_DecoratorNode::Reset()
{

	BT_ReasonerNode::Reset();
	selectedOption = nullptr;
	SetStatus(ActionStatus::ACTION_IDLE);
}

void BT_DecoratorNode::InitConsideration(AIConstructorBase& _constructor)
{
	AIConstructor_BT* btConstructor = static_cast<AIConstructor_BT*>(&_constructor);
	std::vector< std::shared_ptr<AIConsiderationBase> > _nodeConsideratrions = btConstructor->GetConsiderationsForKey(reasonerID);

	for (int j = 0; j < _nodeConsideratrions.size(); j++)
	{
		AIConsideration* c = new AIConsideration();
		c->Init(_nodeConsideratrions[j]->GetID(), _nodeConsideratrions[j]->GetRule());
		nodeConsiderations.push_back(c);
	}

}
















void BT_DecoratorNode::SetOptions(AIConstructorBase& _constructor)
{


	InitConsideration(_constructor);



	AIConstructor_BT* btConstructor = static_cast<AIConstructor_BT*>(&_constructor);

	std::vector<std::string> _reasonerOptions = btConstructor->GetOptionNamesForKey(reasonerID);

	std::vector<AIOptionDefinition> _options = _constructor.GetOptionVector(_reasonerOptions);

	for (int i = 0; i < _options.size(); i++)
	{
		// create a new Option, owned by this reasoner
		std::unique_ptr<AIOption> o = std::make_unique<AIOption>();


		//check if the Action is of type AIActionSubReasoner
		// if so, the Option should be constructed as a SubReasoner
		std::string on = typeid(*_constructor.actions[_options[i].actionName]).name();
		std::string::size_type n = on.find("AIActionSubReasoner");



		if (n != std::string::npos)
		{

			// if the action for the option is an AIActionSubReasoner, we need to create the SubReasoner, and add its options
			std::shared_ptr<AIActionSubReasoner> actionReasoner = std::make_shared< AIActionSubReasoner>();
			actionReasoner->Init(on, nullptr);


			AIActionSubReasoner* _optionAction = static_cast<AIActionSubReasoner*>(_constructor.actions[  _options[i].actionName ].get());

			BT_ReasonerNode* subReasoner = nullptr;
			
			if (_optionAction->GetReasonerType() == AIReasonerBase::NodeType::Decorator)
			{
				subReasoner = new BT_DecoratorNode();

			}
			else if (_optionAction->GetReasonerType() == AIReasonerBase::NodeType::Fallback)
			{
				subReasoner = new BT_FallbackNode();
			}
			else if (_optionAction->GetReasonerType() == AIReasonerBase::NodeType::Sequence)
			{
				subReasoner = new BT_SequenceNode();
			}
	
		
			
			std::string _optionName = _options[i].optionName;

			subReasoner->Init(_optionName, *actorBlackboard);

			std::vector<std::string> _suboptions = btConstructor->GetOptionNamesForKey(_optionName);

			// call the SetOptions function to add options associated with this option
			// will also crate and initalise any sub reasoner actions within them
			subReasoner->SetOptions(_constructor);

			actionReasoner->SetChildReasoner(*subReasoner);

			o->Init(_optionName, actionReasoner, _options[i].priority);

		}
		else
		{
			o->Init(_options[i].optionName, _constructor.actions[_options[i].actionName], _options[i].priority);

		}


		for (int j = 0; j < _options[i].considerationNames.size(); j++)
		{
			if (!_constructor.considerations.contains(_options[i].considerationNames[j]))
			{
				std::cout << "ERROR [AIReasonerBase] : No Consideration " << _options[i].considerationNames[j] << " found  - did you add the correct Consideration? " << std::endl;
				return;
			}

			// link the consideration created by the contructor to the Option
			o->AddOptionConsideration(_constructor.considerations[_options[i].considerationNames[j]]);
		}

		options.push_back(move(o));
	}

}


