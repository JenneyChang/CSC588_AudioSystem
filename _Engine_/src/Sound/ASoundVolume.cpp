#include "ASoundVolume.h"
#include "ASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

ASoundVolume::ASoundVolume(Sound* pSnd, float vol)
	: pSound(pSnd), volume(vol)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void ASoundVolume::Execute()
{
	//Debug::out("ASoundVolume::Execute()\n");

	ASound* pASound = this->pSound->GetASound();
	assert(pASound);

	pASound->SetVolume(this->volume);

	delete this;
}

