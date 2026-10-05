#pragma once
#include "BT_ReasonerNode.h"


/*
* BT_SequenceNode is the implentation of a Sequence Selector node
* If all of the child nodes suceeed in order, this node will succeed
*/
class BT_SequenceNode :
    public BT_ReasonerNode
{
public:
    void Think() override;
    ActionStatus Act() override;
    void Reset() override;
private:
    int runningOptionIndex;
};

