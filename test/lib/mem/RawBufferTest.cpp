#include "RawBufferTest.h"
#include "RawBuffer.h"

void RawBufferTest::testDefault()
{
	RawBuffer mem;
	assert_equal(NULL, mem.ptr());
	assert_equal(0, mem.size());

	mem = RawBuffer((void*)0xdeadf00dull, 42);
	assert_equal((void*)0xdeadf00dull, mem.ptr());
	assert_equal(42, mem.size());
}

