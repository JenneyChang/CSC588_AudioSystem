#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
	// deleted functions
	Command(const Command&) = delete;
	Command& operator=(const Command&) = delete;

	Command() = default;
	virtual ~Command() = default;

	virtual void Execute() = 0;


};
#endif // !COMMAND_H
