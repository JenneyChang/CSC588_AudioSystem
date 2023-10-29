#pragma once
#ifndef ASOUND_MANAGER_H
#define ASOUND_MANAGER_H

#include "Manager.h"
#include "ASound.h"
#include "Sound.h"
#include "PlaylistRef.h"

class ASoundManager : public Manager
{
public:
	// deleted functions
	ASoundManager() = delete;
	ASoundManager(const ASoundManager&) = delete;
	ASoundManager& operator=(const ASoundManager&) = delete;

	static void Create(int toReserve = 2, int toGrow = 1);
	static void Destroy();

	static ASound* Add(Sound* pSound, PlaylistRef::ID refId, Playlist::ID playlistID, SoundCallback* pCallback);
	

protected:
	Node* derivedCreateNode() override;


private:
	static ASoundManager* poInstance;

	static ASoundManager* prInstance();
	
	ASoundManager(int toReserve, int toGrow);
	~ASoundManager();



};
#endif // !ASOUND_MANAGER_H
