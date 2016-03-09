#pragma once

#include "cppunit/CppUnit.h"

class CurrentDirectoryTest : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testDefault();
	void testRelative();
	void testAbsolute();
	void testSetCurrent();
	void testSetRelative();
	void testSetAbsolute();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* CurrentDirectoryTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, CurrentDirectoryTest);

	CPPUNIT_ADD_TEST(suite, testDefault);
	CPPUNIT_ADD_TEST(suite, testRelative);
	CPPUNIT_ADD_TEST(suite, testAbsolute);
	CPPUNIT_ADD_TEST(suite, testSetCurrent);
	CPPUNIT_ADD_TEST(suite, testSetRelative);
	CPPUNIT_ADD_TEST(suite, testSetAbsolute);

	return suite;
}

