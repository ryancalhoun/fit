#pragma once

#include "IBufferReader.h"

class IBuffer : public IBufferReader
{
public:
	virtual void* ptr() = 0;
};

