#pragma once
#ifndef SOUND_START_H
#define SOUND_START_H

#include "Command.h"
#include "Sound.h"

class SoundCallback;
class SoundStart : public Command
{
public:
	// deleted functions
	SoundStart() = delete;
	SoundStart(const SoundStart&) = delete;
	SoundStart& operator=(const SoundStart&) = delete;
	
	SoundStart(Sound::ID id, Sound* pSnd, SoundCallback* callback = nullptr);
	virtual ~SoundStart() = default;

	void Execute() override;


private:
	Sound::ID sndId;
	Sound* pSound;
	SoundCallback* pCallback;


};
#endif // !SOUND_START_H
