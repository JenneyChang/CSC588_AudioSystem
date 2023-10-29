#pragma once
#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include "CircularQueue.h"
#include "Command.h"

class QueueManager
{
public:
	// deleted functions
	QueueManager(const QueueManager&) = delete;
	QueueManager& operator=(const QueueManager&) = delete;

	static void Create();
	static void Destroy();

	static CircularQueue* GetMain();
	static CircularQueue* GetAudio();
	static CircularQueue* GetFile();
	static CircularQueue* GetAux();

	static void SendToMain(Command* cmd);
	static void SendToAudio(Command* cmd);
	static void SendToFile(Command* cmd);
	static void SendToAux(Command* cmd);


private:
	static QueueManager* prInstance();
	
	CircularQueue* toMain;
	CircularQueue* toAudio;
	CircularQueue* toFile;
	CircularQueue* toAux;

	QueueManager();
	~QueueManager();

	void Flush(CircularQueue* queue);


};
#endif // !QUEUE_MANAGER_H
