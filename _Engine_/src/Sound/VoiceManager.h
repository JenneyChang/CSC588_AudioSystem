#pragma once
#ifndef VOICE_MANAGER_H
#define VOICE_MANAGER_H

#include "Manager.h"
#include "Voice.h"

class ASound;
class VoiceManager : public Manager
{
public:
	// deleted functions
	VoiceManager() = delete;
	VoiceManager(const VoiceManager&) = delete;
	VoiceManager& operator=(const VoiceManager&) = delete;

	static void Create(int toReserve = 2, int toGrow = 1);
	static void Destroy();

	static Voice* Add(Wave::ID id);


protected:
	Node* derivedCreateNode() override;


private:
	static VoiceManager* prInstance();

	VoiceManager(int toReserve, int toGrow);
	~VoiceManager();


private:
	static VoiceManager* poInstance;
	Voice* poComparison;


};
#endif // !VOICE_MANAGER_H
