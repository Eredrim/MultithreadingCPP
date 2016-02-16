#pragma once

#include <iostream>
#include <string>
#include "gMutex.h"

class Logger
{
private:
	const std::string path = "hashbreaker.log";
	gMutex mu;
	void Log(std::string, std::string);
	CFileText* file;
public:
	Logger();
	~Logger();
	void Error(std::string);
	void Warning(std::string);
	void Info(std::string);
	void Debug(std::string);
};
