#include "BT_RandomNode.h"
#include "AIConstructor_BT.h"


#include "BT_DecoratorNode.h"
#include "BT_FallbackNode.h"
#include "BT_SequenceNode.h"
#include <iostream>


void BT_RandomNode::Think()
{

	//BONUS TASK TODO - complete logic

}


ActionStatus BT_RandomNode::Act()
{

	//BONUS TASK TODO - complete logic




	return GetStatus();
}

void BT_RandomNode::Reset()
{

	BT_ReasonerNode::Reset();
	runningOptionIndex = 0;
	selectedOption = nullptr;
	SetStatus(ActionStatus::ACTION_IDLE);
}

