cmake_minimum_required(VERSION 2.8)

project(fit)

enable_testing()

include_directories(
	${corelib_SOURCE_DIR}/src
)

add_subdirectory(src/string)
add_subdirectory(test/string)

