#ifndef AI_ACTION_SUB_REASONER_H
#define AI_ACTION_SUB_REASONER_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
#include "../AIBase/AIActionBase.h"
#include "../AIBase/AIReasonerBase.h"
class AIActionSubReasoner :
    public AIActionBase
{
public:



    bool Init(std::string _id, std::function<ActionStatus(AIBrainBlackboardBase&)> _action) override;
    ActionStatus PerformAction(AIBrainBlackboardBase& _context) override;
    void Reset() override;
    void SetChildReasoner(AIReasonerBase& _child);
    AIReasonerBase* GetChildReasoner();
    void SetReasonerType(AIReasonerBase::NodeType _type);
    AIReasonerBase::NodeType GetReasonerType();
    
private:
    //reference to child   
    AIReasonerBase* childReasoner;
    AIReasonerBase::NodeType reasonerType;
};

#endif // !AI_ACTION_SUB_REASONER_H