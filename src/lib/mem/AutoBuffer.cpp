#include "AutoBuffer.h"
#include <algorithm>
#include <cstring>
#include <new>

AutoBuffer::AutoBuffer()
	: _ptr(NULL)
	, _size(0)
	, _maxSize(0)
{}

AutoBuffer::AutoBuffer(size_t size)
	: _ptr(NULL)
	, _size(0)
	, _maxSize(0)
{
	resize(size);
}

AutoBuffer::AutoBuffer(const AutoBuffer& rhs)
	: _ptr(NULL)
	, _size(0)
	, _maxSize(0)
{
	operator=(static_cast<const IBufferReader&>(rhs));
}

AutoBuffer::AutoBuffer(const IBufferReader& rhs)
	: _ptr(NULL)
	, _size(0)
	, _maxSize(0)
{
	operator=(rhs);
}

AutoBuffer::~AutoBuffer()
{
	delete [] _ptr;
}

AutoBuffer& AutoBuffer::operator=(const AutoBuffer& rhs)
{
	return operator=(static_cast<const IBufferReader&>(rhs));
}

AutoBuffer& AutoBuffer::operator=(const IBufferReader& rhs)
{
	if(allocate(rhs.size(), false))
		::memcpy(_ptr, rhs.ptr(), _size);
	return *this;
}

bool AutoBuffer::resize(size_t size)
{
	return allocate(size, true);
}

bool AutoBuffer::allocate(size_t size, bool keepData)
{
	if(size <= _maxSize)
	{
		_size = size;
		return true;
	}

	try
	{
		char* ptr = new char[size];
		if(keepData && _ptr != NULL)
			::memcpy(ptr, _ptr, std::min(size, _size));

		delete [] _ptr;

		_ptr = ptr;
		_size = _maxSize = size;

		return true;
	}
	catch(const std::bad_alloc&)
	{
		return false;
	}
}

void* AutoBuffer::ptr()
{
	return _ptr;
}

const void* AutoBuffer::ptr() const
{
	return _ptr;
}

size_t AutoBuffer::size() const
{
	return _size;
}

