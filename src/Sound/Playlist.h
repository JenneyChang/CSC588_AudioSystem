#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "DLink.h"
#include "Voice.h"
#include "TrackCmd.h"

class ASound;
class PlaylistRef;
class Playlist : public DLink
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
		PLAYING,
		PAUSED,
		ENDED,	// ended?
		REPLAY,
		UNINITIALIZED
	};

	struct Track
	{
		Voice* pVoice;
		TrackCmd* pCmd;
		int index;
	};


public:
	// deleted functions
	Playlist(const Playlist&) = delete;
	Playlist& operator=(const Playlist&) = delete;

	Playlist();
	~Playlist();

	void SetStatus(Playlist::Status newStatus);
	Playlist::Status GetStatus();
	void SetASound(ASound* pASnd);
	void SetPlaylist(PlaylistRef* ref, Playlist::ID id);

	void Play();
	void Pause();
	void Stop();
	void Replay();
	void SetVolume(float vol);
	void Pan(float left, float right);
	void Pitch(float freq);

	bool Finished();
	void AdvanceTrack();
	void ResetTrack();


	bool Compare(Node* pNode) override;

	Playlist::ID playlistID;
	Track* pTrackList;

	unsigned int currTrack;
	unsigned int totalTracks;

private:
	// TODO: change
	Playlist::Status status;

	ASound* pASound;	// back ref to owner...

	TrackCmd* CreateCommand(TrackCmd::Type type, int index);

};
#endif // !PLAYLIST_H
