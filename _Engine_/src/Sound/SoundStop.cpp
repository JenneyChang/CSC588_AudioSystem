#include "SoundStop.h"
#include "AudioEngine.h"
#include "SoundTable.h"
#include "ASound.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

SoundStop::SoundStop(Sound* pSnd)
	: pSound(pSnd)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void SoundStop::Execute()
{
	//Debug::out("SoundStop::Execute()\n");

	// Grab Sound table
	SoundTable* pTable = AudioEngine::GetSoundTable();
	assert(pTable);

	// Unregister sound (sound is no longer active)
	pTable->Unregister(this->pSound);

	// Debug print
	//pTable->Print();

	ASound* pASnd = pSound->GetASound();
	Command* cmd = (Command*)pASnd->GetCallback();
	if (cmd) { QueueManager::SendToMain(cmd); }

	pSound->SetStatus(Sound::Status::STOPPED);

	delete this;
}