#pragma once
#ifndef PLAYLIST_REF_H
#define PLAYLIST_REF_H

#include "DLink.h"
#include "Wave.h"
#include "TrackCmd.h"

class Playlist;
class Voice;
class PlaylistRef : public DLink
{
public:
	enum class ID
	{
		FIDDLE = 101,
		BASSOON = 102,
		OBOE = 103,
		SEINFELD = 104,
		WATERFALL,
		BEETHOVEN_LAENDLER = 501,
		CHOPIN_BOURREE,

		TESTER,
		UNINITIALIZED
	};

	enum class Status
	{
		LOADING,
		READY,
		UNINITIALIZED
	};

	struct Track
	{
		Wave::ID wavId;
		TrackCmd::Type type;
		int index;
	};


public:
	// deleted functions
	PlaylistRef(const PlaylistRef&) = delete;
	PlaylistRef& operator=(const PlaylistRef&) = delete;

	PlaylistRef();
	~PlaylistRef();

	void SetID(PlaylistRef::ID id);
	void SetStatus(PlaylistRef::Status _status);
	void SetRef(PlaylistRef::ID id, int totalNumTracks);

	unsigned int GetTrackTotal();
	void QueueTrack(Wave::ID wavId, TrackCmd::Type cmdType, int index);

	bool Compare(Node* pNode) override;


public:
	PlaylistRef::ID refID;
	PlaylistRef::Status status;

	Track* pTrackList;
	unsigned int totalTracks;


};
#endif // !PLAYLIST_REF_H
