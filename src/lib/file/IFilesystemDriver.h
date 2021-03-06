#pragma once

#include "Path.h"

class IFilesystemDriver
{
public:
	virtual ~IFilesystemDriver() {}

	virtual Path pwd() const = 0;

protected:
	void install();
	void uninstall();
};

