#pragma once

#include "cppunit/CppUnit.h"

class PathTest : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testBasename();
	void testDirname();
	void testIsAbsolute();
	void testIsCurrent();
	void testAppend();
	void testNormalize();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* PathTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, PathTest);

	CPPUNIT_ADD_TEST(suite, testBasename);
	CPPUNIT_ADD_TEST(suite, testDirname);
	CPPUNIT_ADD_TEST(suite, testIsAbsolute);
	CPPUNIT_ADD_TEST(suite, testIsCurrent);
	CPPUNIT_ADD_TEST(suite, testAppend);
	CPPUNIT_ADD_TEST(suite, testNormalize);

	return suite;
}

