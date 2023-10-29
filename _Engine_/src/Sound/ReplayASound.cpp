#include "ReplayASound.h"
#include "Sound.h"
#include "ASound.h"
#include "SoundStart.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

ReplayASound::ReplayASound(Sound* pSnd)
	: pSound(pSnd)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void ReplayASound::Execute()
{
	//Debug::out("ReplayASound::Execute()\n");

	ASound* pASound = this->pSound->GetASound();
	assert(pASound);

	//Update Sound Table...sound is active
	Command* cmd = new SoundStart(pSound->GetID(), pSound, pASound->GetCallback());
	assert(cmd);

	QueueManager::SendToAux(cmd);

	pASound->Replay();
	pSound->SetStatus(Sound::Status::PLAYING);

	delete this;
}
