#pragma once

#include "cppunit/CppUnit.h"

class FilesystemTest : public CppUnit::TestFixture
{
public:
	void testDriverNotInstalled();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* FilesystemTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, FilesystemTest);

	CPPUNIT_ADD_TEST(suite, testDriverNotInstalled);

	return suite;
}

