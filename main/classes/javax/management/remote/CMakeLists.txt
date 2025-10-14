#machine generated

add_subdirectory("rmi")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.management.rem_4_SRCS)
file(GLOB classes.javax.management.rem_4_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.management.rem_4_HEADERS}) 
list(LENGTH classes.javax.management.rem_4_SRCS classes.javax.management.rem_4_SRCS_LENGTH)
if(classes.javax.management.rem_4_SRCS_LENGTH)
	add_library(classes.javax.management.rem_4 OBJECT "${classes.javax.management.rem_4_SRCS}" "${classes.javax.management.rem_4_HEADERS}")
	jcpp_enable_bigobj(classes.javax.management.rem_4)
endif()