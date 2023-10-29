#include "Sound.h"
#include "StringThis.h"
#include "AudioEngine.h"
#include "QueueManager.h"

#include "ASound.h"
#include "PlayASound.h"
#include "PauseASound.h"
#include "StopASound.h"
#include "ASoundVolume.h"
#include "PanASound.h"
#include "PitchASound.h"
#include "ReplayASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

Sound::Sound()
	: handle(), soundID(ID::UNINITIALIZED), pASound(nullptr)
{ }

Sound::~Sound()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

Handle::Status Sound::SetStatus(Sound::Status newStatus)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->status = newStatus;
	}

	return lock;
}

Sound::Status Sound::GetStatus()
{
	return this->status;
}

Sound::ID Sound::GetID()
{
	return this->soundID;
}

Handle::Status Sound::SetPriority(unsigned int _priority)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->priority = _priority;

		// Is this sound active?
		SoundTable* pTable = AudioEngine::GetSoundTable();
		pTable->Update(this);
	}

	return lock;
}

int Sound::GetPriority()
{
	return this->priority;
}

Handle::Status Sound::Play()
{
	Handle::Lock lock(this->handle);

	if (lock)
	{		
		if (this->status == Sound::Status::READY)
		{
			// Check table before play
			SoundTable* pTable = AudioEngine::GetSoundTable();
			if (pTable->QueryTable(this->priority))
			{
				//Create PlaySound Command 
				Command* cmd = new PlayASound(this->soundID, this);
				assert(cmd);

				//Send Command over to Audio to execute 
				QueueManager::SendToAudio(cmd);
			}
			else
			{
				this->status = Sound::Status::REJECTED;
				Debug::out("%-10s: %s\n", StringMe(soundID), StringMe(status));
			}
		}
		else if (this->status == Sound::Status::PAUSED)
		{
			//Create PlaySound Command 
			Command* cmd = new PlayASound(this->soundID, this);
			assert(cmd);

			//Send Command over to Audio to execute 
			QueueManager::SendToAudio(cmd);
		}
		else
		{
			assert(false);
		}
	}

	return lock;
}

Handle::Status Sound::Pause()
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		// can't pause a non-playing sound
		assert(this->status == Sound::Status::PLAYING);

		// Create PauseASound Command
		Command* cmd = new PauseASound(this);
		assert(cmd);

		// Send command to Audio to execute
		QueueManager::SendToAudio(cmd);
	}

	return lock;
}

Handle::Status Sound::Stop()
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		if (this->status == Sound::Status::PLAYING || this->status == Sound::Status::PAUSED)
		{
			Command* cmd = new StopASound(this);
			assert(cmd);

			QueueManager::SendToAudio(cmd);
		}
	}

	return lock;
}

Handle::Status Sound::Replay()
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		if (this->status == Sound::Status::STOPPED || this->status == Sound::Status::PAUSED)
		{
			Command* cmd = new ReplayASound(this);
			assert(cmd);

			QueueManager::SendToAudio(cmd);
		}
	}

	return lock;
}

Handle::Status Sound::SetVolume(float vol)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		Command* cmd = new ASoundVolume(this, vol);
		assert(cmd);

		QueueManager::SendToAudio(cmd);
	}

	return lock;
}

Handle::Status Sound::Pan(float left, float right)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		Command* cmd = new PanASound(this, left, right);
		assert(cmd);

		QueueManager::SendToAudio(cmd);
	}

	return lock;
}

Handle::Status Sound::Pitch(float freq)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		Command* cmd = new PitchASound(this, freq);
		assert(cmd);

		QueueManager::SendToAudio(cmd);
	}

	return lock;
}

bool Sound::Compare(Node* pNode)
{
	assert(pNode);
	Sound* tmp = (Sound*)pNode;

	return (this->handle == tmp->handle);
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Handle::Status Sound::SetSound(Sound::ID id, int _priority)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		this->soundID = id;
		this->priority = _priority;
		this->status = Sound::Status::LOADING;
	}

	return lock;
}

Handle::Status Sound::SetASound(ASound* const pASnd)
{
	Handle::Lock lock(this->handle);

	if (lock)
	{
		assert(pASnd);
		this->pASound = pASnd;
	}

	return lock;
}

ASound* Sound::GetASound()
{
	return this->pASound;
}
