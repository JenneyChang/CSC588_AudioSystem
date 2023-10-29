#pragma once
#ifndef CREATE_A_SOUND_H
#define CREATE_A_SOUND_H

#include "Command.h"
#include "Sound.h"
#include "PlaylistRef.h"
#include "Playlist.h"
#include "SoundCallback.h"

class CreateASound : public Command
{
public:
	// deleted functions
	CreateASound() = delete;
	CreateASound(const CreateASound&) = delete;
	CreateASound& operator=(const CreateASound&) = delete;

	CreateASound(Sound* sound, PlaylistRef::ID refID, Playlist::ID playlist, SoundCallback* pCallback);
	~CreateASound() = default;

	void Execute() override;


private:
	Sound* pSound;
	Sound::ID sndID;
	PlaylistRef::ID refId;
	Playlist::ID playlistID;

	SoundCallback* pSoundCallback;


};
#endif // !CREATE_A_SOUND_H
