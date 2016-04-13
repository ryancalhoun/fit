#pragma once

#include "cppunit/CppUnit.h"

class AutoBufferTest : public CppUnit::TestFixture
{
public:
	void testDefault();
	void testConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testResize();

	static CppUnit::Test* suite();
};

inline CppUnit::Test* AutoBufferTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, AutoBufferTest);

	CPPUNIT_ADD_TEST(suite, testDefault);
	CPPUNIT_ADD_TEST(suite, testConstructor);
	CPPUNIT_ADD_TEST(suite, testCopyConstructor);
	CPPUNIT_ADD_TEST(suite, testAssignment);
	CPPUNIT_ADD_TEST(suite, testResize);

	return suite;
}

