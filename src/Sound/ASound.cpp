#include "ASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

ASound::ASound()
	: pPlaylist(nullptr), pSound(nullptr), sndID(Sound::ID::UNINITIALIZED), state(ASound::State::UNINITIALIZED),
	  pCallback(nullptr)
{ }

ASound::~ASound()
{
	if (this->pCallback)
	{
		delete this->pCallback;
		this->pCallback = nullptr;
	}
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void ASound::Set(Sound* snd, Playlist* playlist, SoundCallback* callback)
{
	assert(snd);
	assert(playlist);

	// ASound data
	this->pPlaylist = playlist;
	this->pSound = snd;
	this->sndID = snd->GetID();
	this->pCallback = callback;

	// back ref to ASound
	this->pSound->SetASound(this);

	// set status
	this->state = ASound::State::READY;
}

Sound* ASound::GetSound()
{
	return this->pSound;
}

SoundCallback* ASound::GetCallback()
{
	return this->pCallback;
}

void ASound::Play()
{
	pPlaylist->Play();

	// set status
	this->state = ASound::State::PLAYING;
}

void ASound::Pause()
{
	pPlaylist->Pause();

	// set status
	this->state = ASound::State::PAUSED;
}

void ASound::Stop()
{
	//Note: Used in priority Kill
	pPlaylist->Stop();

	// set status
	this->state = ASound::State::ENDED;
}

void ASound::Replay()
{
	pPlaylist->ResetTrack();
	pPlaylist->Replay();

	// set status
	this->state = ASound::State::PLAYING;
}

void ASound::SetVolume(float vol)
{
	pPlaylist->SetVolume(vol);
}

void ASound::Pan(float left, float right)
{
	pPlaylist->Pan(left, right);
}

void ASound::Pitch(float freq)
{
	pPlaylist->Pitch(freq);
}

bool ASound::Compare(Node* pNode)
{
	ASound* tmp = (ASound*)pNode;
	if (tmp->pSound == this->pSound)
	{
		return true;
	}
	return false;
}

