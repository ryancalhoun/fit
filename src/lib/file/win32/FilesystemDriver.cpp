#include "FilesystemDriver.h"
#include <vector>
#include <windows.h>

Path FilesystemDriver::pwd() const
{
	std::vector<char> buff(512);

	DWORD size = ::GetCurrentDirectory((DWORD)buff.size(), &buff[0]);
	if(size > buff.size())
	{
		buff.resize(size);
		size = ::GetCurrentDirectory((DWORD)buff.size(), &buff[0]);
	}

	return &buff[0];
}

