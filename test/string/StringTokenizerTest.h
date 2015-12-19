#pragma once

#include "cppunit/CppUnit.h"

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
	CPPUNIT_DEFINE_SUITE(suite, StringTokenizerTest);

	CPPUNIT_ADD_TEST(suite, testSplit);
	CPPUNIT_ADD_TEST(suite, testSplitMinLength);
	CPPUNIT_ADD_TEST(suite, testSplitChar);
	CPPUNIT_ADD_TEST(suite, testSplitSubstr);
	CPPUNIT_ADD_TEST(suite, testSplitCharset);
	CPPUNIT_ADD_TEST(suite, testSplitCharsetEmpty);

	CPPUNIT_ADD_TEST(suite, testSplitEmptyParts);
	CPPUNIT_ADD_TEST(suite, testSplitEmpty);
	CPPUNIT_ADD_TEST(suite, testSplitNoDelimiters);

	return suite;
}


