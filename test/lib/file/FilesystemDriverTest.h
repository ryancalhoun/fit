#pragma once

#include "cppunit/CppUnit.h"

class FilesystemDriverTest : public CppUnit::TestFixture
{
public:
	void testPwd();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* FilesystemDriverTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, FilesystemDriverTest);

	CPPUNIT_ADD_TEST(suite, testPwd);

	return suite;
}

