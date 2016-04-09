#include "Path.h"
#include "string/StringList.h"
#include "string/StringTokenizer.h"
#include <algorithm>
#include <vector>

Path::Path()
{}

Path::Path(const Path& rhs)
	: _path(rhs)
{
	fixSlashes();
}

Path::Path(const std::string& path)
	: _path(path)
{
	fixSlashes();
}

Path::Path(const char* path)
	: _path(path)
{
	fixSlashes();
}

bool Path::operator==(const Path& rhs) const
{
	return _path == rhs._path;
}

Path& Path::operator=(const Path& rhs)
{
	_path = rhs;
	return *this;
}

Path Path::operator/(const Path& rhs) const
{
	Path p = *this;
	p /= rhs;
	return p;
}

Path& Path::operator/=(const Path& rhs)
{
	if(! _path.empty() && _path.compare(_path.size() - 1, 1, "/") != 0)
		_path += "/";

 	if(rhs.str().compare(0, 1, "/") == 0)
		_path += rhs.str().substr(1);
	else
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
	std::string::size_type index = _path.rfind('/');
	if(index == std::string::npos)
		return _path;
	return _path.substr(index + 1);
}

Path Path::dirname(size_t up /* = 1 */) const
{
	std::string::size_type index = _path.size() + 1;
	while(up-- > 0)
	{
		index = _path.rfind('/', index - 1);
		if(index == std::string::npos)
			return ".";
		if(index == 0)
			return "/";
	}
	return _path.substr(0, index);
}

char Path::driveLetter() const
{
	if(_path.size() > 2 && _path[1] == ':')
		return _path[0];
	return 0;
}

bool Path::isAbsolute() const
{
	if(driveLetter() != 0)
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

const std::string& Path::str() const
{
	return _path;
}

void Path::fixSlashes()
{
	std::replace(_path.begin(), _path.end(), '\\', '/');
}

std::ostream& operator<<(std::ostream& out, const Path& path)
{
	return out << path.str();
}

