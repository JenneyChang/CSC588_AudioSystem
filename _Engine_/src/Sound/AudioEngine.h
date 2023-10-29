#pragma once
#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <xaudio2.h>
#include "AnimTimer.h"
#include "WaveTable.h"
#include "SoundTable.h"
#include "PlaylistRef.h"
#include "Playlist.h"
#include "Sound.h"
#include "SoundCallback.h"

class UserFileCallback;

// Loads up XAudio2 and Interfaces with rest of Audio 
class AudioEngine
{
public:
	enum class Async { LOAD };
	enum class Blocking { LOAD };

	// deleted functions
	AudioEngine(const AudioEngine&) = delete;
	AudioEngine& operator=(const AudioEngine&) = delete;

	static void Init();
	static void Destroy();

	static void LoadWave(const AudioEngine::Blocking, Wave::ID wavID, const char* filename);
	static void LoadWave(const AudioEngine::Async, Wave::ID wavID, const char* filename, UserFileCallback* pUserCB = nullptr);
	static void UnloadWave(Wave::ID wavID);

	static void LoadPlaylist(PlaylistRef::ID playlistId, Wave::ID wavID);
	//static void RemovePlaylist(PlaylistRef::ID playlistId);
	static Sound* CreateSound(Sound::ID id, PlaylistRef::ID refId, Playlist::ID playlistId, int priority = 50, SoundCallback* pSndCB = nullptr);
	static void RemoveSound(Sound* pSnd);

	static void Update(Azul::AnimTime t);

	static IXAudio2* GetXAudio();
	static IXAudio2MasteringVoice* GetMasterVoice();
	static WaveTable* GetTable();
	static SoundTable* GetSoundTable();
	static AnimTime GetCurrTime();

	static void QuitFlag();


private:
	static AudioEngine* Instance();

	AudioEngine();
	~AudioEngine();


private:
	IXAudio2* pXAudio2;
	IXAudio2MasteringVoice* pMasterVoice;

	std::atomic_bool quitflag;
	WaveTable* poWaveTable;
	SoundTable* poSoundTable;

	AnimTime currTime;


};
#endif // !AUDIO_ENGINE_H
