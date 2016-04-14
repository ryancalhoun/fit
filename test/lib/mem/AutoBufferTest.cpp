#include "AutoBufferTest.h"
#include "AutoBuffer.h"

#include <cstring>

void AutoBufferTest::testDefault()
{
	AutoBuffer buf;
	assert_equal(NULL, buf.ptr());
	assert_equal(0, buf.size());
}

void AutoBufferTest::testConstructor()
{
	AutoBuffer buf(4);
	assert_equal(4, buf.size());

	*(int*)buf.ptr() = 42;
	assert_equal(42, *(int*)buf.ptr());
}

void AutoBufferTest::testCopyConstructor()
{
	AutoBuffer buf(4);
	*(int*)buf.ptr() = 42;

	AutoBuffer buf2(buf);

	assert_equal(42, *(int*)buf2.ptr());
	assert_equal(4, buf2.size());
}

void AutoBufferTest::testAssignment()
{
	AutoBuffer buf(4);
	*(int*)buf.ptr() = 42;

	AutoBuffer buf2(4);
	*(int*)buf2.ptr() = 11;

	buf = buf2;

	assert_equal(11, *(int*)buf2.ptr());
}

void AutoBufferTest::testResize()
{
	AutoBuffer buf(4);
	::memcpy(buf.ptr(), "abcd", 4);

	assert_true(buf.resize(8));

	assert_equal(0, ::memcmp(buf.ptr(), "abcd", 4));
	::memcpy(buf.ptr(), "defghij", 8);

	assert_true(buf.resize(4));
	assert_equal(0, ::memcmp(buf.ptr(), "defg", 4));

}

