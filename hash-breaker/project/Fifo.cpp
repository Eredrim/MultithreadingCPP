#include "Fifo.h"
#include "PasswordChunk.h"
#include <deque>




Fifo::Fifo()
{
	this->liste = std::deque<CPasswordChunk>();
}

void Fifo::Push(CPasswordChunk chunck) {
	mutex.Lock();
	liste.push_back(chunck);
	mutex.Unlock();
}

CPasswordChunk Fifo::Pop() {
	mutex.Lock();
	CPasswordChunk chunck = liste.front();
	liste.pop_front();
	mutex.Unlock();
	return chunck;
}

Fifo::~Fifo()
{
	this->liste.clear();
}
