#include "MemBuffer.h"

MemBuffer::MemBuffer()
	: _ptr(NULL)
	, _size(0)
{}

MemBuffer::MemBuffer(void* ptr, size_t size)
	: _ptr(ptr)
	, _size(size)
{}

void MemBuffer::setPtr(void* ptr)
{
	_ptr = ptr;
}

void MemBuffer::setSize(size_t size)
{
	_size = size;
}

void MemBuffer::set(void* ptr, size_t size)
{
	setPtr(ptr);
	setSize(size);
}

void* MemBuffer::ptr()
{
	return _ptr;
}

const void* MemBuffer::ptr() const
{
	return _ptr;
}

size_t MemBuffer::size() const
{
	return _size;
}

