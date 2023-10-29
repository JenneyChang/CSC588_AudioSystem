#pragma once
#ifndef ASOUND_VOLUME_H
#define ASOUND_VOLUME_H

#include "Command.h"
#include "Sound.h"

class ASoundVolume : public Command
{
public:
	// deleted functions
	ASoundVolume() = delete;
	ASoundVolume(const ASoundVolume&) = delete;
	ASoundVolume& operator=(const ASoundVolume&) = delete;

	ASoundVolume(Sound* pSnd, float vol);
	~ASoundVolume() = default;

	void Execute() override;


private:
	Sound* pSound;
	float volume;


};
#endif // !ASOUND_VOLUME_H
