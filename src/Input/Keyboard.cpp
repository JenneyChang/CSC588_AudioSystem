//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GameMan.h"
#include "Keyboard.h"

namespace Azul
{
	// Use this to read keyboard
	bool Keyboard::GetKeyPress(Keyboard::Key key)
	{
		Game *pGame = GameMan::GetGame();
		if(pGame->GetKey(key) == GLFW_PRESS)
		{
			return true;
		}

		return false;
	}

	bool Azul::Keyboard::GetKeyRelease(Key key)
	{
		Game* pGame = GameMan::GetGame();
		if (pGame->GetKey(key) == GLFW_RELEASE)
		{
			return true;
		}

		return false;
	}
}

// --- End of File ---
