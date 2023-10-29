#include "StopASound.h"
#include "ASound.h"
#include "SoundStop.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

StopASound::StopASound(Sound* pSnd)
	: pSound(pSnd)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void StopASound::Execute()
{
	//Debug::out("StopASound::Execute()\n");

	ASound* pASnd = pSound->GetASound();
	assert(pASnd);

	// Send command to Aux (update sound table)
	Command* cmd = new SoundStop(pSound);
	assert(cmd);
	QueueManager::SendToAux(cmd);

	pASnd->Stop();

	delete this;
}