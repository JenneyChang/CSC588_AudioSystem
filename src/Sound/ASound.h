#pragma once
#ifndef ASOUND_H
#define ASOUND_H

#include "DLink.h"
#include "Playlist.h"
#include "Sound.h"
#include "SoundCallback.h"

class ASound : public DLink
{
public:
	enum class State
	{
		READY,
		PLAYING,
		PAUSED,
		ENDED,
		UNINITIALIZED
	};


public:
	// deleted functions
	ASound(const ASound&) = delete;
	ASound& operator=(const ASound&) = delete;

	ASound();
	~ASound();

	void Set(Sound* snd, Playlist* playlist, SoundCallback* callback);
	Sound* GetSound();
	SoundCallback* GetCallback();
	Playlist* GetPlaylist() { return this->pPlaylist; }
	ASound::State GetState() { return this->state; }

	bool Compare(Node* pNode) override;

	void Play();
	void Pause();
	void Stop();
	void Replay();

	void SetVolume(float vol);
	void Pan(float left, float right);
	void Pitch(float freq);


private:
	Playlist* pPlaylist;

	Sound* pSound;	//ref ptr
	Sound::ID sndID;
	ASound::State state;

	SoundCallback* pCallback;
	

};
#endif // !ASOUND_H
