#include "SoundTable.h"
#include "StringThis.h"
#include "QueueManager.h"
#include "PriorityKill.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

SoundTable::SoundTable()
	: table(), mtx()
{ }

SoundTable::~SoundTable()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

bool SoundTable::QueryTable(int priority)
{
	std::lock_guard<std::mutex> lock(this->mtx);

	// early out, table still has avaliable entries
	if (this->activeEntries < SoundTable::TABLE_SIZE) { return true; }

	// check for table entry w/ lower or equal priority to kick off
	SoundTable::Entries* pEntry = nullptr;

	// we start at the bottom... (since table is sorted)
	for (unsigned int i = SoundTable::TABLE_SIZE - 1; i > 0; --i)
	{
		if (priority <= table[i].priority)
		{
			// Priority Kill-->Tell Audio to stop playing
			bool isKilled = false;
				Command* cmd = new PriorityKill(isKilled, table[i].pSnd);
				QueueManager::SendToAudio(cmd);
			while (!isKilled);	// blocking call

			// Clear table entry
			pEntry = &table[i];
			pEntry->Clear();

			// Update stats
			this->activeEntries--;

			return true;
		}
	}

	return false;
}

void SoundTable::Register(Sound* const ptr, const Sound::ID id, AnimTime startTime)
{
	std::lock_guard<std::mutex> lock(this->mtx);
	
	// should be true
	assert(this->activeEntries < SoundTable::TABLE_SIZE);

	// Grab empty table entry
	SoundTable::Entries* pEntry = this->prFindEmptyEntry();
	assert(pEntry);
	
	// Fill in table entry
	pEntry->pSnd = ptr;
	pEntry->sndId = id;
	pEntry->priority = ptr->GetPriority();
	pEntry->startTime = (startTime / AnimTime(AnimTime::Duration::ONE_SECOND));

	// Update stats & call sort...
	this->activeEntries++;
	this->prSort();
}

void SoundTable::Unregister(Sound* const ptr)
{
	std::lock_guard<std::mutex> lock(this->mtx);

	// Find table entry
	SoundTable::Entries* pEntry = this->prFind(ptr);
	assert(pEntry);

	// Nuke it
	pEntry->Clear();

	// Update stats
	this->activeEntries--;
	this->prSort();
}

void SoundTable::Update(Sound* const ptr)
{
	std::lock_guard<std::mutex> lock(this->mtx);

	// Find table entry
	SoundTable::Entries* pEntry = this->prFind(ptr);
	if (pEntry)
	{
		//if active sound, we update the priority and resort
		pEntry->priority = ptr->GetPriority();
		this->prSort();
	}
}

void SoundTable::Print()
{
	std::lock_guard<std::mutex> lock(this->mtx);

	Debug::out("-------Sound Table-------\n");
	for (unsigned int i = 0; i < SoundTable::TABLE_SIZE; ++i)
	{
		Debug::out("[%2d]: %-14s\t%d\t%.2fs\n", i, StringMe(table[i].sndId), table[i].priority, table[i].startTime);
	}
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

SoundTable::Entries* SoundTable::prFindEmptyEntry()
{
	SoundTable::Entries* pEntry = nullptr;

	for (unsigned int i = 0; i < SoundTable::TABLE_SIZE; ++i)
	{
		if (table[i].sndId == Sound::ID::UNINITIALIZED)
		{
			// found it
			pEntry = &table[i];
			break;
		}
	}

	return pEntry;
}

SoundTable::Entries* SoundTable::prFind(Sound* const ptr)
{
	assert(ptr);
	SoundTable::Entries* pEntry = nullptr;

	for (unsigned int i = 0; i < SoundTable::TABLE_SIZE; ++i)
	{
		if (table[i].pSnd->Compare(ptr))
		{
			// found it
			pEntry = &table[i];
			break;
		}
	}

	return pEntry;
}

void SoundTable::prSort()
{
	// Sort by priority
	for (int i = 0; i < activeEntries; ++i)
	{
		for (int j = i + 1; j < activeEntries; ++j)
		{
			// descending order...(highest priority up top...lowest at bottom) 
			if (table[i].priority > table[j].priority)
			{
				std::swap(table[i], table[j]);
			}

			// priority is same, sort by duration
			if (table[i].priority == table[j].priority)
			{
				if (table[j].startTime > table[i].startTime)
				{
					std::swap(table[i], table[j]);
				}
			}
		}
	}
}