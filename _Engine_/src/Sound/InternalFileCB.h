#pragma once
#ifndef INTERNAL_FILECB_H
#define INTERNAL_FILECB_H

#include "Command.h"

// Internal File Callback
class InternalFileCB : public Command
{
public:
	// deleted functions
	InternalFileCB() = delete;
	InternalFileCB(const InternalFileCB&) = delete;
	InternalFileCB& operator=(const InternalFileCB&) = delete;


	InternalFileCB(bool& doneFlag);
	~InternalFileCB() = default;

	void Execute() override;


private:
	bool& isDone;


};
#endif // !INTERNAL_FILECB_H
