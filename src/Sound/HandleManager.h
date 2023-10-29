#pragma once
#ifndef HANDLE_MANAGER_H
#define HANDLE_MANAGER_H

#include "Handle.h"
#include <shared_mutex>

class HandleManager
{
public:
	// deleted functions
	HandleManager(const HandleManager&) = delete;
	HandleManager& operator=(const HandleManager&) = delete;

	static Handle::Status Activate(Handle::ID& id, Handle::Index& index);
	
	static Handle::Status Validate(const Handle& h);
	static Handle::Status Invalidate(Handle& h);

	static Handle::Status ValidAcquire(const Handle& h);
	static Handle::Status ValidRelease(const Handle& h);

	static void PrintTable();


private:
	static HandleManager* prInstance();

	HandleManager();
	~HandleManager();

	bool prFindNextAvaliable(Handle::Index& index);
	Handle::ID prGetNewID();

	Handle::Status prIsHandleAndRangeValid(const Handle& h);
	Handle::Status prIsHandleValid(const Handle& h);
	Handle::Status prIsWithinRange(const Handle& h);


private:
	static const unsigned int TABLE_SIZE = 25;
	static const unsigned int INVALID_STATE = 0x0;
	static const unsigned int STARTING_ID = 0xAAAA0000;

	class HandleTable
	{
	public:
		// deleted
		HandleTable(const HandleTable&) = delete;
		HandleTable& operator=(const HandleTable&) = delete;

		HandleTable() = default;
		~HandleTable() = default;

	public:
		std::atomic<unsigned int> id;
		//std::mutex mtx;
		std::shared_mutex mtx;

	};

	HandleTable table[TABLE_SIZE];
	Handle::ID srcID; //last ID created


};
#endif // !HANDLE_MANAGER_H
