#pragma once

#include "IFilesystemDriver.h"

class MockFilesystemDriver : public IFilesystemDriver
{
public:
	MockFilesystemDriver();
	MockFilesystemDriver(const Path& pwd);
	Path pwd() const;

public:
	Path _pwd;
};

inline MockFilesystemDriver::MockFilesystemDriver()
{}

inline MockFilesystemDriver::MockFilesystemDriver(const Path& pwd)
	: _pwd(pwd)
{}

inline Path MockFilesystemDriver::pwd() const
{
	return _pwd;
}


