

#ifndef AI_BLACKBOARD_GLOBAL_H
#define AI_BLACKBOARD_GLOBAL_H


//#include "../../MCTS/GameState.h"
#include <map>
#include <vector>
#include <string>
#include "AIMath_Global.h"
/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
class AIBlackboard_Global
{

public:

	AIBlackboard_Global(const AIBlackboard_Global& obj) = delete;

	static AIBlackboard_Global* getInstance();



	template<typename T>
	void AddNewValue(std::string name, T data)
	{
		GetMap<T>()[name] = data;
	}

	template<typename T>
	T GetValue(std::string name)
	{
		return GetMap<T>().at(name);
	}

	template<typename T>
	T GetAndDeleteValue(std::string name)
	{
		T _val = GetMap<T>().at(name);
		GetMap<T>().erase(name);
		return _val;
	}

	template<typename T>
	void EditValue(std::string name, T newValue)
	{
		GetMap<T>()[name] = newValue;
	}

	template<typename T>
	void DeleteValue(std::string name)
	{
		GetMap<T>().erase(name);
	}

	template<typename T>
	bool HasValue(std::string name)
	{
		return GetMap<T>().contains(name);

	}



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


private:

	static AIBlackboard_Global* instancePointer;
	AIBlackboard_Global() {}



};

#endif //!AI_BLACKBOARD_GLOBAL_H

