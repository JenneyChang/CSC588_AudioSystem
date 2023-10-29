#include "VoiceManager.h"
#include "WaveManager.h"


VoiceManager* VoiceManager::poInstance = nullptr;

//---------------------------------------------------------------
//	CONSTRUCTION
//---------------------------------------------------------------

VoiceManager::VoiceManager(int toReserve, int toGrow)
	: Manager(toGrow)
{
	// prefill reserve
	this->FillReserve(toReserve);

	// comparison node
	this->poComparison = new Voice();
	assert(this->poComparison);
}

VoiceManager::~VoiceManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------

void VoiceManager::Create(int toReserve, int toGrow)
{
	if (VoiceManager::poInstance == nullptr)
	{
		VoiceManager::poInstance = new VoiceManager(toReserve, toGrow);
		assert(VoiceManager::poInstance != nullptr);
	}
}

void VoiceManager::Destroy()
{
	VoiceManager* pManager = VoiceManager::prInstance();
	assert(pManager);

	//delete comparison node
	delete pManager->poComparison;
	pManager->poComparison = nullptr;

	//delete active list
	Iterator* it = pManager->baseGetActiveIterator();
	Node* pNode = it->First();
	while (!it->IsDone())
	{
		Voice* temp = (Voice*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	//delete reserve list
	it = pManager->baseGetReserveIterator();
	pNode = it->First();
	while (!it->IsDone())
	{
		Voice* temp = (Voice*)it->Curr();
		pNode = it->Next();

		delete temp;
	}

	// delete instance
	delete VoiceManager::poInstance;
	VoiceManager::poInstance = nullptr;
}

Voice* VoiceManager::Add(Wave::ID id)
{
	VoiceManager* pManager = VoiceManager::prInstance();
	assert(pManager);

	// pull node from pool
	Voice* pNode = (Voice*)pManager->baseAddToFront();
	assert(pNode);

	Wave* wav = WaveManager::Find(id);
	assert(wav);

	pNode->SetVoice(wav);

	return pNode;
}


//---------------------------------------------------------------
//	PROTECTED METHODS
//---------------------------------------------------------------

Node* VoiceManager::derivedCreateNode()
{
	Node* pNode = new Voice();
	assert(pNode);

	return pNode;
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

VoiceManager* VoiceManager::prInstance()
{
	assert(VoiceManager::poInstance != nullptr);
	return VoiceManager::poInstance;
}
