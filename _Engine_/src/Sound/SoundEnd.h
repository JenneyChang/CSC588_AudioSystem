#pragma once
#ifndef SOUND_END_H
#define SOUND_END_H

#include "Command.h"
#include "ASound.h"
#include "Voice.h"

class SoundEnd : public Command
{
public:
	// deleted functions
	SoundEnd() = delete;
	SoundEnd(const SoundEnd&) = delete;
	SoundEnd& operator=(const SoundEnd&) = delete;


	SoundEnd(ASound* pASnd, Voice* voice);
	~SoundEnd() = default;

	void Execute() override;


private:
	ASound* pASound;
	Voice* pVoice;

};
#endif // !SOUND_END_H
