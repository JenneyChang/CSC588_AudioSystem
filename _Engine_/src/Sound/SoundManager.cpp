#include "SoundManager.h"
#include "QueueManager.h"

#include "CreateASound.h"

SoundManager* SoundManager::poInstance = nullptr;

//---------------------------------------------------------------
//	PRIVATE CONSTRUCTION
//---------------------------------------------------------------

SoundManager::SoundManager(int toReserve, int toGrow)
	: Manager(toGrow)
{ 
	// prefill reserve
	this->FillReserve(toReserve);

	// create comparison node
	this->poComparison = new Sound();
	assert(this->poComparison);
}

SoundManager::~SoundManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void SoundManager::Create(int toReserve, int toGrow)
{
	if (SoundManager::poInstance == nullptr)
	{
		poInstance = new SoundManager(toReserve, toGrow);
		assert(poInstance != nullptr);
	}
}

void SoundManager::Destroy()
{
	SoundManager* pManager = SoundManager::prInstance();
	assert(pManager);

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		Sound* temp = (Sound*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		Sound* temp = (Sound*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	delete pManager->poComparison;
	pManager->poComparison = nullptr;

	delete SoundManager::poInstance;
	SoundManager::poInstance = nullptr;
}

Sound* SoundManager::Add(Sound::ID id, PlaylistRef::ID refID, Playlist::ID playlistId, int priority, SoundCallback* pSndCB)
{
	SoundManager* pManager = SoundManager::prInstance();
	assert(pManager);

	// Grab node from pool
	Sound* pNode = (Sound*)pManager->baseAddToFront();
	assert(pNode);

	// Set data
	pNode->SetSound(id, priority);

	// Notify Audio create Asound equivalent
	Command* cmd = new CreateASound(pNode, refID, playlistId, pSndCB);
	assert(cmd);

	QueueManager::SendToAudio(cmd);

	return pNode;
}

void SoundManager::Remove(Sound* pSnd)
{
	SoundManager* pManager = SoundManager::prInstance();
	assert(pManager);
	assert(pSnd);

	// Notify Audio to remove ASound equivalent

	pManager->baseRemove(pSnd);
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* SoundManager::derivedCreateNode()
{
	Sound* pNode = new Sound();
	assert(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

SoundManager* SoundManager::prInstance()
{
	assert(SoundManager::poInstance != nullptr);
	return SoundManager::poInstance;
}