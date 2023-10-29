#include "Handle.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Handle::Lock::Lock(const Handle& h)
	: handle(h), status(Lock::Status::UNLOCKED)
{
	this->lock();
}

Handle::Lock::~Lock()
{
	this->unlock();
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

Handle::Lock::operator bool() const
{
	return (status == Lock::Status::LOCKED);
}

Handle::Lock::operator Handle::Status() const
{
	Handle::Status hStatus;

	if (this->status == Lock::Status::LOCKED)
	{
		hStatus = Handle::Status::SUCCESS;
	}
	else
	{
		hStatus = Handle::Status::HANDLE_ERROR;
	}

	return hStatus;
}

void Handle::Lock::lock()
{
	if (this->status == Lock::Status::UNLOCKED)
	{
		const Handle::Status hStatus = Handle::ValidAcquire(handle);
		if (hStatus == Handle::Status::VALID_HANDLE)
		{
			this->status = Lock::Status::LOCKED;
		}
		else
		{
			this->status = Lock::Status::UNLOCKED;
		}
	}
	else
	{
		assert(false);
	}
}

void Handle::Lock::unlock()
{
	if (this->status == Lock::Status::LOCKED)
	{
		const Handle::Status hStatus = Handle::ValidRelease(handle);
		if (hStatus == Handle::Status::VALID_HANDLE)
		{
			this->status = Lock::Status::UNLOCKED;
		}
		else
		{
			this->status = Lock::Status::LOCKED;
		}
	}
}
