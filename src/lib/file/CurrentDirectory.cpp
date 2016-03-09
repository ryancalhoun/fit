#include "CurrentDirectory.h"

CurrentDirectory::CurrentDirectory()
{}

CurrentDirectory::CurrentDirectory(const Path& cwd)
	: _currentDirectory(cwd)
{}

Path CurrentDirectory::get(const Path& file) const
{
	if(file.isAbsolute())
		return file;
	return _currentDirectory / file;
}

const Path& CurrentDirectory::get() const
{
	return _currentDirectory;
}

void CurrentDirectory::set(const Path& cwd)
{
	if(_currentDirectory.isCurrent() || cwd.isAbsolute())
		_currentDirectory = cwd;
	else
		_currentDirectory /= cwd;
}


