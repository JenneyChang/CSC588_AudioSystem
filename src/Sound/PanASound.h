#pragma once
#ifndef PAN_A_SOUND_H
#define PAN_A_SOUND_H

#include "Command.h"
#include "Sound.h"


class PanASound : public Command
{
public:
	// deleted function
	PanASound() = delete;
	PanASound(const PanASound&) = delete;
	PanASound& operator=(const PanASound&) = delete;


	PanASound(Sound* pSnd, float inleft, float inright);
	~PanASound() = default;

	void Execute() override;


private:
	Sound* pSound;
	float left;
	float right;

};
#endif // !PAN_A_SOUND_H
