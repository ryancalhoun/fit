#pragma once

#include "IBufferReader.h"

class CString : public IBufferReader
{
public:
	CString();
	CString(const char* str);

	const void* ptr() const;
	size_t size() const;

protected:
	const char* _str;
};

