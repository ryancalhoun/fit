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

	Path operator/(const Path& rhs) const;
	Path& operator/=(const Path& rhs);

	Path& normalize();

	Path basename() const;
	Path dirname() const;

	char driveLetter() const;

	bool isAbsolute() const;
	bool isCurrent() const;

	operator const std::string& () const;
	const std::string& str() const;

protected:
	void fixSlashes();

protected:
	std::string _path;
};

