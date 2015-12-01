#pragma once

#include "cppunit/extensions/HelperMacros.h"
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

//	static CppUnit::Test* suite();

	CPPUNIT_TEST_SUITE(StringTokenizerTest);
	CPPUNIT_TEST(testSplit);
	CPPUNIT_TEST_SUITE_END();


protected:

};
/*
inline CppUnit::Test* StringTokenizerTest::suite()
{
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("class StringTokenizerTest");

	suite->addTest(new CppUnit::TestCaller<StringTokenizerTest>("testSplit", testSplit));

	return suite;
}
*/

