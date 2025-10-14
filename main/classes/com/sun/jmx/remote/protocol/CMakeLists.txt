#machine generated

add_subdirectory("rmi")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun.jmx.remote.p_2_SRCS)
file(GLOB classes.com.sun.jmx.remote.p_2_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun.jmx.remote.p_2_HEADERS}) 
list(LENGTH classes.com.sun.jmx.remote.p_2_SRCS classes.com.sun.jmx.remote.p_2_SRCS_LENGTH)
if(classes.com.sun.jmx.remote.p_2_SRCS_LENGTH)
	add_library(classes.com.sun.jmx.remote.p_2 OBJECT "${classes.com.sun.jmx.remote.p_2_SRCS}" "${classes.com.sun.jmx.remote.p_2_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun.jmx.remote.p_2)
endif()