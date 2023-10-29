#include "WaveManager.h"


WaveManager* WaveManager::poInstance = nullptr;

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

WaveManager::WaveManager(int toReserve, int toGrow)
	: Manager(toGrow)
{
	// prefill reserve
	this->FillReserve(toReserve);

	// create comparison node
	this->poComparison = new Wave();
	assert(this->poComparison);
}

WaveManager::~WaveManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void WaveManager::Create(int toReserve, int toGrow)
{
	if (WaveManager::poInstance == nullptr)
	{
		WaveManager::poInstance = new WaveManager(toReserve, toGrow);
		assert(WaveManager::poInstance != nullptr);
	}
}

void WaveManager::Destroy()
{
	WaveManager* pManager = WaveManager::prInstance();
	assert(pManager);

	//delete comparison node
	delete pManager->poComparison;
	pManager->poComparison = nullptr;

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		Wave* temp = (Wave*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		Wave* temp = (Wave*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	// instance
	delete WaveManager::poInstance;
	WaveManager::poInstance = nullptr;
}

Wave* WaveManager::Add(Wave::ID id, InternalFileCB* pFileCB)
{
	WaveManager* pManager = WaveManager::prInstance();
	assert(pManager);

	// grab node from pool
	Wave* pNode = (Wave*)pManager->baseAddToFront();
	assert(pNode);

	// set data
	pNode->Set(id, pFileCB);

	return pNode;
}

Wave* WaveManager::Add(Wave::ID id, FileCallback* callback)
{
	WaveManager* pManager = WaveManager::prInstance();
	assert(pManager);

	// grab node from pool
	Wave* pNode = (Wave*)pManager->baseAddToFront();
	assert(pNode);

	// set data
	pNode->Set(id, callback);

	return pNode;
}

Wave* WaveManager::Find(Wave::ID id)
{
	WaveManager* pManager = WaveManager::prInstance();
	assert(pManager);

	pManager->poComparison->SetID(id);
	Wave* pNode = (Wave*)pManager->baseFind(pManager->poComparison);

	return pNode;
}

void WaveManager::Remove(Wave* wav)
{
	WaveManager* pManager = WaveManager::prInstance();
	assert(pManager);
	assert(wav);

	pManager->baseRemove(wav);
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* WaveManager::derivedCreateNode()
{
	Node* pNode = new Wave();
	assert(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

WaveManager* WaveManager::prInstance()
{
	assert(WaveManager::poInstance);
	return WaveManager::poInstance;
}