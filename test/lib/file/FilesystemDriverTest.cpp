#include "FilesystemDriverTest.h"
#include "FilesystemDriver.h"

void FilesystemDriverTest::testPwd()
{
	Path pwd = FilesystemDriver().pwd();
	assert_true(pwd.isAbsolute());

	Path thisFile(__FILE__);

	// pwd include build/test/lib/file
	// thisFile includes test/lib/file/FilesystemDriverTest.cpp
	assert_equal(thisFile.dirname(4), pwd.dirname(4));
}

