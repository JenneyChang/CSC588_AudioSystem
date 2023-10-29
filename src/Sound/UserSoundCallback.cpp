#include "UserSoundCallback.h"
#include "Sound.h"

UserSoundCallback::UserSoundCallback(SoundCallback::Type type, Sound* snd)
	: SoundCallback(type), pSound(snd)
{
	assert(snd);
}

void UserSoundCallback::Start()
{
	Debug::out("User Sound Callback--> Sound Start\n");
}

void UserSoundCallback::End()
{
	Debug::out("User Sound Callback--> Sound End\n");

	this->pSound->Play();
}
