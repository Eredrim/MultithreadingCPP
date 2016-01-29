#pragma once
#include <mutex>

class gMutex
{
private:
	std::mutex mu;
public:
	gMutex();
	~gMutex();
	void Lock();
	void Unlock();
};

