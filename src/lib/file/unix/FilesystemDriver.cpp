#include "FilesystemDriver.h"
#include <vector>
#include <cerrno>
#include <unistd.h>

Path FilesystemDriver::pwd() const
{
	std::vector<char> buff(512);
	char* cwd = NULL;
	while(buff.size() <= 8192)
	{
		cwd = ::getcwd(&buff[0], buff.size());
		if(cwd == &buff[0])
			return cwd;

		if(errno != ERANGE)
			break;

		buff.resize(2*buff.size());
	}

	return &buff[0];
}

