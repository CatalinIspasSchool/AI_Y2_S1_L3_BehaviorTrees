#pragma once

#include <stdlib.h>
#include <time.h>

/*
CMP304/MAT501 AI Framework (2025)
*/


class AIRandom_Global
{
public:

	AIRandom_Global(const AIRandom_Global& obj) = delete;

	static AIRandom_Global* getInstance();

	double GetRandom01();
	int GetRandomValue(int _range);
	double GetRandomValue(float _range);


private:

	static AIRandom_Global* instancePointer;
	AIRandom_Global() { srand((unsigned int) (time(0))); }

};

