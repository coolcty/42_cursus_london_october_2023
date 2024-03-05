set(MSVS_FOLDER "${MSVS_FOLDER}/common")

if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
  return()
endif()

project(CMakeFiles)

file(GLOB FILES ${CMAKE_CURRENT_SOURCE_DIR}.*.cmake)

add_custom_target(
${PROJECT_NAME}
SOURCES ${FILES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} prefix "CMake files" FILES ${FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "${MSVS_FOLDER}")

