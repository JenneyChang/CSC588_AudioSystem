#pragma once
#ifndef TRACK_CMD_H
#define TRACK_CMD_H

#include "Command.h"

class Voice;
class TrackCmd : public Command
{
public:
	enum class Type
	{
		PLAY,
		STOP,
		//PAUSE,
		//PAN,
		//VOL,
		UNINITIALIZED,
		DEFAULT = UNINITIALIZED
	};

	TrackCmd::Type type;
	unsigned int index;
	Voice* pVoice;

	// deleted functions
	TrackCmd() = delete;
	TrackCmd(const TrackCmd&) = delete;
	TrackCmd& operator=(const TrackCmd&) = delete;

	TrackCmd(TrackCmd::Type _type, unsigned int _index);
	virtual ~TrackCmd() = default;


};
#endif // !TRACK_CMD_H
