#include "RawBuffer.h"

RawBuffer::RawBuffer()
	: _ptr(NULL)
	, _size(0)
{}

RawBuffer::RawBuffer(void* ptr, size_t size)
	: _ptr(ptr)
	, _size(size)
{}

void RawBuffer::setPtr(void* ptr)
{
	_ptr = ptr;
}

void RawBuffer::setSize(size_t size)
{
	_size = size;
}

void RawBuffer::set(void* ptr, size_t size)
{
	setPtr(ptr);
	setSize(size);
}

void* RawBuffer::ptr()
{
	return _ptr;
}

const void* RawBuffer::ptr() const
{
	return _ptr;
}

size_t RawBuffer::size() const
{
	return _size;
}

