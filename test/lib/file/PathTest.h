#pragma once

#include "cppunit/CppUnit.h"

class PathTest : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testBasename();
	void testDirname();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* PathTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, PathTest);

	CPPUNIT_ADD_TEST(suite, testBasename);
	CPPUNIT_ADD_TEST(suite, testDirname);

	return suite;
}

