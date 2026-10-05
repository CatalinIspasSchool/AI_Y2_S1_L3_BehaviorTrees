
#ifndef AI_BRAIN_BB_BASE_H
#define AI_BRAIN_BB_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


class AIActorBase;

#include<memory>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../Global/AIMath_Global.h"

#pragma once

/*
* AIBrainBlackboardBase holds all data reqiured for the Reasoner to make a decision, including the entity this reasoner belongs to
*/
class AIBrainBlackboardBase
{
public:

	virtual bool Init(AIActorBase& _context) = 0;

	AIActorBase* GetActorContext();

	template<typename T>
	void AddNewValue(std::string name, T data)
	{
		GetMap<T>()[name] = data;
	}

	template<typename T>
	T GetValue(std::string name)
	{
		if (!HasValue<T>(name))
		{
			std::cout << "WARNING [AIBrainBlackboard] : No such key " << name << std::endl;
		}

		return GetMap<T>().at(name);
	}

	template<typename T>
	T GetAndDeleteValue(std::string name)
	{

		if (!HasValue<T>(name))
		{
			std::cout << "WARNING [AIBrainBlackboard] : No such key " << name << std::endl;
		}

		T _val = GetMap<T>().at(name);
		GetMap<T>().erase(name);
		return _val;
	}

	template<typename T>
	void EditValue(std::string name, T newValue)
	{
		if (!HasValue<T>(name))
		{
			std::cout << "WARNING [AIBrainBlackboard] : No such key " << name << std::endl;
		}

		GetMap<T>()[name] = newValue;
	}

	template<typename T>
	void DeleteValue(std::string name)
	{
		if (!HasValue<T>(name))
		{
			std::cout << "WARNING [AIBrainBlackboard] : No such key " << name << std::endl;
		}

		GetMap<T>().erase(name);
	}

	template<typename T>
	bool HasValue(std::string name)
	{
		return GetMap<T>().contains(name);

	}


	virtual ~AIBrainBlackboardBase() = default;

protected:

		template<typename T>
	auto& GetMap() { return GetMap(static_cast<T*>(nullptr)); }

	// allowed map types are defined below
	std::map<std::string, float>& GetMap(float*) { return datamapFloat; }
	std::map<std::string, int>& GetMap(int*) { return datamapInt; }
	std::map<std::string, std::string>& GetMap(std::string*) { return datamapStr; }
	std::map<std::string, AIMath_Global::Vector2f>& GetMap(AIMath_Global::Vector2f*) { return datamapVec2f; }
	std::map<std::string, std::vector<int>>& GetMap(std::vector<int>*) { return datamapIntVec; }

	std::map<std::string, float> datamapFloat;
	std::map<std::string, AIMath_Global::Vector2f> datamapVec2f;
	std::map<std::string, std::vector<int> > datamapIntVec;
	std::map<std::string, std::string > datamapStr;
	std::map<std::string, int> datamapInt;

	//back pointer to the actor that the blackboard data releates to
	AIActorBase* actorContext = nullptr;
};

#endif //!AI_BRAIN_BB_BASE_H