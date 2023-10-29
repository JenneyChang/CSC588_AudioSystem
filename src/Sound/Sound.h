#pragma once
#ifndef SOUND_H
#define SOUND_H

#include "DLink.h"
#include "Handle.h"

class ASound;

// Sound class essentially sends messages to initiate audio engine to play, pause, etc
class Sound : public DLink
{
public:
	enum class ID
	{
		FIDDLE = 101,
		BASSOON = 102,
		OBOE = 103,
		TESTER,
		WATERFALL,
		SEINFELD = 200,

		BEETHOVEN_LAENDLER = 501,
		CHOPIN_BOURREE,

		UNINITIALIZED
	};

	enum class Status
	{
		LOADING,
		READY,
		PLAYING,
		PAUSED,
		STOPPED,
		REJECTED,
		UNINITIALIZED
	};

	Handle::Status Play();
	Handle::Status Pause();
	Handle::Status Stop();
	Handle::Status Replay();

	Handle::Status SetVolume(float vol);
	Handle::Status Pan(float left, float right);
	Handle::Status Pitch(float freq);

	Handle::Status SetPriority(unsigned int);
	int GetPriority();

	Sound::ID GetID();

	Handle::Status SetStatus(Sound::Status status);
	Sound::Status GetStatus();


protected:
	Sound();
	~Sound();


	// TODO...this seems messy
	friend class SoundManager;
	friend class ASound;
	friend class SoundTable;

	// all the free floating commands...
	friend class PlayASound;
	friend class StopASound;
	friend class PauseASound;
	friend class ReplayASound;
	friend class ASoundVolume;
	friend class PitchASound;
	friend class PanASound;
	friend class PriorityKill;
	friend class SoundStop;
	
	Handle::Status SetSound(Sound::ID id, int priority);
	Handle::Status SetASound(ASound* const pASnd);
	ASound* GetASound();

	bool Compare(Node* pNode) override;


private:
	Handle handle;
	Sound::ID soundID;

	ASound* pASound;	// back pointer

	int priority;
	Sound::Status status;


};
#endif // !SOUND_H
