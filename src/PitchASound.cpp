#include "PitchASound.h"
#include "ASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PitchASound::PitchASound(Sound* pSnd, float freq)
	: pSound(pSnd), frequency(freq)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PitchASound::Execute()
{
	//Debug::out("PitchASound::Execute()\n");

	ASound* pASnd = pSound->GetASound();
	assert(pASnd);

	pASnd->Pitch(frequency);

	delete this;
}
