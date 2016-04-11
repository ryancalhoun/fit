#pragma once

#include "cppunit/CppUnit.h"

class MemBufferTest : public CppUnit::TestFixture
{
public:
	void testDefault();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* MemBufferTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, MemBufferTest);

	CPPUNIT_ADD_TEST(suite, testDefault);

	return suite;
}

