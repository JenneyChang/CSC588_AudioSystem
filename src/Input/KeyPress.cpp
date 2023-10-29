#include "KeyPress.h"
#include "InputMan.h"


namespace Azul
{
	//---------------------------------------------------------------------------
	//	CONSTRUCTION
	//---------------------------------------------------------------------------

	KeyPress::KeyPress(Keyboard::Key inKey)
		: key(inKey), isPressed(false)
	{ }

	KeyPress::~KeyPress()
	{ }


	//---------------------------------------------------------------------------
	//	PUBLIC METHODS
	//---------------------------------------------------------------------------

	Azul::KeyPress::operator bool()
	{
		Keyboard* pKeyboard = InputMan::GetKeyboard();

		if (pKeyboard->GetKeyPress(key))
		{
			isPressed = true;
		}
		if (isPressed && pKeyboard->GetKeyRelease(key))
		{
			isPressed = false;
			return true;
		}

		return false;
	}
}