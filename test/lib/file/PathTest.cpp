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

void PathTest::testIsAbsolute()
{
	assert_false(Path().isAbsolute());
	assert_false(Path("file.txt").isAbsolute());
	assert_true(Path("/usr/file.txt").isAbsolute());
}

void PathTest::testIsCurrent()
{
	assert_true(Path().isCurrent());
	assert_true(Path(".").isCurrent());
	assert_true(Path("./").isCurrent());
	assert_false(Path("foo").isCurrent());
}

void PathTest::testAppend()
{
	assert_equal("foo/bar", Path() / "foo" / "bar");
	assert_equal("./foo/bar", Path(".") / "foo" / "bar");
	assert_equal("/foo/bar", Path("/") / "foo" / "bar");

	Path q("foo");
	q /= "bar";

	assert_equal("foo/bar", q);
}

void PathTest::testNormalize()
{
	assert_equal("bar/none", Path("bar/./none/./").normalize());
	assert_equal("bar/none", Path("foo/../bar/./wow/../none/./").normalize());
	assert_equal("../bar/none", Path(".././bar/./none/./").normalize());
}

