#pragma once
#ifndef LOAD_WAV_START_H
#define LOAD_WAV_START_H

#include "Command.h"
#include "Wave.h"

class LoadWaveStart : public Command
{
public:
	// deleted functions
	LoadWaveStart() = delete;
	LoadWaveStart(const LoadWaveStart&) = delete;
	LoadWaveStart& operator=(const LoadWaveStart&) = delete;

	LoadWaveStart(Wave* wav, const char* const filename);
	~LoadWaveStart();

	void Execute() override;


private:
	Wave* pWav;
	const char* wavFile;


};
#endif // !LOAD_WAV_START_H
