#include "FileFlagsTest.h"
#include "FileFlags.h"

#ifdef _WIN32
	#include <windows.h>
#else
	#include <fcntl.h>
#endif

void FileFlagsTest::testOpenFlags()
{
#ifdef _WIN32
	assert_equal(FILE_READ_DATA|FILE_READ_ATTRIBUTES|STANDARD_RIGHTS_READ, FileFlags(File::Read).openFlags());
	assert_equal(FILE_WRITE_DATA|FILE_WRITE_ATTRIBUTES|STANDARD_RIGHTS_WRITE|WRITE_OWNER, FileFlags(File::Write).openFlags());
	assert_equal(FILE_APPEND_DATA|FILE_WRITE_ATTRIBUTES|STANDARD_RIGHTS_WRITE|WRITE_OWNER, FileFlags(File::Append|File::Write).openFlags());
	assert_equal(GENERIC_WRITE, FileFlags(File::Truncate).openFlags());
#else
	assert_equal(O_RDONLY, FileFlags(File::Read).openFlags());
	assert_equal(O_WRONLY, FileFlags(File::Write).openFlags());
	assert_equal(O_RDWR, FileFlags(File::Read|File::Write).openFlags());
	assert_equal(O_WRONLY|O_APPEND, FileFlags(File::Append|File::Write).openFlags());
	assert_equal(O_RDWR|O_APPEND, FileFlags(File::Append|File::Read|File::Write).openFlags());
#endif
}

void FileFlagsTest::testCreateFlags()
{
#ifdef _WIN32
	assert_equal(CREATE_NEW, FileFlags(File::Create|File::CreateEx).createFlags());
	assert_equal(CREATE_ALWAYS, FileFlags(File::Create|File::Truncate).createFlags());
	assert_equal(OPEN_ALWAYS, FileFlags(File::Create).createFlags());
	assert_equal(OPEN_EXISTING, FileFlags(0).createFlags());
	assert_equal(TRUNCATE_EXISTING, FileFlags(File::Truncate).createFlags());
#else
	assert_equal(O_CREAT, FileFlags(File::Create).createFlags());
	assert_equal(O_CREAT|O_EXCL, FileFlags(File::Create|File::CreateEx).createFlags());
	assert_equal(O_TRUNC, FileFlags(File::Truncate).createFlags());
#endif
}

