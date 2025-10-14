#machine generated

add_subdirectory("rmi")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun.jmx.remote.i_0_SRCS)
file(GLOB classes.com.sun.jmx.remote.i_0_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun.jmx.remote.i_0_HEADERS}) 
list(LENGTH classes.com.sun.jmx.remote.i_0_SRCS classes.com.sun.jmx.remote.i_0_SRCS_LENGTH)
if(classes.com.sun.jmx.remote.i_0_SRCS_LENGTH)
	add_library(classes.com.sun.jmx.remote.i_0 OBJECT "${classes.com.sun.jmx.remote.i_0_SRCS}" "${classes.com.sun.jmx.remote.i_0_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun.jmx.remote.i_0)
endif()