#pragma once
#ifndef PITCH_A_SOUND_H
#define PITCH_A_SOUND_H

#include "Command.h"
#include "Sound.h"

class PitchASound : public Command
{
public:
	// deleted functions
	PitchASound() = delete;
	PitchASound(const PitchASound&) = delete;
	PitchASound& operator=(const PitchASound&) = delete;


	PitchASound(Sound* pSnd, float freq);
	~PitchASound() = default;

	void Execute() override;


private:
	Sound* pSound;
	float frequency;


};
#endif // !PITCH_A_SOUND_H
