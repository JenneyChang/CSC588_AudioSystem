#include "Demo1.h"
#include "DemoUtil.h"
#include "AnimTimer.h"
#include "AudioEngine.h"

using namespace Azul;

namespace Demos
{

	void Demo1()
	{
		SimpleBanner b;

		// Load Sound
		Sound* pWaterfall = AudioEngine::CreateSound(Sound::ID::WATERFALL, PlaylistRef::ID::WATERFALL, Playlist::ID::WATERFALL);
		Sound* pFiddle0 = AudioEngine::CreateSound(Sound::ID::FIDDLE, PlaylistRef::ID::FIDDLE, Playlist::ID::FIDDLE);
		Sound* pFiddle1 = AudioEngine::CreateSound(Sound::ID::FIDDLE, PlaylistRef::ID::FIDDLE, Playlist::ID::FIDDLE);
		Sound* pFiddle2 = AudioEngine::CreateSound(Sound::ID::FIDDLE, PlaylistRef::ID::FIDDLE, Playlist::ID::FIDDLE);

		pFiddle1->Pan(-1, 0);
		pFiddle2->Pan(0, 1);

		std::this_thread::sleep_for(1s);

		AnimTimer t1;
		t1.Tic();

		if (WaitForTime(t1, AnimTime(AnimTime::Duration::ZERO)))
		{
			Debug::out("0s --> Play Fiddle center\n");
			pFiddle0->Play();
		}

		if (WaitForTime(t1, 3 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("3s --> Play Fiddle left\n");
			pFiddle1->Play();
		}

		if (WaitForTime(t1, 6 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("6s --> Play Fiddle right\n");
			pFiddle2->Play();
		}

		if (WaitForTime(t1, 9 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("9s --> Play 2 Fiddles (Left and Right)\n");

			pFiddle1->Replay();
			pFiddle2->Replay();

			pFiddle1->SetVolume(0.5f);
			pFiddle2->SetVolume(0.5f);
		}

		if (WaitForTime(t1, 13 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("13s --> Play Waterfall\n");
			pWaterfall->Play();
		}

		if (WaitForTime(t1, 17 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("17s --> Pause Waterfall\n");
			pWaterfall->Pause();
		}

		if (WaitForTime(t1, 20 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("20s --> Change Volume and Play\n");
			pWaterfall->SetVolume(0.5f);
			pWaterfall->Play();
		}

		if (WaitForTime(t1, 23 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("23s --> Decrease Pitch\n");
			pWaterfall->Pitch(0.4f);
		}

		if (WaitForTime(t1, 26 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("26s --> Increase Pitch\n");
			pWaterfall->Pitch(1.5f);
		}

		if (WaitForTime(t1, 29 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("29s --> Regular Pitch\n");
			pWaterfall->Pitch(1.0f);
		}

		if (WaitForTime(t1, 31 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("31s --> Stop Waterfall\n");
			pWaterfall->Stop();
		}

		if (WaitForTime(t1, 33 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("33s --> Replay Waterfall\n");
			pWaterfall->Replay();
		}
	}
}
