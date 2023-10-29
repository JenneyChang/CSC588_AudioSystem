#include "FileThread.h"
#include "QueueManager.h"


using namespace ThreadFramework;

void FileThread(std::atomic_bool& quitFlag)
{
	SimpleBanner b;

	// Get File Queue
	CircularQueue* toFile = QueueManager::GetFile();
	assert(toFile);

	// Process any messages that come to File Thread
	while (!quitFlag.load())
	{
		Command* cmd = nullptr;
		if (toFile->Pop(cmd))
		{
			assert(cmd);
			cmd->Execute();
		}
	}
	
}