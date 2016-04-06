#include "Path.h"
#include "string/StringList.h"
#include "string/StringTokenizer.h"
#include <vector>

Path::Path()
{}

Path::Path(const Path& rhs)
	: _path(rhs)
{}

Path::Path(const std::string& path)
	: _path(path)
{}

Path::Path(const char* path)
	: _path(path)
{}

Path& Path::operator=(const Path& rhs)
{
	_path = rhs;
	return *this;
}

Path Path::operator/(const std::string& rhs) const
{
	Path p = *this;
	p /= rhs;
	return p;
}

Path& Path::operator/=(const std::string& rhs)
{
	if(! _path.empty() && _path.compare(_path.size() - 1, 1, "/") != 0 && rhs.compare(0, 1, "/") != 0)
		_path += "/";
	_path += rhs;
	return *this;
}

Path& Path::normalize()
{
	StringTokenizer tokenizer(_path);
	tokenizer.onCharset("/");

	std::string elem;

	StringList parts;

	while(tokenizer.next(elem))
	{
		if(elem == ".." && ! parts.empty())
			parts.pop();
		else if(elem != ".")
			parts << elem;
	}

	_path = parts.join('/');

	return *this;
}

Path Path::basename() const
{
	std::string::size_type index = _path.find_last_of("\\/");
	if(index == std::string::npos)
		return _path;
	return _path.substr(index + 1);
}

Path Path::dirname() const
{
	std::string::size_type index = _path.find_last_of("\\/");
	if(index == std::string::npos)
		return ".";
	if(index == 0)
		return "/";
	return _path.substr(0, index);
}

bool Path::isAbsolute() const
{
	if(_path.size() > 2 && _path[1] == ':')
		return true;
	return _path.compare(0, 1, "/") == 0;
}

bool Path::isCurrent() const
{
	return _path.empty() || _path == "." || _path == "./";
}

Path::operator const std::string& () const
{
	return _path;
}

