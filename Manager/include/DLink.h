#ifndef DLINK_H
#define DLINK_H

#include "Node.h"

class DLink : public Node
{
public:
	// disabled
	DLink(const DLink&) = delete;
	DLink& operator=(const DLink&) = delete;

	DLink();	
	virtual ~DLink() = default;

	//mandatory overloads
	void ResetLink() override;
	void PrintLink() override;

	DLink* pNext;
	DLink* pPrev;

};

#endif // !DLINK_H
