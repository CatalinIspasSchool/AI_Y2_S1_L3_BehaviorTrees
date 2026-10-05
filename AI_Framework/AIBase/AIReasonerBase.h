#ifndef AI_REASONER_BASE_H
#define AI_REASONER_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/

#include <memory>
#include "AIBrainBlackboardBase.h"
#include <vector>
#include "AIOptionBase.h"
#include <string>
#include "AIConstructorBase.h"

#pragma once

/**
* AIReasonerBase is responsible for selecting one of the possible options that the Actor will perform.
*/
class AIReasonerBase
{
public:

	enum NodeType { Decorator, Sequence, Fallback, Random, Concurrent };

	virtual bool Init(std::string _id, AIBrainBlackboardBase& _context) = 0;
	virtual void SetOptions(AIConstructorBase& _constructor) ;
	void ClearOptions();
	//void AddOption(std::shared_ptr<AIOptionBase> _option);
	AIOptionBase* GetOptionByName(std::string _name);
	AIOptionBase* GetSelectedOption();

	ActionStatus Update();
	virtual void Reset();


	virtual ~AIReasonerBase() = default;
protected:
	void Sense();
	virtual void Think() = 0;
	virtual ActionStatus Act();
	

	// back reference to the blackboard 
	AIBrainBlackboardBase* actorBlackboard = nullptr; // brain's blackboard for the reasoner's context, e.g. Actor's Brain

	std::vector<std::unique_ptr<AIOptionBase>> options; // vector of all possible Options the reasoner can select from
	AIOptionBase* selectedOption = nullptr; // the selected option - set by Update()

	std::string reasonerID;
};

#endif // !AI_REASONER_BASE_H