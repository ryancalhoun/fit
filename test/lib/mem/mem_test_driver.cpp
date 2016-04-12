#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestResultCollector.h"

#include "AutoBufferTest.h"
#include "MemBufferTest.h"

int main(int argc, const char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(AutoBufferTest::suite());
	runner.addTest(MemBufferTest::suite());

	runner.run(argc, argv);

	return runner.result().testFailures();
}
