set(HEADERS
	AutoBuffer.h
	CString.h
	IBuffer.h
	IBufferReader.h
	RawBuffer.h
)

set(SOURCES
	AutoBuffer.cpp
	CString.cpp
	RawBuffer.cpp
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(mem STATIC ${HEADERS} ${SOURCES})
install(TARGETS mem DESTINATION lib)
install_symbols(TARGETS mem STATIC DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/mem)
