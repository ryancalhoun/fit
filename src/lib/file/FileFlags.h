#pragma once

#include "File.h"

class FileFlags
{
public:
	FileFlags(int flags);

	int openFlags() const;

protected:
	int _flags;
};

inline FileFlags::FileFlags(int flags)
	: _flags(flags)
{}


