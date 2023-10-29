#include "UserFileCallback.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

UserFileCallback::UserFileCallback(bool& loadFlag)
	: flag(loadFlag)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void UserFileCallback::Loaded()
{
	Debug::out("User FileCallback--> FILE LOADED \n");

	this->flag = true;
}