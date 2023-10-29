#pragma once
#ifndef KEY_PRESS_H
#define KEY_PRESS_H

#include "Keyboard.h"

namespace Azul
{
	class KeyPress
	{
	public:
		KeyPress() = delete;
		KeyPress(const KeyPress&) = delete;
		KeyPress& operator=(const KeyPress&) = delete;

		KeyPress(Keyboard::Key inKey);
		~KeyPress();

		operator bool();


	private:
		Keyboard::Key key;
		bool isPressed;
		

	};

}
#endif // !KEY_PRESS_H
