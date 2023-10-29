#pragma once
#ifndef PAUSE_ASOUND_H
#define PAUSE_ASOUND_H

#include "Command.h"
#include "Sound.h"

class PauseASound : public Command
{
public:
	// deleted functions
	PauseASound() = delete;
	PauseASound(const PauseASound&) = delete;
	PauseASound& operator=(const PauseASound&) = delete;


	PauseASound(Sound* pSnd);
	~PauseASound() = default;

	void Execute() override;


private:
	Sound* pSound;


};
#endif // !PAUSE_ASOUND_H
