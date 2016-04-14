#include "FileFlags.h"

#include <fcntl.h>
#include <sys/stat.h>

#define SET_BIT(outflags, inflags, myflag, realflag) { if(((inflags) & (myflag)) != 0) outflags |= (realflag); }

int FileFlags::openFlags() const
{
	int cflags = 0;

	if((_flags & File::Read) != 0 && (_flags & File::Write) != 0)
		cflags |= O_RDWR;
	else if((_flags & File::Read) != 0)
		cflags |= O_RDONLY;
	else if((_flags & File::Write) != 0)
		cflags |= O_WRONLY;

	SET_BIT(cflags, _flags, File::Append, O_APPEND);

	return cflags;
}

int FileFlags::createFlags() const
{
	int cflags = 0;

	SET_BIT(cflags, _flags, File::Create, O_CREAT);
	SET_BIT(cflags, _flags, File::CreateEx, O_EXCL);
	SET_BIT(cflags, _flags, File::Truncate, O_TRUNC);

	return cflags;
}

