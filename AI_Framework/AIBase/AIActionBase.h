
#ifndef AI_ACTION_BASE_H
#define AI_ACTION_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once

#include <string>
#include "AIBrainBlackboardBase.h"
#include "AIStatus.h"
#include <functional>

/*
AIActionBase holds data related to an action that can be performed by the AI Actor
*/
class AIActionBase
{
public:
	virtual bool Init(std::string _id, std::function<ActionStatus(AIBrainBlackboardBase&)> _action) =0;
	virtual ActionStatus PerformAction(AIBrainBlackboardBase& _context) ;
	virtual void Reset();
	virtual ~AIActionBase() = default;
protected:
	std::string actionID;
	
	
protected:
	std::function<ActionStatus(AIBrainBlackboardBase&) > action;
};


#endif //!AI_ACTION_BASE_H