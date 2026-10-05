#pragma once
#include "../AI_Framework/framework.h"

/*
BT_ReasonerNode is an implementaiton of a Reasoner, which is the parent type for all Selector Nodes in the Behaviour Tree
*/
class BT_ReasonerNode :
    public AIReasonerBase
{
public:
	bool Init(std::string _id, AIBrainBlackboardBase& _context) override;
	ActionStatus GetStatus();
	void SetStatus(ActionStatus _status);
	void Start();
	void Reset() override;
	void SetOptions(AIConstructorBase& _constructor) override;
protected:
	ActionStatus nodeStatus;
};

