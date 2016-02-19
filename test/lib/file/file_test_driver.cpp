#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestResultCollector.h"

#include "PathTest.h"

int main(int argc, const char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(PathTest::suite());

	runner.run();

	return runner.result().testFailures();
}
