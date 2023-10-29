#include "HandleManager.h"


//---------------------------------------------------------------
//	PRIVATE CONSTRUCTION
//---------------------------------------------------------------

HandleManager::HandleManager()
{
	this->srcID = STARTING_ID;

	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		this->table[i].id.store(INVALID_STATE);
	}
}

HandleManager::~HandleManager()
{
	this->srcID = STARTING_ID;

	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		table[i].id.store(INVALID_STATE);
	}
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

Handle::Status HandleManager::Activate(Handle::ID& id, Handle::Index& index)
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager);

	// Grab avaliable table entry
	Handle::Status status = Handle::Status::HANDLE_ERROR;
	if (pManager->prFindNextAvaliable(index))
	{
		// Attempt to lock table entry
		bool isLocked = pManager->table[index].mtx.try_lock();
		
		// (for whatever reason) during lock attempt, resource is no longer avaliable
		if (pManager->table[index].id.load() != INVALID_STATE)
		{
			// and we have successfully grabed it, after it got took
			if (isLocked)
			{
				// Unlock and bail
				pManager->table[index].mtx.unlock();
				isLocked = false;
			}
		}

		// else, we're going to use this table entry
		if (isLocked)
		{
			// generate new ID & log ID in table
			id = pManager->prGetNewID();
			pManager->table[index].id.store(id);

			// indicate operation was successful
			status = Handle::Status::VALID_HANDLE;

			// unlock on our way out
			pManager->table[index].mtx.unlock();
		}
	}
	else
	{
		status = Handle::Status::INSUFFICIENT_SPACE;
		assert(false); // Debug check
	}

	return status;
}

Handle::Status HandleManager::Validate(const Handle& h)
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager);

	Handle::Status status = pManager->prIsHandleAndRangeValid(h);

	return status;
}

Handle::Status HandleManager::Invalidate(Handle& h)
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager);

	// Check handle data is valid
	Handle::Status status = pManager->prIsHandleValid(h);

	if (status == Handle::Status::VALID_HANDLE)
	{
		// Attempt to lock table entry
		bool isLocked = pManager->table[h.GetIndex()].mtx.try_lock();

		if (isLocked)
		{
			// double check its still valid
			status = pManager->prIsHandleValid(h);

			// handle has been taken or invalidated
			if (status != Handle::Status::VALID_HANDLE)
			{
				// unlock and leave
				pManager->table[h.GetIndex()].mtx.unlock();
			}
			else
			{
				// invalidate it now
				pManager->table[h.GetIndex()].id.store(INVALID_STATE);
			}
		}
	}

	return status;
}

Handle::Status HandleManager::ValidAcquire(const Handle& h)
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager);

	// Check validity
	Handle::Status status = pManager->prIsHandleAndRangeValid(h);
	if (status == Handle::Status::VALID_HANDLE)
	{
		// Get shared mutex
		pManager->table[h.GetIndex()].mtx.lock_shared();

		// Double check validity...case of a race
		status = pManager->prIsHandleAndRangeValid(h);
		if (status == Handle::Status::VALID_HANDLE)
		{
			// acquire is valid
		}
		else
		{
			// either invalid or already acquired
			pManager->table[h.GetIndex()].mtx.unlock_shared();
		}
	}

	return status;
}

Handle::Status HandleManager::ValidRelease(const Handle& h)
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager);

	// Check validity
	Handle::Status status = pManager->prIsHandleAndRangeValid(h);
	if (status == Handle::Status::VALID_HANDLE)
	{
		// unlock resource
		pManager->table[h.GetIndex()].mtx.unlock_shared();
	}
	else
	{
		// something went wrong
		assert(false);
	}

	return status;
}

void HandleManager::PrintTable()
{
	HandleManager* pManager = HandleManager::prInstance();
	assert(pManager != nullptr);

	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		Trace::out("[%2d]:  %d(%p)\n", i, pManager->table[i].id.load(), &pManager->table[i]);
	}
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

HandleManager* HandleManager::prInstance()
{
	static HandleManager poInstance;
	return &poInstance;
}

bool HandleManager::prFindNextAvaliable(Handle::Index& index)
{
	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		if (this->table[i].id.load() == INVALID_STATE)
		{
			//found empty entry
			index = i;
			return true;
		}
	}

	return false;
}

Handle::ID HandleManager::prGetNewID()
{
	return this->srcID++;
}

Handle::Status HandleManager::prIsHandleAndRangeValid(const Handle& h)
{
	Handle::Status status = Handle::Status::HANDLE_ERROR;

	// check handle index is within the table
	if (h.GetIndex() < TABLE_SIZE)
	{
		// check handle id matches table record
		if (table[h.GetIndex()].id.load() == h.GetID())
		{
			status = Handle::Status::VALID_HANDLE;
		}
		else
		{
			status = Handle::Status::INVALID_HANDLE;
		}
	}

	return status;
}

Handle::Status HandleManager::prIsHandleValid(const Handle& h)
{
	Handle::Status status = Handle::Status::HANDLE_ERROR;

	if (table[h.GetIndex()].id.load() == h.GetID())
	{
		status = Handle::Status::VALID_HANDLE;
	}
	else
	{
		status = Handle::Status::INVALID_HANDLE;
	}

	return status;
}

Handle::Status HandleManager::prIsWithinRange(const Handle& h)
{
	Handle::Status status = Handle::Status::HANDLE_ERROR;

	if (h.GetIndex() < TABLE_SIZE)
	{
		status = Handle::Status::VALID_HANDLE;
	}
	else
	{
		status = Handle::Status::INVALID_HANDLE;
	}

	return status;
}