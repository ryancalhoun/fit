#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestResultCollector.h"

#include "StringListTest.h"
#include "StringTokenizerTest.h"

int main(int argc, const char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(StringListTest::suite());
	runner.addTest(StringTokenizerTest::suite());

	runner.run(argc, argv);

	return runner.result().testFailures();
}
