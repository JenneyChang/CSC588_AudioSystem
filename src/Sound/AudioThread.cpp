#include "AudioThread.h"
#include "FileThread.h"
#include "AuxThread.h"

#include "AudioEngine.h"
#include "QueueManager.h"

#include "WaveManager.h"
#include "VoiceManager.h"
#include "PlaylistManRef.h"
#include "PlaylistManager.h"
#include "ASoundManager.h"
#include "SoundManager.h"

using namespace ThreadFramework;

void AudioThread(std::atomic_bool& quitFlag)
{
	SimpleBanner b;

	// Spawn File Thread
	std::thread tFile(FileThread, std::ref(quitFlag));
	Debug::SetName(tFile, "--File--", 2);
	tFile.detach();

	// Spawn Aux Thread
	std::thread tAux(AuxThread, std::ref(quitFlag));
	Debug::SetName(tAux, "--Aux--", 2);
	tAux.detach();

	// Create Audio Queue & set ref for Sound Manager
	CircularQueue* toAudio = QueueManager::GetAudio();

	// Load Managers
	WaveManager::Create();
	VoiceManager::Create();
	PlaylistManRef::Create();
	PlaylistManager::Create();
	ASoundManager::Create();

	while (!quitFlag.load())
	{
		Command* cmd = nullptr; 

		// process commands 
		if (toAudio->Pop(cmd))
		{
			assert(cmd);
			cmd->Execute();
		}
	}

	// Clean up
	ASoundManager::Destroy();
	PlaylistManRef::Destroy();
	PlaylistManager::Destroy();
	VoiceManager::Destroy();
	WaveManager::Destroy();

	//AudioEngine::Destroy();
}