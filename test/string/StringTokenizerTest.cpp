#include "StringTokenizerTest.h"

#include "StringTokenizer.h"

StringTokenizerTest::StringTokenizerTest()
{
}

void StringTokenizerTest::setUp()
{
}

void StringTokenizerTest::tearDown()
{
}

void StringTokenizerTest::testSplit()
{
	StringTokenizer tok("hello world");
	std::vector<std::string> v;
	CPPUNIT_ASSERT(tok.split(v));
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), v[0]);
	CPPUNIT_ASSERT_EQUAL(std::string("world"), v[1]);
}

