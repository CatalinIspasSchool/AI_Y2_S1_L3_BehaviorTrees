
#ifndef AI_CONSIDERTAION_BASE_H
#define AI_CONSIDERTAION_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
#include <string>
#include "AIBrainBlackboardBase.h"
#include <functional>

/*
* AIConsiderationBase is a customisable logic rule that can be used in the process of selecting an option
*/
class AIConsiderationBase
{
public:
	virtual bool Init(std::string _id, std::function<bool(AIBrainBlackboardBase&)> _rule) = 0;
	bool Calculate(AIBrainBlackboardBase& _bb);
	std::string GetID();
	std::function<bool(AIBrainBlackboardBase&)> GetRule();
	virtual ~AIConsiderationBase() = default;

protected:
	std::function<bool(AIBrainBlackboardBase&)> rule;
	std::string considerationID;
};

#endif // !AI_CONSIDERTAION_BASE_H