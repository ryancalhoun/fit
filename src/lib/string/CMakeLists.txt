set(HEADERS
	StringList.h
	StringTokenizer.h
)

set(SOURCES
	StringList.cpp
	StringTokenizer.cpp
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(string STATIC ${HEADERS} ${SOURCES})
install(TARGETS string DESTINATION lib)
install_symbols(TARGETS string STATIC DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/string)
