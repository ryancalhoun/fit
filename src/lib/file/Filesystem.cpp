#include "Filesystem.h"
#include "IFilesystemDriver.h"

IFilesystemDriver* Filesystem::_driver = NULL;

Path Filesystem::pwd()
{
	if(_driver == NULL)
		throw Exception("filesystem driver has not been installed for this process");

	return _driver->pwd();
}

void Filesystem::install(IFilesystemDriver& driver)
{
	_driver = &driver;
}

void Filesystem::uninstall()
{
	_driver = NULL;
}

Filesystem::Exception::Exception(const std::string& message)
	: std::runtime_error(message)
{}

void IFilesystemDriver::install()
{
	Filesystem::install(*this);
}

void IFilesystemDriver::uninstall()
{
	Filesystem::uninstall();
}

