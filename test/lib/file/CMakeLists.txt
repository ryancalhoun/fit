project(file_test)

set(SOURCES
	CurrentDirectoryTest.cpp
	CurrentDirectoryTest.h
	PathTest.cpp
	PathTest.h
	file_test_driver.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/lib/file
)

add_executable(file_test ${SOURCES})
add_test(file_test file_test -V)

target_link_libraries(file_test
	file
	cppunit

	string
)


