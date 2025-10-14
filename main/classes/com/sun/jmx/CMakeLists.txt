#machine generated

add_subdirectory("remote")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun.jmx_SRCS)
file(GLOB classes.com.sun.jmx_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun.jmx_HEADERS}) 
list(LENGTH classes.com.sun.jmx_SRCS classes.com.sun.jmx_SRCS_LENGTH)
if(classes.com.sun.jmx_SRCS_LENGTH)
	add_library(classes.com.sun.jmx OBJECT "${classes.com.sun.jmx_SRCS}" "${classes.com.sun.jmx_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun.jmx)
endif()