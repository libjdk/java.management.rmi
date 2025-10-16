#machine generated

jcpp_add_dependencies(
	"java.naming:17.35"
	"java.management:17.35"
	"java.rmi:17.35"
	"java.base:17.35"
	"java.security.sasl:17.35"
	"java.logging:17.35"
)

include_directories("classes")

add_subdirectory("classes")

set(local_object ${local_object}
	"$<TARGET_OBJECTS:classes>"
	"$<TARGET_OBJECTS:classes.com.sun.jmx.remote.i_1>"
	"$<TARGET_OBJECTS:classes.com.sun.jmx.remote.p_3>"
	"$<TARGET_OBJECTS:classes.javax.management.rem_5>"
)

if(BUILD_STATIC_LIB)
	add_library(${JCPP_PROJECT_NAME}_static STATIC "${local_object}" "${source_SRCS}")

	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_static PROPERTIES VERSION ${JCPP_PROJECT_VERSION} SOVERSION 1)

	jcpp_enable_bigobj(${JCPP_PROJECT_NAME}_static)

	install(TARGETS ${JCPP_PROJECT_NAME}_static
		LIBRARY DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		ARCHIVE DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		RUNTIME DESTINATION "${JCPP_INSTALL_BIN_DIR}"
	)
endif()

if(BUILD_SHARED_LIB)
	add_library(${JCPP_PROJECT_NAME}_shared SHARED "${local_object}" "${source_SRCS}")

	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES VERSION ${JCPP_PROJECT_VERSION} SOVERSION 1)
if(JCPP_OS MATCHES "linux")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES INSTALL_RPATH "\\\$ORIGIN;\\\$ORIGIN/../lib")
elseif(JCPP_OS MATCHES "macosx")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}_shared PROPERTIES INSTALL_RPATH ".;../lib")
endif()

	target_link_libraries(${JCPP_PROJECT_NAME}_shared
		PUBLIC ${JCPP_DEPENDENCY_LIBS}
		PRIVATE ${JCPP_EXT_LIBS}
	)

	jcpp_enable_bigobj(${JCPP_PROJECT_NAME}_shared)

	jcpp_enable_debug_info(${JCPP_PROJECT_NAME}_shared)

	install(TARGETS ${JCPP_PROJECT_NAME}_shared
		LIBRARY DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		ARCHIVE DESTINATION "${JCPP_INSTALL_LIB_DIR}"
		RUNTIME DESTINATION "${JCPP_INSTALL_BIN_DIR}"
	)
endif()

install(
	DIRECTORY "include/"
	DESTINATION "include"
)

if(INSTALL_TO_REPO)
	install(
		FILES "dependencies.txt"
		DESTINATION "."
	)
endif()
