#pragma once
#include "BT_ReasonerNode.h"
class BT_ConcurrentNode :
    public BT_ReasonerNode
{
public:
    void Think() override;
    ActionStatus Act() override;
    void Reset() override;

private:
    int runningOptionIndex;
};

