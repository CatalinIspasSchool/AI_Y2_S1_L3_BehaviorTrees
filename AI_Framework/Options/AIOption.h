
#ifndef AI_OPTION_H
#define AI_OPTION_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
#include "../AIBase/AIOptionBase.h"
class AIOption :
    public AIOptionBase
{
public:
    bool Init(std::string _id, std::shared_ptr<AIActionBase>_action, int _priority = 0) override;
};

#endif