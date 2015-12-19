project(string_test)

set(SOURCES
	StringListTest.cpp
	StringListTest.h
	StringTokenizerTest.cpp
	StringTokenizerTest.h
	string_test_driver.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/string
)

add_executable(string_test ${SOURCES})
add_test(string_test string_test)

target_link_libraries(string_test
	string
	cppunit
)


