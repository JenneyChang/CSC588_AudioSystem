#pragma once
#ifndef STREAM_END_H
#define STREAM_END_H

#include "Command.h"
#include "ASound.h"
#include "Voice.h"


class StreamEnd : public Command
{
public:
	// deleted functions
	StreamEnd() = delete;
	StreamEnd(const StreamEnd&) = delete;
	StreamEnd& operator=(const StreamEnd&) = delete;

	StreamEnd(ASound* pASnd, Voice* voice);
	~StreamEnd() = default;

	void Execute() override;


private:
	ASound* pASound = nullptr;
	Voice* pVoice = nullptr;


};
#endif // !STREAM_END_H
