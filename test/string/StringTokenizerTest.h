#pragma once

#include "CppUnit.h"

class StringTokenizerTest : public CppUnit::TestFixture
{
public:
	StringTokenizerTest();

	void setUp();
	void tearDown();

	void testSplit();
	void testSplitMinLength();
	void testSplitChar();
	void testSplitSubstr();
	void testSplitCharset();
	void testSplitCharsetEmpty();

	void testSplitEmptyParts();
	void testSplitEmpty();
	void testSplitNoDelimiters();

	static CppUnit::Test* suite();

protected:

};

inline CppUnit::Test* StringTokenizerTest::suite()
{
	DEFINE_SUITE(suite, StringTokenizerTest);

	ADD_TEST(suite, testSplit);
	ADD_TEST(suite, testSplitMinLength);
	ADD_TEST(suite, testSplitChar);
	ADD_TEST(suite, testSplitSubstr);
	ADD_TEST(suite, testSplitCharset);
	ADD_TEST(suite, testSplitCharsetEmpty);

	ADD_TEST(suite, testSplitEmptyParts);
	ADD_TEST(suite, testSplitEmpty);
	ADD_TEST(suite, testSplitNoDelimiters);

	return suite;
}


