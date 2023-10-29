#include "PlaylistManager.h"
#include "PlaylistManRef.h"
#include "VoiceManager.h"
#include "WaveManager.h"

PlaylistManager* PlaylistManager::poInstance = nullptr;

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

PlaylistManager::PlaylistManager(int toReserve, int toGrow)
	: Manager(toGrow)
{
	// prefill reserve
	this->FillReserve(toReserve);

	// comparison node
	this->poComparison = new Playlist();
	assert(this->poComparison);
}

PlaylistManager::~PlaylistManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PlaylistManager::Create(int toReserve, int toGrow)
{
	if (PlaylistManager::poInstance == nullptr)
	{
		poInstance = new PlaylistManager(toReserve, toGrow);
		assert(poInstance != nullptr);
	}
}

void PlaylistManager::Destroy()
{
	PlaylistManager* pManager = PlaylistManager::prInstance();
	assert(pManager);

	delete pManager->poComparison;
	pManager->poComparison = nullptr;

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		Playlist* temp = (Playlist*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		Playlist* temp = (Playlist*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	delete PlaylistManager::poInstance;
	PlaylistManager::poInstance = nullptr;
}

Playlist* PlaylistManager::Add(PlaylistRef* pPlaylistRef, Playlist::ID id)
{
	PlaylistManager* pManager = PlaylistManager::prInstance();
	assert(pManager);
	assert(pPlaylistRef);

	// pull from pool
	Playlist* pNode = (Playlist*)pManager->baseAddToFront();
	assert(pNode);

	// set data
	pNode->SetPlaylist(pPlaylistRef, id);

	return pNode;
}

void PlaylistManager::Remove(Playlist* pPlaylist)
{
	PlaylistManager* pManager = PlaylistManager::prInstance();
	assert(pManager);
	assert(pPlaylist);

	// TODO
	//pPlaylist->ClearTracks();
	pManager->baseRemove(pPlaylist);
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* PlaylistManager::derivedCreateNode()
{
	Node* pNode = new Playlist();
	assert(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

PlaylistManager* PlaylistManager::prInstance()
{
	assert(poInstance != nullptr);
	return poInstance;
}