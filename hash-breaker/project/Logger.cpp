#include "Logger.h"
#include "CDateTime.h"
#include "CFileText.h"
#include <iostream>
#include <sstream>
#include "gMutex.h"

Logger::Logger()
{
	this->file = new CFileText(this->path, EFileOpenMode::append);

}

Logger::~Logger()
{
	this->file->Close();
	delete this->file;
}

void Logger::Log(std::string errType, std::string message) {
	CDateTime now;

	std::stringstream logMessage;

	logMessage << now.m_wDay << "/" << now.m_wMonth << "/" << now.m_wYear << " - " << errType << " - " << message << std::endl;

	mu.Lock();
	this->file->AppendLine(logMessage.str());
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