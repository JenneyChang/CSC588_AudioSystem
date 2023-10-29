#include "PauseASound.h"
#include "ASound.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PauseASound::PauseASound(Sound* pSnd)
	: pSound(pSnd)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PauseASound::Execute()
{
	//Debug::out("PauseASound::Execute()\n");

	// Note: Sound is still active, so no table update
	// Tell ASound to pause its playlist
	ASound* pASnd = pSound->GetASound();
	assert(pASnd);
	pASnd->Pause();

	// If User has a callback, ping it
	Command* cmd = pASnd->GetCallback();
	if (cmd) { QueueManager::SendToMain(cmd); }

	// Update Sound status
	pSound->SetStatus(Sound::Status::PAUSED);

	delete this;
}