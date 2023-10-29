#pragma once
#ifndef VOICE_H
#define VOICE_H

#include <xaudio2.h>
#include "DLink.h"
#include "Wave.h"

// Use submit audio data to audio processing pipeline (a mastering voice)
// Basic a queue holds audio buffers
class ASound;
class VoiceCallback;
class Voice : public DLink
{
public:
	// deleted functions
	Voice(const Voice&) = delete;
	Voice& operator=(const Voice&) = delete;

	Voice();
	~Voice();

	void SetVoice(Wave* wav);

	VoiceCallback* GetCallback();
	XAUDIO2_VOICE_DETAILS QueryDetails();

	void Play();
	void Pause();
	void Stop();
	void Replay();

	void SetVolume(float volume);
	void SetPan(unsigned int voiceChannels, unsigned int masterChannels, const float* outputs);
	void SetPitch(float frequency);

	bool Compare(Node* pNode) override;


private:
	IXAudio2SourceVoice* poSourceVoice = nullptr;
	VoiceCallback* poCallback = nullptr;
	Wave* pWave = nullptr;

	XAUDIO2_BUFFER buffer{  };

};
#endif // !VOICE_H
