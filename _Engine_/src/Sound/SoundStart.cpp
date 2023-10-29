#include "SoundStart.h"
#include "AudioEngine.h"
#include "SoundTable.h"
#include "QueueManager.h"
#include "SoundCallback.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

SoundStart::SoundStart(Sound::ID id, Sound* pSnd, SoundCallback* callback)
	: sndId(id), pSound(pSnd), pCallback(callback)
{ 
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void SoundStart::Execute()
{
	//Debug::out("SoundStart::Execute()\n");

	// Grab Sound table
	SoundTable* pTable = AudioEngine::GetSoundTable();
	assert(pTable);

	// Register active sound
	pTable->Register(this->pSound, this->sndId, AudioEngine::GetCurrTime());

	// Debug print
	//pTable->Print();

	// Send User the callback "response"
	Command* cmd = (Command*)pCallback;
	if (cmd)
	{
		QueueManager::SendToMain(cmd);
	}

	delete this;
}