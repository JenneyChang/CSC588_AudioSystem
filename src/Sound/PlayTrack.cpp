#include "PlayTrack.h"
#include "PlaylistManRef.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PlayTrack::PlayTrack(TrackCmd::Type inType, int trackNum)
	: TrackCmd(inType, trackNum)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PlayTrack::Execute()
{
	//Debug::out("PlayTrack::Execute()\n");

	// Should be set in playlist Copy
	assert(pVoice != nullptr);
	pVoice->Play();
}
