#pragma once
#ifndef PLAY_TRACK_H
#define PLAY_TRACK_H

#include "TrackCmd.h"
#include "Playlist.h"

class Voice;

class PlayTrack : public TrackCmd
{
public:
	PlayTrack(TrackCmd::Type inType, int trackNum);
	~PlayTrack() = default;

	void Execute() override;



};
#endif // !PLAY_TRACK_H
