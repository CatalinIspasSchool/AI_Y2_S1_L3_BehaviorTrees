#include "BT_FallbackNode.h"


#include "BT_DecoratorNode.h"
#include "BT_SequenceNode.h"
#include "AIConstructor_BT.h"
#include <iostream>



/*
* Think should check of the conditions (if any) for this node are met, and set the status accordingly
*/
void BT_FallbackNode::Think()
{

	ActionStatus _currentStatus = GetStatus();
	if (_currentStatus == ActionStatus::ACTION_IDLE)
	{
		Start();
	}
	else if (_currentStatus == ActionStatus::ACTION_RUNNING)
	{


		if (options.size() == 0)
		{
			std::cout << "BT LOG - ERROR - Node  " << reasonerID << " has no child nodes " << std::endl;
		}
		else
		{
		

			// select the current running index, but check if any of the conditions are met
			selectedOption = options[runningOptionIndex].get();

			std::vector<std::shared_ptr<AIConsiderationBase>> conditionList = selectedOption->GetOptionConsiderations();


			bool conditionsMet = true;
			for (auto c : conditionList)
			{
				bool ruleResult = c->Calculate(*actorBlackboard);

				if (!ruleResult)
				{
					std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Fallback Node " << selectedOption->GetOptionID() << "  - Consideration " << c->GetID() << " was not TRUE " << std::endl;
					conditionsMet = false;
				}
			}

			if (!conditionsMet)
			{
				SetStatus(ActionStatus::ACTION_FAILURE);
			}

		}

	}


}


/*
* Act should maintin the status tracking of the child nodes and handle their reporting of sucess and failure
*/
ActionStatus BT_FallbackNode::Act()
{

	if (selectedOption != nullptr)
	{

		// run the action on the selected Node
		ActionStatus _actionResult = selectedOption->GetOptionAction()->PerformAction(*actorBlackboard);

		// if child node reports failure, move to next child if possible
		if (_actionResult == ActionStatus::ACTION_FAILURE)
		{
			std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Fallback Node " << reasonerID << " is moving to next option " << runningOptionIndex << " as failure of " << selectedOption->GetOptionID() << std::endl;
			runningOptionIndex++;
			if (runningOptionIndex >= options.size())
			{
				std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Fallback Node " << reasonerID << " Action has Failed " << std::endl;
				SetStatus(ActionStatus::ACTION_FAILURE);
			}
		}
		else if (_actionResult == ActionStatus::ACTION_SUCCESS)
		{
			// if child node has suceeded, this Fallback node has suceeded
			std::cout << "[" << actorBlackboard->GetActorContext()->GetActorID() << "] BT Log: Fallback Node Complete - Success " << std::endl;
			SetStatus(ActionStatus::ACTION_SUCCESS);
		}

	}

	return GetStatus();
}

void BT_FallbackNode::Reset()
{

	BT_ReasonerNode::Reset();
	runningOptionIndex = 0;
	selectedOption = nullptr;
	SetStatus(ActionStatus::ACTION_IDLE);
}
