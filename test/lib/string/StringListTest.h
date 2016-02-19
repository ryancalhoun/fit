#pragma once

#include "cppunit/CppUnit.h"

class StringListTest : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testAppend();
	void testContainerConstructor();
	void testContainerConcat();
	void testIteratorConstructor();
	void testIteratorConcat();

	static CppUnit::Test* suite();
};


inline CppUnit::Test* StringListTest::suite()
{
	CPPUNIT_DEFINE_SUITE(suite, StringListTest);

	CPPUNIT_ADD_TEST(suite, testAppend);
	CPPUNIT_ADD_TEST(suite, testContainerConstructor);
	CPPUNIT_ADD_TEST(suite, testContainerConcat);
	CPPUNIT_ADD_TEST(suite, testIteratorConstructor);
	CPPUNIT_ADD_TEST(suite, testIteratorConcat);

	return suite;
}

