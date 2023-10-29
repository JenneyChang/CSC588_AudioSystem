#include "PlayASound.h"
#include "ASound.h"
#include "SoundStart.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PlayASound::PlayASound(Sound::ID id, Sound* pSnd)
	: sndID(id), pSound(pSnd)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PlayASound::Execute()
{
	//Debug::out("PlayASound::Execute()\n");

	// Grab ASound
	ASound* pASnd = pSound->GetASound();
	assert(pASnd);

	// Sound is just loaded
	if (this->pSound->GetStatus() == Sound::Status::READY)
	{
		//Update Sound Table...sound is active
		Command* cmd = new SoundStart(sndID, pSound, pASnd->GetCallback());
		assert(cmd);

		QueueManager::SendToAux(cmd);
	}

	// Tell ASound to start its playlist
	pASnd->Play();
	pSound->SetStatus(Sound::Status::PLAYING);

	delete this;
}