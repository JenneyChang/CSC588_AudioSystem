#pragma once
#ifndef USER_FILE_CALLBACK_H
#define USER_FILE_CALLBACK_H

#include "FileCallback.h"

class UserFileCallback : public FileCallback
{
public:
	// deleted functions
	UserFileCallback() = delete;
	UserFileCallback(const UserFileCallback&) = delete;
	UserFileCallback& operator=(const UserFileCallback&) = delete;


	UserFileCallback(bool& loadFlag);
	virtual ~UserFileCallback() = default;

	void Loaded() override;


private:
	bool& flag;


};
#endif // !USER_FILE_CALLBACK_H
