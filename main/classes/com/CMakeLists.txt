#machine generated

add_subdirectory("sun")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com_SRCS)
file(GLOB classes.com_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com_HEADERS}) 
list(LENGTH classes.com_SRCS classes.com_SRCS_LENGTH)
if(classes.com_SRCS_LENGTH)
	add_library(classes.com OBJECT "${classes.com_SRCS}" "${classes.com_HEADERS}")
	jcpp_enable_bigobj(classes.com)
endif()