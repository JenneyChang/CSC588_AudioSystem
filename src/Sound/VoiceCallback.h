#pragma once
#ifndef VOICE_CALLBACK_H
#define VOICE_CALLBACK_H

#include <xaudio2.h>
#include "Sound.h"

class Voice;
class ASound;
class VoiceCallback : public IXAudio2VoiceCallback
{
public:
	// deleted functions
	VoiceCallback(const VoiceCallback&) = delete;
	VoiceCallback& operator=(const VoiceCallback&) = delete;

	VoiceCallback();
	virtual ~VoiceCallback() = default;

	void SetVoice(Voice* voice);
	void SetASnd(ASound* const pASnd);
	void SetData(ASound* pASnd, Voice* voice);

	// Only really using this function...
	void STDMETHODCALLTYPE OnStreamEnd() override;

	void STDMETHODCALLTYPE OnVoiceProcessingPassStart(UINT32 bytesRequired) override;
	void STDMETHODCALLTYPE OnVoiceProcessingPassEnd() override;
	void STDMETHODCALLTYPE OnBufferStart(void*) override;
	void STDMETHODCALLTYPE OnBufferEnd(void*) override;
	void STDMETHODCALLTYPE OnLoopEnd(void*) override;
	void STDMETHODCALLTYPE OnVoiceError(void*, HRESULT) override;


private:
	ASound* pASound;
	Voice* pVoice;


};
#endif // !VOICE_CALLBACK_H
