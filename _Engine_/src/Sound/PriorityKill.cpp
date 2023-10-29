#include "PriorityKill.h"
#include "ASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PriorityKill::PriorityKill(bool& flag, Sound* pSnd)
	: killFlag(flag), pSound(pSnd)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PriorityKill::Execute()
{
	//Debug::out("PriorityKill::Execute()\n");
	
	//	Grab ASound
	ASound* pASound = pSound->GetASound();
	assert(pASound);

	// Tell playlist to stop playing
	pASound->Stop();

	killFlag = true;

	delete this;
}