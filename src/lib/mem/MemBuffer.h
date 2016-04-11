#pragma once

#include "IBuffer.h"

class MemBuffer : public IBuffer
{
public:
	MemBuffer();
	MemBuffer(void* ptr, size_t size);

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

