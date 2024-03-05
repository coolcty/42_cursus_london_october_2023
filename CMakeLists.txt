cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(cursus42 VERSION 1.0)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(VALGRIND ON CACHE BOOL "Control if use valgrind" FORCE)

include(CTest)
include(cmake/Build.cmake)


add_subdirectory(cmake)
add_subdirectory(ftUtest)
add_subdirectory(ftLibft)
add_subdirectory(ftft_printf)
add_subdirectory(ftget_next_line)


add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# configure a header file to pass the version number only
#configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
#add_subdirectory(MathFunctions)

# add the executable
#add_executable(Tutorial tutorial.cxx)
#set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

#target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#target_include_directories(Tutorial PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                           )
