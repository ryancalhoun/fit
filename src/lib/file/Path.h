#pragma once

#include <string>
#include <iosfwd>

class Path
{
public:
	Path();
	Path(const Path& rhs);
	Path(const std::string& path);
	Path(const char* path);

	bool operator==(const Path& rhs) const;
	Path& operator=(const Path& rhs);

	Path operator/(const Path& rhs) const;
	Path& operator/=(const Path& rhs);

	Path& normalize();

	Path basename() const;
	Path dirname(size_t up = 1) const;

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

std::ostream& operator<<(std::ostream& out, const Path& path);

