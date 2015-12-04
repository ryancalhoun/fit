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

void StringTokenizerTest::testSplitMinLength()
{
	StringTokenizer tok("hello world");
	std::vector<std::string> v;
	assert_false(tok.split(v, 3));
	assert_equal("hello", v[0]);
	assert_equal("world", v[1]);
}

void StringTokenizerTest::testSplitChar()
{
	StringTokenizer tok("hello world,said,joe", ',');
	std::vector<std::string> v;
	assert_true(tok.split(v));

	assert_equal("hello world", v[0]);
	assert_equal("said", v[1]);
	assert_equal("joe", v[2]);
}

void StringTokenizerTest::testSplitSubstr()
{
	StringTokenizer tok("shine///on///baby/honey///shine");
	tok.onText("///");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal("shine", v[0]);
	assert_equal("on", v[1]);
	assert_equal("baby/honey", v[2]);
	assert_equal("shine", v[3]);
}

void StringTokenizerTest::testSplitCharset()
{
	StringTokenizer tok("one two\r\nthree\tfour\t\r\nfive\r\n");
	tok.onCharset(" \t\r\n");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal("one", v[0]);
	assert_equal("two", v[1]);
	assert_equal("three", v[2]);
	assert_equal("four", v[3]);
	assert_equal("five", v[4]);
}

void StringTokenizerTest::testSplitCharsetEmpty()
{
	StringTokenizer tok("");
	tok.onCharset(" \t\r\n");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_true(v.empty());
}

void StringTokenizerTest::testSplitEmptyParts()
{
	StringTokenizer tok(" I am  having fun ");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal("", v[0]);
	assert_equal("I", v[1]);
	assert_equal("am", v[2]);
	assert_equal("", v[3]);
	assert_equal("having", v[4]);
	assert_equal("fun", v[5]);
	assert_equal("", v[6]);
}

void StringTokenizerTest::testSplitEmpty()
{
	StringTokenizer tok("");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal(1, v.size());
	assert_equal("", v[0]);
}

void StringTokenizerTest::testSplitNoDelimiters()
{
	StringTokenizer tok(" I am  having fun ", '!');
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal(1, v.size());
	assert_equal(" I am  having fun ", v[0]);
}

