#ifndef AI_CONSIDERATION_H
#define AI_CONSIDERATION_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
#include "../AIBase/AIConsiderationBase.h"
class AIConsideration :
    public AIConsiderationBase
{
public:
    bool Init(std::string _id, std::function<bool(AIBrainBlackboardBase&)>_rule) override;
};

#endif // !AI_CONSIDERATION_H