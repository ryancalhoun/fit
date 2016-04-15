#include "CString.h"

#include <cstring>

CString::CString()
	: _str(NULL)
{}

CString::CString(const char* str)
	: _str(str)
{}

const void* CString::ptr() const
{
	return _str;
}

size_t CString::size() const
{
	if(_str == NULL)
		return 0;
	return ::strlen(_str);
}

