#pragma once
#ifndef SOUND_TABLE_H
#define SOUND_TABLE_H

#include "Sound.h"
#include "AnimTimer.h"
#include "Handle.h"

using namespace Azul;

// Priority table for active sounds (playing)
// low value = high priority, higher value = low priority
class SoundTable
{
public:
	struct Entries
	{
		Sound* pSnd = nullptr;
		Sound::ID sndId = Sound::ID::UNINITIALIZED;
		int priority = -1;
		float startTime = 0.0f;	// in seconds

		Entries() = default;
		~Entries() = default;
		Entries(const Entries&) = default;
		Entries& operator=(const Entries&) = default;

		void Clear() 
		{
			this->pSnd = nullptr;
			this->sndId = Sound::ID::UNINITIALIZED;
			this->priority = -1;
			this->startTime = 0.0f;
		}
	};

public:
	// deleted functions
	SoundTable(const SoundTable&) = delete;
	SoundTable& operator=(const SoundTable&) = delete;

	SoundTable();
	~SoundTable();

	bool QueryTable(int priority);
	void Register(Sound* const ptr, const Sound::ID id, AnimTime startTime);
	void Unregister(Sound* const ptr);	
	void Update(Sound* const ptr);

	void Print();


private:
	static const unsigned int TABLE_SIZE = 10;
	SoundTable::Entries table[TABLE_SIZE];
	std::mutex mtx;

	int activeEntries = 0;

	SoundTable::Entries* prFindEmptyEntry();
	SoundTable::Entries* prFind(Sound* const ptr);

	void prSort();
	

};
#endif // !SOUND_TABLE_H
