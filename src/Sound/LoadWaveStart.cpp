#include "LoadWaveStart.h"
#include "WaveManager.h"
#include "RIFF_PARSER.h"
#include "File.h"

#include "QueueManager.h"
#include "LoadWaveEnd.h"

using namespace Azul;


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

LoadWaveStart::LoadWaveStart(Wave* wav, const char* const filename)
	: pWav(wav), wavFile(filename)
{
	assert(wav);
	assert(filename);
}

LoadWaveStart::~LoadWaveStart()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void LoadWaveStart::Execute()
{
	//Debug::out("LoadWavStart::Execute()\n");

	// File Load
	WAVEFORMATEXTENSIBLE	wfx{};

	// READ AUDIO FILE
	File::Handle fh;
	File::Error ferr;
	ferr = File::Open(fh, wavFile, File::Mode::READ);
	assert(ferr == File::Error::SUCCESS);

	// (1) check file type, (2) read chunk data
	DWORD dwChunkSize;
	DWORD dwChunkPosition;
	DWORD filetype;

	//do work
	FindChunk(fh, fourccRIFF, dwChunkSize, dwChunkPosition);
	ReadChunkData(fh, &filetype, sizeof(DWORD), dwChunkPosition);
	if (filetype != fourccWAVE) { assert(false); }

	// locate format (wfx) chunk & copy to wave structure
	FindChunk(fh, fourccFMT, dwChunkSize, dwChunkPosition);
	ReadChunkData(fh, &wfx, dwChunkSize, dwChunkPosition);

	//fill out the audio data buffer with the contents of the fourccDATA chunk
	FindChunk(fh, fourccDATA, dwChunkSize, dwChunkPosition);
	unsigned char* pRawWave = new BYTE[dwChunkSize]();
	ReadChunkData(fh, pRawWave, dwChunkSize, dwChunkPosition);
	
	Debug::out("Read File: %s\n", this->wavFile);

	// Push read data to wave object
	Command* cmd = new LoadWaveEnd(this->pWav, wfx, pRawWave, (unsigned int) dwChunkSize);
	assert(cmd);

	// Send Callback to Audio
	QueueManager::SendToAudio(cmd);

	delete this;
}
