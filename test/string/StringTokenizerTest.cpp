#include "StringTokenizerTest.h"

#include "StringTokenizer.h"
#include "StringList.h"

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
	assert_equal("hello|world", StringList(v).join('|'));
}

void StringTokenizerTest::testSplitMinLength()
{
	StringTokenizer tok("hello world");
	std::vector<std::string> v;
	assert_false(tok.split(v, 3));
	assert_equal("hello|world", StringList(v).join('|'));
}

void StringTokenizerTest::testSplitChar()
{
	StringTokenizer tok("hello world,said,joe", ',');
	std::vector<std::string> v;
	assert_true(tok.split(v));

	assert_equal("hello world|said|joe", StringList(v).join('|'));
}

void StringTokenizerTest::testSplitSubstr()
{
	StringTokenizer tok("shine///on///baby/honey///shine");
	tok.onText("///");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal("shine|on|baby/honey|shine", StringList(v).join('|'));
}

void StringTokenizerTest::testSplitCharset()
{
	StringTokenizer tok("one two\r\nthree\tfour\t\r\nfive\r\n");
	tok.onCharset(" \t\r\n");
	std::vector<std::string> v;
	assert_true(tok.split(v));
	assert_equal("one|two|three|four|five", StringList(v).join('|'));
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
	assert_equal("|I|am||having|fun|", StringList(v).join('|'));
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
	assert_equal(" I am  having fun ", StringList(v).join('|'));
}

