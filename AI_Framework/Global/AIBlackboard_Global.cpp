#include "AIBlackboard_Global.h"
#include <string>


AIBlackboard_Global* AIBlackboard_Global::instancePointer = nullptr;

AIBlackboard_Global* AIBlackboard_Global::getInstance()
{

	if (instancePointer == nullptr)
	{
		instancePointer = new AIBlackboard_Global();
	}

	return(instancePointer);
}

/*
void AIBlackboard_Global::AddNewValueInt(std::string name, int new_value)
{
	datamapInt[name] = new_value;
}

int AIBlackboard_Global::GetValueInt(std::string name)
{
	return datamapInt[name];
}

int AIBlackboard_Global::GetAndDeleteValueInt(std::string name)
{
	int returnValue = datamapInt[name];
	datamapInt.erase(name);
	return returnValue;
}

void AIBlackboard_Global::EditValueInt(std::string name, int new_value)
{
	datamapInt.erase(name);
	datamapInt[name] = new_value;
}

void AIBlackboard_Global::DeleteValueInt(std::string name)
{
	datamapInt.erase(name);
}
*/
/*

void AIBlackboard_Global::AddNewValueGameState(std::string name, GameState new_value)
{
	datamapGameState[name] = new_value;
}

GameState AIBlackboard_Global::GetValueGameState(std::string name)
{
	return datamapGameState[name];
}

GameState AIBlackboard_Global::GetAndDeleteValueGameState(std::string name)
{
	GameState returnValue = datamapGameState[name];
	datamapGameState.erase(name);
	return returnValue;
}

void AIBlackboard_Global::EditValueGameState(std::string name, GameState new_value)
{
	datamapGameState.erase(name);
	datamapGameState[name] = new_value;
}

void AIBlackboard_Global::DeleteValueGameState(std::string name)
{
	datamapGameState.erase(name);
}

*/

/*

void AIBlackboard_Global::AddNewValueVec2f(std::string name, AIMath_Global::Vector2f data)
{
	datamapVec2f[name] = data;
}

AIMath_Global::Vector2f AIBlackboard_Global::GetValueVec2f(std::string name)
{
	return datamapVec2f[name];
}

AIMath_Global::Vector2f AIBlackboard_Global::GetAndDeleteValueVec2f(std::string name)
{
	AIMath_Global::Vector2f returnValue = datamapVec2f[name];
	datamapVec2f.erase(name);
	return returnValue;
}

void AIBlackboard_Global::EditValueVec2f(std::string name, AIMath_Global::Vector2f new_value)
{

	datamapVec2f.erase(name);
	datamapVec2f[name] = new_value;
}

void AIBlackboard_Global::DeleteValueVec2f(std::string name) {

	datamapVec2f.erase(name);
}


void AIBlackboard_Global::AddNewValueIntVec(std::string name, std::vector<int> _newValue)
{
	datamapIntVec[name] = _newValue;
}

std::vector<int> AIBlackboard_Global::GetValueIntVec(std::string name)
{
	return datamapIntVec[name];
}

std::vector<int> AIBlackboard_Global::GetAndDeleteValueIntVec(std::string name)
{
	std::vector<int>returnValue = datamapIntVec[name];
	datamapIntVec.erase(name);
	return returnValue;
}

void AIBlackboard_Global::EditValueIntVec(std::string name, std::vector<int> _newValue)
{

	datamapIntVec.erase(name);
	datamapIntVec[name] = _newValue;
}

void AIBlackboard_Global::DeleteValueIntVec(std::string name)
{
	datamapIntVec.erase(name);
}
*/