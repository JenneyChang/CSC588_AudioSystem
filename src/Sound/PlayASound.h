#pragma once
#ifndef PLAY_A_SOUND_H
#define PLAY_A_SOUND_H

#include "Command.h"
#include "Sound.h"

class PlayASound : public Command
{
public:
	// deleted functions
	PlayASound() = delete;
	PlayASound(const PlayASound&) = delete;
	PlayASound& operator=(const PlayASound&) = delete;


	PlayASound(Sound::ID id, Sound* pSnd);
	~PlayASound() = default;

	void Execute() override;


private:
	Sound::ID sndID;
	Sound* pSound;


};
#endif // !PLAY_A_SOUND_H
