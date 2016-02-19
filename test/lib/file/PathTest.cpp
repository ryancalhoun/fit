#include "PathTest.h"
#include "Path.h"

void PathTest::setUp()
{
}

void PathTest::tearDown()
{
}

void PathTest::testBasename()
{
	assert_equal("file.txt", Path("file.txt").basename());
	assert_equal("file.txt", Path("foo/bar/file.txt").basename());
}

void PathTest::testDirname()
{
	assert_equal(".", Path("file.txt").dirname());
	assert_equal("foo/bar", Path("foo/bar/file.txt").dirname());
	assert_equal("/", Path("/bin").dirname());
}

