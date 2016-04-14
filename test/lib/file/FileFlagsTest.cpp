#include "FileFlagsTest.h"
#include "FileFlags.h"

#include <fcntl.h>
#ifdef __APPLE__
	#define BASE_FLAGS O_CLOEXEC
#else
	#define BASE_FLAGS O_LARGEFILE|O_CLOEXEC
#endif

void FileFlagsTest::testReadWrite()
{
	assert_equal(BASE_FLAGS|O_RDONLY, FileFlags(File::Read).openFlags());
	assert_equal(BASE_FLAGS|O_WRONLY, FileFlags(File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_RDWR, FileFlags(File::Read|File::Write).openFlags());
}

void FileFlagsTest::testAppend()
{
	assert_equal(BASE_FLAGS|O_WRONLY|O_APPEND, FileFlags(File::Append|File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_RDWR|O_APPEND, FileFlags(File::Append|File::Read|File::Write).openFlags());
}

void FileFlagsTest::testCreate()
{
	assert_equal(BASE_FLAGS|O_CREAT, FileFlags(File::Create).openFlags());
	assert_equal(BASE_FLAGS|O_CREAT|O_EXCL, FileFlags(File::Create|File::CreateEx).openFlags());
}

void FileFlagsTest::testTruncate()
{
	assert_equal(BASE_FLAGS|O_TRUNC, FileFlags(File::Truncate).openFlags());
}

