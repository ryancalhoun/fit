#pragma once

#include "File.h"

class FileFlags;
class IBuffer;
class IBufferReader;
class Path;

class FileHandle
{
public:
	FileHandle();

	bool open(const Path& path, const FileFlags& flags);
	void close();

	bool read(IBuffer& data);
	bool write(const IBufferReader& data);

protected:
	int       _fd;
};

inline FileHandle::FileHandle()
	: _fd(-1)
{}

