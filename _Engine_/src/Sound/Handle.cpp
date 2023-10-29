#include "Handle.h"
#include "HandleManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Handle::Handle()
{
	// Activate this handle
	Handle::Status status = HandleManager::Activate(this->id, this->index);
	assert(status == Handle::Status::VALID_HANDLE);

	//Debug::out("Handle(): new Handle(%u):0x%X\n", this->index, this->id);
}

Handle::~Handle()
{
	// Invalidate handle
	HandleManager::Invalidate(*this);

	//Debug::out("~Handle(): invalidate handle(%u):0x%X\n", this->index, this->id);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

bool Handle::operator==(const Handle& h) const
{
	return (this->id == h.id);
}

Handle::ID Handle::GetID() const
{
	return this->id;
}

Handle::Index Handle::GetIndex() const
{
	return this->index;
}

Handle::Status Handle::Validate(const Handle& h)
{
	return HandleManager::Validate(h);
}

Handle::Status Handle::Invalidate(Handle& h)
{
	return HandleManager::Invalidate(h);
}

Handle::Status Handle::ValidAcquire(const Handle& h)
{
	return HandleManager::ValidAcquire(h);
}

Handle::Status Handle::ValidRelease(const Handle& h)
{
	return HandleManager::ValidRelease(h);
}
