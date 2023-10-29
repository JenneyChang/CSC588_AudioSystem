#include "StreamEnd.h"
#include "QueueManager.h"
#include "SoundEnd.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

StreamEnd::StreamEnd(ASound* pASnd, Voice* voice)
	: pASound(pASnd), pVoice(voice)
{
	assert(pASnd);
	assert(voice);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void StreamEnd::Execute()
{
	//Debug::out("StreamEnd::Execute()\n");

	// Advance Playlist
	Playlist* pPlaylist = pASound->GetPlaylist();
	pPlaylist->AdvanceTrack();

	if (pPlaylist->Finished())
	{
		// Send command to Aux (update sound table)
		Command* cmd = new SoundEnd(this->pASound, this->pVoice);
		assert(cmd);

		QueueManager::SendToAux(cmd);

		// Update playlist status
		pPlaylist->SetStatus(Playlist::Status::ENDED);
	}
	else
	{
		// Play next track
		if (pPlaylist->GetStatus() == Playlist::Status::PLAYING)
		{
			pPlaylist->Play();
		}
		else if (pPlaylist->GetStatus() == Playlist::Status::REPLAY)
		{
			pPlaylist->Replay();
		}
	}

	delete this;
}