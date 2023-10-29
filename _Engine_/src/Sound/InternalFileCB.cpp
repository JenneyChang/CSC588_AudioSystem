#include "InternalFileCB.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

InternalFileCB::InternalFileCB(bool& doneFlag)
	: isDone(doneFlag)
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void InternalFileCB::Execute()
{
	//Debug::out("Internal File Callback::Execute\n");

	this->isDone = true;
}