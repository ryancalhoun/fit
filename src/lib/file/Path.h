#pragma once

#include <string>

class Path
{
public:
	Path();
	Path(const Path& rhs);
	Path(const std::string& path);

	Path& operator=(const Path& rhs);
	Path& operator=(const std::string& rhs);

	std::string basename() const;
	std::string dirname() const;

	operator const std::string& () const;

protected:
	std::string _path;
};

