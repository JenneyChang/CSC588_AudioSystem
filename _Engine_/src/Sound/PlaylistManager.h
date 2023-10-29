#pragma once
#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include "Manager.h"
#include "Playlist.h"

class ASound;
// Holds Active copies of playlists
class PlaylistManager : public Manager
{
public:
	// deleted functions
	PlaylistManager() = delete;
	PlaylistManager(const PlaylistManager&) = delete;
	PlaylistManager& operator=(const PlaylistManager&) = delete;

	static void Create(int toReserve = 2, int toGrow = 1);
	static void Destroy();

	// Copies original playlist 
	static Playlist* Add(PlaylistRef* pPlaylistRef, Playlist::ID id);
	static void Remove(Playlist* pPlaylist);


protected:
	Node* derivedCreateNode() override;


private:
	static PlaylistManager* poInstance;
	Playlist* poComparison;

	static PlaylistManager* prInstance();

	PlaylistManager(int toReserve, int toGrow);
	~PlaylistManager();


};
#endif // !PLAYLIST_MANAGER_H
