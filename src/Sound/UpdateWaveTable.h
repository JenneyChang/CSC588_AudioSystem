#pragma once
#ifndef UPDATE_WAVE_TABLE_H
#define UPDATE_WAVE_TABLE_H

#include "Command.h"
#include "WaveTable.h"
#include "FileCallback.h"

class UpdateWaveTable : public Command
{
public:
	// deleted functions
	UpdateWaveTable() = delete;
	UpdateWaveTable(const UpdateWaveTable&) = delete;
	UpdateWaveTable& operator=(const UpdateWaveTable&) = delete;


	UpdateWaveTable(Wave::ID id, WaveTable::Status newStatus, FileCallback* pCallback = nullptr);
	~UpdateWaveTable() = default;

	void Execute() override;


private:
	Wave::ID waveID;
	WaveTable::Status status;
	FileCallback* pUserCallback;

};
#endif // !UPDATE_WAVE_TABLE_H
