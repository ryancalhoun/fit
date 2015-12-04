#pragma once

#include "cppunit/TestCaller.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"

#include <string>

template <typename T>
class DefineSuite
{
protected:
	CppUnit::TestSuite* _suite;
public:
	typedef T type;
	DefineSuite(const char* name)
		: _suite(new CppUnit::TestSuite(name))
	{}
	operator CppUnit::Test* () const
	{
		return _suite;
	}
	void addTest(const char* name, void (T::*method)())
	{
		_suite->addTest(new CppUnit::TestCaller<T>(name, method));
	}
};

namespace CppUnit
{
	inline void assertEquals(const std::string& expected, const std::string& actual, SourceLine sourceLine, const std::string& message)
	{
		CppUnit::assertEquals<std::string>(expected, actual, sourceLine, message);
	}
}

#define STR(name) #name
#define DEFINE_SUITE(var, name) DefineSuite<name> var(STR(name));
#define ADD_TEST(var, test) \
	do { \
		typedef __typeof__(var) test_class; \
		var.addTest(STR(test), &test_class::type::test); \
	} while(0)

#define assert_true(cond) CPPUNIT_ASSERT(cond)
#define assert_false(cond) CPPUNIT_ASSERT(! cond)
#define assert_equal(expected, actual) CPPUNIT_ASSERT_EQUAL(expected, actual)

