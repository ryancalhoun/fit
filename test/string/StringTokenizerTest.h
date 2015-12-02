#pragma once

#include "cppunit/TestCaller.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"

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
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("class StringTokenizerTest");

	suite->addTest(new CppUnit::TestCaller<StringTokenizerTest>("testSplit", &StringTokenizerTest::testSplit));

	return suite;
}


