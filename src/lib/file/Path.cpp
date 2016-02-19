#include "Path.h"

Path::Path()
{}

Path::Path(const Path& rhs)
	: _path(rhs)
{}

Path::Path(const std::string& path)
	: _path(path)
{}

Path& Path::operator=(const Path& rhs)
{
	_path = rhs;
	return *this;
}

Path& Path::operator=(const std::string& rhs)
{
	_path = rhs;
	return *this;
}

std::string Path::basename() const
{
	std::string::size_type index = _path.rfind('/');
	if(index == std::string::npos)
		return _path;
	return _path.substr(index + 1);
}

std::string Path::dirname() const
{
	std::string::size_type index = _path.rfind('/');
	if(index == std::string::npos)
		return ".";
	if(index == 0)
		return "/";
	return _path.substr(0, index);
}

Path::operator const std::string& () const
{
	return _path;
}

