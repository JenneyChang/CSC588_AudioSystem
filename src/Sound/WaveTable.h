#pragma once
#ifndef WAVE_TABLE_H
#define WAVE_TABLE_H

#include "Wave.h"

// Registers loaded wav audio, prevent duplicate resource load
class WaveTable
{
public:
	enum class Status
	{
		PENDING,
		READY,
		EMPTY
	};

	struct Table
	{
		Wave::ID wavID;
		WaveTable::Status status;

		Table() : wavID(Wave::ID::UNINITIALIZED), status(WaveTable::Status::EMPTY) { }
		~Table() = default;
	};

	// deleted functions
	WaveTable(const WaveTable&) = delete;
	WaveTable& operator=(const WaveTable&) = delete;

	WaveTable();
	~WaveTable();

	void Register(const Wave::ID id, const WaveTable::Status newStatus);
	void Unregister(const Wave::ID id);

	void Update(const Wave::ID id, const WaveTable::Status newStatus);
	WaveTable::Table* Find(const Wave::ID id);

	void Print();


private:
	static const unsigned int TABLE_SIZE = 20;
	WaveTable::Table table[TABLE_SIZE];
	std::mutex mtx;

	WaveTable::Table* prGetEmptySlot();
	WaveTable::Table* prFind(const Wave::ID id);


};
#endif // !WAVE_TABLE_H
