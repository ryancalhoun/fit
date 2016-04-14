#include "FileFlagsTest.h"
#include "FileFlags.h"

#ifdef _WIN32
	#include <windows.h>
#else
	#include <fcntl.h>
	#ifdef __APPLE__
		#define BASE_FLAGS O_CLOEXEC
	#else
		#define BASE_FLAGS O_LARGEFILE|O_CLOEXEC
	#endif
#endif

void FileFlagsTest::testOpenFlags()
{
#ifdef _WIN32
	assert_equal(FILE_READ_DATA|FILE_READ_ATTRIBUTES|STANDARD_RIGHTS_READ, FileFlags(File::Read).openFlags());
	assert_equal(FILE_WRITE_DATA|FILE_WRITE_ATTRIBUTES|STANDARD_RIGHTS_WRITE|WRITE_OWNER, FileFlags(File::Write).openFlags());
	assert_equal(FILE_APPEND_DATA|FILE_WRITE_ATTRIBUTES|STANDARD_RIGHTS_WRITE|WRITE_OWNER, FileFlags(File::Append|File::Write).openFlags());
	assert_equal(GENERIC_WRITE, FileFlags(File::Truncate).openFlags());
#else
	assert_equal(BASE_FLAGS|O_RDONLY, FileFlags(File::Read).openFlags());
	assert_equal(BASE_FLAGS|O_WRONLY, FileFlags(File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_RDWR, FileFlags(File::Read|File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_WRONLY|O_APPEND, FileFlags(File::Append|File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_RDWR|O_APPEND, FileFlags(File::Append|File::Read|File::Write).openFlags());
	assert_equal(BASE_FLAGS|O_CREAT, FileFlags(File::Create).openFlags());
	assert_equal(BASE_FLAGS|O_CREAT|O_EXCL, FileFlags(File::Create|File::CreateEx).openFlags());
	assert_equal(BASE_FLAGS|O_TRUNC, FileFlags(File::Truncate).openFlags());
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
#endif
}

