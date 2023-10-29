#include "LoadWaveEnd.h"
#include "QueueManager.h"
#include "UpdateWaveTable.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

LoadWaveEnd::LoadWaveEnd(Wave* wav, WAVEFORMATEXTENSIBLE& inWfx, unsigned char* pData, unsigned int size)
	: pWave(wav), wfx(inWfx), rawSize(size), pRawWave(pData)
{
	assert(wav);
	assert(pData);
	assert(size > 0);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void LoadWaveEnd::Execute()
{
	//Debug::out("LoadWavEnd::Execute()\n");

	// Push Data to wave object
	this->pWave->SetWfx(this->wfx, this->pRawWave, this->rawSize);

	// Send table Update to Aux
	Command* cmd = new UpdateWaveTable(this->pWave->GetID(), WaveTable::Status::READY, this->pWave->GetUserCallback());
	assert(cmd);
	QueueManager::SendToAux(cmd);

	// Send Internal File Callback to Aux
	if (this->pWave->GetFileCallback() != nullptr)
	{
		cmd = (Command*)this->pWave->GetFileCallback();
		QueueManager::SendToAux(cmd);
	}

	delete this;
}