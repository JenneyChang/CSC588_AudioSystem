#include "UpdateWaveTable.h"
#include "AudioEngine.h"
#include "QueueManager.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

UpdateWaveTable::UpdateWaveTable(Wave::ID id, WaveTable::Status newStatus, FileCallback* pCallback)
	: waveID(id), status(newStatus), pUserCallback(pCallback)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void UpdateWaveTable::Execute()
{
	//Debug::out("UpdateWaveTable::Execute()\n");

	// Grab table
	WaveTable* pTable = AudioEngine::GetTable();
	assert(pTable);

	// Update entry
	pTable->Update(this->waveID, this->status);
	//pTable->Print();

	if (pUserCallback)
	{
		Command* cmd = (Command*)pUserCallback;
		QueueManager::SendToMain(cmd);
	}

	delete this;
}