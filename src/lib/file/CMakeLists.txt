set(HEADERS
	CurrentDirectory.h
	Path.h
)

set(SOURCES
	CurrentDirectory.cpp
	Path.cpp
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(file STATIC ${HEADERS} ${SOURCES})
install(TARGETS file DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/file)
