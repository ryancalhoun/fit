#pragma once

#include "CppUnit.h"

class StringTokenizerTest : public CppUnit::TestFixture
{
public:
	StringTokenizerTest();

	void setUp();
	void tearDown();

	void testSplit();

	static CppUnit::Test* suite();

protected:

};

inline CppUnit::Test* StringTokenizerTest::suite()
{
	DEFINE_SUITE(suite, StringTokenizerTest);
	ADD_TEST(suite, testSplit);

	return suite;
}


