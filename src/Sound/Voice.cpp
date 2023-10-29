#include "Voice.h"
#include "AudioEngine.h"
#include "DebugUtility.h"
#include "WaveManager.h"
#include "VoiceCallback.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Voice::Voice()
{ }

Voice::~Voice()
{
	if (poCallback) { delete poCallback; poCallback = nullptr; }
	if(poSourceVoice) 
	{
		poSourceVoice->DestroyVoice(); 
	}
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void Voice::SetVoice(Wave* wav)
{
	IXAudio2* pXAudio2 = AudioEngine::GetXAudio();
	assert(pXAudio2 != nullptr);
	assert(wav);

	// Save ref to wav & set buffer struct
	this->pWave = wav;
	buffer.AudioBytes = pWave->GetSize();
	buffer.pAudioData = pWave->GetData();
	buffer.Flags = XAUDIO2_END_OF_STREAM;

	// Create callback
	this->poCallback = new VoiceCallback();
	this->poCallback->SetVoice(this);

	// Create Source voice
	WAVEFORMATEXTENSIBLE& wfx = wav->GetFormat();
	check_xaudio_result(pXAudio2->CreateSourceVoice(
		&poSourceVoice,								// source voice
		&wfx.Format,								// source format
		0,											// flag -- define behavior
		2.0f,										// default max frequency 
		(IXAudio2VoiceCallback*)this->poCallback,	// callback
		nullptr,									// descr dest of voices for source
		nullptr));									// ptr to list strct descr effects
	assert(poSourceVoice != nullptr);

	// Queue buffer data
	check_xaudio_result(this->poSourceVoice->SubmitSourceBuffer(&buffer));
}

VoiceCallback* Voice::GetCallback()
{
	assert(this->poCallback);
	return this->poCallback;
}

XAUDIO2_VOICE_DETAILS Voice::QueryDetails()
{
	XAUDIO2_VOICE_DETAILS VoiceDetails{};
	this->poSourceVoice->GetVoiceDetails(&VoiceDetails);

	return VoiceDetails;
}

void Voice::Play()
{
	assert(poSourceVoice != nullptr);
	check_xaudio_result(poSourceVoice->Start(0));
}

void Voice::Pause()
{
	assert(poSourceVoice != nullptr);

	// stop consuming audio buffer
	check_xaudio_result(poSourceVoice->Stop());
}

void Voice::Stop()
{
	assert(poSourceVoice != nullptr);

	// Stop consuming buffers & remove from queue
	check_xaudio_result(poSourceVoice->Stop());
	check_xaudio_result(poSourceVoice->FlushSourceBuffers());
}

void Voice::Replay()
{
	assert(poSourceVoice != nullptr);

	// remove any possible queued audio
	check_xaudio_result(poSourceVoice->FlushSourceBuffers());

	// re-submit buffer info
	check_xaudio_result(poSourceVoice->SubmitSourceBuffer(&buffer));
	check_xaudio_result(poSourceVoice->Start(0));
}

void Voice::SetVolume(float volume)
{
	assert(poSourceVoice != nullptr);
	check_xaudio_result(poSourceVoice->SetVolume(volume));
}

void Voice::SetPan(unsigned int voiceChannels, unsigned int masterChannels, const float* outputs)
{
	assert(poSourceVoice != nullptr);
	check_xaudio_result(poSourceVoice->SetOutputMatrix(nullptr, voiceChannels, masterChannels, outputs));
}

void Voice::SetPitch(float frequency)
{
	assert(poSourceVoice != nullptr);
	check_xaudio_result(poSourceVoice->SetFrequencyRatio(frequency));
}

bool Voice::Compare(Node* pNode)
{
	AZUL_UNUSED_VAR(pNode);

	return false;
}
