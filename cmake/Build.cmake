

add_library(common_definitions INTERFACE)

set(ADDED_TEST_DIRECTORIES "" CACHE STRING "List of processed test directories" FORCE)

include(GenerateExportHeader)

function(ext_add_binary)
	set(_OPTIONS hhh )
	set(_ONE_VALUE_ARGS NAME TYPE)
	set(_MULTI_VALUE_ARGS SOURCES SOURCE_MASK PUBLIC_DEFINITIONS PRIVATE_DEFINITIONS COMPILER_OPTIONS LINK_OPTIONS LIBRARIES PLUGINS)
	cmake_parse_arguments(_TARGET "${_OPTIONS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN})
	if(NOT _TARGET_SOURCES)
		if(NOT _TARGET_SOURCE_MASK)
			set(_MASK_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/src/)
			set(_MASKEXTENSIONS "*.h" "*.cpp" "*.c" "*.rc" )
			#message("_MASKEXTENSIONS: " ${_MASKEXTENSIONS})
			set(_TARGET_SOURCE_MASK)
			foreach(ITEM ${_MASKEXTENSIONS} )
			    list(APPEND _TARGET_SOURCE_MASK ${_MASK_PREFIX}${ITEM})
			endforeach()
			#message("_TARGET_SOURCE_MASK: " ${_TARGET_SOURCE_MASK})
		endif()
		file(GLOB _TARGET_SOURCES CONFIGURE_DEPENDS ${_TARGET_SOURCE_MASK})
		#message("_TARGET_SOURCES: " ${_TARGET_SOURCES})
	endif()

	string(TOUPPER ${_TARGET_NAME} _TARGET_NAMESPACE)

	set(IS_INTERFACE_LIB FALSE)
	if(_TARGET_TYPE STREQUAL "INTERFACE")
		set(IS_INTERFACE_LIB TRUE)
	endif()

	if(_TARGET_TYPE STREQUAL "EXECUTABLE")
		add_executable(${_TARGET_NAME} ${_TARGET_SOURCES})
	elseif(_TARGET_TYPE STREQUAL "SHARED" OR _TARGET_TYPE STREQUAL "STATIC")
		add_library(${_TARGET_NAME} ${_TARGET_TYPE} ${_TARGET_SOURCES})
		add_library(${_TARGET_NAMESPACE}::lib ALIAS ${_TARGET_NAME})
		generate_export_header(${_TARGET_NAME} BASE_NAME ${_TARGET_NAME}
			EXPORT_MACRO_NAME DECLSPEC)
		target_include_directories(${_TARGET_NAME} PUBLIC
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )
	elseif(IS_INTERFACE_LIB)
		add_library(${_TARGET_NAME} ${_TARGET_TYPE} ${_TARGET_SOURCES} )
	else()
		message(FATAL_ERROR "Unknown target type: ${_TARGET_TYPE}")
	endif()

	if(NOT IS_INTERFACE_LIB)
		target_link_libraries(${_TARGET_NAME} PRIVATE common_definitions)
	endif()

	if(NOT IS_INTERFACE_LIB)
		target_include_directories(${_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
	endif()

	if(_TARGET_PUBLIC_DEFINITIONS AND NOT IS_INTERFACE_LIB)
		target_compile_definitions(${_TARGET_NAME} PUBLIC ${_TARGET_PUBLIC_DEFINITIONS})
	endif()

	if(_TARGET_PRIVATE_DEFINITIONS)
		message( "_TARGET_PRIVATE_DEFINITIONS: " ${_TARGET_PRIVATE_DEFINITIONS})
		target_compile_definitions(${_TARGET_NAME} PRIVATE ${_TARGET_PRIVATE_DEFINITIONS})
	endif()

	if(_TARGET_COMPILER_OPTIONS)
		target_compile_options(${_TARGET_NAME} PRIVATE ${_TARGET_COMPILER_OPTIONS})
	endif()

	if(_TARGET_LINK_OPTIONS)
		target_link_options(${_TARGET_NAME} PRIVATE ${_TARGET_LINK_OPTIONS})
	endif()

	if(_TARGET_LIBRARIES)
		target_link_libraries(${_TARGET_NAME} PRIVATE ${_TARGET_LIBRARIES})
	endif()

	set(MSVS_FOLDER "${MSVS_FOLDER}/${PROJECT_NAME}")
	set_target_properties(${_TARGET_NAME} PROPERTIES FOLDER ${MSVS_FOLDER})

	if(NOT _TARGET_WITHOUT_TESTS AND IS_DIRECTORY "${PROJECT_SOURCE_DIR}/test")
		if(NOT "${PROJECT_SOURCE_DIR}/test" IN_LIST ADDED_TEST_DIRECTORIES)
			add_subdirectory(test)
			if(NOT DEFINED ADDED_TEST_DIRECTORIES)
				set(ADDED_TEST_DIRECTORIES "" CACHE STRING "List of processed test directories" FORCE)
			endif()
			message("ADDED_TEST_DIRECTORIES: " ${ADDED_TEST_DIRECTORIES})
			set(ADDED_TEST_DIRECTORIES "${ADDED_TEST_DIRECTORIES};${PROJECT_SOURCE_DIR}/test" CACHE STRING "List of processed test directories" FORCE)
			message("ADDED_TEST_DIRECTORIES: " ${ADDED_TEST_DIRECTORIES})
		endif()
	endif()
endfunction(ext_add_binary)


function(ft_add_binary)
	set(_OPTIONS INSTALL)
	set(_ONE_VALUE_ARGS NAME TYPE)
	set(_MULTI_VALUE_ARGS)

	cmake_parse_arguments(_TARGET "${_OPTIONS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN})
	ext_add_binary(${ARGV})
endfunction(ft_add_binary)

function(ft_set_test_properties)
	set(_OPTIONS )
	set(_ONE_VALUE_ARGS TARGET EXTRA_ENVIRONMENT)
	set(_MULTI_VALUE_ARGS)

	cmake_parse_arguments(PROP "${_OPTIONS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN})

	if(NOT PROP_TARGET)
		message(FATAL_ERROR "ft_set_test_properties: TARGET not specified")
	endif()

	set(TEST_ENV "")
	if(PROP_EXTRA_ENVIRONMENT)
		string(APPEND TEST_ENV ";${PROP_EXTRA_ENVIRONMENT}")
	endif()

	set_tests_properties(${PROP_TARGET} PROPERTIES ENVIRONMENT "${TEST_ENV}")

	if(MSVC_IDE)
		set_property(TARGET ${PROP_TARGET} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${VSENVS}")
	endif()
endfunction(ft_set_test_properties)

function(install_test TEST_NAME)
	install(TARGETS ${TEST_NAME} DESTINATION ${UBIN_INSTALL_SUBDIR})
endfunction(install_test)

function(ft_add_test)
	if(TURN_OFF_ALL_TESTS)
		return()
	endif()
	set(_OPTIONS DO_NOT_LINK_PROJECT_DLL)
	set(_ONE_VALUE_ARGS NAME)
	set(_MULTI_VALUE_ARGS SOURCES LIBRARIES COMPILE_DEFINES BUILD_ORDER_DEPENDENCIES)
	cmake_parse_arguments(_TARGET "${_OPTIONS}" "${_ONE_VALUE_ARGS}" "${_MULTI_VALUE_ARGS}" ${ARGN})

	if(NOT _TARGET_SOURCES)
		set(_TARGET_SOURCES "${_TARGET_NAME}.cpp")
	endif()

	set(_EXECUTABLE_NAME ${PROJECT_NAME}.${_TARGET_NAME})
	add_executable(${_EXECUTABLE_NAME} ${_TARGET_SOURCES})
	set_target_properties(${_EXECUTABLE_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${BIN_OUTPUT_DIR}")
	set(TEST_LAUNCH_CMD "")
	message("UNIX:" ${UNIX})
	message("VALGRIND:" ${VALGRIND})
	if(UNIX AND VALGRIND)
		string( APPEND TEST_LAUNCH_CMD 
			"valgrind;" 
			"--leak-check=full;" 
			"-s;" 
			"-q;" 
			"--track-origins=yes;"
			"--show-leak-kinds=all;"
			"--error-exitcode=1;")
	endif()
	string(APPEND TEST_LAUNCH_CMD "$<TARGET_FILE:${PROJECT_NAME}.${_TARGET_NAME}>")
    message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
	add_test(
		NAME ${_EXECUTABLE_NAME}
		COMMAND ${TEST_LAUNCH_CMD}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND_EXPAND_LISTS)

	ft_set_test_properties(TARGET ${_EXECUTABLE_NAME})

	if(UNIX)
			foreach(_SRC_FILE IN ITEMS ${_TARGET_SOURCES})
		           if(NOT _SRC_FILE MATCHES ".*\\.c$")
				         set_property(SOURCE ${_SRC_FILE} PROPERTY COMPILE_FLAGS "-Wno-reorder")
					endif()
			endforeach()
	endif()

	install_test(${_EXECUTABLE_NAME})

	set_target_properties(${_EXECUTABLE_NAME} PROPERTIES FOLDER ${MSVS_FOLDER}/${PROJECT_NAME}.tests)

	if(NOT _TARGET_DO_NOT_LINK_PROJECT_DLL)
		get_target_property(_BINARY_TYPE ${PROJECT_NAME} TYPE)

		if(NOT _BINARY_TYPE STREQUAL "EXECUTABLE")
			list(APPEND _TARGET_LIBRARIES ${PROJECT_NAME})
		endif()
	endif()
	target_link_libraries(${_EXECUTABLE_NAME} PRIVATE 
			${_TARGET_LIBRARIES}
			ftUtest
			common_definitions
			)

	if(WIN32 AND RUNTIME_CHECKS)
		target_compile_options(${_EXECUTABLE_NAME} PRIVATE /RTC1)
	endif()

	if(_TARGET_BUILD_ORDER_DEPENDENCIES)
		add_dependencies(${_EXECUTABLE_NAME} ${_TARGET_BUILD_ORDER_DEPENDENCIES})
	endif()
endfunction(ft_add_test)

function(ft_add_all_tests)
	if(TURN_OFF_ALL_TESTS)
		return()
	endif()

	set(_MULTI_VALUE_ARGS SOURCES LIBRARIES BUILD_ORDER_DEPENDENCIES)
	cmake_parse_arguments(_TARGET "" "" "${_MULTI_VALUE_ARGS}" ${ARGN})
	
	file(GLOB _TESTS CONFIGURE_DEPENDS "t_*.cpp")

	foreach(_TEST IN ITEMS ${_TESTS}) 
		get_filename_component(_TEST_NAME ${_TEST} NAME_WE)
		if(NOT _TEST_NAME IN_LIST _TESTS_EXCLUDE)
		    set(_TEST_FIRST_NAME ${PROJECT_NAME}.${_TEST_NAME})
			ft_add_test(NAME ${_TEST_NAME} 
			SOURCES ${_TEST_NAME}.cpp ${_TEST_SOURCES} 
			LIBRARIES ${_TESTS_LIBRARIES} 
			BUILD_ORDER_DEPENDENCIES ${_TESTS_BUILD_ORDER_DEPENDENCIES})
		endif()
	endforeach()
	
endfunction(ft_add_all_tests)