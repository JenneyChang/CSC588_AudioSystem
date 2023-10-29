#include "CircularQueue.h"
#include "ThreadFramework.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

CircularQueue::CircularQueue()
	: cmdqueue{ 0 }, front(CIRCULAR_DATA_SIZE), back(CIRCULAR_DATA_SIZE), empty(true), full(false)
{ }

CircularQueue::~CircularQueue()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

bool CircularQueue::Push(Command* cmd)
{
	assert(cmd != nullptr);
	
	//lock queue mutex (destructed upon leaving scope)
	std::lock_guard<std::mutex> lock(this->mtx_queue);

	if (this->empty || this->front != this->back)
	{
		//add command to back of queue
		this->cmdqueue[this->back.Index()] = cmd;

		//increment back pointer
		this->back++;

		//update queue status
		this->empty = false;
		if (this->front == this->back)
		{
			this->full = true;
			assert(false);		//shouldn't happen...
		}

		//Debug::out("Queue : Pushed command...\n");
		return true;
	}
	
	return false;
}

bool CircularQueue::Pop(Command*& cmd)
{
	//lock mutex for queue
	std::lock_guard<std::mutex> lock(this->mtx_queue);

	if (this->full || this->front != this->back)
	{
		//grab command
		cmd = this->cmdqueue[this->front.Index()];

		//update index pointer
		this->front++;

		//update queue status
		if (this->front == this->back)
		{
			this->empty = true;
		}

		//Debug::out("Queue : Popped command...\n");
		return true;
	}

	return false;
}

bool CircularQueue::IsEmpty()
{
	return this->empty;
}
