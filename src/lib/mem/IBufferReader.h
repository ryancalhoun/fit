#pragma once

#include <cstddef>

class IBufferReader
{
public:
	virtual ~IBufferReader() {}

	virtual const void* ptr() const = 0;
	virtual size_t size() const = 0;
};

