#pragma once
#include "BT_ReasonerNode.h"


/*
* BT_FallbackNode is the implentation of a Fallback Selector node
* If one of the child nodes suceeed, this node will succeed
*/
class BT_FallbackNode :
    public BT_ReasonerNode
{
public:
    void Think() override;
    ActionStatus Act() override;
    void Reset() override;
private:
    int runningOptionIndex;
};

