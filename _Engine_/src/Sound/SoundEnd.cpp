#include "SoundEnd.h"
#include "AudioEngine.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

SoundEnd::SoundEnd(ASound* pASnd, Voice* voice)
	: pASound(pASnd), pVoice(voice)
{
	assert(pASnd);
	assert(voice);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void SoundEnd::Execute()
{
	//Debug::out("SoundEnd::Execute()\n");

	// Grab Sound table
	SoundTable* pTable = AudioEngine::GetSoundTable();
	assert(pTable);

	// Update Sound status
	Sound* pSound = this->pASound->GetSound();
	assert(pSound);

	// Unregister sound 
	pTable->Unregister(pSound);
	//pTable->Print();

	// Send User Callback to Game Thread
	Command* cmd = (Command*)pASound->GetCallback();
	if (cmd) 
	{
		QueueManager::SendToMain(cmd); 
	}

	pSound->SetStatus(Sound::Status::STOPPED);

	delete this;
}