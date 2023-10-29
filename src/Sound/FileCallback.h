#pragma once
#ifndef FILE_CALLBACK_H
#define FILE_CALLBACK_H

#include "Command.h"

class FileCallback : public Command
{
public:
	// deleted functions
	FileCallback(const FileCallback&) = delete;
	FileCallback& operator=(const FileCallback&) = delete;

	FileCallback() = default;
	virtual ~FileCallback() = default;

	virtual void Loaded();
	virtual void Error();

	void Execute() override;


};
#endif // !FILE_CALLBACK_H
