//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSTREE_ITERATOR_H
#define PCSTREE_ITERATOR_H

#include "PCSNode.h"

namespace Azul
{
	class PCSTreeIterator
	{
	public:
		virtual PCSNode* First() = 0;
		virtual PCSNode* Next() = 0;
		virtual bool IsDone() = 0;
		virtual PCSNode* CurrentItem() = 0;
	};
}

#endif

// ---  End of File ---------------
