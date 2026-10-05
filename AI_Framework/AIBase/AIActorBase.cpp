#include "AIActorBase.h"
#include "AIBrainBase.h"


void AIActorBase::Update(float _dt)
{
	brain->Update();

}

void AIActorBase::PreTransition()
{

}

std::string AIActorBase::GetActorID()
{
	return actorID;
}