cmake_minimum_required(VERSION 2.8)

project(fit)

enable_testing()

include_directories(
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/vendor/cppunit/include
)
link_directories(
	${CMAKE_SOURCE_DIR}/vendor/cppunit/lib
)

add_subdirectory(src/string)
add_subdirectory(test/string)

