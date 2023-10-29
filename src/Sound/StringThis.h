//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STRING_THIS_H
#define STRING_THIS_H

#include "WaveTable.h"
#include "Handle.h"
#include "Sound.h"


class StringThis
{
public:
	static const unsigned int BUFFER_SIZE = 64;
public:
	StringThis(int x);
	StringThis(Wave::ID id);
	StringThis(WaveTable::Status status);
	StringThis(Handle::Status status);
	StringThis(Sound::ID id);
	StringThis(Sound::Status status);

	operator char* ();

	// data:
	char buffer[BUFFER_SIZE];
};

#define StringMe(x)  ((char *)StringThis(x)) 

#endif

// --- End of File ---
