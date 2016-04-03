#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestResultCollector.h"

#include "CurrentDirectoryTest.h"
#include "FilesystemTest.h"
#include "PathTest.h"

int main(int argc, const char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(CurrentDirectoryTest::suite());
	runner.addTest(FilesystemTest::suite());
	runner.addTest(PathTest::suite());

	runner.run(argc, argv);

	return runner.result().testFailures();
}
