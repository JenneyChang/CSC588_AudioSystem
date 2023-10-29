#pragma once
#ifndef STOP_ASOUND_H
#define STOP_ASOUND_H

#include "Command.h"
#include "Sound.h"

class StopASound : public Command
{
public:
	// deleted functions
	StopASound() = delete;
	StopASound(const StopASound&) = delete;
	StopASound& operator=(const StopASound&) = delete;


	StopASound(Sound* pSnd);
	~StopASound() = default;

	void Execute() override;


protected:
	Sound* pSound;


};
#endif // !STOP_ASOUND_H
