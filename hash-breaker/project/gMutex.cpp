#include "gMutex.h"
#include <mutex>

gMutex::gMutex()
{
}

gMutex::~gMutex()
{
}

void gMutex::Lock()
{
	this->mu.lock();
}

void gMutex::Unlock()
{
	this->mu.unlock();
}