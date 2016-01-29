#include "Logger.h"
#include "CDateTime.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "gMutex.h"

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::Log(std::string errType, std::string message) {
	CDateTime now;
	std::ofstream logfile;

	std::stringstream logMessage;

	logMessage << now.m_wDay << "/" << now.m_wMonth << "/" << now.m_wYear << " - " << errType << " - " << message << std::endl;

	mu.Lock();
	logfile.open(this->path, std::ios_base::app);
	logfile << logMessage.str();
	logfile.close();
	mu.Unlock();
}

void Logger::Error(std::string message)
{
	this->Log("ERROR", message);
}

void Logger::Warning(std::string message)
{
	this->Log("WARNING", message);
}

void Logger::Info(std::string message)
{
	this->Log("INFO", message);
}

void Logger::Debug(std::string message) 
{
	this->Log("DEBUG", message);
}