#pragma once
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "Manager.h"
#include "Sound.h"
#include "PlaylistRef.h"
#include "Playlist.h"

class CircularQueue;
class SoundCallback;
class SoundManager : public Manager
{
//public:
protected:
	friend class AudioEngine;

	// deleted functions
	SoundManager() = delete;
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;

	static void Create(int toReserve = 1, int toGrow = 1);
	static void Destroy();

	static Sound* Add(Sound::ID id, PlaylistRef::ID refID, Playlist::ID playlistId, int priority = 50, SoundCallback* pSndCB = nullptr);
	static void Remove(Sound* pSnd);


//protected:
	Node* derivedCreateNode() override;


private:
	static SoundManager* poInstance;
	Sound* poComparison;

	static SoundManager* prInstance();
	
	SoundManager(int toReserve, int toGrow);
	~SoundManager();


};
#endif // !SOUND_MANAGER_H
