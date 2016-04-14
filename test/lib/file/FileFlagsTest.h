#pragma once

#include "cppunit/CppUnit.h"

class FileFlagsTest : public CppUnit::TestFixture
{
public:
	void testReadWrite();
	void testAppend();
	void testCreate();
	void testTruncate();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* FileFlagsTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, FileFlagsTest);

	CPPUNIT_ADD_TEST(suite, testReadWrite);
	CPPUNIT_ADD_TEST(suite, testAppend);
	CPPUNIT_ADD_TEST(suite, testCreate);
	CPPUNIT_ADD_TEST(suite, testTruncate);

	return suite;
}

