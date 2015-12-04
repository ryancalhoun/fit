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
	assert_true(tok.split(v));
	assert_equal("hello", v[0]);
	assert_equal("world", v[1]);
}

