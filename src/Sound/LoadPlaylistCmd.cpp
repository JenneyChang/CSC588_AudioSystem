#include "LoadPlaylistCmd.h"
#include "PlaylistManRef.h"
#include "TrackCmd.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

LoadPlaylistCmd::LoadPlaylistCmd(PlaylistRef::ID playlistId, Wave::ID wavID)
	: id(playlistId), wavId(wavID)
{ 
	assert(this->id != PlaylistRef::ID::UNINITIALIZED);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void LoadPlaylistCmd::Execute()
{
	//Debug::out("LoadPlaylist::Execute()\n");

	if (this->id == PlaylistRef::ID::SEINFELD)
	{		
		// Create Playlist ref
		PlaylistRef* pPlaylistRef = PlaylistManRef::Add(this->id, 10);

		// List of Tracks (Note: holds no real data)
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD0, TrackCmd::Type::PLAY, 0);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD1, TrackCmd::Type::PLAY, 1);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD2, TrackCmd::Type::PLAY, 2);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD3, TrackCmd::Type::PLAY, 3);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD4, TrackCmd::Type::PLAY, 4);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD5, TrackCmd::Type::PLAY, 5);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD6, TrackCmd::Type::PLAY, 6);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD7, TrackCmd::Type::PLAY, 7);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD8, TrackCmd::Type::PLAY, 8);
		pPlaylistRef->QueueTrack(Wave::ID::SEINFELD9, TrackCmd::Type::PLAY, 9);

		// Update playlist status
		pPlaylistRef->SetStatus(PlaylistRef::Status::READY);
	}
	else
	{
		// Single voice playlists

		// Grab playlist ref node from pool
		PlaylistRef* pPlaylistRef = PlaylistManRef::Add(this->id, 1);

		// List of Tracks (Note: holds no real data)
		pPlaylistRef->QueueTrack(this->wavId, TrackCmd::Type::PLAY, 0);

		// Update playlist status
		pPlaylistRef->SetStatus(PlaylistRef::Status::READY);
	}

	delete this;
}