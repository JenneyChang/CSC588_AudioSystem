#include "ASoundManager.h"
#include "PlaylistManager.h"
#include "PlaylistManRef.h"
#include "SoundManager.h"

ASoundManager* ASoundManager::poInstance = nullptr;

//---------------------------------------------------------------
//	PRIVATE CONSTRUCTION
//---------------------------------------------------------------

ASoundManager::ASoundManager(int toReserve, int toGrow)
	: Manager(toGrow)
{
	// prefill reserve
	this->FillReserve(toReserve);
}

ASoundManager::~ASoundManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void ASoundManager::Create(int toReserve, int toGrow)
{
	if (poInstance == nullptr)
	{
		poInstance = new ASoundManager(toReserve, toGrow);
		assert(poInstance != nullptr);
	}
}

void ASoundManager::Destroy()
{
	ASoundManager* pManager = ASoundManager::prInstance();
	assert(pManager);

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		ASound* temp = (ASound*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		ASound* temp = (ASound*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	delete ASoundManager::poInstance;
	ASoundManager::poInstance = nullptr;
}

ASound* ASoundManager::Add(Sound* pSound, PlaylistRef::ID refId, Playlist::ID playlistID, SoundCallback* pCallback)
{
	ASoundManager* pManager = ASoundManager::prInstance();
	assert(pManager);
	assert(pSound);

	// Grab ASound node from reserve pool
	ASound* pNode = (ASound*)pManager->baseAddToFront();
	assert(pNode);

	// find playlist ref
	PlaylistRef* pPlaylistRef = PlaylistManRef::Find(refId);
	assert(pPlaylistRef);

	// Copy playlist...
	Playlist* pPlaylist = PlaylistManager::Add(pPlaylistRef, playlistID);
	assert(pPlaylist);

	// Set ASound data
	pNode->Set(pSound, pPlaylist, pCallback);

	// playlist callback data
	pPlaylist->SetASound(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* ASoundManager::derivedCreateNode()
{
	ASound* pNode = new ASound();
	assert(pNode);

	return pNode;
}

ASoundManager* ASoundManager::prInstance()
{
	assert(poInstance != nullptr);
	return poInstance;
}

