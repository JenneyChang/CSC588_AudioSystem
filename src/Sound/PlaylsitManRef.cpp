#include "PlaylistManRef.h"


PlaylistManRef* PlaylistManRef::poInstance = nullptr;

//---------------------------------------------------------------
//	PRIVATE CONSTRUCTION
//---------------------------------------------------------------

PlaylistManRef::PlaylistManRef(int toReserve, int toGrow)
	: Manager(toGrow)
{
	// prefill reserve
	this->FillReserve(toReserve);

	this->poComparison = new PlaylistRef();
	assert(this->poComparison);
}

PlaylistManRef::~PlaylistManRef()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void PlaylistManRef::Create(int toReserve, int toGrow)
{
	if (poInstance == nullptr)
	{
		poInstance = new PlaylistManRef(toReserve, toGrow);
		assert(poInstance != nullptr);
	}
}

void PlaylistManRef::Destroy()
{
	PlaylistManRef* pManager = PlaylistManRef::prInstance();
	assert(pManager);

	delete pManager->poComparison;
	pManager->poComparison = nullptr;

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		PlaylistRef* temp = (PlaylistRef*)it->Curr();
		pNode = it->Next();

		//temp->ClearTracks();
		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		PlaylistRef* temp = (PlaylistRef*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	delete PlaylistManRef::poInstance;
	PlaylistManRef::poInstance = nullptr;
}

PlaylistRef* PlaylistManRef::Add(PlaylistRef::ID id, int totalNumTracks)
{
	PlaylistManRef* pManager = PlaylistManRef::prInstance();
	assert(pManager);

	// Grab node from pool
	PlaylistRef* pNode = (PlaylistRef*)pManager->baseAddToFront();
	assert(pNode);

	// set playlist ID
	pNode->SetRef(id, totalNumTracks);

	return pNode;
}

PlaylistRef* PlaylistManRef::Find(PlaylistRef::ID id)
{
	PlaylistManRef* pManager = PlaylistManRef::prInstance();
	assert(pManager);

	pManager->poComparison->SetID(id);
	PlaylistRef* pNode = (PlaylistRef*)pManager->baseFind(pManager->poComparison);

	return pNode;
}

//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* PlaylistManRef::derivedCreateNode()
{
	PlaylistRef* pNode = new PlaylistRef();
	assert(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

PlaylistManRef* PlaylistManRef::prInstance()
{
	assert(PlaylistManRef::poInstance != nullptr);
	return PlaylistManRef::poInstance;
}