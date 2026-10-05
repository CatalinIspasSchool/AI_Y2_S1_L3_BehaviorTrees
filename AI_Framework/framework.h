#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
/*
CMP304/MAT501 AI Framework (2025)
*/


#ifndef AI_FRAMEWORK_H
#define AI_FRAMEWORK_H

#include "AIBase/AIActorBase.h"
#include "AIBase/AIActionBase.h"
#include "AIBase/AIBrainBase.h"
#include "AIBase/AIBrainBlackboardBase.h"
#include "AIBase/AIConsiderationBase.h"
#include "AIBase/AIConstructorBase.h"
#include "AIBase/AIOptionBase.h"
#include "AIBase/AIReasonerBase.h"
#include "AIBase/AIStatus.h"
#include "Actions/AIAction.h"
#include "Actions/AIActionSubReasoner.h"
#include "BrainComponents/AIBrain.h"
#include "BrainComponents/AIBrainBlackboard.h"
#include "Considerations/AIConsideration.h"
#include "Global/AIBlackboard_Global.h"
#include "Global/AILogger_Global.h"
#include "Global/AIMath_Global.h"
#include "Global/AIRandom_Global.h"
#include "Options/AIOption.h"



#endif // !AI_FRAMEWORK_H