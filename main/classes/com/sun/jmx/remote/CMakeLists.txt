#machine generated

add_subdirectory("internal")
add_subdirectory("protocol")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun.jmx.remote_SRCS)
file(GLOB classes.com.sun.jmx.remote_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun.jmx.remote_HEADERS}) 
list(LENGTH classes.com.sun.jmx.remote_SRCS classes.com.sun.jmx.remote_SRCS_LENGTH)
if(classes.com.sun.jmx.remote_SRCS_LENGTH)
	add_library(classes.com.sun.jmx.remote OBJECT "${classes.com.sun.jmx.remote_SRCS}" "${classes.com.sun.jmx.remote_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun.jmx.remote)
endif()