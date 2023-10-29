#include "WaveTable.h"
#include "StringThis.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

WaveTable::WaveTable()
	: table(), mtx()
{ }

WaveTable::~WaveTable()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void WaveTable::Register(const Wave::ID id, const WaveTable::Status newStatus)
{
	// Lock table mutex
	std::lock_guard<std::mutex> lock(this->mtx);

	// Grab avaliable table entry
	WaveTable::Table* pEntry = this->prGetEmptySlot();
	assert(pEntry);

	// Fill entry 
	pEntry->wavID = id;
	pEntry->status = newStatus;
}

void WaveTable::Unregister(const Wave::ID id)
{
	// lock table mutex
	std::lock_guard<std::mutex> lock(this->mtx);

	// find entry
	WaveTable::Table* pEntry = this->prFind(id);
	assert(pEntry);

	pEntry->status = WaveTable::Status::EMPTY;
	pEntry->wavID = Wave::ID::UNINITIALIZED;
}

void WaveTable::Update(const Wave::ID id, const WaveTable::Status newStatus)
{
	// Lock table mutex
	std::lock_guard<std::mutex> lock(this->mtx);

	// Find entry went want to update
	WaveTable::Table* pTableEntry = this->prFind(id);

	// Actual update
	pTableEntry->status = newStatus;
}

WaveTable::Table* WaveTable::Find(const Wave::ID id)
{
	// Lock wave table mutex
	std::lock_guard<std::mutex> lock(this->mtx);

	WaveTable::Table* pTableEntry = this->prFind(id);

	return pTableEntry;
}

void WaveTable::Print()
{
	// Lock wave table mutex
	std::lock_guard<std::mutex> lock(this->mtx);

	Debug::out("-------Wave Table-------\n");
	for (unsigned int i = 0; i < TABLE_SIZE; ++i)
	{
		Debug::out("[%2d]: %-14s\t%s\n", i, StringMe(table[i].wavID), StringMe(table[i].status));
	}
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

WaveTable::Table* WaveTable::prGetEmptySlot()
{
	WaveTable::Table* pTableEntry = nullptr;

	for (unsigned int i = 0; i < WaveTable::TABLE_SIZE; ++i)
	{
		if (table[i].status == WaveTable::Status::EMPTY)
		{
			// found empty entry, break
			pTableEntry = &table[i];
			break;
		}
	}

	return pTableEntry;
}

WaveTable::Table* WaveTable::prFind(const Wave::ID id)
{
	WaveTable::Table* pTableEntry = nullptr;

	for (unsigned int i = 0; i < WaveTable::TABLE_SIZE; ++i)
	{
		if (table[i].wavID == id)
		{
			// found entry, break
			pTableEntry = &table[i];
			break;
		}
	}

	return pTableEntry;
}