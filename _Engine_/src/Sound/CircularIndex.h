#pragma once
#ifndef CIRCULAR_INDEX_H
#define CIRCULAR_INDEX_H

class CircularIndex
{
public:
	friend class CircularQueue;

	// deleted constructors
	CircularIndex() = delete;
	CircularIndex(const CircularIndex&) = delete;
	CircularIndex& operator=(const CircularIndex&) = delete;


private:
	unsigned int index;
	unsigned int size;
	unsigned int mask;

	CircularIndex(unsigned int _size);
	~CircularIndex();

	// postfix operator
	unsigned int operator++(int);
	bool operator==(const CircularIndex& tmp);
	bool operator !=(const CircularIndex& tmp);

	// accessor
	unsigned int Index() const;


};
#endif // !CIRCULAR_INDEX_H
