#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestResultCollector.h"
#include "StringTokenizerTest.h"

int main(int argc, const char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(StringTokenizerTest::suite());

	runner.run();

	return runner.result().testFailures();
}
