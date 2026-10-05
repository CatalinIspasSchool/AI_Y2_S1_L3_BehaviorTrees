#include "AIConstructorBase.h"
#include <iostream>
#include "../Considerations/AIConsideration.h"
#include "../Actions/AIAction.h"
#include "../Options/AIOption.h"
#include "../Actions/AIActionSubReasoner.h"


void AIConstructorBase::DefineAI()
{
	DefineActions();
	DefineConsiderations();
	DefineOptions();
}

std::vector< AIOptionDefinition> AIConstructorBase::GetOptionVector(std::vector<std::string> _selectedoptions)
{

	std::vector<AIOptionDefinition > _optionVector;

	for (const auto& optionID : _selectedoptions)
	{
		if (!options.contains(optionID))
		{
			std::cout << "ERROR Matching Options : returning empty vector" << std::endl;
			std::cout << "Option being added: " << optionID << std::endl;
			return _optionVector;
		}

	}
		

	// for all options in the request list, add from the unordered map
	for (const auto& optionID : _selectedoptions)
	{
		_optionVector.push_back(options[optionID]);
	}



	return _optionVector;
}


std::vector< AIOptionDefinition>  AIConstructorBase::GetOptionVector()
{

	std::vector<AIOptionDefinition> _optionVector;

	// for all options in the request list, add from the unordered map
	for (const auto option: options)
	{
		_optionVector.push_back(option.second);
	}

	return _optionVector;
}


AIOptionDefinition AIConstructorBase::GetOptionByName(std::string _optionName)
{

	if (!options.contains(_optionName))
	{
		std::cout << "ERROR [AIConstructorBase] : Matching Option  " << _optionName<<  std::endl;
	}

	return(options[_optionName]);
}


void AIConstructorBase::AddActionByName(std::string _actionName, std::function<ActionStatus(AIBrainBlackboardBase&)> _function)
{

	//Define an action, and init with the function which will be called when the action is selected
	auto _action = std::make_shared<AIAction>();
	_action->Init(_actionName, _function);
	actions.insert({ _actionName, _action });
}

void AIConstructorBase::AddConsiderationByName(std::string _actionName, std::function<bool(AIBrainBlackboardBase&)> _function)
{

	//Define an action, and init with the function which will be called when the action is selected
	auto _consideration = std::make_shared<AIConsideration>();
	_consideration->Init(_actionName, _function);
	considerations.insert({ _actionName, _consideration });
}

void AIConstructorBase::AddOptionByName(std::string _optionName, std::string _actionName, int _priority)
{
	// create an option for action
	AIOptionDefinition _option = AIOptionDefinition();
	_option.SetOptionName(_optionName);
	_option.SetActionName(_actionName);
	_option.SetPriority(_priority);
	options.insert({ _optionName, _option });
}

void AIConstructorBase::AddOptionConsideration(std::string _optionName, std::string _considerationName)
{
	// create a consideration for an option

	if (!options.contains(_optionName))
	{
		std::cout << "ERROR [AIConstructorBase] : Matching Option  " << _optionName << std::endl;
	}

	options[_optionName].AddConsiderationName(_considerationName);
}


void AIConstructorBase::AddTreeNodeOptionByName(std::string _nodeName, int _priority)
{

	/// create the Action - a SubReasoner Actions
	std::shared_ptr<AIActionBase> _subReasoner = std::make_shared<AIActionSubReasoner>();

	_subReasoner->Init(_nodeName, nullptr);
	actions.insert({ _nodeName, _subReasoner });

	// create the option, and link to the Action
	AIOptionDefinition _option = AIOptionDefinition();
	_option.SetOptionName(_nodeName);
	_option.SetActionName(_nodeName);
	_option.SetPriority(_priority);
	options.insert({ _nodeName, _option });


}


void AIConstructorBase::AddOptionToTreeNode(std::string _treeNode, std::string _option)
{

	subReasonerLinks.insert({ _treeNode, _option });



}

std::vector<std::string> AIConstructorBase::GetOptionNamesForKey(std::string _subreasoner)
{

	std::vector<std::string> _matches;
	for (std::multimap<std::string, std::string>::iterator it = subReasonerLinks.begin(); it != subReasonerLinks.end(); ++it) {

		if (it->first == _subreasoner)
		{
			_matches.push_back(it->second);
		}
	}

	return _matches;

}

