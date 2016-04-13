project(mem_test)

set(SOURCES
	AutoBufferTest.cpp
	AutoBufferTest.h
	RawBufferTest.cpp
	RawBufferTest.h
	mem_test_driver.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/lib/mem
)

add_executable(mem_test ${SOURCES})
add_test(mem_test mem_test -V)

target_link_libraries(mem_test
	mem
	cppunit
)


