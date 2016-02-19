#include "StringListTest.h"
#include "StringList.h"

#include <vector>

void StringListTest::setUp()
{
}

void StringListTest::tearDown()
{
}

void StringListTest::testAppend()
{
	StringList list;
	list << "one" << "two" << "three";

	assert_equal("one,two,three", list.join(','));
}

void StringListTest::testContainerConstructor()
{
	std::vector<std::string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");

	StringList list(v);

	assert_equal("one,two,three", list.join(','));
}

void StringListTest::testContainerConcat()
{
	std::vector<std::string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");

	StringList list;
	list.concat(v);

	assert_equal("one,two,three", list.join(','));
}

void StringListTest::testIteratorConstructor()
{
	std::vector<std::string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");

	StringList list(v.begin(), v.end());

	assert_equal("one,two,three", list.join(','));
}

void StringListTest::testIteratorConcat()
{
	std::vector<std::string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");

	StringList list;
	list.concat(v.begin(), v.end());

	assert_equal("one,two,three", list.join(','));
}

