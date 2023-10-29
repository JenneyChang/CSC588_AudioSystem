#include "Playlist.h"
#include "VoiceManager.h"
#include "ASound.h"
#include "AudioEngine.h"

#include <x3daudio.h>
#include "StringThis.h"
#include "PlaylistRef.h"
#include "VoiceCallback.h"

#include "PlayTrack.h"

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Playlist::Playlist()
{ 
	playlistID = Playlist::ID::UNINITIALIZED;
	status = Playlist::Status::UNINITIALIZED;
	pTrackList = nullptr;
	currTrack = 0;
	totalTracks = 0;
	pASound = nullptr;
}

Playlist::~Playlist()
{ 
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		delete this->pTrackList[i].pCmd;
		this->pTrackList[i].pCmd = nullptr;
	}
	delete pTrackList;
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void Playlist::SetStatus(Playlist::Status newStatus)
{
	this->status = newStatus;
}

Playlist::Status Playlist::GetStatus()
{
	return this->status;
}

void Playlist::SetASound(ASound* pASnd)
{
	assert(pASnd);
	this->pASound = pASnd;
	
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		this->pTrackList[i].pVoice->GetCallback()->SetASnd(pASnd);
	}
}

void Playlist::SetPlaylist(PlaylistRef* ref, Playlist::ID id)
{
	assert(ref);

	// playlist info
	this->playlistID = id;
	this->totalTracks = ref->GetTrackTotal();
	
	// create copy of original playlist
	this->pTrackList = new Track[totalTracks]();
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		// creates new xaudio2 voice...sigh
		pTrackList[i].pVoice = VoiceManager::Add(ref->pTrackList[i].wavId);

		// copy command & set ref to voice
		pTrackList[i].pCmd = CreateCommand(ref->pTrackList[i].type, i);
		pTrackList[i].pCmd->pVoice = pTrackList[i].pVoice;
	}

	this->status = Playlist::Status::READY;
}

void Playlist::Play()
{
	// shouldn't play if playlist hasn't been loaded
	if (this->status == Playlist::Status::READY)
	{
		// Start current track & Update status
		this->pTrackList[currTrack].pCmd->Execute();
		this->status = Status::PLAYING;
	}
	else 
	{
		this->pTrackList[currTrack].pVoice->Play();
		this->status = Status::PLAYING;
	}
}

void Playlist::Pause()
{
	// shouldn't stop a playlist that isn't playing...
	assert(this->status == Playlist::Status::PLAYING);

	// Stop playing current track & update status
	this->pTrackList[currTrack].pVoice->Pause();
	this->status = Status::PAUSED;
}

void Playlist::Stop()
{
	// shouldn't stop a playlist that isn't playing...
	assert(this->status == Playlist::Status::PLAYING || this->status == Playlist::Status::PAUSED);

	// Stop playing current track & update status
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		this->pTrackList[currTrack].pVoice->Stop();
	}
	this->status = Status::ENDED;
}

void Playlist::Replay()
{
	assert(this->status == Playlist::Status::ENDED || this->status == Playlist::Status::REPLAY);
	
	this->pTrackList[currTrack].pVoice->Replay();
	this->status = Status::REPLAY;
}

void Playlist::SetVolume(float vol)
{
	// change volume for whole playlist
	// Note: volume = 1.0f means there is no attenuation or gain, 0.0f = silence
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		this->pTrackList[currTrack].pVoice->SetVolume(vol);
	}
}

void Playlist::Pan(float left, float right)
{
	IXAudio2MasteringVoice* pMasterVoice = AudioEngine::GetMasterVoice();
	assert(pMasterVoice);

	// Get speaker config
	DWORD dwChannelMask{};
	pMasterVoice->GetChannelMask(&dwChannelMask);

	XAUDIO2_VOICE_DETAILS masterVoiceDetails{};
	pMasterVoice->GetVoiceDetails(&masterVoiceDetails);

	// Array to hold output (min size is num channels in source voice * channels in output voice)
	// Hard set for stereo...
	float outputMatrix[16]{0.0f};
	outputMatrix[0] = outputMatrix[1] = left;
	outputMatrix[2] = outputMatrix[3] = right;

	// pan whole playlist... 
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		XAUDIO2_VOICE_DETAILS VoiceDetails = this->pTrackList[i].pVoice->QueryDetails();
		this->pTrackList[i].pVoice->SetPan(VoiceDetails.InputChannels, masterVoiceDetails.InputChannels, outputMatrix);
	}
}

void Playlist::Pitch(float freq)
{
	// range: 1/1,024 (down 10 octaves) - 1,024/1 (up 10 octaves)
	// change pitch for whole playlist
	for (unsigned int i = 0; i < totalTracks; ++i)
	{
		this->pTrackList[i].pVoice->SetPitch(freq);
	}
}

bool Playlist::Finished()
{
	return (currTrack == totalTracks);
}

void Playlist::ResetTrack()
{
	this->currTrack = 0;
}

void Playlist::AdvanceTrack()
{
	this->currTrack++;
}

bool Playlist::Compare(Node* pNode)
{
	AZUL_UNUSED_VAR(pNode);
	assert(false);

	return false;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

TrackCmd* Playlist::CreateCommand(TrackCmd::Type type, int index)
{
	TrackCmd* cmd = nullptr;
	
	switch (type)
	{
	case TrackCmd::Type::PLAY:
		cmd = new PlayTrack(type, index);
		break;
	case TrackCmd::Type::STOP:
		break;
	case TrackCmd::Type::UNINITIALIZED:
		break;
	default:
		assert(false);
		break;
	}

	return cmd;
}