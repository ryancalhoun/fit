#pragma once

#include "Path.h"
#include <stdexcept>

class IFilesystemDriver;

class Filesystem
{
public:
	static Path pwd();

public:
	class Exception : public std::runtime_error
	{
	public:
		Exception(const std::string& message);
	};

protected:
	static void install(IFilesystemDriver& driver);

protected:
	static IFilesystemDriver* _driver;
};
