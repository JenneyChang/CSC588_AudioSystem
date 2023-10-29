#pragma once
#ifndef RIFF_PARSER_H
#define RIFF_PARSER_H

#ifdef _XBOX //Big-Endian
#define fourccRIFF 'RIFF'
#define fourccDATA 'data'
#define fourccFMT 'fmt '
#define fourccWAVE 'WAVE'
#define fourccXWMA 'XWMA'
#define fourccDPDS 'dpds'
#endif

#ifndef _XBOX //Little-Endian
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'
#endif

#include "File.h"

using namespace Azul;

enum class ChunkError
{
	CHUNK_FAIL,
	CHUNK_SUCCESS
};

ChunkError FindChunk(File::Handle hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);

ChunkError ReadChunkData(File::Handle hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);


#endif // !RIFF_PARSER_H
