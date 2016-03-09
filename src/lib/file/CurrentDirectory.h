#pragma once

#include "file/Path.h"

class CurrentDirectory
{
public:
	CurrentDirectory();
	CurrentDirectory(const Path& cwd);

	Path get(const Path& file) const;

	const Path& get() const;
	void set(const Path& cwd);

protected:
	Path _currentDirectory;
};

