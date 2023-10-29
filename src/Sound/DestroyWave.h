#pragma once
#ifndef DESTROY_WAVE_H
#define DESTROY_WAVE_H

#include "Command.h"
#include "Wave.h"

class DestroyWave : public Command
{
public:
	// deleted functions
	DestroyWave() = delete;
	DestroyWave(const DestroyWave&) = delete;
	DestroyWave& operator=(const DestroyWave&) = delete;

	DestroyWave(Wave::ID id);
	~DestroyWave() = default;

	void Execute() override;


private:
	Wave::ID wavId;


};
#endif // !DESTROY_WAVE_H
