#machine generated

add_subdirectory("jmx")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun_SRCS)
file(GLOB classes.com.sun_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun_HEADERS}) 
list(LENGTH classes.com.sun_SRCS classes.com.sun_SRCS_LENGTH)
if(classes.com.sun_SRCS_LENGTH)
	add_library(classes.com.sun OBJECT "${classes.com.sun_SRCS}" "${classes.com.sun_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun)
endif()