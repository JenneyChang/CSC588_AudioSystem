#pragma once
#ifndef HANDLE_H
#define HANDLE_H

class Handle
{
public:
	enum class Status
	{
		SUCCESS = 0x7EEE0000,
		VALID_HANDLE,
		INSUFFICIENT_SPACE,
		INVALID_HANDLE,
		HANDLE_ERROR = 0X7EEEFFFF
	};

	typedef unsigned int ID;
	typedef unsigned int Index;

	class Lock
	{
	public:
		enum Status
		{
			LOCKED,
			UNLOCKED
		};

		// deleted functions
		Lock() = delete;
		Lock(const Lock&) = delete;
		Lock& operator=(const Lock&) = delete;

		Lock(const Handle& h);
		~Lock();

		operator bool() const;
		operator Handle::Status() const;

		void lock();
		void unlock();

	private:
		const Handle& handle;	// ref to original
		Lock::Status status;

	};


public:
	// deleted functions
	Handle(const Handle&) = delete;
	Handle& operator=(const Handle&) = delete;

	Handle();
	~Handle();

	bool operator==(const Handle& h) const;

	Handle::ID GetID() const;
	Handle::Index GetIndex() const;

	static Handle::Status Validate(const Handle& h);
	static Handle::Status Invalidate(Handle& h);

	static Handle::Status ValidAcquire(const Handle& h);
	static Handle::Status ValidRelease(const Handle& h);


private:
	ID		id;
	Index	index;


};
#endif // !HANDLE_H
