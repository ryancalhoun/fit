#pragma once

#include "cppunit/CppUnit.h"

class FileFlagsTest : public CppUnit::TestFixture
{
public:
	void testOpenFlags();
	void testCreateFlags();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* FileFlagsTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, FileFlagsTest);

	CPPUNIT_ADD_TEST(suite, testOpenFlags);
	CPPUNIT_ADD_TEST(suite, testCreateFlags);

	return suite;
}

