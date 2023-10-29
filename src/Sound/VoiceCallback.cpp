#include "VoiceCallback.h"
#include "QueueManager.h"
#include "ASound.h"
#include "Voice.h"
#include "StreamEnd.h"
#include "SoundManager.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

VoiceCallback::VoiceCallback()
	: pASound(nullptr), pVoice(nullptr)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void VoiceCallback::SetVoice(Voice* voice)
{
	assert(voice);
	this->pVoice = voice;
}

void VoiceCallback::SetASnd(ASound* const pASnd)
{
	assert(pASnd);
	this->pASound = pASnd;
}

void VoiceCallback::SetData(ASound* pASnd, Voice* voice)
{
	assert(pASnd);
	assert(voice);
	this->pASound = pASnd;
	this->pVoice = voice;
}

void VoiceCallback::OnStreamEnd()
{
	//Debug::out("Voice Stream End\n");

	// Notify Audio voice finished playing
	Command* cmd = new StreamEnd(this->pASound, this->pVoice);
	QueueManager::SendToAudio(cmd);
}

void VoiceCallback::OnVoiceProcessingPassStart(UINT32) { }

void VoiceCallback::OnVoiceProcessingPassEnd() { }

void VoiceCallback::OnBufferStart(void*) { }

void VoiceCallback::OnBufferEnd(void*) { }

void VoiceCallback::OnLoopEnd(void*) { }

void VoiceCallback::OnVoiceError(void*, HRESULT) { }