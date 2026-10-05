#pragma once
#include "BT_ReasonerNode.h"
class BT_DecoratorNode :
    public BT_ReasonerNode
{
public:
  
    void Think() override;
    ActionStatus Act() override;
    void Reset() override;
    void SetOptions(AIConstructorBase& _constructor) override;
    void AddConsideration(AIConsiderationBase* _consideration) { nodeConsiderations.push_back(_consideration); };
    void InitConsideration(AIConstructorBase& _constructor);

    std::vector<AIConsiderationBase*> nodeConsiderations;

};

