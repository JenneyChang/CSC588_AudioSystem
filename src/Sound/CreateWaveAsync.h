#pragma once
#ifndef CREATE_WAVE_ASYNC_H
#define CREATE_WAVE_ASYNC_H

#include "Command.h"
#include "FileCallback.h"
#include "Wave.h"

class CreateWaveAsync : public Command
{
public:
	// deleted functions
	CreateWaveAsync() = delete;
	CreateWaveAsync(const CreateWaveAsync&) = delete;
	CreateWaveAsync& operator=(const CreateWaveAsync&) = delete;

	CreateWaveAsync(Wave::ID id, const char* const filename, FileCallback* callback);
	virtual ~CreateWaveAsync() = default;

	void Execute() override;


private:
	Wave::ID wavID;
	FileCallback* pCallback;
	const char* wavFile;


};
#endif // !CREATE_WAVE_ASYNC_H
