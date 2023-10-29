#include "CircularIndex.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

CircularIndex::CircularIndex(unsigned int _size)
	: index(0), size(_size), mask((unsigned int)_size - 1)
{
	// verify buffer size is power of 2
	assert((size & (size - 1)) == 0);
}

CircularIndex::~CircularIndex()
{ }


//---------------------------------------------------------------
//	OVERLOADED OPERATORS
//---------------------------------------------------------------

unsigned int CircularIndex::operator++(int)
{
	//this->index++;
	//
	//// Circular 
	//this->index = this->index & this->mask;
	//
	//return this->index;

	return this->index = this->index++ & (int)this->mask;
}


bool CircularIndex::operator==(const CircularIndex& tmp)
{
	assert(this->size == tmp.size);
	return (this->index == tmp.index);
}

bool CircularIndex::operator!=(const CircularIndex& tmp)
{
	assert(this->size == tmp.size);
	return (this->index != tmp.index);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

unsigned int CircularIndex::Index() const
{
	return this->index;
}
