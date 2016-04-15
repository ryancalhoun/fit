#include "FileHandle.h"
#include "FileFlags.h"
#include "Path.h"
#include "mem/IBuffer.h"

#include <fcntl.h>
#include <unistd.h>

#ifdef __APPLE__
  #define BASE_FLAGS O_CLOEXEC
#else
  #define BASE_FLAGS O_CLOEXEC|O_LARGEFILE
#endif

bool FileHandle::open(const Path& path, const FileFlags& flags)
{
	if((_fd = ::open(path, BASE_FLAGS | flags.openFlags() | flags.createFlags(), 0644)) == -1)
		return false;
	return true;
}

void FileHandle::close()
{
	if(_fd >= 0)
		::close(_fd);
	_fd = -1;
}

bool FileHandle::read(IBuffer& data)
{
	ssize_t n = ::read(_fd, data.ptr(), data.size());
	if(n < 0)
		return false;
	return true;
}

bool FileHandle::write(const IBufferReader& data)
{
	ssize_t n = ::write(_fd, data.ptr(), data.size());
	if(n < 0)
		return false;
	return true;
}

