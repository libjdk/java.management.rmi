#machine generated

add_subdirectory("management")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax_SRCS)
file(GLOB classes.javax_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax_HEADERS}) 
list(LENGTH classes.javax_SRCS classes.javax_SRCS_LENGTH)
if(classes.javax_SRCS_LENGTH)
	add_library(classes.javax OBJECT "${classes.javax_SRCS}" "${classes.javax_HEADERS}")
	jcpp_enable_bigobj(classes.javax)
endif()