#include "CurrentDirectoryTest.h"
#include "CurrentDirectory.h"

void CurrentDirectoryTest::setUp()
{
}

void CurrentDirectoryTest::tearDown()
{
}

void CurrentDirectoryTest::testDefault()
{
	CurrentDirectory cwd;

	assert_equal("", cwd.get());
	assert_equal("foo", cwd.get("foo"));
	assert_equal("/foo", cwd.get("/foo"));
}

void CurrentDirectoryTest::testRelative()
{
	CurrentDirectory cwd("bar");

	assert_equal("bar", cwd.get());
	assert_equal("bar/foo", cwd.get("foo"));
	assert_equal("/foo", cwd.get("/foo"));
}

void CurrentDirectoryTest::testAbsolute()
{
	CurrentDirectory cwd("/bar");

	assert_equal("/bar", cwd.get());
	assert_equal("/bar/foo", cwd.get("foo"));
	assert_equal("/foo", cwd.get("/foo"));
}

void CurrentDirectoryTest::testSetCurrent()
{
	CurrentDirectory cwd(".");
	cwd.set("bar");
	assert_equal("bar", cwd.get());
}

void CurrentDirectoryTest::testSetRelative()
{
	CurrentDirectory cwd("foo");
	cwd.set("bar");
	assert_equal("foo/bar", cwd.get());

	cwd.set("/bar");
	assert_equal("/bar", cwd.get());
}

void CurrentDirectoryTest::testSetAbsolute()
{
	CurrentDirectory cwd("/foo");
	cwd.set("bar");
	assert_equal("/foo/bar", cwd.get());

	cwd.set("/bar");
	assert_equal("/bar", cwd.get());
}

