#pragma once
#ifndef DEBUG_UTILITY_H
#define DEBUG_UTILITY_H

#include "StringThis.h"

static void check_xaudio_result(HRESULT hr)
{
	if (hr == S_OK) { return; }
	if (hr > 0)
	{
		Debug::out("Error %d : %s\n", hr, StringThis((int)hr));
		assert(false);
	}
}

#endif // !DEBUG_UTILITY_H
