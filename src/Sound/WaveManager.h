#pragma once
#ifndef WAVE_MANAGER_H
#define WAVE_MANAGER_H

#include "Manager.h"
#include "Wave.h"

class InternalFileCB;
class FileCallback;
class WaveManager : public Manager
{
public:
	// deleted functions
	WaveManager() = delete;
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator=(const WaveManager&) = delete;

	static void Create(int toReserve = 2, int toGrow = 1);
	static void Destroy();

	static Wave* Add(Wave::ID id, InternalFileCB* callback);
	static Wave* Add(Wave::ID id, FileCallback* callback);
	static void Remove(Wave* wav);
	static Wave* Find(Wave::ID id);


protected:
	Node* derivedCreateNode() override;


private:
	WaveManager(int toReserve, int toGrow);
	~WaveManager();

	static WaveManager* prInstance();


private:
	static WaveManager* poInstance;
	Wave* poComparison;


};
#endif // !WAVE_MANAGER_H
