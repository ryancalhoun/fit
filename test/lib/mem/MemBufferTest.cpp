#include "MemBufferTest.h"
#include "MemBuffer.h"

void MemBufferTest::testDefault()
{
	MemBuffer mem;
	assert_true(NULL == mem.ptr());
	assert_equal(0, mem.size());

	mem = MemBuffer((void*)0xdeadf00d, 42);
	assert_equal((void*)0xdeadf00d, mem.ptr());
	assert_equal(42, mem.size());
}

