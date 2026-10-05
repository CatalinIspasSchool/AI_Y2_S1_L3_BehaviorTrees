
#ifndef AI_CONSTRUCTOR_BASE_H
#define AI_CONSTRUCTOR_BASE_H


/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include "AIOptionBase.h"
#include "AIConsiderationBase.h"
#include "AIActionBase.h"


/*
* AIOptionDefinition used to hold the data used by to create an option. Used by Reasoner class to create a AIOptionBase during initialisation. 
*/
struct AIOptionDefinition
{
	std::string optionName;
	std::string actionName;
	std::vector<std::string> considerationNames;
	int priority=0;

public:
	void SetOptionName(std::string _optionName) {
		optionName = _optionName;
	}

	void SetActionName(std::string _action) {
		actionName = _action;
	}

	void AddConsiderationName(std::string _consideration) {
		considerationNames.push_back(_consideration);
	}

	void SetPriority(int _priority)
	{
		priority = _priority;
	}
};


/*
AIConstructorBase contains the data used to define how an UI should operate, through creation of Options, Considerations and Actions
*/
class AIConstructorBase
{
public:

	enum Method { DT, RBS, MCTS, BT, GA, GOAP };


	virtual bool Init() = 0;
	virtual void DefineActions() = 0;
	virtual void DefineConsiderations() = 0;
	virtual void DefineOptions() = 0;

	void AddOptionByName(std::string _optionName, std::string _actionName, int _priority = 0);
	void AddConsiderationByName(std::string _actionName, std::function<bool(AIBrainBlackboardBase&)> _function);
	void AddActionByName(std::string _actionName, std::function<ActionStatus(AIBrainBlackboardBase&)> _action);
	void AddOptionConsideration(std::string _optionName, std::string _considerationName);
	
	// tree based functions
	void AddTreeNodeOptionByName(std::string _treeNode, int _priority = 0);
	void AddOptionToTreeNode(std::string _treeNode, std::string _option);
	std::vector<std::string> GetOptionNamesForKey(std::string _subreasoner);

	void DefineAI();

	//functions to return option definitions - primarily used when AIReasoner's are obtaining possible options
	AIOptionDefinition GetOptionByName(std::string _optionName);
	std::vector<AIOptionDefinition>  GetOptionVector(std::vector<std::string> _selectedoptions);
	std::vector<AIOptionDefinition>  GetOptionVector();

	// AIConstructorBase will create and share ownership of actions and considerations (with AIOption)
	std::unordered_map<std::string, std::shared_ptr<AIActionBase> > actions;
	std::unordered_map<std::string, std::shared_ptr<AIConsiderationBase> > considerations;


	// definitions of an option to be used when building the Reasoner
	std::unordered_map<std::string, AIOptionDefinition > options;

	// for tree based methods or hierarchical methods, there will be sub reasoners and decorators
	std::multimap<std::string, std::string> subReasonerLinks;
	std::multimap<std::string, std::string> decoratorConditions;

	Method method;

};

#endif // !AI_CONSTRUCTOR_BASE_H