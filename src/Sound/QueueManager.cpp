#include "QueueManager.h"


//---------------------------------------------------------------
//	PRIVATE CONSTRUCTION
//---------------------------------------------------------------

QueueManager::QueueManager()
	: toMain(nullptr), toAudio(nullptr), toFile(nullptr), toAux(nullptr)
{ }

QueueManager::~QueueManager()
{ }


//---------------------------------------------------------------
//	PUBLIC METHODS
//---------------------------------------------------------------
void QueueManager::Create()
{
	// Create Instance 
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	// Create Queues
	pManager->toMain = new CircularQueue();
	assert(pManager->toMain);

	pManager->toAudio = new CircularQueue();
	assert(pManager->toAudio);

	pManager->toFile = new CircularQueue();
	assert(pManager->toFile);

	pManager->toAux = new CircularQueue();
	assert(pManager->toAux);
}

void QueueManager::Destroy()
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	// should flush queues before exit?
	if (!pManager->toMain->IsEmpty()) { pManager->Flush(pManager->toMain); }
	delete pManager->toMain;

	if (!pManager->toAudio->IsEmpty()) { pManager->Flush(pManager->toAudio); }
	delete pManager->toAudio;

	if (!pManager->toFile->IsEmpty()) { pManager->Flush(pManager->toFile); }
	delete pManager->toFile;

	if (!pManager->toAux->IsEmpty()) { pManager->Flush(pManager->toAux); }
	delete pManager->toAux;
}

CircularQueue* QueueManager::GetMain()
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	return pManager->toMain;
}

CircularQueue* QueueManager::GetAudio()
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	return pManager->toAudio;
}

CircularQueue* QueueManager::GetFile()
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	return pManager->toFile;
}

CircularQueue* QueueManager::GetAux()
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);

	return pManager->toAux;
}

void QueueManager::SendToMain(Command* cmd)
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);
	assert(cmd);

	pManager->toMain->Push(cmd);
}

void QueueManager::SendToAudio(Command* cmd)
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);
	assert(cmd);

	pManager->toAudio->Push(cmd);
}

void QueueManager::SendToFile(Command* cmd)
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);
	assert(cmd);

	pManager->toFile->Push(cmd);
}

void QueueManager::SendToAux(Command* cmd)
{
	QueueManager* pManager = QueueManager::prInstance();
	assert(pManager);
	assert(cmd);

	pManager->toAux->Push(cmd);
}


//---------------------------------------------------------------
//	PRIVATE METHODS
//---------------------------------------------------------------

QueueManager* QueueManager::prInstance()
{
	static QueueManager poInstance;
	return &poInstance;
}

void QueueManager::Flush(CircularQueue* queue)
{
	while (!queue->IsEmpty())
	{
		Command* cmd = nullptr;
		queue->Pop(cmd);

		delete cmd;
	}
}