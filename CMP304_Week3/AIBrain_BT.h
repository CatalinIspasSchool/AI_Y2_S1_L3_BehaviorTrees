#pragma once
#include "../AI_Framework/framework.h"
class AIBrain_BT :
    public AIBrainBase
{
public:
    bool Init(AIConstructorBase& _constructor, AIActorBase& _actorContext) override;
    void Update() override;
};

