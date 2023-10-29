#pragma once
#ifndef SOUND_CALLBACK_H
#define SOUND_CALLBACK_H

#include "Command.h"

class SoundCallback : public Command
{
public:
	enum class Type
	{
		START,
		END,
		PAUSE,
		STOP,
		PRIORITY_KILL
	};

	// deleted function
	SoundCallback() = delete;
	SoundCallback(const SoundCallback&) = delete;
	SoundCallback& operator=(const SoundCallback&) = delete;

	SoundCallback(SoundCallback::Type type);
	virtual ~SoundCallback() = default;

	virtual void Start();
	virtual void End();
	virtual void Pause();
	virtual void Stop();

	virtual void PriorityKill();

	void Execute() override;


protected:
	SoundCallback::Type cbType;


};
#endif // !SOUND_CALLBACK_H
