#include "SoundCallback.h"

SoundCallback::SoundCallback(SoundCallback::Type type)
	: cbType(type)
{ }

void SoundCallback::Start()
{ }

void SoundCallback::End()
{ }

void SoundCallback::Pause()
{ }

void SoundCallback::Stop()
{ }

void SoundCallback::PriorityKill()
{ }

void SoundCallback::Execute()
{
	switch (cbType)
	{
	case Type::START:
		Start();
		break;
	case Type::END:
		End();
		break;
	case Type::PAUSE:
		Pause();
		break;
	case Type::STOP:
		Stop();
		break;
	case Type::PRIORITY_KILL:
		PriorityKill();
		break;
	default:
		assert(false);
		break;
	}
}
