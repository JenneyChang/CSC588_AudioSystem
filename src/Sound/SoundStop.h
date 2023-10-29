#pragma once
#ifndef SOUND_START_H
#define SOUND_START_H

#include "Command.h"
#include "Sound.h"

class SoundStop : public Command
{
public:
	// deleted functions
	SoundStop() = delete;
	SoundStop(const SoundStop&) = delete;
	SoundStop& operator=(const SoundStop&) = delete;

	SoundStop(Sound* pSnd);
	~SoundStop() = default;

	void Execute() override;


private:
	Sound* pSound;


};
#endif // !SOUND_START_H
