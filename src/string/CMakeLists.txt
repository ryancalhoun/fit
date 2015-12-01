set(HEADERS
	StringTokenizer.h
)

set(SOURCES
	StringTokenizer.cpp
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(string STATIC ${HEADERS} ${SOURCES})

