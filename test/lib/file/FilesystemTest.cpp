#include "FilesystemTest.h"
#include "Filesystem.h"
#include "MockFilesystemDriver.h"

void FilesystemTest::testDriverNotInstalled()
{
	assert_throw(Filesystem::Exception, Filesystem::pwd());
}

void FilesystemTest::testPwd()
{
	MockFilesystemDriver mockfs("mock-pwd");

	assert_equal(mockfs._pwd, Filesystem::pwd());
}

