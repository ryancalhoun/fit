cmake_minimum_required(VERSION 2.8)

project(fit)

include(Emplace)

enable_testing()

include_directories(
	${CMAKE_SOURCE_DIR}/src/lib
	${CMAKE_SOURCE_DIR}/vendor/cppunit/include
)
link_directories(
	${CMAKE_SOURCE_DIR}/vendor/cppunit/lib
)

file(GLOB_RECURSE source_projects src/*/CMakeLists.txt)
foreach(project_file ${source_projects})
	get_filename_component(project_dir ${project_file} PATH)
	add_subdirectory(${project_dir})
endforeach()

file(GLOB_RECURSE test_projects test/*/CMakeLists.txt)
foreach(project_file ${test_projects})
	get_filename_component(project_dir ${project_file} PATH)
	add_subdirectory(${project_dir})
endforeach()

