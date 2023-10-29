#pragma once
#ifndef LOAD_PLAYLIST_CMD_H
#define LOAD_PLAYLIST_CMD_H

#include "Command.h"
#include "PlaylistRef.h"
#include "Wave.h"

class LoadPlaylistCmd : public Command
{
public:
	// deleted functions
	LoadPlaylistCmd() = delete;
	LoadPlaylistCmd(const LoadPlaylistCmd&) = delete;
	LoadPlaylistCmd& operator=(const LoadPlaylistCmd&) = delete;

	LoadPlaylistCmd(PlaylistRef::ID playlistId, Wave::ID wavID);
	~LoadPlaylistCmd() = default;

	void Execute() override;


private:
	//bool& done;
	PlaylistRef::ID id;
	Wave::ID wavId;
	

};
#endif // !LOAD_PLAYLIST_H
