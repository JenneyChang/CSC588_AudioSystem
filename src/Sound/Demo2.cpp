#include "Demo2.h"
#include "DemoUtil.h"
#include "AudioEngine.h"

using namespace Azul;

namespace Demos
{
	void Demo2()
	{
		SimpleBanner b;

		// Load Sound
		Sound* pSeinfeld = AudioEngine::CreateSound(Sound::ID::SEINFELD, PlaylistRef::ID::SEINFELD, Playlist::ID::SEINFELD);

		std::this_thread::sleep_for(1s);

		// Play stitched sound
		pSeinfeld->Play();


		// Start timer
		AnimTimer t2;
		t2.Tic();

		if (WaitForTime(t2, 10 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("10s --> Pan Left\n");
			pSeinfeld->Pan(1, 0);
		}

		if (WaitForTime(t2, 20 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("20s --> Pan Right\n");
			pSeinfeld->Pan(0, 1);
		}

		if (WaitForTime(t2, 30 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("30s --> Pan Center\n");
			pSeinfeld->Pan(1, 1);
		}

		if (WaitForTime(t2, 40 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("40s --> Pan Left\n");
			pSeinfeld->Pan(1, 0);
		}

		if (WaitForTime(t2, 50 * AnimTime(AnimTime::Duration::ONE_SECOND)))
		{
			Debug::out("50s --> Pan Right\n");
			pSeinfeld->Pan(0, 1);
		}

	}
}