#pragma once
#ifndef USER_SOUND_CALLBACK_H
#define USER_SOUND_CALLBACK_H

#include "SoundCallback.h"

class Sound;
class UserSoundCallback : public SoundCallback
{
public:
	// deleted functions
	UserSoundCallback(const UserSoundCallback&) = delete;
	UserSoundCallback& operator=(const UserSoundCallback&) = delete;

	UserSoundCallback(SoundCallback::Type type, Sound* snd);
	virtual ~UserSoundCallback() = default;

	void Start() override;
	void End() override;

private:
	Sound* pSound;

};
#endif // !USER_SOUND_CALLBACK_H
