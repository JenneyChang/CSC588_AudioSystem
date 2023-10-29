#include "RIFF_PARSER.h"


using namespace Azul;

static DWORD HEADER_SIZE = sizeof(DWORD) * 2;


// fourcc (looking for this), return (size & position)
ChunkError FindChunk(File::Handle hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition)
{
    DWORD dwChunkType = 0;
    DWORD dwChunkDataSize = 0;
    DWORD dwRIFFDataSize = 0;
    DWORD dwOffset = 0;
    ChunkError cerr = ChunkError::CHUNK_SUCCESS;

    //start at beginning of file
    if (File::Seek(hFile, File::Position::BEGIN, 0) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }

    while (cerr == ChunkError::CHUNK_SUCCESS)
    {
        //read a chunk 
        if (File::Read(hFile, &dwChunkType, sizeof(DWORD)) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }
        if (File::Read(hFile, &dwChunkDataSize, sizeof(DWORD)) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }

        //check if its the type we want
        DWORD dwFileType = 0;
        switch (dwChunkType)
        {
        case fourccRIFF:
            dwRIFFDataSize = dwChunkDataSize;
            dwChunkDataSize = 4;

            if (File::Read(hFile, &dwFileType, sizeof(DWORD)) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }
            break;

        default:
            // no?  then we do nothing to it
            if (File::Seek(hFile, File::Position::CURRENT, dwChunkDataSize) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }
        }

        dwOffset += HEADER_SIZE;
        if (dwChunkType == fourcc)
        {
            dwChunkSize = dwChunkDataSize;
            dwChunkDataPosition = dwOffset;
            break;
        }

        dwOffset += dwChunkDataSize;    // move down by size of chunk data
    }

    return cerr;
}

ChunkError ReadChunkData(File::Handle hFile, void* buffer, DWORD buffersize, DWORD bufferoffset)
{
    ChunkError cerr = ChunkError::CHUNK_SUCCESS;

    if (File::Seek(hFile, File::Position::BEGIN, bufferoffset) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }

    if (File::Read(hFile, buffer, buffersize) != File::Error::SUCCESS) { cerr = ChunkError::CHUNK_FAIL; }

    return cerr;
}