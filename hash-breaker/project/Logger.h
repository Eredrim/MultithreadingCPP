#pragma once

#include <iostream>
#include <string>
#include "CDateTime.h"
#include <fstream>
#include "gMutex.h"

class Logger
{
private:
	const std::string path = "hashbreaker.log";
	gMutex mu;
	void Log(std::string, std::string);
public:
	Logger();
	~Logger();
	void Error(std::string);
	void Warning(std::string);
	void Info(std::string);
	void Debug(std::string);
};
