#pragma once

#include "IBuffer.h"

class RawBuffer : public IBuffer
{
public:
	RawBuffer();
	RawBuffer(void* ptr, size_t size);

	void setPtr(void* ptr);
	void setSize(size_t size);
	void set(void* ptr, size_t size);
	
	void* ptr();
	const void* ptr() const;
	size_t size() const;

protected:
	void*  _ptr;
	size_t _size;
};

