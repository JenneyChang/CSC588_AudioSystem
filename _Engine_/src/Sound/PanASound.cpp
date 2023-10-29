#include "PanASound.h"
#include "ASound.h"


//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PanASound::PanASound(Sound* pSnd, float inleft, float inright)
	: pSound(pSnd), left(inleft), right(inright)
{
	assert(pSnd);
}


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PanASound::Execute()
{
	//Debug::out("PanASound::Execute()\n");

	ASound* pASnd = pSound->GetASound();
	assert(pASnd);

	pASnd->Pan(left, right);

	delete this;
}


