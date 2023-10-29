#include "CreateWaveAsync.h"
#include "WaveManager.h"
#include "QueueManager.h"
#include "LoadWaveStart.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

CreateWaveAsync::CreateWaveAsync(Wave::ID id, const char* const filename, FileCallback* callback)
	: wavID(id), pCallback(callback), wavFile(filename)
{
	assert(filename);
	assert(callback);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void CreateWaveAsync::Execute()
{
	//Debug::out("Create Wave Async::Execute()\n");

	// Create Active Wave Node
	Wave* pWav = WaveManager::Add(this->wavID, this->pCallback);
	assert(pWav);

	// Send message to File Thread (load this wav file)
	Command* cmd = new LoadWaveStart(pWav, wavFile);
	assert(cmd);

	QueueManager::SendToFile(cmd);

	delete this;
}
