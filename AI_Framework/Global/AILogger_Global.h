#pragma once
#include <string>

/*
CMP304/MAT501 AI Framework (2025)
*/



class AILogger_Global
{
public:
	AILogger_Global(const AILogger_Global& obj) = delete;

	static AILogger_Global* getInstance();

	void LogWarning(std::string _logText);
	void LogError(std::string _logText);
	void LogMessage(std::string _logText);
	void EnableLogging(bool enabled) { loggingEnabled = enabled; }

private:

	static AILogger_Global* instancePointer;
	AILogger_Global() { }

	bool loggingEnabled = true;
};

