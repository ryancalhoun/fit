#include "FilesystemTest.h"
#include "Filesystem.h"

void FilesystemTest::testDriverNotInstalled()
{
	assert_throw(Filesystem::Exception, Filesystem::pwd());
}

