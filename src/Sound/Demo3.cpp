#include "Demo3.h"
#include "DemoUtil.h"
#include "LeftRightPan.h"
#include "RightLeftPan.h"
#include "RightLeftVol.h"
#include "LeftRightVol.h"
#include "AudioEngine.h"

namespace Demos
{
	void Demo3()
	{
		SimpleBanner b;

		Sound* pBeethoven = AudioEngine::CreateSound(Sound::ID::BEETHOVEN_LAENDLER, PlaylistRef::ID::BEETHOVEN_LAENDLER, Playlist::ID::BEETHOVEN_LAENDLER);
		std::this_thread::sleep_for(1s);

		AnimTimer t3;
		t3.Tic();

		if (WaitForTime(t3, AnimTime(AnimTime::Duration::ZERO)))
		{
			Debug::out("Play Beethoven Laendler\n");
			pBeethoven->SetVolume(1.0f);
			pBeethoven->Play();
		}
		if (WaitForTime(t3, 4 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Pan Hard Right\n");
			pBeethoven->Pan(0, 1);
		}
		if (WaitForTime(t3, 7 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Pan Hard Left\n");
			pBeethoven->Pan(1, 0);
		}
		if (WaitForTime(t3, 9 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Pan Left-->Right\n");

			std::thread t(Demos::LeftRightPan, std::ref(pBeethoven));
			Debug::SetName(t, "-LeftRightPan-");
			t.join();
		}
		if (WaitForTime(t3, 15 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Pan Right-->Left\n");

			std::thread t(Demos::RightLeftPan, std::ref(pBeethoven));
			Debug::SetName(t, "-RightLeftPan-");
			t.join();
		}
		if (WaitForTime(t3, 20 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Pan Hard Center\n");
			pBeethoven->Pan(1, 1);
		}

		if (WaitForTime(t3, 23 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Volume 100-->0\n");

			std::thread t(Demos::RightLeftVol, std::ref(pBeethoven));
			Debug::SetName(t, "-RightLeftVol-");
			t.join();
		}
		if (WaitForTime(t3, 29 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("Volume 0-->100\n");

			std::thread t(Demos::LeftRightVol, std::ref(pBeethoven));
			Debug::SetName(t, "-LeftRightVol-");
			t.join();
		}
		
	}
}