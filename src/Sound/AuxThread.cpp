#include "AuxThread.h"
#include "QueueManager.h"


using namespace ThreadFramework;

void AuxThread(std::atomic_bool& quitFlag)
{
	SimpleBanner b;

	// Get Aux Queue
	CircularQueue* toAux = QueueManager::GetAux();
	assert(toAux);

	// Process incoming messages
	while (!quitFlag.load())
	{
		Command* cmd = nullptr;
		if (toAux->Pop(cmd))
		{
			assert(cmd);
			cmd->Execute();
		}
	}
}