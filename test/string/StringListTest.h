#pragma once

#include "CppUnit.h"

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
	DEFINE_SUITE(suite, StringListTest);

	ADD_TEST(suite, testAppend);
	ADD_TEST(suite, testContainerConstructor);
	ADD_TEST(suite, testContainerConcat);
	ADD_TEST(suite, testIteratorConstructor);
	ADD_TEST(suite, testIteratorConcat);

	return suite;
}

