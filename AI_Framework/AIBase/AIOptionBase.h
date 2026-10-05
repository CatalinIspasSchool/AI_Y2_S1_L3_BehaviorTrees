#ifndef AI_OPTION_BASE_H
#define AI_OPTION_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
#include <string>
#include "AIConsiderationBase.h"
#include <vector>
#include "AIActionBase.h"
#include <memory>

/*
* AIOptionBase represents one of the possible options a Reasoner can select from. Considerations can be used to determine if the option is valid for the current context. 
*/
class AIOptionBase
{
public:
	virtual bool Init(std::string, std::shared_ptr<AIActionBase>_action, int _priority = 0) = 0;
	void AddOptionConsideration(std::shared_ptr<AIConsiderationBase> _consideration);
	AIActionBase* GetOptionAction();
	std::vector<std::shared_ptr<AIConsiderationBase>> GetOptionConsiderations();
	std::string GetOptionID();
	int GetPriority();
	virtual ~AIOptionBase() = default;

protected:
	std::shared_ptr<AIActionBase> optionAction;
	std::vector<std::shared_ptr<AIConsiderationBase>> optionConsiderations;
	std::string optionID;
	int priority;
};



#endif //!AI_OPTION_BASE_H