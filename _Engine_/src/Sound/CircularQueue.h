#pragma once
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "CircularIndex.h"
#include "Command.h"


class CircularQueue
{
public:
	// deleted functions
	CircularQueue(const CircularQueue&) = delete;
	CircularQueue& operator=(const CircularQueue&) = delete;

	CircularQueue();
	~CircularQueue();

	bool Push(Command* cmd);
	bool Pop(Command*& cmd);
	bool IsEmpty();


private:
	// Needs to be a power of 2
	static const int CIRCULAR_DATA_SIZE = 1 << 8;

	// verify that buffSize is a power of 2
	static_assert((CIRCULAR_DATA_SIZE& (CIRCULAR_DATA_SIZE - 1)) == 0, "not Power of 2");

	//queue of commands
	Command* cmdqueue[CIRCULAR_DATA_SIZE];

	CircularIndex front;
	CircularIndex back;

	bool empty;
	bool full;

	std::mutex mtx_queue;


};
#endif // !CIRCULAR_QUEUE_H
