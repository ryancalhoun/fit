#include "FileHandleTest.h"
#include "FileHandle.h"
#include "FileFlags.h"
#include "Path.h"
#include "mem/AutoBuffer.h"
#include "mem/CString.h"

#include <unistd.h>

void FileHandleTest::tearDown()
{
	::unlink("testfile.txt");
}

void FileHandleTest::testCreateNew()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	assert_true(fh.write(CString("FOO")));
}

void FileHandleTest::testCreateExist()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	fh.close();

	assert_false(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
}

void FileHandleTest::testCreateWriteExist()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	fh.close();

	assert_true(fh.open("testfile.txt", File::Create | File::Write));
}

void FileHandleTest::testOpenReadExist()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	assert_true(fh.write(CString("blah stuff")));
	fh.close();

	assert_true(fh.open("testfile.txt", File::Read));

	AutoBuffer buff(20);
	assert_true(fh.read(buff));
	assert_equal("blah stuff", std::string((const char*)buff.ptr(), 10));
}

void FileHandleTest::testOpenReadNotExist()
{
	FileHandle fh;
	assert_false(fh.open("testfile.txt", File::Read));
}

void FileHandleTest::testOpenWriteExist()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	assert_true(fh.write(CString("blah stuff")));
	fh.close();

	assert_true(fh.open("testfile.txt", File::Write));

	assert_true(fh.write(CString("FOO")));
	fh.close();
}

void FileHandleTest::testOpenWriteNotExist()
{
	FileHandle fh;
	assert_false(fh.open("testfile.txt", File::Write));
}

void FileHandleTest::testOpenAppend()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	assert_true(fh.write(CString("blah stuff")));
	fh.close();

	assert_true(fh.open("testfile.txt", File::Write | File::Append));

	assert_true(fh.write(CString("FOO")));
	fh.close();
}

void FileHandleTest::testOpenTruncate()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::CreateEx | File::Write));
	assert_true(fh.write(CString("blah stuff")));
	fh.close();

	assert_true(fh.open("testfile.txt", File::Write | File::Truncate));

	assert_true(fh.write(CString("FOO")));
	fh.close();
}

void FileHandleTest::testCreateTruncate()
{
	FileHandle fh;
	assert_true(fh.open("testfile.txt", File::Create | File::Write | File::Truncate));

	assert_true(fh.write(CString("FOO")));
	fh.close();
}
