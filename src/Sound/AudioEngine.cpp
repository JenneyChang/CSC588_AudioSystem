#include "AudioEngine.h"
#include "DebugUtility.h"
#include "AudioThread.h"
#include "QueueManager.h"
#include "SoundManager.h"

#include "CreateWave.h"
#include "DestroyWave.h"
#include "CreateWaveAsync.h"
#include "InternalFileCB.h"
#include "UserFileCallback.h"

#include "LoadPlaylistCmd.h"
#include "CreateASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

AudioEngine::AudioEngine()
	: pXAudio2(nullptr), pMasterVoice(nullptr)
{ 
	quitflag.store(false);
	
	poWaveTable = new WaveTable();
	assert(poWaveTable);

	poSoundTable = new SoundTable();
	assert(poSoundTable);
}

AudioEngine::~AudioEngine()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void AudioEngine::Init()
{
	// Create Engine Instance
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	// Init COM lib for calling thread
	check_xaudio_result(CoInitializeEx(nullptr, COINIT_MULTITHREADED));

	// Init XAudio2 
	check_xaudio_result(XAudio2Create(&pEngine->pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR));
	assert(pEngine->pXAudio2 != nullptr);

	// Create Mastering Voice (encaps audio device)
	check_xaudio_result(pEngine->pXAudio2->CreateMasteringVoice(&pEngine->pMasterVoice));
	assert(pEngine->pMasterVoice != nullptr);

	// Managers
	QueueManager::Create();
	SoundManager::Create();

	// Launch Audio Thread
	std::thread audio(AudioThread, std::ref(pEngine->quitflag));
	Debug::SetName(audio, "--Audio--");
	audio.detach();

	Debug::out("Audio Engine Initiated...\n");
}

void AudioEngine::Destroy()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	if (!pEngine->quitflag.load())
	{
		pEngine->quitflag.store(true);
		std::this_thread::sleep_for(1s);
	}

	delete pEngine->poWaveTable;
	delete pEngine->poSoundTable;
	
	SoundManager::Destroy();
	QueueManager::Destroy();

	// clean up XAudio2 Resources
	pEngine->pMasterVoice->DestroyVoice();
	pEngine->pXAudio2->Release();

	// release COM
	CoUninitialize();

	Debug::out("Audio Engine Destroyed...\n");
}

void AudioEngine::LoadWave(const AudioEngine::Blocking, Wave::ID wavID, const char* filename)
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);
	assert(filename);

	// Check wave table (have we already loaded this resource?)
	WaveTable* pTable = pEngine->poWaveTable;
	WaveTable::Table* pTableEntry = pTable->Find(wavID);

	// Resource doesn't exsist
	if (!pTableEntry)
	{
		// Register new resource
		pTable->Register(wavID, WaveTable::Status::PENDING);

		// Setup internal file callback
		bool isDone = false;
		InternalFileCB* pFileCB = new InternalFileCB(isDone);

		// Setup Create Wave
		Command* cmd = new CreateWave(wavID, filename, pFileCB);
		assert(cmd);

		// Send message to Audio
		QueueManager::SendToAudio(cmd);
	
		// Block till load is complete
		while (!isDone);

		// Debug Print table
		//pTable->Print();
	}
	// Resource already pending creation OR exists
	else
	{
		if (pTableEntry->status == WaveTable::Status::PENDING || pTableEntry->status == WaveTable::Status::READY)
		{
			// do nothing
		}
		else
		{
			// something went wrong
			assert(false);
		}
	}
}

void AudioEngine::LoadWave(const AudioEngine::Async, Wave::ID wavID, const char* filename, UserFileCallback* pUserCB)
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);
	assert(filename);

	// Check wave table (have we already loaded this resource?)
	WaveTable* pTable = pEngine->poWaveTable;
	WaveTable::Table* pTableEntry = pTable->Find(wavID);

	// Resource doesn't exist
	if (!pTableEntry)
	{
		// Register new resource
		pTable->Register(wavID, WaveTable::Status::PENDING);

		// Setup Create Wave
		Command* cmd = new CreateWaveAsync(wavID, filename, pUserCB);
		assert(cmd);

		// Send message to Audio
		QueueManager::SendToAudio(cmd);
	}
	else
	{
		if (pTableEntry->status == WaveTable::Status::PENDING || pTableEntry->status == WaveTable::Status::READY)
		{
			// do nothing
		}
		else
		{
			// something went wrong
			assert(false);
		}
	}
}

void AudioEngine::UnloadWave(Wave::ID wavID)
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	// Find registered wave
	WaveTable* pTable = pEngine->poWaveTable;
	WaveTable::Table* pTableEntry = pTable->Find(wavID);

	if (pTableEntry)
	{
		// Tell Audio to remove Wave 
		Command* cmd = new DestroyWave(wavID);
		QueueManager::SendToAudio(cmd);

		// Unregister from table
		pTable->Unregister(wavID);
	}
	else
	{
		assert(false);
		// do nothing, can't remove something that isnt there
	}
}

void AudioEngine::LoadPlaylist(PlaylistRef::ID playlistId, Wave::ID wavID)
{
	//bool isLoaded = false;

	// Load original copy of playlist
	Command* cmd = new LoadPlaylistCmd(/*isLoaded,*/ playlistId, wavID);
	assert(cmd);

	QueueManager::SendToAudio(cmd);

	// spin till playlist is loaded
	//while (!isLoaded);
}

Sound* AudioEngine::CreateSound(Sound::ID id, PlaylistRef::ID refId, Playlist::ID playlistId, int priority, SoundCallback* pSndCB)
{
	return SoundManager::Add(id, refId, playlistId, priority, pSndCB);
}

void AudioEngine::RemoveSound(Sound* pSnd)
{
	assert(pSnd);
	SoundManager::Remove(pSnd);
}

IXAudio2* AudioEngine::GetXAudio()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	return pEngine->pXAudio2;
}

IXAudio2MasteringVoice* AudioEngine::GetMasterVoice()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	return pEngine->pMasterVoice;
}

WaveTable* AudioEngine::GetTable()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	return pEngine->poWaveTable;
}

SoundTable* AudioEngine::GetSoundTable()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	return pEngine->poSoundTable;
}

void AudioEngine::QuitFlag()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	pEngine->quitflag.store(true);
}

void AudioEngine::Update(Azul::AnimTime t)
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	pEngine->currTime = t;
	CircularQueue* toMain = QueueManager::GetMain();

	Command* cmd = nullptr;
	if (toMain->Pop(cmd))
	{
		assert(cmd);
		cmd->Execute();
	}
}

AnimTime AudioEngine::GetCurrTime()
{
	AudioEngine* pEngine = AudioEngine::Instance();
	assert(pEngine != nullptr);

	return pEngine->currTime;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

AudioEngine* AudioEngine::Instance()
{
	static AudioEngine poInstance;
	return &poInstance;
}