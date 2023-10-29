#pragma once
#ifndef DEMO_UTIL_H
#define DEMO_UTIL_H

#include "AnimTimer.h"

using namespace Azul;

namespace Demos
{
	bool WaitForTime(AnimTimer& t, AnimTime triggerTime);

	float Lerp(float A, float B, float t);
	void UpdatePan(float pan, float& A, float& B);

}
#endif // !DEMO_UTIL_H
