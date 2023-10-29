#include "PlaylistRef.h"
#include "Playlist.h"
#include "VoiceManager.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PlaylistRef::PlaylistRef()
	: refID(PlaylistRef::ID::UNINITIALIZED), status(PlaylistRef::Status::UNINITIALIZED), pTrackList(nullptr), totalTracks(0)
{ }

PlaylistRef::~PlaylistRef()
{ 
	delete[] this->pTrackList;
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PlaylistRef::SetID(PlaylistRef::ID id)
{
	this->refID = id;
}

void PlaylistRef::SetStatus(PlaylistRef::Status _status)
{
	this->status = _status;
}

void PlaylistRef::SetRef(PlaylistRef::ID id, int totalNumTracks)
{
	this->refID = id;
	this->totalTracks = totalNumTracks;

	this->pTrackList = new Track[totalNumTracks]();
	assert(this->pTrackList);
}

unsigned int PlaylistRef::GetTrackTotal()
{
	return this->totalTracks;
}

void PlaylistRef::QueueTrack(Wave::ID wavId, TrackCmd::Type cmdType, int index)
{
	this->pTrackList[index].index = index;
	this->pTrackList[index].wavId = wavId;
	this->pTrackList[index].type = cmdType;
}

bool PlaylistRef::Compare(Node* pNode)
{
	assert(pNode);
	
	PlaylistRef* pRef = (PlaylistRef*)pNode;
	if (this->refID == pRef->refID)
	{
		return true;
	}

	return false;
}