#include "StringThis.h"
#include <xaudio2.h>


StringThis::StringThis(int x)
{
	switch (x)
	{
	case XAUDIO2_E_INVALID_CALL:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(XAUDIO2_E_INVALID_CALL));
		break;
	case XAUDIO2_E_XAPO_CREATION_FAILED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(XAUDIO2_E_XAPO_CREATION_FAILED));
		break;
	case XAUDIO2_E_DEVICE_INVALIDATED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(XAUDIO2_E_DEVICE_INVALIDATED));
		break;
	case XAUDIO2_E_XMA_DECODER_ERROR:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(XAUDIO2_E_XMA_DECODER_ERROR));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::StringThis(Wave::ID id)
{
	switch (id)
	{
	case Wave::ID::TESTER:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(TESTER));
		break;
	case Wave::ID::FIDDLE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(FIDDLE));
		break;
	case Wave::ID::OBOE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(OBOE));
		break;
	case Wave::ID::BASSOON:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(BASSOON));
		break;
	case Wave::ID::WATERFALL:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(WATERFALL));
		break;

	case Wave::ID::SEINFELD0:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD0));
		break;
	case Wave::ID::SEINFELD1:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD1));
		break;
	case Wave::ID::SEINFELD2:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD2));
		break;
	case Wave::ID::SEINFELD3:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD3));
		break;
	case Wave::ID::SEINFELD4:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD4));
		break;
	case Wave::ID::SEINFELD5:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD5));
		break;
	case Wave::ID::SEINFELD6:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD6));
		break;
	case Wave::ID::SEINFELD7:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD7));
		break;
	case Wave::ID::SEINFELD8:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD8));
		break;
	case Wave::ID::SEINFELD9:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD9));
		break;

	case Wave::ID::BEETHOVEN_LAENDLER:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(BEETHOVEN_LAENDLER));
		break;
	case Wave::ID::CHOPIN_BOURREE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(CHOPIN_BOURREE));
		break;

	case Wave::ID::UNINITIALIZED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(UNINITIALIZED));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::StringThis(WaveTable::Status status)
{
	switch (status)
	{
	case WaveTable::Status::EMPTY:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(EMPTY));
		break;
	case WaveTable::Status::PENDING:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(PENDING));
		break;
	case WaveTable::Status::READY:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(READY));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::StringThis(Handle::Status status)
{
	switch (status)
	{
	case Handle::Status::SUCCESS:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SUCCESS));
		break;
	case Handle::Status::VALID_HANDLE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(VALID_HANDLE));
		break;
	case Handle::Status::INVALID_HANDLE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(INVALID_HANDLE));
		break;
	case Handle::Status::HANDLE_ERROR:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(HANDLE_ERROR));
		break;
	case Handle::Status::INSUFFICIENT_SPACE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(INSUFFICIENT_SPACE));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::StringThis(Sound::ID id)
{
	switch (id)
	{
	case Sound::ID::TESTER:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(TESTER));
		break;
	case Sound::ID::FIDDLE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(FIDDLE));
		break;
	case Sound::ID::OBOE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(OBOE));
		break;
	case Sound::ID::BASSOON:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(BASSOON));
		break;
	case Sound::ID::SEINFELD:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(SEINFELD));
		break;
	case Sound::ID::BEETHOVEN_LAENDLER:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(BEETHOVEN_LAENDLER));
		break;
	case Sound::ID::CHOPIN_BOURREE:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(CHOPIN_BOURREE));
		break;
	case Sound::ID::WATERFALL:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(WATERFALL));
		break;
	case Sound::ID::UNINITIALIZED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(UNINITIALIZED));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::StringThis(Sound::Status status)
{
	switch (status)
	{
	case Sound::Status::LOADING:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(LOADING));
		break;
	case Sound::Status::READY:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(READY));
		break;
	case Sound::Status::PLAYING:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(PLAYING));
		break;
	case Sound::Status::PAUSED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(PAUSED));
		break;
	case Sound::Status::REJECTED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(REJECTED));
		break;
	case Sound::Status::STOPPED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(STOPPED));
		break;

	case Sound::Status::UNINITIALIZED:
		strcpy_s(buffer, BUFFER_SIZE, STRING_ME(UNINITIALIZED));
		break;
	default:
		assert(false);
		break;
	}
}

StringThis::operator char* ()
{
	return this->buffer;
}