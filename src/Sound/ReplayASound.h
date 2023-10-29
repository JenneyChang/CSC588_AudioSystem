#pragma once
#ifndef REPLAY_A_SOUND_H
#define REPLAY_A_SOUND_H

#include "Command.h"

class Sound;
class ReplayASound : public Command
{
public:
	// deleted functions
	ReplayASound() = delete;
	ReplayASound(const ReplayASound&) = delete;
	ReplayASound& operator=(const ReplayASound&) = delete;


	ReplayASound(Sound* pSnd);
	~ReplayASound() = default;

	void Execute() override;


private:
	Sound* pSound;


};
#endif // !REPLAY_A_SOUND_H
