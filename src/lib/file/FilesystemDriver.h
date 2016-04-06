#pragma once

#include "IFilesystemDriver.h"

class FilesystemDriver : public IFilesystemDriver
{
public:
	Path pwd() const;
};

