#pragma once

#include "IFilesystemDriver.h"
#include "Filesystem.h"

class MockFilesystemDriver : public IFilesystemDriver
{
public:
	MockFilesystemDriver();
	MockFilesystemDriver(const Path& pwd);
	~MockFilesystemDriver();
	Path pwd() const;

public:
	Path _pwd;
};

inline MockFilesystemDriver::MockFilesystemDriver()
{
	install();
}

inline MockFilesystemDriver::MockFilesystemDriver(const Path& pwd)
	: _pwd(pwd)
{
	install();
}

inline MockFilesystemDriver::~MockFilesystemDriver()
{
	uninstall();
}

inline Path MockFilesystemDriver::pwd() const
{
	return _pwd;
}


