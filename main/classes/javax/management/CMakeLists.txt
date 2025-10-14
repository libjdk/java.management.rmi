#machine generated

add_subdirectory("remote")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.management_SRCS)
file(GLOB classes.javax.management_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.management_HEADERS}) 
list(LENGTH classes.javax.management_SRCS classes.javax.management_SRCS_LENGTH)
if(classes.javax.management_SRCS_LENGTH)
	add_library(classes.javax.management OBJECT "${classes.javax.management_SRCS}" "${classes.javax.management_HEADERS}")
	jcpp_enable_bigobj(classes.javax.management)
endif()