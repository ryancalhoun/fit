#pragma once

#include "cppunit/CppUnit.h"

class RawBufferTest : public CppUnit::TestFixture
{
public:
	void testDefault();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* RawBufferTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, RawBufferTest);

	CPPUNIT_ADD_TEST(suite, testDefault);

	return suite;
}

