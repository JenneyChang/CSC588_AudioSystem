#pragma once
#ifndef LOAD_WAVE_END_H
#define LOAD_WAVE_END_H

#include "Command.h"
#include "Wave.h"


class LoadWaveEnd : public Command
{
public:
	// deleted functions
	LoadWaveEnd() = delete;
	LoadWaveEnd(const LoadWaveEnd&) = delete;
	LoadWaveEnd& operator=(const LoadWaveEnd&) = delete;

	LoadWaveEnd(Wave* wav, WAVEFORMATEXTENSIBLE& inWfx, unsigned char* pData, unsigned int size);
	~LoadWaveEnd() = default;

	void Execute() override;


private:
	Wave* pWave;

	WAVEFORMATEXTENSIBLE	wfx;
	unsigned int rawSize;
	unsigned char* pRawWave;


};
#endif // !LOAD_WAVE_END_H
