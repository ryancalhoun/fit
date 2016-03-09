#pragma once

#include <string>

class Path
{
public:
	Path();
	Path(const Path& rhs);
	Path(const std::string& path);
	Path(const char* path);

	Path& operator=(const Path& rhs);

	Path operator/(const std::string& rhs) const;
	Path& operator/=(const std::string& rhs);

	Path& normalize();

	Path basename() const;
	Path dirname() const;

	bool isAbsolute() const;
	bool isCurrent() const;

	operator const std::string& () const;

protected:
	std::string _path;
};

