#include "DemoUtil.h"

namespace Demos
{
	bool Demos::WaitForTime(AnimTimer& t, AnimTime triggerTime)
	{
		AnimTime delta(AnimTime::Duration::ZERO);

		if (delta != triggerTime)
		{
			while (!AnimTime::Quotient(delta, triggerTime))
			{
				// spin
				delta = t.Toc();
			}
		}

		return true;
	}

	float Demos::Lerp(float A, float B, float t)
	{
		return (A + t * (B - A));
	}

	void Demos::UpdatePan(float pan, float& A, float& B)
	{
		// Note: -1 = A only and 1 = B only
		A = 0.5f - pan * 0.5f;
		B = 0.5f + pan * 0.5f;
	}
}