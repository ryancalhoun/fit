#include "FilesystemDriverTest.h"
#include "FilesystemDriver.h"

void FilesystemDriverTest::testPwd()
{
	Path pwd = FilesystemDriver().pwd();
	assert_true(pwd.isAbsolute());
	assert_equal("file", pwd.basename());
}

