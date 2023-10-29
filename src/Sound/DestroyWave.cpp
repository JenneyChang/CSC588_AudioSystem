#include "DestroyWave.h"
#include "WaveManager.h"
#include "QueueManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

DestroyWave::DestroyWave(Wave::ID id)
	: wavId(id)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void DestroyWave::Execute()
{
	Debug::out("DestroyWave::Execute()\n");

	Wave* pWav = WaveManager::Find(wavId);
	assert(pWav);

	WaveManager::Remove(pWav);

	delete this;
}