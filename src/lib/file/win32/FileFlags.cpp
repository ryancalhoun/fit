#include "FileFlags.h"
#include <windows.h>

int FileFlags::openFlags() const
{
	DWORD cflags = 0;
	if((_flags & File::Read) != 0)
	{
		cflags |= FILE_READ_DATA | FILE_READ_ATTRIBUTES | STANDARD_RIGHTS_READ;
	}
	if((_flags & File::Write) != 0)
	{
		cflags |= FILE_WRITE_ATTRIBUTES | STANDARD_RIGHTS_WRITE | WRITE_OWNER;
		if((_flags & File::Append) == 0)
			cflags |= FILE_WRITE_DATA;
	}
	if((_flags & File::Append) != 0)
	{
		cflags |= FILE_APPEND_DATA;
	}

	if((_flags & File::Create) == 0 && (_flags & File::Truncate) != 0)
	{
		cflags |= GENERIC_WRITE;
	}

	return (int)cflags;
}

int FileFlags::createFlags() const
{
	if((_flags & File::Create) != 0 && (_flags & File::CreateEx) != 0)
		return (int)CREATE_NEW;
	else if((_flags & File::Create) != 0 && (_flags & File::Truncate) != 0)
		return (int)CREATE_ALWAYS;
	else if((_flags & File::Create) != 0 && (_flags & File::Truncate) == 0)
		return (int)OPEN_ALWAYS;
	else if((_flags & File::Create) == 0 && (_flags & File::Truncate) != 0)
		return (int)TRUNCATE_EXISTING;
	else if((_flags & File::Create) == 0 && (_flags & File::Truncate) == 0)
		return (int)OPEN_EXISTING;

	return 0;
}

