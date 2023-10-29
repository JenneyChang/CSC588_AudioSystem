#pragma once
#ifndef CREATE_WAVE_H
#define CREATE_WAVE_H

#include "Command.h"
#include "InternalFileCB.h"
#include "Wave.h"

class CreateWave : public Command
{
public:
	// deleted functions
	CreateWave() = delete;
	CreateWave(const CreateWave&) = delete;
	CreateWave& operator=(const CreateWave&) = delete;

	CreateWave(Wave::ID id, const char* const filename, InternalFileCB* pFileCB);
	virtual ~CreateWave() = default;

	void Execute() override;


private:
	Wave::ID wavID;
	InternalFileCB* pCallback;
	const char* wavFile;
	

};
#endif // !CREATE_WAVE_H
