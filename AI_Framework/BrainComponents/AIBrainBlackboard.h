
#pragma once
#include "../AIBase/AIBrainBlackboardBase.h"

/*
CMP304/MAT501 AI Framework (2025)
*/


class AIBrainBlackboard :
    public AIBrainBlackboardBase
{
public:
    bool Init(AIActorBase& _context) override;
};

