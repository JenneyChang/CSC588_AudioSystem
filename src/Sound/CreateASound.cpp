#include "CreateASound.h"
#include "ASoundManager.h"
#include "SoundManager.h"
#include "PlaylistManRef.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

CreateASound::CreateASound(Sound* sound, PlaylistRef::ID refID, Playlist::ID playlist, SoundCallback* pCallback)
	: pSound(sound), refId(refID), playlistID(playlist), pSoundCallback(pCallback)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void CreateASound::Execute()
{
	//Debug::out("CreateASound::Execute()\n");

	// Create ASound
	ASoundManager::Add(pSound, refId, playlistID, pSoundCallback);

	// Update Sound status
	pSound->SetStatus(Sound::Status::READY);
	
	delete this;
}