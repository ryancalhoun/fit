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

Filesystem::Exception::Exception(const std::string& message)
	: std::runtime_error(message)
{}

