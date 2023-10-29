#pragma once
#ifndef WAVE_H
#define WAVE_H

#include <xaudio2.h>
#include "DLink.h"
#include "Handle.h"

class InternalFileCB;
class FileCallback;
class Wave : public DLink
{
public:
	enum class ID
	{
		FIDDLE = 101,
		BASSOON = 102,
		OBOE = 103,
		TESTER,
		WATERFALL,
		SEINFELD0 = 200,
		SEINFELD1,
		SEINFELD2,
		SEINFELD3,
		SEINFELD4,
		SEINFELD5,
		SEINFELD6,
		SEINFELD7,
		SEINFELD8,
		SEINFELD9,

		BEETHOVEN_LAENDLER = 501,
		CHOPIN_BOURREE,

		UNINITIALIZED
	};

	enum class Status
	{
		LOADING,
		READY,
		UNINITIALIZED
	};


public:
	// deleted functions
	Wave(const Wave&) = delete;
	Wave& operator=(const Wave&) = delete;

	Wave();
	~Wave();

	Handle::Status Set(Wave::ID id, InternalFileCB* callback);
	Handle::Status Set(Wave::ID id, FileCallback* callback);

	Handle::Status SetID(Wave::ID id);
	Wave::ID GetID();

	Handle::Status SetWfx(WAVEFORMATEXTENSIBLE& inWfx, unsigned char* pData, unsigned int size);
	unsigned int GetSize();
	unsigned char* GetData();
	WAVEFORMATEXTENSIBLE& GetFormat();

	InternalFileCB* GetFileCallback();
	FileCallback* GetUserCallback();

	bool Compare(Node* pNode) override;


private:
	Handle handle;
	unsigned char*			pRawWave;
	unsigned int			wavSize;

	WAVEFORMATEXTENSIBLE	wfx;
	Wave::ID				waveID;
	Wave::Status			status;

	InternalFileCB* pFileCB;	// internal callback
	FileCallback* pUserFileCB;	// user callback


};
#endif // !WAVE_H
