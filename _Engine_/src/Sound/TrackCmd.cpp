#include "TrackCmd.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

TrackCmd::TrackCmd(TrackCmd::Type _type, unsigned int _index) 
	: type(_type), index(_index), pVoice(nullptr)
{ }