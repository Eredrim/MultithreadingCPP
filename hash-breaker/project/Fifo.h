#pragma once
#include <deque>;
#include "PasswordChunk.h";
#include "gMutex.h";

class Fifo
{
private:
	std::deque<CPasswordChunk> liste;
	gMutex mutex;
public:
	Fifo();
	void Push(CPasswordChunk);
	CPasswordChunk Pop();
	~Fifo();
};

