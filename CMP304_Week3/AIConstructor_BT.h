#pragma once
#include "../AI_Framework/framework.h"
class AIConstructor_BT :
    public AIConstructorBase
{
public:


	bool Init() override;
	void DefineActions() override;
	void DefineConsiderations() override;
	void DefineOptions() override;


	std::vector< std::shared_ptr<AIConsiderationBase>> GetConsiderationsForKey(std::string _condition);
	AIReasonerBase::NodeType rootType;

private:


	void AddControlNodeByName(std::string _subReasonerName, AIReasonerBase::NodeType _nodeType, int _priority = 0);
	void AddDecoratorConsideration(std::string _decorator, std::string _consideration);

	std::multimap<std::string, std::string> subReasonerLinks;
	std::multimap<std::string, std::string> decoratorConditions;


};

