#include "CreateWave.h"
#include "WaveManager.h"

#include "QueueManager.h"
#include "LoadWaveStart.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

CreateWave::CreateWave(Wave::ID id, const char* const filename, InternalFileCB* pFileCB)
	: wavID(id), pCallback(pFileCB), wavFile(filename)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void CreateWave::Execute()
{
	//Debug::out("CreateWave::Execute() \n");

	// Create Active Wave Node
	Wave* pWav = WaveManager::Add(this->wavID, this->pCallback);
	assert(pWav);

	// Send message to File Thread (load this wav file)
	Command* cmd = new LoadWaveStart(pWav, wavFile);
	assert(cmd);

	QueueManager::SendToFile(cmd);

	delete this;
}