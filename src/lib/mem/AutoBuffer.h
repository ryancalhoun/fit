#pragma once

#include "IBuffer.h"

class AutoBuffer : public IBuffer
{
public:
	AutoBuffer();
	AutoBuffer(size_t size);
	AutoBuffer(const AutoBuffer& rhs);
	AutoBuffer(const IBufferReader& rhs);
	~AutoBuffer();

	AutoBuffer& operator=(const AutoBuffer& rhs);
	AutoBuffer& operator=(const IBufferReader& rhs);

	bool resize(size_t size);

	void* ptr();
	const void* ptr() const;
	size_t size() const;

protected:
	bool allocate(size_t size, bool keepData);

protected:
	char*  _ptr;
	size_t _size;
	size_t _maxSize;
};

