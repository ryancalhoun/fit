#pragma once

#include "Path.h"

class IFilesystemDriver
{
public:
	virtual ~IFilesystemDriver() {}

	virtual Path pwd() = 0;
};

