//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "InputMan.h"
#include "AudioEngine.h"
#include "KeyPress.h"

namespace Azul
{
	InputMan *InputMan::poInputMan = nullptr;

	//---------------------------------------------------------------------------
	//	PRIVATE CONSTRUCTION
	//---------------------------------------------------------------------------

	InputMan::InputMan()
	{
		this->poKeyboard = new Keyboard();
		assert(this->poKeyboard);

		this->poMouse = new Mouse();
		assert(this->poMouse);
	}

	InputMan::~InputMan()
	{ }


	//---------------------------------------------------------------------------
	//	PUBLIC STATIC METHODS
	//---------------------------------------------------------------------------

	void InputMan::Create()
	{
		InputMan::privCreate();
	}

	void InputMan::Destroy()
	{
		InputMan *pMan = InputMan::privInstance();
		assert(pMan);

		delete pMan->poMouse;
		delete pMan->poKeyboard;

		delete pMan->poInputMan;
	}

	void InputMan::Update()
	{ 
		InputMan* pManager = InputMan::privInstance();
		assert(pManager);

		if (pManager->poKeyboard->GetKeyPress(Keyboard::KEY_0))
		{
			AudioEngine::QuitFlag();
		}
	}

	Keyboard *InputMan::GetKeyboard()
	{
		InputMan *pMan = InputMan::privInstance();
		return pMan->poKeyboard;
	}

	Mouse *InputMan::GetMouse()
	{
		InputMan *pMan = InputMan::privInstance();
		return pMan->poMouse;
	}


	//---------------------------------------------------------------------------
	//	PRIVATE METHODS
	//---------------------------------------------------------------------------

	void InputMan::privCreate()
	{
		InputMan::poInputMan = new InputMan();
		assert(poInputMan);
	}

	InputMan *InputMan::privInstance()
	{
		assert(poInputMan);
		return poInputMan;
	}

}

// --- End of File ---
