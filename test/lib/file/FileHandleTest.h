#pragma once

#include "cppunit/CppUnit.h"

class FileHandleTest : public CppUnit::TestFixture
{
public:
	void tearDown();

	void testCreateNew();
	void testCreateExist();
	void testCreateWriteExist();

	void testOpenReadExist();
	void testOpenReadNotExist();

	void testOpenWriteExist();
	void testOpenWriteNotExist();

	void testOpenAppend();

	void testOpenTruncate();
	void testCreateTruncate();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* FileHandleTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, FileHandleTest);

	CPPUNIT_ADD_TEST(suite, testCreateNew);
	CPPUNIT_ADD_TEST(suite, testCreateExist);
	CPPUNIT_ADD_TEST(suite, testCreateWriteExist);

	CPPUNIT_ADD_TEST(suite, testOpenReadExist);
	CPPUNIT_ADD_TEST(suite, testOpenReadNotExist);

	CPPUNIT_ADD_TEST(suite, testOpenWriteExist);
	CPPUNIT_ADD_TEST(suite, testOpenWriteNotExist);

	CPPUNIT_ADD_TEST(suite, testOpenAppend);

	CPPUNIT_ADD_TEST(suite, testOpenTruncate);
	CPPUNIT_ADD_TEST(suite, testCreateTruncate);

	return suite;
}

