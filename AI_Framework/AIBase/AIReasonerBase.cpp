#include "AIReasonerBase.h"
#include <iostream>
#include "../Options/AIOption.h"
#include "../Considerations/AIConsideration.h"
#include "../Actions/AIActionSubReasoner.h"

void AIReasonerBase::ClearOptions()
{
	options.clear();
}


AIOptionBase* AIReasonerBase::GetSelectedOption()
{
	// return a raw pointer, no ownership
	return selectedOption;
}

ActionStatus AIReasonerBase::Update()
{
	Sense();
	Think();
	return Act();

}

void AIReasonerBase::Sense()
{

}


ActionStatus AIReasonerBase::Act()
{

	if (selectedOption == nullptr)
	{
		std::cout << "WARNING: Null Selected option, no action taken. " << std::endl;
		return ActionStatus::ACTION_FAILURE;
	}

	return selectedOption->GetOptionAction()->PerformAction(*actorBlackboard);

}


void AIReasonerBase::Reset()
{

}

AIOptionBase* AIReasonerBase::GetOptionByName(std::string _name)
{
	for (int i=0;i<options.size();i++)
	{
		if (options[i]->GetOptionID() == _name)
		{
			return options[i].get();
		}
	}

	return nullptr;

}


/*
* SetOptions will create and store the Options has defined by the provided constructor
* Tree based reasoners (BT, DT) should override this function and add code using appropriate method classes to connect the reasoners and sub reasoners
*/
void AIReasonerBase::SetOptions(AIConstructorBase& _constructor)
{

	std::vector<AIOptionDefinition> _options = _constructor.GetOptionVector();

	for (int i = 0; i < _options.size(); i++)
	{
		// create a new Option, owned by this reasoner
		std::unique_ptr<AIOption> o = std::make_unique<AIOption>();

		if (!_constructor.actions.contains(_options[i].actionName))
		{
			std::cout << "ERROR [AIReasonerBase] : No Action " << _options[i].actionName << " found  - did you add the correct Action? " << std::endl;
			return;
		}

	

		o->Init(_options[i].optionName, _constructor.actions[_options[i].actionName], _options[i].priority);
		

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

		// move the ownership to the vector
		options.push_back(std::move(o));
	}

}