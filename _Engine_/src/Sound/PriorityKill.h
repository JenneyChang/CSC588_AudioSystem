#pragma once
#ifndef PRIORITY_KILL_H
#define PRIORITY_KILL_H

#include "Command.h"
#include "Sound.h"

class PriorityKill : public Command
{
public:
	// deleted functions
	PriorityKill(const PriorityKill&) = delete;
	PriorityKill& operator=(const PriorityKill&) = delete;

	PriorityKill(bool& flag, Sound* pSnd);
	~PriorityKill() = default;

	void Execute() override;


private:
	bool& killFlag;
	Sound* pSound;


};
#endif // !PRIORITY_KILL_H
