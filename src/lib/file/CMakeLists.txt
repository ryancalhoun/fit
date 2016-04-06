set(HEADERS
	CurrentDirectory.h
	IFilesystemDriver.h
	Filesystem.h
	FilesystemDriver.h
	Path.h
)

set(SOURCES
	CurrentDirectory.cpp
	Filesystem.cpp
	Path.cpp
)
if(UNIX)
	list(APPEND SOURCES
		unix/FilesystemDriver.cpp
	)
else()
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(file STATIC ${HEADERS} ${SOURCES})
install(TARGETS file DESTINATION lib)
install_symbols(TARGETS file STATIC DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/file)
