#include "RightLeftPan.h"
#include "DemoUtil.h"
#include "Sound.h"


namespace Demos
{
	void RightLeftPan(Sound* snd)
	{
		SimpleBanner b;

		// Panning values
		float pan(0.0f);
		float left(0.0f);
		float right(0.0f);

		// Time markers
		AnimTimer t3;
		AnimTime totalTime = AnimTime(AnimTime::Duration::ONE_SECOND) * 2;
		AnimTime timeElapsed(AnimTime::Duration::ZERO);

		float tElapsed = (float)AnimTime::Quotient(timeElapsed, AnimTime(AnimTime::Duration::ONE_MILLISECOND));
		float tTotal = (float)AnimTime::Quotient(totalTime, AnimTime(AnimTime::Duration::ONE_MILLISECOND));
		float ratio = 0.0f;

		while (timeElapsed <= totalTime)
		{
			t3.Tic();

			if (AnimTime::Remainder(timeElapsed, 10 * AnimTime(AnimTime::Duration::ONE_MILLISECOND)) == AnimTime(AnimTime::Duration::ZERO))
			{
				tElapsed = (float)AnimTime::Quotient(timeElapsed, AnimTime(AnimTime::Duration::ONE_MILLISECOND));
				ratio = tElapsed / tTotal;
				//Debug::out("Elapsed time: %fms\n", tElapsed);

				pan = Lerp(1.0f, -1.0f, ratio);
				UpdatePan(pan, left, right);
				//Debug::out("left[%0.2f]\tright[%0.2f]\n", left, right);
				snd->Pan(left, right);
			}

			timeElapsed += t3.Toc();
		}
	}
}