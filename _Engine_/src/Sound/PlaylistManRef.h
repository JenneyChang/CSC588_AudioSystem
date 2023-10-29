#pragma once
#ifndef PLAYLIST_MAN_REF_H
#define PLAYLIST_MAN_REF_H

#include "Manager.h"
#include "PlaylistRef.h"


// Holds static list of loaded playlists 
class PlaylistManRef : public Manager
{
public:
	// deleted functions
	PlaylistManRef() = delete;
	PlaylistManRef(const PlaylistManRef&) = delete;
	PlaylistManRef& operator=(const PlaylistManRef&) = delete;

	static void Create(int toReserve = 2, int toGrow = 1);
	static void Destroy();

	static PlaylistRef* Add(PlaylistRef::ID id, int totalNumTracks);
	static PlaylistRef* Find(PlaylistRef::ID id);


protected:
	Node* derivedCreateNode() override;


private:
	static PlaylistManRef* poInstance;
	PlaylistRef* poComparison;

	static PlaylistManRef* prInstance();

	PlaylistManRef(int toReserve, int toGrow);
	~PlaylistManRef();


};
#endif // !PLAYLIST_MAN_REF_H
