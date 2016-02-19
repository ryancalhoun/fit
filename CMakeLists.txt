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

file(GLOB source_projects src/lib/*/CMakeLists.txt)
foreach(project_file ${source_projects})
	get_filename_component(project_dir ${project_file} DIRECTORY)
	add_subdirectory(${project_dir})
endforeach()

file(GLOB test_projects test/lib/*/CMakeLists.txt)
foreach(project_file ${test_projects})
	get_filename_component(project_dir ${project_file} DIRECTORY)
	add_subdirectory(${project_dir})
endforeach()

