#include "FileCallback.h"


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void FileCallback::Loaded()
{ 
	// does nothing, needs to be overridded
}

void FileCallback::Error()
{ 
	// does nothing, needs to be overridded
}

void FileCallback::Execute()
{
	Loaded();
	Error();
}
