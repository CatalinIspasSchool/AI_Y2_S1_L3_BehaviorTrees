#include "BT_ReasonerNode.h"
#include <iostream>
#include "AIConstructor_BT.h"

#include "BT_DecoratorNode.h"
#include "BT_FallbackNode.h"
#include "BT_SequenceNode.h"
#include "BT_ConcurrentNode.h"
#include "BT_RandomNode.h"


bool BT_ReasonerNode::Init(std::string _id, AIBrainBlackboardBase& _context)
{
	actorBlackboard = &_context;
	reasonerID = _id;
	return true;
}

void BT_ReasonerNode::SetStatus(ActionStatus _status)
{
	nodeStatus = _status;
}

ActionStatus BT_ReasonerNode::GetStatus()
{
	return nodeStatus;
}

void BT_ReasonerNode::Start()
{
	std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Node " << reasonerID << " is starting " << std::endl;
	Reset();
	nodeStatus = ActionStatus::ACTION_RUNNING;
}

void BT_ReasonerNode::Reset()
{
	for (const auto& option : options)
	{
		option->GetOptionAction()->Reset();
	}
}


/*
SetOptions will create the options for this node based on the provided constructor
*/
void BT_ReasonerNode::SetOptions(AIConstructorBase& _constructor)
{
	AIConstructor_BT* btConstructor = static_cast<AIConstructor_BT*>(&_constructor);

	std::vector<std::string> _reasonerOptions = btConstructor->GetOptionNamesForKey(reasonerID);

	std::vector<AIOptionDefinition> _options = _constructor.GetOptionVector(_reasonerOptions);

	for (int i = 0; i < _options.size(); i++)
	{
		// create a new Option, owned by this reasoner
		std::unique_ptr<AIOption> o = std::make_unique<AIOption>();


		//if (_options[i].optionName ==L)
		//{
		//	std::cout << "ERROR  - did not find option for " << _reasonerOptions[i] << std::endl;
	//	}
	//	if (_options[i].actionName == NULL)
		//{
		//	std::cout << "ERROR  - did not find action for " << _reasonerOptions[i] << std::endl;
		//}


		//check if the Action is of type AIActionSubReasoner
		// if so, the Option should be constructed as a SubReasoner
		std::string on = typeid(*_constructor.actions[_options[i].actionName]).name();
		std::string::size_type n = on.find("AIActionSubReasoner");



		if (n != std::string::npos)
		{

			// if the action for the option is an AIActionSubReasoner, we need to create the SubReasoner, and add its options
			std::shared_ptr<AIActionSubReasoner> actionReasoner = std::make_shared< AIActionSubReasoner>();
			actionReasoner->Init(on, nullptr);


			AIActionSubReasoner* _optionAction = static_cast<AIActionSubReasoner*>(_constructor.actions[_options[i].actionName].get());

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
			else if (_optionAction->GetReasonerType() == AIReasonerBase::NodeType::Concurrent)
			{
				subReasoner = new BT_ConcurrentNode();
			}
			else if (_optionAction->GetReasonerType() == AIReasonerBase::NodeType::Random)
			{
				subReasoner = new BT_RandomNode();
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
