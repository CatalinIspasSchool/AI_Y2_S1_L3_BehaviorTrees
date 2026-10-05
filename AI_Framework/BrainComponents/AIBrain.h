#ifndef AI_BRAIN_H
#define AI_BRAIN_H


#pragma once
#include "../AIBase/AIBrainBase.h"
class AIBrain :
    public AIBrainBase
{
public:
	 bool Init(AIConstructorBase& _constructor, AIActorBase& _actorContext) override;
	 void Update() override;
};

#endif //!AI_BRAIN_H