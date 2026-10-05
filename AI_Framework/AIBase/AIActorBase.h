
#ifndef AI_ACTOR_BASE_H
#define AI_ACTOR_BASE_H
#include <string>
#include "AIReasonerBase.h"
#include "AIConstructorBase.h"
#include "AIBrainBase.h"

/*
CMP304/MAT501 AI Framework (2025)
*/


/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
/*
AIActorBase represents an actor or entity in the game scene that uses AI to make decisions
*/
class AIActorBase
{
public:
	virtual bool Init(std::string _id, AIConstructorBase& _constructor) = 0;

	// called each frame or decision point to make and carry out a decision
	virtual void Update(float _dt);
	virtual void PreTransition();

	std::string GetActorID();

	// convenience functions for accessing the actor's blackboard and seperating from implementation

    template<typename T>
    void AddBBValue(std::string _key, T _value)
    {
        brain->GetBrainBlackboard()->AddNewValue<T>(_key, _value);
    }

    template<typename T>
    void EditBBValue(std::string _key, T _newValue)
    {
        brain->GetBrainBlackboard()->EditValue<T>(_key, _newValue);
    }

    template<typename T>
    void DeleteBBValue(std::string _key)
    {
        brain->GetBrainBlackboard()->DeleteValue<T>(_key);
    }

    template<typename T>
    T GetBBValue(std::string _key)
    {
        return brain->GetBrainBlackboard()->GetValue<T>(_key);
    }

    template<typename T>
    T GetAndDeleteBBValue(std::string _key)
    {
        return brain->GetBrainBlackboard()->GetAndDeleteValue<T>(_key);        
    }

    template<typename T>
    bool HasBBValue(std::string _key)
    {
        return brain->GetBrainBlackboard()->HasValue<T>(_key);

    }

	virtual ~AIActorBase() = default;



protected:
	std::string actorID;

	// Actor owns a brain
	std::unique_ptr<AIBrainBase> brain;
};

#endif // !AI_ACTOR_BASE_H