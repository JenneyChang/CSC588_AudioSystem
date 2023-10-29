#include "Wave.h"
#include "InternalFileCB.h"
#include "FileCallback.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Wave::Wave()
	: handle(), pRawWave(nullptr), wavSize(0), wfx{}, waveID(Wave::ID::UNINITIALIZED), status(Wave::Status::UNINITIALIZED),
	  pFileCB(nullptr), pUserFileCB(nullptr)
{ }

Wave::~Wave()
{
	if (pFileCB) { delete pFileCB; pFileCB = nullptr; }
	if (pUserFileCB) { delete pUserFileCB; pUserFileCB = nullptr; }

	delete[] pRawWave;
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

unsigned int Wave::GetSize()
{
	return this->wavSize;
}

unsigned char* Wave::GetData()
{
	assert(this->pRawWave);
	return this->pRawWave;
}

WAVEFORMATEXTENSIBLE& Wave::GetFormat()
{
	return this->wfx;
}

InternalFileCB* Wave::GetFileCallback()
{
	return this->pFileCB;
}

FileCallback* Wave::GetUserCallback()
{
	return this->pUserFileCB;
}

Wave::ID Wave::GetID()
{
	return this->waveID;
}

Handle::Status Wave::SetID(Wave::ID id)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->waveID = id;
	}

	return lock;
}

Handle::Status Wave::Set(Wave::ID id, InternalFileCB* callback)
{
	assert(callback);

	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->waveID = id;
		this->pFileCB = callback;
		this->status = Wave::Status::LOADING;
	}

	return lock;
}

Handle::Status Wave::Set(Wave::ID id, FileCallback* callback)
{
	assert(callback);
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->waveID = id;
		this->pUserFileCB = callback;
		this->status = Wave::Status::LOADING;
	}

	return lock;
}

Handle::Status Wave::SetWfx(WAVEFORMATEXTENSIBLE& inWfx, unsigned char* pData, unsigned int size)
{
	assert(pData);
	assert(size > 0);
	
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->wfx = inWfx;
		this->pRawWave = pData;
		this->wavSize = size;
	}

	return lock;
}

bool Wave::Compare(Node* pNode)
{
	assert(pNode);
	Wave* tmp = (Wave*)pNode;

	if (this->waveID == tmp->waveID)
	{
		return true;
	}

	return false;
}